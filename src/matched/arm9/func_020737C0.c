/*
 * function: NNS_SndStrmInit
 * address:  0x020737C0
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Constructor for the 0x54-byte sound object: lazily create the heap through
 * func_02060468(gSndStrmList, 0) behind the one-shot latch gSndStrmListReady, install
 * the two callbacks (NNSi_SndStrmAlarmHandler at +0x08, func_02073CEC at +0x18) each with
 * the object itself as the following context word, null the handle pair at
 * +0x4C/+0x50, and clear bits 0 and 1 of the flags word at +0x2C.
 *
 * PINNED ../2.0/sp2, the pin four cluster siblings carry (NNS_SndStrmSetVolume,
 * NNS_SndStrmStop, NNSi_SndStrmAlarmHandler, NNS_SndHeapSaveState). docs/notes/NNS_SndStrmInit.c.txt
 * recorded this exact C as a 57-byte DIFF at 116 bytes against 120 under
 * dsi/1.1p1, where the read-modify-write of +0x2C is hoisted above the six
 * stores and the two `bic` immediates collapse. Under the pin the same C is
 * 120 bytes, 0 concrete mismatches.
 *
 * Two 1-bit clears must stay two statements: `p->f2c &= ~3` folds to one
 * `bic r0,r0,#3` and loses four bytes, which is what proves the source clears
 * two separate 1-bit fields rather than a 2-bit one.
 *
 * The note's second cap is also gone: the pool word naming gSndStrmListReady is this
 * function's own, but the 2026-09-21 sole-ref widening attests it (data start
 * in a data section), so this is EXACT and not MATCH.
 *
 * symbols:
 *   gSndStrmListReady     0x0214E8E4  data
 *   gSndStrmList     0x0214E8E8  data
 *   NNSi_SndStrmAlarmHandler  0x02073CA0  arm
 *   func_02073CEC  0x02073CEC  arm
 *   func_02060468  0x02060468  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndStrmInit.c \
 *       --func NNS_SndStrmInit --addr 0x020737C0 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  gSndStrmListReady;
extern u8   gSndStrmList[];
extern void func_02060468(int p0, int p1);
struct A;
struct Obj;
extern void NNSi_SndStrmAlarmHandler(struct Obj *o);
extern void func_02073CEC(struct A *a);

typedef struct S {
    char pad_00[8];
    void (*f08)(void);  /* 0x08 */
    u32  f0c;           /* 0x0c -- back-pointer to the object */
    char pad_10[8];
    void (*f18)(void);  /* 0x18 */
    u32  f1c;           /* 0x1c -- back-pointer to the object */
    char pad_20[0xc];
    u32  f2c;           /* 0x2c -- flags */
    char pad_30[0x1c];
    u32  f4c;           /* 0x4c */
    u32  f50;           /* 0x50 */
} S;

void NNS_SndStrmInit(S *p)
{
    if (gSndStrmListReady == 0) {
        func_02060468((int)gSndStrmList, 0);
        gSndStrmListReady = 1;
    }

    p->f08 = (void (*)(void))NNSi_SndStrmAlarmHandler;
    p->f0c = (u32)p;
    p->f18 = (void (*)(void))func_02073CEC;
    p->f1c = (u32)p;
    p->f4c = 0;
    p->f50 = 0;
    p->f2c &= ~1;
    p->f2c &= ~2;
}
