/*
 * function: func_021B95F4
 * address: 0x021B95F4
 * packet: pkt_ov205_021B95F4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Case3 early nonzero break restores the branch stub; case9 separate calls in if/else restore its independent fade BL. Fixed one EXACT, 624 bytes, 43/43 resolved.
 * volatile: DISPCNT 0x04000000 read at 021B9650 and written at 021B965A.
 * symbols:
 *   init 0x021B9E50 data a2
 *   func_020362DC 0x020362DC arm
 *   func_021B9874 0x021B9874 thumb ov205
 *   func_020111E8 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B99E4 0x021B99E4 thumb ov205
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02012DAC 0x02012DAC thumb
 *   func_021B9A68 0x021B9A68 thumb ov205
 *   func_021B9A94 0x021B9A94 thumb ov205
 *   func_021B9B04 0x021B9B04 thumb ov205
 *   func_021B9AD8 0x021B9AD8 thumb ov205
 *   func_021B9B20 0x021B9B20 thumb ov205
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_021B9B78 0x021B9B78 thumb ov205
 *   func_02012DD0 0x02012DD0 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021B9928 0x021B9928 thumb ov205
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0202F0B0 0x0202F0B0 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 value;} Init;
extern const Init init;
extern void func_020362DC(void);
extern void func_021B9874(char *,const char *);
extern u32 func_020111E8(void);
extern void func_0207E468(void *,u32,u32);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_020061E4(u32);
extern void func_021B99E4(char *,u32,u32,u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_020409B4(u8);
extern int func_02012DAC(int);
extern void func_021B9A68(char *);
extern void func_021B9A94(char *);
extern void func_021B9B04(char *);
extern void func_021B9AD8(char *);
extern void func_021B9B20(char *);
extern void *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_021B9B78(char *);
extern int func_02012DD0(void *);
extern void func_0202F038(void *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u32);
extern void func_021B9928(char *);
extern int func_02028484(void *,void *);
extern void func_020310C4(void *);
extern void func_0202F0B0(void *);
typedef enum { ST0=0,ST13=13 } State;
int func_021B95F4(void *unused,State *state,const char *context,char *p)
{
    Init local;
    void *obj;
    enum { M3=3,M12=12 } mode;
    local=init;
    func_020362DC();
    switch(*state){
    case 0:func_021B9874(p,context);(*state)++;break;
    case 1:
    {
        enum { Z0,Z1 } zero;
        zero=0;
        *(u16 *)0x04000050=zero;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&0xffffe0ff)|256;
        if(func_020111E8()==21)mode=3;
        else {func_0207E468(&local,zero,2);mode=12;}
        func_0204E720(mode,16,zero,zero);(*state)++;break;
    }
    case 2:if(!func_0204E804())*state=3;break;
    case 3:
        if(*(u32 *)(p+64)!=0){ (*state)++; break; }
        {
            func_020061E4(0x54c);func_021B99E4(p,3,0,0);
            obj=*(void **)(p+28);func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            *(u32 *)(p+68)=4;*state=13;func_02012DAC(*(int *)(p+4));
        }
        break;
    case 4:
        if(*(u32 *)(p+64)==0){
            if(*(u32 *)(context+4)==0){func_021B9A68(p);func_021B9A94(p);}
            else {func_021B9B04(p);func_021B9AD8(p);func_021B9B20(p);}
        }
        *(void **)(p+48)=func_0202EE8C(*(u32 *)(p+36),*(void **)(p+28),15,16,*(u16 *)p);
        (*state)++;break;
    case 5:
        if(*(u32 *)(p+64)==0 && *(u32 *)(p+56)!=0){
            func_021B9B78(p);
            if(*(u32 *)(p+60)!=0)(*state)++;
        }else (*state)++;
        break;
    case 6:
        if(*(u32 *)(p+64)==0){
            switch(func_02012DD0(*(void **)(p+4))){
            case 0:case 1:break;
            case 2:*(u32 *)(p+52)=1;(*state)++;break;
            case 3:*(u32 *)(p+52)=0;(*state)++;break;
            }
        }else (*state)++;
        break;
    case 7:
        func_0202F038(*(void **)(p+48));
        if(*(u32 *)(p+64)==0 && *(u32 *)(p+52)!=0){
            func_021B99E4(p,4,0,0);
            obj=*(void **)(p+28);func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            *(u32 *)(p+68)=8;*state=13;func_020061E4(0x558);
        }else{
            func_021B99E4(p,5,0,0);
            obj=*(void **)(p+28);func_02045334(obj);func_02045374(obj);func_020409B4(func_02045730(obj));
            *(u32 *)(p+68)=8;*state=13;
        }
        break;
    case 8:
        if(*(int *)(p+72)>120)(*state)++;
        (*(int *)(p+72))++;break;
    case 9:
        if(func_020111E8()==21){ func_0204E720(3,0,16,0); }
        else { func_0204E720(12,0,16,0); }
        (*state)++;break;
    case 10:
        if(!func_0204E804()){func_02043B5C(func_02045770(*(void **)(p+28)),15);(*state)++;}
        break;
    case 11:func_021B9928(p);(*state)++;break;
    case 12:return 1;
    case 13:
        if(func_02028484(p+40,*(void **)(p+32)))*state=*(u32 *)(p+68);
        break;
    }
    if(*(void **)(p+36))func_020310C4(*(void **)(p+36));
    if(*(void **)(p+48))func_0202F0B0(*(void **)(p+48));
    return 0;
}
