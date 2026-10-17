/*
 * file:     card_hash.c
 * unit:     yes
 * function: CARD_CalcRomHashBufferLength, CARDi_CompareHash, CARDi_StartLoading, CARD_NotifyRomHashReadAsync, CARDi_TouchRomHashBlock, CARDi_TouchRomHashSector, CARD_InitRomHashContext, CARDi_ReadRomHashImageDirect, CARDi_ReadRomHashImageCaching, CARD_ReadRomHashImage
 * address:  0x0272EBDC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcard.TWL.HYB.a card_hash.o
 *
 * symbols:
 *   data_02732E98  0x02732E98  data twl
 *   data_02732E34  0x02732E34  data twl
 *   MI_CpuCopy8  0x02082D44  arm
 *   MSL_C_LIB_TwlCall3  0x02091200  thumb
 *   MSL_C_LIB_TwlCall2  0x02091230  thumb
 *   OS_GetBootType  0x02087B04  arm
 *   CARD_IsPulledOut  0x020774B0  arm
 *   MI_CpuFill  0x02082C60  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   data_02150FEC  0x02150FEC  data
 *   OS_SleepThread  0x020857B0  arm
 *   OSi_EnterNDmaCallback  0x020848EC  arm
 *   MIi_GetControlData  0x0272F804  arm twl
 *   MSL_C_LIB_TwlCall1  0x020911D8  thumb  arm9
 */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    struct Node *next;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
} Node;

typedef struct Node16 {
    struct Node16 *next;
    int f4;
    u32 f8;
    u32 fc;
} Node16;

/* ROM header fields read by CARD_InitRomHashContext */
typedef struct {
    char pad0[0x1e0];
    u32 f1e0, f1e4, f1e8, f1ec, f1f0, f1f4, f1f8, f1fc, f200, f204;
    char pad1[0x328 - 0x208];
    u32 digest[5];
} RomHdr;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    int (*f34)(u32, void *, u32, u32);
    int (*f38)(u32, void *, u32, u32);
    u32 id;
    Node *cur;
    Node *free_a;
    Node *used_a;
    Node *cache_a;
    Node *free_b;
    Node *used_b;
    Node *cache_b;
    u8 *hash;
    u8 *l0;
    u8 *l1;
    Node16 *l2;
    Node *l3;
} CardHash;

typedef struct {
    u32 f0;
    u32 id;
} IdSrc;

typedef struct {
    char pad[0x1fc];
    u32 c;
    u32 b;
    u32 a;
} SizeHdr;

