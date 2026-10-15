/*
 * function: DUP_FITTING_HitCircle
 * address: 0x021B8FF4
 * packet: pkt_ov133_021B8FF4
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 */
int DUP_FITTING_HitCircle(int x,int y,int radius,float scale) {short k=(short)((float)x*scale);if(k*k+y*y<radius*radius)return 1;return 0;}
