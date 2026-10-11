/*
 * file:     unit_0272E9E8_p02.c
 * unit:     yes
 * function: func_0272EBDC, func_0272EC38, func_0272ED4C, func_0272EE2C, func_0272EE98, func_0272EFB0, func_0272F0BC
 * address:  0x0272EBDC
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
 *   data_02732E98 0x02732E98 data twl
 *   data_02732E34 0x02732E34 data twl
 *   func_02082D44 0x02082D44 arm
 *   func_02091200 0x02091200 thumb
 *   func_02091230 0x02091230 thumb
 *   func_02087B04 0x02087B04 arm
 *   func_020774B0 0x020774B0 arm
 *   func_02082C60 0x02082C60 arm
 *   func_02088234 0x02088234 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02085868 0x02085868 arm
 *   func_0209C2B0 0x0209C2B0 arm
 */
typedef unsigned int u32;

struct Node {
    struct Node *next;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct Obj_0272EBDC {
    char pad0[0x10];
    u32 f10;
    char pad0b[0xc];
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
    struct Node *used_c;
};

typedef unsigned char u8;

struct Obj_0272EFB0 {
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
    int (*f34)(u32, void *, u32, u32);
    int (*f38)(u32, void *, u32, u32);
    u32 id;
    struct Node *cur;
    struct Node *free_a;
    struct Node *used_a;
    struct Node *cache_a;
    struct Node *free_b;
    struct Node *used_b;
    struct Node *cache_b;
    u8 *hash;
};

extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02091200(void *ctx, void *data, u32 len);
extern void func_02091230(void *ctx, void *out);
extern int func_02087B04(void);
extern void *func_020774B0(void);
extern void func_02082C60(void *p, int v, u32 n);
extern void func_02088234(void);
extern u32 func_0209C2B0(u32, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_02085868(u32);
asm u32 func_0272EBDC(void *r0);
void func_0272EC38(u32 *expect, void *data, u32 len);
void func_0272ED4C(struct Obj_0272EBDC *p);
void func_0272EE2C(struct Obj_0272EBDC *p);
struct Node *func_0272EE98(struct Obj_0272EBDC *obj, u32 a);
u32 func_0272EFB0(struct Obj_0272EFB0 *obj, u32 addr);
asm void func_0272F0BC(void);
extern u32 data_02732E98[], data_02732E34[];



asm u32 func_0272EBDC(void *r0)
{
    ldr r2, [r0, #0x204]
    mov r1, #0x14
    mul r1, r2, r1
    add r1, r1, #0xff
    ldr r2, [r0, #0x1fc]
    ldr r0, [r0, #0x200]
    mov ip, #0
    add r2, r2, #0x1f
    mov r0, r0, lsl #5
    bic r3, r2, #0x1f
    add r2, r0, #0x1f
    add r1, r1, #0x500
    sub r0, ip, #0x600
    and r0, r1, r0
    mov r0, r0, lsl #2
    add r0, r0, #0x1f
    add r3, r3, #0
    bic r1, r2, #0x1f
    add r1, r3, r1
    bic r0, r0, #0x1f
    add r0, r1, r0
    add r0, r0, #0x260
    bx lr
}



void func_0272EC38(u32 *expect, void *data, u32 len)
{
    unsigned char dbuf[20];
    u32 *digest = (u32 *)dbuf;
    unsigned char ctx[0x64];
    u32 diff = 0;

    func_02082D44(data_02732E98, ctx, 0x64);
    func_02091200(ctx, data, len);
    func_02091230(ctx, digest);
    func_02082D44(data_02732E34, ctx, 0x64);
    func_02091200(ctx, digest, 0x14);
    func_02091230(ctx, digest);
    diff |= expect[0] ^ digest[0];
    diff |= expect[1] ^ digest[1];
    diff |= expect[2] ^ digest[2];
    diff |= expect[3] ^ digest[3];
    diff |= expect[4] ^ digest[4];
    if (diff == 0)
        return;
    if (func_02087B04() == 1 && func_020774B0() != 0) {
        func_02082C60(data, 0, len);
        return;
    }
    func_02088234();
}



void func_0272ED4C(struct Obj_0272EBDC *p)
{
    void *a = 0;
    u32 b = 0;
    u32 c = 0;
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
    func_0208799C(irq);
    if (a != 0) {
        if (p->f38(p->f30, a, b, c) != 0) {
            return;
        }
        p->f34(p->f30, a, b, c);
        func_0272EE2C((struct Obj_0272EBDC *)p);
    }
}



void func_0272EE2C(struct Obj_0272EBDC *p)
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
    func_0272ED4C((struct Obj_0272EBDC *)p);
}



struct Node *func_0272EE98(struct Obj_0272EBDC *obj, u32 a)
{
    u32 key = func_0209C2B0(a, obj->f24);
    struct Node *res;
    struct Node *tail;
    struct Node **pp = &obj->used_c;

    for (;;) {
        tail = *pp;
        res = tail;
        if (tail->f4 == key) {
            *pp = tail->next;
            tail->next = obj->used_c;
            obj->used_c = tail;
            break;
        } else if (tail->next == 0) {
            u32 irq = func_02087988();
            struct Node *n = obj->used_b;
            struct Node *link;
            while (n != 0) {
                if (n->f4 == key) {
                    res = n;
                    tail = 0;
                    break;
                }
                n = n->next;
            }
            if (tail != 0) {
                n = obj->free_b;
                link = (struct Node *)&obj->free_b;
                while (n != 0) {
                    if (n->f4 == key) {
                        res = n;
                        tail = 0;
                        break;
                    }
                    link = n;
                    n = n->next;
                }
                if (tail != 0) {
                    *pp = 0;
                    link->next = tail;
                    tail->f4 = key;
                    tail->f8 = key * (obj->f24 * 0x14) + obj->f10;
                }
            }
            func_0208799C(irq);
            if (tail != 0) {
                func_0272ED4C((struct Obj_0272EBDC *)obj);
            }
            break;
        } else {
            pp = (struct Node **)tail;
        }
    }
    return res;
}


u32 func_0272EFB0(struct Obj_0272EFB0 *obj, u32 addr)
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
            func_0272EE98((struct Obj_0272EBDC *)obj, key);
            func_0272ED4C((struct Obj_0272EBDC *)obj);
            break;
        }
        pp = (struct Node **)n;
    }
    return res;
}


asm void func_0272F0BC(void)
{
}
