/*
 * function: func_021D83DC
 * address: 0x021D83DC
 * packet: pkt_ov121_021D83DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware argument 04001050 passed to blend helper
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045808 0x02045808 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_021D694C 0x021D694C thumb ov121
 *   d_021DF544 0x021DF544 data a4
 */
typedef unsigned char u8;
typedef struct { int w[12]; } Config;
extern const Config d_021DF544;
extern void *func_020457B0(int,int);
extern void func_02045994(void *,void *,int);
extern void func_02045808(void *);
extern void func_020409B4(int);
extern void func_02040588(int,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void *func_021DA1BC(int,Config *,int,int,int,void *,void *,void *,int);
extern void func_021D694C(void *,int);
void func_021D83DC(u8 *p,int heap)
{
    Config c;
    if(*(void **)(p+652)==0) {
        c=d_021DF544;
        c.w[2]=(int)func_020457B0(37,heap);
        func_02045994((void *)c.w[2],p+1068,37);
        c.w[8]=(int)func_020457B0(253,heap);
        func_02045994((void *)c.w[8],p+1180,253);
        *(void **)(p+652)=func_021DA1BC(0,&c,2,4,15,*(void **)(p+924),*(void **)(p+932),*(void **)(p+920),heap);
        func_02045808((void *)c.w[2]);
        func_02045808((void *)c.w[8]);
        func_021D694C(p+912,1);
        func_020409B4(6);
        func_02040588(6,1);
        func_0207D63C((void *)0x04001050,4,24,15,3);
    }
}
