#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;

tema1::tema1()
{
}


tema1::~tema1()
{
}


void tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    glm::vec3 corner2 = glm::vec3(0, 0, 1);
    float squareSide = 100;
    float redsquare = 70;
    x_inamic = 1200;
    lives = 3;
    selectedRhombusIndex = -1;
    lastpointpos = 1080;
    stars = 8;
    move = false;
    rhombus1 = 0;
    rhombus2 = 0;
    rhombus3 = 0;
    rhombus4 = 0;
    radians = 1;
 
    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;

    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    // Initialize angularStep
    angularStep = 0;

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(1, 1, 1));
    AddMeshToList(square2);

    Mesh* square3 = object2D::CreateSquare("square3", corner, redsquare, glm::vec3(1, 0, 0), true);
    AddMeshToList(square3);

    Mesh* rhombus1 = object2D::CreateRhombus("rhombus1", corner2, 15, 35, glm::vec3(1, 1, 0), true);
    AddMeshToList(rhombus1);

    Mesh* rhombus2 = object2D::CreateRhombus("rhombus2", corner2, 15, 35, glm::vec3(1, 0, 1), true);
    AddMeshToList(rhombus2);

    Mesh* rhombus3 = object2D::CreateRhombus("rhombus3", corner2, 15, 35, glm::vec3(0, 1, 1), true);
    AddMeshToList(rhombus3);

    Mesh* rhombus4 = object2D::CreateRhombus("rhombus4", corner2, 15, 35, glm::vec3(0, 0, 1), true);
    AddMeshToList(rhombus4);

    Mesh* star = object2D::CreateStar("star", corner, 20, glm::vec3(1, 1, 1), true);
    AddMeshToList(star);

    Mesh* star_point = object2D::CreateStar("star_point", corner + glm::vec3(0,0,2), 30, glm::vec3(1, 0.69f, 0.7f), true);
    AddMeshToList(star_point);

    Mesh* star1 = object2D::CreateStar("star1", corner, 25, glm::vec3(1, 1, 0), true);
    AddMeshToList(star1);

    Mesh* star2 = object2D::CreateStar("star2", corner, 25, glm::vec3(1, 0, 1), true);
    AddMeshToList(star2);

    Mesh* star3 = object2D::CreateStar("star3", corner, 25, glm::vec3(0, 1, 1), true);
    AddMeshToList(star3);

    Mesh* star4 = object2D::CreateStar("star4", corner, 25, glm::vec3(0, 0, 1), true);
    AddMeshToList(star4);

    Mesh* hexagon1 = object2D::CreateHexagon("hexagon1", corner, 35, glm::vec3(1, 1, 0), glm::vec3(0.5, 0.7 , 1), true);
    AddMeshToList(hexagon1);
    hexagoane.push_back(hexagon1);
 

    Mesh* hexagon2 = object2D::CreateHexagon("hexagon2", corner, 35, glm::vec3(1, 0, 1), glm::vec3(0.5, 0.7, 1), true);
    AddMeshToList(hexagon2);
    hexagoane.push_back(hexagon2);


    Mesh* hexagon3 = object2D::CreateHexagon("hexagon3", corner, 35, glm::vec3(0, 1, 1), glm::vec3(0.5, 0.7, 1), true);
    AddMeshToList(hexagon3);
    hexagoane.push_back(hexagon3);


    Mesh* hexagon4 = object2D::CreateHexagon("hexagon4", corner, 35, glm::vec3(0, 0, 1), glm::vec3(0.5, 0.7, 1), true);
    AddMeshToList(hexagon4);
    hexagoane.push_back(hexagon4);



    Mesh* rectangle1 = object2D::CreateRectangle("rectangle1", corner, 40, 360 , glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle1);
}


void tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void tema1::Update(float deltaTimeSeconds)
{

    if (lives == 0)
        window->Close();



    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 30);
    
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 30);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(360, 30);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 160);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 160);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(360, 160);

    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);

    modelMatrix *= transform2D::Translate(100, 290);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 290);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(360, 290);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(60, 600);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(220, 600);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(380, 600);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(540, 600);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    if (lives > 0) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(780, 620);
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    }

    if (lives > 1) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(900, 620);
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    }

    if (lives > 2) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(1020, 620);
        RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(20, 30);
    RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(100, 650);
    RenderMesh2D(meshes["rhombus1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(70, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(260, 650);
    RenderMesh2D(meshes["rhombus2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(270, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(420, 650);
    RenderMesh2D(meshes["rhombus3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(390, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(430, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(580, 650);
    RenderMesh2D(meshes["rhombus4"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(550, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(590, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(630, 580);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);




    for (float j = 800; j <= lastpointpos; j = j + 40) {
        pointsPositions.push_back(glm::vec2(j * window->GetResolution().x, 600 * window->GetResolution().y));
        pointsPositions.push_back(glm::vec2(j * window->GetResolution().x, 600 * window->GetResolution().y));
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(j, 600);
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }
    
    //romburile urmeaza pozitia cursorului

    if (selectedRhombusIndex == 1) {
        if (move == false) {
            glm::vec2 cursor = window->GetCursorPosition();
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(cursor.x, 720 - cursor.y);
            RenderMesh2D(meshes["rhombus1"], shaders["VertexColor"], modelMatrix);
        }

    }
    else if (selectedRhombusIndex == 2) {
        if (move == false) {
            glm::vec2 cursor = window->GetCursorPosition();
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(cursor.x, 720 - cursor.y);
            RenderMesh2D(meshes["rhombus2"], shaders["VertexColor"], modelMatrix);
        }

    }
    else if (selectedRhombusIndex == 3) {
        if (move == false) {
            glm::vec2 cursor = window->GetCursorPosition();
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(cursor.x, 720 - cursor.y);
            RenderMesh2D(meshes["rhombus3"], shaders["VertexColor"], modelMatrix);
        }

    }
    else if (selectedRhombusIndex == 4) {
        if (move == false) {
            glm::vec2 cursor = window->GetCursorPosition();
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(cursor.x, 720 - cursor.y);
            RenderMesh2D(meshes["rhombus4"], shaders["VertexColor"], modelMatrix);
        }

    }

    //verific ca cel putin un romb a fost amplasat pe tabla
    
    if ((rhombus1 > 0 || rhombus2 > 0 || rhombus3 > 0 || rhombus4 > 0))
    {

        //daca da, pozitionez rombul pe tabla
        for (size_t rh = 0; rh < rhombusPositions.size(); ++rh) {
            if (tipuriromb[rh] == 1) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(rhombusPositions[rh].x, rhombusPositions[rh].y);
                RenderMesh2D(meshes["rhombus1"], shaders["VertexColor"], modelMatrix);
            }
            else if (tipuriromb[rh] == 2) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(rhombusPositions[rh].x, rhombusPositions[rh].y);
                RenderMesh2D(meshes["rhombus2"], shaders["VertexColor"], modelMatrix);
            }
            else if (tipuriromb[rh] == 3) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(rhombusPositions[rh].x, rhombusPositions[rh].y);
                RenderMesh2D(meshes["rhombus3"], shaders["VertexColor"], modelMatrix);
            }
            else if (tipuriromb[rh] == 4) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(rhombusPositions[rh].x, rhombusPositions[rh].y);
                RenderMesh2D(meshes["rhombus4"], shaders["VertexColor"], modelMatrix);
            }
            auto iterator = std::find_if(inamicPositions.begin(), inamicPositions.end(), [&](const auto& inamicPos) {
                return inamicPos.x <= (rhombusPositions[rh].x + 67) && inamicPos.y == rhombusPositions[rh].y;
                });
            if (iterator != inamicPositions.end()) {
                rhombusPositions.erase(rhombusPositions.begin() + rh);
                if (tipuriromb[rh] == 1)
					rhombus1--;
				else if (tipuriromb[rh] == 2)
					rhombus2--;
				else if (tipuriromb[rh] == 3)
					rhombus3--;
				else if (tipuriromb[rh] == 4)
					rhombus4--;
                tipuriromb.erase(tipuriromb.begin() + rh);
            }
        }

        radians -= deltaTimeSeconds * 3;

        //verific pentru fiecare romb daca am inamici pe linia respectiva de culoarea respectiva
        for (size_t rh1 = 0; rh1 < rhombus1Positions.size(); rh1++) {

            int ok = 0;
            for (size_t i = 0; i < star1Positions.size(); ++i) {
                if (star1Positions[i].y == rhombus1Positions[rh1].y) {
                    ok = 1;
                }
            }
            if (star1Positions.empty() || ok == 0) {
                if (selectedRhombusIndex == -1) {
                    for (size_t i = 0; i < inamic1Positions.size(); ++i) {
                        if (inamic1Positions[i].y == rhombus1Positions[rh1].y) {
                            star1Positions.push_back(glm::vec2(rhombus1Positions[rh1].x + 20, rhombus1Positions[rh1].y));
                        }
                    }
                }
            }
            else {
                for (size_t st = 0; st < star1Positions.size(); st++) {
                    if (star1Positions[st].y == rhombus1Positions[rh1].y) {
                        ok = st;
                    }
                }
                if (star1Positions[ok].x - rhombus1Positions[rh1].x > 300) {
                    for (size_t i = 0; i < inamic1Positions.size(); ++i) {
                        if (inamic1Positions[i].y == rhombus1Positions[rh1].y) {
                            star1Positions.push_back(glm::vec2(rhombus1Positions[rh1].x + 20, rhombus1Positions[rh1].y));
                        }
                    }
                }
            }

        //verific coliziunile dintre stele si inamici

            for (size_t s = 0; s < star1Positions.size(); s++) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(star1Positions[s].x, star1Positions[s].y);
                modelMatrix *= transform2D::Rotate(radians);
                RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);
                star1Positions[s].x = star1Positions[s].x + deltaTimeSeconds * 150;
                auto iterator = std::find_if(inamic1Positions.begin(), inamic1Positions.end(), [&](const auto& inamicPos) {
                    return inamicPos.x <= (star1Positions[s].x + 60) && inamicPos.y == star1Positions[s].y;
                    });

                if (star1Positions[s].x > 1250 || iterator != inamic1Positions.end()) {
                    star1Positions.erase(star1Positions.begin() + s);
                    if (iterator != inamic1Positions.end()) {
                        size_t index = std::distance(inamic1Positions.begin(), iterator);
                        hexa1[index]++;
                        if (hexa1[index] == 3) {
                            inamic1erase.push_back(inamic1Positions[index]);
                            inamic1Positions.erase(inamic1Positions.begin() + index);
                            scales1.push_back(1);
                            hexa1.erase(hexa1.begin() + index);
                        }
                    }
                }
            }
        }

  


        for (int x = 0; x < rhombus2; x++) {

            int ok = 0;
            for (size_t i = 0; i < star2Positions.size(); ++i) {
                if (star2Positions[i].y == posy2[x]) {
                    ok = 1;
                }
            }
            if (star2Positions.empty() || ok == 0 ) {
                if (selectedRhombusIndex == -1) {
                    for (size_t i = 0; i < inamic2Positions.size(); ++i) {
                        if (inamic2Positions[i].y == posy2[x]) {
                            star2Positions.push_back(glm::vec2(posx2[x] + 20, posy2[x]));
                        }
                    }
                }
            }
            else
            {
                for (size_t st = 0; st < star2Positions.size(); st++) {
                    if (star2Positions[st].y == posy2[x]) {
                        ok = st;
                    }
                }
                if (star2Positions[ok].x - posx2[x] > 300) {
                    for (size_t i = 0; i < inamic2Positions.size(); ++i) {
                        if (inamic2Positions[i].y == posy2[x]) {
                            star2Positions.push_back(glm::vec2(posx2[x] + 20, posy2[x]));
                        }
                    }
                }
            }

            for (size_t s = 0; s < star2Positions.size(); s++) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(star2Positions[s].x, star2Positions[s].y);
                modelMatrix *= transform2D::Rotate(radians);
                RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);
                star2Positions[s].x = star2Positions[s].x + deltaTimeSeconds * 150;
                auto iterator = std::find_if(inamic2Positions.begin(), inamic2Positions.end(), [&](const auto& inamicPos) {
                    return inamicPos.x <= (star2Positions[s].x + 60) && inamicPos.y == star2Positions[s].y;
                    });

                if (star2Positions[s].x > 1250 || iterator != inamic2Positions.end()) {
                    star2Positions.erase(star2Positions.begin() + s);
                    size_t index = std::distance(inamic2Positions.begin(), iterator);
                    if (iterator != inamic2Positions.end()) {
                        hexa2[index]++;
                        if (hexa2[index] == 3) {
                            inamic2erase.push_back(inamic2Positions[index]);
                            scales2.push_back(1);
                            inamic2Positions.erase(inamic2Positions.begin() + index);
                            hexa2.erase(hexa2.begin() + index);
                        }
                    }
                }
            }
        }


        for (int x = 0; x < rhombus3; x++) {

            int ok = 0;
            for (size_t i = 0; i < star3Positions.size(); ++i) {
                if (star3Positions[i].y == posy3[x]) {
                    ok = 1;
                }
            }
            if (star3Positions.empty() || ok == 0) {
                if (selectedRhombusIndex == -1) {
                    for (size_t i = 0; i < inamic3Positions.size(); ++i) {
                        if (inamic3Positions[i].y == posy3[x]) {
                            star3Positions.push_back(glm::vec2(posx3[x] + 20, posy3[x]));
                        }
                    }
                }
            }
            else
            {
                for (size_t st = 0; st < star3Positions.size(); st++) {
                    if (star3Positions[st].y == posy3[x]) {
                        ok = st;
                    }
                }
                if (star3Positions[ok].x - posx3[x] > 300) {
                    for (size_t i = 0; i < inamic3Positions.size(); ++i) {
                        if (inamic3Positions[i].y == posy3[x]) {
                            star3Positions.push_back(glm::vec2(posx3[x] + 20, posy3[x]));
                        }
                    }
                }
            }

            for (size_t s = 0; s < star3Positions.size(); s++) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(star3Positions[s].x, star3Positions[s].y);
                modelMatrix *= transform2D::Rotate(radians);
                RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);
                star3Positions[s].x = star3Positions[s].x + deltaTimeSeconds * 150;
                auto iterator = std::find_if(inamic3Positions.begin(), inamic3Positions.end(), [&](const auto& inamicPos) {
                    return inamicPos.x <= (star3Positions[s].x + 60) && inamicPos.y == star3Positions[s].y;
                    });

                if (star3Positions[s].x > 1250 || iterator != inamic3Positions.end()) {
                    star3Positions.erase(star3Positions.begin() + s);
                    size_t index = std::distance(inamic3Positions.begin(), iterator);
                    if (iterator != inamic3Positions.end()) {
                        hexa3[index]++;
                        if (hexa3[index] == 3) {
                            inamic3erase.push_back(inamic3Positions[index]);
                            scales3.push_back(1);
                            inamic3Positions.erase(inamic3Positions.begin() + index);
                            hexa3.erase(hexa3.begin() + index);
                        }
                    }
                }
            }
        }

        for (int x = 0; x < rhombus4; x++) {

            int ok = 0;
            for (size_t i = 0; i < star4Positions.size(); ++i) {
                if (star4Positions[i].y == posy4[x]) {
                    ok = 1;
                }
            }
            if (star4Positions.empty() || ok == 0) {
                if (selectedRhombusIndex == -1) {
                    for (size_t i = 0; i < inamic4Positions.size(); ++i) {
                        if (inamic4Positions[i].y == posy4[x]) {
                            star4Positions.push_back(glm::vec2(posx4[x] + 20, posy4[x]));
                        }
                    }
                }
            }
            else
            {
                for (size_t st = 0; st < star4Positions.size(); st++) {
                    if (star4Positions[st].y == posy4[x]) {
                        ok = st;
                    }
                }
                if (star4Positions[ok].x - posx4[x] > 300) {
                    for (size_t i = 0; i < inamic4Positions.size(); ++i) {
                        if (inamic4Positions[i].y == posy4[x]) {
                            star4Positions.push_back(glm::vec2(posx4[x] + 20, posy4[x]));
                        }
                    }
                }
            }

            for (size_t s = 0; s < star4Positions.size(); s++) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(star4Positions[s].x, star4Positions[s].y);
                modelMatrix *= transform2D::Rotate(radians);
                RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);
                star4Positions[s].x = star4Positions[s].x + deltaTimeSeconds * 150;
                auto iterator = std::find_if(inamic4Positions.begin(), inamic4Positions.end(), [&](const auto& inamicPos) {
                    return inamicPos.x <= (star4Positions[s].x + 60) && inamicPos.y == star4Positions[s].y;
                    });

                if (star4Positions[s].x > 1250 || iterator != inamic4Positions.end()) {
                    star4Positions.erase(star4Positions.begin() + s);
                    if (iterator != inamic4Positions.end()) {
                        size_t index = std::distance(inamic4Positions.begin(), iterator);
                        hexa4[index]++;
                        if (hexa4[index] == 3) {
                            inamic4erase.push_back(inamic4Positions[index]);
                            scales4.push_back(1);
                            inamic4Positions.erase(inamic4Positions.begin() + index);
                            hexa4.erase(hexa4.begin() + index);
                        }
                    }
                }
            }
        }

    }

    //generez stele in pozitii random
    float randomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    if (lives > 0 && randomValue < 0.002) 
    {
        
        float randomX = static_cast<float>(rand() % window->GetResolution().x) / static_cast<float>(window->GetResolution().x);
        float randomY = static_cast<float>(rand() % window->GetResolution().y) / static_cast<float>(window->GetResolution().y);

        float randomx = static_cast<float>(rand() % window->GetResolution().x) / static_cast<float>(window->GetResolution().x);
        float randomy = static_cast<float>(rand() % window->GetResolution().y) / static_cast<float>(window->GetResolution().y);

        
        starPositions.push_back(glm::vec2(randomX * window->GetResolution().x, randomY * window->GetResolution().y));
        starPositions.push_back(glm::vec2(randomx * window->GetResolution().x, randomy * window->GetResolution().y));
    }

    
    for (const auto& starPos : starPositions)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(starPos.x, starPos.y);
        RenderMesh2D(meshes["star_point"], shaders["VertexColor"], modelMatrix);
    }


    //generez inamici in pozitii random
    float rV = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    if (lives > 0 && rV < 0.002) 
    {
        
        int randomNumber = (std::rand() % 4);
        inamici.push_back(hexagoane[randomNumber]);
        int randomX = (std::rand() % 3) + 1;
        if (randomX == 1) {
            inamicPositions.push_back(glm::vec2(1250, 80));
        }
        if (randomX == 2) {
            inamicPositions.push_back(glm::vec2(1250, 210));
        }
        if (randomX == 3) {
            inamicPositions.push_back(glm::vec2(1250, 340));
        }
        if (randomNumber == 0) {
            inamic1Positions.push_back(inamicPositions[inamicPositions.size() - 1]);
            inamic1.push_back({ 0 });
            hexa1.push_back(0);
        }
        if (randomNumber == 1) {
            inamic2Positions.push_back(inamicPositions[inamicPositions.size() - 1]);
            inamic2.push_back({ 0 });
            hexa2.push_back(0);
        }
        if (randomNumber == 2) {
            inamic3Positions.push_back(inamicPositions[inamicPositions.size() - 1]);
            inamic3.push_back({ 0 });
            hexa3.push_back(0);
        }
        if (randomNumber == 3) {
            inamic4Positions.push_back(inamicPositions[inamicPositions.size() - 1]);
            inamic4.push_back({ 0 });
            hexa4.push_back(0);
        }


    }


    //pentru fiecare inamic, verific daca a ajuns la capatul tablei si verific daca a depasit un romb care trebuie sters
    for (size_t i = 0; i < inamic1Positions.size(); ++i) {

        if (inamic1Positions[i].x > 95) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(inamic1Positions[i].x, inamic1Positions[i].y);
            RenderMesh2D(meshes["hexagon1"], shaders["VertexColor"], modelMatrix);
            inamic1Positions[i].x = inamic1Positions[i].x - deltaTimeSeconds * 100;
            auto it = std::find_if(rhombusPositions.begin(), rhombusPositions.end(), [&](const auto& rhombusPos) {
                return rhombusPos.x >= (inamic1Positions[i].x - 47) && rhombusPos.y == inamic1Positions[i].y;
                });

            if (it != rhombusPositions.end()) {
                size_t index = std::distance(rhombusPositions.begin(), it);
                if (tipuriromb[index] == 1) {
                    rhombus1--;
                }
                else if (tipuriromb[index] == 2) {
                    rhombus2--;
                }
                else if (tipuriromb[index] == 3) {
                    rhombus3--;
                }
                else if (tipuriromb[index] == 4) {
                    rhombus4--;
                }
                rhombuserase.push_back(rhombusPositions[index]);
                colorerase.push_back(tipuriromb[index]);
                scalerhombus.push_back(1);
                rhombusPositions.erase(it);
                tipuriromb.erase(tipuriromb.begin() + index);

            }
        }

        if (inamic1Positions[i].x < 95) {
            lives--;
            inamic1Positions.erase(inamic1Positions.begin() + i);
            hexa1.erase(hexa1.begin() + i);
        }

    }

    for (size_t i = 0; i < inamic2Positions.size(); ++i) {

        if (inamic2Positions[i].x > 95) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(inamic2Positions[i].x, inamic2Positions[i].y);
            RenderMesh2D(meshes["hexagon2"], shaders["VertexColor"], modelMatrix);
            inamic2Positions[i].x = inamic2Positions[i].x - deltaTimeSeconds * 100;
            auto it = std::find_if(rhombusPositions.begin(), rhombusPositions.end(), [&](const auto& rhombusPos) {
                return rhombusPos.x >= (inamic2Positions[i].x - 47) && rhombusPos.y == inamic2Positions[i].y;
                });

            if (it != rhombusPositions.end()) {
                size_t index = std::distance(rhombusPositions.begin(), it);
                if (tipuriromb[index] == 1) {
                    rhombus1--;
                }
                else if (tipuriromb[index] == 2) {
                    rhombus2--;
                }
                else if (tipuriromb[index] == 3) {
                    rhombus3--;
                }
                else if (tipuriromb[index] == 4) {
                    rhombus4--;
                }
                rhombuserase.push_back(rhombusPositions[index]);
                colorerase.push_back(tipuriromb[index]);
                scalerhombus.push_back(1);
                rhombusPositions.erase(it);
                tipuriromb.erase(tipuriromb.begin() + index);


            }

        }

        if (inamic2Positions[i].x < 95) {
            lives--;
            inamic2Positions.erase(inamic2Positions.begin() + i);
            hexa2.erase(hexa2.begin() + i);
        }

    }

    for (size_t i = 0; i < inamic3Positions.size(); ++i) {

        if (inamic3Positions[i].x > 95) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(inamic3Positions[i].x, inamic3Positions[i].y);
            RenderMesh2D(meshes["hexagon3"], shaders["VertexColor"], modelMatrix);
            inamic3Positions[i].x = inamic3Positions[i].x - deltaTimeSeconds * 100;
            auto it = std::find_if(rhombusPositions.begin(), rhombusPositions.end(), [&](const auto& rhombusPos) {
                return rhombusPos.x >= (inamic3Positions[i].x - 47) && rhombusPos.y == inamic3Positions[i].y;
                });

            if (it != rhombusPositions.end()) {
                size_t index = std::distance(rhombusPositions.begin(), it);
                if (tipuriromb[index] == 1) {
                    rhombus1--;
                }
                else if (tipuriromb[index] == 2) {
                    rhombus2--;
                }
                else if (tipuriromb[index] == 3) {
                    rhombus3--;
                }
                else if (tipuriromb[index] == 4) {
                    rhombus4--;
                }
                rhombuserase.push_back(rhombusPositions[index]);
                colorerase.push_back(tipuriromb[index]);
                scalerhombus.push_back(1);
                rhombusPositions.erase(it);
                tipuriromb.erase(tipuriromb.begin() + index);

            }
        }

        if (inamic3Positions[i].x < 95) {
            lives--;
            inamic3Positions.erase(inamic3Positions.begin() + i);
            hexa3.erase(hexa3.begin() + i);
        }

    }

    for (size_t i = 0; i < inamic4Positions.size(); ++i) {

        if (inamic4Positions[i].x > 95) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(inamic4Positions[i].x, inamic4Positions[i].y);
            RenderMesh2D(meshes["hexagon4"], shaders["VertexColor"], modelMatrix);
            inamic4Positions[i].x = inamic4Positions[i].x - deltaTimeSeconds * 100;
            auto it = std::find_if(rhombusPositions.begin(), rhombusPositions.end(), [&](const auto& rhombusPos) {
                return rhombusPos.x >= (inamic4Positions[i].x - 47) && rhombusPos.y == inamic4Positions[i].y;
                });

            if (it != rhombusPositions.end()) {
                size_t index = std::distance(rhombusPositions.begin(), it);
                if (tipuriromb[index] == 1) {
                    rhombus1--;
                }
                else if (tipuriromb[index] == 2) {
                    rhombus2--;
                }
                else if (tipuriromb[index] == 3) {
                    rhombus3--;
                }
                else if (tipuriromb[index] == 4) {
                    rhombus4--;
                }
                rhombuserase.push_back(rhombusPositions[index]);
                colorerase.push_back(tipuriromb[index]);
                scalerhombus.push_back(1);
                rhombusPositions.erase(it);
                tipuriromb.erase(tipuriromb.begin() + index);

            }
        }

        if (inamic4Positions[i].x < 95) {
            lives--;
            inamic4Positions.erase(inamic4Positions.begin() + i);
            hexa4.erase(hexa4.begin() + i);
        }

    }

    processEntities(inamic1erase, scales1, "hexagon1",deltaTimeSeconds);
    processEntities(inamic2erase, scales2, "hexagon2",deltaTimeSeconds);
    processEntities(inamic3erase, scales3, "hexagon3",deltaTimeSeconds);
    processEntities(inamic4erase, scales4, "hexagon4",deltaTimeSeconds);


    for (auto it = rhombuserase.begin(); it != rhombuserase.end();) {

        int index = std::distance(rhombuserase.begin(), it);
        scalerhombus[index] -= deltaTimeSeconds * 2;
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(it->x, it->y);
        modelMatrix *= transform2D::Scale(scalerhombus[index], scalerhombus[index]);
        RenderMesh2D(meshes["rhombus" + std::to_string(colorerase[index])], shaders["VertexColor"], modelMatrix);

        if (scalerhombus[index] < 0) {
            it = rhombuserase.erase(it);
            scalerhombus.erase(scalerhombus.begin() + index);
            colorerase.erase(colorerase.begin() + index);
        }
        else {
            ++it;
        }
    }




}


