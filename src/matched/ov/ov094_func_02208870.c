/*
 * function: func_02208870
 * address:  0x02208870
 * packet:   pkt_ov094_02208870
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AAB8     0x0220AAB8  data  ov094  a2
 *   func_022079C0  0x022079C0  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef struct {
    int f00;                /* 0x40 in the work area */
    char pad04[0x70 - 0x04];
    struct {
        u32 lo : 3;
        u32 b3 : 1;
        u32 mid : 16;
        u32 b20 : 1;
        u32 hi : 9;
        u32 b30 : 1;
        u32 b31 : 1;
    } flags;                /* 0xb0 */
    char pad74[0x80 - 0x74];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 hi : 11;
    } flags;                /* 0x440 */
} W;

extern const Pt d_0220AAB8;
extern void func_022079C0(W *w, int i, Pt *p);

void func_02208870(W *w, int sel)
{
    Pt b;
    Pt a = d_0220AAB8;
    int i;

    for (i = 0; i < 8; i++) {
        if (w->r[i].f00 != 0 && w->r[i].flags.b20) {
            b = a;
            w->r[i].flags.b20 = 0;
            func_022079C0(w, i, &b);
        }
    }
    if (sel != 8) {
        w->r[sel].flags.b20 = 1;
        w->flags.mid = 0;
    }
}
