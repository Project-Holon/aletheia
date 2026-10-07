/*
 * file:     net_state_p42.c
 * unit:     yes
 * function: func_0203C010, func_0203C044, func_0203C05C, func_0203C060, func_0203C064, func_0203C068, func_0203C0B4, func_0203C0DC, func_0203C0F4
 * address:  0x0203C010
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
 *   func_020379C8  0x020379C8  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203C00C  0x0203C00C  arm
 *   unk_021469DC   0x021469DC  data
 *   func_0203D788  0x0203D788  arm
 *   g_021469DC     0x021469DC  data
 */
#include "../../matched/include/Obj15960.h"
#include "../../matched/include/Obj15961.h"
#include "../../matched/include/Obj15962.h"
#include "../../matched/include/Obj11369.h"

struct NetState;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int    s32;

extern int func_020379C8(u32 p);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203C00C(void);
extern void *func_0203D788(void);
extern void func_020394DC(u8 v);
void func_0203C010(void);
int func_0203C044(int a0, int a1, int a2, int a3);
void func_0203C05C(void);
void func_0203C060(void);
void func_0203C064(void);
void func_0203C068(void);
void func_0203C0B4(void);
void func_0203C0DC(u8 *p, u32 v);
void func_0203C0F4(void *p);
extern u32  unk_021469DC;
extern int  g_021469DC;



/*
 * PROMOTED FROM src/pending/ AT THE END OF WAVE 4 LANE 0x02038000..0x02040000.
 * It was parked at MATCH with every concrete byte right, held there only by
 * the `bl` to 0x020379C8, which nothing outside this range witnessed.  That
 * address has since been matched, so the site now resolves on the `matched`
 * class and the whole 52 bytes are EXACT with no change to the C at all.
 *
 * The callback stub this file passes, 0x0203C00C, is matched as well now, as
 * the last function of src/matched/unit_0203BF9C.c.
 *
 * Allocates 0x200 bytes, then starts the card task on the object at
 * 0x021469DC with the four-byte `bx lr` stub at 0x0203C00C as its callback and
 * 0x4DA (1242) as the fourth argument - the source file/line pair of an assert
 * style entry point.  The stub is a real 4-byte ARM function in the listing, so
 * its address is declared as the function it is and passed as a function
 * pointer; the pool word for it is attested by a dozen other pools elsewhere
 * in the image, and unk_021469DC likewise.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203C010.c \
 *       --func func_0203C010 --addr 0x0203C010 --cc 1.1p1 --arm
 */
void func_0203C010(void)
{
    func_020379C8(0x200);
    func_0203AD80((struct NetState *)unk_021469DC, func_0203C00C, 0, 0x4DA);
}



int func_0203C044(int a0, int a1, int a2, int a3){ int t0; t0 = func_0203D798(); ((struct Obj15961 *)((char *)(t0)))->f64 = (unsigned char)((struct Obj15960 *)((char *)(a2)))->f0; return t0; }


/*
 * Empty callback (a lone bx lr), one of three adjacent stubs at
 * 0x0203C05C/60/64 whose addresses func_0203C0F4, func_0203C3EC,
 * func_0203C494 and func_0203C7E0 pass or compare as handler pointers.
 */
void func_0203C05C(void)
{
}


void func_0203C060(void)
{
}


void func_0203C064(void)
{
}



/*
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through func_0203AD80 when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C068.c  *       --func func_0203C068 --addr 0x0203C068 --cc 1.1p1 --arm
 */
void func_0203C068(void)
{
    if (((int (*)(u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0xC))(0) < 0)
        func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203C05C, 0, (int)0x52C);
}


void func_0203C0B4(void)
{
    int *r = func_0203D788();
    void (*fn)(int);
    func_020394DC(1);
    fn = *(void (**)(int))(((struct Obj15962 *)r)->f340 + 0xc);
    fn(0);
}



/*
 * Stores one byte at +0x4E, negating it first unless it is 1005 or 1006.  The
 * threshold is written `v - 1005 > 1`, and 1005 is not encodable as an ARM
 * immediate in a `sub`, so mwcc builds it the other way round: `mvn r2, #1004`
 * is -1005 and one `add` finishes the subtraction.  The comparison is
 * unsigned (`rsbhi`), and the negation is `rsb r1, r1, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C0DC.c \
 *       --func func_0203C0DC --addr 0x0203C0DC --cc 1.1p1 --arm
 */
void func_0203C0DC(u8 *p, u32 v)
{
    if (v - 1005 > 1)
        v = -v;
    p[0x4E] = (u8)v;
}


void func_0203C0F4(void *p)
{
    u8 *net = func_0203D788();
    u32 *obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    s32 res = ((s32 (*)(int))obj[3])(0);

    if (res == 1000) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C0B4, 0, 1403);
        return;
    }

    obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    if (((s32 (*)(void))obj[0xac / 4])() != 0) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C0B4, 0, 1407);
        return;
    }

    if (res == 1007) {
        return;
    }

    if (res == 1001) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C060, 0, 1413);
        return;
    }

    if (res == 1002) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C064, 0, 1416);
        return;
    }

    if (res >= 10) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C064, 0, 1420);
        return;
    }

    if (res >= 0) {
        return;
    }

    func_0203C0DC(p, res);
    func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203C05C, 0, 1424);
}
