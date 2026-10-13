/*
 * function: SCRCMD_PROC_GetMonParamIfListed
 * address: 0x0215C138
 * packet: pkt_ov010_0215C138
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: selector remains live in r2 and is SCRCMD_PROC_GetPartyMemberParam's third argument.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_PROC_GetPartyMemberParam 0x0215B4DC thumb ov010
 *   sScrcmdAllowedParamIds 0x02171182 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern int SCRCMD_PROC_GetPartyMemberParam(void *a0, void *a1, void *a2);
extern const u8 sScrcmdAllowedParamIds[];
int SCRCMD_PROC_GetMonParamIfListed(void *c, void *vm)
{
    u16 *dst;
    u32 arg;
    u32 sel;
    u32 i;
    dst = SCRIPT_WORK_ReadWorkPointer(c, vm);
    arg = SCRIPT_WORK_ReadWorkValue(c, vm);
    sel = SCRIPT_WORK_ReadWorkValue(c, vm);
    for (i = 0; i < 12; i++) {
        if (sel == sScrcmdAllowedParamIds[i]) {
            *dst = SCRCMD_PROC_GetPartyMemberParam(vm, (void *)arg, (void *)sel);
            return 0;
        }
    }
    *dst = 0;
    return 0;
}
