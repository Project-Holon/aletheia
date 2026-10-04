/*
 * function: func_021BC948
 * address:  0x021BC948
 * packet:   pkt_ov021_021BC948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD1D4  0x021BD1D4  thumb  ov021
 *   func_021BD1E4  0x021BD1E4  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
    char pad2[0x149 - 0xC8 - 0x80];
    u8 b149;
} Obj;

extern void func_021BD1D4(void *a);
extern void func_021BD1E4(void *a, unsigned int b);

void func_021BC948(Obj *p)
{
    u8 i = p->b149++;

    if (p->fC8[i] != 0) {
        func_021BD1D4(p->fC8[i]);
        func_021BD1E4(p->fC8[i], 1);
    }
}
