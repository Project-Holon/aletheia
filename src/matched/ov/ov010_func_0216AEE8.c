/*
 * function: SCRCMD_SYMBOL_GetTargetObjectKey
 * address: 0x0216AEE8
 * packet: pkt_ov010_0216AEE8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   SCRIPT_WORK_GetWorkValue 0x0215901C thumb ov010
 *   SCRCMD_SYMBOL_GetMmdl 0x0216AED0 thumb ov010
 *   INTRUDE_FIELD_GetMmdlParamPair 0x0217C274 thumb ov018
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u32 SCRIPT_WORK_GetWorkValue(void *, void *, u32);
extern void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id);
extern void INTRUDE_FIELD_GetMmdlParamPair(unsigned int *out, char *p);
void SCRCMD_SYMBOL_GetTargetObjectKey(int vm, int *out)
{
    void *ws;
    ws = SCRCMD_WORK_GetScriptWork((void *)vm);
    INTRUDE_FIELD_GetMmdlParamPair((unsigned int *)out, (char *)((int)SCRCMD_SYMBOL_GetMmdl((void *)vm, SCRIPT_WORK_GetWorkValue(ws, SCRCMD_WORK_GetGameData((void *)vm), 0x8011))));
}
