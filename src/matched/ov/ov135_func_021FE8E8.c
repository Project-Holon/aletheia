/*
 * function: func_021FE8E8
 * address: 0x021FE8E8
 * packet: pkt_ov135_021FE8E8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021FF474 0x021FF474 thumb ov135
 */
#include "../include/Obj08191.h"
extern void func_021FF318(unsigned char *p, unsigned int k, int b, int c, int d);
typedef unsigned char  u8;
extern void func_021F4E98(u8 *p, unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021FF474(void *, void *, int, void *);
int func_021FE8E8(char *p)
{
    ((struct Obj08191 *)p)->fB5C = 0;
    func_021FF318((unsigned char *)p, 44, 1, 0, 0xf0f);
    func_021F4E98((u8 *)p, 23, 1);
    GFL_USE_PlaySeDefaultVolume(0x557);
    ((struct Obj08191 *)p)->fD0 = 0;
    func_021FF474(((struct Obj08191 *)p)->fDB0, ((struct Obj08191 *)p)->fB6C, 0, p + 0xfa0);
    return 2;
}
