/*
 * function: func_021A87A8
 * address:  0x021A87A8
 * packet:   pkt_ov021_021A87A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B09C  0x0204B09C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    int pad0;
    int f0;
    int pad8[3];
    int f10;
    int pad18;
} E;

typedef struct {
    char pad0[0x2c];
    int f2c;
    char pad30[0x8];
    E e[7];
    s16 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
    int f124;
} S;

extern void func_0204B09C(int a, int b, P *c);
extern void func_0204B454(int h, P *out, int k);
extern void func_0204B3DC(int h, int v);

void func_021A87A8(S *s)
{
    P v;
    P p4;
    P p0;
    u8 i;

    v.x = 0;
    v.y = -s->hfc;
    func_0204B09C(s->f120, 0, &v);
    for (i = 0; i < 7; i++) {
        if (s->e[i].f10 != 0 && s->e[i].f0 != 7) {
            func_0204B454(s->e[i].f10, &p4, 0);
            if (p4.y < 0xd0) {
                func_0204B3DC(s->e[i].f10, 1);
            } else {
                func_0204B3DC(s->e[i].f10, 0);
            }
        }
    }
    func_0204B454(s->f124, &p0, 0);
    if (s->f2c != 0 && p0.y < 0xd6) {
        func_0204B3DC(s->f124, 1);
    } else {
        func_0204B3DC(s->f124, 0);
    }
}
