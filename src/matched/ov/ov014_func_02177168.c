/*
 * unit: yes
 * function: func_02177168, func_0217717C, func_02177184, func_02177190
 * address: 0x02177168
 * packet: pkt_ov014_02177168
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02177190 forwards r1 unchanged to 02177C30; that leaf
 * performs the u16 truncation itself. Its matched signature uses full width.
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_021793B8 0x021793B8 thumb ov014
 *   func_02179394 0x02179394 thumb ov014
 *   func_02177C30 0x02177C30 thumb ov014
 */
extern int func_02178E4C(void);
int func_02177168(void) { if (func_02178E4C() == 5) return 1; return 0; }
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021793B8(int);
extern int func_02179394(u16);
extern int func_02177C30(int,u32,int);
int func_0217717C(int a) { return func_021793B8(a); }
int func_02177184(u32 a) { return func_02179394((u16)a); }
int func_02177190(int a,u32 b,int c,int d) { return func_02177C30(a,b,d); }
