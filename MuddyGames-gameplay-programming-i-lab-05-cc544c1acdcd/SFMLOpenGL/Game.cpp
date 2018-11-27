#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
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

	

	glClearColor(255.0f, 255.0f, 255.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
	timer = timer++;
	
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (timer < 300)
	{
		glColor3f(0.0f, 255.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		{ glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0); }
		glEnd();
	}
	else if (timer < 600)
	{
		glPointSize((10.0f));
		glColor3f(255.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	
	else if (timer < 900)
	{
		glLineWidth(5.0f);
		glColor3f(255.0f, 255.0f, 0.0f);
		glBegin(GL_LINES);
		{
			glVertex3f(1.0, 0.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
		}
		glEnd();
	}
	
	else if (timer < 1200)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_STRIP);
		{
			glVertex3f(0.0, 0.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, 1.5, -6.0);
			glVertex3f(1.0, 0.0, -3.0);
		}
		glEnd();
	}
	else if (timer < 1500)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(0.0, 0.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, 1.5, -6.0);
			glVertex3f(1.0, 0.0, -3.0);
		}
		glEnd();
	}
	else if (timer < 1800)
	{
		glColor3f(255.0f, 0.0f, 255.0f);
		glBegin(GL_TRIANGLE_STRIP);
		{
			glVertex3f(0.0, 0.0, -10.5);
			glVertex3f(-1.0, -1.0, -10.5);
			glVertex3f(1.0, -1.0, -10.5);
			glVertex3f(2.0, -2.0, -10.5);
		}
		glEnd();
	}
	else if (timer < 2100)
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0.0, 1.0, -10.5);
			glVertex3f(-1.0, -1.0, -10.5);
			glVertex3f(1.0, -1.0, -10.5);
			glVertex3f(2.0, -2.0, -10.5);
			glVertex3f(-1.0, -2.0, -10.5);
		}
		glEnd();
	}
	else if (timer < 2400)
	{
		glColor3f(110.0, 0.0, 60.0);
		glBegin(GL_QUADS);
		{
			glVertex3f(2.0, -2.0, -10.0);
			glVertex3f(2.0, 2.0, -10.0);
			glVertex3f(-2.0, 2.0, -10.0);
			glVertex3f(-2.0, -2.0, -10.0);
		}
		glEnd();
	}
	else if (timer < 2700)
	{
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
	}
	else if (timer < 3000)
	{
		glColor3f(0.0,0.0,255.0);
		glBegin(GL_POLYGON);
		{
			glVertex3f(0.0, 0.0, -20.0);
			glVertex3f(0.0, 3.0, -20.0);
			glVertex3f(4.0, 3.0, -20.0);
			glVertex3f(6.0, 1.5, -20.0);
			glVertex3f(4.0, 0.0, -20.0);
		}
		glEnd();
	}
	else if (timer > 3000)
	{
		timer = 0;
	}
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

