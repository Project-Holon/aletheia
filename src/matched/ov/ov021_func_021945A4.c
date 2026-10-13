/*
 * function: func_021945A4
 * address:  0x021945A4
 * packet:   pkt_ov021_021945A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021945E0  0x021945E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 FIELDMAP_GetSubscreen(u8 *p);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern int func_021945E0(void *a, int b, u8 *c);

void *func_021945A4(void *a, u32 b, u32 c)
{
    void *t;
    u32 *w;

    FIELDMAP_GetSubscreen((u8 *)b);
    t = func_020122C0(a, 0, func_021945E0, 0x14);
    w = func_020124E8(t);
    MI_CpuFill8(w, 0, 0x14);
    w[1] = (u32)a;
    w[0] = (u32)t;
    w[2] = b;
    w[3] = c;
    return t;
}
