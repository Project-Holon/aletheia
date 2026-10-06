/*
 * function: func_0220DE4C
 * address: 0x0220DE4C
 * packet: pkt_ov198_0220DE4C
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B0D 0x02211B0D data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D6DC 0x0220D6DC thumb ov198
 *   sub_0201BD28 0x0201BD28 thumb
 */
#include "../include/Obj00507.h"
#include "../include/Obj25183.h"
#include "../include/Obj25184.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B0D[];
extern const int d_02211B3C[];
extern void func_0220BDA0(u8 *p);
extern void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern int func_022110D4(u8 *,int);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D6DC(char *p, u8 *record, int slot);
extern unsigned sub_0201BD28(u16,unsigned);
void func_0220DE4C(char *p) {
    long i;
    int offset;
    char *base,*rec;
    u16 value;
    u8 local[8];
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B0D;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base=p+0x30;
    for(i=0;i<4u;i++) {
        offset=i*8;
        value=((u16 *)(rec=base+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76))[i*4];
        if(value==0) *(u8 *)(p+offset+0x1f7c)=1;
        else {
            func_0220C4DC(p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC(p,(u8 *)(rec+offset),i+1);
        }
    }
    func_0220C4DC(p,((struct Obj25183 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5,0x53,65535,7,0x3dc0);
    local[2]=sub_0201BD28(((struct Obj25184 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
    local[3]=local[2];
    func_0220D6DC(p,(u8 *)local,5);
}
