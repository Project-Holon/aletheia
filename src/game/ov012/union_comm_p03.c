/*
 * file:     union_comm_p03.c
 * unit:     yes
 * function: func_02172CAC, func_02172CE8, func_02172D14, func_02172D20, func_02172D38, func_02172D50
 * address:  0x02172CAC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02172C1C 0x02172C1C thumb ov012
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 */
#include "../../matched/include/Obj09356.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_0203CEAC(int a0);
extern void func_02172C1C(void *a, u8 *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
int func_02172CAC(void *a, void *b, u8 *p);
int func_02172CE8(void *a, void *b, u8 *p);
void func_02172D14(u8 *p);
void func_02172D20(u8 *p);
void func_02172D38(u8 *p);
void func_02172D50(u8 *p);

int func_02172CAC(void *a, void *b, u8 *p) { ((struct Obj09356 *)p)->f356C = 1; if (p[0x3560] < 3) return 0; p[0x3560] = 4; if (func_0203CEAC((int)func_02172D14) == 0) func_02172D14(p); return 1; }

int func_02172CE8(void *a, void *b, u8 *p) { if (p[0x3560] == 5) { func_02172C1C(b,p); if (func_0200FB24() != 0) func_0200FBA0(); return 1; } return 0; }

/*
 * extent: existing matched follower ov012_func_02172D20.c
 */
void func_02172D14(u8 *p) { p[0x3560] = 5; }


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov019 func_0217C074.
 */
void func_02172D20(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 0;
    }
}


void func_02172D38(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 1;
    }
}


void func_02172D50(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 2;
    }
}
