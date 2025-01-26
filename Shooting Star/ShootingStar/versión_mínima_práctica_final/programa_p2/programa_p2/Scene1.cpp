#include "Scene1.h"
#include <random>
#include <iostream>
#include <cmath>

void Scene1::Init1(bool vertex, bool box, float x, float y, float z, Color color, bool fondo) {
	loader = new ModelLoader();
	SetDrawVertexes(vertex);
	SetDrawBox(box);
	Init(x, y, z, color, fondo);

	loader->Clear();
}
void Scene1::CreateEnemies(int numEnemigos1, int numEnemigos2, int numEnemigos3) {
    if (numEnemigos3 > 1) {
        cout << "Numero de enemigos invalido" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = 0; i < numEnemigos1; ++i) {
            random_device rd1;
            mt19937 gen1(rd1());
            random_device rd2;
            mt19937 gen2(rd2());
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_real_distribution<double> dis(0.0, 1.0);
            uniform_real_distribution<double> dis2(0.0, 10.0);
            double a = round(dis(gen1) * 10) / 10;
            double b = round(dis(gen2) * 10) / 10;
            double c = round(dis(gen3) * 10) / 10;
            double d = round(dis2(gen1));
            Enemigo1* enemigo1 = new Enemigo1();
            enemigo1->SetVelocidadMovimiento(0.003);
            Cube* cube1 = new Cube();
            cube1->SetColor(Color(a, b, c));
            cube1->SetPosition(Vector3D(d, 14, 5));
            cube1->SetSpeed(Vector3D(-0.0, -0.0, 0.));
            cube1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
            enemigo1->SetFigura(*cube1);

            AddGameEnemigo1(enemigo1);
        
        }

        for (int i = 0; i < numEnemigos2; ++i) {
            random_device rd1;
            mt19937 gen1(rd1());
            random_device rd2;
            mt19937 gen2(rd2());
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_real_distribution<double> dis(0.0, 1.0);
            uniform_real_distribution<double> dis2(0.0, 10.0);
            double a = round(dis(gen1) * 10) / 10;
            double b = round(dis(gen2) * 10) / 10;
            double c = round(dis(gen3) * 10) / 10;
            double d = round(dis2(gen1));
            Enemigo2* enemigo4 = new Enemigo2();
            enemigo4->SetVelocidadMovimiento(0.003);
            Sphere* sphere4 = new Sphere();
            sphere4->SetRadius(0.9);
            sphere4->SetColor(Color(a, b, c));
            sphere4->SetPosition(Vector3D(d, 11, 5));
            sphere4->SetSpeed(Vector3D(0.0, 0.0, -0.0));
            enemigo4->SetFigura(*sphere4);

            AddGameEnemigo2(enemigo4);
        }
    
        for (int i = 0; i < numEnemigos3; ++i) {
            random_device rd1;
            mt19937 gen1(rd1());
            random_device rd2;
            mt19937 gen2(rd2());
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_real_distribution<double> dis(0.0, 1.0);
            uniform_real_distribution<double> dis2(0.0, 10.0);
            double a = round(dis(gen1) * 10) / 10;
            double b = round(dis(gen2) * 10) / 10;
            double c = round(dis(gen3) * 10) / 10;
            double d = round(dis2(gen1));
            Torreta* torreta = new Torreta();
            Cube* cube7 = new Cube();
            cube7->SetColor(Color(a, b, c));
            cube7->SetSize(1.5);
            cube7->SetPosition(Vector3D(d, 10, 5));
            cube7->SetSpeed(Vector3D(-0.0, -0.0, 0.));
            cube7->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
            torreta->SetFigura(*cube7);

            Cuboid* cuboid = new Cuboid();
            cuboid->SetColor(Color(0.2, 0.2, 0.7));
            cuboid->SetPosition(Vector3D(d, 9, 5));
            cuboid->SetSpeed(Vector3D(-0.0, -0.0, 0.0));
            cuboid->SetOrientation(Vector3D(0., 0., 0.));
            cuboid->SetOrientationSpeed(Vector3D(0., 0., 0.));
            torreta->SetCanon(*cuboid);
            torreta->SetPosDisparo(Vector3D(d, 9, 5));
            AddGameTorreta(torreta);
        }
    }
}

