/*
 * function: func_0218403C
 * address:  0x0218403C
 * packet:   pkt_ov020_0218403C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202E848  0x0202E848  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020140B4  0x020140B4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_0202E848(int a, u16 *b, u16 *c);
extern int func_02188C84(int a);
typedef unsigned int   u32;
extern u32 func_02013B38(u32 id);
extern int func_0201407C(int a, int b, int c);
extern int func_020140D8(int a);
extern u32 func_020140B4(u32 a);

void func_0218403C(u8 *p)
{
    u16 s[2];
    int r4;
    int r6;
    int flag;
    u16 hi;

    func_0202E848(*(int *)(p + 4), &s[1], &s[0]);
    r4 = func_02188C84(*(int *)(p + 8));
    r6 = func_0201407C(r4, func_02013B38(*(u16 *)(p + 0x14)), 0);
    flag = 0;
    if (func_020140D8(r6) != 0)
        flag = 1;
    func_020140B4(r6);
    hi = s[1];
    if (s[0] != hi && flag) {
        *(int *)(p + 0x44) = 1;
        *(u16 *)(p + 0x48) = hi;
        *(u16 *)(p + 0x4a) = s[0];
    }
}