extern IdSrc data_02150FEC;
extern u32 data_02732E98[], data_02732E34[];
extern u8 data_0272EB9C[];
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void func_02082A7C(u32 v, void *dst, u32 n);
extern void MSL_C_LIB_TwlCall3(void *ctx, void *data, u32 len);
extern void MSL_C_LIB_TwlCall2(void *ctx, void *out);
extern void MSL_C_LIB_TwlCall1(void *ctx);
extern int OS_GetBootType(void);
extern void *CARD_IsPulledOut(void);
extern void MI_CpuFill(void *p, int v, u32 n);
extern void OS_Terminate(void);
extern u32 _u32_div_f(u32, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void OS_WakeupThreadDirect(u32);
extern void OS_SleepThread(int);

u32 CARD_CalcRomHashBufferLength(void *p);
void CARDi_CompareHash(const u32 *expect, void *data, u32 len);
void CARDi_StartLoading(CardHash *p);
void CARD_NotifyRomHashReadAsync(CardHash *p);
Node *CARDi_TouchRomHashBlock(CardHash *obj, u32 a);
u32 CARDi_TouchRomHashSector(CardHash *obj, u32 addr);
void CARD_InitRomHashContext(CardHash *obj, const RomHdr *hdr, u32 base, u32 size,
                   int (*cb34)(u32, void *, u32, u32),
                   int (*cb38)(u32, void *, u32, u32), u32 arg30);
void CARDi_ReadRomHashImageDirect(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARDi_ReadRomHashImageCaching(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARD_ReadRomHashImage(CardHash *obj, u8 *buf, u32 off, u32 len);

u32 CARD_CalcRomHashBufferLength(void *p)
{
    SizeHdr *hdr = p;
    u32 per = hdr->a * 0x14;
    u8 *start = 0;
    u8 *q = start;
    q += (hdr->c + 0x1f) & ~0x1f;
    q += ((hdr->b << 5) + 0x1f) & ~0x1f;
    q += (((((per + 0xff + 0x500) & (u32)(start - 0x600)) << 2) + 0x1f) & ~0x1f);
    return (u32)q + 0x260;
}

void CARDi_CompareHash(const u32 *expect, void *data, u32 len)
{
    unsigned char dbuf[20];
    u32 *digest = (u32 *)dbuf;
    unsigned char ctx[0x64];
    u32 diff = 0;

    MI_CpuCopy8(data_02732E98, ctx, 0x64);
    MSL_C_LIB_TwlCall3(ctx, data, len);
    MSL_C_LIB_TwlCall2(ctx, digest);
    MI_CpuCopy8(data_02732E34, ctx, 0x64);
    MSL_C_LIB_TwlCall3(ctx, digest, 0x14);
    MSL_C_LIB_TwlCall2(ctx, digest);
    diff |= expect[0] ^ digest[0];
    diff |= expect[1] ^ digest[1];
    diff |= expect[2] ^ digest[2];
    diff |= expect[3] ^ digest[3];
    diff |= expect[4] ^ digest[4];
    if (diff == 0)
        return;
    if (OS_GetBootType() == 1 && CARD_IsPulledOut() != 0) {
        MI_CpuFill(data, 0, len);
        return;
    }
    OS_Terminate();
}

void CARDi_StartLoading(CardHash *p)
{
    void *a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 irq = OS_DisableInterrupts();

    if (p->cur == 0) {
        Node *q = p->free_b;
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

void CARD_NotifyRomHashReadAsync(CardHash *p)
{
    u32 irq = OS_DisableInterrupts();
    Node *n = p->free_a;

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

Node *CARDi_TouchRomHashBlock(CardHash *obj, u32 a)
{
    u32 key = _u32_div_f(a, obj->f24);
    Node *res;
    Node *tail;
    Node **pp = &obj->cache_b;

    for (;;) {
        tail = *pp;
        res = tail;
        if (tail->f4 == key) {
            *pp = tail->next;
            tail->next = obj->cache_b;
            obj->cache_b = tail;
            break;
        } else if (tail->next == 0) {
            u32 irq = OS_DisableInterrupts();
            Node *n = obj->used_b;
            Node *link;
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
                link = (Node *)&obj->free_b;
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
            OS_RestoreInterrupts(irq);
            if (tail != 0) {
                CARDi_StartLoading(obj);
            }
            break;
        } else {
            pp = (Node **)tail;
        }
    }
    return res;
}

u32 CARDi_TouchRomHashSector(CardHash *obj, u32 addr)
{
    u32 res = 0;
    u32 off = addr;
    u32 size;
    u32 key;
    Node **pp;

    off -= obj->f0;
    size = obj->f4;
    if (off >= size) {
        off += obj->f0 - obj->f8;
        if (off < obj->fc) {
            off += size;
        } else {
            OS_Terminate();
        }
    }
    key = _u32_div_f(off, obj->f20);
    pp = &obj->cache_a;
    for (;;) {
        Node *n = *pp;
        if (n->f4 == key) {
            *pp = n->next;
            n->next = obj->cache_a;
            obj->cache_a = n;
            res = n->fc;
            break;
        }
        if (n->next == 0) {
            u32 irq = OS_DisableInterrupts();
            Node *t = *pp;
            Node *l;
            Node *q;
            *pp = 0;
            q = obj->free_a;
            l = (Node *)&obj->free_a;
            while (q != 0) {
                l = q;
                q = q->next;
            }
            l->next = t;
            t->f4 = key;
            t->f8 = addr & ~(obj->f20 - 1);
            OS_RestoreInterrupts(irq);
            CARDi_TouchRomHashBlock(obj, key);
            CARDi_StartLoading(obj);
            break;
        }
        pp = (Node **)n;
    }
    return res;
}

#pragma opt_common_subs off
void CARD_InitRomHashContext(CardHash *obj, const RomHdr *hdr, u32 base, u32 size,
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
    obj->l2 = (Node16 *)l2;
    l3 = l2 + 0x200;
    obj->l3 = (Node *)l3;
    if ((u32)(l3 + 0x60) > size) {
        OS_Terminate();
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
    MSL_C_LIB_TwlCall1(data_02732E98);
    MSL_C_LIB_TwlCall1(data_02732E34);
    MSL_C_LIB_TwlCall3(data_02732E98, ipad, 0x40);
    MSL_C_LIB_TwlCall3(data_02732E34, opad, 0x40);
    obj->f34(obj->f30, obj->hash, obj->f18, obj->f1c);
    CARDi_CompareHash(hdr->digest, obj->hash, obj->f1c);
    {
        Node16 *n = obj->l2;
        for (i = 0; (i < obj->f2c) ? 1 : 0; i++) {
            n[i].next = n + (i - 1);
            n[i].fc = (u32)obj->l0 + i * obj->f20;
            n[i].f4 = -1;
        }
    }
    {
        Node *m;
        obj->l2->next = 0;
        obj->cache_a = (Node *)((Node16 *)obj->l2 + (obj->f2c - 1));
        obj->free_a = 0;
        obj->used_a = 0;
        m = (Node *)obj->l3;
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

void CARDi_ReadRomHashImageDirect(CardHash *obj, u8 *buf, u32 off, u32 len)
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
            OS_Terminate();
        }
    }
    key = _u32_div_f(a, obj->f20);
    while (off < end) {
        u32 n;

        n = obj->f34(obj->f30, buf, off, end - off);
        CARDi_TouchRomHashBlock(obj, key);
        if (obj->f38 != 0 && off + n < end) {
            obj->f38(obj->f30, 0, off + n, end - (off + n));
        }
        while (n >= psz) {
            Node *node = CARDi_TouchRomHashBlock(obj, key);
            u32 idx = key - node->f4 * per;

            for (; idx < per && n >= psz; idx++, key++) {
                if (node != obj->cache_b) {
                    u32 irq = OS_DisableInterrupts();

                    while (obj->free_b != 0) {
                        OS_SleepThread(0);
                    }
                    if (node == obj->used_b) {
                        obj->used_b = node->next;
                    }
                    OS_RestoreInterrupts(irq);
                    CARDi_CompareHash((u32 *)(obj->hash + node->f4 * 0x14), (void *)node->fc, per * 0x14);
                    node->next = obj->cache_b;
                    obj->cache_b = node;
                }
                CARDi_CompareHash((u32 *)(node->fc + idx * 0x14), buf, psz);
                n -= psz;
                off += psz;
                buf += psz;
            }
        }
    }
}

void CARDi_ReadRomHashImageCaching(CardHash *obj, u8 *buf, u32 off, u32 len)
{
    while (len != 0) {
        u32 page = CARDi_TouchRomHashSector(obj, off);

        if (page != 0) {
            u32 pos = off - (off & ~(obj->f20 - 1));
            u32 n = obj->f20 - pos;

            if (len <= n) {
                n = len;
            }
            MI_CpuCopy8((u8 *)page + pos, buf, n);
            len -= n;
            buf += n;
            off += n;
        } else {
            u32 a = off & ~(obj->f20 - 1);
            u32 end = off + len;
            u32 irq;
            Node *nb;
            Node *na;

            while (obj->cache_a != 0 && obj->cache_b != 0) {
                a += obj->f20;
                if (a >= end) {
                    break;
                }
                CARDi_TouchRomHashSector(obj, a);
            }
            for (;;) {
                irq = OS_DisableInterrupts();
                na = 0;
                while ((obj->free_a != 0 && obj->used_a == 0) || (obj->free_b != 0 && obj->used_b == 0)) {
                    OS_SleepThread(0);
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
                OS_RestoreInterrupts(irq);
                if (nb != 0) {
                    CARDi_CompareHash((u32 *)(obj->hash + nb->f4 * 0x14), (void *)nb->fc, obj->f24 * 0x14);
                    nb->next = obj->cache_b;
                    obj->cache_b = nb;
                } else if (na != 0) {
                    Node *h = CARDi_TouchRomHashBlock(obj, na->f4);
                    CARDi_CompareHash((u32 *)(h->fc + (na->f4 - h->f4 * obj->f24) * 0x14), (void *)na->fc, obj->f20);
                    na->next = obj->cache_a;
                    obj->cache_a = na;
                } else {
                    break;
                }
            }
        }
    }
}

void CARD_ReadRomHashImage(CardHash *obj, u8 *buf, u32 off, u32 len)
{
    u32 mask;
    u32 head;
    u32 bulk;

    obj->id = data_02150FEC.id;
    obj->cur = 0;
    if (len >= obj->f20 << 4 && OS_GetBootType() != 1) {
        mask = obj->f20 - 1;
        head = mask & (obj->f20 - off);
        bulk = ~mask & (len - head);
        if (head != 0) {
            CARDi_ReadRomHashImageCaching(obj, buf, off, head);
            off += head;
            len -= head;
            buf += head;
        }
        if (bulk != 0) {
            CARDi_ReadRomHashImageDirect(obj, buf, off, bulk);
            off += bulk;
            len -= bulk;
            buf += bulk;
        }
    }
    CARDi_ReadRomHashImageCaching(obj, buf, off, len);
}
