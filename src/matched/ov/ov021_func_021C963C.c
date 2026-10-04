/*
 * function: func_021C963C
 * address:  0x021C963C
 * packet:   pkt_ov021_021C963C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047504  0x02047504  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;
struct Rec;
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
void func_021C963C(void *task, Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204762C((struct Rec *)q->f8[i]);
    func_02047738((struct Rec *)q->f4);
    func_02047504((struct Rec *)q->f14);
}
