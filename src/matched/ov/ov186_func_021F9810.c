/*
 * function: func_021F9810
 * address: 0x021F9810
 * packet: pkt_ov186_021F9810
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: compute ctx+0x20 before storing the getter result, then read ctx+0x1c.
 * Direct getter store leaves an 8-byte scheduling/register residue.
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 */
extern int func_021FC4DC(int);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02200D00[];
void func_021F9810(int *out,int *source,const char *ctx,int type)
{
    unsigned a;
    int b,result;
    if(type!=2) func_02034714(d_02200D00,0,d_02200D00);
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[5];
    out[4]=source[2];
    result=func_021FC4DC(source[0]);
    a=*(unsigned *)(ctx+0x20);
    out[1]=result;
    b=*(int *)(ctx+0x1c);
    out[8]=a;
    out[7]=b;
    out[5]=(*(int **)((char *)source[6]+0xc))[1];
    out[6]=*(int *)((char *)source[6]+8)+0x1748;
    out[9]=*(int *)(ctx+4);
}
