/*
 * function: func_0219F3F0
 * address:  0x0219F3F0
 * packet:   pkt_ov021_0219F3F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked only by unlabelled arm9 leaf(s) (Ilias's), each verified EXACT from a scratch
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
 *   func_0216D678 (ov010, unlabelled thumb leaf, no ov010 shard yet; asm: ldrh r0,[r0,#0x2a]; bx lr):
 *   u16 func_0216D678(u8 *p) { return *(u16 *)(p + 0x54); }
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

void func_0219F3F0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 r;
    u32 x;
    u32 y;
    q = (u8 *)func_0216D6F0(a);
    if (*(u16 *)q != 0xFFFF) {
        func_0216D910(a);
        r = func_0219C9DC();
        x = func_0216D678(a);
        if (x >= 10) {
            y = func_0219FFD4(a);
            if (x != q[5]) {
                q[4] = y;
                q[5] = x;
                q[6] = 0;
                func_0205082C(r, *(u16 *)q, (u16)(x + 0x1e));
            }
            func_021A000C(a, r, *(u16 *)q, 1, 0);
        } else {
            func_0219FEB0((u16 *)(q + 4), a, r, *(u16 *)q);
        }
    func_02197CCC(a, buf);
    func_0219FFBC(a, buf);
    r = func_02050080(r);
    func_0204F638(r, *(u16 *)q, buf);
    }
}
