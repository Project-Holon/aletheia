/*
 * function: SCRCMD_POKEMON_FLD_CheckMonTutorStatus
 * address:  0x021B6164
 * packet:   pkt_ov021_021B6164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   SCRCMD_PROC_CheckMonKnowsMove  0x0215B500  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SCRCMD_POKEMON_FLD_CheckTutorGroup  0x021B5FB8  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetTutorFriendship  0x021B5FB4  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetTutorMoveId  0x021B5F24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern int SCRCMD_PROC_CheckMonKnowsMove(int a0, int a1);
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern int SCRCMD_POKEMON_FLD_CheckTutorGroup(u32 a, int sel);
extern int SCRCMD_POKEMON_FLD_GetTutorFriendship(u32 a);
extern int SCRCMD_POKEMON_FLD_GetTutorMoveId(u32 a, int sel);

int SCRCMD_POKEMON_FLD_CheckMonTutorStatus(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;

    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *o = 1;
    if (SCRCMD_PROC_GetPartyMember((void *)b, y, (void **)(&rec)) == 0)
        return 0;
    if (SCRCMD_POKEMON_FLD_CheckTutorGroup(rec, x) == 0) {
        *o = 1;
    } else if (SCRCMD_PROC_CheckMonKnowsMove(rec, SCRCMD_POKEMON_FLD_GetTutorMoveId(rec, x)) == 1) {
        *o = 3;
    } else if (POKE_TOOL_GetPartyValue((void *)rec, 9, 0) < SCRCMD_POKEMON_FLD_GetTutorFriendship(x)) {
        *o = 2;
    } else {
        *o = 0;
    }
    return 0;
}
