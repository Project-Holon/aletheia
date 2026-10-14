/*
 * function: ZUKAN_DETAIL_FORM_CreateCurrentIcon
 * address:  0x021C57A4
 * packet:   pkt_ov208_021C57A4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry        0x021BC3C0  thumb
 *   ZUKAN_DETAIL_FORM_CreateIconActor  0x021C535C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Ent {
    u32 kind;
    u32 mode;
    u16 pad8;
    u8  forms;
    u8  padb;
    u16 species;
    u16 pade;
};

struct Ov208Menu {
    u32 owner;
    u8  pad4[0x124];
    u32 arc;
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    int cur;
    struct Ov208Ent ents[8];
    u8  pad1c8[0x386];
    u16 sel;
};

extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(int key);
extern u32 ZUKAN_DETAIL_FORM_CreateIconActor(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                               u32 form, u32 gender, u32 isEgg);

void ZUKAN_DETAIL_FORM_CreateCurrentIcon(u16 *heap, struct Ov208Menu *p, int key, u16 idx)
{
    u16 k = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);

    p->obj[p->cur] = ZUKAN_DETAIL_FORM_CreateIconActor(p->arc, &p->res[p->cur], p->j, p->k, p->owner, *heap, k,
                                         p->ents[idx].species, p->ents[idx].forms, 0);
}
