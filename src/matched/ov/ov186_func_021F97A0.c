/*
 * function: func_021F97A0
 * address: 0x021F97A0
 * packet: pkt_ov186_021F97A0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 */
extern int func_021FC4DC(int);
extern void func_02034714(const char *,int,const char *);
extern const char d_02200D00[];
void func_021F97A0(int *out,int *source,int *ctx,int type)
{
    if(type==1) {
        out[0]=ctx[2];
        out[3]=source[1];
        out[1]=source[3];
        out[4]=source[2];
        out[2]=func_021FC4DC(source[0]);
        out[5]=(*(int **)((char *)source[6]+0xc))[1];
        out[6]=*(int *)((char *)source[6]+8)+0x1748;
    } else {
        func_02034714(d_02200D00,0,d_02200D00);
    }
}
