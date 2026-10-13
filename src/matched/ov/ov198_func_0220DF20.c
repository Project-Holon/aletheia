/*
 * function: func_0220DF20
 * address: 0x0220DF20
 * packet: pkt_ov198_0220DF20
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B2C 0x02211B2C data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_0220C5AC 0x0220C5AC thumb ov198
 *   func_0220D034 0x0220D034 thumb ov198
 *   func_0220D1BC 0x0220D1BC thumb ov198
 *   func_0220D3B4 0x0220D3B4 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D090 0x0220D090 thumb ov198
 *   func_0220D218 0x0220D218 thumb ov198
 *   func_0220D348 0x0220D348 thumb ov198
 *   func_0220D418 0x0220D418 thumb ov198
 *   func_0220D494 0x0220D494 thumb ov198
 *   func_0220D628 0x0220D628 thumb ov198
 *   sub_0201BD28 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 */
#include "../include/Obj00507.h"
#include "../include/Obj25185.h"
#include "../include/Obj25186.h"
#include "../include/Obj25187.h"
#include "../include/Obj25188.h"
#include "../include/Obj25189.h"
#include "../include/Obj25190.h"
#include "../include/Obj25191.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B2C[];
extern const int d_02211B3C[];
extern void func_0220BDA0(u8 *p);
extern void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void func_0220C5AC(char *,int,u16,u16);
extern void func_0220D034(char *,int),func_0220D1BC(char *,int),func_0220D3B4(char *,int);
extern int func_022110D4(u8 *,int);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D090(char *,int,int),func_0220D218(char *,int,unsigned);
extern void func_0220D348(char *,int,int),func_0220D418(char *,int,int);
extern void func_0220D494(u8 *p, int slot, int a2, int a3);
extern void func_0220D628(char *,int);
extern unsigned sub_0201BD28(u16,unsigned);
typedef unsigned int   u32;
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
void func_0220DF20(char *p) {
    unsigned index,offset,type;
    char *base,*rec;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B2C;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    func_0220C5AC(p,2,0,0);
    func_0220D034(p,4);
    func_0220D1BC(p,5);
    func_0220D3B4(p,9);
    index=(*(u8 **)p)[0x4b];
    if(index<4) {
        base=p+0x30+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76;
        offset=index*8;
        rec=base+offset;
        func_0220C4DC(p,*(u16 *)(base+offset),1,d_02211B3C[index],0,0,0x3dc0);
        func_0220D090(p,6,(u8)rec[6]);
        func_0220D218(p,7,(u8)rec[7]);
        func_0220D348(p,8,*(u16 *)(base+offset));
        func_0220D418(p,10,(u8)rec[5]);
        func_0220D494((u8 *)p,3,(u8)rec[2],(u8)rec[3]);
    } else {
        type=sub_0201BD28(((struct Obj25185 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
        func_0220C4DC(p,((struct Obj25186 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,1,0x53,0,0,0x3dc0);
        func_0220D348(p,8,((struct Obj25187 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26);
        if(WAZA_TOOL_IsAlwaysHit(((struct Obj25188 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26)==1) func_0220D090(p,6,0);
        else func_0220D090(p,6,sub_0201BD28(((struct Obj25189 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,4));
        func_0220D218(p,7,sub_0201BD28(((struct Obj25190 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,3));
        func_0220D418(p,10,sub_0201BD28(((struct Obj25191 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,2));
        func_0220D494((u8 *)p,3,type,type);
    }
    func_0220D628(p,11);
}
