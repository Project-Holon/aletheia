/*
 * function: sub_0203545C
 * address:  0x0203545C
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   func_020353F8   0x020353F8  arm
 *   func_02035E08   0x02035E08  arm
 *   func_0203524C   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   func_020353C8   0x020353C8  arm
 *   func_020352AC   0x020352AC  arm
 *   func_02035268   0x02035268  arm
 *   func_02035DC8   0x02035DC8  arm
 *   func_02035428   0x02035428  arm
 *   func_02035284   0x02035284  arm
 *
 * The lid/sleep service, one of the five sub_02034EF8 runs per frame.  Bit
 * 15 of the halfword at 0x02FFFFA8 is the lid-closed flag; when it is set
 * and the veto predicate sub_020353F8 says no, the machine goes to sleep
 * with the whole shutdown/wake sequence around it, and when the predicate
 * says yes the context is instead marked as suspended (+0x43) with the
 * backlight forced off.  An open lid undoes the suspension.
 *
 * The flag is read as a signed `int`, hence `asrs r1, r1, #0xf` rather than
 * a logical shift: the halfword zero-extends into an `int`, the mask keeps
 * it positive, and the shift inherits the signed type.
 *
 * The literal 0 sits in r5 for the whole function because PM_GoSleepMode's
 * second and third arguments and the +0x43 store all want it.
 *
 * PARKED AT MATCH.  Every concrete byte is right, and fifteen of the sixteen
 * relocation sites resolve.  The sixteenth, PM_GoSleepMode at 0x0208C154, is
 * reached from exactly one place in the whole image: the `bl` at 0x020354A4
 * inside this function.  `label` therefore has no outside branch, and
 * `matched` would need an EXACT manifest entry for TwlSDK libspi code.  No
 * split can help, because the site is inside the only function that needs
 * it.
 *
 * This is what caps src/pending/sub_02034EF8.c as well.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203545C.c \
 *       --func sub_0203545C --addr 0x0203545C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct UiCtx {
    u8 pad00[0x3b];
    u8 backlight;
    u8 pad3c[7];
    u8 suspended;
};

extern struct UiCtx *func_02035224(void);
extern int  func_020353F8(struct UiCtx *p);
extern void func_02035E08(void);
extern void func_0203524C(struct UiCtx *p);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void func_020353C8(struct UiCtx *p);
extern void func_020352AC(struct UiCtx *p);
extern void func_02035268(struct UiCtx *p);
extern void func_02035DC8(void);
extern void func_02035428(u32 status);
extern void func_02035284(struct UiCtx *p);

void sub_0203545C(void)
{
    struct UiCtx *p;

    p = func_02035224();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (func_020353F8(p) == 0) {
            func_02035E08();
            func_0203524C(p);
            PM_GoSleepMode(0xC, 0, 0);
            func_020353C8(p);
            func_020352AC(p);
            func_02035268(p);
            func_02035DC8();
            if (p->suspended != 0) {
                p->suspended = 0;
                func_02035428(p->backlight);
            }
        } else {
            if (p->suspended == 0) {
                p->suspended = 1;
                func_02035428(0);
                func_02035284(p);
                func_0203524C(p);
            }
        }
    } else {
        if (p->suspended != 0) {
            p->suspended = 0;
            func_02035428(p->backlight);
            func_02035268(p);
            func_020352AC(p);
        }
    }
}
