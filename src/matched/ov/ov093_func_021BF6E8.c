/*
 * function: func_021BF6E8
 * address:  0x021BF6E8
 * packet:   pkt_ov093_021BF6E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021BF78C  0x021BF78C  thumb  ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../include/Obj13316.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
extern u32 func_021C8828(u8 *p);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *p);
extern int func_021C88E4(u8 *p);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

int func_021BF6E8(u8 *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1)
{
    u32 s;
    int flag;
    int r;
    s = func_021CC8D8(p + 0x1d74, 4784);
    flag = 0;
    r = func_021BF78C(p, b, s1, c2, d, s0, p + 0x1ae4, &flag);
    if (r != 0) {
        if (func_021C8828(p + 0x1ae4) != 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1ae4));
            func_021C8810(p + 0x1ae4);
        } else if (func_021C88E4(p) == 0 && flag == 0) {
            func_021CD64C(((struct Obj13316 *)p)->fC, 0x5b, 0xd2, func_021D5440(d), 0xffff0000);
        }
    }
    func_021CC95C((u32 *)(p + 0x1d74), s, 4810);
    return r;
}
