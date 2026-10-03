/*
 * function: func_021BC350
 * address: 0x021BC350
 * packet: pkt_ov091_021BC350
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BBE74 0x021BBE74 thumb ov091
 *   func_021BB464 0x021BB464 thumb ov091
 *   func_02018430 0x02018430 thumb
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9EC 0x021BB9EC thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_020457B0 0x020457B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02027268 0x02027268 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BCC2C 0x021BCC2C thumb ov091
 *   func_021BCC80 0x021BCC80 thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BCC40 0x021BCC40 thumb ov091
 *   func_021BC5CC 0x021BC5CC thumb ov091
 *   func_021BC6A0 0x021BC6A0 thumb ov091
 *   func_021BC548 0x021BC548 thumb ov091
 *   func_021B9E44 0x021B9E44 thumb ov091
 *   d_021BECE4 0x021BECE4 data ov091 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021BBE74(int);
extern u16 func_021BB464(u8 *,int);
extern int func_02018430(int);
extern void func_021BB97C(u8 *,int);
extern void func_021BB99C(u8 *,int,int,int);
extern void func_021BB9EC(u8 *,int,int,u16,u8);
extern void func_021B9788(u8 *,int,int,void (*)(int));
typedef unsigned int   u32;
extern void func_021BB98C(void *p, u32 s);
extern int func_020457B0(unsigned,unsigned);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02027268(int);
extern void func_02045808(int);
extern int func_021BCC2C(int,int,int);
extern void func_021BCC80(u8 *,int,int);
extern void func_021BB9CC(u8 *,int,int,u16);
extern void func_021BCC40(u8 *,int);
extern void func_021BC5CC(int);
extern void func_021BC6A0(int);
extern void func_021BC548(int);
extern void func_021B9E44(int);
extern u16 d_021BECE4[];
#define W(k) (*(int *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
int func_021BC350(u8 *p,int v)
{
    int n=func_021BBE74(*(u16 *)(W(0x280)+0x44));
    int t;
    u8 i;
    u16 z;
    switch(n) {
    case 0:case 8:case 10:case 25:case 29:break;
    case 1:{
        int row=W(0x2c);
        *(u8 *)(p+12)=10;
        H(0x11c)=func_021BB464(p,*(int *)(p+row*4+0x160));
        W(0x120)=(int)func_021BC5CC;
        break;
    }
    case 2:
        t=func_02018430(W(0x38));
        func_021BB97C(p,W(0x150));
        func_021BB99C(p,W(0x150),0,W(0x38));
        func_021BB9EC(p,W(0x150),1,t+1,3);
        func_021B9788(p,0x9d,1,func_021BC6A0);
        func_021BB98C(p,W(0x150));
        t=func_020457B0(12,H(0));
        func_02017E1C((void *)W(0x38),0x73,t);
        func_02027268(t);
        func_02045808(t);
        for(i=0;i<6;i++) {
            int j=i*2;
            *(u16 *)(p+j+0x124)=func_02017E1C((void *)W(0x38),*(u16 *)((u8 *)d_021BECE4+j),0);
        }
        break;
    case 3:func_021BCC40(p,0x47);break;
    case 4:func_021BCC40(p,0x2d);break;
    case 5:func_021BCC40(p,0x2f);break;
    case 6:func_021BCC40(p,0x30);break;
    case 7:func_021BCC40(p,0x2e);break;
    case 9:func_021BCC40(p,0x33);break;
    case 11:case 12:{
        int row=W(0x2c);
        *(u8 *)(p+12)=10;
        H(0x11c)=func_021BB464(p,*(int *)(p+row*4+0x160));
        W(0x120)=(int)func_021BC548;
        break;
    }
    case 13:case 14:case 15:case 16:case 17:case 18:
        func_021BCC80(p,0x37,(u16)(n-13));break;
    case 19:case 20:case 21:case 22:case 23:case 24:
        z=n-19;
        if(func_021BCC2C(W(0x38),z+13,*(u16 *)(W(0x280)+0x44))==0) func_021BCC80(p,0x55,z);
        else if(func_02017E1C((void *)W(0x38),9,0)==255) func_021BCC80(p,0x54,z);
        else func_021BCC80(p,0x53,z);
        break;
    case 26:case 27:
        func_021BB97C(p,W(0x150));
        func_021BB9CC(p,W(0x150),0,v);
        func_021B9788(p,0x34,1,func_021B9E44);
        func_021BB98C(p,W(0x150));
        break;
    case 28:func_021BCC40(p,0x31);break;
    }
    return n;
}
