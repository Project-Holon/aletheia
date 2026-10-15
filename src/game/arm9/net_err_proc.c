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
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

struct ProcSysProc;
struct ProcSysParent;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* The 0x28-byte argument block a save proc is pushed with (record +0x180). */
typedef struct NetSaveRequest {
    u32   source0;        /* 0x00: value copied from the caller's data */
    u32   source1;        /* 0x04: second value copied from the caller's data */
    void *dataPtr;        /* 0x08: the save proc's data, or 1 while retrying */
    u32   state;          /* 0x0C: 0x21 while a save runs, 2 when it finished */
    void *workPtr;        /* 0x10: work block handed to the pushed proc */
    u32   retryFlag;      /* 0x14: 1 on the first retry pass */
    u32   pad18;          /* 0x18 */
    u32   cancelled;      /* 0x1C: nonzero once the save was cancelled */
} NetSaveRequest;

/* The 0x1A8-byte save-screen work record (GFL_NET_SAVE_CreateScreenWork). */
typedef struct NetSaveScreenWork {
    u32           data;             /* 0x00: the constructor's argument (a pointer, see ScreenMain) */
    u32           updateConnection; /* 0x04: nonzero while a connection update is owed */
    u32           proc;             /* 0x08: PROCSYS proc handle of heap 0x5b */
    u8            pad0C[0x180 - 0x0C]; /* 0x0C: argument block of the pushed save procs */
    NetSaveRequest request;         /* 0x180: pushed-proc argument block */
} NetSaveScreenWork;

/* The caller's argument of GFL_NET_SAVE_DeleteScreenWork (game data at +0x44). */
typedef struct NetSaveDeleteWork {
    u8  pad00[0x44];
    u32 gameData;   /* 0x44: GameData pointer, released before the reset */
} NetSaveDeleteWork;

extern void GAME_DATA_Delete(unsigned char *p);
extern void func_020315D4(struct ProcSysProc *p);
extern void  BG_SYS_SetMainVisiblePlanes(u32 a);
extern void  BG_SYS_SetSubVisiblePlanes(u32 a);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 heap, u32 size);
extern void *PROCSYS_AllocProcWork(struct ProcSysParent *obj, u32 size, u32 heap);
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


int GFL_NET_SAVE_DeleteScreenWork(int a0, int a1, int a2, int a3){ int t2, t3; GAME_DATA_Delete((unsigned char *)((NetSaveDeleteWork *)(char *)(a3))->gameData); func_020315D4((struct ProcSysProc *)((a0 + 0) + 0)); t2 = GFL_HEAP_DeleteChecked((int)0x67); t3 = OS_ResetSystem((int)0); return 1; }


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
    ((NetSaveScreenWork *)p)->data = (u32)a2;
    ((NetSaveScreenWork *)p)->proc = (unsigned int)PROCSYS_Create(0x5b);
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

    st = PROCSYS_Main((void *)((NetSaveScreenWork *)ctx)->proc);
    if (st == 2 || st == 0) {
        GFL_NET_ERR_ShowScreen(0);
    }
    switch (*seq) {
    case 0:
        (*seq)++;
        break;
    case 1:
        flag = 1;
        if (((NetSaveScreenWork *)ctx)->request.state != 2) {
            flag = 0;
        }
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, 0x28);
        ((NetSaveScreenWork *)ctx)->request.source0 = **(u32 * *)&((NetSaveScreenWork *)ctx)->data;
        ((NetSaveScreenWork *)ctx)->request.source1 = 0;
        *(u32 *)&((NetSaveScreenWork *)ctx)->request.dataPtr = 1;
        *(u8 * *)&((NetSaveScreenWork *)ctx)->request.workPtr = ctx + 0xc;
        ((NetSaveScreenWork *)ctx)->request.state = 0x21;
        if (flag) {
            ((NetSaveScreenWork *)ctx)->request.retryFlag = 1;
        } else {
            ((NetSaveScreenWork *)ctx)->request.retryFlag = 0;
        }
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, ov115_id, gNetSaveMainProc, &((NetSaveScreenWork *)ctx)->request);
        (*seq)++;
        break;
    case 2:
        if (st != 0) {
            break;
        }
        if (((NetSaveScreenWork *)ctx)->request.cancelled == 0) {
            ((NetSaveScreenWork *)ctx)->updateConnection = 1;
            (*seq)++;
            break;
        }
        *seq = 7;
        break;
    case 3:
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, 0x10);
        ((NetSaveScreenWork *)ctx)->request.source0 = (*(u32 **)ctx)[1];
        ((NetSaveScreenWork *)ctx)->request.source1 = (*(u32 **)ctx)[0];
        *(u8 * *)&((NetSaveScreenWork *)ctx)->request.dataPtr = ctx + 0xc;
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, ov187_id, d_0220B294, &((NetSaveScreenWork *)ctx)->request);
        (*seq)++;
        break;
    case 4:
        if (st != 0) {
            break;
        }
        if (((NetSaveScreenWork *)ctx)->request.state == 2) {
            *seq = 1;
            break;
        }
        (*seq)++;
        break;
    case 5:
        MI_CpuFill8(&((NetSaveScreenWork *)ctx)->request, 0, 0x1c);
        ((NetSaveScreenWork *)ctx)->request.source0 = **(u32 * *)&((NetSaveScreenWork *)ctx)->data;
        ((NetSaveScreenWork *)ctx)->request.source1 = 0;
        *(u32 *)&((NetSaveScreenWork *)ctx)->request.dataPtr = 1;
        PROCSYS_Push(((NetSaveScreenWork *)ctx)->proc, ov115_id, gNetSaveRetryProc, &((NetSaveScreenWork *)ctx)->request);
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
