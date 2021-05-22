#include "kargo.h"

KargoBilgileri::KargoBilgileri() {
	std::cout<<"\n\n\n == Kargo otomasyonu == \n\n\n";
}

KargoBilgileri::~KargoBilgileri() {
	std::cout<<"\n\n\n == Hoscakalin == \n\n\n";
}

//void KargoBilgileri::kargoYazdir() {}

Islemler::Islemler() {}
Islemler::~Islemler() {}

std::pair<bool, size_t> Islemler::kargoSec(std::string &id) {
	for(size_t i=0;i<kargolar.size();i++)
		if(kargolar[i].id == id)
			return {true, i};

	return {false, 0};
}

void Islemler::menu() {
	std::cout<<"Kargo ekleme           [1]\n";
	std::cout<<"Kargo silme            [2]\n";
	std::cout<<"Kargo yazdirma         [3]\n";
	std::cout<<"Tum kargolari yazdirma [4]\n";
	std::cout<<"\nExit                 [5]\n\n";
}

void Islemler::kargoEkle() {
	kargo_t kargo;
	gonderici_t gonderici;
	alici_t alici;

	std::cout<<"Kargo id: ";
	std::cin>>kargo.id;
	std::cout<<"Kargo ad: ";
	std::cin>>kargo.ad;
	std::cout<<"Kargo agirlik: ";
	std::cin>>kargo.agirlik;
	std::cout<<"Gonderilme tarihi: ";
	std::cin>>kargo.tarih;

	kargolar.push_back(kargo);

	std::cout<<"\nGonderici ad: ";
	std::cin>>gonderici.ad;
	std::cout<<"Gonderici soyad: ";
	std::cin>>gonderici.soyad;

	gondericiler.push_back(gonderici);

	std::cout<<"\nAlici ad: ";
	std::cin>>alici.ad;
	std::cout<<"Alici soyad: ";
	std::cin>>alici.soyad;

	alicilar.push_back(alici);

	std::cout<<"Kargo eklendi.\n\n";
}

void Islemler::kargoSil() {
	std::string id;

	std::cout<<"Kargo id si: ";
	std::cin>>id;

	auto [x,y] = kargoSec(id);
	if(x) {
		kargolar.erase(kargolar.begin()+y);
		gondericiler.erase(gondericiler.begin()+y);
		alicilar.erase(alicilar.begin()+y);

		std::cout<<"Kargo silindi.\n\n";
	}

	else {
		std::cout<<"Kargo bulunamadi.\n\n";
	}
}

void Islemler::kargoYazdir() {
	std::string id;

	std::cout<<"Kargo id si:";
	std::cin>>id;

	auto [x,i] = kargoSec(id);

	if(x) {
		std::cout<<"\nKargo ismi        : "<<kargolar[i].ad;
		std::cout<<"\nKargo id          : "<<kargolar[i].id;
		std::cout<<"\nKargo agirligi    : "<<kargolar[i].agirlik;
		std::cout<<"\nGonderilme tarihi : "<<kargolar[i].tarih;

		std::cout<<"\nGonderici adi     : "<<gondericiler[i].ad;
		std::cout<<"\nGonderici soyadi  : "<<gondericiler[i].soyad;

		std::cout<<"\nAlici adi         : "<<alicilar[i].ad;
		std::cout<<"\nAlici soyadi      : "<<alicilar[i].soyad<<"\n\n";
	} else {
		std::cout<<"Kargo bulunamadi.\n\n";
	}
}

void Islemler::tumunuYazdir() {
	std::cout<<"\n\n";

	if(kargolar.size() == 0) {
		std::cout<<"Hic kargo eklenmedi\n\n";
		return;
	}


	for(int i=0;i<kargolar.size();i++) {
		std::cout<<"\nKargo ismi        : "<<kargolar[i].ad;
		std::cout<<"\nKargo id          : "<<kargolar[i].id;
 		std::cout<<"\nKargo agirligi    : "<<kargolar[i].agirlik;
 		std::cout<<"\nGonderilme tarihi : "<<kargolar[i].tarih;

 		std::cout<<"\nGonderici adi     : "<<gondericiler[i].ad;
 		std::cout<<"\nGonderici soyadi  : "<<gondericiler[i].soyad;

 		std::cout<<"\nAlici adi         : "<<alicilar[i].ad;
 		std::cout<<"\nAlici soyadi      : "<<alicilar[i].soyad<<"\n\n";
	}

	std::cout<<"\n\n";
}
