/*
 * function: func_0217DAA8
 * address:  0x0217DAA8
 * packet:   pkt_ov018_0217DAA8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836CC     0x021836CC  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;
typedef struct { u8 pad[4]; u8 a, b; } Ent;

extern int func_0204B294(int, int, int, int, Rect *, int, int);
extern void func_0204B3DC(int, int);
extern void func_0204B92C(int, int);
extern const Rect d_021836CC;
extern const Ent d_02176AA0[];

void func_0217DAA8(int *p)
{
    Rect r;
    int i;

    r = d_021836CC;
    for (i = 0; i <= 7; i++) {
        r.a = d_02176AA0[i].a;
        r.b = d_02176AA0[i].b;
        p[0x5c / 4 + i] = func_0204B294(p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B3DC(p[0x5c / 4 + i], 0);
        func_0204B92C(p[0x5c / 4 + i], 1);
    }
    r.c = 8;
    r.a = 0x80;
    r.b = 0x5c;
    p[0x7c / 4] = func_0204B294(p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B3DC(p[0x7c / 4], 0);
    func_0204B92C(p[0x7c / 4], 1);
}
