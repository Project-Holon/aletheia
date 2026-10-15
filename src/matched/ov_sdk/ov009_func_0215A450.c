/*
 * function: check_frag
 * address:  0x0215A450
 * packet:   pkt_ov009_0215A450
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      check_frag (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   MI_CpuCopy                       0x02082ea4 arm
 *   gCpsFragTable                       0x021a8a64 data
 *   gCpsNetVars                       0x021a826c data
 */

#include "../include/G_CPSFragTable.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u32 ipfrom;
    u16 count;
    u16 id;
    u16 last;
    u16 size;
    u16 ofs[8];
    u16 end[8];
    u32 time;
    u8 *data;
    u8 *buf;
} CPSFragTable;

struct CPSVars {
    u8 pad0[0x14];
    void *(*alloc)(u32);
    u8 pad18[0x44 - 0x18];
    void (*free)(void *);
};

extern struct CPSFragTable gCpsFragTable[8];
extern struct CPSVars gCpsNetVars;
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);

#define TICK() ((u32)(OS_GetTick() >> 16))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))

u8 *check_frag(u8 *buf, u32 *fragmented)
{
    u32 i;
    u32 frag;
    u32 id;
    u32 frag_size;
    u32 frag_ofs;
    u32 frag_last;
    u32 header_len;
    CPSFragTable *unused;
    CPSFragTable *p;
    u32 size;
    u32 ipfrom;

    *fragmented = 0;
    unused = 0;
    frag = NTOHS(buf + 6);
    if ((frag & 0x3fff) == 0)
        return buf;
    header_len = (buf[0] & 0xf) << 2;
    ipfrom = NTOHL(buf + 0xc);
    id = *(u16 *)(buf + 4);
    p = ((CPSFragTable *)gCpsFragTable);
    for (i = 0; i < 8; i++, p++) {
        if (p->count != 0 && p->ipfrom == ipfrom && p->id == id)
            break;
        if (p->count == 0 && unused == 0)
            unused = p;
    }
    frag_size = NTOHS(buf + 2) - header_len;
    frag_ofs = frag & 0x1fff;
    size = frag_size + (frag_ofs << 3);
    if (i == 8) {
        if (unused == 0 || size > 0x1000)
            return 0;
        p = unused;
        p->buf = gCpsNetVars.alloc(header_len + 0xe + 0x1000);
        if (p->buf == 0)
            return 0;
        p->ipfrom = ipfrom;
        p->id = id;
        p->last = 0;
        p->time = TICK();
        p->data = p->buf + 0xe + header_len;
        MI_CpuCopy(buf, p->buf + 0xe, header_len);
    }
    if (p->count == 8 || size > 0x1000) {
        p->count = 0;
        gCpsNetVars.free(p->buf);
        return 0;
    }
    frag_last = frag_ofs + ((frag_size + 7) >> 3);
    if ((frag & 0x2000) == 0) {
        p->size = size;
        p->last = frag_last;
    }
    p->ofs[p->count] = frag_ofs;
    p->end[p->count] = frag_last;
    p->count++;
    MI_CpuCopy(buf + header_len, p->data + (frag_ofs << 3), frag_size);
    if (p->last == 0)
        return 0;
    size = 0;
    i = 0;
    while (i < p->count) {
        if (p->ofs[i] <= size && size < p->end[i]) {
            size = p->end[i];
            i = 0;
        } else {
            i++;
        }
    }
    if (size < p->last)
        return 0;
    buf = p->buf + 0xe;
    *(u16 *)(buf + 2) = HTONS(p->size + ((buf[0] & 0xf) << 2));
    p->count = 0;
    *fragmented = 1;
    return buf;
}
