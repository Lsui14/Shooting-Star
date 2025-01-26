#include "Scene2.h"
void Scene2::Init2() {
    loader = new ModelLoader();
    SetDrawVertexes(false);
    SetDrawBox(true);
    Init(100, 100, 100, Color(1, 1, 1), true);

    CreateText();
    CreateModel();

    loader->Clear();
}
void Scene2::CreateText() {
    Text* texto1 = new Text();
    texto1->SetText("¡Has ganado, enhorabuena!");
    texto1->SetPosition(Vector3D(-1, 2, 5));
    texto1->SetColor(Color(0, 0, 0));
    AddGameObject(texto1);
}
void Scene2::CreateModel() {
    Model* ganar = new Model();
    loader->LoadModel("..\\..\\3dModels\\Star.obj");
    *ganar = loader->GetModel();
    ganar->SetPosition(Vector3D(5.5, 10, 5));
    ganar->SetSpeed(Vector3D(0.0, 0, 0));
    ganar->SetOrientation(Vector3D(0, 0, 0));
    ganar->SetOrientationSpeed(Vector3D(0, 1., 0));
    ganar->PaintColor(Color(0.6, 0.3, 0.3));
    AddGameObject(ganar);
    loader->Clear();

    Model* ganar2 = new Model();
    loader->LoadModel("..\\..\\3dModels\\Star.obj");
    *ganar2 = loader->GetModel();
    ganar2->SetPosition(Vector3D(3.5, 7, 5));
    ganar2->SetSpeed(Vector3D(0.0, 0, 0));
    ganar2->SetOrientation(Vector3D(0, 0, 0));
    ganar2->SetOrientationSpeed(Vector3D(0, 1., 0));
    ganar2->PaintColor(Color(0.6, 0.3, 0.3));
    AddGameObject(ganar2);
    loader->Clear();

    Model* ganar3 = new Model();
    loader->LoadModel("..\\..\\3dModels\\Star.obj");
    *ganar3 = loader->GetModel();
    ganar3->SetPosition(Vector3D(7.5, 7, 5));
    ganar3->SetSpeed(Vector3D(0.0, 0, 0));
    ganar3->SetOrientation(Vector3D(0, 0, 0));
    ganar3->SetOrientationSpeed(Vector3D(0, 1., 0));
    ganar3->PaintColor(Color(0.6, 0.3, 0.3));
    AddGameObject(ganar3);
    loader->Clear();
}