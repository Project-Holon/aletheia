/*
 * function: FLDEFF_RIPPLE_CreateZoneStartWarpTask
 * address:  0x021D2418
 * packet:   pkt_ov021_021D2418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FLDEFF_RIPPLE_WarpToZoneStartTask  0x021D2278  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int FLDEFF_RIPPLE_WarpToZoneStartTask(u32 a, int *seq, int *w);

void *FLDEFF_RIPPLE_CreateZoneStartWarpTask(void *a, u32 b)
{
    void *task = func_020122C0(a, 0, FLDEFF_RIPPLE_WarpToZoneStartTask, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 0;
    return task;
}
