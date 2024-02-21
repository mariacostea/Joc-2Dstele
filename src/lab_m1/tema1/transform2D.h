#pragma once

#include "utils/glm_utils.h"


namespace transform2D
{
    // Translate matrix
    inline glm::mat3 Translate(float translateX, float translateY)
    {
        // TODO(student): Implement the translation matrix
        return glm::transpose(
            glm::mat3(
                1, 0, translateX,     // coloana 1 in memorie 
                0, 1, translateY,     // coloana 2 in memorie 
                0, 0, 1)   // coloana 3 in memorie 
        );
        return glm::mat3(1);

    }

    // Scale matrix
    inline glm::mat3 Scale(float scaleX, float scaleY)
    {
        return glm::transpose(
            glm::mat3(scaleX, 0, 0,
                0, scaleY, 0,
                0, 0, 1)
        );
        // TODO(student): Implement the scaling matrix
        return glm::mat3(1);

    }

    // Rotate matrix
    inline glm::mat3 Rotate(float radians)
    {
        // TODO(student): Implement the rotation matrix
        return glm::transpose(
            glm::mat3(cos(radians), -sin(radians), 0,     // coloana 1 in memorie 
                sin(radians), cos(radians), 0,     // coloana 2 in memorie 
                0, 0, 1));
        // coloana 3 in memorie 

        return glm::mat3(1);

    }
}   // namespace transform2D