#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace Lengine{

	TextureCache::TextureCache(){

	}


	GLTexture TextureCache::getTexture(std::string texturePath){

		std::map<std::string, GLTexture>::iterator mit = _textureMap.find(texturePath);

		if(mit == _textureMap.end()){
			GLTexture texture = ImageLoader::loadPNG(texturePath);

			std::pair<std::string, GLTexture> pair(texturePath, texture);

			_textureMap.insert(pair);
			std::cout << "Loaded to cache\n";
			return texture;
		}
		std::cout << "Found from cache\n";

		return mit->second;

	}


	TextureCache::~TextureCache(){

	}
}