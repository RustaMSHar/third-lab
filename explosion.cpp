#include <iostream>
#include <Windows.h>
#include <chrono>

#include "figura.h"
#include "explosion.h"
#include "symbol.h"

using namespace std;

int Explosion::getType()
{
	return 1;
}

void Explosion::run(int console_height)
{
	for (int i = 0, j = current_raduis - 1; i <= current_raduis - 1; i++, j--){
		
		if (symbol.coord_y + i < console_height) {
			
			symbol.gotoXY(symbol.coord_x + j, symbol.coord_y + i);
			cout << " ";

			symbol.gotoXY(symbol.coord_x - j, symbol.coord_y + i);
			cout << " ";
		}
	}

	for (int i = 1, j = current_raduis - 2; i <= current_raduis; i++, j--){
		
		if (symbol.coord_y - i < console_height) {
			
			symbol.gotoXY(symbol.coord_x + j, symbol.coord_y - i);
			cout << " ";

			symbol.gotoXY(symbol.coord_x - j, symbol.coord_y - i);
			cout << " ";
		}
	}

	if (current_raduis <= radius) {
		for (int i = 0, j = current_raduis; i <= current_raduis; i++, j--){
			
			if (symbol.coord_y + i < console_height) {
				symbol.gotoXY(symbol.coord_x + j, symbol.coord_y + i);
				symbol.setColor(rand() % 15+1, 0);
				cout << (char)((rand() % 63) + 33);

				symbol.gotoXY(symbol.coord_x - j, symbol.coord_y + i);
				symbol.setColor(rand() % 15+1, 0);
				cout << (char)((rand() % 63) + 33);
			}
		}

		for (int i = 1, j = current_raduis - 1; i <= current_raduis; i++, j--){
			
			if (symbol.coord_y - i > -1 && symbol.coord_y - i < console_height) {
				symbol.gotoXY(symbol.coord_x + j, symbol.coord_y - i);
				symbol.setColor(rand() % 15+1, 0);
				cout << (char)((rand() % 63) + 33);

				symbol.gotoXY(symbol.coord_x - j, symbol.coord_y - i);
				symbol.setColor(rand() % 15+1, 0);
				cout << (char)((rand() % 63) + 33);
			}
		}

	}
	
	current_raduis++;
	time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() + 500;
}
