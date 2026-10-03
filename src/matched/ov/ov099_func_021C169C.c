/*
 * function: func_021C169C
 * address: 0x021C169C
 * packet: pkt_ov099_021C169C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero alignment bytes at 0x021C16EA.
 * lever: func_0203CEAC receives the live zero in r0.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98 0x0203CD98 arm
 */
extern int func_021BA928(char *, int);
extern void func_021BAAB8(char *, int, int);
struct Sub020097BCObj;
extern int func_0203CEAC(int a0);
extern int func_0203CD98(void);
extern void func_02009B3C(struct Sub020097BCObj *obj);
int func_021C169C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (*(int *)(p + 0x1e0) == 1) {
        *(int *)(p + 0x1e0) = 0;
        func_0203CEAC(0);
    }
    if (func_0203CD98() == 0) {
        func_02009B3C(*(void **)(p + 4));
        func_021BAAB8(p, 27, 1);
        *(int *)(p + 0x1cc) = 52;
        *(int *)(p + 0x1e0) = 30;
    }
    return ret;
}
