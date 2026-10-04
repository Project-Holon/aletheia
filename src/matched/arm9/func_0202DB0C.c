/*
 * function: func_0202DB0C
 * address:  0x0202DB0C
 * packet:   pkt_0202DB0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The PmsDraw constructor.  Closed 2026-09-23 from the 68-byte near miss
 * in docs/notes/pkt_0202DB0C.c.txt by two changes:
 *   - the second allocator's heap is a named u16 local read back from
 *     p->heap IMMEDIATELY after the store (`h = p->heap;`), so it is the
 *     same value as the strh operand and stays in r0 across the three
 *     field stores; `p->heap` written at the call re-reads it, the `heap`
 *     parameter makes it a callee-saved copy from the prologue;
 *   - the fifth parameter is u8 after all (`ldrb` at the func_0202DF68
 *     site); it only looked like it cost four bytes while the heap value
 *     was wrong.
 * The allocator result still has to go through a named local before p.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0202DF68  0x0202DF68  thumb
 *   func_0202E09C  0x0202E09C  thumb
 *   s_pms_draw_c   0x020A77B8  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PmsElem { u8 raw[0x28]; };

struct PmsDraw {
    u16   heap;
    u8    pad02[2];
    u32   unk04;
    void *unk08;
    struct PmsElem *elems;
    u32   res[5];
    u16   unk24;
    u8    pad26[2];
    u32   selected;
    u32   unk2c;
    u8    count;
    u8    unk31;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *p, u32 v, u32 n);
extern void  func_0202DF68(u32 *res, u32 a, u32 heap);
struct Res;
extern void  func_0202E09C(u8 *e, struct Res *res, u16 heap);
extern char  s_pms_draw_c[];

struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap)
{
    struct PmsDraw *p;
    u32 n;
    u16 h;
    int i;
    struct PmsDraw *tmp = func_02030734(heap, 0x34, 1, s_pms_draw_c, 0x81);

    p = tmp;
    MI_CpuFill8(p, 0, 0x34);
    p->heap = heap;
    h = p->heap;
    p->unk08 = (void *)c;
    p->unk04 = d;
    p->count = e1;
    p->unk31 = 0xf;
    p->unk2c = 0;
    n = e1 * 0x28;
    p->elems = func_02030734(h, n, 1, s_pms_draw_c, 0x8c);
    MI_CpuFill8(p->elems, 0, n);
    p->res[0] = a;
    p->res[1] = b;
    p->unk24 = 0x11 << 6;
    func_0202DF68(p->res, e0, p->heap);
    for (i = 0; i < p->count; i++) {
        func_0202E09C((u8 *)&p->elems[i], (struct Res *)p->res, p->heap);
    }
    return p;
}
