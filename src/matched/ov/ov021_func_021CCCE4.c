/*
 * function: PARTY_SELECT_LIST_CreateStatusIcons
 * address:  0x021CCCE4
 * packet:   pkt_ov021_021CCCE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the party icon sprites for both sides: one per non-empty slot, at x = 0x20 + 0x28 * slot, flagged for the alternate form, into the +0x4C and +0x64 handle arrays.
 *
 * The alternate-form flag is an if/else storing 1 or 0 into pos.alt, not a
 * ternary: the ternary version (114 bytes out) left the second party count in
 * a register and rematerialised &pos; the if/else spills both counts and
 * keeps &pos hoisted in each loop, as the original does.
 *
 * symbols:
 *   d_021DB40C  0x021DB40C  data
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
    u16 alt;
    u16 h6;
} IconPos;

typedef struct {
    u8 pad0[4];
    void *party[2];     /* 0x04 */
    u16 hC;             /* 0x0C */
    u8 padE[0x18 - 0xe];
    void *sys;          /* 0x18 */
    u8 pad1C[0x4c - 0x1c];
    void *icon[2][6];   /* 0x4C */
    u8 pad7C[0x98 - 0x7c];
    u16 h98;
    u16 h9A;
    u16 h9C;
} Work;

extern const IconPos d_021DB40C;
struct Obj;
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 arg);
extern u32 FILE_UTIL_IsMailItem(u16 v);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void PARTY_SELECT_LIST_CreateStatusIcons(Work *w)
{
    IconPos pos = d_021DB40C;
    int n0;
    int n1;
    int i;
    u32 species;

    n0 = POKEPARTY_GetCount(w->party[0]);
    for (i = 0; i < n0; i++) {
        species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(w->party[0], i), 6, 0);
        if (species != 0) {
            if (FILE_UTIL_IsMailItem(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            w->icon[0][i] = CLACT_CreateActor(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
            CLACT_SetActorDrawEnable(w->icon[0][i], 0);
        }
    }
    if (w->party[1] != 0) {
        n1 = POKEPARTY_GetCount(w->party[1]);
        for (i = 0; i < n1; i++) {
            species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(w->party[1], i), 6, 0);
            if (species != 0) {
                if (FILE_UTIL_IsMailItem(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
                pos.x = i * 0x28 + 0x20;
                w->icon[1][i] = CLACT_CreateActor(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
                CLACT_SetActorDrawEnable(w->icon[1][i], 0);
            }
        }
    }
}
