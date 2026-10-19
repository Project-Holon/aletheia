/*
 * function: SYMBOL_MAP_GetSelection
 * address:  0x02166434
 * packet:   pkt_ov010_02166434
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads two 4-bit values (bitfields at bits 6..9 and 10..13 of the word at +0x50 of
 * the record behind INTRUDE_COMM_GetPartnerSymbolPage) into the out parameters, or takes them
 * from the two ov010 accessors when INTRUDE_COMM_GetPartnerSlot answers 4.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   SYMBOL_MAP_GetSymbolIndex  0x021673C4  thumb  ov010
 *   SYMBOL_MAP_GetGroup  0x021673A8  thumb  ov010
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPartnerSymbolPage  0x02176880  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBlock(void *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *a, void *b);
extern u8 SYMBOL_MAP_GetSymbolIndex(u8 *p);
extern u8 SYMBOL_MAP_GetGroup(u8 *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
struct Rec {
    u8 pad[0x50];
    u32 : 6;
    u32 a : 4;
    u32 b : 4;
};

extern u8 *INTRUDE_COMM_GetPartnerSymbolPage(u8 *p);

int SYMBOL_MAP_GetSelection(void *a, u32 *out0, u32 *out1)
{
    void *t;
    u8 *sav;
    void *r;
    struct Rec *rec;

    t = GAMESYSTEM_GetGameData(a);
    sav = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(t));
    r = (void *)GAMESYSTEM_GetGameComm(a);
    if (INTRUDE_COMM_GetPartnerSlot(r, t) == 4) {
        *out0 = SYMBOL_MAP_GetSymbolIndex(sav);
        *out1 = SYMBOL_MAP_GetGroup(sav);
        return 1;
    }
    r = (void *)INTRUDE_COMM_GetWorkIfRunning((int)r);
    if (r == 0) {
        *out0 = 0;
        *out1 = 0;
        return 0;
    }
    rec = (struct Rec *)INTRUDE_COMM_GetPartnerSymbolPage(r);
    *out0 = rec->a;
    *out1 = rec->b;
    return 1;
}
