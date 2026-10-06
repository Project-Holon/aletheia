/*
 * function: func_021D4CBC
 * address: 0x021D4CBC
 * packet: pkt_ov123_021D4CBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
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
#include "../include/Obj13970.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
typedef unsigned char  u8;
struct Chan02021FD8;
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020862F0(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *);
void func_021D4CBC(char *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = func_02021518(((struct Obj13970 *)p)->fC);
    func_0202155C(obj, n, 0x200, ((struct Obj13970 *)p)->fC);
    bytes = count * 32;
    func_020216D4(obj, n, 0, bytes);
    func_02021FD8(obj, (int)n, (int)0, (u16)(count * 16), (int)6, (int)0);
    buffer = (void *)func_02021730(obj, n);
    func_020862F0(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    func_020215A0(obj, n);
    func_02021540(obj);
}
