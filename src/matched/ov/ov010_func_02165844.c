/*
 * function: func_02165844
 * address: 0x02165844
 * packet: pkt_ov010_02165844
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027060 0x02027060 thumb
 *   func_02026FB8 0x02026FB8 thumb
 *   g_02146940 0x02146940 data
 *   func_0216586C 0x0216586C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02027060(int);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_0216586C(void *,void *);
void func_02165844(void *v) { if(func_02027060(0x31)) { func_0216586C(g_02146940+4,v); func_02026FB8(g_02146940+4); } }
