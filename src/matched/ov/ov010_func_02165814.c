/*
 * function: func_02165814
 * address: 0x02165814
 * packet: pkt_ov010_02165814
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C20C 0x0200C20C thumb
 *   func_0201F41C 0x0201F41C thumb
 *   func_0202744C 0x0202744C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk34;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_0201F41C(const u16 *,u16 *,u32);
extern void func_0202744C(void *);
void func_02165814(u8 *p,void *a,u16 b) { func_0201F41C(func_0200C20C(func_0200C0F0(func_02012EBC(a))),(u16 *)(p+0x34),9); *(u16 *)(p+0x30)=0x18; *(u16 *)(p+0x46)=b; func_0202744C(p); }
