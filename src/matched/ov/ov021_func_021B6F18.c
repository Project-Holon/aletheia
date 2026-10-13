/*
 * function: SCRCMD_POKEMON_FLD_ReceiveGiftMon
 * address:  0x021B6F18
 * packet:   pkt_ov021_021B6F18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRCMD_POKEMON_FLD_CreateGiftMon  0x021B6EE0  thumb  ov021
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct BigObj;
struct Party;
struct PartyMon;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
struct Blk37;
extern int SCRCMD_POKEMON_FLD_CreateGiftMon(u32 a, u32 b);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);

void SCRCMD_POKEMON_FLD_ReceiveGiftMon(int a, int b, int c)
{
    void *l;
    void *m;

    l = GAME_DATA_GetMyParty((void *)b);
    m = (void *)SCRCMD_POKEMON_FLD_CreateGiftMon(a, c);
    if ((int)POKEPARTY_GetCount(l) < 6 && m != 0) {
        POKEPARTY_Add(l, m);
        func_0200CDE0(func_0200CA1C((void *)b), m);
        func_020307B0(m);
    }
}
