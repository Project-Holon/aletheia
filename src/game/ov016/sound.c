/*
 * file:     sound.c
 * unit:     yes
 * function: DWCi_SNDlInit, DWCi_SNDlEnd, DWCi_SNDlPlay, DWCi_SNDlSetVolume, DWCi_SNDlSetPitch, DWCi_SNDlStop, taskSound
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
 * sdk:      taskSound (libdwcutil.TWL.HYB.a sound.o, static)
 * Task callback DWCi_SNDlInit (DWCi_SNDlInit) registers: a tail call to
 * NNS_SndBoot.
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_ARClReadEx  0x021D4B68  arm  ov016
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndArcInitOnMemory  0x02074220  arm
 *   NNS_SndArcPlayerSetup  0x020754C4  arm
 *   NNS_SndHandleInit  0x02072E9C  arm
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 *   NNS_SndPlayerSetPlayableSeqCount  0x02072DB0  arm
 *   NNS_SndPlayerSetAllocatableChannel  0x02072DD0  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   taskSound  0x021D0034  arm  ov016
 *   gSoundWork  0x021DE648  data
 *   sSoundTable  0x021DB8D4  data
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   NNS_SndHandleSetVolume  0x02072F34  arm  arm9
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm  arm9
 *   NNS_SndBoot  0x02072758  arm
 *   NNS_SndHandleStopSeq  0x02072E7C  arm  arm9
 *   NNS_SndArcPlayerStartSeqArc  0x02075618  arm  arm9
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void NNS_SndInit();
struct NNSSndArc;
extern void NNS_SndArcInitOnMemory(struct NNSSndArc *arc, unsigned char *base);
struct NNSSndHeap;
extern unsigned int NNS_SndArcPlayerSetup(struct NNSSndHeap *heap);
struct SndHandle;
extern void NNS_SndHandleInit(struct SndHandle *handle);
extern void NNS_SndPlayerSetPlayerVolume(unsigned int playerNo, unsigned int volume);
extern void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount);
extern void NNS_SndPlayerSetAllocatableChannel(unsigned int playerNo, unsigned int channelMask);
struct TCB;
extern struct TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskSound(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_HEAPlFree_(void **mem);
extern u32 NNS_SndArcPlayerStartSeqArc(u32 a, u32 b, u32 c);
extern void NNS_SndHandleSetVolume(char *, unsigned int);
extern void NNS_SndHandleSetTrackPitch(struct SndHandle *handle, unsigned int trackMask, unsigned int value);
extern void NNS_SndHandleStopSeq(struct SndHandle *handle, int fadeFrame);
extern void NNS_SndBoot(void);
void DWCi_SNDlInit(void);
void DWCi_SNDlEnd(void);
void DWCi_SNDlPlay(unsigned int v);
void DWCi_SNDlSetVolume(unsigned int v);
void DWCi_SNDlSetPitch(unsigned int a, unsigned int b);
void DWCi_SNDlStop(void);
void taskSound(void);
extern struct SND *gSoundWork;
extern char sSoundTable[];


/*
 * sdk:      DWCi_SNDlInit (libdwcutil.TWL.HYB.a(sound.o))
 */

void DWCi_SNDlInit(void)
{
	unsigned long size;
	int playerNo;

	gSoundWork = (struct SND *)((SND *)DWCi_HEAPlAllocEx(0xac, 4));
	gSoundWork->arc = DWCi_ARClReadEx(sSoundTable, &size, 0x20);
	NNS_SndInit();
	NNS_SndArcInitOnMemory((struct NNSSndArc *)(((SND *)gSoundWork)), gSoundWork->arc);
	NNS_SndArcPlayerSetup(0);
	NNS_SndHandleInit((struct SndHandle *)(&gSoundWork->handle));
	for (playerNo = 0; playerNo < 0x20; playerNo++) {
		NNS_SndPlayerSetPlayerVolume(playerNo, 0x7f);
		NNS_SndPlayerSetPlayableSeqCount(playerNo, 1);
		NNS_SndPlayerSetAllocatableChannel(playerNo, 0);
	}
	gSoundWork->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskSound, 0, 0xc8);
}


/*
 * sdk:      DWCi_SNDlEnd (libdwcutil.TWL.HYB.a(sound.o))
 */
void DWCi_SNDlEnd(void)
{
	DWCi_TSKlDelete(0, gSoundWork->task);
	DWCi_HEAPlFree_((void **)0x021DE648);
}


void DWCi_SNDlPlay(unsigned int v)
{
    NNS_SndArcPlayerStartSeqArc((u32)(*(char **)0x021DE648 + 0xa0), 0, v);
}


/*
 * Tail-call NNS_SndHandleSetVolume with the global object +0xa0 and the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlSetVolume.c \
 *       --func DWCi_SNDlSetVolume --addr 0x021CFFD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SNDlSetVolume(unsigned int v)
{
    NNS_SndHandleSetVolume(*(char **)0x021DE648 + 0xa0, v);
}


/*
 * Tail-call NNS_SndHandleSetTrackPitch with the global object +0xa0 and two arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SNDlSetPitch.c \
 *       --func DWCi_SNDlSetPitch --addr 0x021CFFF0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SNDlSetPitch(unsigned int a, unsigned int b)
{
    NNS_SndHandleSetTrackPitch((struct SndHandle *)(*(char **)0x021DE648 + 0xa0), a, b);
}


void DWCi_SNDlStop(void)
{
    NNS_SndHandleStopSeq((struct SndHandle *)(*(char **)0x021DE648 + 0xa0), 0);
}


void taskSound(void)
{
    NNS_SndBoot();
}
