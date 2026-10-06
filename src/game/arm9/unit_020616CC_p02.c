/*
 * file:     unit_020616CC_p02.c
 * unit:     yes
 * function: func_02061808, func_02061824, func_02061840, func_02061860, func_02061878, func_0206188C, func_020618B8, func_020618E4, func_02061908
 * address:  0x02061808
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146B74       0x02146B74  data
 *   _u32_div_f   0x0209C2B0  arm
 */
#include "../../matched/include/Obj11496.h"
#include "../../matched/include/Obj16393.h"
#include "../../matched/include/Obj04778.h"
#include "../../matched/include/Obj16394.h"

struct Obj02061BD0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Pair02061808 {
    u32 a;
    u32 b;
};

void func_02061824(void *p0);
u32 func_02061840(u8 *p, u32 v);
int func_02061860(u8 *p);
extern void func_0207F7A0(void);
extern void func_0207F7FC(u32 a, u32 b, u32 c);
extern void func_0207F9B4(void);
extern void func_0207FA0C(void);
extern void func_0207FA40(u32 a, u32 b, u32 c);
extern void func_0207FADC(void);
extern void func_0207FB2C(void);
extern void func_0207FBBC(u32 a, u32 c);
extern void func_0207FCE4(void);
extern void func_0207FC48(u32 a, u32 c);
void func_0206188C(u32 a, u32 b, u32 c);
void func_020618B8(u32 a, u32 b, u32 c);
void func_020618E4(u32 a, u32 b, u32 c);
void func_02061908(u32 a, u32 b, u32 c);
extern struct Pair02061808 g_02146B74;



void func_02061808(struct Pair02061808 *dst)
{
    dst->a = g_02146B74.a;
    dst->b = g_02146B74.b;
}



void func_02061824(void *p0){ *(int *)(0x2146B74) = (int)((struct Obj11496 *)p0)->f0; *(int *)((0x2146B74 + 4)) = (int)((struct Obj11496 *)p0)->f4; }



/*
 * Returns (value + 1) modulo the +4 word, truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061840.c \
 *       --func func_02061840 --addr 0x02061840 --arm --cc 1.1p1
 */
u32 func_02061840(u8 *p, u32 v)
{
    return (u16)((v + 1) % ((struct Obj16393 *)p)->f4);
}



/*
 * Returns whether the +0xc halfword equals the +4 word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061860.c \
 *       --func func_02061860 --addr 0x02061860 --arm --cc 1.1p1
 */
int func_02061860(u8 *p)
{
    u16 a = ((struct Obj04778 *)p)->fC;
    u32 b = ((struct Obj04778 *)p)->f4;

    return a == b ? 1 : 0;
}



/*
 * Returns whether the +0xc halfword is zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061878.c \
 *       --func func_02061878 --addr 0x02061878 --arm --cc 1.1p1
 */
int func_02061878(struct Obj02061BD0 *p)
{
    return ((struct Obj16394 *)p)->fC == 0 ? 1 : 0;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206188C.c \
 *       --func func_0206188C --addr 0x0206188C --arm --cc 1.1p1
 */
void func_0206188C(u32 a, u32 b, u32 c)
{
    func_0207F7A0();
    func_0207F7FC(a, b, c);
    func_0207F9B4();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020618B8.c \
 *       --func func_020618B8 --addr 0x020618B8 --arm --cc 1.1p1
 */
void func_020618B8(u32 a, u32 b, u32 c)
{
    func_0207FA0C();
    func_0207FA40(a, b, c);
    func_0207FADC();
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FBBC (GX_LoadClearImageColor) has exactly one
 * branch reference image wide and it is that call, so no cut of a
 * one-function range frees it.  Blocking evidence class: label/matched, no
 * outside witness -- the SDK table names the address but attest() has no
 * class that trusts a table alone.  It unsticks when the callee has its own
 * EXACT entry or a second caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020618E4.c \
 *       --func func_020618E4 --addr 0x020618E4 --arm --cc 1.1p1
 */
void func_020618E4(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FBBC(a, c);
    func_0207FCE4();
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FC48 (GX_LoadClearImageDepth) has exactly one
 * branch reference image wide and it is that call.  Same class and same
 * unblock as src/pending/func_020618E4.c: label/matched, no outside witness.
 * The `*` is disasm.py's extent for the original running past the leaf.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02061908.c \
 *       --func func_02061908 --addr 0x02061908 --arm --cc 1.1p1
 */
void func_02061908(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FC48(a, c);
    func_0207FCE4();
}
