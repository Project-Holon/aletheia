/*
 * function: func_021F4C10
 * address: 0x021F4C10
 * packet: pkt_ov048_021F4C10
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048F74 0x02048F74 arm
 */
typedef unsigned int   u32;
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
int func_021F4C10(int a,int b,int c) { func_02048F74((void *)a,b,c,0,(u32 *)0x7c); return 1; }
