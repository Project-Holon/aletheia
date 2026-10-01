/*
 * function: func_021D2418
 * address:  0x021D2418
 * packet:   pkt_ov021_021D2418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D2278  0x021D2278  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020122C0(void *a, u32 b, void (*fn)(void *, void *), u32 size);
extern u32 *func_020124E8(void *task);
extern void func_021D2278(void *task, void *work);

void *func_021D2418(void *a, u32 b)
{
    void *task = func_020122C0(a, 0, func_021D2278, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 0;
    return task;
}
