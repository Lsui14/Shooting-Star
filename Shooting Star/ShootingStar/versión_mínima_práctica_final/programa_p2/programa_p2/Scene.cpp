#include "Scene.h"
#include <iostream>

void Scene::Init(float x, float y, float z, Color color, bool fondo)
{
	camera.SetPosition(Vector3D(this->boundary.GetX() / 2, this->boundary.GetY() / 2, this->boundary.GetZ() * 3));
	
	Vector3D aux = this->GetBoundary();
	aux.SetX(x);
	aux.SetY(y);
	aux.SetZ(z);
	this->SetBoundary(aux);
	
	if (this->GetDrawVertexes())
	{
		Cube* point1 = new Cube();
		point1->SetColor(Color(0, 0, 1));
		point1->SetPosition(Vector3D(0, 0, 0));
		point1->SetSize(0.2);
		this->AddGameObject(point1);

		Cube* point2 = new Cube();
		point2->SetColor(Color(0, 0, 1));
		point2->SetPosition(Vector3D(0, 0, 0));
		point2->SetSize(0.2);
		this->AddGameObject(point2);

		Cube* point3 = new Cube();
		point3->SetColor(Color(0, 0, 1));
		point3->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), 0));
		point3->SetSize(0.2);
		this->AddGameObject(point3);

		Cube* point4 = new Cube();
		point4->SetColor(Color(0, 0, 1));
		point4->SetPosition(Vector3D(0, this->GetBoundary().GetY(), 0));
		point4->SetSize(0.2);
		this->AddGameObject(point4);

		Cube* point5 = new Cube();
		point5->SetColor(Color(0, 0, 1));
		point5->SetPosition(Vector3D(0, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point5->SetSize(0.2);
		this->AddGameObject(point5);

		Cube* point6 = new Cube();
		point6->SetColor(Color(0, 0, 1));
		point6->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point6->SetSize(0.2);
		this->AddGameObject(point6);

		Cube* point7 = new Cube();
		point7->SetColor(Color(0, 0, 1));
		point7->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, this->GetBoundary().GetZ()));
		point7->SetSize(0.2);
		this->AddGameObject(point7);

		Cube* point8 = new Cube();
		point8->SetColor(Color(0, 0, 1));
		point8->SetPosition(Vector3D(0, 0, this->GetBoundary().GetZ()));
		point8->SetSize(0.2);
		this->AddGameObject(point8);
	}

	if (this->drawBox)
	{
		if (fondo == true) {
			Cuboid* back = new Cuboid();
			back->SetHeight(this->GetBoundary().GetY());
			back->SetWidth(0.01);
			back->SetLength(this->GetBoundary().GetX());
			back->SetColor(color);
			back->SetPosition(Vector3D(0, 0, 0));
			back->SetOrientation(Vector3D(0., 180., 0));
			/*back->SetIsTransparent(true);*/
			this->AddGameObject(back);
		}
		else {
			Cuboid* floor = new Cuboid();
			floor->SetHeight(0.01);
			floor->SetWidth(this->GetBoundary().GetZ());
			floor->SetLength(this->GetBoundary().GetX());
			floor->SetColor(Color(0.5, 0.8, 1));
			floor->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, 0, this->GetBoundary().GetZ() / 2));
			/*floor->SetIsTransparent(true);*/ // Transparencia del cubo
			this->AddGameObject(floor);

			Cuboid* ceil = new Cuboid();
			ceil->SetHeight(0.01);
			ceil->SetWidth(this->GetBoundary().GetZ());
			ceil->SetLength(this->GetBoundary().GetX());
			ceil->SetColor(Color(0.5, 0.8, 1));
			ceil->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY(), this->GetBoundary().GetZ() / 2));
			/*ceil->SetIsTransparent(true);*/
			this->AddGameObject(ceil);

			Cuboid* back = new Cuboid();
			back->SetHeight(this->GetBoundary().GetY());
			back->SetWidth(0.01);
			back->SetLength(this->GetBoundary().GetX());
			back->SetColor(color);
			back->SetPosition(Vector3D(this->GetBoundary().GetX() / 2, this->GetBoundary().GetY() / 2, 0));
			back->SetOrientation(Vector3D(0., 180., 0));
			/*back->SetIsTransparent(true);*/
			this->AddGameObject(back);

			Cuboid* left = new Cuboid();
			left->SetHeight(this->GetBoundary().GetY());
			left->SetWidth(this->GetBoundary().GetZ());
			left->SetLength(0.01);
			left->SetColor(Color(0.2, 0.2, 0.6));
			left->SetPosition(Vector3D(0, this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ() / 2));
			/*left->SetIsTransparent(true);*/
			this->AddGameObject(left);

			Cuboid* right = new Cuboid();
			right->SetHeight(this->GetBoundary().GetY());
			right->SetWidth(this->GetBoundary().GetZ());
			right->SetLength(0.01);
			right->SetColor(Color(0.2, 0.2, 0.6));
			right->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY() / 2, this->GetBoundary().GetZ() / 2));
			/*right->SetIsTransparent(true);*/
			this->AddGameObject(right);
		}	
	}
}

