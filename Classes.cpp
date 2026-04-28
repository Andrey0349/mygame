#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <chrono>
#include <thread>


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
		if (hp < 0) {
			HP = 0;
		}
		else {
			HP = hp;
		}
	}
	void setCRT(float crt_ch, float crt_dmg) {
		CRT_CH = crt_ch;
		CRT_DMG = crt_dmg;
	}

	//Установка итога
	void set_total_STATS() {
		totalDMG = get_total_dmg();
		totalHP = get_total_hp();
		totalCRT_CH = get_total_crtch();
		totalCRT_DMG = get_total_dmg();
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
		set_total_STATS();

		cout << "HP\tDMG\tCRT_CH\tCRT_DMG\n";
		cout << totalHP << "\t"
			<< totalDMG << "\t"
			<< totalCRT_CH << "\t"
			<< totalCRT_DMG << "\n";
	}

};

void clear_screen() {
	system("clear");
}
void pause_screen() {
    cout << "Нажмите Enter для продолжения...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

//Меню для выбора доступного оружия
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
			pause_screen();
			clear_screen();
			break;
		case 1:
			current_player.equip_weapon(weapon[choice]);
			pause_screen();
			clear_screen();
			break;
		case 2:
			current_player.equip_weapon(weapon[choice]);
			pause_screen();
			clear_screen();
			break;
		case 3:
			current_player.equip_weapon(weapon[choice]);
			pause_screen();
			clear_screen();
			break;
		case 4:
			current_player.unequip_weapon();
			pause_screen();
			clear_screen();
			break;
		case 5:
			clear_screen();
			return;
		default:
			cout << "Ошибка! Введи 0-5!\n";
		}
	}
}


//Меню игрока
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
			clear_screen();
			current_player.print_player_info();
			break;
		case 1:
			clear_screen();
			current_player.print_total_stats();
			break;
		case 2:
			clear_screen();
			cout << "Введите новое имя игрока: ";
			cin >> name;
			current_player.setNAME(name);
			break;
		case 3:
			clear_screen();
			WeaponMenu(current_player, weapons);
			break;
		case 4:
			clear_screen();
			return;
		default:
			cout << "Ошибка! Введи 0-4\n";
			pause_screen();
			clear_screen();
		}
	}
}
//----------------------------------------
//Вся логика битвы
int firstturnrandom() { //рандомный ход игрока
	return rand() % 2;
}

int change_turn(int turn) {	//Замена хода
	return (turn == 0) ? 1 : 0;
}

//Проверка на наличие победы
bool check_win(player current_player[]) {
	if (current_player[0].get_total_hp() <= 0) {
		return true;
	}
	if (current_player[1].get_total_hp() <= 0) {
		return true;
	}
	return false;
}

void loop_battle(int turn, player players[]) {
	while (true) {
		for (int i = 0; i < 2; i++) {
			players[i].set_total_STATS();
		}

		//Проверка на победу
		if (players[0].get_total_hp() <= 0) {
			cout << "\n" << players[1].getNAME() << " победил!\n";
			return;
		}
		if (players[1].get_total_hp() <= 0) {
			cout << "\n" << players[0].getNAME() << " победил!\n";
			return;
		}

		//Ход текущего игрока
		cout << "\n=== Ход игрока: " << players[turn].getNAME() << " ===\n";
		cout << "Ваше HP: " << players[turn].get_total_hp() << endl;
		cout << "HP противника: " << players[change_turn(turn)].get_total_hp() << endl;
		cout << "1. Обычный удар\n"
			<< "2. Сильный удар\n";

		int choice;
		cout << "\nВыбери действие: ";
		cin >> choice;

		int DMG;
		int enemy_index = change_turn(turn);

		int current_dmg = players[turn].get_total_dmg();
		switch (choice) {
		case 1:
			DMG = (rand() % players[turn].get_total_dmg() + players[turn].get_total_dmg()) / 3;
			players[enemy_index].setHP(players[enemy_index].getHP() - DMG);
			cout << "Нанесённый урон противнику: " << DMG << endl;
			pause_screen();
			break;
		case 2:
			DMG = (rand() % players[turn].get_total_dmg() + players[turn].get_total_dmg()) / 2;
			players[enemy_index].setHP(players[enemy_index].getHP() - DMG);
			cout << "Нанесённый урон противнику: " << DMG << endl;
			pause_screen();
			break;
		default:
			cout << "\nОшибка! Попробуй снова!" << endl;
			pause_screen();
			continue;
		}

		//смена хода
		turn = change_turn(turn);
		clear_screen();
	}
}

void StartBattle(player players[]) {
	clear_screen();
	cout << "=== НАЧАЛО БИТВЫ ===\n";

	//Задаём статистику перед битвой
	for (int i = 0; i < 2; i++) {
		players[i].set_total_STATS();
	}

	int turn = firstturnrandom();
	cout << "Первым ходит: " << players[turn].getNAME() << endl;
	pause_screen();
	clear_screen();
	loop_battle(turn, players);
}
//Логика битвы окончена
//--------------------------------------------
int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");

	//Создание игроков
	player players[2];
	string name_player[2] = { "ИГРОК 1", "ИГРОК 2" };
	for (int i = 0; i < 2; i++) {
		players[i].setNAME(name_player[i]);
		players[i].setID(i + 1);
		players[i].setHP();
		players[i].setCRT();
		players[i].setDMG();
	}
	

	//СОздание оружия
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
			clear_screen();
			StartBattle(players);	//Начать битву
			break;
		case 1:
			clear_screen();
			PlayerMenu(players[choice - 1], weapon);		//Открыть меню игрока 1
			break;
		case 2:
			clear_screen();
			PlayerMenu(players[choice - 1], weapon);		//Открыть меню игрока 2
			break;
		case 3:
			return 0;
		default:
			cout << "Ошибка! Введи 0-3\n";
			pause_screen();
			clear_screen();
		}

		clear_screen();
		if (check_win(players) == true) {
			if (players[0].get_total_hp() <= 0) {
				cout << "================ ПОБЕДИТЕЛЬ ================\n";
				cout << "Игрок: " << players[1].getNAME() << endl;
				cout << "============================================\n";
			}
			if (players[1].get_total_hp() <= 0) {
				cout << "================ ПОБЕДИТЕЛЬ ================\n";
				cout << "Игрок: " << players[0].getNAME() << endl;
				cout << "============================================\n";
			}
			return 0;
		}
	}
}
