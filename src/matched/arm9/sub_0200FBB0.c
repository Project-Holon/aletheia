/*
 * function: sub_0200FBB0
 * address:  0x0200FBB0
 * packet:   pkt_0200FBB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_02178E4C  0x02178E4C  thumb
 *   func_0203CFA0  0x0203CFA0  arm
 *   func_0201034C  0x0201034C  thumb
 *   func_0208459C  0x0208459C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *
 * A polling loop, gated on func_0203CD98(): returns 1 immediately if it is
 * zero. Otherwise fetches the same status object sub_0200F734 reads
 * (func_0203D798, offset +0x65), resets three link-state counters, then
 * polls func_0203CDBC() once per iteration, quitting the moment it stops
 * returning zero. Each iteration checks the status byte first: 0 or 5
 * means "ready to ask", and if func_02178E4C() then answers 0xa the
 * function returns 0 straight out of the loop.
 *
 * Every concrete byte matches; func_0203CFA0 is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule. The other nine calls all resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FBB0.c \
 *       --func sub_0200FBB0 --addr 0x0200FBB0 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_0203CFA0 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day either
 * func_0203CFA0 gets a second caller elsewhere in the image, or is itself
 * matched.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_0203CD98(void);
extern void *func_0203D798(void);
extern void func_0203CF04(void);
extern int func_0203CEAC(int a0);
extern void func_0203D0D0(void);
extern u32  func_02178E4C(void);
extern void func_0203CFA0(void);
extern int func_0201034C(void);
extern void func_0208459C(int clear, u32 irqFlags);
extern int func_0203CDBC(void);

u32 sub_0200FBB0(void)
{
    u8 *obj;
    u32 flag;

    if (func_0203CD98() != 0) {
        obj = func_0203D798();
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        flag = 1;

        for (;;) {
            if (obj != 0) {
                u8 v = obj[0x65];
                if (v == 0 || v == 5) {
                    if (func_02178E4C() == 0xa) {
                        return 0;
                    }
                }
            }
            func_0203CFA0();
            func_0201034C();
            func_0208459C(flag, flag);
            if (func_0203CDBC() == 0) {
                continue;
            }
            break;
        }
    }

    return 1;
}
