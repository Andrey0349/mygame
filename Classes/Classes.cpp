#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <Windows.h>

using namespace std;

class weapon {
private:
	int DMG, HP, ID;
	string NAME;
public:
	//Сеттеры
	//Дефолт статистика
	void setID(int id) {
		ID = id;
	}
	void setNAME(string name) {
		NAME = name;
	}
	void setDMG() {
		DMG = 200;
	}
	void setHP() {
		HP = 600;
	}
	//Своя статистика
	void setDMG(int dmg) {
		DMG = dmg;
	}
	void setHP(int hp) {
		HP = hp;
	}
	//Геттеры
	int getDMG() { return DMG; }
	int getHP() { return HP; }
	int getID() { return ID; }
	string getNAME() { return NAME; }
	
	void print_weapon_info() {
		cout << getID() << "\t"
			<< getDMG() << "\t"
			<< getHP() << "\t"
			<< getNAME() << "\n";
	}
};

class player {
private:
	int DMG = 0, HP = 0, ID = 0;
	float CRT_CH = 0, CRT_DMG = 0;
	string NAME;
	weapon* equipped_weapon = NULL;

	int totalDMG = 0;
	int totalHP = 0;
	float totalCRT_CH = 0;
	float totalCRT_DMG = 0;

public:
	//сеттеры
	//Дефолт статистика
	void setNAME() {
		NAME = "UNKNOWN";
	}
	void setID(int id) {
		ID = id;
	}
	void setDMG() {
		DMG = 100;
	}
	void setHP() {
		HP = 1000;
	}
	void setCRT() {
		CRT_CH = 40;
		CRT_DMG = 150;
	}

	//своя статистика
	void setNAME(string name) {
		NAME = name;
	}
	void setDMG(int dmg) {
		DMG = dmg;
	}
	void setHP(int hp) {
		HP = hp;
	}
	void setCRT(float crt_ch, float crt_dmg) {
		CRT_CH = crt_ch;
		CRT_DMG = crt_dmg;
	}

	//Установка итога для битвы
	void set_total_STATS() {
		DMG = get_total_dmg();
		HP = get_total_hp();
		CRT_CH = get_total_crtch();
		CRT_DMG = get_total_dmg();
	}


	//--------геттеры--------
	//игрок
	string getNAME() { return NAME; }
	int getID() { return ID; }
	int getHP() { return HP; }
	int getDMG() { return DMG; }
	float getCRT_CH() { return CRT_CH; }
	float getCRT_DMG() { return CRT_DMG; }
	//получение ВСЕГО для каждой статистики
	int get_total_hp() {
		totalHP = getHP();
		if (equipped_weapon != NULL) {
			totalHP += equipped_weapon->getHP();
		}
		return totalHP;
	}
	int get_total_dmg() {
		totalDMG = getDMG();
		if (equipped_weapon != NULL) {
			totalDMG += equipped_weapon->getDMG();
		}
		return totalDMG;
	}
	float get_total_crtch() {
		totalCRT_CH = getCRT_CH();
		return totalCRT_CH;
	}
	float get_total_crtdmg() {
		totalCRT_DMG = getCRT_DMG();
		return totalCRT_DMG;
	}

	void equip_weapon(weapon& weapon) {
		equipped_weapon = &weapon;
		cout << "Оружие экипировано!\n";
	}
	void unequip_weapon() {
		equipped_weapon = NULL;
		cout << "Оружие снято!\n";
	}

	void print_player_info() {
		cout << "ID\tHP\tDMG\tCRT_CH\tCRT_DMG\tNAME\n";
		cout << getID() << "\t"
			<< getHP() << "\t"
			<< getDMG() << "\t"
			<< getCRT_CH() << "\t"
			<< getCRT_DMG() << "\t"
			<< getNAME() << "\n";
	}

	void print_total_stats() {
		//обновляем значения перед выводом
		totalHP = get_total_hp();
		totalDMG = get_total_dmg();
		totalCRT_CH = get_total_crtch();
		totalCRT_DMG = get_total_crtdmg();

		cout << "HP\tDMG\tCRT_CH\tCRT_DMG\n";
		cout << totalHP << "\t"
			<< totalDMG << "\t"
			<< totalCRT_CH << "\t"
			<< totalCRT_DMG << "\n";
	}

};

void WeaponMenu(player &current_player, weapon weapon[]) {
	while (true) {
		cout << "--- ИНВЕНТАРЬ ОРУЖИЯ ---\n";
		cout << "  ID\tDMG\tHP\tNAME\n";
		cout << "0. ";
		weapon[0].print_weapon_info();
		cout << "1. ";
		weapon[1].print_weapon_info();
		cout << "2. ";
		weapon[2].print_weapon_info();
		cout << "3. ";
		weapon[3].print_weapon_info();
		cout << "\n4. Снять оружие\n"
			<< "5. Назад\n";
		cout << "Выбери действие\n"
			<< "Введи 0-5: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0:
			current_player.equip_weapon(weapon[choice]);
			system("pause");
			system("cls");
			break;
		case 1:
			current_player.equip_weapon(weapon[choice]);
			system("pause");
			system("cls");
			break;
		case 2:
			current_player.equip_weapon(weapon[choice]);
			system("pause");
			system("cls");
			break;
		case 3:
			current_player.equip_weapon(weapon[choice]);
			system("pause");
			system("cls");
			break;
		case 4:
			current_player.unequip_weapon();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			return;
		default:
			cout << "Ошибка! Введи 0-5!\n";
		}
	}
}

