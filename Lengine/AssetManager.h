#pragma once

#include "TextureCache.h"
#include "GLTexture.h"
#include <string>
namespace Lengine{
	class AssetManager{
	public:

		static GLTexture getTexture(std::string texturePath);

	private:
		//wrapper object
		static TextureCache _textureCache;
	};
}
