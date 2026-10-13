/*
 * function: SCRIPT_SYS_RunScriptNow
 * address:  0x02158A34
 * packet:   pkt_ov010_02158A34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Narrow parameter c matches SCRIPT_WORK_Create's stored halfword and restores
 * spill/call scheduling. The remaining two bytes are zero alignment padding.
 *
 * symbols:
 *   SCRIPT_WORK_Create  0x02158E7C  thumb
 *   SCRIPT_SYS_GetZoneId  0x021588D0  thumb
 *   SCRIPT_SYS_CreateVm  0x02158BFC  thumb
 *   VM_Control  0x02011298  thumb
 *   SCRIPT_SYS_DeleteVm  0x02158CB4  thumb
 *   SCRIPT_WORK_Delete  0x02158F18  thumb
 */

typedef unsigned short u16;
struct ScriptVm;
extern int *SCRIPT_WORK_Create(u16 a, int b, int c, int d, int e, int f);
extern int SCRIPT_SYS_GetZoneId(int);
extern int *SCRIPT_SYS_CreateVm(int a0, int a1, int a2, int a3, int a4);
extern int VM_Control(struct ScriptVm *vm);
extern int SCRIPT_SYS_DeleteVm(int a0);
extern int SCRIPT_WORK_Delete(int a0);

void SCRIPT_SYS_RunScriptNow(int a, int b, u16 c, int d)
{
    int t = 0;
    int r;
    if (b == 0) {
        t = (int)SCRIPT_WORK_Create(4, a, t, c, t, d);
        b = t;
    }
    r = (int)SCRIPT_SYS_CreateVm(4, b, SCRIPT_SYS_GetZoneId(a), c, d);
    while (VM_Control((struct ScriptVm *)r) == 1)
        ;
    SCRIPT_SYS_DeleteVm(r);
    if (t != 0)
        SCRIPT_WORK_Delete(t);
}
