/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006238
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_IsAnySeBusy, GFL_USE_IsSeqPlaying, GFL_USE_SetSeSlotParams, GFL_USE_SetSeSlotVolume,
 *           GFL_USE_LoaderThreadSeqBank, GFL_USE_LoaderThreadWaves, GFL_USE_StartLoaderThread
 *
 * symbols:
 *   sub_02006238_Table   0x020AA294  data
 *   sub_02006300_State   0x020AA260  data
 *   sub_02006300_Thread  0x020AA354  data
 *   sub_02006300_Stack   0x020AA9B4  data
 *   GFL_USE_IsSeSlotBusy         0x02006224  thumb
 *   GFL_USE_StopLoaderThread         0x02006368  thumb
 *   func_02072EE0        0x02072EE0  arm
 *   NNS_SndHandleSetSeqPriority        0x02072F34  arm
 *   NNS_SndHandleSetTrackPitch        0x02073018  arm
 *   NNS_SndHandleSetTrackPan        0x02073038  arm
 *   NNS_SndHandleStop        0x02073098  arm
 *   func_020853C0        0x020853C0  arm
 *   func_02074AC4        0x02074AC4  arm
 *   func_02085868        0x02085868  arm
 *
 * The two thread bodies and the routine that starts one.  GFL_USE_LoaderThreadSeqBank and
 * GFL_USE_LoaderThreadWaves carry no label: both are six instructions with no prologue
 * that dereference the thread argument, read one field of the state block
 * and tail call func_02074AC4 with a different constant, and the only
 * references to them in the image are the two pool words of GFL_USE_StartLoaderThread
 * immediately below.  That is why the three have to be one byte range:
 * outside it neither thread body has a witness, and inside it both are
 * `local`.
 *
 * GFL_USE_StartLoaderThread's call to func_020853C0 is an OS thread creation: the thread
 * object at 0x020AA354, the entry point, the argument, the stack at
 * 0x020AA9B4, and 0x400 and 0x11 on the stack for the stack size and the
 * priority.  The argument, 0x020AA26C, is the address of the state block's
 * own `unk0C` field, which is the word GFL_USE_StartLoaderThread has just written, so it
 * reaches the relocation as the state symbol with an addend of 0xC rather
 * than as an object of its own.
 */

typedef unsigned int u32;

struct Sub02006300State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};

struct Sub02006238Entry {
    void *unk00;
    u32   unk04;
};

extern struct Sub02006300State sub_02006300_State;
extern struct Sub02006238Entry sub_02006238_Table[];
extern u32 sub_02006300_Thread[];
extern u32 sub_02006300_Stack[];

extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void GFL_USE_StopLoaderThread(void);
extern int  func_02072EE0(u32 a);
extern void NNS_SndHandleSetSeqPriority(u32 *req, u32 level);
struct Obj;
extern void NNS_SndHandleSetTrackPitch(struct Obj *o, u32 v, u32 w);
extern void NNS_SndHandleSetTrackPan(struct Obj *o, u32 v, u32 w);
extern void NNS_SndHandleStop(struct Obj *o, u32 v);
extern u32 func_02074AC4(u32 a, u32 b, u32 c);
extern void func_020853C0(u32 *thread, void (*entry)(void *), void *arg,
                          u32 *stack, u32 size, u32 prio);
extern void func_02085868(u32 *thread);

void GFL_USE_LoaderThreadSeqBank(u32 *arg);
void GFL_USE_LoaderThreadWaves(u32 *arg);

int GFL_USE_IsAnySeBusy(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (GFL_USE_IsSeSlotBusy(i) == 1) {
            return 1;
        }
    }
    return 0;
}

int GFL_USE_IsSeqPlaying(u32 a)
{
    if (func_02072EE0(a) != 0) {
        return 1;
    }
    return 0;
}

void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c)
{
    if (a != -1) {
        NNS_SndHandleStop((struct Obj *)(&sub_02006238_Table[i].unk04), a);
    }
    if (b != -1) {
        NNS_SndHandleSetTrackPitch((struct Obj *)(&sub_02006238_Table[i].unk04), 0xFFFF, b);
    }
    if (c != -1) {
        NNS_SndHandleSetTrackPan((struct Obj *)(&sub_02006238_Table[i].unk04), 0xFFFF, c);
    }
}

void GFL_USE_SetSeSlotVolume(int i, u32 level)
{
    if (level > 0x7F) {
        level = 0x7F;
    }
    NNS_SndHandleSetSeqPriority(&sub_02006238_Table[i].unk04, level);
}

void GFL_USE_LoaderThreadSeqBank(u32 *arg)
{
    func_02074AC4(*arg, 3, sub_02006300_State.unk10);
}

void GFL_USE_LoaderThreadWaves(u32 *arg)
{
    func_02074AC4(*arg, 4, sub_02006300_State.unk10);
}

void GFL_USE_StartLoaderThread(u32 a, int mode)
{
    sub_02006300_State.unk0C = a;
    GFL_USE_StopLoaderThread();
    switch (mode) {
    case 0:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))GFL_USE_LoaderThreadSeqBank,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    case 1:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))GFL_USE_LoaderThreadWaves,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    }
    func_02085868(sub_02006300_Thread);
    sub_02006300_State.unk14 = (u32)sub_02006300_Thread;
}
