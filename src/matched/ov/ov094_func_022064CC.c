/*
 * function: func_022064CC
 * address:  0x022064CC
 * packet:   pkt_ov094_022064CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { void *h; int x; } Slot;
typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void *, Point *, int);

void func_022064CC(W *p, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    Point pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            func_0204B3DC(p->slots[i].h, *p->f274);
            func_0204B404(p->slots[i].h, &pos, 1);
        } else {
            func_0204B3DC(p->slots[i].h, 0);
        }
    }
}
