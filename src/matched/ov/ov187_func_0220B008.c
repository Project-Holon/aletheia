/*
 * function: func_0220B008
 * address:  0x0220B008
 * packet:   pkt_0220B008
 * region:   ov187
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02031324  0x02031324  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 *f0;
    u8 pad[0xc];
    u16 f10;
    u8 pad2[2];
    u32 f14;
    u32 f18;
};

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 *func_02031324(u32 c);

void func_0220B008(struct S *p, u32 a, u32 b, u32 c)
{
    func_02082BCC(p, 0, 0x28);
    p->f0 = func_02031324(c);
    p->f14 = b;
    p->f18 = a;
    p->f10 = c;
}
