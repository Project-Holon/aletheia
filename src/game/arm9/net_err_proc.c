/*
 * file:     net_err_proc.c
 * unit:     yes
 * function: GFL_NET_SAVE_DeleteScreenWork, GFL_NET_SAVE_CreateScreenWork, GFL_NET_SAVE_ScreenMain, GFL_NET_SAVE_ScreenExit
 * address:  0x02010B98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_err_proc.c, net_err_proc_exit.c by tools/splitfile.py.
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
 *   DWC_UpdateConnection  0x0205D074  arm
 *   GAME_DATA_Delete  0x02012704  thumb
 *   OS_ResetSystem  0x02087BCC  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   PROCSYS_Delete  0x0203133C  arm
 */

struct ProcSysProc;

struct ProcSysParent;

#include "../types.h"

#include "net_save_types.h"

#include "../ov187/br_launch_types.h"

/* The 0x28-byte argument block a save proc is pushed with (record +0x180): the ov115 login block or the ov187 launch block. */
typedef union NetSaveRequest {
    WifiLoginParam login;
    BrLaunchParam br;
} NetSaveRequest;

/* The proc argument of GFL_NET_SAVE_CreateScreenWork. */
typedef struct NetSaveScreenInput {
    struct GameData *gameData;  /* 0x00 */
    u32 kind;                   /* 0x04 */
} NetSaveScreenInput;

/* The 0x1A8-byte save-screen work record (GFL_NET_SAVE_CreateScreenWork). */
typedef struct NetSaveScreenWork {
    NetSaveScreenInput *input;      /* 0x00: the constructor's argument */
    u32           updateConnection; /* 0x04: nonzero while a connection update is owed */
    struct ProcSys *proc;           /* 0x08: PROCSYS proc handle of heap 0x5b */
    u8            saveBuf[0x174];   /* 0x0C: save buffer handed to the pushed procs */
    NetSaveRequest request;         /* 0x180: pushed-proc argument block */
} NetSaveScreenWork;

/* Fill and allocation sizes of the work record: DS byte counts, host struct sizes. */
#ifdef __MWERKS__
enum { NET_SAVE_WORK_SIZE = 0x1a8, NET_SAVE_REQUEST_SIZE = 0x28 };
#else
enum { NET_SAVE_WORK_SIZE = sizeof(NetSaveScreenWork), NET_SAVE_REQUEST_SIZE = sizeof(NetSaveRequest) };
#endif
enum { NET_SAVE_CLEAR_TO_WORK_PTR = BW_OFFSETOF(WifiLoginParam, saveData), NET_SAVE_CLEAR_TO_CANCELLED = BW_OFFSETOF(WifiLoginParam, result) };

#include "game_data.h"

#include "gfl_heap_wrap.h"
struct Proc;

#include "procsys.h"

#include "bg_sys.h"


#include "gfl_heap.h"


#include "mi_memory.h"



#include "net_err.h"

#include "dwc_connectinet.h"

int GFL_NET_SAVE_DeleteScreenWork(struct Proc *proc, int seq, int pwork, struct NetSaveProcWork *work);

int GFL_NET_SAVE_CreateScreenWork(void *ctx, int seq, NetSaveScreenInput *pwork);

int GFL_NET_SAVE_ScreenMain(u32 proc, u32 *seq, u32 pwork, u8 *ctx);

extern u8 ov115_id[];

extern u8 ov187_id[];

#include "net_save.h"

extern u8 d_0220B294[];


