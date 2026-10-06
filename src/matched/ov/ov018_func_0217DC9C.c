/*
 * function: func_0217DC9C
 * address:  0x0217DC9C
 * packet:   pkt_ov018_0217DC9C
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
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836EC  0x021836EC  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B6F4(struct Obj *o, unsigned int v, unsigned int flag);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern const Rect d_021836EC;

void func_0217DC9C(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836EC;
    for (i = 17; i <= 19; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 16), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}
