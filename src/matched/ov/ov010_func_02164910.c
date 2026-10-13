/*
 * function: FLD_FACEUP_ScrCmdStart
 * address:  0x02164910
 * packet:   pkt_ov010_02164910
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads three values off a stream, loads overlay 82 and calls into it.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb ov010
 *   func_02034AC4  0x02034AC4  arm
 *   FLD_FACEUP_Create  0x021F5260  thumb ov082
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *a);
extern void *SCRCMD_WORK_GetGameSystem(void *a);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void SCRIPT_WORK_SetCheckFlag(int a);
extern int func_02034AC4(int a);
extern void *FLD_FACEUP_Create(int a0, int a1, int a2, void *a3, int a4);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern u8 ov_id_52[];

int FLD_FACEUP_ScrCmdStart(void *s, void *q)
{
    void *x = SCRCMD_WORK_GetScriptWork(q);
    void *y = SCRCMD_WORK_GetGameSystem(q);
    u8 a = VM_GetU16(s);
    u8 b = VM_GetU16(s);
    u32 c = VM_GetU16(s);
    int r;
    SCRIPT_WORK_SetCheckFlag(7);
    func_02034AC4((int)ov_id_52);
    r = (int)FLD_FACEUP_Create(a, b, c, y, (int)q);
    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, (void *)r);
    return 1;
}
