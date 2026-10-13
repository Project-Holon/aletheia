/*
 * function: SCRCMD_PROC_GetMonSpeciesOrEgg
 * address: 0x0215B7E8
 * packet: pkt_ov010_0215B7E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_PROC_GetPartyMemberParam 0x0215B4DC thumb ov010
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *,void *);
extern int SCRCMD_PROC_GetPartyMemberParam(void *a0, void *a1, void *a2);
int SCRCMD_PROC_GetMonSpeciesOrEgg(int a,int b)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a,(void *)b);
    int k = SCRIPT_WORK_ReadWorkValue((void *)a,(void *)b);
    if (SCRCMD_PROC_GetPartyMemberParam((void *)b,(void *)k,(void *)0x4C) != 0) *out = 0x28A; else *out = SCRCMD_PROC_GetPartyMemberParam((void *)b,(void *)k,(void *)5);
    return 0;
}
