/*
 * function: func_021ADE4C
 * address:  0x021ADE4C
 * packet:   pkt_ov021_021ADE4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

struct Rec;
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);

void func_021ADE4C(u32 a, Q *q)
{
    int i;

    for (i = 0; i < 4; i++)
        func_0204762C((struct Rec *)q->arr[i]);
    func_02047738((struct Rec *)q->f4);
    func_02047504((struct Rec *)q->f18);
}
