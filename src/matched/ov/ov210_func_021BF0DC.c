/*
 * function: ZKNSEARCH_MAIN_CreateActors
 * address:  0x021BF0DC
 * packet:   pkt_ov210_021BF0DC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   ZUKAN_CreateActor 0x021C940C thumb ov212
 *   ZKNSEARCH_MAIN_SetActorAnimAuto 0x021BEDB8 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorObjMode 0x021BEE14 thumb ov210
 *   data_021C09AC 0x021C09AC data
 *   data_021C0978 0x021C0978 data
 *   data_021C0960 0x021C0960 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Tpl021BF0DC {
    int f0;
    u16 id;
    u16 f6;
    int a;
    int b;
    int c;
    u16 f14;
    u16 f16;
};

struct Obj021BF0DC {
    void **sys;
    u8 pad04[0x20];
    void *set;
    void *objs[57];
    int a[6];
    int b[6];
    int c[4];
};

struct Actor;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
struct Obj;
extern struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorObjMode(char *p, int idx, int flag);
extern const struct Tpl021BF0DC data_021C09AC[15];
extern const struct Tpl021BF0DC data_021C0978;
extern const struct Tpl021BF0DC data_021C0960;

void ZKNSEARCH_MAIN_CreateActors(struct Obj021BF0DC *p)
{
    u32 i;
    struct Tpl021BF0DC t0;
    struct Tpl021BF0DC t;
    struct Tpl021BF0DC ta;
    struct Tpl021BF0DC tb;

    p->set = CLACT_CreateUnit(0x39, 0, 0x7B);
    for (i = 0; i < 0x39; i++)
        p->objs[i] = 0;

    for (i = 0; i <= 14; i++) {
        t0 = data_021C09AC[i];
        t0.a = p->a[t0.a];
        t0.b = p->b[t0.b];
        t0.c = p->c[t0.c];
        p->objs[i] = ZUKAN_CreateActor((u32)p->set, (const u8 *)(&t0), 0x7B);
    }

    if (GAME_DATA_CheckSaveFlag((int)(*p->sys), 0x10) == 1)
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 4, 7);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 5, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 6, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 1, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 7, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 8, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 10, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 11, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 12, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 13, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 14, 0);
    CLACT_SetActorObjMode(p->objs[13], 2);
    CLACT_SetActorObjMode(p->objs[14], 2);
    ZKNSEARCH_MAIN_SetActorObjMode((char *)p, 11, 1);
    ZKNSEARCH_MAIN_SetActorObjMode((char *)p, 12, 1);

    ta = data_021C0978;
    tb = data_021C0960;
    for (i = 0; i < 14; i++) {
        t = ta;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[15 + i] = ZUKAN_CreateActor((u32)p->set, (const u8 *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 15, 0);

        t = tb;
        t.a = p->a[t.a];
        t.b = p->b[t.b];
        t.c = p->c[t.c];
        t.id = i;
        p->objs[29 + i] = ZUKAN_CreateActor((u32)p->set, (const u8 *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 29, 0);
        ZKNSEARCH_MAIN_SetActorObjMode((char *)p, (int)i + 29, 1);
        p->objs[43 + i] = ZUKAN_CreateActor((u32)p->set, (const u8 *)(&t), 0x7B);
        ZKNSEARCH_MAIN_SetActorVisible((int)p, i + 43, 0);
        CLACT_SetActorObjMode(p->objs[43 + i], 2);
    }
}
