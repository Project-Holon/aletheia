/*
 * function: func_021DF978
 * address: 0x021DF978
 * packet: pkt_ov119_021DF978
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E6308 0x021E6308 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern void func_021E6308(void *,int,int);
typedef unsigned int   u32;
extern void func_021E293C(char *p, int i);
extern void func_021E36D8(void *,int);
extern void func_02041300(int,int,unsigned char,int,int,int,int);
extern void func_02041B6C(u32 bit);
void func_021DF978(void *p)
{
    int i;
    for(i=0;i<2;i++) {
        if (((unsigned char *)p+i)[0x11e2]==0) continue;
        ((unsigned char *)p+i)[0x11e2]--;
        func_021E6308(p,i,0);
        if (((unsigned char *)p+i)[0x11e2]==0) {
            func_021E293C(p,i);
            func_02041300(1,0,(unsigned char)(i<<4),0,16,24,16);
            func_02041B6C(1);
            func_021E36D8(p,i);
            func_021E6308(p,i,1);
        }
    }
}
