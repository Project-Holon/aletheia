/*
 * file:     unit_0272E9E8_p03.c
 * unit:     yes
 * function: func_0272F368, func_0272F570, func_0272F740, func_0272F804, func_0272F8A8, func_0272F9C4
 * address:  0x0272F368
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
 *   data_02150FEC 0x02150FEC data
 *   func_02087B04 0x02087B04 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020857B0 0x020857B0 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02088234 0x02088234 arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_0272EFB0 0x0272EFB0 arm twl
 *   func_0272EE98 0x0272EE98 arm twl
 *   func_0272EC38 0x0272EC38 arm twl
 *   func_0272F570 0x0272F570 arm twl
 *   func_0272F368 0x0272F368 arm twl
 *   func_0272FD40 0x0272FD40 arm twl
 *   func_020848EC 0x020848EC arm
 *   func_0272F804 0x0272F804 arm twl
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
extern struct Node *func_0272EE98(struct Obj *, u32);
extern void func_0272ED4C(struct Obj *);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_020857B0(int);
extern void func_0272EC38(u32 *expect, void *data, u32 len);
extern int func_02087B04(void);
struct IdSrc {
    u32 f0;
    u32 id;
};
extern struct IdSrc data_02150FEC;
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_0272FD40(int);
u32 func_0272F804(u32 type);
struct Cfg {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};


struct NdmaCh {
    u32 src;
    u32 dst;
    u32 total;
    u32 block;
    u32 intv;
    u32 fill;
    u32 ctrl;
};
#define NDMA ((volatile struct NdmaCh *)0x04004104)

void func_0272F368(struct Obj *obj, u8 *buf, u32 off, u32 len);
void func_0272F570(struct Obj *obj, u8 *buf, u32 off, u32 len);
void func_0272F740(struct Obj *obj, u8 *buf, u32 off, u32 len);
void func_0272F8A8(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, struct Cfg *cfg, int words, u32 flags);
void func_0272F9C4(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, struct Cfg *cfg, int words, u32 flags);
extern void func_020848EC(u32 ch, void (*cb)(), u32 arg);

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

void func_0272F740(struct Obj *obj, u8 *buf, u32 off, u32 len)
{
    u32 mask;
    u32 head;
    u32 bulk;

    obj->id = data_02150FEC.id;
    obj->cur = 0;
    if (len >= obj->f20 << 4 && func_02087B04() != 1) {
        mask = obj->f20 - 1;
        head = mask & (obj->f20 - off);
        bulk = ~mask & (len - head);
        if (head != 0) {
            func_0272F570(obj, buf, off, head);
            off += head;
            len -= head;
            buf += head;
        }
        if (bulk != 0) {
            func_0272F368(obj, buf, off, bulk);
            off += bulk;
            len -= bulk;
            buf += bulk;
        }
    }
    func_0272F570(obj, buf, off, len);
}

u32 func_0272F804(u32 type)
{
    switch (type) {
    case 0:
        return 0x6000;
    case 1:
        return 0;
    case 2:
    case 8:
        return 0x800;
    case 9:
        return 0x40000800;
    case 3:
        return 0x4000;
    case 4:
        return 0x4800;
    case 10:
        return 0x60005000;
    case 5:
        return 0x20001000;
    case 6:
        return 0x60001000;
    case 7:
        return 0x20000800;
    default:
        return 0;
    }
}


void func_0272F8A8(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, struct Cfg *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        return;
    }
    irq = func_02087988();
    func_0272FD40(ch);
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->unk0 | cfg->unk4;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->unkC != -1) {
            w = cfg->unkC;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->unk8 | (flags & 0x80000000);
    ctrl |= func_0272F804(mode);
    NDMA[ch].ctrl = ctrl | (words == -1 ? 0x10000000 : words);
    func_0272FD40(ch);
    func_0208799C(irq);
}


void func_0272F9C4(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, void (*cb)(), u32 arg, struct Cfg *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    irq = func_02087988();
    func_0272FD40(ch);
    if (cb != 0) {
        func_020848EC(ch, cb, arg);
    }
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->unk0 | cfg->unk4;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->unkC != -1) {
            w = cfg->unkC;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->unk8 | (flags & 0x80000000);
    ctrl |= func_0272F804(mode);
    ctrl |= (words == -1 ? 0x10000000 : words);
    if (cb != 0) {
        ctrl |= 0x40000000;
    }
    NDMA[ch].ctrl = ctrl;
    func_0208799C(irq);
}
