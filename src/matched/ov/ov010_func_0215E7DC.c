/*
 * function: func_0215E7DC
 * address: 0x0215E7DC
 * packet: pkt_ov010_0215E7DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200D4AC 0x0200D4AC thumb
 *   func_0200D480 0x0200D480 thumb
 *   func_0200D50C 0x0200D50C thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *func_0200D4AC(void *,u32);
extern void func_0200D480(void *,u32,u8);
extern void func_0200D50C(void *,u32,u32);
void func_0215E7DC(void *p,u32 i,u8 v,u32 n)
{
 void *rec = func_0200D4AC(p,i);
 func_0200D480(p,i,v);
 func_0200D50C(rec,1,n);
}
