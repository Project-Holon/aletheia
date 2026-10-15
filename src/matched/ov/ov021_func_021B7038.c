/*
 * function: SCRCMD_POKEMON_FLD_PrepareGiftItemMessage
 * address:  0x021B7038
 * packet:   pkt_ov021_021B7038
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   WORDSET_Callback_EF40  0x0201EF40  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct WordSet;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);

int SCRCMD_POKEMON_FLD_PrepareGiftItemMessage(void *a, u32 *b, void *c)
{
    void *t;
    u16 x;

    t = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(c));
    x = *b;
    func_0201F02C(a, 0, t);
    WORDSET_Callback_EF40(a, 1, x);
    return 7;
}
