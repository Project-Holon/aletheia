/*
 * function: func_021B7004
 * address: 0x021B7004
 * packet: pkt_ov174_021B7004
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; the returned object pointer is stored as a word.
 * symbols:
 *   func_021B7180 0x021B7180 thumb ov174
 *   func_021B71A0 0x021B71A0 thumb ov174
 *   func_020307B0 0x020307B0 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 *   d_021B7481 0x021B7481 data a1
 */
#include "../include/Obj00476.h"
#include "../include/Obj01422.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; u16 id; u8 a, b; } Request;
extern const u8 d_021B7481[];
extern void func_021B7180(char *p, char *q, int id);
extern void func_021B71A0(int, int *, int, int, int);
extern u32 func_020307B0(void *p);
extern int CLACT_RegisterPaletteCompressed(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
struct Actor;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_StopActorAnim(struct Actor *a);
void func_021B7004(u8 *p, u8 *q)
{
    int step;
    int base;
    Request req;
    if (((struct Obj01422 *)p)->f8 == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    func_021B7180((char *)p, (char *)q, (d_021B7481 + 4)[q[2] * 3]);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x10000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    func_021B7180((char *)p, (char *)q, d_021B7481[q[3] * 2] + ((struct Obj01422 *)p)->f10 * 2);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x28000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    *(int *)&((struct Obj00476 *)q)->f1C = CLACT_RegisterPaletteCompressed(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3], 0, (u16)((q[0] * 2 + 4) << 5), ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f20 = CLACT_RegisterCharacter(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 1, 0, 0, ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f24 = CLACT_RegisterCellAnim(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 2, (d_021B7481 + 5)[q[2] * 3] + 3, ((struct Obj01422 *)p)->f0);
    req.a = 10; req.b = 1;
    req.x = (q[0] % 2) * 128 + 64;
    req.y = (q[0] / 2) * 96 + 48;
    if (((struct Obj01422 *)p)->f8 == 2) req.y += 56;
    req.id = 0;
    *(u32 *)&((struct Obj00476 *)q)->f28 = (u32)CLACT_CreateActor((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00476 *)q)->f28, 1);
    CLACT_SetActorAutoAnim(((struct Obj00476 *)q)->f28, 1);
    CLACT_StopActorAnim(((struct Obj00476 *)q)->f28);
    req.id = 1;
    *(u32 *)&((struct Obj00476 *)q)->f2C = (u32)CLACT_CreateActor((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00476 *)q)->f2C, 1);
    CLACT_SetActorAutoAnim(((struct Obj00476 *)q)->f2C, 1);
    CLACT_StopActorAnim(((struct Obj00476 *)q)->f2C);
}