void Scene::Update(const float& timeIncrement)
{
	
	this->camera.Update(timeIncrement);

	for (int idx = 0; idx < this->gameObjects.size() ; idx++)
	{
		this->gameObjects[idx]->Update(timeIncrement);
	}
	for (int idx = 0; idx < this->gameJugador.size(); idx++)
	{
		this->gameJugador[idx]->Update(timeIncrement);
		for (int idx2 = 0; idx2 < this->gameBalasTorreta.size(); idx2++) {
			if (this->gameJugador[idx]->Colision(this->gameBalasTorreta[idx2])) {
				for (int idx3 = 0; idx3 < this->gameTorretas.size(); idx3++) {
					if (this->gameJugador[idx]->GetVida() - this->gameTorretas[idx3]->GetDano() <= 0) {
						ClearJugador();
					}
					else if (this->gameJugador[idx]->GetVida() - this->gameTorretas[idx3]->GetDano() == 2) {
						this->gameJugador[idx]->SetVida(this->gameJugador[idx]->GetVida() - this->gameTorretas[idx3]->GetDano());
						Model* modelo = new Model();
						*modelo = this->gameJugador[idx]->GetModel();
						modelo->PaintColor(Color(0.5,0.2,0.2 ));
						this->gameJugador[idx]->SetModel(*modelo);
					}

					else {
						this->gameJugador[idx]->SetVida(this->gameJugador[idx]->GetVida() - this->gameTorretas[idx3]->GetDano());
						Model* modelo = new Model();
						*modelo = this->gameJugador[idx]->GetModel();
						modelo->PaintColor(Color(0.5, 0., 0.));
						this->gameJugador[idx]->SetModel(*modelo);
					}
				}
				
				ClearOneBalaTorreta(idx2);
			}
		}
	}

	for (int idx = 0; idx < this->gameEnemigos.size(); idx++)
	{


		if (this->gameEnemigos.size() > 0) {
			this->gameEnemigos[idx]->Update(timeIncrement);
		}
		if (this->gameEnemigos.size() > 0) {

			if (this->gameEnemigos[idx]->Impacto(0)) {
				for (int idx3 = 0; idx3 < this->gameJugador.size(); idx3++) {
					if (this->gameJugador[idx3]->GetVida() - this->gameEnemigos[idx]->GetDano() <= 0) {
						ClearJugador();
					}
					else if (this->gameJugador[idx3]->GetVida() - this->gameEnemigos[idx]->GetDano() == 2) {
						

						this->gameJugador[idx3]->SetVida(this->gameJugador[idx3]->GetVida() - this->gameEnemigos[idx]->GetDano());
						ClearOneEnemigo(idx);
						Model* modelo = new Model();
						*modelo = this->gameJugador[idx3]->GetModel();
						modelo->PaintColor(Color(0.5, 0.2, 0.2));
						this->gameJugador[idx3]->SetModel(*modelo);
					}

					else {
						

						this->gameJugador[idx3]->SetVida(this->gameJugador[idx3]->GetVida() - this->gameEnemigos[idx]->GetDano());
						ClearOneEnemigo(idx);
						Model* modelo = new Model();
						*modelo = this->gameJugador[idx3]->GetModel();
						modelo->PaintColor(Color(0.5, 0., 0.));
						this->gameJugador[idx3]->SetModel(*modelo);
					}
				}

			}
		}
	}

	for (int idx = 0; idx < this->gameEnemigos.size(); idx++){
			for (int idx2 = 0; idx2 < this->gameBalas.size(); idx2++) {
				if (this->gameEnemigos[idx]->Colision(this->gameBalas[idx2])) {
					for (int idx3 = 0; idx3 < this->gameJugador.size(); idx3++) {
						if (this->gameEnemigos[idx]->GetVida() - this->gameJugador[idx3]->GetDano() <= 0) {
							ClearOneEnemigo(idx);
						}
						else {
							this->gameEnemigos[idx]->SetVida(this->gameEnemigos[idx]->GetVida() - this->gameJugador[idx3]->GetDano());
						}
					}
				
					
					ClearOneBala(idx2);
					
					
				}
			}
			
		}
	


	for (int idx = 0; idx < this->gameEnemigos2.size(); idx++)
	{
		if (this->gameEnemigos2.size() > 0) {
			this->gameEnemigos2[idx]->Update(timeIncrement);
		}

		if (this->gameEnemigos2[idx]->Impacto(0)) {
			for (int idx3 = 0; idx3 < this->gameJugador.size(); idx3++) {
				if (this->gameJugador[idx3]->GetVida() - this->gameEnemigos2[idx]->GetDano() <= 0) {
					cout << "Muerte" << endl;
					ClearJugador();
				}

				else if (this->gameJugador[idx3]->GetVida() - this->gameEnemigos2[idx]->GetDano() == 2) {
					
					this->gameJugador[idx3]->SetVida(this->gameJugador[idx3]->GetVida() - this->gameEnemigos2[idx]->GetDano());
					ClearOneEnemigo2(idx);
					Model* modelo = new Model();
					*modelo = this->gameJugador[idx3]->GetModel();
					modelo->PaintColor(Color(0.5, 0.2, 0.2));
					this->gameJugador[idx3]->SetModel(*modelo);
					cout << "quita" << endl;
				}

				else {
					
					this->gameJugador[idx3]->SetVida(this->gameJugador[idx3]->GetVida() - this->gameEnemigos2[idx]->GetDano());
					ClearOneEnemigo2(idx);
					Model* modelo = new Model();
					*modelo = this->gameJugador[idx3]->GetModel();
					modelo->PaintColor(Color(0.5, 0., 0.));
					this->gameJugador[idx3]->SetModel(*modelo);
				}
			}

		}

	}

	for (int idx = 0; idx < this->gameEnemigos2.size(); idx++){
		for (int idx2 = 0; idx2 < this->gameBalas.size(); idx2++) {
			if (this->gameEnemigos2[idx]->Colision(this->gameBalas[idx2])) {
				for (int idx3 = 0; idx3 < this->gameJugador.size(); idx3++) {
					if (this->gameEnemigos2[idx]->GetVida() - this->gameJugador[idx3]->GetDano() <= 0) {
						ClearOneEnemigo2(idx);
					}
					else {
						this->gameEnemigos2[idx]->SetVida(this->gameEnemigos2[idx]->GetVida() - this->gameJugador[idx3]->GetDano());
						Sphere* sphere = new Sphere();
						*sphere = this->gameEnemigos2[idx]->GetFigura();
						sphere->SetColor(Color(sphere->GetColor().GetRed() - 0.3, sphere->GetColor().GetGreen() - 0.3, sphere->GetColor().GetBlue() - 0.3));
						this->gameEnemigos2[idx]->SetFigura(*sphere);
					}
				}
				
				ClearOneBala(idx2);
			}
		}
		
	}

	for (int idx = 0; idx < this->gameTorretas.size(); idx++)
	{
		if (this->gameTorretas.size() > 0) {
			this->gameTorretas[idx]->Update(timeIncrement);
		}

		if (this->gameBalasTorreta.size() == 0) {
			AddGameBalasTorreta(this->gameTorretas[idx]->Disparo(timeIncrement));
		}

		
		for (int idx2 = 0; idx2 < this->gameBalas.size(); idx2++) {
			if (this->gameTorretas[idx]->Colision(this->gameBalas[idx2])) {
				for (int idx3 = 0; idx3 < this->gameJugador.size(); idx3++) {
					if (this->gameTorretas[idx]->GetVida() - this->gameJugador[idx3]->GetDano() <= 0) {
						ClearOneTorreta(idx);
					}
					else {
						this->gameTorretas[idx]->SetVida(this->gameTorretas[idx]->GetVida() - this->gameJugador[idx3]->GetDano());
						Cube* cube = new Cube();
						*cube = this->gameTorretas[idx]->GetFigura();
						cube->SetColor(Color(cube->GetColor().GetRed() - 0.1, cube->GetColor().GetGreen() - 0.1, cube->GetColor().GetBlue() - 0.1));
						this->gameTorretas[idx]->SetFigura(*cube);
					}
				}
				
				ClearOneBala(idx2);
			}
		}

	}
	
	this->checkBoundary();

	for (int idx = 0; idx < this->gameBalas.size(); idx++)
	{
		this->gameBalas[idx]->Update(timeIncrement);
	}

	for (int idx = 0; idx < this->gameBalasTorreta.size(); idx++)
	{
		this->gameBalasTorreta[idx]->Update(timeIncrement);
	}
}

