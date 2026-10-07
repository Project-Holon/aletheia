/*
 * file:     field_gimmick_gate_p02.c
 * unit:     yes
 * function: func_021F3818, func_021F3830
 * address:  0x021F3818
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3B8 0x0200C3B8 thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02014314  0x02014314  thumb
 *   func_021F37A4  0x021F37A4  thumb  ov048
 */
#include "../../matched/include/Obj00377.h"

struct Big;
struct Blk34;
struct BigObj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern void func_0200C3B8(struct Blk34 *p, u16 v);
extern unsigned int func_0201296C(const struct BigObj *p);
extern void func_02014314(char *a0, int a1);
extern u8 *func_021F37A4(u32 a);
void func_021F3818(int *p);
void func_021F3830(int *p);

void func_021F3818(int *p) { func_0200C3B8(func_0200C0F0(func_02012EBC(((struct Obj00377 *)p)->f8)), ((struct Obj00377 *)p)->f64); }


void func_021F3830(int *p)
{
    int r6;
    int i;
    u8 *q;

    r6 = (int)func_0201296C((const struct BigObj *)p[2]);
    q = func_021F37A4(p[1]) + 0xc;
    for (i = 0; i < q[0]; i++) {
        if (*(int *)(q + i * 4 + 4) == 8) {
            func_02014314((char *)r6, (u16)(*(int *)(q + i * 4 + 0x20)));
        }
    }
}
