/*
 * function: func_021C5B98
 * address: 0x021C5B98
 * packet: pkt_ov127_021C5B98
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding precede func_021C5C8C.
 * lever: Integer address q spills; a pointer q consumes the clipping register.
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_021C5C8C 0x021C5C8C thumb ov127
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern void func_02041300(u8,int,int,int,u8,u8,u8);
extern void func_021C5C8C(void *,u8,u8,u8,u8,u8,void *,u8,u8,u8,u8);
void func_021C5B98(void *p,int layer,unsigned int q,s16 x,s16 y)
{
    s16 width=*(u16 *)q/8;
    s16 height=*(u16 *)(q+2)/8;
    s16 sx,sy,w,h;
    if(x<0) sx=-x; else sx=0;
    if(y<0) sy=-y; else sy=0;
    if(x<=0) x=0;
    if(y<=0) y=0;
    w=33-x;
    h=25-y;
    if(width<sx+w) w-= (s16)(sx+w-width);
    if(height<sy+h) h-= (s16)(sy+h-height);
    func_02041300(layer,0,0,0,33,25,17);
    q+=12;
    func_021C5C8C(p,layer,x,y,w,h,(void *)q,sx,sy,width,height);
}
