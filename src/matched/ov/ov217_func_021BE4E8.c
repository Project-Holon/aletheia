/*
 * function: func_021BE4E8
 * address: 0x021BE4E8
 * packet: pkt_ov217_021BE4E8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE9B8 0x021BE9B8 thumb ov217
 *   func_021BE91C 0x021BE91C thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BE934 0x021BE934 thumb ov217
 *   func_021BF3D8 0x021BF3D8 thumb ov217
 *   func_021BF4AC 0x021BF4AC thumb ov217
 *   func_021BF594 0x021BF594 thumb ov217
 *   func_021BEBA4 0x021BEBA4 thumb ov217
 *   func_021BEFF8 0x021BEFF8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BE9B8(u8 *);
extern void func_021BE91C(char *,int);
extern u32 func_021BF810(void *p);
extern int func_021BE934(char *);
extern void func_021BF3D8(char *p);
extern void func_021BF4AC(char *p);
extern void func_021BF594(char *p, int i);
extern u32 func_021BEBA4(u32);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021BEFF8(u8 *p);
void func_021BE4E8(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,-1);
    do {
        u32 index=((struct Obj00021 *)p)->f34;
        if (index-1<=1) {
            if (((struct Obj00021 *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct Obj00021 *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct Obj00021 *)p)->f34==4) func_021BEBA4((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BEFF8(p);
}
