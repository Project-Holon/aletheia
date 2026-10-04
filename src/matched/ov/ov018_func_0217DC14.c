/*
 * function: func_0217DC14
 * address:  0x0217DC14
 * packet:   pkt_ov018_0217DC14
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836D4  0x021836D4  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

extern int func_020120F4(int);
extern u8 *func_02012944(int);
extern int func_02008550(u8 *);
extern int func_02012B58(int);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(int, int);
extern void func_0204B6F4(int, int, int);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern const Rect d_021836D4;

void func_0217DC14(int *p)
{
    Rect r;
    int h;

    r = d_021836D4;
    h = func_020120F4(p[0]);
    if (func_02008550(func_02012944(h)) == 1) {
        r.c = 3;
    }
    p[0x98 / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B6F4(p[0x98 / 4], (u8)(func_02012B58(h) + 1), 1);
    func_0204B3DC(p[0x98 / 4], 0);
    func_0204B92C((struct Obj *)p[0x98 / 4], 1);
}
