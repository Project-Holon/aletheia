/*
 * function: func_021E4B00
 * address:  0x021E4B00
 * packet:   pkt_ov119_021E4B00
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever:    the slot base read in the compares and the end store is spelled ((u8 *)(p + row * 5) + j)[K]
 *           and the update stores plain, so 1.1p1 CSEs only the first group; the last three object
 *           reads use (u32)j * 4 so they recompute after the copy; the VRAM base is an enum local
 *           (operand order of 0x06600000 + addr, as in ov094_func_02204CC0).
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021E4984 0x021E4984 thumb ov119
 *   func_021E49DC 0x021E49DC thumb ov119
 *   func_021E4AD0 0x021E4AD0 thumb ov119
 *   func_021E496C 0x021E496C thumb ov119
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_02061CA4 0x02061CA4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_02017E88 0x02017E88 thumb
 *   func_021E4A84 0x021E4A84 thumb ov119
 */
#include "../include/Obj00001.h"
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u16 id; u8 b2, b3; } Ent;
typedef struct { s16 x, y; } Pt;
typedef struct { int a, b, c, d[6]; } Info;
struct Obj;
extern u8 func_020355C4(void);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern int func_021E4984(int v, int a, int b, char *p, int *out);
struct Struct36;
extern char *func_021E49DC(int a, int b, char *p);
extern void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5);
extern void func_021E496C(int x, int y, u16 *out);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void MI_CpuCopy8(int src, int dst, int n);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021E4A84(char *p, int i);
void func_021E4B00(char *p, int v, int a, int row, int flag)
{
    int j, rec, id, b2, b3, idx, n;
    Ent *e;
    Info info;
    int kind;
    u16 pos[2];
    Pt pt;
    enum { VRAM_BASE = 0x06600000 } vram;
    if (a == ((struct Obj00001 *)p)->fF74 && func_020355C4() == 0) {
        CLACT_SetActorDrawEnable(((void **)(p + row * 20 + 0xbb0))[((struct Obj00001 *)p)->fF78], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = func_021E4984(v, a, j, p, &kind);
        e = (Ent *)func_021E49DC(a, j, p);
        if (e == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        if (e->id == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        ((u8 *)(p + row * 5) + j)[0xd90] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 == ((u8 *)(p + row * 5) + j)[0xd18]
            && b3 == ((u8 *)(p + row * 5) + j)[0xd54]) {
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + j * 4 + 0xac0), 1);
            func_021E4AD0(p, a, j, rec, kind, row);
        } else if (id != *(u16 *)(p + row * 10 + j * 2 + 0xca0)
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 != ((u8 *)(p + row * 5) + j)[0xd18])
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b3 != ((u8 *)(p + row * 5) + j)[0xd54])) {
            *(u16 *)(p + row * 10 + j * 2 + 0xca0) = id;
            *(u8 *)(p + row * 5 + j + 0xd18) = b2;
            *(u8 *)(p + row * 5 + j + 0xd54) = b3;
            func_021E496C(a, j, pos);
            CLACT_GetActorImageProxy(*(void **)(p + row * 20 + j * 4 + 0xac0), (struct Struct36 *)(&info));
            n = func_021D8AF4(a, p);
            idx = func_021D8B0C(a, j);
            idx += n * 30;
            CLACT_GetActorSurfacePos((struct Actor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct PtS *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (func_02061CA4((void *)0x23, info.c, *(int *)(p + 0x1184) + idx * 0x200, 0x200) == 0) {
                    vram = VRAM_BASE;
                    MI_CpuCopy8(*(int *)(p + 0x1184) + idx * 0x200, vram + info.c, 0x200);
                }
            } else {
                vram = VRAM_BASE;
                MI_CpuCopy8(*(int *)&((struct Obj00001 *)p)->f1184 + idx * 0x200, vram + info.c, 0x200);
            }
            func_021E4AD0(p, a, j, rec, kind, row);
            CLACT_SetActorPaletteOffset(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), POKE_TOOL_GetIconPalette((void *)rec), 1);
            CLACT_SetActorAutoAnim(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (func_02017E88((void *)rec, 0x4c, 0) == 0 && func_021E4A84(p, id)) {
            ((u8 *)(p + row * 5) + j)[0xebc] = 1;
        }
    }
}
