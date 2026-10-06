/*
 * file:     net_err_p03.c
 * unit:     yes
 * function: func_0200FAAC, func_0200FB24, func_0200FB38, func_0200FB4C
 * address:  0x0200FAAC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203C990  0x0203C990  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203D798  0x0203D798  arm
 *   sub_02010054   0x02010054  thumb
 *   g0214617C      0x0214617C  data
 *   g_0214617C     0x0214617C  data  a4
 *   g_021461BC     0x021461BC  data  a4
 */
#include "../../matched/include/Obj03039.h"

typedef unsigned char u8;

typedef unsigned int  u32;

struct Blk16_0200FAAC {
    u32 w[4];
};

extern int   sub_02010054(void);
extern int   func_0203CDBC(void);
extern u32 func_0203C990(void);
extern u32 func_0203CA98(void);
extern u8   *func_0203D798(void);
void sub_0200FAAC(void);
u32 sub_0200FB24(void);
void func_0200FB38(void);
void func_0200FB4C(unsigned int x);
extern u8    g0214617C[];
extern unsigned int g_0214617C[];
extern unsigned char g_021461BC[];


/*
 * Wave 13: the parked MATCH named its global as 0x0202617C, a transcription
 * slip; the pool word at 0x0200FB20 reads 0x0214617C, the net_err.c module
 * object every sibling uses (literal x42), and the site resolves with it.
 */
void sub_0200FAAC(void)
{
    u8 *g = g0214617C;
    u8 t;

    if (sub_02010054() == 0) {
        return;
    }
    if (((struct Obj03039 *)g)->f2C != 0) {
        return;
    }
    ((struct Obj03039 *)g)->f2C = 1;
    if (func_0203CDBC() != 0) {
        return;
    }
    ((struct Obj03039 *)g)->f59 = func_0203D798()[0x65];
    *(struct Blk16_0200FAAC *)(g + 0x48) = *(struct Blk16_0200FAAC *)func_0203CA98();
    ((struct Obj03039 *)g)->f58 = (u8)func_0203C990();
    t = ((struct Obj03039 *)g)->f59;
    if (t == 1 || t == 2 || t == 6) {
        if ((u32)(((struct Obj03039 *)g)->f4C - 1) <= 1) {
            ((struct Obj03039 *)g)->f5C = 2;
        } else {
            ((struct Obj03039 *)g)->f5C = 1;
        }
        return;
    }
    ((struct Obj03039 *)g)->f5C = 2;
}


/*
 * A getter on the module-wide object at 0x0214617C (the same object
 * unit_0200F7C0.c names sub_0200F7C0_Obj): returns field +0x5c when field
 * +0x2c is set, 0 otherwise.
 *
 * EXACT* because the 20 compiled bytes fall 52 short of the disasm.py
 * extent: an unlabelled follower, sub_0200FB38, hides in the run of
 * literal-pool .word data right after this function (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * sub_0200FB38 itself (a conditional store: bump the object's +0x2c field
 * from 1 to 2) is a documented near miss: every write attempt reproduces
 * all twenty bytes but with r0 and r1 swapped throughout, a pure
 * register-numbering difference no source restructuring here changed, in
 * the same class as the codegen near misses in docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FB24.c \
 *       --func sub_0200FB24 --addr 0x0200FB24 --cc 1.1p1
 */
u32 sub_0200FB24(void)
{
    u32 *obj = (u32 *)0x0214617C;

    if (obj[0x2c / 4] != 0) {
        return obj[0x5c / 4];
    }
    return 0;
}


/*
 * Unlabelled Thumb leaf accessor: if the u32 at +0x2c of the object at
 * g_0214617C is 1, set it to 2.
 */
void func_0200FB38(void)
{
    if (g_0214617C[11] == 1) {
        g_0214617C[11] = 2;
    }
}


/*
 * Unlabelled Thumb leaf: if the u32 at +0x2c of the object at g_0214617C is
 * not 2, store the argument at +0x60, set two flag bytes of the object at
 * g_021461BC, and set +0x2c to 2.
 */
void func_0200FB4C(unsigned int x)
{
    if (g_0214617C[11] != 2) {
        g_0214617C[24] = x;
        g_021461BC[0x1a] = 1;
        g_021461BC[0x19] = 1;
        g_0214617C[11] = 2;
    }
}
