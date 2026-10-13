/*
 * function: SCRCMD_PROC_Ov037ReadEightVars
 * address:  0x0215CDF0
 * packet:   pkt_ov010_0215CDF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GIMMICK_INIT_RestoreGimmick38State  0x021F3768  thumb  ov037
 *   ov037_id       0x00000025  data
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void GIMMICK_INIT_RestoreGimmick38State(unsigned int a0, unsigned short **a1);
extern char ov037_id[];

int SCRCMD_PROC_Ov037ReadEightVars(void *a, void *b)
{
    unsigned short *v[8];
    void *h = SCRCMD_WORK_GetGameSystem(b);
    v[0] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[1] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[2] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[3] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[4] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[5] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[6] = SCRIPT_WORK_ReadWorkPointer(a, b);
    v[7] = SCRIPT_WORK_ReadWorkPointer(a, b);
    func_02034AC4((u32)ov037_id);
    GIMMICK_INIT_RestoreGimmick38State((unsigned int)h, v);
    func_02034A5C((u32)ov037_id);
    return 0;
}
