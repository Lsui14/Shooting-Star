#include "Scene3.h"
void Scene3::Init3() {
    loader = new ModelLoader();
    SetDrawVertexes(false);
    SetDrawBox(true);
    Init(100, 100, 100, Color(1, 1, 1), true);

    CreateText();
    CreateModel();

    loader->Clear();
}
void Scene3::CreateText() {
    Text* texto2 = new Text();
    texto2->SetText("Has perdido, lo siento");
    texto2->SetPosition(Vector3D(1, 2, 5));
    texto2->SetColor(Color(0, 0, 0));
    AddGameObject(texto2);
}
void Scene3::CreateModel() {
    Model* final = new Model();
    loader->LoadModel("..\\..\\3dModels\\Star.obj");
    *final = loader->GetModel();
    final->SetPosition(Vector3D(5.5, 7, 5));
    final->SetSpeed(Vector3D(0.0, 0, 0));
    final->SetOrientation(Vector3D(60, 0, 0));
    final->SetOrientationSpeed(Vector3D(0, 0., 0));
    final->PaintColor(Color(0.6, 0.3, 0.3));
    AddGameObject(final);
    loader->Clear();
}