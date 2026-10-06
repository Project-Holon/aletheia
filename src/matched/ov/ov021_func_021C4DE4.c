/*
 * function: func_021C4DE4
 * address:  0x021C4DE4
 * packet:   pkt_ov021_021C4DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finishes the record's task and tears the record down.
 *
 * symbols:
 *   func_021C4E34  0x021C4E34  thumb  ov021
 *   func_021C4E6C  0x021C4E6C  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    u32 f14;
} R;

struct IcaAnime;
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_021C4E34(R *r);
extern void func_021C4E6C(char *p);

u32 func_021C4DE4(R *r, s32 dv)
{
    u32 v;

    if (r->task == 0)
        return 0;
    v = func_02011590((struct IcaAnime *)r->task, dv);
    func_021C4E34(r);
    func_021C4E6C((char *)r);
    return v;
}
