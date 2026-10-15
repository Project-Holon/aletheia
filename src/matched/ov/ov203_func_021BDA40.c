/*
 * function: DEMO3D_Init
 * address: 0x021BDA40
 * packet: pkt_ov203_021BDA40
 * region: ov203
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI exceptions: 3159C returns the allocation still live in r0; BDC20
 * receives the caller's explicit byte truncation of its full-word payload.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DEMO3D_GRAPHIC_Create 0x021BDDD8 thumb ov203
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   DEMO3D_ENGINE_Create 0x021BE160 thumb ov203
 *   DEMO3D_CreateContext 0x021BDCC0 thumb ov203
 *   DEMO3D_ENGINE_GetFrameNum 0x021BE62C thumb ov203
 *   DEMO3D_DATA_GetTextureSize 0x021BE948 thumb ov203
 *   DEMO3D_StartWipe 0x021BDC20 thumb ov203
 *   ov067_id 0x00000043 data a1
 */
#include "../include/Obj06663.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Work { u16 heap, pad; void *arg; int state; void *view, *str, *msg, *model, *ctx; int tail[3]; } Work;
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned);
extern void *DEMO3D_GRAPHIC_Create(unsigned, void *, unsigned);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned PRINTSYS_QUE_Create(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
struct Cfg;
struct Ctx;
extern struct Ctx *DEMO3D_ENGINE_Create(void *owner, struct Cfg *cfg, u16 heap);
extern void *DEMO3D_CreateContext(int, void *, void *, unsigned);
extern u32 DEMO3D_ENGINE_GetFrameNum(char *p);
extern void DEMO3D_DATA_GetTextureSize(void *, int, u8 *, u8 *);
extern int DEMO3D_StartWipe(u8, unsigned, unsigned);
extern const char ov067_id[];
int DEMO3D_Init(void *manager, int unused, u8 *p)
{
    Work *w;
    u8 width, height;
    int delta;
    unsigned one = 1;
    unsigned heap = 0x6c;
    func_02034AC4((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x6c, 0x130000);
    w = PROCSYS_AllocProcWork(manager, sizeof(Work), 0x6c);
    MI_CpuFill8(w, 0, sizeof(Work));
    w->heap = heap;
    w->arg = p;
    w->view = DEMO3D_GRAPHIC_Create(1, ((struct Obj06663 *)p)->f4, w->heap);
    w->msg = func_02045B38(0, 2, 0x41, w->heap);
    w->str = (void *)PRINTSYS_QUE_Create((void *)w->heap);
    func_02040588(6, 0);
    func_02040588(4, 0);
    func_02040588(3, 0);
    func_02040588(2, 0);
    func_02040588(1, 0);
    BG_SYS_SetMainPlaneVisible(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    w->model = DEMO3D_ENGINE_Create(w->view, (struct Cfg *)p, w->heap);
    w->ctx = DEMO3D_CreateContext(*(int *)&((struct Obj06663 *)p)->f4, w->view, w->model, w->heap);
    delta = DEMO3D_ENGINE_GetFrameNum(w->model) - ((struct Obj06663 *)p)->f8;
    DEMO3D_DATA_GetTextureSize(((struct Obj06663 *)p)->f4, 0, &width, &height);
    if (delta > height) DEMO3D_StartWipe(*(unsigned *)&((struct Obj06663 *)p)->f4, one, w->heap);
    return 1;
}
