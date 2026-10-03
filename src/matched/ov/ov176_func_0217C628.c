/*
 * function: func_0217C628
 * address: 0x0217C628
 * packet: pkt_ov176_0217C628
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: E1FC and E2C0 return r0 consumed by the original although their own C returns void.
 * symbols:
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0217CEAC 0x0217CEAC thumb ov176
 *   func_0217CFDC 0x0217CFDC thumb ov176
 *   func_0217CFD0 0x0217CFD0 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_0217E078 0x0217E078 thumb ov176
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_020061E4 0x020061E4 thumb
 *   func_0217E0A8 0x0217E0A8 thumb ov176
 *   func_0217E0B0 0x0217E0B0 thumb ov176
 *   func_020362DC 0x020362DC arm
 *   func_0217E158 0x0217E158 thumb ov176
 *   func_0217E178 0x0217E178 thumb ov176
 *   func_0217D388 0x0217D388 thumb ov176
 *   func_0217E1FC 0x0217E1FC thumb ov176
 *   func_0217E23C 0x0217E23C thumb ov176
 *   func_0201A918 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200B078 0x0200B078 thumb
 *   func_0200E994 0x0200E994 thumb
 *   func_02006210 0x02006210 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0217E2C0 0x0217E2C0 thumb ov176
 *   func_0217E2F8 0x0217E2F8 thumb ov176
 *   func_0217E1B8 0x0217E1B8 thumb ov176
 *   func_0217E1C0 0x0217E1C0 thumb ov176
 *   func_02040588 0x02040588 arm
 *   func_0217D1C8 0x0217D1C8 thumb ov176
 *   func_0217D238 0x0217D238 thumb ov176
 *   func_0200AE54 0x0200AE54 thumb
 */
