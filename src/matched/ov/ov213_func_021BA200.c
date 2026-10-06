/*
 * function: func_021BA200
 * address: 0x021BA200
 * packet: pkt_ov213_021BA200
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_020450F0 0x020450F0 arm
 * domain: index 0..3, supplied by A268 from A38C's bounded 2/4-row loop; all valid switch paths initialize coordinates.
 * prototype: visible byte truncations require u8 second/third extern parameters despite callee's u32 spelling.
 */
extern int func_021B9E50(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
unsigned func_021BA200(unsigned kind,unsigned index)
{
    int x,y;
    if(func_021B9E50(kind)) {
        if(index==0) {x=4;y=17;}
        else {x=16;y=3;}
    } else {
        switch(index) {
        case 0:x=5;y=13;break;
        case 1:x=13;y=19;break;
        case 2:x=15;y=1;break;
        case 3:x=23;y=7;break;
        }
    }
    return func_020450F0(1,(unsigned char)x,(unsigned char)y,10,3,1,1);
}
