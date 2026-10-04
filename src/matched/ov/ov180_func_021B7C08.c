/*
 * unit: yes
 * function: func_021B7C08, func_021B7C60
 * address: 0x021B7C08
 * packet: pkt_ov180_021B7C08
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 0x021B7C60 tail-call stub included in this verified unit.
 * symbols:
 *   func_021B7408 0x021B7408 thumb ov180
 *   func_0202590C 0x0202590C thumb
 *   func_02025774 0x02025774 thumb
 */
extern void func_021B7408(char *,int,short *,short *);
typedef signed short   s16;
struct Grid;
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
void func_021B7C08(char *p) {
    short x,y;
    func_021B7408(p,2,&x,&y);
    func_0202590C((struct Grid *)(*(int *)(p+0x9120)),x-176,y-8);
    func_021B7408(p,3,&x,&y);
    func_0202590C((struct Grid *)(*(int *)(p+0x9128)),x,y-8);
}
extern void func_02025774(unsigned char *,unsigned);
void func_021B7C60(char *p,int index,unsigned value) {
    func_02025774(*(unsigned char **)(p+0x9120+index*8),value);
}
