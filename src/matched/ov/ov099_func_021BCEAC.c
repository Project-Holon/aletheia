/*
 * function: func_021BCEAC
 * address: 0x021BCEAC
 * packet: pkt_ov099_021BCEAC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021BC06C 0x021BC06C thumb ov099
 */
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *);
int func_021BCEAC(char *p, int ret)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        *(u32 *)(p + 0x1CC) = 0x4E;
    }
    return ret;
}
