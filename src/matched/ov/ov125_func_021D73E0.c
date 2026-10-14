/*
 * function: GDS_RAP_GetUploadedDataNumber
 * address: 0x021D73E0
 * packet: pkt_ov125_021D73E0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 */
extern char *GDS_SOCKET_GetReply(void);
unsigned long long GDS_RAP_GetUploadedDataNumber(char *a0) { int *p=(int *)GDS_SOCKET_GetReply(); return *(unsigned long long *)(p+1); }
