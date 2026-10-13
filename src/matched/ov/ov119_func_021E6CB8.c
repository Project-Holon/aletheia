/*
 * function: func_021E6CB8
 * address: 0x021E6CB8
 * packet: pkt_ov119_021E6CB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_Create 0x02043678 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E7E64 0x021E7E64 data a2
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short x,y; } Pt;
typedef struct { Pt pos[8]; } Table;
extern const Table d_021E7E64;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
struct Bmp;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021E6CB8(char *p)
{
    Table t = d_021E7E64;
    void *h = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    Create c;
    int i;
    ((struct Obj00001 *)p)->f10EC = CLACT_RegisterPaletteEx(h, 0, 1, 0x1c0, 0, 1, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f10F0 = CLACT_RegisterCellAnim(h, 2, 1, ((struct Obj00001 *)p)->f5F4);
    for (i = 0; i < 8; i++) {
        *(void **)(p + i * 4 + 0x10f4) = BMP_Create(16, 6, 32, ((struct Obj00001 *)p)->f5F4);
        *(u32 *)(p + i * 4 + 0x1114) = CLACT_RegisterCharacter(h, 3, 0, 1, ((struct Obj00001 *)p)->f5F4);
    }
    for (i = 0; i < 8; i++) {
        c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.z = 0; c.a = 0; c.b = 1;
        *(int *)(p + i * 4 + 0x10cc) = (int)CLACT_CreateActor((void *)((struct Obj00001 *)p)->f9C4, *(int *)(p + i * 4 + 0x1114), *(int *)(p + 0x10ec), *(int *)(p + 0x10f0), &c, 1, ((struct Obj00001 *)p)->f5F4);
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x10cc), 1);
    }
    ARC_TOOL_DeleteHandle(h);
}
