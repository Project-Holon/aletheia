/*
 * function: func_021B6418
 * address: 0x021B6418
 * packet: pkt_ov180_021B6418
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 */
extern void *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern void *func_0201D7EC(unsigned,unsigned,unsigned,unsigned,unsigned);
extern void *func_0201EC64(unsigned); extern void *func_020457B0(unsigned,unsigned);
void func_021B6418(char *p) {
 *(void **)(p+0x9038)=func_02045B38(0,2,32,141);
 *(void **)(p+0x9030)=func_0201D7EC(23,0,0,0,141);
 *(void **)(p+0x9034)=func_0201D7EC(23,3,0,0,141);
 *(void **)(p+0x903C)=func_0201EC64(141);
 *(void **)(p+0x9040)=func_020457B0(1024,141);
}
