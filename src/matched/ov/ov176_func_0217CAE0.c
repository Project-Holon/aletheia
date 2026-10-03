/*
 * function: func_0217CAE0
 * address: 0x0217CAE0
 * packet: pkt_ov176_0217CAE0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217E078 0x0217E078 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217C2EC 0x0217C2EC thumb ov176
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_0217E1B8 0x0217E1B8 thumb ov176
 *   func_0217E1C0 0x0217E1C0 thumb ov176
 *   func_0200E918 0x0200E918 thumb
 *   func_0200E958 0x0200E958 thumb
 *   func_0200E978 0x0200E978 thumb
 *   func_02034714 0x02034714 arm
 *   func_0200E920 0x0200E920 thumb
 *   func_0217D160 0x0217D160 thumb ov176
 *   func_0217CFE8 0x0217CFE8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_0217D010 0x0217D010 thumb ov176
 *   func_0217D000 0x0217D000 thumb ov176
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   d_0217E618 0x0217E618 data a4
 */
typedef unsigned char u8;
typedef unsigned u32;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
extern int func_0217E078(u8 *p);
extern void func_021E8AA0(int *,int);
extern void func_0217C2EC(int *sys, u32 *state, u8 *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern int func_0217E1B8(int *);
extern int func_0217E1C0(int *);
extern u32 func_0200E918(const u8 *,u32);
extern void func_0200E958(u8 *,u32,const void *);
extern void func_0200E978(u8 *,u32,u32,u8);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0200E920(u8 *,u32,int);
extern void func_0217D160(int *);
extern void func_0217CFE8(void *,int,int);
extern void func_021E8AB4(u32,u32);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_0217D010(u8 *,int);
extern int func_0217D000(u8 *);
extern void func_021E8AB8(u32);
extern const char d_0217E618[];
void func_0217CAE0(int *sys,u32 *state,u8 *p)
{
    if(func_0217E078(*(void **)(p+12))==1){
        *(int *)(*(u8 **)(p+0x1c4)+12)=1;
        func_021E8AA0(sys,(int)func_0217C2EC);
    }
    switch(*state){
    case 0:{
        void *v=func_0200ED48(func_02012EBC(*(void **)(p+0x1b8)));
        func_0200ED54(v,func_02008530(*(void **)(p+0x1c0)));
        *state=1;break;
    }
    case 1:if(func_0217E1B8(*(int **)(p+12))) *state=2;break;
    case 2:if(func_0217E1C0(*(int **)(p+12))) *state=3;break;
    case 3:{
        int a=0;
        int b;
        u8 index=func_0200E918(*(u8 **)(p+0x34),0);
        func_0200E958(*(u8 **)(p+0x34),index,*(u8 **)(p+0x1c0)+0x20);
        func_0200E978(*(u8 **)(p+0x34),index,0,(*(u8 **)(p+0x1c4))[8]);
        func_0200E978(*(u8 **)(p+0x34),index,1,(*(u8 **)(p+0x1c4))[9]);
        b=0;
        switch(**(u32 **)(p+0x1c4)){
        case 1:case 4:a=1;break;
        case 0:case 3:b=1;break;
        case 2:break;
        default:func_02034714(d_0217E618,0,d_0217E618);break;
        }
        func_0200E920(*(u8 **)(p+0x34),1,a);
        func_0200E920(*(u8 **)(p+0x34),2,b);
        func_0200E920(*(u8 **)(p+0x34),0,1);
        func_0217D160((int *)p);
        *state=4;break;
    }
    case 4:func_0217CFE8(p,10,2);*state=8;func_021E8AB4((u32)sys,5);break;
    case 5:func_02012DAC(*(int *)(p+0x1b8));*state=6;break;
    case 6:if(func_02012DD0(*(u8 **)(p+0x1b8))==2)*state=7;break;
    case 7:func_0217D010(p,3);break;
    case 8:if(func_0217D000(p))func_021E8AB8((u32)sys);break;
    }
}
