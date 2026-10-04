/*
 * function: func_0220DC04
 * address: 0x0220DC04
 * packet: pkt_ov198_0220DC04
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02211B06 0x02211B06 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D6DC 0x0220D6DC thumb ov198
 *   func_0220C694 0x0220C694 thumb ov198
 */
#include "../include/Obj00507.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B06[];
extern const int d_02211B3C[];
extern void func_0220BDA0(char *);
extern void func_0220BEB8(char *,int,int,u8,u8);
extern int func_022110D4(u8 *,int);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D6DC(char *,char *,int);
extern void func_0220C694(char *,int,int);
void func_0220DC04(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211B06;
    func_0220BDA0((char *)p);
    func_0220BEB8((char *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,rec+offset,i+1);
        }
    }
    func_0220C694((char *)p,5,24);
}
