/*
 * function: func_021BC730
 * address:  0x021BC730
 * packet:   pkt_ov021_021BC730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9B78     0x021D9B78  data  a4
 */

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x2A];
    void *f38;
} Obj;

extern int d_021D9B78;

extern void *func_0204B034(void *a, unsigned int a1, unsigned int heap);

void func_021BC730(Obj *p)
{
    p->f38 = func_0204B034(&d_021D9B78, 1, p->hC);
}