void tema1::processEntities(std::vector<glm::vec2>& entities, std::vector<float>& scales, const std::string& meshName, float deltaTimeSeconds) {
    for (auto it = entities.begin(); it != entities.end();) {
        int index = std::distance(entities.begin(), it);

        scales[index] -= deltaTimeSeconds * 2;

        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(it->x, it->y);
        modelMatrix *= transform2D::Scale(scales[index], scales[index]);

        RenderMesh2D(meshes[meshName], shaders["VertexColor"], modelMatrix);

        if (scales[index] < 0) {
            it = entities.erase(it);
            scales.erase(scales.begin() + index);
        }
        else {
            ++it;
        }
    }
}




void tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event

    
}


void tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event

    //verific daca apas pe o stea
    if (button == GLFW_MOUSE_BUTTON_2)
    {
        for (auto it = starPositions.begin(); it != starPositions.end();)
        {
            const glm::vec2& starPos = *it;
            if(mouseX >= starPos.x - 35 && mouseX <= starPos.x + 35 && 720 - mouseY >= starPos.y - 35 && 720 - mouseY <= starPos.y + 35)
			{   
		
				it = starPositions.erase(it);
                if (stars < 12 && lives > 0) {
                    stars++;
                    lastpointpos = lastpointpos + 40;
                    pointsPositions.push_back(glm::vec2(lastpointpos * window->GetResolution().x, 600 * window->GetResolution().y));
                    pointsPositions.push_back(glm::vec2(lastpointpos * window->GetResolution().x, 600 * window->GetResolution().y));
                }


			}
            else
            {
                ++it;
            }

        }

        //verific daca apas pe un romb
        if (mouseX >= 100 - 35 && mouseX <= 100 + 35 && 720 - mouseY >= 650 - 35 && 720 - mouseY <= 650 + 35 && stars > 0)
        {
			selectedRhombusIndex = 1;
            rhombus1++;
            move = false;
		}
        else if (mouseX >= 260 - 35 && mouseX <= 260 + 35 && 720 - mouseY >= 650 - 35 && 720 - mouseY <= 650 + 35 && stars > 1)
        {
			selectedRhombusIndex = 2;
            rhombus2++;
            move = false;
		}
        else if (mouseX >= 420 - 35 && mouseX <= 420 + 35 && 720 - mouseY >= 650 - 35 && 720 - mouseY <= 650 + 35 && stars > 1)
        {
			selectedRhombusIndex = 3;
            rhombus3++;
            move = false;
		}
        else if (mouseX >= 580 - 35 && mouseX <= 580 + 35 && 720 - mouseY >= 650 - 35 && 720 - mouseY <= 650 + 35 && stars > 2)
        {
			selectedRhombusIndex = 4;
            rhombus4++;
            move = false;
		}
        else
        {
			selectedRhombusIndex = -1;
		}
    }

    //verific daca apas pe un romb plasat care trebuie sters
    if (button == GLFW_MOUSE_BUTTON_3) {
        mouseY = 720 - mouseY;
        if (((mouseY > 30 && mouseY < 130) || (mouseY > 160 && mouseY < 260) || (mouseY > 290 && mouseY < 420)) &&
            ((mouseX > 100 && mouseX < 200) || (mouseX > 230 && mouseX < 330) || (mouseX > 360 && mouseX < 460))) {

            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 80;

            }
            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 80;
            }
            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 80;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 210;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 210;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 210;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 340;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 340;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 340;
            }

            //sterg rombul plasat pe care se apasa
            auto iterator = std::find_if(rhombusPositions.begin(), rhombusPositions.end(), [&](const auto& rhPos) {
                return rhPos.x == mouseX && rhPos.y == mouseY;
                });

            if (iterator != rhombusPositions.end()) {
                size_t index = std::distance(rhombusPositions.begin(), iterator);
                if (tipuriromb[index] == 1) {
                    rhombus1--;
                    auto iterator1 = std::find_if(rhombus1Positions.begin(), rhombus1Positions.end(), [&](const auto& rh1Pos) {
                        return rh1Pos.x == mouseX && rh1Pos.y == mouseY;
                        });
                    size_t index1 = std::distance(rhombus1Positions.begin(), iterator1);
                    rhombus1Positions.erase(iterator1);
                }
                else if (tipuriromb[index] == 2) {
                    auto iterator2 = std::find_if(rhombus2Positions.begin(), rhombus2Positions.end(), [&](const auto& rh2Pos) {
                        return rh2Pos.x == mouseX && rh2Pos.y == mouseY;
                        });
                    size_t index2 = std::distance(rhombus2Positions.begin(), iterator2);
                    for (int romb2 = index2; romb2 < rhombus2 - 1; ++romb2) {
                        posx2[romb2] = posx2[romb2 + 1];
                        posy2[romb2] = posy2[romb2 + 1];
                    }
                    rhombus2--;
                    
                }
                else if (tipuriromb[index] == 3) {
                    auto iterator3 = std::find_if(rhombus3Positions.begin(), rhombus3Positions.end(), [&](const auto& rh3Pos) {
                        return rh3Pos.x == mouseX && rh3Pos.y == mouseY;
                        });
                    size_t index3 = std::distance(rhombus3Positions.begin(), iterator3);
                    for (int romb3 = index3; romb3 < rhombus3 - 1; ++romb3) {
                        posx3[romb3] = posx3[romb3 + 1];
                        posy3[romb3] = posy3[romb3 + 1];
                    }
                    rhombus3--;
                }
                else if (tipuriromb[index] == 4) {
                    auto iterator4 = std::find_if(rhombus4Positions.begin(), rhombus4Positions.end(), [&](const auto& rh4Pos) {
                        return rh4Pos.x == mouseX && rh4Pos.y == mouseY;
                        });
                    size_t index4 = std::distance(rhombus4Positions.begin(), iterator4);
                    for (int romb4 = index4; romb4 < rhombus4 - 1; ++romb4) {
                        posx4[romb4] = posx4[romb4 + 1];
                        posy4[romb4] = posy4[romb4 + 1];
                    }
                    rhombus4--;
                }

                tipuriromb.erase(tipuriromb.begin() + index);
                rhombusPositions.erase(iterator);
                selectedRhombusIndex = -1;
            }
        }
    }

}


void tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    //verific daca am facut release intr un patrat pentru a plasa rombul
    int ok = 0;
    if (selectedRhombusIndex == 1) {
        ok = 1;
    }
    else if (selectedRhombusIndex == 2 || selectedRhombusIndex == 3) {
        ok = 2;
    }
    else if (selectedRhombusIndex == 4) {
		ok = 3;
    }
    if (button == GLFW_MOUSE_BUTTON_2 && selectedRhombusIndex != -1 && stars - ok >= 0)
    {
        mouseY = 720 - mouseY;
        if(((mouseY >= 30 && mouseY <= 130) || (mouseY >= 160 && mouseY <= 260) || (mouseY >= 290 && mouseY <= 420)) && ((mouseX >= 100 && mouseX <= 200) || (mouseX >= 230 && mouseX <= 330) || (mouseX >= 360 && mouseX <= 460)))
        {
            move = true;
            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 80;
       
            }
            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 80;
            }
            if ((mouseY >= 30 && mouseY <= 130) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 80;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 210;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 210;
            }
            if ((mouseY >= 160 && mouseY <= 260) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 210;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 100 && mouseX <= 200))
            {
                mouseX = 150;
                mouseY = 340;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 230 && mouseX <= 330))
            {
                mouseX = 280;
                mouseY = 340;
            }
            if ((mouseY >= 290 && mouseY <= 390) && (mouseX >= 360 && mouseX <= 460))
            {
                mouseX = 410;
                mouseY = 340;
            }
            if (selectedRhombusIndex == 1) {
                if (!pointsPositions.empty() && stars != 0) {
                    pointsPositions.erase(pointsPositions.end() - 1, pointsPositions.end());
                    lastpointpos = lastpointpos - 40;
                    stars--;

                    posx1[rhombus1 - 1] = mouseX;
                    posy1[rhombus1 - 1] = mouseY;
                    tipuriromb.push_back(1);
                    rhombusPositions.push_back(glm::vec2(posx1[rhombus1 - 1], posy1[rhombus1 - 1]));
                    rhombus1Positions.push_back(glm::vec2(posx1[rhombus1 - 1], posy1[rhombus1 - 1]));

    
                }

            }
            if (selectedRhombusIndex == 2) {
                if (!pointsPositions.empty() && stars != 0) {
                    pointsPositions.erase(pointsPositions.end() - 2, pointsPositions.end());
                    lastpointpos = lastpointpos - 80;
                    stars -= 2;

                    posx2[rhombus2 - 1] = mouseX;
                    posy2[rhombus2 - 1] = mouseY;
                    tipuriromb.push_back(2);
                    rhombusPositions.push_back(glm::vec2(posx2[rhombus2 - 1], posy2[rhombus2 - 1]));
                    rhombus2Positions.push_back(glm::vec2(posx2[rhombus2 - 1], posy2[rhombus2 - 1]));


                }

            }
            if (selectedRhombusIndex == 3) {
                if (!pointsPositions.empty() && stars != 0) {
                    pointsPositions.erase(pointsPositions.end() - 2, pointsPositions.end());
                    lastpointpos = lastpointpos - 80;
                    stars -= 2;

                    posx3[rhombus3 - 1] = mouseX;
                    posy3[rhombus3 - 1] = mouseY;
                    tipuriromb.push_back(3);
                    rhombusPositions.push_back(glm::vec2(posx3[rhombus3 - 1], posy3[rhombus3 - 1]));
                    rhombus3Positions.push_back(glm::vec2(posx3[rhombus3 - 1], posy3[rhombus3 - 1]));


                }
            }
            if (selectedRhombusIndex == 4) {
                if (!pointsPositions.empty() && stars != 0) {
                    pointsPositions.erase(pointsPositions.end() - 3, pointsPositions.end());
                    lastpointpos = lastpointpos - 120;
                    stars -= 3;
                    
                    posx4[rhombus4 - 1] = mouseX;
                    posy4[rhombus4 - 1] = mouseY;
                    tipuriromb.push_back(4);
                    rhombusPositions.push_back(glm::vec2(posx4[rhombus4 - 1], posy4[rhombus4 - 1]));
                    rhombus4Positions.push_back(glm::vec2(posx4[rhombus4 - 1], posy4[rhombus4 - 1]));

                }

            }
            selectedRhombusIndex = -1;

        }

        else {
            if (selectedRhombusIndex == 1) {
                rhombus1--;
            }
            if (selectedRhombusIndex == 2) {
                rhombus2--;
            }
            if (selectedRhombusIndex == 3) {
                rhombus3--;
            }
            if (selectedRhombusIndex == 4) {
                rhombus4--;
            }
            selectedRhombusIndex = -2;
        }

    }
}


void tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema1::OnWindowResize(int width, int height)
{
}
