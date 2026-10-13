/*
 * function: func_021FF198
 * address: 0x021FF198
 * packet: pkt_ov135_021FF198
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj08192.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021FFB00(int);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021FF198(char *p)
{
    int r;
    if (KEY_GetTrg() & 1) {
        WIPE_SYS_Start(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = func_021FFB00(((struct Obj08192 *)p)->fD0);
        if (((struct Obj08192 *)p)->fE1A && r >= 0) {
            CLACT_SetActorAnimSeq((struct Obj *)(*(unsigned *)(p + 0xd0c + (r + 1) * 4)), (u16)(16 + r * 4));
            ((struct Obj08192 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 0);
            ((struct Obj08192 *)p)->fD4 = r;
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
    }
    return 2;
}