#include "os_reset.h"
int GFL_NET_SAVE_DeleteScreenWork(struct Proc *proc, int seq, int pwork, struct NetSaveProcWork *work){ GAME_DATA_Delete(work->gameData); PROCSYS_FreeProcWork(proc); GFL_HEAP_DeleteChecked(0x67); OS_ResetSystem(0); return 1; }

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
int GFL_NET_SAVE_CreateScreenWork(void *ctx, int seq, NetSaveScreenInput *pwork)
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
    p = PROCSYS_AllocProcWork(ctx, NET_SAVE_WORK_SIZE, 0x5b);
    MI_CpuFill8(p, 0, NET_SAVE_WORK_SIZE);
    ((NetSaveScreenWork *)p)->input = pwork;
    ((NetSaveScreenWork *)p)->proc = (struct ProcSys *)PROCSYS_Create(0x5b);
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
 *           function pointers each, 0x021D6338 -> 0x021D4BFC/4CE4/4D10,
 *           0x021D654C -> 0x021D603C/6104/60D4), loaded with overlay id
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
int GFL_NET_SAVE_ScreenMain(u32 proc, u32 *seq, u32 pwork, u8 *ctx)
{
    int st;
    int flag;

    st = PROCSYS_Main(((NetSaveScreenWork *)ctx)->proc);
    if (st == 2 || st == 0) {
        GFL_NET_ERR_ShowScreen(0);
    }
    switch (*seq) {
    case 0:
        (*seq)++;
        break;
    case 1:
        flag = 1;
        if (((NetSaveScreenWork *)ctx)->request.login.messageId != 2) {
            flag = 0;
        }
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, NET_SAVE_REQUEST_SIZE);
        ((NetSaveScreenWork *)ctx)->request.login.gameData = ((NetSaveScreenWork *)ctx)->input->gameData;
        ((NetSaveScreenWork *)ctx)->request.login.loginType = 0;
        ((NetSaveScreenWork *)ctx)->request.login.loginOption = 1;
        ((NetSaveScreenWork *)ctx)->request.login.saveData = ((NetSaveScreenWork *)ctx)->saveBuf;
        ((NetSaveScreenWork *)ctx)->request.login.messageId = 0x21;
        if (flag) {
            ((NetSaveScreenWork *)ctx)->request.login.useSaveData = 1;
        } else {
            ((NetSaveScreenWork *)ctx)->request.login.useSaveData = 0;
        }
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, (uptr)ov115_id, &gNetSaveMainProc, &((NetSaveScreenWork *)ctx)->request);
        (*seq)++;
        break;
    case 2:
        if (st != 0) {
            break;
        }
        if (((NetSaveScreenWork *)ctx)->request.login.result == 0) {
            ((NetSaveScreenWork *)ctx)->updateConnection = 1;
            (*seq)++;
            break;
        }
        *seq = 7;
        break;
    case 3:
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, NET_SAVE_CLEAR_TO_WORK_PTR);
        ((NetSaveScreenWork *)ctx)->request.br.kind = ((NetSaveScreenWork *)ctx)->input->kind;
        ((NetSaveScreenWork *)ctx)->request.br.gameData = ((NetSaveScreenWork *)ctx)->input->gameData;
        ((NetSaveScreenWork *)ctx)->request.br.netArg = ((NetSaveScreenWork *)ctx)->saveBuf;
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, (uptr)ov187_id, (const ProcData *)d_0220B294, &((NetSaveScreenWork *)ctx)->request);
        (*seq)++;
        break;
    case 4:
        if (st != 0) {
            break;
        }
        if (((NetSaveScreenWork *)ctx)->request.login.messageId == 2) {
            *seq = 1;
            break;
        }
        (*seq)++;
        break;
    case 5:
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, NET_SAVE_CLEAR_TO_CANCELLED);
        ((NetSaveScreenWork *)ctx)->request.login.gameData = ((NetSaveScreenWork *)ctx)->input->gameData;
        ((NetSaveScreenWork *)ctx)->request.login.loginType = 0;
        ((NetSaveScreenWork *)ctx)->request.login.loginOption = 1;
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, (uptr)ov115_id, &gNetSaveRetryProc, &((NetSaveScreenWork *)ctx)->request);
        ((NetSaveScreenWork *)ctx)->updateConnection = 0;
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
    if (((NetSaveScreenWork *)ctx)->updateConnection == 1) {
        DWC_UpdateConnection();
    }
    return 0;
}

int GFL_NET_SAVE_ScreenExit(struct ProcSysProc *proc, u32 *seq, void *param, NetSaveScreenWork *work);

int GFL_NET_SAVE_ScreenExit(struct ProcSysProc *proc, u32 *seq, void *param, NetSaveScreenWork *work)
{
    PROCSYS_Delete(work->proc);
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(0x5b);
    return 1;
}
