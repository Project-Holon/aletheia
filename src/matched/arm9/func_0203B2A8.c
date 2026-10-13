/*
 * unit:     no
 * function: GFL_NET_STATE_ChangeParentWait
 * address:  0x0203B2A8
 * packet:   pkt_0203AD8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 */

typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
void GFL_NET_STATE_ChangeParentWait(int a0){ GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B228, (int)0, (int)0x214); }
