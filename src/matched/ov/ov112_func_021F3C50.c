/*
 * function: MUSICAL_SHOT_SYS_DrawScene
 * address: 0x021F3C50
 * packet: pkt_ov112_021F3C50
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F3CA2.
 * symbols:
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_021F4280 0x021F4280 thumb ov112
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "../include/Obj02823.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Board;
struct Camera;
struct Lights;
extern void func_021F7160(u8 *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u32);
extern void func_021F75A0(u8 *p);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *p);
extern void func_021F4280(u8 *);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void G3D_SYSTEM_DrawEnd(void);
void MUSICAL_SHOT_SYS_DrawScene(u8 *p)
{
    func_021F7160((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51E8(*(u8 * *)&((struct Obj02823 *)p)->f20);
    func_021F6CB0((char *)(((struct Obj02823 *)p)->f40));
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    func_021F6E74(((struct Obj02823 *)p)->f40);
    func_021F75A0((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51F4((void **)(*(u32 *)&((struct Obj02823 *)p)->f20));
    func_021F718C((char *)(((struct Obj02823 *)p)->f2C));
    func_021F6F8C((u8 *)(((struct Obj02823 *)p)->f28));
    BILLBOARD_Draw((struct Board *)(((struct Obj02823 *)p)->f1C),(struct Camera *)(((struct Obj02823 *)p)->f18),0);
    func_021F4280(p);
    G3D_SYSTEM_DrawEnd();
}
