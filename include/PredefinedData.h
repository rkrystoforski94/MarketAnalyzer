#pragma once

#include <string>
#include <utility>

static struct s_stockdata;
static struct s_stock;


static struct s_stockdata {
	std::string shortStockName;
	std::string stockName;
};
typedef struct s_stockdata t_stockdata;
typedef struct s_stock t_stock;

namespace predef {
	
	static struct s_stock {
		t_stockdata apple;								// 0
		t_stockdata tesla;								// 1
		t_stockdata tauron;								// 2
		t_stockdata ccc;								// 3
		t_stockdata bogdanka;							// 4
		t_stockdata mabion;								// 5
		t_stockdata jastrzebska;						// 6
		t_stockdata lpp;								// 7
		t_stockdata cdproject;							// 8
		t_stockdata pge;								// 9
		t_stockdata allegro;							// 10
		t_stockdata polsat;								// 11
		t_stockdata dino;								// 12
		t_stockdata kruk;								// 13
		t_stockdata mbk;								// 14
		t_stockdata tpsa;								// 15
		t_stockdata pekao;								// 16
		t_stockdata adidas;								// 17
		t_stockdata bmwg;								// 18
		t_stockdata intel;								// 19
		t_stockdata m3;									// 20
		t_stockdata americanexpress;					// 21
		t_stockdata co;									// 22
		t_stockdata ibm;								// 23
		t_stockdata orlen;								// 24
		t_stockdata amazon;								// 25
		t_stockdata netflix;							// 26
	} stock = {
		{"AAPL", "apple-computer-inc"},					// 0
		{"TSLA", "tesla-motors"},						// 1
		{"TPE", "tauron-polska-energia"},				// 2
		{"CCCP", "ccc"},								// 3
		{"LWBP", "lubelski-wegiel-bogdanka"},			// 4
		{"MABP", "mabion"},								// 5
		{"JSW", "jastrzebska-spolka-weglowa"},			// 6
		{"LPPP", "lpp"},								// 7
		{"CDR", "cdproject"},							// 8
		{"PGE", "pge-polska"},							// 9
		{"ALEP", "allegro"},							// 10
		{"CPS", "cyfrowy-polsat-sa"},					// 11
		{"DNP", "dino-polska-sa"},						// 12
		{"KRU", "kruk"},								// 13
		{"MBK", "bre-bank-sa"},							// 14
		{"OPL", "tpsa"},								// 15
		{"PEO", "bank-pekao-sa"},						// 16
		{"ADSGn", "adidas-salomon"},					// 17
		{"BMWG", "bay-mot-werke"},						// 18
		{"INTC", "intel-corp"},							// 19
		{"MMM", "3m-co"},								// 20
		{"AXP", "american-express"},					// 21
		{"KO", "coca-cola-co"},							// 22
		{"IBM", "ibm"},									// 23
		{"PKN", "pkn-orlen"},							// 24
		{"AMZN", "amazon-com-inc"},						// 25
		{"NFLX", "netflix,-inc."}						// 26
	};

}
