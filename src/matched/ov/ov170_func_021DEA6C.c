/*
 * function: func_021DEA6C
 * address: 0x021DEA6C
 * packet: pkt_ov170_021DEA6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   func_021ED164 0x021ED164 thumb ov170
 *   func_021ED198 0x021ED198 thumb ov170
 *   func_021ED14C 0x021ED14C thumb ov170
 *   func_021ED310 0x021ED310 thumb ov170
 */
typedef struct {
    unsigned short index;
    unsigned short pad;
    int value, x, y, dx, dy;
    unsigned dirX:1;
    unsigned dirY:1;
    unsigned count:30;
} Motion;
extern void func_021ED164(char *w, int i, int v);
extern void func_021ED198(char *w, int i, int v);
extern void func_021ED14C(char *w, short x, short y);
extern void func_021ED310(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021DEA6C(char *p, int a)
{
    Motion *m;
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                func_021ED164(WORK(p), m->index, m->value);
            else
                func_021ED198(WORK(p), m->index, m->value);
        }
        func_021ED310(WORK(p));
        return 0;
    }
    if (m->dirX == 0)
        m->x += m->dx;
    else
        m->x -= m->dx;
    if (m->dirY == 0)
        m->y += m->dy;
    else
        m->y -= m->dy;
    func_021ED14C(WORK(p), m->x >> 8, m->y >> 8);
    func_021ED310(WORK(p));
    m->count++;
    return 1;
}
