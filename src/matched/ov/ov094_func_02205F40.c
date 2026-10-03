/*
 * function: func_02205F40
 * address:  0x02205F40
 * packet:   pkt_ov094_02205F40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct { void *h; int x; } E;
typedef struct { char pad[0x180]; E a[6]; } W;
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_02205F40(W *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (p->a[i].h != 0) {
            func_0204B3B4(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}
