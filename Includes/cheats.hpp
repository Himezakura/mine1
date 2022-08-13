#ifndef CHEATS_H
#define CHEATS_H

#include <3ds.h>
#include "csvc.h"
#include <vector>
#include <CTRPluginFramework.hpp>
#include "Helpers.hpp"
#include "Unicode.h"

namespace CTRPluginFramework
{
    using StringVector = std::vector<std::string>;
	
	
	void speed1(MenuEntry *entry);
	void speed2(MenuEntry *entry);
	void kantu(MenuEntry *entry);
	void hp_huan(MenuEntry *entry);
	void kuuhuku_huan(MenuEntry *entry);
	void dameji_bairitu(MenuEntry *entry);
	void block_wanpan(MenuEntry *entry);
	void block_wanpan_turuhasi(MenuEntry *entry);
	
}
#endif
