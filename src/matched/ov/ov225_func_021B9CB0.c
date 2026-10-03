/*
 * function: func_021B9CB0
 * address: 0x021B9CB0
 * packet: pkt_ov225_021B9CB0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200EE14 0x0200EE14 thumb
 */
struct Big;
extern void *func_02012EBC(struct Big *);
extern void *func_0200ED48(void *);
extern void func_0200EE14(void *,int);
void func_021B9CB0(void *unused,int code,struct Big *save) {func_0200EE14(func_0200ED48(func_02012EBC(save)),code);}
