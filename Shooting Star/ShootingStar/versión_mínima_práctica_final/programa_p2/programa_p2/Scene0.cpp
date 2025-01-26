#include "Scene0.h"
void Scene0::Init0() {
    loader = new ModelLoader();
    SetDrawVertexes(false);
    SetDrawBox(true);
    Init(100, 100, 100, Color(1, 1, 1), true);

    CreateText();
    CreateModel();

    loader->Clear();
}

void Scene0::CreateText() {
    Text* texto = new Text();
    texto->SetText("Pulsa J para jugar");
    texto->SetPosition(Vector3D(1, 2, 5));
    texto->SetColor(Color(0, 0, 0));
    AddGameObject(texto);
}

void Scene0::CreateModel() {
    Model* inicio = new Model();
    loader->LoadModel("..\\..\\3dModels\\Star.obj");
    *inicio = loader->GetModel();
    inicio->SetPosition(Vector3D(5.5, 7, 5));
    inicio->SetSpeed(Vector3D(0.0, 0, 0));
    inicio->SetOrientationSpeed(Vector3D(0, 1., 0));
    inicio->PaintColor(Color(0.6, 0.3, 0.3));
    AddGameObject(inicio);
}
