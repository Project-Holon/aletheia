/*
 * function: func_0215E580
 * address: 0x0215E580
 * packet: pkt_ov010_0215E580
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_0200D468 0x0200D468 thumb
 *   func_0215E440 0x0215E440 thumb ov010
 */
typedef unsigned char u8;
extern void *func_02012EBC(void *);
extern void *func_0200D418(void *);
extern u8 func_0200D468(void *,u8);
extern void func_0215E440(void *,u8);
void func_0215E580(void *a)
{
 int i;
 void *p = func_0200D418(func_02012EBC(a));
 for(i=0;i<2;i++) {
  if(func_0200D468(p,i)==2) func_0215E440(a,i);
 }
}
