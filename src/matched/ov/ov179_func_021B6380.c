/*
 * function: func_021B6380
 * address: 0x021B6380
 * packet: pkt_ov179_021B6380
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E30 0x02005E30 thumb
 *   d_021B6A04 0x021B6A04 data a4
 */

typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_02005F38(void);
extern void func_02005E30(unsigned v);
extern int (*const d_021B6A04[])(char *);
int func_021B6380(char *p)
{
    if (((unsigned char *)*(char **)p)[2] != 0 && (func_020362DC() & 0xB) != 0) {
        if (func_02005F38() == 1)
            func_02005E30(8);
        *(int *)(p + 0x6050) = 1;
        (*(char **)p)[3] = 1;
    }
    *(int *)(p + 0x6050) = d_021B6A04[*(int *)(p + 0x6050)](p);
    if (*(int *)(p + 0x6050) != 6)
        return 1;
    return 0;
}
