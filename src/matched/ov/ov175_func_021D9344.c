/*
 * function: func_021D9344
 * address: 0x021D9344
 * packet: pkt_ov175_021D9344
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021D98E4 0x021D98E4 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_021D9A08 0x021D9A08 thumb ov175
 *   func_021D97E4 0x021D97E4 thumb ov175
 *   func_021DD020 0x021DD020 thumb ov175
 *   func_021DC8B4 0x021DC8B4 thumb ov175
 *   func_021DC908 0x021DC908 thumb ov175
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj00781.h"
#include "../include/Obj08278.h"
#include "../include/Obj24288.h"
#include "../include/Obj24292.h"
#include "../include/Obj24293.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct Big;
typedef struct { u8 a,b,c,d; u32 id; } Request;
extern void func_021E8738(int *,int,int,int);
extern void func_021E8AB4(u32,u32),func_021E8AB8(u32);
extern void func_021E8AA8(int);
extern int func_021E8844(const int *);
extern void func_021D98E4(u32 *,int),func_021D99F4(char *),func_021D97E4(char *,u32);
extern int func_021D9A08(char *);
extern u32 func_021DD020(char *);
extern void func_021DC8B4(char *,void *,unsigned);
extern int func_021DC908(char *);
extern void *func_02012EBC(struct Big *),*func_0200BAC8(void *);
typedef signed int     s32;
typedef unsigned short u16;
struct Obj;
struct Reg2;
extern void func_0200BBD8(struct Obj *p, int v);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern int func_02012DAC(int),func_02012DD0(u8 *);
extern void func_02082BCC(void *,int,u32);
void func_021D9344(u32 sys,int *state,char *p) {
    char *ctx=*(char * *)&((struct Obj00781 *)p)->f104;
    int r;
    Request request;
    switch(*state) {
    case 0:
        r=((struct Obj24288 *)(*(char * *)&((struct Obj08278 *)ctx)->f30))->f5;
        if((u8)(r+255)<=1) { ((struct Obj00781 *)p)->f40=1; *state=2; }
        else { ((struct Obj00781 *)p)->f40=2; *state=1; }
        break;
    case 1:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,82,1);
        *state=16; func_021E8AB4(sys,15); break;
    case 2:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,83,1);
        *state=16; func_021E8AB4(sys,3); break;
    case 3: func_021D98E4((u32 *)p,5); *state=4; break;
    case 4:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,84,1);
        *state=16; func_021E8AB4(sys,6); break;
    case 6: func_021D98E4((u32 *)p,5); *state=7; break;
    case 7:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,40,2);
        *state=16; func_021E8AB4(sys,9); break;
    case 9:
        func_0200BBD8(func_0200BAC8(func_02012EBC(**(struct Big ** *)&((struct Obj08278 *)ctx)->f8)),1);
        func_0200B110((struct Reg2 *)(((struct Obj00781 *)p)->f108),10,4);
        func_02012DAC(**(int * *)&((struct Obj08278 *)ctx)->f8); *state=10; break;
    case 10:
        r=func_02012DD0(**(u8 ** *)&((struct Obj08278 *)ctx)->f8);
        if(r==2) { ((struct Obj00781 *)p)->f40=0; *state=11; }
        else if(r==3) *state=15;
        break;
    case 11:
        func_021D97E4(p,1);
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,81,1);
        *state=16; func_021E8AB4(sys,12); break;
    case 12:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,70,2);
        *state=16; func_021E8AB4(sys,13); break;
    case 13:
        func_02082BCC(&request,0,8); request.b=4;
        request.id=func_021DD020(*(char * *)&((struct Obj00781 *)p)->f34);
        ((struct Obj24293 *)(*(char * *)&((struct Obj24292 *)(*(char * *)&((struct Obj00781 *)p)->f104))->f30))->f5=4;
        func_021DC8B4(*(char * *)&((struct Obj00781 *)p)->f34,&request,87); *state=14; break;
    case 14:
        r=func_021DC908(*(char * *)&((struct Obj00781 *)p)->f34);
        if(r==1) *state=15;
        else if(r==3) { ((struct Obj00781 *)p)->f40=3; *state=15; }
        break;
    case 15: func_021E8AA8(sys); break;
    case 16: if(func_021E8844(*(int * *)&((struct Obj00781 *)p)->f2C)) func_021E8AB8(sys); break;
    }
}
