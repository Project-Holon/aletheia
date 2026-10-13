/*
 * function: CARDi_StartLoading
 * address:  0x0272ED4C
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
 *   CARD_NotifyRomHashReadAsync 0x0272EE2C arm twl
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
    int (*f34)(u32, void *, u32, u32);
    int (*f38)(u32, void *, u32, u32);
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
extern void CARD_NotifyRomHashReadAsync(struct Obj *);

void CARDi_StartLoading(struct Obj *p)
{
    void *a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 irq = OS_DisableInterrupts();

    if (p->cur == 0) {
        struct Node *q = p->free_b;
        if (q != 0) {
            u32 v = q->f8;
            u32 sz = v & 0x1FF;
            q->fc = q->f10 + sz;
            p->cur = q;
            b = v - sz;
            c = (p->f24 * 20 + sz + 0x1FF) & ~0x1FF;
            a = (void *)q->f10;
        } else {
            q = p->free_a;
            if (q != 0) {
                p->cur = q;
                a = (void *)q->fc;
                b = q->f8;
                c = p->f20;
            }
        }
    }
    OS_RestoreInterrupts(irq);
    if (a != 0) {
        if (p->f38(p->f30, a, b, c) != 0) {
            return;
        }
        p->f34(p->f30, a, b, c);
        CARD_NotifyRomHashReadAsync(p);
    }
}
