/*
 * function: func_02010AC4
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
 *           resolve as `overlay_id` (id argument of func_020312CC).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           func_02010C34's pool (0x02010D84..), which disasm.py prints as
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
 *
 * symbols:
 *   ov115_id       0x00000073  data  a1
 *   ov123_id       0x0000007B  data  a1
 *   d_021D6338     0x021D6338  data  ov115
 *   d_021DA9A8     0x021DA9A8  data
 *   d_021D654C     0x021D654C  data  ov115
 *   func_020312CC  0x020312CC  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_0203CD98  0x0203CD98  arm
 *
 * The net_save.c save task's per-frame step (the task record of
 * sub_02010A5C; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to func_0200F7B8(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ov115_id[];
extern u8 ov123_id[];
extern u8 d_021D6338[];
extern u8 d_021DA9A8[];
extern u8 d_021D654C[];

extern void func_020312CC(void *ovl, void *proc, void *arg);
extern void func_0200F7B8(u32 a);
extern int  func_0203CD98(void);

int func_02010AC4(u32 a0, u32 a1, u32 a2, u8 *ctx)
{
    switch (*(u32 *)(ctx + 0x1d4)) {
    case 0:
        *(u32 *)(ctx + 0x00) = *(u32 *)(ctx + 0x44);
        *(u32 *)(ctx + 0x04) = 0;
        *(u32 *)(ctx + 0x08) = 1;
        *(u32 *)(ctx + 0x0c) = 0x32;
        *(u8 **)(ctx + 0x10) = ctx + 0x5c;
        func_020312CC(ov115_id, d_021D6338, ctx);
        *(u32 *)(ctx + 0x1d4) += 1;
        break;
    case 1:
        if (*(u32 *)(ctx + 0x1c) == 1) {
            *(u32 *)(ctx + 0x1d4) = 4;
            break;
        }
        *(u32 *)(ctx + 0x48) = *(u32 *)(ctx + 0x44);
        *(u16 *)(ctx + 0x50) = *(u16 *)(ctx + 0x1d0);
        *(u8 **)(ctx + 0x4c) = ctx + 0x5c;
        func_020312CC(ov123_id, d_021DA9A8, ctx + 0x48);
        *(u32 *)(ctx + 0x1d4) += 1;
        break;
    case 2:
        if (*(u32 *)(ctx + 0x54) == 1) {
            *(u32 *)(ctx + 0x1d4) = 4;
            break;
        }
        func_0200F7B8(0);
        *(u32 *)(ctx + 0x1d4) += 1;
        break;
    case 3:
        if (func_0203CD98() == 0 || *(u32 *)(ctx + 0x58) == 1) {
            *(u32 *)(ctx + 0x14) = 1;
            *(u32 *)(ctx + 0x1d4) = 0;
            break;
        }
        *(u32 *)(ctx + 0x28) = *(u32 *)(ctx + 0x44);
        *(u32 *)(ctx + 0x2c) = 0;
        *(u32 *)(ctx + 0x30) = 1;
        func_020312CC(ov115_id, d_021D654C, ctx + 0x28);
        *(u32 *)(ctx + 0x1d4) += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
