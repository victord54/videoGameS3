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

		std::string lire(int line) {
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
				file >> tmp;
				score = std::stoi(tmp);
				std::string s;
				s.append(name + " : " + std::to_string(score));
				return s;

			} else {
				std::cout << "Erreur ouverture fichier" << std::endl;
				return 0;
			}
		}

		int getLineMax() {
			std::ifstream file(str);
			int nbLignes = 0;
			std::string ligne;

			if (file) {
				while (std::getline(file, ligne)) {
					nbLignes++;
				}
			}
			file.close();
			return nbLignes;
		}
};

#endif