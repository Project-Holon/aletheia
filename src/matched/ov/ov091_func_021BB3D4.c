/*
 * function: func_021BB3D4
 * address: 0x021BB3D4
 * packet: pkt_ov091_021BB3D4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 d_021BEC74[];
extern u8 d_021BEC75[];
void func_021BB3D4(void *a,u8 *s,u16 *out) { out[0]=(d_021BEC74[s[4]*2]+8)<<3; out[1]=(d_021BEC75[s[4]*2]+3)<<3; }