void PlayerMenu(player& current_player, weapon weapons[]) {
	setlocale(LC_ALL, "ru");
	string name;

	while (true) {
		current_player.set_total_STATS();

		cout << "--- МЕНЮ ИГРОКА ---\n";
		cout << "0. Информация об игроке\n"
			<< "1. Полная статистика\n"
			<< "2. Переименовать\n"
			<< "3. Оружие\n"
			<< "4. Назад в меню...\n";

		cout << "\nВведи 0-4: ";
		int choice;
		cin >> choice;
		switch(choice) {
		case 0:
			system("cls");
			current_player.print_player_info();
			break;
		case 1:
			system("cls");
			current_player.print_total_stats();
			break;
		case 2:
			system("cls");
			cout << "Введите новое имя игрока: ";
			cin >> name;
			current_player.setNAME(name);
			break;
		case 3:
			system("cls");
			WeaponMenu(current_player, weapons);
			break;
		case 4:
			system("cls");
			return;
		default:
			cout << "Ошибка! Введи 0-4\n";
			system("pause");
			system("cls");
		}
	}
}

//Вся логика битвы
int firstturnrandom() { //рандомный ход игрока
	return rand() % 2;
}

int change_turn(int turn) {	//Замена хода
	if (turn == 1) {
		return turn - 1;
	}
	else {
		return turn + 1;
	}
}

bool check_win(player current_player[]) {
	if (current_player[0].getHP() <= 0) {
		return true;
	}
	if (current_player[1].getHP() <= 0) {
		return true;
	}
	false;
}

void player_turn(int turn, player current_player[]) {
	while (true) {
		int tempturn = turn;
		system("cls");

		if (check_win(current_player) == true) {
			return;
		}

		cout << "Ход игрока ";
		cout << current_player[turn].getNAME() << endl;
		current_player[turn].print_player_info();
		cout << "0. Обычный удар\n"
			<< "1. Сильный удар\n";

		cout << "Введи 0-1:";
		int choice;
		cin >> choice;

		int DMG;
		switch (choice) {
		case 0:
			DMG = (rand() % current_player[tempturn].getDMG()) + (current_player[tempturn].getDMG() / 3.5);
			cout << "Нанесено урона: " << DMG << endl;
			system("pause");
			current_player[change_turn(tempturn)].setHP(current_player[change_turn(tempturn)].getHP() - DMG);	//ещё больше наговнокодил...
			turn = change_turn(turn);
			player_turn(turn, current_player);
		case 1:
			DMG = (rand() % current_player[tempturn].getDMG()) + (current_player[tempturn].getDMG() / 2);
			cout << "Нанесено урона: " << DMG << endl;
			system("pause");
			current_player[change_turn(tempturn)].setHP(current_player[change_turn(tempturn)].getHP() - DMG);
			turn = change_turn(turn);
			player_turn(turn, current_player);
		}
	}
}

void StartBattle(player players[]) {
	/*
	players[0].getNAME();
	players[0].print_total_stats();
	
	players[1].getNAME();
	players[1].print_total_stats();
	*/
	cout << "Первым ходит игрок: ";
	int turn;
	turn = firstturnrandom();
	// cout << "Игрок: " << turn << endl;
	if (turn == 0) {
		cout << players[0].getNAME();
	}
	else {
		cout << players[1].getNAME();
	}
	cout << endl;
	system("pause");
	player_turn(turn, players);
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);        
	SetConsoleOutputCP(1251);

	player players[2];
	string name_player[2] = { "ИГРОК 1", "ИГРОК 2" };
	for (int i = 0; i < 2; i++) {
		players[i].setNAME(name_player[i]);
		players[i].setID(i + 1);
		players[i].setHP();
		players[i].setCRT();
		players[i].setDMG();
	}
	
	weapon weapon[4];
	string weapon_name[4] = { "Кинжал", "Эксалибур", "Простой меч", "Ржавый меч" };
	for (int i = 0; i < 4; i++) {
		weapon[i].setID(i + 1);
		weapon[i].setNAME(weapon_name[i]);
		weapon[i].setDMG(rand() % 300 + 200);
		weapon[i].setHP(rand() % 300 + 600);
	}
	//НАГОВНОКОДИЛ ТУТ И ТЕПЕРЬ НЕ ПОНИМАЮ КАК ЭТО ВСЁ ФИКСИТЬ ТТ-ТТ

	while (true) {
		cout << "--- ГЛАВНОЕ МЕНЮ ---\n"
			<< "0. Начать битву\n"
			<< "1. Настроить игрока 1\n"
			<< "2. Настроить игрока 2\n"
			<< "3. Выйти из игры\n";
		
		cout << "Введи 0-3: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0:
			system("cls");
			StartBattle(players);
			break;
		case 1:
			system("cls");
			PlayerMenu(players[choice - 1], weapon);
			break;
		case 2:
			system("cls");
			PlayerMenu(players[choice - 1], weapon);
			break;
		case 3:
			return 0;
		default:
			cout << "Ошибка! Введи 0-3\n";
			system("pause");
			system("cls");
		}

		system("cls");
		if (check_win(players) == true) {
			if (players[0].getHP() <= 0) {
				cout << "================ ПОБЕДИТЕЛЬ ================\n";
				cout << "Игрок: " << players[1].getNAME() << endl;
				cout << "================+===========================\n";
			}
			if (players[1].getHP() <= 0) {
				cout << "================ ПОБЕДИТЕЛЬ ================\n";
				cout << "Игрок: " << players[0].getNAME() << endl;
				cout << "================+===========================\n";
			}
			return 0;
		}
	}
}
