/*
 * unit: yes
 * function: func_021E448C, func_021E4558
 * address: 0x021E448C
 * packet: pkt_ov093_021E448C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D7D78 0x021D7D78 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F278C 0x021F278C data a4
 */
#include "../include/Obj02433.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B48(u8 *p);
extern Word func_021D7D78(int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int, u32);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern int d_021F278C[];

void func_021E448C(int unused, void *s, int k)
{
    void *q;
    u8 *p;
    u32 n;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(s, k);
        if (func_021D5B48(q) == 0) {
            p = func_021C88A4(s, 12, k);
            p[15] = k;
            ((struct Obj02433 *)p)->f4 = 2;
            *(Word *)(p + 8) = func_021D7D78(3);
            p[12] = 1;
            p[16] = 1;
            p[14] = 1;
            func_021C8838(p + 20, 2, 638);
            func_021C8860((struct S *)(p + 20), k);
            func_021C88C8(s, p);
            p = func_021C88A4(s, 5, k);
            p[6] = k;
            n = func_021D59B4(q, 14);
            *(u16 *)&((struct Obj02433 *)p)->f4 = n - func_021D59B4(q, 13);
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 33, k);
            p[4] = k;
            ((struct Obj02433 *)p)->f8 = 3;
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            func_021D76BC(81, 0);
        }
    }
}

int *func_021E4558(int *p)
{
    *p = 1;
    return d_021F278C;
}
