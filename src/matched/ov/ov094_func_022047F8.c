/*
 * function: BTLV_INPUT_CursorActorTaskEnd
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
 *   TCBL_GetOwnedWork  0x02030EE8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
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

typedef unsigned int   u32;
struct Bank;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void BTLV_INPUT_CursorActorTaskEnd(void *h)
{
    Ctx *c = (Ctx *)TCBL_GetOwnedWork(h);
    int i;

    for (i = 0; i < 6; i++) {
        if (c->ent[i] != 0)
            CLACT_DeleteActor(c->ent[i]);
    }
    CLACT_DeleteUnit((struct Bank *)c->h4);
    c->main->st = c->main->st - 1;
}
