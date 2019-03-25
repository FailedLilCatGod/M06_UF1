#include <iostream>
#include <fstream>
#include <string>

std::string* textures;
std::string title;

int LoadTextures(std::ifstream& file, int num)
{
	std::string word;
	textures = new std::string[num + 1];
	textures[0] = "none";

	int counter = 1;
	while (counter < num + 1)
	{
		//1; suelo_verde.png
		std::getline(file, word, ';');
		
		std::getline(file, word, ';');
		textures[counter] = word;
		
		std::cout << word << '\n';
		
		std::getline(file, word, '\n');
		
		counter++;
	}

	return 0;
}

int main(int argc, char* argv[]) {
	
	std::ifstream game_conf("../M06_UF1/game.csv");


	if (!game_conf.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	int textures_num = 0;
	//TITLE;Las Aventuras Emocionantes de Marsal;;
	while (game_conf.good())
	{
		std::getline(game_conf, word, ';');

		if (word.compare("TEXTURES") == 0)
		{
			std::getline(game_conf, word, ';');
			textures_num = std::stoi(word);
			std::getline(game_conf, word, '\n');
			LoadTextures(game_conf, textures_num);
		}
		else if (word.compare("TITLE") == 0)
		{
			std::getline(game_conf, word, ';');
			title = word;
			std::cout << title << std::endl;
			std::getline(game_conf, word, '\n');
		}
	}
	game_conf.close();

	return 0;
	//Crear Archivo

	/*
	std::ofstream archivo;
	archivo.open("datos.csv");

	archivo << "a;b;c;;\n";
	archivo << "d;e;f;;\n";
	archivo << "1;2;3.456;;\n";

	archivo.close();
	*/
	
	//Leer Archivo

	/*
	std::ifstream ip("../M06_UF1/personas.csv");

	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string nombre;
	std::string apellido;
	std::string edad;
	std::string peso;
	int edadi = 0;
	float pesof = .0f;

	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edad, ';');
		std::getline(ip, peso, '\n');

		edadi = std::stoi(edad);
		pesof = std::stof(peso);

		std::cout << "Nombre:" << nombre << " " << apellido << '\n';
		std::cout << "Edad:" << edad << '\n';
		std::cout << "Peso:" << peso << '\n';
		std::cout << "=============" << '\n';
	}

	ip.close();
	*/
	
	return 0;

}