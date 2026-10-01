/*
 * function: func_021F6AA8
 * address:  0x021F6AA8
 * packet:   pkt_ov094_021F6AA8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Arms entry j of table i when its state is 1: sets the flag and stores the two values.
 */
typedef struct {
    int state;
    int armed;
    int a;
    int b;
} Entry;

typedef struct {
    char pad[8];
    Entry *tab[1];
} Obj;

void func_021F6AA8(Obj *p, int i, int j, int a, int b)
{
    if (p->tab[i][j].state == 1) {
        p->tab[i][j].armed = 1;
        p->tab[i][j].a = a;
        p->tab[i][j].b = b;
    }
}
