/*
 * function: SCRCMD_POKEMON_FLD_GetMonTypeForTm
 * address:  0x021B62C8
 * packet:   pkt_ov021_021B62C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb ov010
 *   POKE_TOOL_CheckTmCompat  0x020188AC  thumb
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 FILE_UTIL_GetId(u32 id);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_CheckTmCompat(void *p, int v);
extern u32 POKE_TOOL_GetHiddenPowerType(void *p);

int SCRCMD_POKEMON_FLD_GetMonTypeForTm(void *a, void *b)
{
    u16 *p;
    u32 v;
    u32 w;
    u32 x;
    u16 r;

    p = SCRIPT_WORK_ReadWorkPointer(a, b);
    v = SCRIPT_WORK_ReadWorkValue(a, b);
    w = FILE_UTIL_GetId(0x151);
    if (SCRCMD_PROC_GetPartyMember(b, v, (void **)(&x)) == 0) {
        *p = 0xFFFF;
    } else if (POKE_TOOL_CheckTmCompat((void *)x, w) == 0) {
        *p = 0xFFFF;
    } else {
        *p = POKE_TOOL_GetHiddenPowerType((void *)x);
    }
    return 0;
}
