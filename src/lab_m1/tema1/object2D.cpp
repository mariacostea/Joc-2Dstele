#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    float width,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, width, 0), color),
        VertexFormat(corner + glm::vec3(0, width, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}
        
Mesh* object2D::CreateRhombus(
    const std::string& name,
    glm::vec3 center,
    float length,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 leftPoint = center - glm::vec3(length, 0, 1);
    glm::vec3 rightPoint = center + glm::vec3(length , 0, 1);
    glm::vec3 bottomPoint = center - glm::vec3(0, height, 1);
    glm::vec3 topPoint = center + glm::vec3(0, height, 1);

    glm::vec3 topLeftRectangle = center + glm::vec3(0, height / 5, 1);
    glm::vec3 bottomLeftRectangle = center - glm::vec3(0, height / 5, 1);
    glm::vec3 topRightRectangle = center + glm::vec3(1.2 * height, height / 5, 1);
    glm::vec3 bottomRightRectangle = center + glm::vec3( 1.2 * height, -height / 5, 1);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(topPoint, color),
        VertexFormat(leftPoint, color),
        VertexFormat(rightPoint, color),
        VertexFormat(bottomPoint, color),

        VertexFormat(topLeftRectangle, color),
        VertexFormat(bottomLeftRectangle, color),
        VertexFormat(topRightRectangle, color),
        VertexFormat(bottomRightRectangle, color)
    };
    
    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 
                                          3, 1, 2, 
                                          0, 1, 3,
                                          0, 2, 3,
                                          4, 5, 6, 
                                          7 , 5, 6};
 

        
    if (!fill) {
		rhombus->SetDrawMode(GL_LINE_LOOP);
	}
    else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

    rhombus->InitFromData(vertices, indices);
	return rhombus;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices = {
        VertexFormat(center, color)
    };


    for (int i = 0 ; i < 5; ++i) {
        float angle = glm::radians(360.0f * i / 5.0f + 18.0f);
        float x = center.x + radius * cos(angle);
        float y = center.y + radius * sin(angle);
        vertices.push_back(VertexFormat(glm::vec3(x, y, 1), color));
    }

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 3, 
                                          0, 4, 1, 
                                          0, 2, 4, 
                                          0, 2, 5,
                                          0, 3, 5};

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(2);
        indices.push_back(4);
        indices.push_back(4);
        indices.push_back(1);
        indices.push_back(1);
        indices.push_back(3);
        indices.push_back(3);
        indices.push_back(0);
    }

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color1,
    glm::vec3 color2,
    bool fill)
{
    std::vector<VertexFormat> vertices;


   for (int i = 0; i < 6; ++i) {
        float angle = glm::radians(360.0f * i / 6.0f );
        float x = center.x + radius * cos(angle);
        float y = center.y + radius * sin(angle);
        vertices.push_back(VertexFormat(glm::vec3(x, y, 1), color1));
    } 

   for (int i = 0; i < 6; ++i) {
       float angle = glm::radians(360.0f * i / 6.0f);
       float x = center.x + radius * 0.7f * cos(angle);
       float y = center.y + radius * 0.7f * sin(angle);
       vertices.push_back(VertexFormat(glm::vec3(x, y, 2), color2));
   }

    Mesh* hexagon = new Mesh(name);
    std::vector<unsigned int> indices = { 6, 7, 8,
                                          6, 8, 9,
                                          6, 9, 10,
                                          6, 10, 11,      
                                          0, 1, 2,
                                          0, 2, 3,
                                          0, 3, 4,
                                          0, 4, 5,};

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(2);
        indices.push_back(4);
        indices.push_back(4);
        indices.push_back(1);
        indices.push_back(1);
        indices.push_back(3);
        indices.push_back(3);
        indices.push_back(5);
        indices.push_back(5);
        indices.push_back(6);
        indices.push_back(6);
        indices.push_back(0);
    }

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}

    










