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
 *   OSi_ThreadInfo  0x02150FEC  data
 *   OS_SleepThread  0x020857B0  arm
 *   OSi_EnterNDmaCallback  0x020848EC  arm
 *   MIi_GetControlData  0x0272F804  arm twl
 *   MSL_C_LIB_TwlCall1  0x020911D8  thumb  arm9
 *   MIi_CpuClear32  0x02082A7C  arm  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 *   data_0272EB9C                0x0272EB9C  data
 */
#include "../types.h"
#include "card_hash.h"

typedef struct {
    char pad[0x1fc];
    u32 c;
    u32 b;
    u32 a;
} SizeHdr;

extern u32 data_02732E98[], data_02732E34[];
extern u8 data_0272EB9C[];
#include "../arm9/mi_memory.h"
#include "../arm9/msl_crt.h"
#include "../arm9/os_systemwork.h"
#include "../arm9/card_pullout.h"
#include "../arm9/os_terminate_processor.h"
#include "../arm9/os_system.h"

u32 CARD_CalcRomHashBufferLength(const void *p);
void CARDi_CompareHash(const u32 *expect, void *data, u32 len);
void CARDi_StartLoading(CardHash *p);
void CARD_NotifyRomHashReadAsync(void *arg);
CardHashNode *CARDi_TouchRomHashBlock(CardHash *obj, u32 a);
u32 CARDi_TouchRomHashSector(CardHash *obj, u32 addr);
void CARD_InitRomHashContext(CardHash *obj, const RomHdr *hdr, u32 base, u32 size,
                   int (*cb34)(void *, void *, u32, u32),
                   int (*cb38)(void *, void *, u32, u32), void *arg30);
