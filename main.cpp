#include "kargo.h"

int main() {
	Islemler obj;
	int islem;

	while(1) {
		obj.menu();

		std::cout<<"islem sec: ";
		std::cin>>islem;

		switch(islem) {
			case 1:
				system(CLEAR);
				obj.kargoEkle();
				break;
			case 2:
				system(CLEAR);
				obj.kargoSil();
				break;
			case 3:
				system(CLEAR);
				obj.kargoYazdir();
				break;
			case 4:
				system(CLEAR);
				obj.tumunuYazdir();
				break;
			case 5:
				std::cout<<"Hoscakalin.\n";
				exit(0);
				break;
			default:
				std::cout<<"Hatali secim!\n";
				break;
		}
	}

	return 0;
}
