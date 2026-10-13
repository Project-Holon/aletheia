/*
 * function: SCRCMD_FillPartnerCandidates
 * address:  0x021CFC4C
 * packet:   pkt_ov021_021CFC4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   func_0200E878  0x0200E878  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   SCRCMD_CollectPartnersByLanguage  0x021CFC80  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct Sub02009470Obj;
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern int func_0200E878(u8 *p);
extern int SCRCMD_CollectPartnersByLanguage(u32 a, u8 *b, int c, void *d);

int SCRCMD_FillPartnerCandidates(void *a, int b, void *c)
{
    void *sys = GAMESYSTEM_GetGameData(a);
    u8 *sv = (u8 *)GAME_DATA_GetSaveSyncBlock((int)sys);

    if (b < 0xe9) {
        return SCRCMD_CollectPartnersByLanguage((u32)func_02009470(GAME_DATA_GetSaveControl(sys)), sv, b, c);
    }
    return func_0200E878(sv);
}
