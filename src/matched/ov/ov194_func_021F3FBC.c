/*
 * function: NAMEIN_GRAPHIC_InitIconActor
 * address:  0x021F3FBC
 * packet:   pkt_ov194_021F3FBC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * pass 2 2026-10-06 P2L13: EXACT (was DIFF 6). v2c is a u8 local (it holds the u8 table byte
 *   d_021F5569[a2]), and a3 is a u32 parameter. The narrow v2c moves the heap stack-parameter load
 *   up to its image place before the memset arguments; the earlier u16 a3 form is no longer needed.
 *   Earlier lanes (wD3..wD9r, G3L1) tried the entry spill order through parameter widths, local
 *   widths of flagA/w24/h20/flagB, heap copies, pragmas and callee types.
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020276A4  0x020276A4  thumb
 *   func_020276A8  0x020276A8  thumb
 *   func_020276AC  0x020276AC  thumb
 *   func_020276B0  0x020276B0  thumb
 *   func_0201BC3C  0x0201BC3C  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   NAMEIN_GRAPHIC_LoadIconMember  0x021F51E4  thumb ov194
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *p, int v, u32 n);
extern u32  func_020275E4(void);
extern u32  func_020276A4(void);
extern u32  func_020276A8(void);
extern u32  func_020276AC(u32 a);
extern u32  func_020276B0(u32 a);
typedef signed int     s32;
struct Bmp;
struct CharBuf;
struct Grid;
struct MsgBank;
struct Obj;
struct Param;
struct Sys;
extern int func_0201BC3C(void);
extern u32  POKE_TOOL_CalcGraphicIndex(u32 a, u32 b, u32 c, u32 d);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32  POKE_TOOL_CalcIconPalette(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *h);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void NAMEIN_GRAPHIC_LoadIconMember(u8 *dst, unsigned arc, u32 member, u32 index, u16 width, u16 height, int pos, int mode, u16 heap);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(u32 a, void *b, s16 c, u32 d, void *e, u32 f, u32 g);
extern const u8 d_021F5569[];

typedef struct { u16 w; u16 h; u32 pad; } Dim8;

void NAMEIN_GRAPHIC_InitIconActor(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap)
{
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u8 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    MI_CpuFill8(o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = func_020275E4();
        v3c = func_020276A4();
        v38 = func_020276A8();
        v34 = func_020276AC(2);
        v30 = func_020276B0(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        v1c = (a2 >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = func_0201BC3C();
        v38 = POKE_TOOL_CalcGraphicIndex(a2, (u8)a3, v1c, 0);
        v34 = func_0201BC40();
        v30 = func_0201BCB4();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = func_020490F4(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = (void *)CLACT_RegisterPaletteCompressed(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = (void *)CLACT_RegisterPaletteEx(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = (void *)CLACT_RegisterCellAnim(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = (void *)CLACT_RegisterCharacter(h, v38, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
    {
        Dim8 dim;
        MI_CpuFill8(&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = CLACT_CreateActor((void *)s0, (u32)(*(void **)(o + 0xC)), (u32)(*(void **)(o + 8)), (u32)(*(void **)(o + 0x10)), &dim, flagB, heap);
    }
    CLACT_SetActorAutoAnim(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        CLACT_SetActorPaletteOffset(*(void **)o, 0, 1);
        break;
    case 3:
        CLACT_SetActorAnimSeq(*(void **)o, 1);
        CLACT_SetActorPaletteOffset(*(void **)o, POKE_TOOL_CalcIconPalette(a2, (u8)a3, (a3 & 0xFF00) >> 8, flagB), flagB);
        break;
    case 5:
        CLACT_SetActorAnimSeq(*(void **)o, 5);
        CLACT_SetActorPaletteOffset(*(void **)o, flagB, 1);
        break;
    case 4:
        CLACT_SetActorAnimSeq(*(void **)o, 2);
        CLACT_SetActorPaletteOffset(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        u8 st[0x18];
        h2 = func_020490F4(0x17, heap);
        *(void **)(o + 0x30) = BMP_Create(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = (void *)CLACT_RegisterPaletteCompressed(h2, 5, 0, 0xA0, heap);
        ARC_TOOL_DeleteHandle(h2);
        MI_CpuFill8(st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(u8 *)(st + 0x10) = 0;
        *(u16 *)(st + 0x12) = 0;
        *(u32 *)(st + 0x14) = 0;
        *(u8 *)(st + 0x11) = 0;
        *(u32 *)(st + 0xC) = 0;
        *(void **)(o + 0x2C) = BMP_OAM_Create((struct Sys *)s4, (const struct Param *)st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        *(void **)(o + 0x28) = func_02045EC0(s3, idx);
        BMP_Clear(*(void **)(o + 0x30), 0);
        PRINTSYS_PrintQueColor(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}
