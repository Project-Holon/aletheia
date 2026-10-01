/*
 * function: func_021BD234
 * address:  0x021BD234
 * packet:   pkt_ov021_021BD234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x44];
    int f44;
    u16 h48;
} Obj;

extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02045A98(void);

void func_021BD234(Obj *p)
{
    func_02082BCC(p, 0, 0x4C);
    p->f44 = 0;
    p->h48 = func_02045A98();
}
