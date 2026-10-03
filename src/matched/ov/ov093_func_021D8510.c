/*
 * function: func_021D8510
 * address: 0x021D8510
 * packet: pkt_ov093_021D8510
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D732C 0x021D732C thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void *func_021D732C(int,int);
extern void func_021D7040(void *);
void func_021D8510(void *p) { int n = func_021D5440(p); void *a; while ((a=func_021D732C(4,n)) != 0) { func_021D7040(a); } }
