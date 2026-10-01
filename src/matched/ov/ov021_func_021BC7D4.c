/*
 * function: func_021BC7D4
 * address:  0x021BC7D4
 * packet:   pkt_ov021_021BC7D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD148  0x021BD148  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj;

extern void *func_021BD148(u16 a, void *b, int c, void *d);

void func_021BC7D4(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        p->f50[i] = func_021BD148(p->hC, p->f30, 0, p->f2C);
    }
}
