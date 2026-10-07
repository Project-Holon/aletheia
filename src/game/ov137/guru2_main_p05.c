/*
 * file:     guru2_main_p05.c
 * unit:     yes
 * function: func_021DEA0C, func_021DEA68, func_021DEA70, func_021DEA84
 * address:  0x021DEA0C
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E217C 0x021E217C data a4
 *   func_021E0570 0x021E0570 thumb ov137
 *   func_021E07A4 0x021E07A4 thumb ov137
 *   func_021DF864 0x021DF864 thumb ov137
 *   func_02030D28 0x02030D28 arm
 *   func_021E0130  0x021E0130  thumb
 *   func_02039338 0x02039338 arm
 */
#include "../../matched/include/Obj23742.h"
#include "../../matched/include/Obj14219.h"
#include "../../matched/include/Obj23743.h"
#include "../../matched/include/Obj08214.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021E0570(u8 *p);
extern void func_021E07A4(char *p);
extern void func_021DF864(u8 *p);
extern void func_02030D28(struct Ctx *c);
extern u32 func_020221A4(void);
extern u32 func_0200FB24(void);
extern void func_021E0130(u8 *p, int message);
extern u16 func_02039338(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
int func_021DEA0C(int a, int b, int c, u8 *p);
void func_021DEA68(char *p);
int func_021DEA70(u8 *p);
int func_021DEA84(u8 *p);

extern int (*const d_021E217C[])(void *);

int func_021DEA0C(int a, int b, int c, u8 *p)
{
    int result;
    do { result = d_021E217C[*(int *)p](p); } while (result == 1);
    if (result == 2) return 1;
    func_021E0570(p);
    func_021E07A4((char *)p);
    func_021DF864(p);
    func_021DEA68((char *)p);
    func_02030D28(((struct Obj23742 *)p)->fD98);
    if (func_020221A4() && func_0200FB24()) return 1;
    return 0;
}

void func_021DEA68(char *p) { ((struct Obj14219 *)p)->f34=0;((struct Obj14219 *)p)->f3C=0; }


/*
 * Addresses are Black-image addresses.
 */
int func_021DEA70(u8 *p)
{
    func_021E0130(p, 0);
    ((struct Obj23743 *)p)->f0 = 1;
    return 0;
}

int func_021DEA84(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj08214 *)p)->f0 = func_02039338() == 0 ? 2 : 8;
        ((struct Obj08214 *)p)->fDA8 = func_0202EE30(((struct Obj08214 *)p)->fD98, ((struct Obj08214 *)p)->fCF0, 15, 16, 114);
        return 1;
    }
    return 0;
}
