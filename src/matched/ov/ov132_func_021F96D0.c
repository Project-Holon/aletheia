/*
 * function: func_021F96D0
 * address: 0x021F96D0
 * packet: pkt_ov132_021F96D0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021F96D0(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char **)(p + 0x30);
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) func_020061E4(1578);
    else if (min >= 30) func_020061E4(1579);
    else if (min >= 1) func_020061E4(1580);
}
