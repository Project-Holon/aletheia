/*
 * function: MYSTERY_ALBUM_Delete
 * address: 0x021DD980
 * packet: pkt_ov121_021DD980
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DA3C0 0x021DA3C0 thumb ov121
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 */
#include "../include/Obj03789.h"
typedef unsigned char  u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern unsigned int func_020307B0(void *p);
extern void func_021DA3C0(u8 *p);
typedef unsigned int   u32;
extern void func_021DBEE4(u32 p);
void MYSTERY_ALBUM_Delete(char *p)
{
    if (((struct Obj03789 *)p)->f128) {
        func_02030EAC(((struct Obj03789 *)p)->f128);
        ((struct Obj03789 *)p)->f128=0;
    }
    if (((struct Obj03789 *)p)->f13C) func_020307B0(((struct Obj03789 *)p)->f13C);
    if (((struct Obj03789 *)p)->f134) func_020307B0(((struct Obj03789 *)p)->f134);
    func_021DA3C0(((struct Obj03789 *)p)->f144);
    func_021DBEE4((u32)p);
    func_020307B0(p);
}
