/*
 * function: func_0217BFF8
 * address: 0x0217BFF8
 * packet: pkt_ov176_0217BFF8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217D028 0x0217D028 thumb ov176
 *   func_0217D1A0 0x0217D1A0 thumb ov176
 *   func_0217D244 0x0217D244 thumb ov176
 *   func_0217D188 0x0217D188 thumb ov176
 *   func_0217D2A4 0x0217D2A4 thumb ov176
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_0217CEAC 0x0217CEAC thumb ov176
 *   func_0217CFDC 0x0217CFDC thumb ov176
 *   func_0217CFD0 0x0217CFD0 thumb ov176
 *   func_0217D2B0 0x0217D2B0 thumb ov176
 *   func_0217D290 0x0217D290 thumb ov176
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0217D2BC 0x0217D2BC thumb ov176
 *   func_0201AA50 0x0201AA50 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_0217D194 0x0217D194 thumb ov176
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_0200BBC8 0x0200BBC8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_0200B2A4 0x0200B2A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned u32;
extern void func_0217D028(u8 *);
extern void func_0217D1A0(u8 *,int);
extern void func_0217D244(char *);
extern int func_0217D188(u8 *);
extern int func_0217D2A4(u8 *);
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
extern void func_0217CEAC(u8 *,unsigned);
extern int func_0217CFDC(u8 *);
extern void func_0217CFD0(u8 *);
extern int func_0217D2B0(u8 *);
extern void func_0217D290(u8 *);
extern void * func_0200AE14(void *);
extern void func_0217D2BC(u8 *,void *);
extern u32 func_0201AA50(void *);
extern int func_0201A090(void *,void *,u32 *);
extern int func_0217D194(u8 *);
extern void func_0217D174(int *);
extern void * func_02012EBC(void *);
extern void * func_0200BAC8(void *);
extern void * func_0200B358(void *);
extern void * func_0200B204(void *,u32);
extern void * func_0200BAF4(int,int);
extern void func_0200BBC8(void *,u32);
extern void func_0200B110(void *,u32,int);
extern void func_0200B2A4(int,int);
extern void func_020307B0(void *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021E8AA0(int *,int);
extern void func_0217C2EC(void);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
void func_0217BFF8(int *sys,u32 *state,u8 *p)
{
    switch(*state){
    case 0:func_0217D028(p);func_0217D1A0(p,2);func_0217D244((char *)p);*state=1;break;
    case 1:{
        int flag=1;
        flag&=func_0217D188(p);
        flag&=func_0217D2A4(p);
        if(flag)*state=2;break;
    }
    case 2:func_0217CFE8(p,5,1);*state=21;func_021E8AB4((u32)sys,3);break;
    case 3:func_0217CEAC(p,0);*state=4;break;
    case 4:{
        int v=func_0217CFDC(p);
        if(v!=-1){func_0217CFD0(p);switch(v){case 0:*state=8;break;case 1:*state=5;break;}}break;
    }
    case 5:func_0217CFE8(p,8,1);*state=21;func_021E8AB4((u32)sys,6);break;
    case 6:func_0217CEAC(p,0);*state=7;break;
    case 7:{
        int v=func_0217CFDC(p);
        if(v!=-1){func_0217CFD0(p);switch(v){case 0:*state=19;break;case 1:*state=2;break;}}break;
    }
    case 8:if(func_0217D2B0(p)){func_0217D290(p);*state=9;}break;
    case 9:{
        u32 mask=0;
        void *v=func_0200AE14(*(void **)(p+0x38));
        func_0217D2BC(p,*(void **)(p+0x30));
        if(func_0201AA50(*(void **)(p+0x30))==0)*state=11;
        else if(func_0201A090(v,*(void **)(p+0x30),&mask)==0)*state=13;
        else *state=10;
        break;
    }
    case 10:func_0217CFE8(p,9,1);*state=21;func_021E8AB4((u32)sys,12);break;
    case 11:func_0217CFE8(p,37,1);*state=21;func_021E8AB4((u32)sys,12);break;
    case 12:if(func_0217D194(p)){func_0217D174((int *)p);*state=20;}break;
    case 13:{
        void *base=func_02012EBC(*(void **)(p+0x1b8));
        void *rules=func_0200BAC8(base);
        void *entry=func_0200B204(func_0200B358(base),1);
        void *tmp=func_0200BAF4((int)rules,0x8056);
        func_0200BBC8(rules,2);
        func_0200B110(*(void **)(p+0x38),10,2);
        func_0200B2A4((int)entry,(int)tmp);
        func_020307B0(tmp);
        *state=14;break;
    }
    case 14:func_0217CFE8(p,10,2);*state=21;func_021E8AB4((u32)sys,15);break;
    case 15:func_02012DAC(*(int *)(p+0x1b8));*state=16;break;
    case 16:if(func_02012DD0(*(u8 **)(p+0x1b8))==2)*state=17;break;
    case 17:func_0217D1A0(p,0);func_0217CFE8(p,11,1);*state=21;func_021E8AB4((u32)sys,18);break;
    case 18:func_021E8AA0(sys,(int)func_0217C2EC);break;
    case 19:{
        int flag=1;
        flag&=func_0217D194(p);
        flag&=func_0217D2B0(p);
        if(flag){func_0217D174((int *)p);func_0217D290(p);*state=20;}break;
    }
    case 20:func_0217D010(p,1);break;
    case 21:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
