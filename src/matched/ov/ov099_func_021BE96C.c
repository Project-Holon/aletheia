/*
 * function: func_021BE96C
 * address: 0x021BE96C
 * packet: pkt_ov099_021BE96C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021BE9C6.
 * symbols:
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned int u32;
extern u32 func_021BA858(char *p);
extern int func_0203CEAC(int a0);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BA8EC(char *);
int func_021BE96C(char *p, int v)
{
    int t;
    int zero;
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        func_0203CEAC(0);
        func_021C18C8(p, 1, 2);
        *(int *)(p + 0x1cc) = 4;
    } else {
        func_021C18C8(p, 1, 2);
        zero = 0;
        func_0203CEAC(0);
        *(int *)(p + 0x1d0) = zero;
        *(int *)(p + 0x1cc) = 0x1a;
    }
    func_021BA8EC(p);
    return v;
}
