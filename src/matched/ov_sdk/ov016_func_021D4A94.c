/*
 * function: func_021D4A94
 * address:  0x021D4A94
 * packet:   pkt_ov016_021D4A94
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      userProc (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   func_02075E10  0x02075E10  arm
 *   func_02075E80  0x02075E80  arm
 *   g_021DE66C  0x021DE66C  data
 */

#include "../include/G_MemArc.h"

typedef unsigned short u16;
extern void func_02075E10(u16 lock_id);
extern void func_02075E80(int id);
extern struct MemArc *g_021DE66C;

int func_021D4A94(int unused, unsigned long cmd)
{
	switch (cmd) {
	case 9:
		func_02075E10(*(unsigned short *)(((char *)g_021DE66C) + 0xe4));
		return 0;
	case 10:
		func_02075E80(*(unsigned short *)(((char *)g_021DE66C) + 0xe4));
		return 0;
	case 1:
		return 4;
	default:
		return 0x102;
	}
}
