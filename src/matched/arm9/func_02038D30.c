/*
 * unit:     no
 * function: GFL_NET_SYSTEM_GetChildRingDataSize
 * address:  0x02038D30
 * packet:   pkt_02038C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RING_BUFF_GetDataSize  0x020365E8  arm
 */

extern int GFL_NET_RING_BUFF_GetDataSize(char *p);
void GFL_NET_SYSTEM_GetChildRingDataSize(int a0, int a1, int a2, int a3){ GFL_NET_RING_BUFF_GetDataSize((char *)((int)(*(int *)((char *)(0x21469D0)) + 0x1c))); }
