/*
 * function: func_021DE5F8
 * address: 0x021DE5F8
 * packet: pkt_ov170_021DE5F8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: slot=a; slot=a-30; preserves the two stores to its stack home.
 * symbols:
 *   func_021DDEFC 0x021DDEFC thumb ov170
 */
typedef struct {
    unsigned short idx,slot,f4,f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj;
extern void func_021DDEFC(unsigned char *,Obj *);
void func_021DE5F8(unsigned char *p,unsigned a)
{
    Obj *o;
    unsigned i;
    unsigned slot;
    o=*(Obj **)(*(char **)(p+0x2c)+0x60);
    slot=a;
    slot=a-30;
    for(i=0;i<6;i++){
        o[i].idx=i+30;
        o[i].slot=i+30;
        o[i].f4=i+30;
        o[i].f6=0;
    }
    o[i].f6=0;
    for(i=slot+1;i<6;i++){
        o[i].slot=i+29;
        o[i].f6=1;
        func_021DDEFC(p,&o[i]);
    }
    o[slot].slot=35;
    o[slot].f6=1;
    func_021DDEFC(p,&o[slot]);
}
