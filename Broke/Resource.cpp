#include "Resource.h"


namespace law {

	ResourcesManager * ResourcesManager::instace = nullptr;

	ResourcesManager::ResourcesManager()
	{

	}


	ResourcesManager::~ResourcesManager()
	{
	}

	ResourcesManager * ResourcesManager::Instace()
	{
		if (instace == nullptr)
			instace = new ResourcesManager();
		return instace; 
	}

	bool ResourcesManager::loadTexture(string path, string name)
	{
		if (name == "none")
			name = path;
		if (textures.count(name) == 0)
		{

			Texture texture;

			textures.insert(map<string, Texture>::value_type(name, texture));
			bool did = textures.find(name)->second.loadFromFile(path);



			if (!did)
				textures.erase(name);

			return did;
		}

		cout << "Couldn't load the texture " + name + "  because there's an texture with this name.\n";
		return false;
	}

	bool ResourcesManager::loadFont(string path, string name)
	{
		if (name == "none")
			name = path;
		if (fonts.count(name) == 0)
		{
			Font font;

			fonts.insert(map<string, Font>::value_type(name, font));
			bool did = fonts.find(name)->second.loadFromFile(path);



			if (!did) {
				fonts.erase(name);
				cout << "Couldn't load the font " + name + "\n";

			}

			return did;
		}
		cout <<"Couldn't load the font " + name + "  because there's an font with this name.\n";
		return false;
	}

	bool ResourcesManager::loadSound(string path, string name)
	{
		if (name == "none")
			name = path;
		if (sounds.count(name) == 0)
		{
			SoundBuffer sound;

			sounds.insert(map<string, SoundBuffer>::value_type(name, sound));
			bool did = sounds.find(name)->second.loadFromFile(path);



			if (!did)
				sounds.erase(name);

			return did;
		}
		else
		{
			cout <<"Couldn't load the sound " + name + "  because there's an sound with this name.\n";
		}
		return false;
	}

	Texture* ResourcesManager::getTexture(string name)
	{
		if (textures.count(name) != 0)
			return &textures.find(name)->second;
		else
			return NULL;
	}

	Font * ResourcesManager::getFont(string name)
	{
		if (fonts.count(name) != 0)
			return &fonts.find(name)->second;
		else
			return NULL;
	}

	SoundBuffer * ResourcesManager::getSound(string name)
	{
		if (sounds.count(name) != 0)
			return &sounds.find(name)->second;
		else
			return NULL;
	}

	bool ResourcesManager::isTextureLoaded(string name)
	{
		return textures.count(name);
	}
	bool ResourcesManager::isFontLoaded(string name)
	{
		return fonts.count(name);
	}
	bool ResourcesManager::isSoundLoaded(string name)
	{
		return sounds.count(name);
	}
}

