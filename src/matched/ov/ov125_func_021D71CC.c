/*
 * function: GDS_RAP_CopyNickname
 * address: 0x021D71CC
 * packet: pkt_ov125_021D71CC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuCopy8(const void *,void *,u32);
void GDS_RAP_CopyNickname(const void *src,void *dst,u32 n) {MI_CpuCopy8(src,dst,n*2);}
