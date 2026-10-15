/*
 * file:     net_err_proc.c
 * unit:     yes
 * function: GFL_NET_SAVE_DeleteScreenWork, GFL_NET_SAVE_CreateScreenWork, GFL_NET_SAVE_ScreenMain
 * address:  0x02010B98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PROCSYS_Create  0x02031324  arm
 *   ov115_id       0x00000073  data  a1
 *   ov187_id       0x000000BB  data  a1
 *   gNetSaveMainProc     0x021D6338  data  ov115
 *   d_0220B294     0x0220B294  data
 *   gNetSaveRetryProc     0x021D654C  data  ov115
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   DWC_UpdateConnection  0x0205D074  arm
 *   GAME_DATA_Delete  0x02012704  thumb
 *   OS_ResetSystem  0x02087BCC  arm
 */
#include "../../matched/include/Obj15614.h"
#include "../../matched/include/Obj11242.h"
#include "../../matched/include/Obj00645.h"

struct S020315D4;
struct Obj0203159C;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void GAME_DATA_Delete(unsigned char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void  BG_SYS_SetMainVisiblePlanes(u32 a);
extern void  BG_SYS_SetSubVisiblePlanes(u32 a);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 heap, u32 size);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *dst, int val, unsigned n);
extern void *PROCSYS_Create(int a0);
extern unsigned int PROCSYS_Main(void *p);
extern void PROCSYS_Push(u32 h, void *ovl, void *proc, void *arg);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern int DWC_UpdateConnection(void);
int GFL_NET_SAVE_DeleteScreenWork(int a0, int a1, int a2, int a3);
int GFL_NET_SAVE_CreateScreenWork(void *ctx, int a1, int a2);
int GFL_NET_SAVE_ScreenMain(u32 a0, u32 *seq, u32 a2, u8 *ctx);
extern u8 ov115_id[];
extern u8 ov187_id[];
extern u8 gNetSaveMainProc[];
extern u8 d_0220B294[];
extern u8 gNetSaveRetryProc[];


int GFL_NET_SAVE_DeleteScreenWork(int a0, int a1, int a2, int a3){ int t2, t3; GAME_DATA_Delete((unsigned char *)((struct Obj15614 *)((char *)(a3)))->f44); func_020315D4((struct S020315D4 *)((a0 + 0) + 0)); t2 = func_020306F0((int)0x67); t3 = OS_ResetSystem((int)0); return 1; }


/*
 * The save-screen constructor of the net_save.c family (see
 * docs/families/net_save.h section 3).  It blanks both display engines'
 * blend and window bits -- 0x04000000 and 0x04001000 are the two DISPCNT
 * words, masked first with ~0x1F00 and then with ~0xE000, and 0x04000050 /
 * 0x04001050 are the two BLDCNT halfwords zeroed -- then allocates a
 * 0x1A8-byte record at heap 0x5b, zeroes it, stores its third argument at
 * +0x00 and the heap's own handle (PROCSYS_Create(0x5b)) at +0x08.
 *
 * The four masked read-modify-writes are written as four separate compound
 * assignments in source order: the compiler reuses the two pooled addresses
 * across them, which is what puts the second pair's `adds r1, #0x50` /
 * `adds r0, #0x50` in place of two more pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_CreateScreenWork.c \
 *       --func GFL_NET_SAVE_CreateScreenWork --addr 0x02010BB8 --cc 1.1p1 --thumb
 */
int GFL_NET_SAVE_CreateScreenWork(void *ctx, int a1, int a2)
{
    u8 *p;

    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(u32 *)0x04000000 &= 0xFFFFE0FF;
    *(u32 *)0x04001000 &= 0xFFFFE0FF;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    GFL_HEAP_CreateChildHeap(1, 0x5b, 0x800);
    p = PROCSYS_AllocProcWork(ctx, 0x1a8, 0x5b);
    MI_CpuFill8(p, 0, 0x1a8);
    ((struct Obj11242 *)p)->f0 = (u32)a2;
    ((struct Obj11242 *)p)->f8 = (unsigned int)PROCSYS_Create(0x5b);
    return 1;
}


/*
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the overlay ids 0x73 / 0xBB (ov115_id, ov187_id) now resolve as
 *           `overlay_id` (id argument of PROCSYS_Push), and 0x0220B294
 *           resolves.  Two ABS32 sites are left, the overlay-resident procs
 *           0x021D6338 / 0x021D654C.  Both ALSO sit in GFL_NET_SAVE_Main's pool
 *           (0x02010B84..0x02010B94), which would attest them as `literal`,
 *           but disasm.py prints both functions' pools as Thumb
 *           instructions, so the pool-word index never sees them.
 *           Integrator: seed these pools as .word and both sites here (and
 *           both in GFL_NET_SAVE_Main) resolve.
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
 * net_save.c's save-SCREEN task step (record of GFL_NET_SAVE_CreateScreenWork; *seq is the
 * step, ctx the record): polls the save proc's status (PROCSYS_Main),
 * drops to GFL_NET_ERR_ShowScreen(0) on states 0/2, then walks eight steps that start
 * overlay 0x73's save procs and overlay 0xBB's proc on the +0x180 request
 * block via PROCSYS_Push, returning 1 at step 7.  The only non-obvious
 * spelling: the +0x194 flag is an if/else of two constant stores, which
 * lets the 1 already in r0 from the +0x188 store be reused.
 */
int GFL_NET_SAVE_ScreenMain(u32 a0, u32 *seq, u32 a2, u8 *ctx)
{
    int st;
    int flag;

    st = PROCSYS_Main((void *)((struct Obj00645 *)ctx)->f8);
    if (st == 2 || st == 0) {
        GFL_NET_ERR_ShowScreen(0);
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
        PROCSYS_Push(((struct Obj00645 *)ctx)->f8, ov115_id, gNetSaveMainProc, ctx + 0x180);
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
        PROCSYS_Push(((struct Obj00645 *)ctx)->f8, ov187_id, d_0220B294, ctx + 0x180);
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
        PROCSYS_Push(((struct Obj00645 *)ctx)->f8, ov115_id, gNetSaveRetryProc, ctx + 0x180);
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
        DWC_UpdateConnection();
    }
    return 0;
}
