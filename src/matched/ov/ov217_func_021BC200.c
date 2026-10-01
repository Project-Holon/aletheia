/*
 * function: func_021BC200
 * address: 0x021BC200
 * packet: pkt_ov217_021BC200
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC40C 0x021BC40C thumb ov217
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
extern int func_021BC40C(void *p);
typedef enum { ZERO = 0 } Origin;
int func_021BC200(void *p,int position)
{
    float ratio;
    int height;
    float zero;
    Origin origin;
    if(position<32)position=32;
    if(position>160)position=160;
    ratio=(float)(position-32)/128.0f;
    height=func_021BC40C(p)+24;
    origin=ZERO;
    zero=(float)origin;
    return (int)(zero+ratio*(float)height);
}
