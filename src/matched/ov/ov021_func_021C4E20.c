/*
 * function: func_021C4E20
 * address:  0x021C4E20
 * packet:   pkt_ov021_021C4E20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns the task's status word, 0 without a task (EXACT*: pad).
 *
 * symbols:
 *   func_0201160C  0x0201160C  thumb
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

struct Obj11245;
extern u32 func_0201160C(struct Obj11245 *p);

u32 func_021C4E20(R *r)
{
    if (r->task == 0)
        return 0;
    return func_0201160C((struct Obj11245 *)r->task);
}
