/*
 * function: func_021C4E08
 * address:  0x021C4E08
 * packet:   pkt_ov021_021C4E08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stops the record's task and syncs the final position (EXACT*: pad).
 *
 * symbols:
 *   func_021C4E34  0x021C4E34  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    V3 *pos;
} R;

struct IcaAnime;
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern void func_021C4E34(R *r);

void func_021C4E08(R *r, s32 frame)
{
    if (r->task != 0) {
        func_020115EC((struct IcaAnime *)r->task, frame);
        func_021C4E34(r);
    }
}
