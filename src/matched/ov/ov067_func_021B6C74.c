/*
 * function: func_021B6C74
 * address:  0x021B6C74
 * packet:   pkt_ov067_021B6C74
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a narrow (u8) parameter: it is spilled at entry and
 * reloaded for both calls (u16 gives the same bytes). The size is a spilled
 * local assigned twice, the second time recomputed from n.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`size = n * 4;` before `size = n * 4 + 8;`). Game code has no line table,
 * so these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   d_021B9558     0x021B9558  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern const char d_021B9558[];

u32 *func_021B6C74(u32 *src, u32 n, u16 heap)
{
    u32 size;
    u32 *o;
    u32 i;

    size = n * 4 + 8;
    o = func_02030734(heap, size, 0, d_021B9558, 0x40);
    i = 0;
    func_02082BCC(o, 0, size);
    o[1] = n;
    for (i = 0; i < n; i++) {
        o[2 + i] = src[i];
    }
    o[0] = (u32)func_020457B0(0x80, heap);
    return o;
}
