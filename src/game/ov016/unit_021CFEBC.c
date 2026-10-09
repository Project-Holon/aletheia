/*
 * file:     unit_021CFEBC.c
 * unit:     yes
 * function: func_021CFEBC, func_021CFF80, func_021CFFAC, func_021CFFD0, func_021CFFF0, func_021D0014
 * address:  0x021CFEBC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 */
struct Obj;
typedef struct SND {
	unsigned char pad_0[0xa0];
	int handle;
	void *arc;
	void *task;
	int pad2;
} SND;

typedef unsigned int   u32;

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
extern void func_021D7724(int kind, void *task);
extern void func_021D6438(void **mem);
extern u32 func_02075618(u32 a, u32 b, u32 c);
extern void func_02072F34(char *, unsigned int);
extern void func_02073018(struct Obj *o, u32 v, u32 w);
extern void func_02072E7C(void **r0, int fadeFrame);
void func_021CFEBC(void);
void func_021CFF80(void);
void func_021CFFAC(unsigned int v);
void func_021CFFD0(unsigned int v);
void func_021CFFF0(unsigned int a, unsigned int b);
void func_021D0014(void);
extern struct SND *g_021DE648;
extern char g_021DB8D4[];


/*
 * sdk:      DWCi_SNDlInit (libdwcutil.TWL.HYB.a(sound.o))
 */
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




/*
 * sdk:      DWCi_SNDlEnd (libdwcutil.TWL.HYB.a(sound.o))
 */
void func_021CFF80(void)
{
	func_021D7724(0, g_021DE648->task);
	func_021D6438((void **)0x021DE648);
}




void func_021CFFAC(unsigned int v)
{
    func_02075618((u32)(*(char **)0x021DE648 + 0xa0), 0, v);
}




/*
 * Tail-call func_02072F34 with the global object +0xa0 and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFD0.c \
 *       --func func_021CFFD0 --addr 0x021CFFD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CFFD0(unsigned int v)
{
    func_02072F34(*(char **)0x021DE648 + 0xa0, v);
}




/*
 * Tail-call func_02073018 with the global object +0xa0 and two arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFFF0.c \
 *       --func func_021CFFF0 --addr 0x021CFFF0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CFFF0(unsigned int a, unsigned int b)
{
    func_02073018((struct Obj *)(*(char **)0x021DE648 + 0xa0), a, b);
}




void func_021D0014(void)
{
    func_02072E7C((void **)(*(char **)0x021DE648 + 0xa0), 0);
}
