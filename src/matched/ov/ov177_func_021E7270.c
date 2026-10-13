/*
 * function: func_021E7270
 * address: 0x021E7270
 * packet: pkt_ov177_021E7270
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 */
#include "../include/Obj00133.h"
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
typedef unsigned short u16;

extern void func_02082BCC(void *, unsigned, unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *e, unsigned short f, unsigned short g);
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E7270(char *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x16c)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
        if (*(void **)(p + i * 4 + 0x1a8)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x1a8));
            *(void **)(p + i * 4 + 0x1a8) = 0;
        }
    }
    for (i = 0; i < 6; i++)
        CLACT_ReleaseCharacter(*(unsigned *)(p + i * 4 + 0x1c4));
    CLACT_ReleaseCellAnim(*(unsigned *)&((struct Obj00133 *)p)->f1E0);
    CLACT_ReleasePalette(*(unsigned *)&((struct Obj00133 *)p)->f1E4);
    CLACT_ReleaseCharacter(*(unsigned *)&((struct Obj00133 *)p)->f1F8);
    CLACT_ReleasePalette(*(unsigned *)&((struct Obj00133 *)p)->f1F4);
    CLACT_ReleaseCellAnim(*(unsigned *)&((struct Obj00133 *)p)->f1FC);
}
