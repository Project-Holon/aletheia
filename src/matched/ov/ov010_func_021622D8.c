/*
 * function: func_021622D8
 * address: 0x021622D8
 * packet: pkt_ov010_021622D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned short u16;
extern void func_02082D44(void *, void *, unsigned);
int func_021622D8(char *p, void *out)
{
    int result = 0;
    if (*(u16 *)(p + 2) & 16) {
        func_02082D44(p + 0x28, out, 8);
        result = 1;
    }
    return result;
}
