/*
 * function: func_021C59F4
 * address: 0x021C59F4
 * packet: pkt_ov127_021C59F4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_021C5AAC 0x021C5AAC thumb ov127
 *   d_021C6144 0x021C6144 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *f0; u32 f4; void *f8; u32 fC, f10, f14, f18; } Obj;
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_02049EB4(u8, u8, u8, void *, u16);
extern void func_021C5AAC(u32, u32, const u8 *);
extern const char d_021C6144[];
Obj *func_021C59F4(void *p, u32 n, const u8 *q, u32 heap)
{
    Obj *o = func_02030734((u16)heap, 28, 1, d_021C6144, 104);
    o->f0 = p;
    o->f4 = n;
    o->f10 = q[0];
    o->f14 = q[1];
    func_021C5AAC(n, q[1], q);
    o->f8 = func_02049EB4(q[8], q[9], q[10], &o->fC, heap);
    return o;
}
