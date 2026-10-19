/*
 * file:     musical_dressup_sys.c
 * unit:     yes
 * function: MUSICAL_DRESSUP_SYS_Init, MUSICAL_DRESSUP_SYS_Exit, MUSICAL_DRESSUP_SYS_Main, MUSICAL_DRESSUP_SYS_Create, MUSICAL_DRESSUP_SYS_Delete
 * address:  0x02156BD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_dressup_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   STA_NET_GetRole  0x021FD904  thumb  ov132
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   sMusicalDressupSysFileName  0x02172730  data
 *   ov133_id  0x00000085  data
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   DUP_FITTING_Create  0x021B6100  thumb ov133
 *   DUP_FITTING_Main  0x021B63BC  thumb  ov133
 *   DUP_FITTING_Delete  0x021B6294  thumb ov133
 *   STA_NET_BeginTransfer  0x021FD52C  thumb ov132
 */
#include "event_ircbattle_shared_types.h"
#include "musical_event_shared_types.h"

/* Work of the dress-up proc. */
typedef struct MusicalDressupWork {
    u32 *paramCopy;                     /* 0x00 */
    void *ui;                           /* 0x04 */
    int result;                         /* 0x08 */
    MusicalDressupParam *param;         /* 0x0C */
} MusicalDressupWork;

extern int GF_OVERLAY_Load(s32 overlayId);

extern void GF_OVERLAY_Unload(s32 overlayId);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 GFL_HEAP_Free(void *ptr);

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);

extern int STA_NET_GetRole(void *session);

extern void GFL_HEAP_DeleteChecked(u32 heapId);

extern void *MUSICAL_SAVE_GetFromSave(void *saveControl);

extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);

extern void PROCSYS_FreeProcWork(void *proc);

extern void *DUP_FITTING_Create(void *param, int heapId);

extern int DUP_FITTING_Main(void *ui);

extern void DUP_FITTING_Delete(void *ui);

extern void STA_NET_BeginTransfer(void *session);

extern char ov133_id[];

extern const char sMusicalDressupSysFileName[];

int MUSICAL_DRESSUP_SYS_Init(void *proc, u32 *state, MusicalDressupParam *param);

int MUSICAL_DRESSUP_SYS_Exit(void *proc, int unused1, int unused2, MusicalDressupWork *work);

int MUSICAL_DRESSUP_SYS_Main(void *proc, int *state, int unused, MusicalDressupWork *work);

MusicalDressupParam *MUSICAL_DRESSUP_SYS_Create(int heapId, MusicalPerformer *performer, void *saveControl);

void MUSICAL_DRESSUP_SYS_Delete(MusicalDressupParam *param);

/*
 * Init of the dress-up proc: loads overlay 133 and copies the parameter
 * block to a heap copy the UI keeps.
 */
int MUSICAL_DRESSUP_SYS_Init(void *proc, u32 *state, MusicalDressupParam *param)
{
    MusicalDressupWork *work;
    *state = 0;
    GF_OVERLAY_Load((u32)ov133_id);
    GFL_HEAP_CreateChildHeap(1, 0x2d, 1 << 18);
    work = PROCSYS_AllocProcWork(proc, 0x10, 0x2d);
    work->paramCopy = GFL_HEAP_Alloc(0x2d, 0xc, 0, sMusicalDressupSysFileName, 0x4e);
    work->param = param;
    work->paramCopy[0] = ((u32 *)param)[0];
    work->paramCopy[1] = ((u32 *)param)[1];
    work->paramCopy[2] = ((u32 *)param)[2];
    return 1;
}

/*
 * Exit of the dress-up proc: frees the parameter copy and the proc work,
 * unloads overlay 133.
 */
int MUSICAL_DRESSUP_SYS_Exit(void *proc, int unused1, int unused2, MusicalDressupWork *work)
{
    GFL_HEAP_Free(work->paramCopy);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x2d);
    GF_OVERLAY_Unload((u32)ov133_id);
    return 1;
}

/*
 * Main of the dress-up proc: start the UI over the parameter copy, wait for
 * its result, close it. In a wireless session the host side is told first.
 */
int MUSICAL_DRESSUP_SYS_Main(void *proc, int *state, int unused, MusicalDressupWork *work)
{
    switch (*state) {
    case 0:
        work->ui = DUP_FITTING_Create(work->paramCopy, 0x2d);
        *state = 1;
        if (work->param->session != 0) {
            if (STA_NET_GetRole(work->param->session) == 1)
                STA_NET_BeginTransfer(work->param->session);
        }
        break;
    case 1: {
        int result = DUP_FITTING_Main(work->ui);
        if (result != 0) {
            work->result = result;
            *state = 2;
        }
        break;
    }
    case 2:
        DUP_FITTING_Delete(work->ui);
        return 1;
    }
    return 0;
}

/*
 * Creates the dress-up parameter block.
 */
MusicalDressupParam *MUSICAL_DRESSUP_SYS_Create(int heapId, MusicalPerformer *performer, void *saveControl)
{
    MusicalDressupParam *param;
    int zero = 0;

    param = GFL_HEAP_Alloc(heapId, 12, 0, sMusicalDressupSysFileName, 0xa7);
    param->session = (void *)zero;
    param->save = MUSICAL_SAVE_GetFromSave(saveControl);
    param->performer = performer;
    return param;
}

/*
 * Frees the dress-up parameter block (tail call through a pool word and
 * `bx r3`: docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
void MUSICAL_DRESSUP_SYS_Delete(MusicalDressupParam *param)
{
    GFL_HEAP_Free(param);
}
