/*
 * function: func_021E65FC
 * address: 0x021E65FC
 * packet: pkt_ov177_021E65FC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { short x, y; } Pt;
typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    char pad1c4[0x200 - 0x1c4];
    unsigned count;      /* 0x200 */
    short baseX[22];     /* 0x204 */
    unsigned char bg;    /* 0x230 */
    char pad231[3];
    unsigned layer;      /* 0x234 */
} Work;
extern void func_0204B454(void *, Pt *, unsigned short);
extern void func_0204B404(void *, const Pt *, unsigned short);
extern void func_020061E4(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
extern void func_02041EE4(unsigned char, int, int);
int func_021E65FC(Work *w)
{
    int ret = 0;
    int level;
    int i;
    Pt cur, pos;
    if (w->count == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                func_0204B454(w->objs[i], &cur, w->layer);
                w->baseX[i] = cur.x;
            }
        }
        func_020061E4(0x63b);
    }
    level = func_0209C2B0(w->count << 8, 20);
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            func_0204B454(w->objs[i], &pos, w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->count << 8, 20);
            func_0204B404(w->objs[i], &pos, w->layer);
        }
    }
    if (w->count++ >= 20) {
        level = 0x100;
        w->count = 0;
        ret = 1;
    }
    func_02041EE4(w->bg + 1, 0, level);
    func_02041EE4(w->bg, 0, level);
    return ret;
}
