//
//  sceneTest001.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef sceneTest001_hpp
#define sceneTest001_hpp

#include "Scene.hpp"
#include "Engines/RessourcesEngine/Elements/Asset.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/Vertex.hpp"
#include "Utils/Selector/Selector.hpp"

class sceneTest001: public Scene
{
public:
	/**
	 Fast-forward method to instanciate, init and in the scene GameObj
	 */
	static void load();

	/**
	 Initialize the scene
	 */
	void init();

	/**
	 Execute all the actions in the scene
	 */
	void execute();

	/**
	 Render the scene on the screen
	 */
	void render();

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	~sceneTest001() {};

private:

	ShaderProgram * m_program;
	Font * m_font;
	FontFace m_fontFace;

	GLuint m_vao;
	Mesh * m_tile;
	Mesh * m_caption;

	Selector m_menu;
};

#endif /* sceneTest001_hpp */
