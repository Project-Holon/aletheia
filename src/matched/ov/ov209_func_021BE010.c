/*
 * function: ZUKAN_LIST_UpdateSpeciesActors
 * address: 0x021BE010
 * packet: pkt_ov209_021BE010
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_CreateActor 0x021C940C thumb ov212
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   ZUKAN_LIST_SetActorObjMode 0x021BD908 thumb ov209
 *   ZUKAN_LIST_SetActorVisible 0x021BD8D8 thumb ov209
 *   gZukanListSpeciesActor 0x021BE9A4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R { u16 f0; u16 f2; u32 f4; u32 f8; u32 fC; u32 f10; u16 f14; u16 f16; };
extern const struct R gZukanListSpeciesActor;
struct Obj;
extern struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap);
struct Actor;
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void ZUKAN_LIST_SetActorObjMode(char *, u32, u32);
extern void ZUKAN_LIST_SetActorVisible(char *, u32, u32);
void ZUKAN_LIST_UpdateSpeciesActors(char *p) {
    struct R a;
    struct R b;
    u32 *pb;
    u32 i;
    u32 j;
    u32 k;
    a = gZukanListSpeciesActor;
    b = gZukanListSpeciesActor;
    b.fC = *(u32 *)(p + 0xBF4);
    b.f10 = *(u32 *)(p + 0xC0C);
    for (i = 0; i < 16; i++) {
        b.f2 = i * 0x18 + 8;
        b.f8 = *(u32 *)(p + i * 4 + 0xB64);
        *(u32 *)(p + i * 4 + 0xA9C) = (u32)ZUKAN_CreateActor(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + i * 4 + 0xA9C)), 0);
    }
    b = a;
    b.fC = *(u32 *)(p + 0xBF8);
    b.f10 = *(u32 *)(p + 0xC10);
    for (j = 0; j < 16; j++) {
        b.f2 = j * 0x18 + 0x20;
        b.f8 = *(u32 *)(p + j * 4 + 0xBA4);
        b.f16 = 1;
        *(u32 *)(p + j * 4 + 0xADC) = (u32)ZUKAN_CreateActor(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + j * 4 + 0xADC)), 0);
        ZUKAN_LIST_SetActorObjMode(p, j + 0x1a, 1);
        pb = (u32 *)(p + 0xA70);
        *(u32 *)(p + j * 4 + 0xB1C) = (u32)ZUKAN_CreateActor(*pb, (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 0);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 2);
    }
    for (k = 0; k < 16; k++) ZUKAN_LIST_SetActorVisible(p, k + 0xa, 0);
    for (i = 0; i < 16; i++) {
        ZUKAN_LIST_SetActorVisible(p, i + 0x1a, 0);
        ZUKAN_LIST_SetActorVisible(p, i + 0x2a, 0);
    }
}
