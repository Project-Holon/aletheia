/*
 * function: UNION_COMM_InitWait
 * address: 0x02172C78
 * packet: pkt_ov012_02172C78
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing matched follower ov012_func_02172C98.c
 * symbols:
 *   GFL_NET_EndDeviceWrapper 0x0203D0FC arm
 */
typedef unsigned char u8;
extern void GFL_NET_EndDeviceWrapper(int a);
int UNION_COMM_InitWait(void *a, void *b, u8 *p) { if (p[0x3560] >= 2) { p[0x3560] = 3; GFL_NET_EndDeviceWrapper(0); return 1; } return 0; }
