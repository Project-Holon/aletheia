/*
 * function: SCRCMD_POKEMON_FLD_GetMonTutorMove
 * address:  0x021B6124
 * packet:   pkt_ov021_021B6124
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   SCRCMD_POKEMON_FLD_GetTutorMoveId  0x021B5F24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern int SCRCMD_POKEMON_FLD_GetTutorMoveId(u32 a, int sel);

int SCRCMD_POKEMON_FLD_GetMonTutorMove(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;
    int v;

    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    if (SCRCMD_PROC_GetPartyMember((void *)b, y, (void **)(&rec)) == 1)
        v = SCRCMD_POKEMON_FLD_GetTutorMoveId(rec, x);
    else
        v = 0;
    *o = v;
    return 0;
}
