/*
 * function: func_021C0628
 * address:  0x021C0628
 * packet:   pkt_ov021_021C0628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf of ov043 func_021F36C0: fills slot i of a table of
 * 0x1C-byte entries when it is in range and not yet in use.
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int used;
    int f18;
} Slot;

typedef struct {
    int n;
    Slot *e;
} SlotTable;

void func_021C0628(int i, int a, int b, int c, int d, int e, int f, SlotTable *t)
{
    if (i < t->n && t->e[i].used == 0) {
        t->e[i].f0 = a;
        t->e[i].f4 = b;
        t->e[i].f8 = c;
        t->e[i].fc = d;
        t->e[i].f10 = e;
        t->e[i].f18 = f;
        t->e[i].used = 1;
    }
}
