/*
 * function: SCRCMD_POKEMON_FLD_GetMonIvStat
 * address:  0x021B5CE8
 * packet:   pkt_ov021_021B5CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

int SCRCMD_POKEMON_FLD_GetMonIvStat(void *a, void *b)
{
    u16 v[6];
    void *mon;
    u32 slot;
    u32 which;
    u16 *out;
    u16 sum;
    u16 max;
    u32 i;

    slot = SCRIPT_WORK_ReadWorkValue(a, b);
    which = SCRIPT_WORK_ReadWorkValue(a, b);
    out = SCRIPT_WORK_ReadWorkPointer(a, b);
    if (SCRCMD_PROC_GetPartyMember(b, slot, &mon) == 0) {
        *out = 0;
        return 0;
    }
    sum = 0;
    v[0] = POKE_TOOL_GetPartyValue(mon, 0x46, 0);
    v[1] = POKE_TOOL_GetPartyValue(mon, 0x47, 0);
    v[2] = POKE_TOOL_GetPartyValue(mon, 0x48, 0);
    v[3] = POKE_TOOL_GetPartyValue(mon, 0x49, 0);
    v[4] = POKE_TOOL_GetPartyValue(mon, 0x4a, 0);
    v[5] = POKE_TOOL_GetPartyValue(mon, 0x4b, 0);
    max = 0;
    for (i = 0; i < 6; i++) {
        sum += v[i];
        if (max < v[i]) {
            max = v[i];
        }
    }
    switch (which) {
    case 0:
        *out = sum;
        break;
    case 1:
        *out = max;
        break;
    case 2:
        *out = v[0];
        break;
    case 3:
        *out = v[1];
        break;
    case 4:
        *out = v[2];
        break;
    case 5:
        *out = v[3];
        break;
    case 6:
        *out = v[4];
        break;
    case 7:
        *out = v[5];
        break;
    }
    return 0;
}
