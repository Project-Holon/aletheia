/*
 * function: CARD_InitRomHashContext
 * address:  0x0272F0BC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_0272EB9C 0x0272EB9C data twl
 *   data_02732E98 0x02732E98 data twl
 *   data_02732E34 0x02732E34 data twl
 *   CARDi_CompareHash  0x0272EC38  arm
 *
 * Built with IRO common-subexpression elimination off for this function
 * (#pragma opt_common_subs off ... reset). With CSE on, m + i * 20 in the
 * last loop and the key byte in the pad loop become CSE temps and the
 * registers of both loops, the obj field store order and the loop-3
 * preheader differ (38 bytes). hsz is read before the obj->hash store so
 * the load is not propagated into the l0 sum; that keeps base + 0x1f in r1.
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
struct Node16 {
    struct Node16 *next;
    int f4;
    u32 f8;
    u32 fc;
};
struct Hdr {
    char pad0[0x1e0];
    u32 f1e0, f1e4, f1e8, f1ec, f1f0, f1f4, f1f8, f1fc, f200, f204;
    char pad1[0x328 - 0x208];
    u32 digest[5];
};
struct Obj {
    u32 f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c;
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
    u8 *l0;
    u8 *l1;
    struct Node16 *l2;
    struct Node *l3;
};

extern void func_02088234(void);
extern void func_02082A7C(u32 v, void *dst, u32 n);
extern void func_020911D8(void *ctx);
extern void func_02091200(void *ctx, void *data, u32 len);
extern void CARDi_CompareHash(const u32 *expect, void *data, u32 len);
extern u8 data_0272EB9C[];
extern u8 data_02732E98[], data_02732E34[];

#pragma opt_common_subs off
void CARD_InitRomHashContext(struct Obj *obj, const struct Hdr *hdr, u32 base, u32 size,
                   int (*cb34)(u32, void *, u32, u32),
                   int (*cb38)(u32, void *, u32, u32), u32 arg30)
{
    u8 ipad[0x40];
    u8 opad[0x40];
    u32 psz, per, hsz;
    u8 *start, *l0, *l1, *l2, *l3;
    int i;
    per = hdr->f204;
    psz = hdr->f200;
    hsz = hdr->f1fc;
    start = (u8 *)((base + 0x1f) & ~0x1f);
    size = (u32)(start + size) & ~0x1f;
    obj->hash = start;
    l0 = start + ((hsz + 0x1f) & ~0x1f);
    obj->l0 = l0;
    l1 = l0 + (((psz << 5) + 0x1f) & ~0x1f);
    obj->l1 = l1;
    l2 = l1 + (((((per * 0x14 + 0xff + 0x500) & -0x600) << 2) + 0x1f) & ~0x1f);
    obj->l2 = (struct Node16 *)l2;
    l3 = l2 + 0x200;
    obj->l3 = (struct Node *)l3;
    if ((u32)(l3 + 0x60) > size) {
        func_02088234();
        return;
    }
    func_02082A7C(0, start, l3 + 0x60 - start);
    obj->f0 = hdr->f1e0;
    obj->f4 = hdr->f1e4;
    obj->f8 = hdr->f1e8;
    obj->fc = hdr->f1ec;
    obj->f10 = hdr->f1f0;
    obj->f14 = hdr->f1f4;
    obj->f18 = hdr->f1f8;
    obj->f1c = hdr->f1fc;
    obj->f20 = psz;
    obj->f24 = per;
    obj->f28 = 4;
    obj->f2c = 0x20;
    obj->f34 = cb34;
    obj->f38 = cb38;
    obj->f30 = arg30;
    for (i = 0; (i < 0x40) ? 1 : 0; i++) {
        ipad[i] = data_0272EB9C[i] ^ 0x36;
        opad[i] = data_0272EB9C[i] ^ 0x5c;
    }
    func_020911D8(data_02732E98);
    func_020911D8(data_02732E34);
    func_02091200(data_02732E98, ipad, 0x40);
    func_02091200(data_02732E34, opad, 0x40);
    obj->f34(obj->f30, obj->hash, obj->f18, obj->f1c);
    CARDi_CompareHash(hdr->digest, obj->hash, obj->f1c);
    {
        struct Node16 *n = obj->l2;
        for (i = 0; (i < obj->f2c) ? 1 : 0; i++) {
            n[i].next = n + (i - 1);
            n[i].fc = (u32)obj->l0 + i * obj->f20;
            n[i].f4 = -1;
        }
    }
    {
        struct Node *m;
        obj->l2->next = 0;
        obj->cache_a = (struct Node *)((struct Node16 *)obj->l2 + (obj->f2c - 1));
        obj->free_a = 0;
        obj->used_a = 0;
        m = (struct Node *)obj->l3;
        for (i = 0; (i < obj->f28) ? 1 : 0; i++) {
            m[i].next = m + (i + 1);
            m[i].f4 = -1;
            m[i].f10 = (u32)obj->l1 + i * ((((int)per * 0x14 + 0xff + 0x500) & -0x600));
        }
        obj->cache_b = obj->l3;
        obj->l3[obj->f28 - 1].next = 0;
        obj->free_b = 0;
        obj->used_b = 0;
    }
}
#pragma opt_common_subs reset
