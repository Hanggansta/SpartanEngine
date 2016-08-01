class FirstPersonController
{
	GameObject @gameobject;
	Transform @transform;
	
	// misc
	bool control = false;
	bool allowToggle = false;
	
	// mouse look
	float mouseSensitivity = 0.025f;
	float mouseSmoothing = 7.0f;
	Vector2 smoothMouse = Vector2(0.0f, 0.0f);
	Vector2 mouseRotation = Vector2(0.0f, 0.0f);
	
	// wasd movement
	float movementAcceleration = 0.0025f;
	float movementDeacceleration = 0.9f;
	Vector3 movementSpeed = Vector3(0,0,0);
	
	// Constructor
	FirstPersonController(GameObject @obj)
	{
		@gameobject = obj;
	}
	
	// Use this for initialization
	void Start()
	{
		@transform = gameobject.GetTransform();
	}

	// Update is called once per frame
	void Update()
	{
		if (input.GetKey(E) && allowToggle)
		{
			control = !control;
			allowToggle = false;
		}
		else if (!input.GetKey(E))
		{
			allowToggle = true;
		}
	
		if (control)
		{
			MouseLook();
			WASD();
		}
	}

	void MouseLook()
	{
		// Get raw mouse input
		Vector2 mouseDelta = Vector2(input.GetMousePositionDelta().x, input.GetMousePositionDelta().y);
	
		// Scale input against the sensitivity setting and multiply that against the smoothing value.
		mouseDelta.x *= mouseSensitivity * mouseSmoothing;
		mouseDelta.y *= mouseSensitivity * mouseSmoothing;
		
        // Interpolate mouse movement over time to apply smoothing delta.
		smoothMouse.x = mathHelper.Lerp(smoothMouse.x, mouseDelta.x, 1.0f / mouseSmoothing);
        smoothMouse.y = mathHelper.Lerp(smoothMouse.y, mouseDelta.y, 1.0f / mouseSmoothing);
		
		// Add the smooth rotation delta to the mouse rotation
		mouseRotation += smoothMouse;
		
		// Clamp top/bottom movement freedom
		mouseRotation.y = ClampRotation(mouseRotation.y);
		
		// Create a new quaternion and update the transform
		Quaternion newRot = QuaternionFromEuler(mouseRotation.y, mouseRotation.x, 0.0f);
		transform.SetRotationLocal(newRot);
	}
	
	float ClampRotation(float rotation)
	{
		if (rotation > 90)
			rotation = 90;
		
		if (rotation < -90)
			rotation = -90;
			
		return rotation;
	}
	
	void WASD()
	{	
		// Move forward
		if (input.GetKey(W))
			movementSpeed += movementAcceleration * transform.GetForward();
			
		// Move backward
		if (input.GetKey(S))
			movementSpeed -= movementAcceleration * transform.GetForward();
		
		// Move right
		if (input.GetKey(D))
			movementSpeed += movementAcceleration * transform.GetRight();
		
		// Move left
		if (input.GetKey(A))
			movementSpeed -= movementAcceleration * transform.GetRight();
		
		// Apply some drag
		movementSpeed *= movementDeacceleration;
		
		// Update the current position of the transform
		Vector3 currentPos = transform.GetPositionLocal() + movementSpeed;
		
		// Update the transform's position
		transform.SetPositionLocal(currentPos);
	}
}