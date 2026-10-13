/*
 * function: func_021BB460
 * address:  0x021BB460
 * packet:   pkt_ov099_021BB460
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C388C     0x021C388C  data   ov099  a4
 *   func_02082BCC  0x02082BCC  arm
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   TOUCHBAR_SetButtonKeyMask  0x021B6578  thumb  ov067
 */
#include "../include/Obj07942.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int v[8];
} T8;

typedef struct {
    void *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} A;

extern const T8 d_021C388C;
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *TOUCHBAR_Create(A *a, int heap);
extern void TOUCHBAR_SetButtonKeyMask(unsigned char *p, unsigned int id, int v);

void func_021BB460(char *p, int x)
{
    T8 t;
    A a;
    void *r;

    t = d_021C388C;
    if (((struct Obj07942 *)p)->f9AC == 0) {
        func_02082BCC(&a, 0, 0x20);
        a.f0 = &t;
        a.f4 = 1;
        a.f8 = ((struct Obj07942 *)p)->f110;
        a.f1c = 0;
        a.fC = 4;
        a.f10 = 0xC;
        a.f14 = 0xC;
        a.f18 = 2;
        r = TOUCHBAR_Create(&a, x);
        ((struct Obj07942 *)p)->f9AC = r;
        TOUCHBAR_SetButtonKeyMask(r, 1, 0);
    }
}
