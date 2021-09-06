/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"
#include <iostream>
#include <string>

bool initGL()
{
   //Initialize Projection Matrix
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   //Initialize Modelview Matrix
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   //Initialize clear color
   glClearColor(0.f, 0.f, 0.f, 1.f);

   //Check for error
   GLenum error = glGetError();
   if (error != GL_NO_ERROR)
   {
      printf("Error initializing OpenGL! %s\n", gluErrorString(error));
      return false;
   }

   return true;
}

void update()
{

}

void render()
{
   static bool first_time = true;
   if (first_time)
   {
      first_time = false;
      std::cout << "Cout works!!!" << std::endl;
   }

   //Clear color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   //Render quad
   glColor3f(0.5f, 0.0f, 0.0f);  // Red rectangle
   glBegin(GL_QUADS);
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(0.5f, -0.5f);
   glVertex2f(0.5f, 0.5f);
   glVertex2f(-0.5f, 0.5f);
   glEnd();

   // From rectangle draw example at:  https://en.wikibooks.org/wiki/OpenGL_Programming/Basics/Rectangles
   // glColor3f(0.0f, 0.0f, 0.0f);
   // glRectf(-0.75f, 0.75f, 0.75f, -0.75f);

   //Update screen
   glutSwapBuffers();
}
