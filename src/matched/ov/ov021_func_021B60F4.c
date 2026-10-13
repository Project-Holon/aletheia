/*
 * function: SCRCMD_POKEMON_FLD_GetTutorAvailability
 * address:  0x021B60F4
 * packet:   pkt_ov021_021B60F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   SCRCMD_POKEMON_FLD_FindTutorCandidates  0x021B6048  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRCMD_POKEMON_FLD_FindTutorCandidates(u32 a, u32 b, u32 key, u8 *mask, u32 flag);

int SCRCMD_POKEMON_FLD_GetTutorAvailability(void *a, void *b)
{
    u32 v;
    u16 *p;
    u32 tmp;

    v = SCRIPT_WORK_ReadWorkValue(a, b);
    p = SCRIPT_WORK_ReadWorkPointer(a, b);
    *p = SCRCMD_POKEMON_FLD_FindTutorCandidates((u32)a, (u32)b, v, (u8 *)(&tmp), 1);
    return 0;
}
