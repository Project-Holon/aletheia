/*
 * function: func_02052DC8
 * address:  0x02052DC8
 * packet:   pkt_020528D0
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020583CC  0x020583CC  arm
 *
 * The rig constructor: allocate and zero the 0x4c-byte Head through the
 * caller's allocator, record the two pool sizes (+0x34, +0x36), pack the
 * 6-bit fields of the +0x38 word (b0 = a4, b6 = a5, b12 = b0, b18 = a3,
 * b24 and b25..31 cleared, one read-modify-write per field under 1.2), clear
 * the three list headers and the counters, then allocate n1 nodes of 0x9c
 * bytes pushed onto the recycle list at +0x10 and n2 records of 0x44 bytes
 * pushed onto the list at +0x1c.  Returns the Head.  Caller 0x02050D88 passes
 * every scalar argument truncated to u16.
 *
 * Closed by indexing: `&p[i]` over a 0x9c-byte element type rather than a
 * hand-advanced `char *` (8 bytes out, a p/i register swap, otherwise).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef void *(*AllocFn)(u32 size);

struct Head {
    AllocFn alloc;       /* 0x00 */
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u16 f32;
    u16 f34;
    u16 f36;
    u32 b0  : 6;
    u32 b6  : 6;
    u32 b12 : 6;
    u32 b18 : 6;
    u32 b24 : 1;
    u32 b25 : 7;
    u32 f3c;
    u32 f40;
    u32 f44;
    u16 f48;
    u16 f4a;
};

struct Node9C { u8 b[0x9c]; };
struct Node44 { u8 b[0x44]; };

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
struct List;
struct Node;
extern void func_020583CC(volatile struct List *list, volatile struct Node *node);

struct Head *func_02052DC8(AllocFn alloc, u16 n1, u16 n2, u16 a3, u16 a4, u16 a5)
{
    struct Head *h;
    struct Node9C *p;
    struct Node44 *q;
    int i;

    h = alloc(sizeof(struct Head));
    MI_CpuFill8(h, 0, sizeof(struct Head));
    h->f34 = n1;
    h->f36 = n2;
    h->b0 = a4;
    h->b6 = a5;
    h->b12 = h->b0;
    h->b18 = a3;
    h->b24 = 0;
    h->b25 = 0;
    h->alloc = alloc;
    h->f08 = 0;
    h->f14 = 0;
    h->f20 = 0;
    h->f04 = 0;
    h->f10 = 0;
    h->f1c = 0;
    h->f3c = 0;
    h->f48 = 0;

    p = alloc(n1 * sizeof(struct Node9C));
    MI_CpuFill8(p, 0, n1 * sizeof(struct Node9C));
    for (i = 0; i < n1; i++)
        func_020583CC((volatile struct List *)(&h->f10), (volatile struct Node *)(&p[i]));

    q = alloc(n2 * sizeof(struct Node44));
    MI_CpuFill8(q, 0, n2 * sizeof(struct Node44));
    for (i = 0; i < n2; i++)
        func_020583CC((volatile struct List *)(&h->f1c), (volatile struct Node *)(&q[i]));

    h->f28 = 0;
    h->f2c = 0;
    h->f30 = h->f32 = 0;
    return h;
}
