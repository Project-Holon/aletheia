/*
 * file:     nns_snd_main_1.c
 * unit:     yes
 * function: func_02073CEC, func_02073D5C, func_02073D7C, func_02073DFC
 * address:  0x02073CEC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E9B4       0x0214E9B4  data
 *   g_0214E9FC       0x0214E9FC  data
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   func_02089638  0x02089638  arm
 *   g_0214E9BC     0x0214E9BC  data
 *   func_020894DC  0x020894DC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 *   func_02085E50  0x02085E50  arm
 *   SND_CHANNEL_ClearClaimedMask  0x020729A4  arm
 *   SND_CHANNEL_UnlockChannels  0x02072974  arm
 *   NNS_SndWaveOutFreeChannel  0x02072A08  arm
 *   func_0208972C  0x0208972C  arm
 */
struct LerpObj;
struct Obj;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct St {
    u32 f00;
    u32 f04;
    u8  pad08[0x18];
    u32 f20;
    u32 f24;
    u32 f28;
    s32 f2c;
    u8  pad30[0x0c];
    u8  f3c[0x10];
    u32 f4c;
    s32 f50;
} St;

struct A {
    u8  p00[0x2c];
    int b0 : 1;
    int b1 : 1;
    int hi : 30;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void func_02073BF0(struct A *, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020894B4(u32, u32, u32, u32);
extern void NNS_SndFaderUpdate(struct LerpObj *obj);
extern int NNS_SndFaderIsFinished(struct LerpObj *obj);
extern s32 NNS_SndFaderGet(struct Obj *o);
extern void func_02089638(u32 a, s32 b, s32 c);
extern void func_020894DC(u32 a, u32 b, u32 c, s32 d);
extern s32  func_02089D40(void);
extern void func_02089B38(s32 a);
extern void func_02089CD4(s32 a);
extern s32  func_02085E50(void *p, s32 b, s32 c);
extern void SND_CHANNEL_ClearClaimedMask(u32 mask);
extern void SND_CHANNEL_UnlockChannels(u32 chan);
extern void NNS_SndWaveOutFreeChannel(u32 bit);
extern void func_0208972C(s32 a, s32 b, s32 c, s32 d);
void func_02073CEC(struct A *a);
void func_02073D5C(void);
void func_02073D7C(void);
void func_02073DFC(void);
extern u32 g_0214E9B4;
extern St g_0214E9FC;
extern u8   g_0214E9BC[];


void func_02073CEC(struct A *a) {
    u32 r;
    if (!a->b1) return;
    while (a->f40 != 0) {
        r = func_02087988();
        func_02073BF0(a, 1);
        func_0208799C(r);
    }
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
}




/*
 * Clears the two words of the sequence/index pair to zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073D5C.c \
 *       --func func_02073D5C --addr 0x02073D5C --cc 1.1p1 --arm
 */
void func_02073D5C(void)
{
    g_0214E9B4 = 0;
    g_0214E9FC.f00 = 0;
}



/*
 * Blocked at MATCH: every concrete byte of the 128 is identical and 5 of the
 * 6 relocations resolve.  The one that does not is the PC24 at +0x44 to
 * func_02073DFC, this function's own immediate follower at 0x02073DFC: that
 * `bl` is the only branch to the address anywhere in the image, so neither
 * `label` nor `matched` can attest it while 0x02073DFC is unfiled.
 * func_02073DFC was worked this pass and reached 228 of its 232 bytes with
 * the whole structure right; see docs/notes/func_02073DFC.c.txt.  Filing it
 * EXACT promotes this file with no C change, and this file in turn is one of
 * the two remaining blockers on src/pending/func_02072758.c.
 */
void func_02073D7C(void)
{
    St *s;
    s32 v;

    s = &g_0214E9FC;
    if (s->f00 == 0) {
        return;
    }
    if (s->f04 != 0) {
        return;
    }

    NNS_SndFaderUpdate((struct LerpObj *)s->f3c);

    if (s->f4c != 0 && NNS_SndFaderIsFinished((struct LerpObj *)s->f3c) != 0) {
        func_02073DFC();
        return;
    }

    v = NNS_SndFaderGet((struct Obj *)s->f3c) >> 8;
    if (v == s->f50) {
        return;
    }
    func_02089638(s->f24, v, 0);
    s->f50 = v;
}


/*
 * Shutdown of the global sequence object g_0214E9FC: release its channel
 * pair, and when it owns a channel save/mute/restore the driver and spin
 * until func_02085E50 reports idle; then free the +0x28 mask, the +0x20
 * channel and the +0x2c channel bit, notify when +0x04 == 1, and clear the
 * liveness word.
 *
 * THE LEVER (after four passes and 2215 permuter candidates flat on the
 * body, docs/notes/func_02073DFC.c.txt): two extern signatures.
 * SND_CHANNEL_ClearClaimedMask and SND_CHANNEL_UnlockChannels each take the field their guard just
 * tested -- SND_CHANNEL_ClearClaimedMask(s->f28), SND_CHANNEL_UnlockChannels(s->f20) -- exactly as
 * their own matched sources declare them (`u32 mask`, `u32 chan`).  The
 * image's `ldr r0,[r4,#0x28]; cmp r0,#0; beq; bl` was always passing it.
 * Declared void(void), the three callee-saved locals rotated r5/r6/r7.
 */
void func_02073DFC(void)
{
    St  *s;
    s32  on;
    s32  h;
    s32  z;

    s = &g_0214E9FC;
    if (s->f00 == 0) {
        return;
    }

    on = (s->f2c >= 0);
    func_020894DC(s->f24, s->f28, on ? (u32)(1 << s->f2c) : 0, 0);

    if (on) {
        h = func_02089D40();
        func_02089B38(1);
        func_02089CD4(h);
        z = 0;
        while (func_02085E50(g_0214E9BC, z, z) != 0)
            ;
    }

    if (s->f28 != 0) {
        SND_CHANNEL_ClearClaimedMask(s->f28);
    }
    if (s->f20 != 0) {
        SND_CHANNEL_UnlockChannels(s->f20);
    }
    if (on) {
        NNS_SndWaveOutFreeChannel(s->f2c);
    }
    if (s->f04 == 1) {
        func_0208972C(0, 0, 0, 0);
    }
    s->f00 = 0;
}
