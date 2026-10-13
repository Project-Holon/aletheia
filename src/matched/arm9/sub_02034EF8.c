/*
 * function: sub_02034EF8
 * address:  0x02034EF8
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020352DC  0x020352DC  arm
 *   KEY_Main  0x020360A8  arm
 *   TOUCHPANEL_Main  0x02035A60  arm
 *   UI_ServiceLidSleep  0x0203545C  arm
 *   sub_020356A0  0x020356A0  arm
 *   KEY_GetCont  0x0203630C  arm
 *   sub_02035544  0x02035544  arm
 *
 * One tick of the main loop the areaman singleton drives: bump the frame
 * counter at +0x3e, run the five per-frame services in order, then, only
 * when both pad bits 0x30c are held and the +0x39 inhibit byte is clear,
 * fire the registered callback at +8 with its argument at +0xc and hand 0
 * to sub_02035544.
 *
 * The callback null test and the sub_02035544 call are one block: the `beq`
 * over the `blx` lands on the `mov r0, #0` that sets up the last call, so
 * sub_02035544 runs whether or not a callback was installed.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  All five per-frame
 * services it calls are reached from this one site only, so each needs to be
 * EXACT in the manifest before its `bl` resolves on `matched`:
 *
 *   0x020352DC, 0x020360A8, 0x02035A60, 0x0203545C, 0x020356A0
 *
 * Of those, 0x0203545C is the blocker that cannot be cleared from inside
 * this territory: src/pending/UI_ServiceLidSleep.c is byte-correct but capped on
 * PM_GoSleepMode (0x0208C154), which the whole image calls exactly once,
 * from that function.  0x02035A60 and 0x020360A8 are byte-correct too
 * (src/pending/) and capped on their own single-caller callees 0x020358A0
 * and 0x02035F38.  So this function stays MATCH until the 0x02035000 block
 * is finished bottom-up, and even then only if PM_GoSleepMode acquires a
 * second call site.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034EF8.c \
 *       --func sub_02034EF8 --addr 0x02034EF8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct AreaCtx {
    u32 unk00;
    u32 unk04;
    void (*fn)(u32);
    u32  arg;
    u8   unk10[0x29];
    u8   inhibit;
    u8   unk3A[4];
    u8   frames;
};

extern void sub_020352DC(void);
extern void KEY_Main(void);
extern void TOUCHPANEL_Main(void);
extern void UI_ServiceLidSleep(void);
extern void sub_020356A0(int a0);
extern unsigned int KEY_GetCont(void);
extern void sub_02035544(u32 x);

void sub_02034EF8(struct AreaCtx *p)
{
    p->frames++;

    sub_020352DC();
    KEY_Main();
    TOUCHPANEL_Main();
    UI_ServiceLidSleep();
    sub_020356A0((int)p);

    if ((KEY_GetCont() & 0x30C) == 0x30C && p->inhibit == 0) {
        if (p->fn != 0) {
            p->fn(p->arg);
        }
        sub_02035544(0);
    }
}
