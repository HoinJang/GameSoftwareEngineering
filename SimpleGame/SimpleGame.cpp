/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "SceneMgr.h"

Renderer *g_Renderer = NULL;
SceneMgr *g_SceneMgr = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	for (int i = 0; i < 50; i++)
	{
		g_Renderer->DrawSolidRect(g_SceneMgr->m_objects[i]->GetPositionX(), g_SceneMgr->m_objects[i]->GetPositionY(), g_SceneMgr->m_objects[i]->GetPositionZ(), g_SceneMgr->m_objects[i]->GetSize(), g_SceneMgr->m_objects[i]->GetColorRed(), g_SceneMgr->m_objects[i]->GetColorGreen(), g_SceneMgr->m_objects[i]->GetColorBlue(), 1);
	}
	// Renderer Test
	//g_Renderer->DrawSolidRect(Test.GetPositionX(), Test.GetPositionY(), Test.GetPositionZ(), Test.GetSize(), Test.GetColorRed(), Test.GetColorGreen(), Test.GetColorBlue(),1);

	glutSwapBuffers();
}

void Idle(void)
{
	g_SceneMgr->SceneUpdate();
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{	
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	//
	if (g_SceneMgr == NULL)
	{
		g_SceneMgr = new SceneMgr();
		g_SceneMgr->Init();
	}
	//
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;
	delete g_SceneMgr;

    return 0;
}

