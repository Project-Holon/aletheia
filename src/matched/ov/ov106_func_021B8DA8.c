/*
 * function: func_021B8DA8
 * address: 0x021B8DA8
 * packet: pkt_ov106_021B8DA8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return, before 0x021B8E50.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 */
extern int func_02035D20(int *,int *);
extern int func_02035CB8(int *,int *);
extern unsigned int func_020362DC(void);
extern unsigned int func_0203630C(void);
void func_021B8DA8(int *p) {
    int x,y;
    int d;
    if(func_02035D20(&x,&y)) {
        p[0]=x;p[1]=y;p[2]=x;p[3]=y;p[4]=x;p[5]=y;
        p[6]=0;p[7]=0;p[8]=0;
    } else if(func_02035CB8(&x,&y)) {
        d=y-p[1];
        if(d<0)d=-d;
        if(d>=1) {
            p[6]=x-p[4];p[7]=y-p[5];p[4]=x;p[5]=y;
        }
        p[2]=x;p[3]=y;p[8]++;p[9]=0;
    } else p[9]++;
    if(func_020362DC()&192) {p[10]=0;return;}
    if(func_0203630C()&192)p[10]++;
}
