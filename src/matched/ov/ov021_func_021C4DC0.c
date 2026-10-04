/*
 * function: func_021C4DC0
 * address:  0x021C4DC0
 * packet:   pkt_ov021_021C4DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Restarts the record's task with new arguments.
 */

typedef unsigned short u16;
typedef unsigned int u32;

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
extern void func_02011558(struct IcaAnime *p);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);

void func_021C4DC0(R *r, u32 a, u32 b, u32 c)
{
    if (r->task != 0)
        func_02011558((struct IcaAnime *)r->task);
    r->task = (u32)func_02011510(r->heap, a, b, c);
}
