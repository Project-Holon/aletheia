/*
 * function: GFL_NET_SAVE_Main
 * address:  0x02010AC4
 * packet:   pkt_02010AC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the pooled overlay ids 0x73 / 0x7B (ov115_id, ov123_id) now
 *           resolve as `overlay_id` (id argument of PROCSYS_PushGlobal).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           GFL_NET_SAVE_ScreenMain's pool (0x02010D84..), which disasm.py prints as
 *           Thumb code, so the literal index misses them.  Seeding those
 *           pools as .word, or a matched referrer, would close both.
 *           Seed round 10: both words are ov115 proc tables (three Thumb
 *           function pointers each, 0x021D6338 -> func_021D4BFC/4CE4/4D10,
 *           0x021D654C -> func_021D603C/6104/60D4), loaded with overlay id
 *           0x73 = ov115, not ov021 (docs/sessions/2026-09-23/reports/
 *           wave17_evidence.md).  ov115 declares both starts in
 *           layout/data_objects.txt and the symbols lines carry the ov115
 *           token.  0x021D654C resolves as sole-ref/data (ov115 is the only
 *           overlay with a start there).  0x021D6338 resolves as
 *           sole-ref/self on the ov115 hint; ov021's listing also starts a
 *           block there, so sole-ref/data refuses the contested hint, and the
 *           choice rests on the hint plus the overlay_id 0x73 site in this
 *           same function.  EXACT, seed round 10.
 * evidence: gNetSaveCheckProc lies in the windows of ov016, ov021, ov123, ov125
 *           and ov175, so the ov123 hint needs outside support.  Case 1
 *           passes ov123_id (0x7B, attested `overlay_id`) and this pointer
 *           in one PROCSYS_PushGlobal call; PROCSYS_PushInternal -> PROCSYS_NewProc stores
 *           the id at Proc+4 and the pointer at Proc+0 (ProcData), and
 *           PROCSYS_StepProc loads overlay Proc+4 (func_02034AC4) before it
 *           calls any ProcData callback.  So ov123 is resident whenever the
 *           pointer is dereferenced.  Independently, ov123's bytes at
 *           0x021DA9A8 are three Thumb pointers 0x021DA479/0x021DA54D/
 *           0x021DA5D1, each a func_ label in ov123's own listing, while
 *           ov125 has bss there and ov016/ov021/ov175 hold non-pointer
 *           words.  With the hint the site attests as `sole-ref` in ov123.
 *
 * symbols:
 *   ov115_id       0x00000073  data  a1
 *   ov123_id       0x0000007B  data  a1
 *   gNetSaveMainProc     0x021D6338  data  ov115
 *   gNetSaveCheckProc     0x021DA9A8  data  ov123
 *   gNetSaveRetryProc     0x021D654C  data  ov115
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *
 * The net_save.c save task's per-frame step (the task record of
 * GFL_NET_SAVE_InitWork; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to GFL_NET_ERR_ShowScreen(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */
#include "../include/Obj00562.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ov115_id[];
extern u8 ov123_id[];
extern u8 gNetSaveMainProc[];
extern u8 gNetSaveCheckProc[];
extern u8 gNetSaveRetryProc[];

extern void PROCSYS_PushGlobal(u32 ovl, u32 proc, u32 arg);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern int  GFL_NET_GetRunState(void);

int GFL_NET_SAVE_Main(u32 a0, u32 a1, u32 a2, u8 *ctx)
{
    switch (((struct Obj00562 *)ctx)->f1D4) {
    case 0:
        ((struct Obj00562 *)ctx)->f0 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f4 = 0;
        ((struct Obj00562 *)ctx)->f8 = 1;
        ((struct Obj00562 *)ctx)->fC = 0x32;
        *(u8 * *)&((struct Obj00562 *)ctx)->f10 = ctx + 0x5c;
        PROCSYS_PushGlobal((u32)ov115_id, (u32)gNetSaveMainProc, (u32)ctx);
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 1:
        if (((struct Obj00562 *)ctx)->f1C == 1) {
            ((struct Obj00562 *)ctx)->f1D4 = 4;
            break;
        }
        ((struct Obj00562 *)ctx)->f48 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f50 = ((struct Obj00562 *)ctx)->f1D0;
        *(u8 * *)&((struct Obj00562 *)ctx)->f4C = ctx + 0x5c;
        PROCSYS_PushGlobal((u32)ov123_id, (u32)gNetSaveCheckProc, (u32)(ctx + 0x48));
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 2:
        if (((struct Obj00562 *)ctx)->f54 == 1) {
            ((struct Obj00562 *)ctx)->f1D4 = 4;
            break;
        }
        GFL_NET_ERR_ShowScreen(0);
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 3:
        if (GFL_NET_GetRunState() == 0 || ((struct Obj00562 *)ctx)->f58 == 1) {
            ((struct Obj00562 *)ctx)->f14 = 1;
            ((struct Obj00562 *)ctx)->f1D4 = 0;
            break;
        }
        ((struct Obj00562 *)ctx)->f28 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f2C = 0;
        ((struct Obj00562 *)ctx)->f30 = 1;
        PROCSYS_PushGlobal((u32)ov115_id, (u32)gNetSaveRetryProc, (u32)(ctx + 0x28));
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