void CARDi_ReadRomHashImageDirect(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARDi_ReadRomHashImageCaching(CardHash *obj, u8 *buf, u32 off, u32 len);
void CARD_ReadRomHashImage(CardHash *obj, u8 *buf, u32 off, u32 len);

u32 CARD_CalcRomHashBufferLength(const void *romHeader)
{
    const SizeHdr *hdr = romHeader;
    u32 per = hdr->a * 0x14;
    u8 *start = 0;
    u8 *q = start;
    q += (hdr->c + 0x1f) & ~0x1f;
    q += ((hdr->b << 5) + 0x1f) & ~0x1f;
    q += (((((per + 0xff + 0x500) & (uptr)(start - 0x600)) << 2) + 0x1f) & ~0x1f);
    return (uptr)q + 0x260;
}

void CARDi_CompareHash(const u32 *expect, void *data, u32 len)
{
    unsigned char dbuf[20];
    u32 *digest = (u32 *)dbuf;
    unsigned char ctx[0x64];
    u32 diff = 0;

    MI_CpuCopy8(data_02732E98, ctx, 0x64);
    MSL_C_LIB_TwlCall3((uptr)ctx, (uptr)data, len);
    MSL_C_LIB_TwlCall2((uptr)ctx, (uptr)digest);
    MI_CpuCopy8(data_02732E34, ctx, 0x64);
    MSL_C_LIB_TwlCall3((uptr)ctx, (uptr)digest, 0x14);
    MSL_C_LIB_TwlCall2((uptr)ctx, (uptr)digest);
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

void CARDi_StartLoading(CardHash *obj)
{
    void *a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 irq = OS_DisableInterrupts();

    if (obj->cur == 0) {
        CardHashNode *q = obj->free_b;
        if (q != 0) {
            u32 v = q->offset;
            u32 sz = v & 0x1FF;
            q->data = q->buffer + sz;
            obj->cur = q;
            b = v - sz;
            c = (obj->blockSectorCount * 20 + sz + 0x1FF) & ~0x1FF;
            a = (void *)q->buffer;
        } else {
            q = obj->free_a;
            if (q != 0) {
                obj->cur = q;
                a = (void *)q->data;
                b = q->offset;
                c = obj->sectorSize;
            }
        }
    }
    OS_RestoreInterrupts(irq);
    if (a != 0) {
        if (obj->asyncReadCallback(obj->userData, a, b, c) != 0) {
            return;
        }
        obj->readCallback(obj->userData, a, b, c);
        CARD_NotifyRomHashReadAsync(obj);
    }
}

void CARD_NotifyRomHashReadAsync(void *arg)
{
    CardHash *obj = arg;
    u32 irq = OS_DisableInterrupts();
    CardHashNode *n = obj->free_a;

    if (obj->cur == n) {
        obj->free_a = n->next;
        n->next = obj->used_a;
        obj->used_a = n;
    } else {
        n = obj->free_b;
        obj->free_b = n->next;
        n->next = obj->used_b;
        obj->used_b = n;
    }
    obj->cur = 0;
    OS_RestoreInterrupts(irq);
    OS_WakeupThreadDirect(obj->thread);
    CARDi_StartLoading(obj);
}

CardHashNode *CARDi_TouchRomHashBlock(CardHash *obj, u32 sector)
{
    u32 key = sector / obj->blockSectorCount;
    CardHashNode *res;
    CardHashNode *tail;
    CardHashNode **pp = &obj->cache_b;

    for (;;) {
        tail = *pp;
        res = tail;
        if (tail->key == key) {
            *pp = tail->next;
            tail->next = obj->cache_b;
            obj->cache_b = tail;
            break;
        } else if (tail->next == 0) {
            u32 irq = OS_DisableInterrupts();
            CardHashNode *n = obj->used_b;
            CardHashNode *link;
            while (n != 0) {
                if (n->key == key) {
                    res = n;
                    tail = 0;
                    break;
                }
                n = n->next;
            }
            if (tail != 0) {
                n = obj->free_b;
                link = (CardHashNode *)&obj->free_b;
                while (n != 0) {
                    if (n->key == key) {
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
                    tail->key = key;
                    tail->offset = key * (obj->blockSectorCount * 0x14) + obj->sectorHashOffset;
                }
            }
            OS_RestoreInterrupts(irq);
            if (tail != 0) {
                CARDi_StartLoading(obj);
            }
            break;
        } else {
            pp = (CardHashNode **)tail;
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
    CardHashNode **pp;

    off -= obj->ntrAreaOffset;
    size = obj->ntrAreaLength;
    if (off >= size) {
        off += obj->ntrAreaOffset - obj->ltdAreaOffset;
        if (off < obj->ltdAreaLength) {
            off += size;
        } else {
            OS_Terminate();
        }
    }
    key = off / obj->sectorSize;
    pp = &obj->cache_a;
    for (;;) {
        CardHashNode *n = *pp;
        if (n->key == key) {
            *pp = n->next;
            n->next = obj->cache_a;
            obj->cache_a = n;
            res = n->data;
            break;
        }
        if (n->next == 0) {
            u32 irq = OS_DisableInterrupts();
            CardHashNode *t = *pp;
            CardHashNode *l;
            CardHashNode *q;
            *pp = 0;
            q = obj->free_a;
            l = (CardHashNode *)&obj->free_a;
            while (q != 0) {
                l = q;
                q = q->next;
            }
            l->next = t;
            t->key = key;
            t->offset = addr & ~(obj->sectorSize - 1);
            OS_RestoreInterrupts(irq);
            CARDi_TouchRomHashBlock(obj, key);
            CARDi_StartLoading(obj);
            break;
        }
        pp = (CardHashNode **)n;
    }
    return res;
}

#pragma opt_common_subs off
void CARD_InitRomHashContext(CardHash *obj, const RomHdr *hdr, u32 base, u32 size,
                   int (*cb34)(void *, void *, u32, u32),
                   int (*cb38)(void *, void *, u32, u32), void *arg30)
{
    u8 ipad[0x40];
    u8 opad[0x40];
    u32 psz, per, hsz;
    u8 *start, *l0, *l1, *l2, *l3;
    int i;
    per = hdr->blockSectorCount;
    psz = hdr->sectorSize;
    hsz = hdr->blockHashLength;
    start = (u8 *)((base + 0x1f) & ~0x1f);
    size = (uptr)(start + size) & ~0x1f;
    obj->hash = start;
    l0 = start + ((hsz + 0x1f) & ~0x1f);
    obj->l0 = l0;
    l1 = l0 + (((psz << 5) + 0x1f) & ~0x1f);
    obj->l1 = l1;
    l2 = l1 + (((((per * 0x14 + 0xff + 0x500) & -0x600) << 2) + 0x1f) & ~0x1f);
    obj->l2 = (Node16 *)l2;
    l3 = l2 + 0x200;
    obj->l3 = (CardHashNode *)l3;
    if ((uptr)(l3 + 0x60) > size) {
        OS_Terminate();
        return;
    }
    MIi_CpuClear32(0, start, l3 + 0x60 - start);
    obj->ntrAreaOffset = hdr->ntrAreaOffset;
    obj->ntrAreaLength = hdr->ntrAreaLength;
    obj->ltdAreaOffset = hdr->ltdAreaOffset;
    obj->ltdAreaLength = hdr->ltdAreaLength;
    obj->sectorHashOffset = hdr->sectorHashOffset;
    obj->sectorHashLength = hdr->sectorHashLength;
    obj->blockHashOffset = hdr->blockHashOffset;
    obj->blockHashLength = hdr->blockHashLength;
    obj->sectorSize = psz;
    obj->blockSectorCount = per;
    obj->blockCacheCount = 4;
    obj->sectorCacheCount = 0x20;
    obj->readCallback = cb34;
    obj->asyncReadCallback = cb38;
    obj->userData = arg30;
    for (i = 0; (i < 0x40) ? 1 : 0; i++) {
        ipad[i] = data_0272EB9C[i] ^ 0x36;
        opad[i] = data_0272EB9C[i] ^ 0x5c;
    }
    MSL_C_LIB_TwlCall1((uptr)data_02732E98);
    MSL_C_LIB_TwlCall1((uptr)data_02732E34);
    MSL_C_LIB_TwlCall3((uptr)data_02732E98, (uptr)ipad, 0x40);
    MSL_C_LIB_TwlCall3((uptr)data_02732E34, (uptr)opad, 0x40);
    obj->readCallback(obj->userData, obj->hash, obj->blockHashOffset, obj->blockHashLength);
    CARDi_CompareHash(hdr->digest, obj->hash, obj->blockHashLength);
    {
        Node16 *n = obj->l2;
        for (i = 0; (i < obj->sectorCacheCount) ? 1 : 0; i++) {
            n[i].next = n + (i - 1);
            n[i].data = (uptr)obj->l0 + i * obj->sectorSize;
            n[i].key = -1;
        }
    }
    {
        CardHashNode *m;
        obj->l2->next = 0;
        obj->cache_a = (CardHashNode *)((Node16 *)obj->l2 + (obj->sectorCacheCount - 1));
        obj->free_a = 0;
        obj->used_a = 0;
        m = (CardHashNode *)obj->l3;
        for (i = 0; (i < obj->blockCacheCount) ? 1 : 0; i++) {
            m[i].next = m + (i + 1);
            m[i].key = -1;
            m[i].buffer = (uptr)obj->l1 + i * ((((int)per * 0x14 + 0xff + 0x500) & -0x600));
        }
        obj->cache_b = obj->l3;
        obj->l3[obj->blockCacheCount - 1].next = 0;
        obj->free_b = 0;
        obj->used_b = 0;
    }
}
#pragma opt_common_subs reset

void CARDi_ReadRomHashImageDirect(CardHash *obj, u8 *buf, u32 off, u32 len)
{
    u32 psz = obj->sectorSize;
    u32 per = obj->blockSectorCount;
    u32 end = len + off;
    u32 a = off;
    u32 size;
    u32 key;

    a -= obj->ntrAreaOffset;
    size = obj->ntrAreaLength;
    if (a >= size) {
        a += obj->ntrAreaOffset - obj->ltdAreaOffset;
        if (a < obj->ltdAreaLength) {
            a += size;
        } else {
            OS_Terminate();
        }
    }
    key = a / obj->sectorSize;
    while (off < end) {
        u32 n;

        n = obj->readCallback(obj->userData, buf, off, end - off);
        CARDi_TouchRomHashBlock(obj, key);
        if (obj->asyncReadCallback != 0 && off + n < end) {
            obj->asyncReadCallback(obj->userData, 0, off + n, end - (off + n));
        }
        while (n >= psz) {
            CardHashNode *node = CARDi_TouchRomHashBlock(obj, key);
            u32 idx = key - node->key * per;

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
                    CARDi_CompareHash((u32 *)(obj->hash + node->key * 0x14), (void *)node->data, per * 0x14);
                    node->next = obj->cache_b;
                    obj->cache_b = node;
                }
                CARDi_CompareHash((u32 *)(node->data + idx * 0x14), buf, psz);
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
            u32 pos = off - (off & ~(obj->sectorSize - 1));
            u32 n = obj->sectorSize - pos;

            if (len <= n) {
                n = len;
            }
            MI_CpuCopy8((u8 *)page + pos, buf, n);
            len -= n;
            buf += n;
            off += n;
        } else {
            u32 a = off & ~(obj->sectorSize - 1);
            u32 end = off + len;
            u32 irq;
            CardHashNode *nb;
            CardHashNode *na;

            while (obj->cache_a != 0 && obj->cache_b != 0) {
                a += obj->sectorSize;
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
                    CARDi_CompareHash((u32 *)(obj->hash + nb->key * 0x14), (void *)nb->data, obj->blockSectorCount * 0x14);
                    nb->next = obj->cache_b;
                    obj->cache_b = nb;
                } else if (na != 0) {
                    CardHashNode *h = CARDi_TouchRomHashBlock(obj, na->key);
                    CARDi_CompareHash((u32 *)(h->data + (na->key - h->key * obj->blockSectorCount) * 0x14), (void *)na->data, obj->sectorSize);
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

    obj->thread = OSi_ThreadInfo.current;
    obj->cur = 0;
    if (len >= obj->sectorSize << 4 && OS_GetBootType() != 1) {
        mask = obj->sectorSize - 1;
        head = mask & (obj->sectorSize - off);
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
