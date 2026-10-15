/*
 * function: func_021DBF40
 * address: 0x021DBF40
 * packet: pkt_ov121_021DBF40
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: FILE_UTIL_Get item is u16 here, matching caller truncation before the call.
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 *   func_0201BC3C 0x0201BC3C thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DC024(void *); extern char *func_021DC02C(void *); extern int func_0201BC3C(void); extern u32 FILE_UTIL_Get(u16,u32);
u32 func_021DBF40(void *p) { switch(func_021DC024(p)) { case 1:return func_0201BC3C(); case 2:return FILE_UTIL_Get(*(u32 *)func_021DC02C(p),2); default:return 3; } }
