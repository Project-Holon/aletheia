/*
 * function: func_021F2F44
 * address:  0x021F2F44
 * packet:   pkt_ov032_021F2F44
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note:     func_0204B258 takes two arguments (twin ov029_func_021F1DE8): the
 *           0x12C result still in r1 at that call is its second argument.
 * symbols:
 *   func_021F2F44 0x021F2F44 thumb
 *   d_021F35E0 0x021F35E0 data ov032 a4
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_021F3264 0x021F3264 thumb ov032
 *   func_021F32F8 0x021F32F8 thumb ov032
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj00007.h"

typedef struct { int w[4]; } T16;

extern T16 d_021F35E0;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void func_021F3264(char *);
extern void func_021F32F8(char *, unsigned char);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);

void func_021F2F44(char *p, void *a)
{
    T16 t;
    int i;

    ((struct Obj00007 *)p)->f128 = CLACT_CreateUnit(0x40, 0, ((struct Obj00007 *)p)->f94);
    t = d_021F35E0;
    ((struct Obj00007 *)p)->f12C = CLACT_CreateRenderer((u8 *)(&t), 1, ((struct Obj00007 *)p)->f98);
    func_0204B258(((struct Obj00007 *)p)->f128, ((struct Obj00007 *)p)->f12C);
    ((struct Obj00007 *)p)->f124 = BMP_OAM_CreateSys(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f128);
    func_021F3264(p);
    for (i = 0; i < 5; i++) {
        func_021F32F8(p, i);
    }
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
