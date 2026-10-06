/*
 * function: func_021E7098
 * address: 0x021E7098
 * packet: pkt_ov119_021E7098
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 02021540 forwards live r0 to 020307B0, so caller passes s.
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E3D0 0x0207E3D0 arm
 */
#include "../include/Obj13926.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { void *a, *b; u32 size, c, d; } Slot;
extern void *func_02021518(u32 heap);
struct Chan02021FD8;
struct PalAnmSlot;
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *,int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(Slot *);
extern void func_020862F0(void *,u32);
extern void func_0207E5D0(void *,u32,u32);
extern void func_0207E468(void *,u32,u32);
extern void func_0207E51C(void *,u32,u32);
extern void func_0207E3D0(void *,u32,u32);
void func_021E7098(char *p, int bank, int mask)
{
    Slot *s;
    char *buf;
    int i;
    int off;
    s=func_02021518(((struct Obj13926 *)p)->f5F4);
    func_0202155C((struct PalAnmSlot *)s,bank,0x200,((struct Obj13926 *)p)->f5F4);
    func_020216D4((struct PalAnmSlot *)s,bank,0,0x200);
    func_02021FD8((struct Chan02021FD8 *)s,bank,0,0x100,6,0);
    buf=(char *)func_02021730((char *)s,bank);
    for(i=0;i<16;i++) {
        if(mask & (1<<i)) {
            off=i*32;
            func_020862F0(buf+off,32);
            switch(bank) {
            case 3: func_0207E5D0(buf+off,off,32); break;
            case 1: func_0207E468(buf+off,off,32); break;
            case 2: func_0207E51C(buf+off,off,32); break;
            case 0: func_0207E3D0(buf+off,off,32); break;
            }
        }
    }
    func_020215A0((struct PalAnmSlot *)s,bank);
    func_02021540(s);
}
