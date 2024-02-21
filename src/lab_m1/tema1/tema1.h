#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class tema1 : public gfxc::SimpleScene
    {
     public:
         tema1();
        ~tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY;
        float scaleX, scaleY;
        float scaleValue;
        float angularStep;
        float x_inamic;
        float lives;
        void processEntities(std::vector<glm::vec2>& entities, std::vector<float>& scales, const std::string& meshName, float deltaTimeSeconds);
        std::vector<glm::vec2> starPositions;
        std::vector<glm::vec2> star1Positions;
        std::vector<glm::vec2> star2Positions;
        std::vector<glm::vec2> star3Positions;
        std::vector<glm::vec2> star4Positions;
        std::vector<glm::vec2> pointsPositions;
        std::vector<glm::vec2> rhombusPositions;
        std::vector<glm::vec2> rhombus1Positions;
        std::vector<glm::vec2> rhombus2Positions;
        std::vector<glm::vec2> rhombus3Positions;
        std::vector<glm::vec2> rhombus4Positions;
        std::vector<glm::vec2> inamicPositions;
        std::vector<glm::vec2> inamic1Positions;
        std::vector<glm::vec2> inamic2Positions;
        std::vector<glm::vec2> inamic3Positions;
        std::vector<glm::vec2> inamic4Positions;
        std::vector<glm::vec2> inamic1erase;
        std::vector<glm::vec2> inamic2erase;
        std::vector<glm::vec2> inamic3erase;
        std::vector<glm::vec2> inamic4erase;
        std::vector<glm::vec2> rhombuserase;
        std::vector<float> scalerhombus;
        std::vector<int> colorerase;
        std::vector<std::vector<int>> inamic1;
        std::vector<std::vector<int>> inamic2;
        std::vector<std::vector<int>> inamic3;
        std::vector<std::vector<int>> inamic4;
        std::vector<int> hexa1;
        std::vector<int> hexa2;
        std::vector<int> hexa3;
        std::vector<int> hexa4;
        std::vector<float> scales1;
        std::vector<float> scales2;
        std::vector<float> scales3;
        std::vector<float> scales4;
        std::vector<glm::vec3> colors;
        std::vector<Mesh*> hexagoane;
        std::vector<Mesh*> inamici;
        std::vector<int> tipuriromb;
        int selectedRhombusIndex;
        float lastpointpos;
        int stars;
        float radians;
        float newgunX;
        float newgunY;
        bool move;
        int rhombus1;
        int rhombus2;
        int rhombus3;
        int rhombus4;
        int posx1[10];
        int posx2[10];
        int posx3[10];
        int posx4[10];
        int posy1[10];
        int posy2[10];
        int posy3[10];
        int posy4[10];
       

        // TODO(student): If you need any other class variables, define them here.

    };
}   // namespace m1
