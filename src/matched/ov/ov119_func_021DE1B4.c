/*
 * function: func_021DE1B4
 * address: 0x021DE1B4
 * packet: pkt_ov119_021DE1B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   func_021E6440 0x021E6440 thumb ov119
 */
extern int func_021D89EC(void *);
extern void func_021E219C(void *,void *,int,int);
extern void func_021E6440(void *,int,int);
typedef struct { char pad[0xfd8]; void *obj[2][3]; } State;
void func_021DE1B4(State *p,int index)
{
    int col=index%3;
    int row=index/3;
    int other=1-row;
    void *obj=p->obj[other][col];
    if(func_021D89EC(obj)) {
        func_021E219C(p,obj,other,1);
        func_021E6440(p,row,col);
    }
}
