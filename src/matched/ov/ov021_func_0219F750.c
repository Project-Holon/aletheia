/*
 * function: func_0219F750
 * address:  0x0219F750
 * packet:   pkt_ov021_0219F750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: func_02050080 (0x02050080), func_0205082C (0x0205082C) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_02050080(u32 *p) { return p[1]; }  (EXACT as arm9 leaf, verified)
 *   void func_0205082C(u8 *p, int i, u16 h): strh into the record at +0xE, then tail-calls func_020500A0 (bx ip, pool 0x020500A0); not compiled here
 *
 * symbols:
 *   func_0204F638  0x0204F638  arm
 *   func_02050080  0x02050080  arm
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Trip;
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern void func_0219FFBC(u32, u32 *);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern u32 func_0219FFD4(u32);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(void *p, int idx, u16 v);

void func_0219F750(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0219FFD4(a);
        if (((u8 *)p)[4] != v) {
            func_0205082C(h, *p, v);
            func_0205085C((void *)h, *p, 0);
            ((u8 *)p)[4] = v;
        }
        func_021A000C(a, h, *p, 0, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}
