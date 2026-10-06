/*
 * function: func_021E066C
 * address: 0x021E066C
 * packet: pkt_ov170_021E066C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021ECC1C 0x021ECC1C thumb ov170
 */
typedef struct {
    unsigned char x, y, dx, dy;
    unsigned directionX:1;
    unsigned directionY:1;
    unsigned count:30;
} Motion;
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC0B0(char *w, int i, short *x, short *y, unsigned short z);
extern void func_021ECC1C(unsigned char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E066C(char *p)
{
    Motion *m;
    short xy[2];
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 0) {
        func_021EC08C(WORK(p), 4, m->x, m->y, 0);
        func_021ECC1C((unsigned char *)p);
        return 0;
    }
    m->count--;
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    if (m->directionX == 0)
        xy[1] += m->dx;
    else
        xy[1] -= m->dx;
    if (m->directionY == 0)
        xy[0] += m->dy;
    else
        xy[0] -= m->dy;
    func_021EC08C(WORK(p), 4, xy[1], xy[0], 0);
    func_021ECC1C((unsigned char *)p);
    return 1;
}
