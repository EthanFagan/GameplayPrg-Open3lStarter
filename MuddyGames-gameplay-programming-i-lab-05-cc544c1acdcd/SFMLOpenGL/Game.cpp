#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"),
primatives(10)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;
	

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glNewList(index, GL_COMPILE);
	glColor3f(0.0f, 255.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	{ glVertex3f(0.0, 2.0, -5.0);
	glVertex3f(-2.0, -2.0, -5.0);
	glVertex3f(2.0, -2.0, -5.0); }
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glPointSize((5.0f));
	glColor3f(255.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glLineWidth(5.0f);
	glColor3f(255.0f, 255.0f, 0.0f);
	glBegin(GL_LINES);
	{
		glVertex3f(1.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glColor3f(255.0f, 255.0f, 255.0f);
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, 1.5, -6.0);
		glVertex3f(1.0, 0.0, -3.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glColor3f(255.0f, 255.0f, 255.0f);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, 1.5, -6.0);
		glVertex3f(1.0, 0.0, -3.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glColor3f(255.0f, 0.0f, 255.0f);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.0, 0.0, -10.5);
		glVertex3f(-1.0, -1.0, -10.5);
		glVertex3f(1.0, -1.0, -10.5);
		glVertex3f(2.0, -2.0, -10.5);
	}
	glEnd();
	glEndList();

	glNewList(index + 6, GL_COMPILE);
	glColor3f(255.0, 255.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0, 1.0, -10.5);
		glVertex3f(-1.0, -1.0, -10.5);
		glVertex3f(1.0, -1.0, -10.5);
		glVertex3f(2.0, -2.0, -10.5);
		glVertex3f(-1.0, -2.0, -10.5);
	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glColor3f(110.0, 0.0, 60.0);
	glBegin(GL_QUADS);
	{
		glVertex3f(2.0, -2.0, -10.0);
		glVertex3f(2.0, 2.0, -10.0);
		glVertex3f(-2.0, 2.0, -10.0);
		glVertex3f(-2.0, -2.0, -10.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glColor3f(255.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(2.0, -2.0, -10.0);
		glVertex3f(2.0, 2.0, -10.0);
		glVertex3f(-2.0, -2.0, -10.0);
		glVertex3f(-2.0, 2.0, -10.0);
		glVertex3f(-3.0, -2.0, -10.0);
		glVertex3f(-3.0, 2.0, -10.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 9, GL_COMPILE);
	glColor3f(0.0, 0.0, 255.0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.0, 0.0, -20.0);
		glVertex3f(0.0, 3.0, -20.0);
		glVertex3f(4.0, 3.0, -20.0);
		glVertex3f(6.0, 1.5, -20.0);
		glVertex3f(4.0, 0.0, -20.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	cout << "Update up" << endl;
	timer = timer++;
	
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	 // ********************

}

void Game::draw()
{

	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Investigate Here!!!!!
	glLoadIdentity();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		rotationAngle++;
	}
	else
	{
		rotationAngle = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glScalef(1.0f, 2.0f, 3.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		glTranslatef(1.0f, 0.0f, 0.0f);
	}


	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);


	cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

