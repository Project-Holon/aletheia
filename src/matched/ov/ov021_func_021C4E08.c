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

extern void func_020115EC(u32 t);
extern void func_021C4E34(R *r);

void func_021C4E08(R *r)
{
    if (r->task != 0) {
        func_020115EC(r->task);
        func_021C4E34(r);
    }
}
