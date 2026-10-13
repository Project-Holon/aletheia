/*
 * function: SCRCMD_PROC_GetMonPairedParams
 * address:  0x0215B558
 * packet:   pkt_ov010_0215B558
 * region:   ov010
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_PROC_GetPartyMember(void *a0, u32 a1, void **a2);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
int SCRCMD_PROC_GetMonPairedParams(int a0, int a1)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    u16 *q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    int obj;
    if (SCRCMD_PROC_GetPartyMember((void *)a1, SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1), (void **)(&obj)) == 1) {
        *p = POKE_TOOL_GetPartyValue((void *)obj, 0xAE, 0);
        *q = POKE_TOOL_GetPartyValue((void *)obj, 0xAF, 0);
    } else {
        *p = 0;
        *q = 0;
    }
    return 0;
}
