/*
 * function: func_021657E8
 * address: 0x021657E8
 * packet: pkt_ov010_021657E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027060 0x02027060 thumb
 *   func_02026FB8 0x02026FB8 thumb
 *   g_02146940 0x02146940 data
 *   func_02165814 0x02165814 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165814(u8 *,void *,u16);
void func_021657E8(void *a,u16 b) { if(func_02027060(0x18)) { func_02165814((u8 *)g_02146940+4,a,b); func_02026FB8(g_02146940+4); } }
