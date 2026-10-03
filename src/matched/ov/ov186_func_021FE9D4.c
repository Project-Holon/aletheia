/*
 * function: func_021FE9D4
 * address: 0x021FE9D4
 * packet: pkt_ov186_021FE9D4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021FEA84 and 021FEACC write the engine-A/B blend coefficients.
 * abi: E6E0's r0 return is consumed.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0207D63C(u32,int,int,int,int);
extern int func_0204E6E0(void);
extern int func_0209C0A4(int,int);
extern u32 _u32_div_f(u32,u32);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
int func_021FE9D4(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int a,b,duration;
        if(*(int *)(p+8)==0){a=0;b=16;}
        else if(*(int *)(p+8)==1){a=16;b=0;}
        if(*(int *)(p+4)&1)func_0207D63C(0x04000050,7,31,a,b);
        if(*(int *)(p+4)&2)func_0207D63C(0x04001050,3,7,a,b);
        *(u32 *)(p+0x10)=0;
        duration=*(int *)(p+0x18);
        if(duration==0)duration=func_0209C0A4(16,func_0204E6E0());
        *(u32 *)(p+0x14)=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        if(*(int *)(p+8)==0){b=_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14));a=16-b;}
        else if(*(int *)(p+8)==1){a=_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14));b=16-a;}
        if(*(int *)(p+4)&1) {
            *(volatile u16 *)0x04000052=b|(a<<8);
            if(b==0){func_020434DC(1,0);func_020434DC(2,0);func_020434DC(4,0);}
            else{func_020434DC(1,1);func_020434DC(2,1);func_020434DC(4,1);}
        }
        if(*(int *)(p+4)&2) {
            *(volatile u16 *)0x04001052=b|(a<<8);
            if(b==0){func_02043598(1,0);func_02043598(2,0);}
            else{func_02043598(1,1);func_02043598(2,1);}
        }
        if((*(u32 *)(p+0x10))++ >= *(u32 *)(p+0x14))*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}
