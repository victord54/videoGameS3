#ifndef WRITE_READ_FILE_HPP
#define WRITE_READ_FILE_HPP

#include <iostream>
#include <fstream>

class FichierIO {
	private:
		std::string str;
	
	public:
		FichierIO(std::string s) {
			str = s;
		}

		void ecrire(std::string name, int score) {
			std::ofstream file(str, std::ios::app);
			if (file) {
				file << name << " " << score << std::endl;
			}
		}

		void lire(int line) {
			std::ifstream file(str);
			if (file) {
				std::string name;
				std::string tmp;
				int score;
				for (int i = 0; i < line; i++) {
					file >> name;
					file >> name;
				}
				file >> name;
				std::cout << name;
				file >> tmp;
				score = std::stoi(tmp);
				std::cout << " : " << score << std::endl;
			} else {
				std::cout << "Erreur ouverture fichier" << std::endl;
			}
		}
};

#endif