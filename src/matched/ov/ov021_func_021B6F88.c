/*
 * function: SCRCMD_POKEMON_FLD_PrepareGiftMonMessage
 * address:  0x021B6F88
 * packet:   pkt_ov021_021B6F88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRCMD_POKEMON_FLD_CreateGiftMon  0x021B6EE0  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   WORDSET_Callback_EEC4  0x0201EEC4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned char  u8;
struct WordSet;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int SCRCMD_POKEMON_FLD_CreateGiftMon(u32 a, u32 b);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void WORDSET_Callback_EEC4(struct WordSet *p, u32 i, u32 v);
struct WordSet;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void func_0201EED4(struct WordSet *p, u32 i, void *mon);
extern u32 func_020307B0(void *p);

int SCRCMD_POKEMON_FLD_PrepareGiftMonMessage(int a, int b, int c)
{
    void *m;
    int h;
    int r;

    h = (int)GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData((void *)c));
    m = (void *)SCRCMD_POKEMON_FLD_CreateGiftMon(c, b);
    r = 5;
    func_0201F02C((struct WordSet *)a, 0, (void *)h);
    if (m == 0) {
        WORDSET_Callback_EEC4((struct WordSet *)a, 1, 0);
    } else {
        if (POKE_TOOL_GetPartyValue(m, 0x4c, 0) == 1)
            r = 0xb;
        else
            func_0201EED4((void *)a, 1, m);
        func_020307B0(m);
    }
    return r;
}
