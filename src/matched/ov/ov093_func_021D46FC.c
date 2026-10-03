/*
 * function: func_021D46FC
 * address:  0x021D46FC
 * packet:   pkt_ov093_021D46FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT (extent 168, compiled 136: the rest is an unlabelled leaf at 0x021D4784, `d->tblC[a] != 0`, and its pool)
 *
 * Lever: the message header is read as bitfields (type:8, size:24) through a `const`
 * pointer. Plain `(u8)*c` / `*c >> 8` loads *c before &d (8 bytes out); bitfields through a
 * non-const pointer put &d first but reload *c for the size; `const` lets the size share
 * the first load (const-pointer-lets-a-field-load-survive-a-store.md).
 *
 * Message handler: ensures d->tblC[type] is allocated (sub_02030734 with size, tag 0x282),
 * copies the payload (c+1) into it, frees d->f3b14 and clears it.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021F3B88     0x021F3B88  data  ov093
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
    u8 pad06[0x3afe];
    void *tblC[4];
    void *f3b14;
};

extern struct S *d_021F3B88;
extern const char d_021F3A98[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_020307B0(void *p);

typedef union {
    u32 w;
    struct {
        u32 type : 8;
        u32 size : 24;
    } h;
} Hdr;

void func_021D46FC(u32 a, u32 b, const Hdr *c)
{
    if (d_021F3B88->tblC[c->h.type] == 0) {
        d_021F3B88->tblC[c->h.type] = sub_02030734((u16)((d_021F3B88->f04 & 0x7fff) | 0x8000), c->h.size, 1, d_021F3A98, 0x282);
    }
    MI_CpuCopy8(c + 1, d_021F3B88->tblC[c->h.type], c->h.size);
    func_020307B0(d_021F3B88->f3b14);
    d_021F3B88->f3b14 = 0;
}
