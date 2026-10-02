/*
 * function: func_0217BEA8
 * address: 0x0217BEA8
 * packet: pkt_ov018_0217BEA8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02182B9C 0x02182B9C data ov018 a4
 */
typedef unsigned int u32;
typedef struct { u32 x:10; u32 rest:22; u32 y, z; } Entry;
extern Entry d_02182B9C[];
Entry *func_0217BEA8(u32 a) { u32 i; for (i=0; i<218; i++) { if (d_02182B9C[i].x == a) return &d_02182B9C[i]; } return 0; }
