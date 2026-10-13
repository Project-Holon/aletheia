/*
 * function: SCRCMD_PROC_GetMonMove
 * address:  0x0215BCE8
 * packet:   pkt_ov010_0215BCE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);

int SCRCMD_PROC_GetMonMove(void *a0, void *a1)
{
    u16 *out;
    void *k;
    char *p;
    void *v;

    out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    k = (char *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    p = (char *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    if (SCRCMD_PROC_GetPartyMember(a1, (u32)k, &v) == 1) {
        *out = POKE_TOOL_GetPartyValue(v, (u32)(p + 0x36), 0);
    } else {
        *out = 0;
    }
    return 0;
}
