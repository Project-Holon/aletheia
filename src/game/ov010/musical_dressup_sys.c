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
    MusicalDressupParam *paramCopy;                     /* 0x00 */
    void *ui;                           /* 0x04 */
    int result;                         /* 0x08 */
    MusicalDressupParam *param;         /* 0x0C */
} MusicalDressupWork;

#include "../arm9/gf_overlay.h"


#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gfl_heap.h"

#include "../ov132/sta_net.h"

struct SaveControl;
struct MusicalSave;

#include "../arm9/musical_save.h"
struct Proc;

#include "../arm9/procsys.h"


#include "../ov133/dup_fitting.h"
struct DupFittingWork;


struct StaNetWork;


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
    GF_OVERLAY_Load((uptr)ov133_id);
    GFL_HEAP_CreateChildHeap(1, 0x2d, 1 << 18);
    work = PROCSYS_AllocProcWork(proc, sizeof(*work), 0x2d);
    work->paramCopy = GFL_HEAP_Alloc(0x2d, sizeof(MusicalDressupParam), 0, sMusicalDressupSysFileName, 0x4e);
    work->param = param;
    work->paramCopy->session = param->session;
    work->paramCopy->performer = param->performer;
    work->paramCopy->save = param->save;
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
    GF_OVERLAY_Unload((uptr)ov133_id);
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
        work->ui = DUP_FITTING_Create((u8 *)work->paramCopy, 0x2d);
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
    sptr zero = 0;

    param = GFL_HEAP_Alloc(heapId, sizeof(*param), 0, sMusicalDressupSysFileName, 0xa7);
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