typedef unsigned char u8;
typedef unsigned u32;
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
typedef signed int     s32;
struct Reg;
struct Reg2;
extern void func_0217CEAC(u8 *p, int mode);
extern int func_0217CFDC(u8 *);
extern void func_0217CFD0(u8 *);
extern void func_021E8AA0(int *,int);
extern void func_0217C2EC(int *sys, u32 *state, u8 *p);
extern void * func_0200AE14(void *);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
extern int func_0217E078(u8 *p);
extern void func_021E7E0C(void **,int);
extern void func_020061E4(u32);
extern int func_0217E0A8(int *);
extern int func_0217E0B0(unsigned *);
extern u32 func_020362DC(void);
extern void func_0217E158(unsigned *);
extern int func_0217E178(int *);
extern void func_0217D388(int *,int *);
extern int func_0217E1FC(int,int);
extern int func_0217E23C(char *,void **);
extern int func_0201A918(void);
extern void func_02082D44(const void *,void *,u32);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern u32 func_0200E994(void *base, void *key);
extern void func_02006210(void);
extern int func_020399A8(void);
extern void func_02039C68(u32,u32,u32);
extern u32 func_02039CB4(u32,u32,u32);
extern int func_0217E2C0(void *,u32 *);
extern int func_0217E2F8(u8 *p, const void *q);
extern int func_0217E1B8(int *);
extern int func_0217E1C0(int *);
extern void func_02040588(u32 which, u32 enable);
extern void func_0217D1C8(char *,int);
extern int func_0217D238(u8 *);
extern u32 func_0200AE54(struct Reg *p, u32 id);
void func_0217C628(int *sys,u32 *state,u8 *p)
{
    if(func_0217E078(*(void **)(p+12))==1){
        *(int *)(*(u8 **)(p+0x1c4)+12)=1;
        func_021E8AA0(sys,(int)func_0217C2EC);
    }
    switch(*state){
    case 0:func_0217CFE8(p,20,1);*state=40;func_021E8AB4((u32)sys,1);break;
    case 1:func_0217CFE8(p,33,0);func_021E7E0C(*(void ***)(p+28),1);func_020061E4(0x80d);*(u32 *)(p+0x1d4)=0;*(u32 *)(p+0x1d8)=0;*state=40;func_021E8AB4((u32)sys,2);break;
    case 2:if(func_0217E0A8(*(int **)(p+12)))*state=3;break;
    case 3:switch(func_0217E0B0(*(unsigned **)(p+12))){case 1:*state=13;break;case 2:*state=9;break;}if(func_020362DC()&2)*state=4;break;
    case 4:func_0217E158(*(unsigned **)(p+12));*state=5;break;
    case 5:if(func_0217E178(*(int **)(p+12)))*state=6;break;
    case 6:func_021E7E0C(*(void ***)(p+28),0);func_0217CFE8(p,21,1);*state=40;func_021E8AB4((u32)sys,7);break;
    case 7:func_0217CEAC(p,0);*state=8;break;
    case 8:{
        int v=func_0217CFDC(p);
        if(v!=-1){func_0217CFD0(p);switch(v){
        case 0:func_021E7E0C(*(void ***)(p+28),0);func_021E8AA0(sys,(int)func_0217C2EC);break;
        case 1:*state=1;break;
        }}break;
    }
    case 9:func_021E7E0C(*(void ***)(p+28),0);func_0217E158(*(unsigned **)(p+12));*state=10;break;
    case 10:if(func_0217E178(*(int **)(p+12)))*state=11;break;
    case 11:func_0217CFE8(p,28,1);*state=40;func_021E8AB4((u32)sys,12);break;
    case 12:func_021E8AA0(sys,(int)func_0217C2EC);break;
    case 13:func_0217D388(*(int **)(p+0x1bc),(int *)p);if(func_0217E1FC(*(int *)(p+12),*(int *)(p+0x1bc)))*state=14;break;
    case 14:{
        void *out;
        if(func_0217E23C(*(char **)(p+12),&out)){func_02082D44(out,*(void **)(p+0x1c0),func_0201A918()+0xd4);*state=15;}break;
    }
    case 15:
        if(*(u32 *)(*(u8 **)(p+0x1bc)+0x40)==*(u32 *)(*(u8 **)(p+0x1c0)+0x40)){
            u32 a=func_0200B078(*(void **)(p+0x38),12);
            int b=func_0200E994(*(void **)(p+0x34),*(u8 **)(p+0x1c0)+0x20);
            *(u32 *)(p+0x1d4)=(a!=0||(a==0&&b==0));
            *state=16;
        }else{func_021E7E0C(*(void ***)(p+28),0);func_02006210();*state=21;}
        break;
    case 16:func_02039C68(func_020399A8(),0x48,0x1f);*state=17;break;
    case 17:if(func_02039CB4(func_020399A8(),0x48,0x1f))*state=18;break;
    case 18:if(func_0217E2C0(*(void **)(p+12),(u32 *)(p+0x1d4)))*state=19;break;
    case 19:if(func_0217E2F8(*(void **)(p+12),(u32 *)(p+0x1d8)))*state=20;break;
    case 20:
        func_021E7E0C(*(void ***)(p+28),0);func_02006210();
        if(*(u32 *)(p+0x1d8)&&*(u32 *)(p+0x1d4)){func_020061E4(0x63a);*state=27;}else *state=24;break;
    case 21:if(func_0217E1B8(*(int **)(p+12)))*state=22;break;
    case 22:if(func_0217E1C0(*(int **)(p+12)))*state=23;break;
    case 23:func_0217CFE8(p,22,1);*state=40;func_021E8AB4((u32)sys,39);break;
    case 24:if(func_0217E1B8(*(int **)(p+12)))*state=25;break;
    case 25:if(func_0217E1C0(*(int **)(p+12)))*state=26;break;
    case 26:func_0217CFE8(p,36,1);*state=40;func_021E8AB4((u32)sys,39);break;
    case 27:func_0217CFE8(p,23,1);*state=40;func_021E8AB4((u32)sys,28);break;
    case 28:if((*(u32 *)(p+0x1cc))++>120){*(u32 *)(p+0x1cc)=0;func_02040588(0,0);*state=29;}break;
    case 29:func_0217D1C8((char *)p,*(int *)(p+0x1c0));*state=30;break;
    case 30:if(func_0217D238(p))*state=31;break;
    case 31:if((*(u32 *)(p+0x1cc))++>300){*(u32 *)(p+0x1cc)=0;*state=32;}break;
    case 32:func_02040588(0,1);func_0217CFE8(p,24,1);*state=40;func_021E8AB4((u32)sys,33);break;
    case 33:func_0217CFE8(p,35,2);*state=40;func_021E8AB4((u32)sys,34);break;
    case 34:func_02039C68(func_020399A8(),0x47,0x1f);*state=35;break;
    case 35:if(func_02039CB4(func_020399A8(),0x47,0x1f))*state=36;break;
    case 36:func_02040588(0,1);func_0217CFE8(p,38,2);*state=40;func_021E8AB4((u32)sys,37);break;
    case 37:
        if((*(u32 *)(p+0x1cc))++>60){
            void *v=func_0200AE14(*(void **)(p+0x38));
            *(u32 *)(p+0x1cc)=0;func_0200AE54(v,19);*state=38;
        }break;
    case 38:func_0217D010(p,2);break;
    case 39:func_021E8AA0(sys,(int)func_0217C2EC);break;
    case 40:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
