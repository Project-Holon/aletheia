/*
 * function: func_0219FD1C
 * address:  0x0219FD1C
 * packet:   pkt_ov021_0219FD1C
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
 *   func_0204F638  0x0204F638  arm
 *   func_02050080  0x02050080  arm
 *   func_0205082C  0x0205082C  arm
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
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
extern u16 func_0216D678(void *p);
extern void func_0205082C(u32, u32, u32);

void func_0219FD1C(u32 a)
{
    u32 flag;
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    flag = 0;
    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0216D678((void *)a);
        if (v != ((u8 *)p)[5] && v < 2) {
            ((u8 *)p)[5] = v;
            func_0205082C(h, *p, v);
            flag = 1;
        }
        func_021A000C(a, h, *p, flag, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}
