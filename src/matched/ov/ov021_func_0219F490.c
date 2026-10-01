/*
 * function: func_0219F490
 * address:  0x0219F490
 * packet:   pkt_ov021_0219F490
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
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_021A000C  0x021A000C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern u16 *func_0216D6F0(u32);
extern void func_0216D910(u32);
extern u32 func_0219C9DC(void);
extern void func_02197CCC(u32, s32 *);
extern void func_0219FFBC(u32, s32 *);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, s32 *);
extern u32 func_0216D678(u32);
extern u32 func_0219FFD4(u32);
extern void func_0219FEB0(u16 *, u32, u32, u32);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(u32, u32, u32);
extern void func_021A000C(u32, u32, u32, u32, u32);

void func_0219F490(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 x;
    u32 r;
    q = (u8 *)func_0216D6F0(a);
    if (*(u16 *)q != 0xFFFF) {
        func_0216D910(a);
        r = func_0219C9DC();
        x = func_0216D678(a);
        if (q[5] >= 2) {
            q[5] = 0;
            func_0205082C(r, *(u16 *)q, q[5]);
            func_0205085C(r, *(u16 *)q, 0);
        }
        if (x < 2 && q[5] != x) {
            q[5] = x;
            func_0205082C(r, *(u16 *)q, q[5]);
            func_0205085C(r, *(u16 *)q, 0);
        }
        func_021A000C(a, r, *(u16 *)q, 0, 0);
    func_02197CCC(a, buf);
    func_0219FFBC(a, buf);
    r = func_02050080(r);
    func_0204F638(r, *(u16 *)q, buf);
    }
}
