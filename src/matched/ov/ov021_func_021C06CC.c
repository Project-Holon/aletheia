/*
 * function: EVENT_COMM_ERROR_Create
 * address:  0x021C06CC
 * packet:   pkt_ov021_021C06CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the EVENT_COMM_ERROR_Run task with no work area.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   EVENT_COMM_ERROR_Run  0x021C06E0  thumb  ov021
 */

typedef unsigned int   u32;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
int EVENT_COMM_ERROR_Run(u32 a, int *st);

void EVENT_COMM_ERROR_Create(void *p)
{
    func_020122C0(p, 0, EVENT_COMM_ERROR_Run, 0);
}
