/*
 * function: GFL_HEAP_Init
 * address:  0x02030608
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Every one of the 68 concrete bytes is reproduced.  Blocked on: no evidence
 * class for 0x0202FC48.  It has no caller outside this range and no matched
 * entry, so the PC24 at +0x14 stays wildcarded, and it is not adjacent, so no
 * cut reaches it.  0x0202FC48 is a 380-byte initialiser that currently stops
 * four bytes short on register allocation alone; the analysis and everything
 * already ruled out are in docs/notes/GFL_HEAP_InitManager.c.txt.  Closing that
 * function graduates this file unchanged.
 *
 * symbols:
 *   GFL_HEAP_InitManager  0x0202FC48  arm
 *   sub_02030524  0x02030524  arm
 *   sub_02086580  0x02086580  arm
 *   sub_0208656C  0x0208656C  arm
 *   sub_02088234  0x02088234  arm
 *
 * Bring the module up and, if that failed, hand the failure to the reporter.
 * The two notifications with a zero argument run either way; only the final
 * report is conditional.
 *
 * The `lsl #16` / `lsr #16` pairs on both arguments before the call are the
 * truncation into 0x0202FC48's two u16 parameters, so this function's own
 * parameters are the wider type: nothing else in the body produces them.
 *
 * The literal zero passed twice lives in the callee-saved r4 rather than
 * being rematerialised at each call site
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_Init.c \
 *       --func GFL_HEAP_Init --addr 0x02030608 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct EnvRes;
extern int GFL_HEAP_InitManager(const struct EnvRes *res, u16 count, u16 idCount, u32 extra);
extern u16 sub_02030524(void);
extern void  sub_02086580(u32 a);
extern void  sub_0208656C(u32 a);
extern void  sub_02088234(void *obj);

void GFL_HEAP_Init(u32 a, u32 b, u32 c, u32 d)
{
    int ok;

    ok = GFL_HEAP_InitManager((const struct EnvRes *)a, b, c, d);
    sub_02086580(0);
    sub_0208656C(0);
    if (ok != 0) {
        return;
    }
    sub_02088234((void *)sub_02030524());
}
