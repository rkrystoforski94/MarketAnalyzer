#pragma once
#include <string>
#include <map>

/* https://pl.investing.com/equities/<stockName> */

namespace predefdata {

	struct FullStockName {
		std::string shortStockName; std::string stockName;
	};

	typedef struct FullStockName fullstockname;

	fullstockname fullstocknameArray[] = {
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
