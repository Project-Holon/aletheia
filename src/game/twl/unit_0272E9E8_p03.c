/*
 * file:     unit_0272E9E8_p03.c
 * unit:     yes
 * function: func_0272ED4C, func_0272EE2C, func_0272EE98
 * address:  0x0272ED4C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02085868 0x02085868 arm
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

extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_02085868(u32);

void func_0272ED4C(struct Obj *p);
void func_0272EE2C(struct Obj *p);
asm void func_0272EE98(void);

void func_0272ED4C(struct Obj *p)
{
    u32 a = 0;
    u32 b = a;
    u32 c = a;
    u32 irq = func_02087988();

    if (p->cur == 0) {
        struct Node *q = p->free_b;
        if (q != 0) {
            u32 v = q->f8;
            u32 sz = v & 0x1FF;
            q->fc = q->f10 + sz;
            p->cur = q;
            b = v - sz;
            c = (p->f24 * 20 + sz + 0x1FF) & ~0x1FF;
            a = q->f10;
        } else {
            q = p->free_a;
            if (q != 0) {
                p->cur = q;
                a = q->fc;
                b = q->f8;
                c = p->f20;
            }
        }
    }
    func_0208799C(irq);
    if (a != 0) {
        if (p->f38(p->f30, a, b, c) != 0) {
            return;
        }
        p->f34(p->f30, a, b, c);
        func_0272EE2C(p);
    }
}

void func_0272EE2C(struct Obj *p)
{
    u32 irq = func_02087988();
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
    func_0208799C(irq);
    func_02085868(p->id);
    func_0272ED4C(p);
}

asm void func_0272EE98(void)
{
}
