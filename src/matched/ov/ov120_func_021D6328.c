/*
 * function: func_021D6328
 * address: 0x021D6328
 * packet: pkt_ov120_021D6328
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D63F2.
 * lever: declaring the counter before the context places it at sp+0x10.
 * interface: func_02021540 forwards the supplied context to its free target.
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
#include "../include/Obj13934.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02021518(u32);
struct Chan02021FD8;
struct PalAnmSlot;
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *,int);
extern void func_020862F0(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *);
void func_021D6328(u8 *p,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=func_02021518(((struct Obj13934 *)p)->fF4);
    func_0202155C(obj,bank,0x200,((struct Obj13934 *)p)->fF4);
    func_020216D4(obj,bank,0,0x200);
    func_02021FD8(obj,bank,0,0x100,6,0);
    buffer=(u8 *)func_02021730(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E5D0(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E468(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    func_020215A0(obj,bank);
    func_02021540(obj);
}
