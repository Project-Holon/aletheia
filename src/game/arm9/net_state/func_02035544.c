/*
 * function: func_02035544
 * address:  0x02035544
 * packet:   pkt_02035544
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
 *
 * The soft-reset trap: fade both screens to white, tear the UI down, then spin
 * forever pumping the main loop's per-frame work.  The loop never exits (the
 * image's tail is an unconditional `b` back to the func_0203D210 test), and
 * the reset path inside it returns through OS_ResetSystem.
 *
 * Both master-brightness registers come off one pool word: 0x0400006C is the
 * main engine's MASTER_BRIGHT and the sub engine's sits +0x1000 away, which is
 * why the image loads the base once into r5 and spells the second as
 * `add r0, r5, #0x1000`.  The brightness value 0x10 and the OS_WaitIrq mask
 * are both kept in r4 across the calls, and the `mov r4, #1` that retargets it
 * sits before the loop head.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035544.c \
 *       --func func_02035544 --addr 0x02035544 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct UiCtx;

extern struct UiCtx *sub_02035224(void);
extern void GXx_SetMasterBrightness_(u32 reg, int brightness);
extern int func_0203CEAC(int a0);
extern u32 func_0203D210(void);
extern u32 func_02076B8C(void);
extern void sub_02035428(u32 status);
extern void OS_ResetSystem(u32 param);
extern void OS_WaitIrq(u32 clear, u32 irqFlags);
extern u32 func_0203CF5C(void);
extern void func_0204E638(void);

void func_02035544(u32 param)
{
    struct UiCtx *ctx;

    ctx = sub_02035224();
    GXx_SetMasterBrightness_(0x0400006C, 0x10);
    GXx_SetMasterBrightness_(0x0400006C + 0x1000, 0x10);
    func_0203CEAC(0);

    while (1) {
        if (func_0203D210() != 0 && func_02076B8C() != 0) {
            sub_02035428(((u8 *)ctx)[0x3b]);
            OS_ResetSystem(param);
        }
        OS_WaitIrq(1, 1);
        func_0203CF5C();
        func_0204E638();
    }
}
