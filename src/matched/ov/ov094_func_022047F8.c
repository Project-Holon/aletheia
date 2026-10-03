/*
 * function: func_022047F8
 * address:  0x022047F8
 * packet:   pkt_ov094_022047F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 */
typedef struct Main {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main;

typedef struct Ctx {
    Main *main;
    int h4;
    void *ent[6];
} Ctx;

extern Ctx *func_02030EE8(void *h);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B1CC(int h);

void func_022047F8(void *h)
{
    Ctx *c = func_02030EE8(h);
    int i;

    for (i = 0; i < 6; i++) {
        if (c->ent[i] != 0)
            func_0204B3B4(c->ent[i]);
    }
    func_0204B1CC(c->h4);
    c->main->st = c->main->st - 1;
}
