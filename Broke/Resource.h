#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <map>
#include <string>
#include <iostream>

using namespace std;

using sf::Texture;
using sf::Font;
using sf::SoundBuffer;


namespace law {
	class ResourcesManager
	{
	public:
	
		~ResourcesManager();

		static ResourcesManager *Instace();

		bool loadTexture(string path, string name = "none"); // You can't load textures with the same name
		bool loadFont(string path, string name = "none"); // You can't load fonts with the same name
		bool loadSound(string path, string name = "none"); // Sound is only to short sounds, otherwise use music. WAV, OGG/Vorbis, FLAC.



		Texture* getTexture(std::string name);
		Font* getFont(string name);
		SoundBuffer* getSound(string name);

		bool isTextureLoaded(string name);
		bool isFontLoaded(string name);
		bool isSoundLoaded(string name);
	

	private:
		ResourcesManager();
		static ResourcesManager *instace;
		map<string, Texture> textures;
		map<string, Font> fonts;
		map<string, SoundBuffer> sounds;
	};


}

#define gResource law::ResourcesManager::Instace()