void Scene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size() ; idx++)
	{
		this->gameObjects[idx]->Render();
	}
	for (int idx = 0; idx < this->gameJugador.size(); idx++)
	{
		this->gameJugador[idx]->Render();
	}
	for (int idx = 0; idx < this->gameEnemigos.size(); idx++)
	{
		this->gameEnemigos[idx]->Render();
	}

	for (int idx = 0; idx < this->gameEnemigos2.size(); idx++)
	{
		this->gameEnemigos2[idx]->Render();
	}

	for (int idx = 0; idx < this->gameTorretas.size(); idx++)
	{
		this->gameTorretas[idx]->Render();
		
	}

	for (int idx = 0; idx < this->gameBalas.size(); idx++)
	{
		this->gameBalas[idx]->Render();
	}

	

	for (int idx = 0; idx < this->gameBalasTorreta.size(); idx++)
	{
		this->gameBalasTorreta[idx]->Render();
	}
	

}

void Scene::checkBoundary()
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		if (this->gameObjects[idx]->GetPosition().GetX() < 0 || this->gameObjects[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(-1 * this->gameObjects[idx]->GetSpeed().GetX(),
				this->gameObjects[idx]->GetSpeed().GetY(),
				this->gameObjects[idx]->GetSpeed().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetY() < 0 || this->gameObjects[idx]->GetPosition().GetY() > this->boundary.GetY())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
				-1 * this->gameObjects[idx]->GetSpeed().GetY(),
				this->gameObjects[idx]->GetSpeed().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetZ() < 0 || this->gameObjects[idx]->GetPosition().GetZ() > this->boundary.GetZ())
		{
			this->gameObjects[idx]->SetSpeed(Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
				this->gameObjects[idx]->GetSpeed().GetY(),
				-1 * this->gameObjects[idx]->GetSpeed().GetZ()));
		}
	}

	for (int idx = 0; idx < this->gameEnemigos.size(); idx++)
	{
		
		
		Cube* cube = new Cube();
		*cube = this->gameEnemigos[idx]->GetFigura();
		if (cube->GetPosition().GetX() < 0 )
		{
			
			cube->SetPosition(Vector3D(this->boundary.GetX(),cube->GetPosition().GetY(), cube->GetPosition().GetZ()));
			/*cube->SetSpeed(Vector3D(-1 * cube->GetSpeed().GetX(),
				cube->GetSpeed().GetY(),
				cube->GetSpeed().GetZ()));*/
		}
		else if ( cube->GetPosition().GetX() > this->boundary.GetX()) {
			cube->SetPosition(Vector3D(0, cube->GetPosition().GetY(), cube->GetPosition().GetZ()));
		}

		if (cube->GetPosition().GetY() < 0 || cube->GetPosition().GetY() > this->boundary.GetY())
		{
			cube->SetSpeed(Vector3D(cube->GetSpeed().GetX(),
				-1 * cube->GetSpeed().GetY(),
				cube->GetSpeed().GetZ()));
		}

		if (cube->GetPosition().GetZ() < 0 || cube->GetPosition().GetZ() > this->boundary.GetZ())
		{
			cube->SetSpeed(Vector3D(cube->GetSpeed().GetX(),
				cube->GetSpeed().GetY(),
				-1 * cube->GetSpeed().GetZ()));
		}
		this->gameEnemigos[idx]->SetFigura(*cube);
	}

	for (int idx = 0; idx < this->gameEnemigos2.size(); idx++)
	{
		Sphere* sphere = new Sphere();
		*sphere = this->gameEnemigos2[idx]->GetFigura();
		if (sphere->GetPosition().GetX() < 0 )
		{

			sphere->SetPosition(Vector3D(this->boundary.GetX(), sphere->GetPosition().GetY(), sphere->GetPosition().GetZ()));

			/*sphere->SetSpeed(Vector3D(-1 * sphere->GetSpeed().GetX(),
				sphere->GetSpeed().GetY(),
				sphere->GetSpeed().GetZ()));*/
		}

		else if (sphere->GetPosition().GetX() > this->boundary.GetX()) {
			sphere->SetPosition(Vector3D(0, sphere->GetPosition().GetY(), sphere->GetPosition().GetZ()));
		}

		if (sphere->GetPosition().GetY() < 0 || sphere->GetPosition().GetY() > this->boundary.GetY())
		{
			sphere->SetSpeed(Vector3D(sphere->GetSpeed().GetX(),
				-1 * sphere->GetSpeed().GetY(),
				sphere->GetSpeed().GetZ()));
		}

		if (sphere->GetPosition().GetZ() < 0 || sphere->GetPosition().GetZ() > this->boundary.GetZ())
		{
			sphere->SetSpeed(Vector3D(sphere->GetSpeed().GetX(),
				sphere->GetSpeed().GetY(),
				-1 * sphere->GetSpeed().GetZ()));
		}
		this->gameEnemigos2[idx]->SetFigura(*sphere);
	}

	for (int idx = 0; idx < this->gameBalas.size(); idx++) {
		if (this->gameBalas[idx]->GetPosition().GetY() > this->boundary.GetY()) {
			ClearOneBala(idx);
		}
	}

	for (int idx = 0; idx < this->gameBalasTorreta.size(); idx++) {
		if (this->gameBalasTorreta[idx]->GetPosition().GetY() - this->gameBalasTorreta[idx]->GetHeight() < 0) {
			ClearOneBalaTorreta(idx);
		}
	}
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//cout << "Tecla pulsada: " << key << endl;
	camera.SetOrientation(Vector3D(0, camera.GetOrientation().GetY() + 90, 0));

}

void Scene::ProcessMouseMovement(int x, int y)
{
	//cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y)
{
	//cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;

}