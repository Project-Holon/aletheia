/*
 * function: COLOSSEUM_Delete
 * address:  0x0217505C
 * packet:   pkt_ov012_0217505C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   COMM_PLAYER_Delete  0x0216754C  thumb  ov010
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct O;
extern void COMM_PLAYER_Delete(int a, struct O *o);

void COLOSSEUM_Delete(int *p, int x)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_020307B0(*(void **)((char *)p + i * 4 + 0x134));
        func_020307B0(*(void **)((char *)p + i * 4 + 0x148));
    }
    COMM_PLAYER_Delete(x, (struct O *)(*p));
    func_020307B0(p);
}
