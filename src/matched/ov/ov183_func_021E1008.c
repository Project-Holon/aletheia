/*
 * function: func_021E1008
 * address: 0x021E1008
 * packet: pkt_ov183_021E1008
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 */
typedef short s16;
typedef unsigned char u8;
extern void func_0204B454(void *, s16 *, int);
void func_021E1008(char *p)
{
    int i, x, y;
    s16 pos[2];
    for (i = 0; i < *(int *)(p + 0x23c); i++) {
        if (i >= *(int *)(p + 0x248) && i < *(int *)(p + 0x24c)) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        func_0204B454(*(void **)(p + i * 28 + 12), pos, 1);
        (*(u8 **)(p + i * 28 + 16))[0] = pos[1] - y;
        (*(u8 **)(p + i * 28 + 16))[2] = pos[0] - x;
        (*(u8 **)(p + i * 28 + 16))[1] = pos[1] + y;
        (*(u8 **)(p + i * 28 + 16))[3] = pos[0] + x;
    }
}
