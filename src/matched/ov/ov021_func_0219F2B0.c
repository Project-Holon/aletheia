/*
 * function: func_0219F2B0
 * address:  0x0219F2B0
 * packet:   pkt_ov021_0219F2B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
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
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_0219FEB0  0x0219FEB0  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern u16 *func_0216D6F0(u32);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u32);
extern void func_02197CCC(u32, s32 *);
extern void func_0219FFBC(u32, s32 *);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, s32 *);
extern u16 func_0216D678(void *p);
extern u32 func_0219FFD4(u32);
extern void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(void *p, int idx, u16 v);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern u32 func_0216D598(u32);
extern u8 *func_0216E3C4(u32);

void func_0219F2B0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 f;
    u32 x;
    u32 k;
    u32 w;
    flag = 0;
    f = 0;
    q = (u8 *)func_0216D6F0(a);
    if (*(u16 *)q != 0xFFFF) {
        r = func_0219C9DC(func_0216D910(a));
        x = func_0219FFD4(a);
        if (func_0216D598(a) == 0xCC) {
            f = 1;
        }
        k = func_0216E3C4(a)[3];
        if (k == 0xF) {
            k = 4;
        } else if (k == 5) {
            k = 8;
        } else {
            k = 0x10;
        }
        w = (u16)(k + x);
        if (q[4] != x) {
            q[4] = x;
            func_0205082C(r, *(u16 *)q, w);
            flag = 1;
        }
        func_021A000C(a, r, *(u16 *)q, flag, f);
    func_02197CCC(a, buf);
    func_0219FFBC(a, buf);
    r = func_02050080(r);
    func_0204F638(r, *(u16 *)q, buf);
    }
}
