/*
 * function: func_021F39E4
 * address:  0x021F39E4
 * packet:   pkt_ov048_021F39E4
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 */

typedef unsigned short u16;

typedef struct Ent {
    int pad[2];
    int x;
    int y;
    int z;
    int mode;
} Ent;

extern int func_02188D2C(int a);
extern int *func_021BE480(int a, int b, int c);
extern void func_020520FC(u16 a, u16 b, u16 c, int *d);

void func_021F39E4(int *p)
{
    int *r3;
    Ent *e;
    int r4;

    r4 = 0;
    r3 = func_021BE480(func_02188D2C(p[1]), 1, 0);
    e = (Ent *)p[7];
    r3[0] = e->x << 12;
    r3[1] = e->y << 12;
    r3[2] = e->z << 12;
    switch (e->mode) {
    case 1:
        r4 = 0;
        break;
    case 3:
        r4 = 90;
        break;
    case 0:
        r4 = 180;
        break;
    case 2:
        r4 = 270;
        break;
    default:
        r4 = 0;
        break;
    }
    func_020520FC(0, r4 * 0xb6, 0, r3 + 6);
}
