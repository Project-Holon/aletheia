/*
 * function: SCRIPT_COMMAND_TaskRotate
 * address:  0x021FBA14
 * packet:   pkt_ov132_021FBA14
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the bl to 0x021F8068 named an unlabelled leaf in the co-resident
 *           ov112 (ov112 0x021F36C0..0x021F8480 abuts ov132 0x021F8480..);
 *           it was filed EXACT as src/matched/ov112_func_021F8068.c, so the
 *           site now attests as `matched` and every concrete byte reproduces.
 *           EXACT* only because the inferred extent runs into an unlabelled
 *           follower in ov132; there is no byte difference.
 *
 * symbols:
 *   STA_ACTING_GetActorSystem  0x021F9DA0  thumb  ov132
 *   STA_ACT_SCRIPT_StepTaskInt  0x021FAE1C  thumb  ov132
 *   func_0209C0A4  0x0209C0A4  arm
 *   STA_ACT_LIGHT_ElemOpC  0x021F8068  thumb  ov112
 *   STA_ACT_SCRIPT_RemoveTask  0x021FADF8  thumb  ov132
 */

typedef unsigned short u16;

extern void *STA_ACTING_GetActorSystem(char *p);
extern int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out);
extern int func_0209C0A4();
extern void STA_ACT_LIGHT_ElemOpC(int self, char *p, u16 v);
extern void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);

void SCRIPT_COMMAND_TaskRotate(int a0, int *a1)
{
    int r4 = (int)STA_ACTING_GetActorSystem((char *)a1[0]);
    int local;
    if (STA_ACT_SCRIPT_StepTaskInt((char *)a1, &local) == 1) {
        STA_ACT_LIGHT_ElemOpC(r4, (char *)a1[6], (u16)func_0209C0A4(a1[2] << 16, 0x168));
        STA_ACT_SCRIPT_RemoveTask((char *)a1[7], (char *)a1[8]);
    } else {
        STA_ACT_LIGHT_ElemOpC(r4, (char *)a1[6], (u16)func_0209C0A4(local << 16, 0x168));
    }
}
