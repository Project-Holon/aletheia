/*
 * function: func_021BD558
 * address: 0x021BD558
 * packet: pkt_ov099_021BD558
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021BC06C 0x021BC06C thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *);
extern void func_021BAAB8(char *, int, int);
int func_021BD558(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BAAB8(p, 0x71, 0);
        *(u32 *)(p + 0x1cc) = 0x65;
    }
    return v;
}
