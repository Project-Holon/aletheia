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

struct Rec;
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);

void func_021AD8A4(Z *z, W *w)
{
    int i;

    for (i = 0; i < w->n; i++)
        func_0204762C((struct Rec *)z->arr[i]);
    func_02047738((struct Rec *)z->f0);
    func_02047504((struct Rec *)z->f14);
}
