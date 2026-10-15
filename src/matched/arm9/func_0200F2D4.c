/*
 * unit:     no
 * function: GFL_NET_ERR_PollNetState
 * address:  0x0200F2D4
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_GetGameKind  0x0203D5D4  arm
 */

int GFL_NET_ERR_PollNetState(void){ int t0, t1, t2; t0 = GFL_NET_GetGameKind(); if ((unsigned int)(t0) == (unsigned int)(2)) { if ((unsigned int)(*(unsigned char *)((char *)(0x2146178))) == (unsigned int)(0)) { t1 = GFL_NET_Main((int)*(unsigned char *)((char *)(0x2146178))); *(unsigned char *)((char *)(0x2146178)) = (unsigned char)t1; return t1; } else { *(unsigned char *)((char *)(0x2146178)) = (unsigned char)0; return 0; } } else { t2 = GFL_NET_Main((int)t0); return t2; } }
