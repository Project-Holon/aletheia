/*
 * function: func_021F0478
 * address: 0x021F0478
 * packet: pkt_ov031_021F0478
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021F0478(char *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        func_020452E8(*(void **)(p + 0x4c + i * 4));
    }
}
