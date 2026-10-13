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
 *   CARD_LockRom  0x02075E10  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   gMemArchive  0x021DE66C  data
 */

#include "../include/G_MemArc.h"

typedef unsigned short u16;
extern void CARD_LockRom(u16 lock_id);
extern void CARD_UnlockRom(int id);
extern struct MemArc *gMemArchive;

int func_021D4A94(int unused, unsigned long cmd)
{
	switch (cmd) {
	case 9:
		CARD_LockRom(*(unsigned short *)(((char *)gMemArchive) + 0xe4));
		return 0;
	case 10:
		CARD_UnlockRom(*(unsigned short *)(((char *)gMemArchive) + 0xe4));
		return 0;
	case 1:
		return 4;
	default:
		return 0x102;
	}
}
