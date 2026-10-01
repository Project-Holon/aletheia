/*
 * function: func_0220F22C
 * address: 0x0220F22C
 * packet: pkt_ov198_0220F22C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef struct {short x,y;} Pair;
extern int func_022110D4(u8 *,int);
extern void func_0204B454(void *,void *,int);
extern void func_0204B404(void *,void *,int);
void func_0220F22C(u8 *p,int a,short delta)
{
    int i=func_022110D4(p,a);
    Pair pair;
    func_0204B454(*(void **)(p+0x1ebc+i*4),&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ebc+i*4),&pair,1);
    func_0204B454(*(void **)(p+0x1ed8+i*4),&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ed8+i*4),&pair,1);
    func_0204B454(*(void **)(p+0x1ef0+i*4),&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ef0+i*4),&pair,1);
    func_0204B454(*(void **)(p+0x1f08+i*4),&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1f08+i*4),&pair,1);
}
