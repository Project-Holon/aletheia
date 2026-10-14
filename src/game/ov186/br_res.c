/*
 * file:     br_res.c
 * unit:     yes
 * function: BR_RES_Create, BR_RES_Delete, BR_RES_LoadBgGraphics, BR_RES_ApplyBgSet, BR_RES_LoadSprite, BR_RES_ReleaseSprite, BR_RES_GetSprite, BR_RES_LoadUiPalette, BR_RES_ReleaseUiPalette, BR_RES_GetFont, BR_RES_GetMsgData, BR_RES_GetWordSet, BR_RES_GetCurrentSetParam, BR_RES_SetPalSet, BR_RES_GetPalSet, BR_RES_LoadFadePalettes, BR_RES_GetPaletteFileId, BR_RES_GetCharFileId, BR_RES_GetScreenFileId, BR_RES_GetSetParam
 * address:  0x021FB884
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, ov186_func_02200228.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_Create 0x021FB884 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_Delete 0x021FB92C thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   d_02200D3C 0x02200D3C data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D48       0x02200D48  data
 *   CLACT_RegisterCharacter    0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx    0x0204AC18  arm
 *   CLACT_RegisterCellAnim    0x0204AF28  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02049B68 0x02049B68 arm
 *   BR_FADE_LoadPalette 0x021FE8E8 thumb ov186
 *   d_022008C0 0x022008C0 data a4
 *   d_022008A0 0x022008A0 data a4
 *   d_02200880 0x02200880 data a4
 *   d_022008E0 0x022008E0 data a4
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 */
#include "br_types.h"

struct Rec_021FAA74 {void *a,*b;unsigned char pad[12];void *handle;};

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, int, int);

extern u32 func_020307B0(void *p);

extern u32 func_0201ED04(struct WordSet *p);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void *func_0201EC74(unsigned,unsigned,unsigned);

extern unsigned int MSGDATA_Delete(struct Rec_021FAA74 *rec);

extern unsigned int GF_FONT_Delete(void *ptr);

extern void *func_020490F4(u32 id, u32 heap);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_020414EC(u32 i);

extern void func_020409B4(u32 index);

extern u32 CLACT_RegisterCharacter(void *h, u32 a1, u32 a2, u32 a3, u32 s0);

extern u32 CLACT_RegisterPaletteEx(void *h, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,unsigned);

extern void BR_FADE_LoadPalette(void *fade, void *archive, u32 fileId, u32 slot, u32 offset, u32 count, u16 heapId);

void *BR_RES_Create(unsigned palSet,unsigned useCustomSet,unsigned heapId);

void BR_RES_Delete(struct BrRes *res);

void BR_RES_LoadBgGraphics(void *unusedCtx,unsigned kind,unsigned short heapId);

void BR_RES_ApplyBgSet(int unusedA,unsigned palSet);

void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId);

void BR_RES_ReleaseSprite(struct BrRes *res,unsigned spriteIndex);

int BR_RES_GetSprite(struct BrRes *res,unsigned spriteIndex,void *outSprite);

void BR_RES_LoadUiPalette(struct BrRes *res,unsigned screen,unsigned heapId);

void BR_RES_ReleaseUiPalette(struct BrRes *res, int screen);

unsigned BR_RES_GetFont(struct BrRes *res);

int BR_RES_GetMsgData(struct BrRes *res);

int BR_RES_GetWordSet(struct BrRes *res);

int BR_RES_GetCurrentSetParam(struct BrRes *res);

void BR_RES_SetPalSet(struct BrRes *res,int palSet);

int BR_RES_GetPalSet(struct BrRes *res);

void BR_RES_LoadFadePalettes(struct BrRes *res,void *fade,unsigned short heapId);

unsigned short BR_RES_GetPaletteFileId(unsigned palSet);

unsigned short BR_RES_GetCharFileId(unsigned palSet);

unsigned short BR_RES_GetScreenFileId(unsigned palSet);

u16 BR_RES_GetSetParam(u32 palSet);

extern const char d_02200D3C[];

extern char d_02200D48[];

extern const unsigned d_022008C0[];

extern const unsigned d_022008A0[];

extern const unsigned d_02200880[];

extern const u32 d_022008E0[];

/*
 * volatile: allocated fields +F4 and +F8 re-read after their stores at 021FB8B0 and 021FB8C0.
 */
void *BR_RES_Create(unsigned palSet,unsigned useCustomSet,unsigned heapId)
{
    struct BrRes *res;
    res=func_02030734(heapId,0xfc,0,d_02200D3C,0x60);
    MI_CpuFill8(res,0,0xfc);
    res->useCustomSet=useCustomSet;
    if(res->useCustomSet){res->palSet=palSet;if(res->palSet==1)res->palSet=0;}
    else res->palSet=1;
    res->font=GF_FONT_Create(0x17,0,0,0,heapId);
    res->msgData=func_02045B38(0,2,5,heapId);
    res->wordSet=func_0201EC74(8,0x40,heapId);
    BR_RES_LoadUiPalette(res,0,heapId);
    BR_RES_LoadUiPalette(res,1,heapId);
    return res;
}

