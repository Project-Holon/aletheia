/*
 * unit: yes
 * function: func_021BAA3C,func_021BAA5C,func_021BAA68,func_021BAA74,func_021BAA80
 * address: 0x021BAA3C
 * packet: pkt_ov110_021BAA3C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
extern void func_021BC6F8(void *);
extern void func_021B9CBC(u8 *);
void func_021BAA3C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 **)p;
    if(q[0x74]!=1) func_021BC6F8(*(void **)(q+0x54));
    func_021B9CBC(p);
}
void func_021BAA5C(void *unused,u8 *p) { func_021B9CBC(p); }
void func_021BAA68(void *unused,u8 *p) { func_021B9CBC(p); }
void func_021BAA74(void *unused,u8 *p) { func_021B9CBC(p); }
void func_021BAA80(void *unused,u8 *p) { func_021B9CBC(p); }
