/*
 * function: func_021E8338
 * address: 0x021E8338
 * packet: pkt_ov177_021E8338
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { short x, y; } Pos;
typedef struct {
    char pad0[0x30];
    void *obj[14];
    char pad68[0xb0 - 0x68];
    unsigned count;
    short base[14];
} Work;
typedef unsigned int   u32;
extern u32 func_020407E8(u32 layer);
extern void func_0204B454(void *, Pos *, int);
extern void func_0204B404(void *, Pos *, int);
extern int func_0209C2B0(int, int);
extern void func_02041EE4(u32 index, u32 a, u32 b);
int func_021E8338(Work *p)
{
    int done;
    int shift;
    Pos pos[2];
    int i;
    if (func_020407E8(2) == 0) {
        return 1;
    }
    done = 0;
    if (p->count == 0) {
        for (i = done; i < 14; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], &pos[1], 0);
                p->base[i] = pos[1].x;
            }
        }
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    for (i = 0; i < 14; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], &pos[0], 0);
            pos[0].x = p->base[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], &pos[0], 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}
