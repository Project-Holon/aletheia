/*
 * function: SCRIPT_SYS_SetCommandCheck
 * address: 0x02158E38
 * packet: pkt_ov010_02158E38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_02011328 0x02011328 thumb
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_SYS_CheckCommandPermit 0x02158DE8 thumb ov010
 */
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern int SCRIPT_SYS_CheckCommandPermit(int a, int b, int c, int idx);
extern void func_02011328(void *, int (*)(int, void *, void *, int), void *);
void SCRIPT_SYS_SetCommandCheck(void *a) {
    void *b = SCRCMD_WORK_GetGameSystem(func_02011324(a));
    func_02011328(a, (int (*)(int,  void *, void *, int))SCRIPT_SYS_CheckCommandPermit, b);
}
