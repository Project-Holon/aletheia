/*
 * function: func_021BC6E8
 * address:  0x021BC6E8
 * packet:   pkt_ov021_021BC6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0x28];
    int f28;
} Obj;

typedef unsigned int   u32;
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);

void func_021BC6E8(Obj *p)
{
    if (p->f28 == -1) {
        p->f28 = func_0203FA08(3, 0x20, 0);
    }
}
