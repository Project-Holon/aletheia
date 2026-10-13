/*
 * function: SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage
 * address:  0x021B709C
 * packet:   pkt_ov021_021B709C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F184  0x0201F184  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef signed int     s32;
struct Big;
struct WordSet;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);

int SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage(void *a, u32 *b, void *c)
{
    void *t;
    void *r;
    u32 x;

    t = SCRCMD_WORK_GetGameData(c);
    func_0200BE48(GAME_DATA_GetSaveControl(t));
    r = GAME_DATA_GetMyStatus(t);
    x = *b;
    func_0201F02C(a, 0, r);
    func_0201F184(a, 1, x);
    return 9;
}
