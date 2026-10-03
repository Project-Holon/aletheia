/*
 * function: func_0215CFB4
 * address:  0x0215CFB4
 * packet:   pkt_0215CFB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C340C  0x021C340C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D50(void *a0);
extern int func_021C340C();

int func_0215CFB4(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFBC:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFC4:
    v2 = func_0201210C(v1);
loc_0215CFC8:
    a0 = func_021C340C(func_02188D50(v2));
loc_0215CFCC:
loc_0215CFD0:
*(u16 *)((char *)v0) = a0;
a0 = 0;
    return a0;}
