#include "blackjack.hpp"

void Player::check() {
	getPlayerNum();
	if (playernum == 0) {
		playernum += rand() % 11;
	}
}

void Computer::check() {
	getComputerNum();
	if (computernum == 0) {
		computernum += rand() % 11;
	}
}

int Computer::play() {
	if (getComputerNum() < 18 && getComputerNum() != 21) {
		computernum += rand() % 11;
		check();
		//std::cout << "Computer value is: " << getComputerNum() << std::endl;
	}
	else {
		return computernum;
	}
	return computernum;
}

int Player::play() {
	if (getPlayerNum() != 21) {
		playernum += rand() % 11;
		check();
		std::cout << "Your value is: " << getPlayerNum() << std::endl;
		return playernum;
	}
	return playernum;
}


int main() {
	
	srand(time(nullptr));

	Player human;

	Computer opponent;

	human.check();
	opponent.check();

	std::cout << "Your value is: " << human.getPlayerNum() << std::endl;

	char choice = '0';

	//std::cout << "Computer value is: " << opponent.getComputerNum() << std::endl;

	do {
		std::cout << "Would you like to stand or hit? [s/h]: " << std::endl;
		std::cin >> choice;
		if (choice == 'h') {
			human.play();
			human.check();
			opponent.play();
			opponent.check();
		}
		else if (choice == 's') {
			if (human.getPlayerNum() > opponent.getComputerNum()) {
				opponent.play();
				opponent.check();
				std::cout << "Player value: " << human.getPlayerNum() << "\n";
				std::cout << "Computer value: " << opponent.getComputerNum() << "\n";
				std::cout << "You win!";
			}
			else {
				opponent.play();
				opponent.check();
				std::cout << "Player value: " << human.getPlayerNum() << "\n";
				std::cout << "Computer value: " << opponent.getComputerNum() << "\n";
				std::cout << "You lose!";
			}
		}
	} while (human.getPlayerNum() <= 21 && opponent.getComputerNum() <= 21 && choice != 's');
}