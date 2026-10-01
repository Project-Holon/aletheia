/*
 * function: func_021DB89C
 * address: 0x021DB89C
 * packet: pkt_ov119_021DB89C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   func_02035C38 0x02035C38 arm
 */
typedef short s16;
extern unsigned func_02035CB8(int *,int *);
extern void func_0204B92C(int,int),func_021DB7AC(char *,int,int);
extern int func_02035C38(void);
#define H(o) (*(s16 *)(p+(o)))
#define I(o) (*(int *)(p+(o)))
void func_021DB89C(char *p)
{
    int x,y,i;
    if(I(0xf60)) return;
    if(func_02035CB8(&x,&y)) {
        if(I(0x1088)) {
            if((unsigned)x>=64 && (unsigned)x<192 && (unsigned)y>=168 && (unsigned)y<188) {
                int previous;
                func_0204B92C(I(0xf04),1);
                previous=H(0x1078);
                H(0x107a)=(x-previous)*2;
                H(0x1078)=x;
                H(0x107c)-=H(0x107a);
                if(H(0x107a)>12) func_021DB7AC(p,1,1);
                else func_021DB7AC(p,0,1);
            } else H(0x107a)=0;
        }
        H(0x1078)=x;
    } else H(0x1078)=0;
    if(func_02035C38()==0 && H(0x107a)!=0) {
        for(i=2;i!=0 && H(0x107a)!=0;i--) {
            if(H(0x107a)<0) H(0x107a)++;
            if(H(0x107a)>0) H(0x107a)--;
        }
        H(0x107c)-=H(0x107a);
        func_021DB7AC(p,1,1);
    }
}
