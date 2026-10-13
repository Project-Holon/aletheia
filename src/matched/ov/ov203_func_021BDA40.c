/*
 * function: func_021BDA40
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
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDDD8 0x021BDDD8 thumb ov203
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_021BE160 0x021BE160 thumb ov203
 *   func_021BDCC0 0x021BDCC0 thumb ov203
 *   func_021BE62C 0x021BE62C thumb ov203
 *   func_021BE948 0x021BE948 thumb ov203
 *   func_021BDC20 0x021BDC20 thumb ov203
 *   ov067_id 0x00000043 data a1
 */
#include "../include/Obj06663.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Work { u16 heap, pad; void *arg; int state; void *view, *str, *msg, *model, *ctx; int tail[3]; } Work;
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_021BDDD8(unsigned, void *, unsigned);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_0201C440(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
struct Cfg;
struct Ctx;
extern struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);
extern void *func_021BDCC0(int, void *, void *, unsigned);
extern u32 func_021BE62C(char *p);
extern void func_021BE948(void *, int, u8 *, u8 *);
extern int func_021BDC20(u8, unsigned, unsigned);
extern const char ov067_id[];
int func_021BDA40(void *manager, int unused, u8 *p)
{
    Work *w;
    u8 width, height;
    int delta;
    unsigned one = 1;
    unsigned heap = 0x6c;
    func_02034AC4((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x6c, 0x130000);
    w = PROCSYS_AllocProcWork(manager, sizeof(Work), 0x6c);
    func_02082BCC(w, 0, sizeof(Work));
    w->heap = heap;
    w->arg = p;
    w->view = func_021BDDD8(1, ((struct Obj06663 *)p)->f4, w->heap);
    w->msg = func_02045B38(0, 2, 0x41, w->heap);
    w->str = (void *)func_0201C440((void *)w->heap);
    func_02040588(6, 0);
    func_02040588(4, 0);
    func_02040588(3, 0);
    func_02040588(2, 0);
    func_02040588(1, 0);
    func_020434DC(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    w->model = func_021BE160(w->view, (struct Cfg *)p, w->heap);
    w->ctx = func_021BDCC0(*(int *)&((struct Obj06663 *)p)->f4, w->view, w->model, w->heap);
    delta = func_021BE62C(w->model) - ((struct Obj06663 *)p)->f8;
    func_021BE948(((struct Obj06663 *)p)->f4, 0, &width, &height);
    if (delta > height) func_021BDC20(*(unsigned *)&((struct Obj06663 *)p)->f4, one, w->heap);
    return 1;
}
