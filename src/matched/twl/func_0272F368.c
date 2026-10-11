/*
 * function: func_0272F368
 * address:  0x0272F368
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088234 0x02088234 arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_020857B0 0x020857B0 arm
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

extern void func_02088234(void);
extern u32 func_0209C2B0(u32, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020857B0(int);
extern struct Node *func_0272EE98(struct Obj *obj, u32 key);
extern void func_0272EC38(u32 *expect, void *data, u32 len);

void func_0272F368(struct Obj *obj, u8 *buf, u32 off, u32 len)
{
    u32 psz = obj->f20;
    u32 per = obj->f24;
    u32 end = len + off;
    u32 a = off;
    u32 size;
    u32 key;

    a -= obj->f0;
    size = obj->f4;
    if (a >= size) {
        a += obj->f0 - obj->f8;
        if (a < obj->fc) {
            a += size;
        } else {
            func_02088234();
        }
    }
    key = func_0209C2B0(a, obj->f20);
    while (off < end) {
        u32 n;

        n = obj->f34(obj->f30, buf, off, end - off);
        func_0272EE98(obj, key);
        if (obj->f38 != 0 && off + n < end) {
            obj->f38(obj->f30, 0, off + n, end - (off + n));
        }
        while (n >= psz) {
            struct Node *node = func_0272EE98(obj, key);
            u32 idx = key - node->f4 * per;

            for (; idx < per && n >= psz; idx++, key++) {
                if (node != obj->cache_b) {
                    u32 irq = func_02087988();

                    while (obj->free_b != 0) {
                        func_020857B0(0);
                    }
                    if (node == obj->used_b) {
                        obj->used_b = node->next;
                    }
                    func_0208799C(irq);
                    func_0272EC38((u32 *)(obj->hash + node->f4 * 0x14), (void *)node->fc, per * 0x14);
                    node->next = obj->cache_b;
                    obj->cache_b = node;
                }
                func_0272EC38((u32 *)(node->fc + idx * 0x14), buf, psz);
                n -= psz;
                off += psz;
                buf += psz;
            }
        }
    }
}
