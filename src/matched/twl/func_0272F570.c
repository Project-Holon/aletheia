/*
 * function: func_0272F570
 * address:  0x0272F570
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_020857B0 0x020857B0 arm
 *   func_0272EFB0 0x0272EFB0 arm twl
 *   func_0272EE98 0x0272EE98 arm twl
 *   func_0272EC38 0x0272EC38 arm twl
 */
typedef unsigned int u32;
typedef unsigned char u8;
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
    u8 *hash;
};

extern void func_02082D44(const void *src, void *dst, u32 n);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020857B0(int);
extern u32 func_0272EFB0(struct Obj *obj, u32 off);
extern struct Node *func_0272EE98(struct Obj *obj, u32 key);
extern void func_0272EC38(u32 *expect, void *data, u32 len);

void func_0272F570(struct Obj *obj, u8 *buf, u32 off, u32 len)
{
    while (len != 0) {
        u32 page = func_0272EFB0(obj, off);

        if (page != 0) {
            u32 pos = off - (off & ~(obj->f20 - 1));
            u32 n = obj->f20 - pos;

            if (len <= n) {
                n = len;
            }
            func_02082D44((u8 *)page + pos, buf, n);
            len -= n;
            buf += n;
            off += n;
        } else {
            u32 a = off & ~(obj->f20 - 1);
            u32 end = off + len;
            u32 irq;
            struct Node *nb;
            struct Node *na;

            while (obj->cache_a != 0 && obj->cache_b != 0) {
                a += obj->f20;
                if (a >= end) {
                    break;
                }
                func_0272EFB0(obj, a);
            }
            for (;;) {
                irq = func_02087988();
                na = 0;
                while ((obj->free_a != 0 && obj->used_a == 0) || (obj->free_b != 0 && obj->used_b == 0)) {
                    func_020857B0(0);
                }
                nb = obj->used_b;
                if (nb != 0) {
                    obj->used_b = nb->next;
                } else {
                    na = obj->used_a;
                    if (na != 0) {
                        obj->used_a = na->next;
                    }
                }
                func_0208799C(irq);
                if (nb != 0) {
                    func_0272EC38((u32 *)(obj->hash + nb->f4 * 0x14), (void *)nb->fc, obj->f24 * 0x14);
                    nb->next = obj->cache_b;
                    obj->cache_b = nb;
                } else if (na != 0) {
                    struct Node *h = func_0272EE98(obj, na->f4);
                    func_0272EC38((u32 *)(h->fc + (na->f4 - h->f4 * obj->f24) * 0x14), (void *)na->fc, obj->f20);
                    na->next = obj->cache_a;
                    obj->cache_a = na;
                } else {
                    break;
                }
            }
        }
    }
}
