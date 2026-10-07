/*
 * function: func_021CFEBC
 * address:  0x021CFEBC
 * packet:   pkt_ov016_021CFEBC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SNDlInit (libdwcutil.TWL.HYB.a(sound.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D4B68  0x021D4B68  arm  ov016
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndArcInitOnMemory  0x02074220  arm
 *   NNS_SndArcPlayerSetup  0x020754C4  arm
 *   NNS_SndHandleInit  0x02072E9C  arm
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 *   NNS_SndPlayerSetPlayableSeqCount  0x02072DB0  arm
 *   NNS_SndPlayerSetAllocatableChannel  0x02072DD0  arm
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D0034  0x021D0034  arm  ov016
 *   g_021DE648  0x021DE648  data
 *   g_021DB8D4  0x021DB8D4  data
 */

#include "../include/G_SND.h"

typedef struct {
	char pad[0xa0];
	int handle;
	void *arc;
	void *task;
	int pad2;
} SND;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void NNS_SndInit();
extern void NNS_SndArcInitOnMemory();
extern void NNS_SndArcPlayerSetup();
extern void NNS_SndHandleInit();
extern void NNS_SndPlayerSetPlayerVolume();
extern void NNS_SndPlayerSetPlayableSeqCount();
extern void NNS_SndPlayerSetAllocatableChannel();
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021D0034(void);
extern struct SND *g_021DE648;
extern char g_021DB8D4[];

void func_021CFEBC(void)
{
	unsigned long size;
	int playerNo;

	g_021DE648 = (struct SND *)((SND *)func_021D6414(0xac, 4));
	g_021DE648->arc = func_021D4B68(g_021DB8D4, &size, 0x20);
	NNS_SndInit();
	NNS_SndArcInitOnMemory(((SND *)g_021DE648), g_021DE648->arc);
	NNS_SndArcPlayerSetup(0);
	NNS_SndHandleInit(&g_021DE648->handle);
	for (playerNo = 0; playerNo < 0x20; playerNo++) {
		NNS_SndPlayerSetPlayerVolume(playerNo, 0x7f);
		NNS_SndPlayerSetPlayableSeqCount(playerNo, 1);
		NNS_SndPlayerSetAllocatableChannel(playerNo, 0);
	}
	g_021DE648->task = func_021D7680(0, (void (*)(void *, void *))func_021D0034, 0, 0xc8);
}
