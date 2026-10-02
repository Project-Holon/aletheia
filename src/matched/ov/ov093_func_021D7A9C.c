/*
 * function: func_021D7A9C
 * address: 0x021D7A9C
 * packet: pkt_ov093_021D7A9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F047C 0x021F047C data ov093 a1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 d_021F047C[17][17];
u8 func_021D7A9C(int a,u8 *out) { u8 n,i; i=0; n=0; do { if(d_021F047C[a][i]==0 || d_021F047C[a][i]==2) out[n++]=i; ++i; } while(i<17); return n; }
