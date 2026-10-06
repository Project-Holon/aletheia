/*
 * function: func_02010C34
 * address:  0x02010C34
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the overlay ids 0x73 / 0xBB (ov115_id, ov187_id) now resolve as
 *           `overlay_id` (id argument of func_02031348), and 0x0220B294
 *           resolves.  Two ABS32 sites are left, the overlay-resident procs
 *           0x021D6338 / 0x021D654C.  Both ALSO sit in func_02010AC4's pool
 *           (0x02010B84..0x02010B94), which would attest them as `literal`,
 *           but disasm.py prints both functions' pools as Thumb
 *           instructions, so the pool-word index never sees them.
 *           Integrator: seed these pools as .word and both sites here (and
 *           both in func_02010AC4) resolve.
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
 *   ov187_id       0x000000BB  data  a1
 *   d_021D6338     0x021D6338  data  ov115
 *   d_0220B294     0x0220B294  data
 *   d_021D654C     0x021D654C  data  ov115
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0205D074  0x0205D074  arm
 *
 * net_save.c's save-SCREEN task step (record of func_02010BB8; *seq is the
 * step, ctx the record): polls the save proc's status (func_02031330),
 * drops to func_0200F7B8(0) on states 0/2, then walks eight steps that start
 * overlay 0x73's save procs and overlay 0xBB's proc on the +0x180 request
 * block via func_02031348, returning 1 at step 7.  The only non-obvious
 * spelling: the +0x194 flag is an if/else of two constant stores, which
 * lets the 1 already in r0 from the +0x188 store be reused.
 */
#include "../include/Obj00645.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ov115_id[];
extern u8 ov187_id[];
extern u8 d_021D6338[];
extern u8 d_0220B294[];
extern u8 d_021D654C[];

extern unsigned int func_02031330(void *p);
extern void func_02031348(u32 h, void *ovl, void *proc, void *arg);
extern u32 func_0200F7B8(u32 a0);
extern void MI_CpuFill8(void *dst, u8 v, u32 size);
extern int func_0205D074(void);

int func_02010C34(u32 a0, u32 *seq, u32 a2, u8 *ctx)
{
    int st;
    int flag;

    st = func_02031330((void *)((struct Obj00645 *)ctx)->f8);
    if (st == 2 || st == 0) {
        func_0200F7B8(0);
    }
    switch (*seq) {
    case 0:
        (*seq)++;
        break;
    case 1:
        flag = 1;
        if (((struct Obj00645 *)ctx)->f18C != 2) {
            flag = 0;
        }
        MI_CpuFill8(ctx + 0x180, 0, 0x28);
        ((struct Obj00645 *)ctx)->f180 = **(u32 * *)&((struct Obj00645 *)ctx)->f0;
        ((struct Obj00645 *)ctx)->f184 = 0;
        *(u32 *)&((struct Obj00645 *)ctx)->f188 = 1;
        *(u8 * *)&((struct Obj00645 *)ctx)->f190 = ctx + 0xc;
        ((struct Obj00645 *)ctx)->f18C = 0x21;
        if (flag) {
            ((struct Obj00645 *)ctx)->f194 = 1;
        } else {
            ((struct Obj00645 *)ctx)->f194 = 0;
        }
        func_02031348(((struct Obj00645 *)ctx)->f8, ov115_id, d_021D6338, ctx + 0x180);
        (*seq)++;
        break;
    case 2:
        if (st != 0) {
            break;
        }
        if (((struct Obj00645 *)ctx)->f19C == 0) {
            ((struct Obj00645 *)ctx)->f4 = 1;
            (*seq)++;
            break;
        }
        *seq = 7;
        break;
    case 3:
        MI_CpuFill8(ctx + 0x180, 0, 0x10);
        ((struct Obj00645 *)ctx)->f180 = (*(u32 **)ctx)[1];
        ((struct Obj00645 *)ctx)->f184 = (*(u32 **)ctx)[0];
        *(u8 * *)&((struct Obj00645 *)ctx)->f188 = ctx + 0xc;
        func_02031348(((struct Obj00645 *)ctx)->f8, ov187_id, d_0220B294, ctx + 0x180);
        (*seq)++;
        break;
    case 4:
        if (st != 0) {
            break;
        }
        if (((struct Obj00645 *)ctx)->f18C == 2) {
            *seq = 1;
            break;
        }
        (*seq)++;
        break;
    case 5:
        MI_CpuFill8(ctx + 0x180, 0, 0x1c);
        ((struct Obj00645 *)ctx)->f180 = **(u32 * *)&((struct Obj00645 *)ctx)->f0;
        ((struct Obj00645 *)ctx)->f184 = 0;
        *(u32 *)&((struct Obj00645 *)ctx)->f188 = 1;
        func_02031348(((struct Obj00645 *)ctx)->f8, ov115_id, d_021D654C, ctx + 0x180);
        ((struct Obj00645 *)ctx)->f4 = 0;
        (*seq)++;
        break;
    case 6:
        if (st != 0) {
            break;
        }
        (*seq)++;
        break;
    case 7:
        return 1;
    }
    if (((struct Obj00645 *)ctx)->f4 == 1) {
        func_0205D074();
    }
    return 0;
}
