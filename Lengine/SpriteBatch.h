#pragma once

#include <GL\glew.h>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <vector>

namespace Lengine{

	struct Glyph{

		GLuint texture;
		float depth;

		Vertex topLeft;
		Vertex bottomLeft;
		Vertex topRight;
		Vertex bottomRight;
		

	};
	enum class GlyphSortType{
		NONE,
		FRONT_TO_BACK,
		BACK_TO_FRONT,
		TEXTURE
	};

	class RenderBatch{
	public:
		RenderBatch(GLuint offsetOf, GLuint numOfVertices, GLuint tex) : offset(offsetOf), numVertices(numOfVertices), texture(tex){}
		GLuint offset;
		GLuint numVertices;
		GLuint texture;


	};

	class SpriteBatch{
	public:
		SpriteBatch();


		void init();

		void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
		void end();

		void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color);

		void renderBatch();




		~SpriteBatch();
	


	private:
		void createRenderBatches();
		void createVertexArray();
		void sortGlyphs();

		static bool compareFrontToBack(Glyph* a, Glyph* b);
		static bool compareBackToFront(Glyph* a, Glyph* b);
		static bool compareTexture(Glyph* a, Glyph* b);
		GLuint _vbo;
		GLuint _vao;

		GlyphSortType _sortType;

		std::vector<Glyph*> _glyphs;
		std::vector<RenderBatch> _renderBatches;

	};

}

