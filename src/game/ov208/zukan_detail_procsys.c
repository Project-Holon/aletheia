/*
 * file:     zukan_detail_procsys.c
 * unit:     yes
 * function: ZUKAN_DETAIL_PROCSYS_AllocNode, ZUKAN_DETAIL_PROCSYS_FreeNode, ZUKAN_DETAIL_PROCSYS_RunStateCallbacks, ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate, ZUKAN_DETAIL_PROCSYS_CallOwnerHook, ZUKAN_DETAIL_PROCSYS_AllocBuffer, ZUKAN_DETAIL_PROCSYS_FreeBuffer
 * address:  0x021BC240
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c, zukan_detail_form.c, ov208_func_021C80CC.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D80 0x021C8D80 data a1
 *   func_020307B0 0x020307B0  arm
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 */
#include "zukan_detail_shared_types.h"

typedef void (*Vfn)(char *self, char *a, int b, int c, int d);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

struct Ov208Fsm *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap);

void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p);

int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct Ov208Fsm *p,int arg);

void ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(char *p, int a, int b);

void ZUKAN_DETAIL_PROCSYS_CallOwnerHook(char *p, int v);

void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Fsm *p, u32 size, u32 heap);

void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *p);

extern const char d_021C8D80[];

struct Ov208Fsm *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap)
{
    struct Ov208Fsm *p = func_02030734(heap, 20, 0, d_021C8D80, 0x4f);
    p->callbacks = (Ov208FsmCallback *)owner;
    p->state = 0;
    p->counter = 0;
    p->a = val;
    p->work = 0;
    return p;
}

void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p)
{
    func_020307B0(p);
}

int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct Ov208Fsm *p,int arg)
{
    int result=1;
    switch(p->state) {
    case 0:
        if(p->callbacks[0]) result=p->callbacks[0](p,&p->counter,p->a,p->work,arg);
        if(result==1) { p->state=1; p->counter=0; }
        break;
    case 1:
        if(p->callbacks[1]) result=p->callbacks[1](p,&p->counter,p->a,p->work,arg);
        if(result==1) { p->state=2; p->counter=0; }
        break;
    case 2:
        if(p->callbacks[2]) result=p->callbacks[2](p,&p->counter,p->a,p->work,arg);
        if(result==1) return 1;
        break;
    }
    return 0;
}

/*
 * Virtual call through the handler table entry at +0xc of the node, passing the
 * node, its counter word, its two payload words and the two arguments.
 */
void ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(char *p, int a, int b)
{
    void (*fn)(char *, char *, int, int, int, int);

    fn = (void (*)(char *, char *, int, int, int, int))((struct Ov208Fsm *)p)->callbacks[3];
    if (fn != 0)
        fn(p, p + 8, ((struct Ov208Fsm *)p)->a, (int)((struct Ov208Fsm *)p)->work, a, b);
}

void ZUKAN_DETAIL_PROCSYS_CallOwnerHook(char *p, int v)
{
    Vfn fn = (Vfn)((struct Ov208Fsm *)p)->callbacks[4];

    if (fn != 0)
        fn(p, p + 8, ((struct Ov208Fsm *)p)->a, (int)((struct Ov208Fsm *)p)->work, v);
}

void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Fsm *p, u32 size, u32 heap)
{
    p->work = func_02030734(heap, size, 0, d_021C8D80, 0xc8);
    return p->work;
}

void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *p)
{
    func_020307B0(((struct Ov208Fsm *)p)->work);
    ((struct Ov208Fsm *)p)->work = 0;
}