void BR_RES_Delete(struct BrRes *res) {BR_RES_ReleaseUiPalette(res,0);BR_RES_ReleaseUiPalette(res,1);func_0201ED04(res->wordSet);MSGDATA_Delete((struct Rec_021FAA74 *)res->msgData);GF_FONT_Delete(res->font);func_020307B0(res);}

void BR_RES_LoadBgGraphics(void *unusedCtx,unsigned kind,unsigned short heapId)
{
    void *h;
    h=func_020490F4(0x89,heapId);
    switch(kind) {
    case 0:
        func_02049658(h,0x26,3,0,0,0,heapId);
        func_020498F4(h,0x28,3,0,0,0,heapId);
        break;
    case 1:
        func_02049658(h,0x26,6,0,0,0,heapId);
        func_020498F4(h,0x28,6,0,0,0,heapId);
        break;
    case 2:
        func_02049658(h,0x6b,0,0,0,0,heapId);
        func_020498F4(h,0x2,0,0,0,0,heapId);
        break;
    case 3:
        func_02049658(h,0x26,2,0,0,0,heapId);
        func_020498F4(h,0x27,2,0,0,0,heapId);
        break;
    case 4:
        func_02049658(h,0x26,2,0,0,0,heapId);
        func_020498F4(h,0x1a,2,0,0,0,heapId);
        break;
    case 5:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x5,5,0,0,0,heapId);
        break;
    case 6:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x2d,2,0,0,0,heapId);
        break;
    case 7:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x2c,2,0,0,0,heapId);
        break;
    case 8:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x2b,2,0,0,0,heapId);
        break;
    case 9:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x61,5,0,0,0,heapId);
        break;
    case 10:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x63,2,0,0,0,heapId);
        break;
    case 11:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x64,2,0,0,0,heapId);
        break;
    case 12:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x65,2,0,0,0,heapId);
        break;
    case 13:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x66,2,0,0,0,heapId);
        break;
    case 19:
        func_02049658(h,0x6b,2,0,0,0,heapId);
        func_020498F4(h,0x2,2,0,0,0,heapId);
        break;
    case 14:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x62,2,0,0,0,heapId);
        break;
    case 15:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x67,5,0,0,0,heapId);
        break;
    case 18:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x68,2,0,0,0,heapId);
        break;
    case 17:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x69,2,0,0,0,heapId);
        break;
    case 16:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x6a,2,0,0,0,heapId);
        break;
    case 20:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x1f,5,0,0,0,heapId);
        break;
    case 21:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x1d,5,0,0,0,heapId);
        break;
    case 22:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0xd,5,0,0,0,heapId);
        break;
    case 23:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0xe,5,0,0,0,heapId);
        break;
    case 24:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x3,2,0,0,0,heapId);
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,6,5,0,0,0,heapId);
        break;
    case 25:
        func_02049658(h,0x21,2,0,0,0,heapId);
        func_020498F4(h,0x1b,2,0,0,0,heapId);
        break;
    case 26:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x1e,5,0,0,0,heapId);
        break;
    case 28:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x1c,5,0,0,0,heapId);
        break;
    case 27:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x20,5,0,0,0,heapId);
        break;
    case 29:
        func_02049658(h,0x26,5,0,0,0,heapId);
        func_020498F4(h,0x12,5,0,0,0,heapId);
        break;
    case 30:
        func_02049658(h,0x21,5,0,0,0,heapId);
        func_020498F4(h,0x2f,5,0,0,0,heapId);
        break;
    }
    ARC_TOOL_DeleteHandle(h);
}

