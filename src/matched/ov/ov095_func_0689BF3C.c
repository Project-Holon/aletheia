/*
 * function: BTL_SICK_OnAdded
 * address:  0x0689BF3C
 * packet:   pkt_ov095_0689BF3C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689BFD8   0x0689BFD8  thumb  ov095
 *   func_0689BFE8   0x0689BFE8  thumb  ov095
 *   BTL_SICK_StartYawnSleep   0x0689BFF8  thumb  ov095
 *   BTL_SICK_ApplyPerishFaint   0x0689C0A8  thumb  ov095
 *   BTL_SICK_OnHealBlockAdded   0x0689C1A4  thumb  ov095
 *   BTL_SICK_OnItemBlockAdded   0x0689C214  thumb  ov095
 *   BTL_SICK_BuildAddMessage   0x0689C464  thumb  ov095
 */

typedef struct Word { int v; } Word;
typedef struct Blk { int w[9]; } Blk;
typedef struct Rec {
    int f00;
    Blk blk;
} Rec;

extern int BTL_SICK_BuildAddMessage(int, Word, void *, int, Blk *);
extern Rec *func_0689BFD8(void *, int, int);
extern void func_0689BFE8(void *, Rec *);
extern void BTL_SICK_StartYawnSleep(void *, void *);
extern void BTL_SICK_ApplyPerishFaint(void *, void *);
extern void BTL_SICK_OnHealBlockAdded(void *, void *);
extern void BTL_SICK_OnItemBlockAdded(void *, void *);

void BTL_SICK_OnAdded(void *a, void *b, int c, int d, Word e)
{
    Blk buf;
    Rec *r;

    if (BTL_SICK_BuildAddMessage(d, e, b, 0, &buf) != 0) {
        r = func_0689BFD8(a, 4, c);
        r->blk = buf;
        func_0689BFE8(a, r);
    }
    switch (d) {
    case 14:
        BTL_SICK_StartYawnSleep(a, b);
        return;
    case 20:
        BTL_SICK_ApplyPerishFaint(a, b);
        return;
    case 19:
        BTL_SICK_OnHealBlockAdded(a, b);
        return;
    case 15:
        BTL_SICK_OnItemBlockAdded(a, b);
        return;
    }
}
