/*
 * function: func_021BD0BC
 * address: 0x021BD0BC
 * packet: pkt_ov099_021BD0BC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
extern u32 func_020362DC(void);
int func_021BD0BC(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (func_020362DC() == 0) return v;
    *(u8 *)(p + 0x1353) = 0x6e;
    *(u32 *)(p + 0x1cc) = 0x8a;
    return v;
}