void BR_RES_ApplyBgSet(int unusedA,unsigned palSet)
{
    switch(palSet){
    case 24:
        func_020414EC(2);func_020409B4(2);
        func_020414EC(5);func_020409B4(5);break;
    case 0:func_020414EC(3);func_020409B4(3);break;
    case 1:func_020414EC(6);func_020409B4(6);break;
    case 2:func_020414EC(0);func_020409B4(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        func_020414EC(5);func_020409B4(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        func_020414EC(2);func_020409B4(2);break;
    case 14:break;
    }
}

void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId)
{
    struct BrResSprite *sprite;

    sprite = &res->sprite[spriteIndex];

    if (res->spriteLoaded[spriteIndex] != 0) {
        func_02034714(d_02200D48, 0, d_02200D48);
    }

    switch (spriteIndex) {
    case 4: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x24, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 5: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x24, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 0: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x22, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 1: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x22, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 2: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x3f, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 3: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x3f, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 6: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x23, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 7, 8, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 8: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x56, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 7: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x56, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 11: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = CLACT_RegisterPaletteEx(h, 0x13, 1, 0x80, 0, 1, heapId);
        sprite->charId = CLACT_RegisterCharacter(h, 0xf, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x10, 0x11, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 12: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = CLACT_RegisterPaletteEx(h, 0x33, 1, 0xa0, 0, 1, heapId);
        sprite->charId = CLACT_RegisterCharacter(h, 0x32, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x30, 0x31, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 9: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x36, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 10: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x36, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 13: {
        void *h = func_020490F4(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x29, 0x2a, heapId);
        sprite->charId = CLACT_RegisterCharacter(h, 0x25, 0, 0, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    default:
        break;
    }

    res->spriteLoaded[spriteIndex] = 1;
}

void BR_RES_ReleaseSprite(struct BrRes *res,unsigned spriteIndex)
{
    struct BrResSprite *r=&res->sprite[spriteIndex];
    switch(spriteIndex){
    case 11: case 12:
        CLACT_ReleasePalette(r->paletteId);
        CLACT_ReleaseCharacter(r->charId);
        CLACT_ReleaseCellAnim(r->cellAnimId);
        break;
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
        CLACT_ReleaseCharacter(r->charId);
        CLACT_ReleaseCellAnim(r->cellAnimId);
        break;
    case 4: case 5: break;
    }
    res->spriteLoaded[spriteIndex]=0;
}

int BR_RES_GetSprite(struct BrRes *res,unsigned spriteIndex,void *outSprite) { if(res->spriteLoaded[spriteIndex]) *(struct BrResSprite *)outSprite=res->sprite[spriteIndex];return res->spriteLoaded[spriteIndex]; }

void BR_RES_LoadUiPalette(struct BrRes *res,unsigned screen,unsigned heapId)
{
    void *h;
    h=func_020490F4(0x89,heapId);
    res->paletteId[screen]=CLACT_RegisterPaletteEx(h,BR_RES_GetPaletteFileId(res->palSet),screen,0,0,13,heapId);
    if(screen==0){
        func_02049B68(h,BR_RES_GetCharFileId(res->palSet),0,0,0,heapId);
        func_02049B68(h,BR_RES_GetScreenFileId(res->palSet),0,0x1c0,0x20,heapId);
    }else{
        func_02049B68(h,BR_RES_GetCharFileId(res->palSet),4,0,0,heapId);
        func_02049B68(h,BR_RES_GetScreenFileId(res->palSet),4,0x1c0,0x20,heapId);
    }
    ARC_TOOL_DeleteHandle(h);
}

void BR_RES_ReleaseUiPalette(struct BrRes *res, int screen)
{
    CLACT_ReleasePalette(res->paletteId[screen]);
    res->paletteId[screen] = -1;
}

unsigned BR_RES_GetFont(struct BrRes *res) { return (unsigned)res->font; }

int BR_RES_GetMsgData(struct BrRes *res)
{
    return (int)res->msgData;
}

/*
 * trailing: two zero padding bytes at 021FC222, then existing matched 021FC224.
 */
int BR_RES_GetWordSet(struct BrRes *res)
{
    return (int)res->wordSet;
}

/*
 * Extent runs long: 0x021FC230 is an unlabelled follower leaf (a plain
 * `p[0x3e] = v` setter), so this is EXACT*.
 */
int BR_RES_GetCurrentSetParam(struct BrRes *res)
{
    return BR_RES_GetSetParam(res->palSet);
}

void BR_RES_SetPalSet(struct BrRes *res,int palSet){res->palSet=palSet;}

int BR_RES_GetPalSet(struct BrRes *res) { return res->palSet; }

/*
 * prototype: 490F4 receives full heap, no caller truncation; E8E8 reads stack heap halfword.
 */
void BR_RES_LoadFadePalettes(struct BrRes *res,void *fade,unsigned short heapId)
{
    void *h;
    h=func_020490F4(0x89,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetPaletteFileId(res->palSet),2,0,0x1C0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetPaletteFileId(res->palSet),3,0,0x1C0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetCharFileId(res->palSet),0,0,0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetCharFileId(res->palSet),1,0,0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetScreenFileId(res->palSet),0,0xE0,0x20,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetScreenFileId(res->palSet),1,0xE0,0x20,heapId);
    ARC_TOOL_DeleteHandle(h);
}

unsigned short BR_RES_GetPaletteFileId(unsigned palSet) { if(palSet>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008C0[palSet]; }

unsigned short BR_RES_GetCharFileId(unsigned palSet) { if(palSet>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008A0[palSet]; }

unsigned short BR_RES_GetScreenFileId(unsigned palSet) { if(palSet>=8)func_02034714(d_02200D48,0,d_02200D48);return d_02200880[palSet]; }

u16 BR_RES_GetSetParam(u32 palSet){if(palSet>=8)func_02034714(d_02200D48,0,d_02200D48);return *(const u32*)((u32)d_022008E0+palSet*4);}
