/*
 * function: func_021AD8A4
 * address:  0x021AD8A4
 * packet:   pkt_ov021_021AD8A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Z { u32 f0; u32 arr[4]; u32 f14; } Z;
typedef struct W { u8 pad[0x88]; u8 n; } W;

extern void func_0204762C(u32 a);
extern void func_02047738(u32 a);
extern void func_02047504(u32 a);

void func_021AD8A4(Z *z, W *w)
{
    int i;

    for (i = 0; i < w->n; i++)
        func_0204762C(z->arr[i]);
    func_02047738(z->f0);
    func_02047504(z->f14);
}
