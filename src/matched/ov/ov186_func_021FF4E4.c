/*
 * function: func_021FF4E4
 * address: 0x021FF4E4
 * packet: pkt_ov186_021FF4E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021FFB50 0x021FFB50 thumb ov186
 *   func_0200D5C8 0x0200D5C8 thumb
 *   func_021D6770 0x021D6770 thumb ov125
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov125_id 0x0000007D data
 */
#include "../include/Obj08336.h"
extern void func_02156DE0(int, int);
extern void func_021FFB50(void *);
struct GdsProfile;
extern void func_0200D5C8(struct GdsProfile *p);
extern void func_021D6770(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern char ov125_id[];
void func_021FF4E4(char *p)
{
    func_02156DE0(0, 0);
    func_021FFB50(((struct Obj08336 *)p)->f5AC);
    func_0200D5C8(((struct Obj08336 *)p)->f5A8);
    if (((struct Obj08336 *)p)->f5A4) {
        func_021D6770(p);
        ((struct Obj08336 *)p)->f5A4 = 0;
    }
    func_020307B0(p);
    func_02034A5C((int)ov125_id);
}
