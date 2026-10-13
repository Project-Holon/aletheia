/*
 * function: SCRCMD_FLD_BATTLE_CheckPartyRegulation
 * address:  0x021B574C
 * packet:   pkt_ov021_021B574C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * POKE_REGULATION_Load is filed as src/matched/arm9/POKE_REGULATION_Load.c (witness).
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   SCRCMD_FLD_BATTLE_CreatePartyCheckTask  0x021B58B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *POKE_REGULATION_Load(int a, int b);
extern void *SCRCMD_FLD_BATTLE_CreatePartyCheckTask(void *sys, int flag, void *rules, u16 *out, int k);
extern u32 func_020307B0(void *p);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_FLD_BATTLE_CheckPartyRegulation(int a0, int a1)
{
    void *s8 = SCRCMD_WORK_GetScriptWork((void *)a1);
    void *s4 = SCRCMD_WORK_GetGameSystem((void *)a1);
    int r4 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    u16 *r7 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    int r6 = SCRCMD_WORK_GetHeapId((void *)a1);
    void *r5 = POKE_REGULATION_Load(r4, r6);
    int r1 = 1;
    u16 d = r4 + 0xffec;
    void *res;

    if (d > 2) {
        r1 = 0;
    }
    res = SCRCMD_FLD_BATTLE_CreatePartyCheckTask((void *)s4, r1, r5, r7, r6);
    func_020307B0(r5);
    if (res == 0) {
        return 0;
    }
    SCRIPT_SYS_CallEvent(s8, res);
    return 1;
}
