/*
 * function: GPOWER_EVENT_RestoreParty
 * address:  0x021F5488
 * packet:   pkt_ov083_021F5488
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   GPOWER_UseHpRestore  0x0201104C  thumb
 *   GPOWER_UsePpRestore  0x020110CC  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BigObj;
struct Ctx;
struct WordSet;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32   func_0201AB08(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern u32   GPOWER_UseHpRestore(void *p);
extern u32   GPOWER_UsePpRestore(void *p);

void GPOWER_EVENT_RestoreParty(void *a0, void *a1, int a2)
{
    void *h = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(a0));
    u8 i;

    i = func_0201AB08(h);
    func_0201EEF4(a1, 1, func_0201AB28(h, i));
    switch (a2) {
    case 5:
        GPOWER_UseHpRestore(h);
        break;
    case 6:
        GPOWER_UsePpRestore(h);
        break;
    }
}
