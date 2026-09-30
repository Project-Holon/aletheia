/*
 * function: func_021D44AC
 * address: 0x021D44AC
 * packet: pkt_ov120_021D44AC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4490 0x021D4490 thumb ov120
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021D4244(void *,void (*)(void *),int);
extern void func_021D4490(void *);
void func_021D44AC(char *p) {
    if (--*(int *)(p+0x14)<=0) {
        func_0202208C(0,0,0,0,6,1,*(u16 *)(p+0xc));
        func_021D4244(p,func_021D4490,0x21e);
    }
}
