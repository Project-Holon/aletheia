/*
 * function: func_021F04EC
 * address:  0x021F04EC
 * packet:   pkt_ov031_021F04EC
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021F1048     0x021F1048  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(int, int);
extern const Rect d_021F1048;

void func_021F04EC(int *p)
{
    Rect r;
    int i;

    r = d_021F1048;
    for (i = 0; i <= 4; i++) {
        r.a = i * 0x30 + 0x20;
        r.c = i;
        p[6 + i] = (int)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    }
    r.c = 5;
    r.a = 0xF4;
    r.b = 0x9C;
    p[0xB] = (int)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    func_0204B3DC(p[0xB], 0);
}
