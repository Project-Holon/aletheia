/*
 * function: func_021FAB0C
 * address: 0x021FAB0C
 * packet: pkt_ov094_021FAB0C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * witness: arm9 func_02051788 filed as src/matched/arm9/func_02051788.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201134C 0x0201134C thumb
 *   func_020515CC 0x020515CC arm
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209DA8, d_02209D9C;
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_020515CC(int *p, int a, int b, int c);
extern void func_02051648(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int func_02051788(char *p);
extern u32 func_021FE38C(char *, u32);
extern int func_021FD1A8(char *, int);
extern void func_021FD1CC(void *p);
int func_021FAB0C(void *a, char *s)
{
    Desc desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = 8;
    p[10] = func_0201134C(a);
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[20] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[16] = 3;
    if (idx != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209DA8;
        v2 = d_02209D9C;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (func_02051788(*(void **)(s + 0xc + idx * 4)) == 0)
            func_02051648(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
