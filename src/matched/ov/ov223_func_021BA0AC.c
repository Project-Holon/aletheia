/*
 * function: PSEL_InterpolateCurve
 * address: 0x021BA0AC
 * packet: pkt_ov223_021BA0AC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u16 register parameters reproduce spill ordering; a named s16 result preserves narrowing after float conversion.
 * symbols:
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
int PSEL_InterpolateCurve(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time)
{
    float x,y,arc,scale;
    s16 px,py,result;
    int fixed;
    x=(float)a+(float)time*((float)c-(float)a)/(float)duration;
    y=(float)b+(float)time*((float)d-(float)b)/(float)duration;
    arc=4.0f*((0.0f-(float)amplitude)*((float)time-(float)duration/2.0f)*((float)time-(float)duration/2.0f))/(float)duration/(float)duration+(float)amplitude;
    scale=(float)e+(float)time*((float)f-(float)e)/(float)duration;
    px=(s16)x;
    py=(s16)(y-arc);
    fixed=FIX(scale/16.0f);
    pos[0]=px;pos[1]=py;
    size[0]=size[1]=fixed;
    result=(s16)y;
    return result;
}
