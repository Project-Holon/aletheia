/*
 * function: func_021BD4A8
 * address: 0x021BD4A8
 * packet: pkt_ov099_021BD4A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BBEB4 0x021BBEB4 thumb ov099
 */
typedef unsigned char u8;
extern int func_021BA928(char *, int);
extern int func_020362DC(void);
extern void func_021BA8EC(char *);
extern void func_021BCB70(int, int, int *);
extern void func_021BBEB4(char *, int, u8, int);
int func_021BD4A8(char *p, int ret)
{
    int out;
    if (func_021BA928(p, ret) == 0) return ret;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70(*(int *)(p + 0x1348), *(int *)(p + 0xc4), &out);
        func_021BBEB4(p, out, *(u8 *)(*(u8 **)(p + 0x248) + 0x48), 2);
        *(int *)(p + 0x1cc) = 0x6d;
    }
    return ret;
}
