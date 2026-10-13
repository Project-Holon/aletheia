/*
 * function: func_021F47C0
 * address: 0x021F47C0
 * packet: pkt_ov135_021F47C0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_021F49A4 0x021F49A4 thumb ov135
 *   func_02045C04 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   func_02202744 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 */
#include "../include/Obj02854.h"
typedef unsigned char u8;
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021F50EC(u8 *);
extern void func_021F49A4(void *a0);
typedef signed int     s32;
struct Rec;
struct S020314B8;
struct S020315D4;
struct WordSet;
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_02030DA4(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02202744(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern const u8 ov067_id[];
extern const u8 ov114_id[];
int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p)
{
    GFL_USE_CancelChangeAndStopBgm();
    func_021F50EC(p);
    func_021F49A4(p);
    func_02045C04(((struct Obj02854 *)p)->fB70);
    func_02045C04(((struct Obj02854 *)p)->fB78);
    func_02045C04(((struct Obj02854 *)p)->fB74);
    func_02045C04(((struct Obj02854 *)p)->fB6C);
    func_02045C04(((struct Obj02854 *)p)->fB7C);
    func_0201ED04(((struct Obj02854 *)p)->fB68);
    func_02030DA4(((struct Obj02854 *)p)->fF94);
    func_020307B0(((struct Obj02854 *)p)->fF9C);
    func_0203133C(((struct Obj02854 *)p)->f12F0);
    func_020307B0(((struct Obj02854 *)p)->fEA8);
    func_02202744(p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}
