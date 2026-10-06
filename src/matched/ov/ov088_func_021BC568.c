/*
 * function: func_021BC568
 * address:  0x021BC568
 * packet:   pkt_ov088_021BC568
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC8AC  0x021BC8AC  thumb  ov088
 *   func_020083EC  0x020083EC  thumb
 *   func_021BC84C  0x021BC84C  thumb  ov088
 *   func_021BC75C  0x021BC75C  thumb  ov088
 *   func_0200854C  0x0200854C  thumb
 *   func_02008450  0x02008450  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021BC944  0x021BC944  thumb  ov088
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021BC8AC(u8 *p);
struct Flags02008450;
extern void func_020083EC(unsigned short *p, unsigned int v);
extern void func_021BC84C(u8 *p);
extern void func_021BC75C(u8 *p);
struct Sub0200852CObj;
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008450(struct Flags02008450 *p, int on);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
typedef signed int     s32;
struct W;
extern s32 func_021BC944(struct W *w);

int func_021BC568(int a, int b, int *s, int *q)
{
    int r;

    switch (q[1]) {
    case 0:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_020083EC((void *)s[1], 0);
            else
                func_020083EC((void *)s[1], 1);
            func_021BC84C((u8 *)q);
            q[1] = 1;
            func_021BC75C((u8 *)q);
        }
        break;
    case 1:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_0200854C((struct Sub0200852CObj *)s[2], 0);
            else
                func_0200854C((struct Sub0200852CObj *)s[2], 1);
            func_021BC84C((u8 *)q);
            q[1] = 2;
            func_021BC75C((u8 *)q);
        }
        break;
    case 2:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_02008450((void *)s[1], 1);
            else
                func_02008450((void *)s[1], 0);
            func_0202208C(0, 0, 0, 0, 0xc, 1, 0x39);
            q[1] = 3;
        }
        break;
    case 3:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    func_021BC944((struct W *)q);
    return 0;
}
