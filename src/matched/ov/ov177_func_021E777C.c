/*
 * function: func_021E777C
 * address: 0x021E777C
 * packet: pkt_ov177_021E777C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { short x, y; } Pos;
typedef struct {
    char pad0[0x64];
    void *main;
    void *obj[5];
    char pad7c[0x88 - 0x7c];
    unsigned count;
    unsigned short base;
    unsigned short objBase[5];
} Work;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern int func_0209C2B0(int, int);
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_020061E4(unsigned se);
int func_021E777C(Work *p)
{
    int done;
    int shift;
    Pos pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        if (p->main != 0) {
            func_0204B454(p->main, (struct PtS *)&pos[1], done);
            p->base = pos[1].x;
        }
        for (i = 0; i < 5; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->objBase[i] = pos[1].x;
            }
        }
        func_020061E4(0x63B);
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    if (p->main != 0) {
        func_0204B454(p->main, (struct PtS *)&pos[0], 0);
        pos[0].x = p->base - func_0209C2B0(p->count << 8, 20);
        func_0204B404(p->main, (const struct Vec2 *)(&pos[0]), 0);
    }
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->objBase[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], (const struct Vec2 *)(&pos[0]), 0);
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
