/*
 * function: func_0219FB5C
 * address:  0x0219FB5C
 * packet:   pkt_ov021_0219FB5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0205082C  0x0205082C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 *func_0216D6F0(u32);
extern void func_0216D910(u32);
extern u32 func_0219C9DC(void);
extern u32 func_0216D598(u32);
extern u32 func_0216D678(u32);
extern u32 func_0219FFD4(u32);
extern void func_02197CCC(u32, s32 *);
extern void func_0219FFBC(u32, s32 *);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, s32 *);
extern void func_0205082C(u32, u32, u32);
extern void func_021A000C(u32, u32, u32, u32, u32);

void func_0219FB5C(u32 a)
{
    s32 buf[3];
    u32 flag;
    u32 r;
    u32 x;
    u8 *q;
    u32 t;
    u32 y;
    u32 m;

    flag = 0;
    q = (u8 *)func_0216D6F0(a);
    if (*(u16 *)q == 0xFFFF)
        return;
    func_0216D910(a);
    r = func_0219C9DC();
    t = func_0216D598(a);
    x = func_0216D678(a);
    if (t == 0xd3 || t == 0xd5 || t == 0x79) {
        m = 0;
        if (x == q[5])
            goto tail;
        switch (x) {
        case 10:
            m = 1;
            break;
        case 11:
            m = 2;
            break;
        case 12:
            m = 3;
            break;
        }
        q[5] = x;
        func_0205082C(r, *(u16 *)q, m);
        flag = 1;
    } else if (t == 0xd4 || t == 0xd6) {
        y = func_0219FFD4(a);
        m = 0;
        if (x < 10) {
            if (y == q[4] && x == q[5])
                goto tail;
            if (y == 0)
                m = 0;
            else if (y == 1)
                m = 1;
            q[4] = y;
        } else {
            if (x == q[5])
                goto tail;
            switch (x) {
            case 10:
                m = 2;
                break;
            case 11:
                m = 3;
                break;
            }
        }
        q[5] = x;
        func_0205082C(r, *(u16 *)q, m);
        flag = 1;
    } else {
        if (x == q[5])
            goto tail;
        q[5] = x;
        func_0205082C(r, *(u16 *)q, flag);
        flag = 1;
    }
tail:
    func_021A000C(a, r, *(u16 *)q, flag, 1);
    func_02197CCC(a, buf);
    func_0219FFBC(a, buf);
    func_0204F638(func_02050080(r), *(u16 *)q, buf);
}
