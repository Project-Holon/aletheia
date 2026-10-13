/*
 * function: SCRCMD_POKEMON_FLD_GetMysteryEntryCount
 * address:  0x021B6A78
 * packet:   pkt_ov021_021B6A78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200A8AC  0x0200A8AC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef signed int     s32;
struct Big;
struct Rec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200A8A0(void *);
extern s32 func_0200A8AC(struct Rec *r);

int SCRCMD_POKEMON_FLD_GetMysteryEntryCount(void *a, void *b)
{
    void *t;
    u16 *p;

    t = SCRCMD_WORK_GetGameData(b);
    p = SCRIPT_WORK_ReadWorkPointer(a, b);
    *p = func_0200A8AC(func_0200A8A0(GAME_DATA_GetSaveControl(t)));
    return 0;
}
