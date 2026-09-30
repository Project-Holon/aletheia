/*
 * function: func_021E6440
 * address: 0x021E6440
 * packet: pkt_ov119_021E6440
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   d_021E7DA0 0x021E7DA0 data a4
 */
typedef struct { short x,y; } Pt;
extern const int d_021E7DA0[6][2];
extern void func_0204B404(int,const Pt *,unsigned int);
void func_021E6440(int p, int a, int b) {
    int i,j;
    Pt pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (*(int *)(p+i*12+j*4+0x1008)) {
                pos.x=d_021E7DA0[i*3+j][0]; pos.y=d_021E7DA0[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                func_0204B404(*(int *)(p+i*12+j*4+0x1008),&pos,1);
            }
        }
    }
}
