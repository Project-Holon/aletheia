/*
 * function: func_021BD9B4
 * address: 0x021BD9B4
 * packet: pkt_ov099_021BD9B4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned int u32;
extern int func_020399A8(void);
extern int func_02039CB4(u32, u32, u32);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
int func_021BD9B4(char *p, int v)
{
    if (func_02039CB4(func_020399A8(), 0x1b, 10) != 0) {
        if (func_0203D3A8(func_020399A8(), 0xa05, 1, p + 0x1353) != 0) {
            *(int *)(p + 0x1cc) = 0x48;
        }
    }
    return v;
}
