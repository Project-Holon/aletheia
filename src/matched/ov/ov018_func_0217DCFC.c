/*
 * function: func_0217DCFC
 * address:  0x0217DCFC
 * packet:   pkt_ov018_0217DCFC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217F1E8  0x0217F1E8  thumb  ov018
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021836C4  0x021836C4  data  a4
 */

typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

typedef unsigned char  u8;
extern int func_0217F1E8(u8 *p);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern const Rect d_021836C4;

void func_0217DCFC(int *p, void *a1)
{
    Rect r;
    int h;

    r = d_021836C4;
    h = func_0217F1E8((u8 *)p);
    p[0xac / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[5], p[2], p[6], &r, 0, 0x70);
    func_0204B3DC((struct Obj *)p[0xac / 4], h);
}
