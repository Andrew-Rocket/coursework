#include <iostream>
#include "Application.h"
#include "Auth.h"

int main()
{
	try
	{
		Auth* auth = new Auth();
		Application* app = new Application(auth);
		app->start();

	}
	catch (exception e)
	{
		return EXIT_FAILURE;
	}
}
