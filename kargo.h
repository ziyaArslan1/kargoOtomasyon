#ifndef _KARGO_H_
#define _KARGO_H_

#ifdef WIN32
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "kargo.h"

class KargoBilgileri {
	protected:
		typedef struct {
			std::string ad;
			std::string agirlik;
			std::string id;
			std::string tarih;
		}kargo_t;

		std::vector<kargo_t>kargolar;

	public:
		KargoBilgileri();
		~KargoBilgileri();

		//friend void kargoYazdir();
};

class Islemler : public KargoBilgileri {
	private:
		typedef struct {
			std::string ad, soyad;
		}gonderici_t;

		typedef struct {
			std::string ad,soyad;
		}alici_t;

		std::vector<gonderici_t>gondericiler;
		std::vector<alici_t>alicilar;

	public:
		Islemler();
		~Islemler();

		std::pair<bool, size_t> kargoSec(std::string &);
		void kargoEkle();
		void kargoSil();

		void kargoYazdir();
		void tumunuYazdir();
		void menu();

};

#endif /* kargo.h  end */

