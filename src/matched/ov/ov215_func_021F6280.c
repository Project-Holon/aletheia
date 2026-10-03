/*
 * function: func_021F6280
 * address:  0x021F6280
 * packet:   pkt_021F6280
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FA08 0x0203FA08 arm
 *   func_0203FB44 0x0203FB44 arm
 */

typedef unsigned int   u32;
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);

void func_021F6280(int unused, unsigned char *q)
{
    int h = func_0203FA08(1, 0x500, 1);

    func_0203FB44(1, h, 0x500);
    q[0x70] = 1;
    q[0x71] = 0x18;
    q[0x72] = 0xd;
    q[0x73] = 1;
    *(unsigned short *)(q + 0x74) = h;
    *(int *)(q + 0x7c) = 2;
}
