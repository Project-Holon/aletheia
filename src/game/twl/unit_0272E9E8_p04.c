/*
 * file:     unit_0272E9E8_p04.c
 * unit:     yes
 * function: func_0272EFB0, func_0272F0BC, func_0272F368, func_0272F570, func_0272F740
 * address:  0x0272EFB0
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
 *   func_02088234 0x02088234 arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_0272EE98 0x0272EE98 arm twl
 *   func_0272ED4C 0x0272ED4C arm twl
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
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    char pad0b[0xc];
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
    struct Node *cache_a;
    struct Node *free_b;
    struct Node *used_b;
    struct Node *cache_b;
};
extern void func_02088234(void);
extern u32 func_0209C2B0(u32, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern struct Node *func_0272EE98(struct Obj *, u32);
extern void func_0272ED4C(struct Obj *);

u32 func_0272EFB0(struct Obj *obj, u32 addr);
asm void func_0272F0BC(void);
asm void func_0272F368(void);
asm void func_0272F570(void);
asm void func_0272F740(void);

u32 func_0272EFB0(struct Obj *obj, u32 addr)
{
    u32 res = 0;
    u32 off = addr;
    u32 size;
    u32 key;
    struct Node **pp;

    off -= obj->f0;
    size = obj->f4;
    if (off >= size) {
        off += obj->f0 - obj->f8;
        if (off < obj->fc) {
            off += size;
        } else {
            func_02088234();
        }
    }
    key = func_0209C2B0(off, obj->f20);
    pp = &obj->cache_a;
    for (;;) {
        struct Node *n = *pp;
        if (n->f4 == key) {
            *pp = n->next;
            n->next = obj->cache_a;
            obj->cache_a = n;
            res = n->fc;
            break;
        }
        if (n->next == 0) {
            u32 irq = func_02087988();
            struct Node *t = *pp;
            struct Node *l;
            struct Node *q;
            *pp = 0;
            q = obj->free_a;
            l = (struct Node *)&obj->free_a;
            while (q != 0) {
                l = q;
                q = q->next;
            }
            l->next = t;
            t->f4 = key;
            t->f8 = addr & ~(obj->f20 - 1);
            func_0208799C(irq);
            func_0272EE98(obj, key);
            func_0272ED4C(obj);
            break;
        }
        pp = (struct Node **)n;
    }
    return res;
}

asm void func_0272F0BC(void)
{
}

asm void func_0272F368(void)
{
}

asm void func_0272F570(void)
{
}

asm void func_0272F740(void)
{
}
