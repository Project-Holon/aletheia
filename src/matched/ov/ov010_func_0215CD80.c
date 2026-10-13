/*
 * function: SCRCMD_PROC_Ov037SetValueA
 * address: 0x0215CD80
 * packet: pkt_ov010_0215CD80
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   GIMMICK_INIT_SetGimmick40Flag 0x021F36E8 thumb ov037
 *   ov037_id 0x00000025 data a1
 */
extern char ov037_id[];
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void GIMMICK_INIT_SetGimmick40Flag(void *, int);

int SCRCMD_PROC_Ov037SetValueA(void *a, void *b)
{
    void *p = SCRCMD_WORK_GetGameSystem(b);
    int v = SCRIPT_WORK_ReadWorkValue(a, b);
    func_02034AC4((int)ov037_id);
    GIMMICK_INIT_SetGimmick40Flag(p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}
