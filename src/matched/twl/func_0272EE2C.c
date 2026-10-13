/*
 * function: CARD_NotifyRomHashReadAsync
 * address:  0x0272EE2C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   CARDi_StartLoading 0x0272ED4C arm twl
 */
typedef unsigned int u32;

struct Node {
    struct Node *next;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct Obj {
    char pad0[0x20];
    u32 f20;
    u32 f24;
    char pad1[8];
    u32 f30;
    int (*f34)(u32, u32, u32, u32);
    int (*f38)(u32, u32, u32, u32);
    u32 id;
    struct Node *cur;
    struct Node *free_a;
    struct Node *used_a;
    char pad3[4];
    struct Node *free_b;
    struct Node *used_b;
};

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void OS_WakeupThreadDirect(u32);
extern void CARDi_StartLoading(struct Obj *);

void CARD_NotifyRomHashReadAsync(struct Obj *p)
{
    u32 irq = OS_DisableInterrupts();
    struct Node *n = p->free_a;

    if (p->cur == n) {
        p->free_a = n->next;
        n->next = p->used_a;
        p->used_a = n;
    } else {
        n = p->free_b;
        p->free_b = n->next;
        n->next = p->used_b;
        p->used_b = n;
    }
    p->cur = 0;
    OS_RestoreInterrupts(irq);
    OS_WakeupThreadDirect(p->id);
    CARDi_StartLoading(p);
}
