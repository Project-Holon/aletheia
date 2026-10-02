/*
 * function: func_021BC240
 * address: 0x021BC240
 * packet: pkt_ov208_021BC240
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D80 0x021C8D80 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Obj { void *owner; int f4; int f8; int fc; int f10; };
extern const char d_021C8D80[];
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap)
{
    struct Ov208Obj *p = func_02030734(heap, 20, 0, d_021C8D80, 0x4f);
    p->owner = owner;
    p->f4 = 0;
    p->f8 = 0;
    p->fc = val;
    p->f10 = 0;
    return p;
}
