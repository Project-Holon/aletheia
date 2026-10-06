/*
 * function: func_021E6EFC
 * address: 0x021E6EFC
 * packet: pkt_ov177_021E6EFC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021E6EFC(unsigned *p)
{
    unsigned i;
    for (i = 0; i < p[0]; i++) {
        if ((void *)p[i + 1] != 0)
            func_020452E8((void *)p[i + 1]);
    }
}
