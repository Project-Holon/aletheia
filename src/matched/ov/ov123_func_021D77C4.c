/*
 * function: func_021D77C4
 * address: 0x021D77C4
 * packet: pkt_ov123_021D77C4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7798 0x021D7798 thumb ov123
 *   func_0203F1FC 0x0203F1FC arm
 *   MUSICAL_DIST_SAVE_CreateFromData  0x0200C5C8  thumb  arm9
 */
#include "../include/Obj02837.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D5BA0(char *p);
typedef unsigned int   u32;
extern u16 func_0203F1FC(const u8 *src, u32 len);
struct MusicalDist;
extern struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *sys, const void *src, u32 size, u32 heap);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6FF0(char *p);
extern void func_021D7798(u8 *p);
void func_021D77C4(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((struct Obj02837 *)a)->fA4=0;
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02837 *)a)->f8));
    h=n/2;
    if(n>0x1fc0e) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3a3);
        return;
    }
    ((struct Obj02837 *)a)->fAE=1;
    ((struct Obj02837 *)a)->f30=(int)MUSICAL_DIST_SAVE_CreateFromData((void *)(((struct Obj02837 *)a)->f2C),p,n,((struct Obj02837 *)a)->f0);
    func_021D6EE0((u8 *)a,(int)func_021D7798,0x3a9);
}
