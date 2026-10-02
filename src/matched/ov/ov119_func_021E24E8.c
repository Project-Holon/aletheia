/*
 * function: func_021E24E8
 * address: 0x021E24E8
 * packet: pkt_ov119_021E24E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second func_0201DD78 call, not before the loop.
 * symbols:
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_021E6CB8 0x021E6CB8 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021E6E7C 0x021E6E7C thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void func_0201DD78(u32,u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02045CAC(void *,u32,void *);
extern void func_0201F02C(void *,int,void *);
extern void func_0201F250(void *,void *,void *);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern int func_021D8ADC(char *);
extern void func_021E6CB8(char *);
extern void func_021E6334(char *,int,int,void *,int,u32);
extern void func_021E6E7C(char *);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E15F8(void *,void *,int,int,char *);
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
void func_021E24E8(char *p)
{
    void *arr[2];
    void *mon;
    u32 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    func_021E6CB8(p);
    arr[0]=P(0x834);
    arr[1]=P(0x830);
    func_0201DD78(15,2,0);
    for(j=0;j<2;j++) {
        func_02045CAC(P(0x720),128,P(0x734));
        func_0201F02C(P(0x724),0,arr[j]);
        func_0201F250(P(0x724),P(0x730),P(0x734));
        func_0201C7A4(*(void **)(p+j*16+0x10f4),0,0,P(0x730),P(0x728));
    }
    k=0;
    func_0201DD78(15,2,k);
    for(;k<2;k++) {
        func_0201DD78(1,2,0);
        q1=p+(1-k)*12;
        q2=p+k*16;
        for(n=0;n<3;n++) {
            mon=*(void **)(q1+n*4+0xfd8);
            if(*(int *)(q1+n*4+0xfa4)!=-1) {
                flag76=func_02017E1C(mon,76,0);
                func_021E6334(p,k,n,mon,0,1);
                func_021E1430(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,func_021D8ADC(p),p);
                if(flag76==0) {
                    func_021E1670(mon,*(void **)(q2+n*4+0x10f8),56,16,p,0,func_021D8ADC(p));
                    func_021E15F8(mon,*(void **)(q2+n*4+0x10f8),0,16,p);
                }
            }
        }
    }
    func_021E6E7C(p);
}
