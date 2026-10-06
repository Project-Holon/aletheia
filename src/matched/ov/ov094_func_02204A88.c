/*
 * function: func_02204A88
 * address:  0x02204A88
 * packet:   pkt_ov094_02204A88
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef short s16;

typedef struct Main {
    unsigned char pad00[0x210];
    void *o210;
    void *o214;
} Main;

typedef struct Ctx {
    Main *main;
} Ctx;

struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0220687C(char *p, void *q);

void func_02204A88(int a0, Ctx *c)
{
    s16 v[2];

    func_0204B454(c->main->o210, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404(c->main->o210, (const struct Vec2 *)v, 1);
    func_0204B454(c->main->o214, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404(c->main->o214, (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        func_0220687C((char *)c->main, (void *)a0);
    }
}
