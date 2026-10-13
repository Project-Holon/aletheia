/*
 * function: PARTICLE_ApplyLoadHandlersTask
 * address:  0x020513F8
 * packet:   pkt_02051230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_ApplyLoadHandlersTask.c \
 *       --func PARTICLE_ApplyLoadHandlersTask --addr 0x020513F8 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_ApplyLoadHandlers  0x02051394  arm
 */

typedef unsigned int   u32;
extern void PARTICLE_ApplyLoadHandlers(u32 *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void PARTICLE_ApplyLoadHandlersTask(void *p, int a)
{
    PARTICLE_ApplyLoadHandlers((u32 *)a);
    func_02030EAC(p);
}
