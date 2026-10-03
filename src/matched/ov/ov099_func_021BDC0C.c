/*
 * function: func_021BDC0C
 * address: 0x021BDC0C
 * packet: pkt_ov099_021BDC0C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *);
int func_021BDC0C(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        *(u8 *)(p + 0x1353) = 0x4a;
        *(u32 *)(p + 0x1cc) = 0x8a;
    }
    return v;
}
