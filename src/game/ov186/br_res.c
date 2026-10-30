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
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_Create 0x021FB884 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_Delete 0x021FB92C thumb ov186
 *   GF_PANIC_Fail 0x02034714 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   d_02200D3C 0x02200D3C data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_02200D48       0x02200D48  data
 *   CLACT_RegisterCharacter    0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx    0x0204AC18  arm
 *   CLACT_RegisterCellAnim    0x0204AF28  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
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

struct MsgDataRec {void *a,*b;unsigned char pad[12];void *handle;};

#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"



#include "../arm9/gf_font.h"

#include "../arm9/msgdata.h"




#include "../arm9/arc_tool.h"

/* The DS code passes the flags as a word (the original prototype); the header has a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define ARC_UTIL_UploadPaletteFromHandleWhole ARC_UTIL_UploadPaletteFromHandleWhole_header
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadPaletteFromHandleWhole
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *arc, u32 memberIdx, int kind, int dest, int size, u32 flags);
#endif



#include "../arm9/bg_sys.h"


/* The DS code passes the heap id and colour counts as words (the original prototypes); the header has halfword parameters. The host build uses the header. */
#ifdef __MWERKS__
#define CLACT_RegisterCharacter CLACT_RegisterCharacter_header
#define CLACT_RegisterPaletteEx CLACT_RegisterPaletteEx_header
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
#undef CLACT_RegisterCharacter
#undef CLACT_RegisterPaletteEx
extern s32 CLACT_RegisterCharacter(void *archive, u32 file_idx, u32 compressed, u32 vram_mode, u32 heap_id);
extern s32 CLACT_RegisterPaletteEx(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u32 first_color, u32 color_count, u32 heap_id);
#endif






struct BrFade;

/* Message bank of the battle recorder texts. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define BR_RES_MSG_BANK 8
#else
#define BR_RES_MSG_BANK 5
#endif

#include "br_fade.h"

#include "../arm9/wordset.h"
#include "../version.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02200E8C[];
extern const char str_ja_02200E98[];
#endif
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02200E8C[];
extern const char str_ja_02200EBC[];
extern const char str_ja_02200EE0[];
extern const char str_ja_02200F04[];
extern const char str_ja_02200F28[];
#endif
void *BR_RES_Create(unsigned palSet,unsigned useCustomSet,u16 heapId);

void BR_RES_Delete(struct BrRes *res);

void BR_RES_LoadBgGraphics(void *unusedCtx,unsigned kind,unsigned short heapId);

void BR_RES_ApplyBgSet(void *unusedA, unsigned palSet);

void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId);

void BR_RES_ReleaseSprite(struct BrRes *res,unsigned spriteIndex);

int BR_RES_GetSprite(struct BrRes *res,unsigned spriteIndex,void *outSprite);

void BR_RES_LoadUiPalette(struct BrRes *res,unsigned screen,unsigned heapId);

void BR_RES_ReleaseUiPalette(struct BrRes *res, int screen);

void *BR_RES_GetFont(struct BrRes *res);

void *BR_RES_GetMsgData(struct BrRes *res);

void *BR_RES_GetWordSet(struct BrRes *res);

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
void *BR_RES_Create(unsigned palSet,unsigned useCustomSet,u16 heapId)
{
    struct BrRes *res;
    res=GFL_HEAP_Alloc(heapId,sizeof(*res),0,PM_LANG_JA(d_02200D3C, str_ja_02200E8C),0x60);
    MI_CpuFill8(res,0,sizeof(*res));
    res->useCustomSet=useCustomSet;
    if(res->useCustomSet){res->palSet=palSet;if(res->palSet==1)res->palSet=0;}
    else res->palSet=1;
    res->font=GF_FONT_Create(0x17,0,0,0,heapId);
    res->msgData=MSGDATA_CreateFromArchive(0,2,BR_RES_MSG_BANK,heapId);
    res->wordSet=WORDSET_Create(8,0x40,heapId);
    BR_RES_LoadUiPalette(res,0,heapId);
    BR_RES_LoadUiPalette(res,1,heapId);
    return res;
}

void BR_RES_Delete(struct BrRes *res) {BR_RES_ReleaseUiPalette(res,0);BR_RES_ReleaseUiPalette(res,1);WORDSET_Delete(res->wordSet);MSGDATA_Delete((struct MsgBank *)res->msgData);GF_FONT_Delete(res->font);GFL_HEAP_Free(res);}

void BR_RES_LoadBgGraphics(void *unusedCtx,unsigned kind,unsigned short heapId)
{
    void *h;
    h=ARC_TOOL_CreateHandle(0x89,heapId);
    switch(kind) {
    case 0:
        ARC_UTIL_UploadBgCharFromHandle(h,0x26,3,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x28,3,0,0,0,heapId);
        break;
    case 1:
        ARC_UTIL_UploadBgCharFromHandle(h,0x26,6,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x28,6,0,0,0,heapId);
        break;
    case 2:
        ARC_UTIL_UploadBgCharFromHandle(h,0x6b,0,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2,0,0,0,0,heapId);
        break;
    case 3:
        ARC_UTIL_UploadBgCharFromHandle(h,0x26,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x27,2,0,0,0,heapId);
        break;
    case 4:
        ARC_UTIL_UploadBgCharFromHandle(h,0x26,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1a,2,0,0,0,heapId);
        break;
    case 5:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x5,5,0,0,0,heapId);
        break;
    case 6:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2d,2,0,0,0,heapId);
        break;
    case 7:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2c,2,0,0,0,heapId);
        break;
    case 8:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2b,2,0,0,0,heapId);
        break;
    case 9:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x61,5,0,0,0,heapId);
        break;
    case 10:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x63,2,0,0,0,heapId);
        break;
    case 11:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x64,2,0,0,0,heapId);
        break;
    case 12:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x65,2,0,0,0,heapId);
        break;
    case 13:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x66,2,0,0,0,heapId);
        break;
    case 19:
        ARC_UTIL_UploadBgCharFromHandle(h,0x6b,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2,2,0,0,0,heapId);
        break;
    case 14:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x62,2,0,0,0,heapId);
        break;
    case 15:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x67,5,0,0,0,heapId);
        break;
    case 18:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x68,2,0,0,0,heapId);
        break;
    case 17:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x69,2,0,0,0,heapId);
        break;
    case 16:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x6a,2,0,0,0,heapId);
        break;
    case 20:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1f,5,0,0,0,heapId);
        break;
    case 21:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1d,5,0,0,0,heapId);
        break;
    case 22:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0xd,5,0,0,0,heapId);
        break;
    case 23:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0xe,5,0,0,0,heapId);
        break;
    case 24:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x3,2,0,0,0,heapId);
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,6,5,0,0,0,heapId);
        break;
    case 25:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,2,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1b,2,0,0,0,heapId);
        break;
    case 26:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1e,5,0,0,0,heapId);
        break;
    case 28:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x1c,5,0,0,0,heapId);
        break;
    case 27:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x20,5,0,0,0,heapId);
        break;
    case 29:
        ARC_UTIL_UploadBgCharFromHandle(h,0x26,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x12,5,0,0,0,heapId);
        break;
    case 30:
        ARC_UTIL_UploadBgCharFromHandle(h,0x21,5,0,0,0,heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h,0x2f,5,0,0,0,heapId);
        break;
    }
    ARC_TOOL_DeleteHandle(h);
}

void BR_RES_ApplyBgSet(void *unusedA, unsigned palSet)
{
    switch(palSet){
    case 24:
        BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);
        BG_SYS_ClearSlot(5);BG_SYS_PushTile(5);break;
    case 0:BG_SYS_ClearSlot(3);BG_SYS_PushTile(3);break;
    case 1:BG_SYS_ClearSlot(6);BG_SYS_PushTile(6);break;
    case 2:BG_SYS_ClearSlot(0);BG_SYS_PushTile(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        BG_SYS_ClearSlot(5);BG_SYS_PushTile(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);break;
    case 14:break;
    }
}

void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId)
{
    struct BrResSprite *sprite;

    sprite = &res->sprite[spriteIndex];

    if (res->spriteLoaded[spriteIndex] != 0) {
        GF_PANIC_Fail(PM_LANG_JA(d_02200D48, str_ja_02200E8C), PM_SRC_LINE(0, 0x218), PM_LANG_JA(d_02200D48, str_ja_02200E98));
    }

    switch (spriteIndex) {
    case 4: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x24, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 5: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x24, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 0: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x22, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 1: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x22, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 2: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x3f, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 3: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x3f, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 6: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x23, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 7, 8, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 8: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x56, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 7: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x56, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 11: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = CLACT_RegisterPaletteEx(h, 0x13, 1, 0x80, 0, 1, heapId);
        sprite->charId = CLACT_RegisterCharacter(h, 0xf, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x10, 0x11, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 12: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = CLACT_RegisterPaletteEx(h, 0x33, 1, 0xa0, 0, 1, heapId);
        sprite->charId = CLACT_RegisterCharacter(h, 0x32, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x30, 0x31, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 9: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[0];
        sprite->charId = CLACT_RegisterCharacter(h, 0x36, 0, 0, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 10: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
        sprite->paletteId = res->paletteId[1];
        sprite->charId = CLACT_RegisterCharacter(h, 0x36, 0, 1, heapId);
        sprite->cellAnimId = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, heapId);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 13: {
        void *h = ARC_TOOL_CreateHandle(0x89, heapId);
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
    h=ARC_TOOL_CreateHandle(0x89,heapId);
    res->paletteId[screen]=CLACT_RegisterPaletteEx(h,BR_RES_GetPaletteFileId(res->palSet),screen,0,0,13,heapId);
    if(screen==0){
        ARC_UTIL_UploadPaletteFromHandleWhole(h,BR_RES_GetCharFileId(res->palSet),0,0,0,heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(h,BR_RES_GetScreenFileId(res->palSet),0,0x1c0,0x20,heapId);
    }else{
        ARC_UTIL_UploadPaletteFromHandleWhole(h,BR_RES_GetCharFileId(res->palSet),4,0,0,heapId);
        ARC_UTIL_UploadPaletteFromHandleWhole(h,BR_RES_GetScreenFileId(res->palSet),4,0x1c0,0x20,heapId);
    }
    ARC_TOOL_DeleteHandle(h);
}

void BR_RES_ReleaseUiPalette(struct BrRes *res, int screen)
{
    CLACT_ReleasePalette(res->paletteId[screen]);
    res->paletteId[screen] = -1;
}

void *BR_RES_GetFont(struct BrRes *res) { return res->font; }

void *BR_RES_GetMsgData(struct BrRes *res)
{
    return res->msgData;
}

/*
 * trailing: two zero padding bytes at 021FC222, then existing matched 021FC224.
 */
void *BR_RES_GetWordSet(struct BrRes *res)
{
    return res->wordSet;
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
    h=ARC_TOOL_CreateHandle(0x89,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetPaletteFileId(res->palSet),2,0,0x1C0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetPaletteFileId(res->palSet),3,0,0x1C0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetCharFileId(res->palSet),0,0,0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetCharFileId(res->palSet),1,0,0,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetScreenFileId(res->palSet),0,0xE0,0x20,heapId);
    BR_FADE_LoadPalette(fade,h,BR_RES_GetScreenFileId(res->palSet),1,0xE0,0x20,heapId);
    ARC_TOOL_DeleteHandle(h);
}

unsigned short BR_RES_GetPaletteFileId(unsigned palSet) { if(palSet>=8)GF_PANIC_Fail(PM_LANG_JA(d_02200D48, str_ja_02200E8C),PM_SRC_LINE(0, 0x409),PM_LANG_JA(d_02200D48, str_ja_02200EBC));return d_022008C0[palSet]; }

unsigned short BR_RES_GetCharFileId(unsigned palSet) { if(palSet>=8)GF_PANIC_Fail(PM_LANG_JA(d_02200D48, str_ja_02200E8C),PM_SRC_LINE(0, 0x424),PM_LANG_JA(d_02200D48, str_ja_02200EE0));return d_022008A0[palSet]; }

unsigned short BR_RES_GetScreenFileId(unsigned palSet) { if(palSet>=8)GF_PANIC_Fail(PM_LANG_JA(d_02200D48, str_ja_02200E8C),PM_SRC_LINE(0, 0x43F),PM_LANG_JA(d_02200D48, str_ja_02200F04));return d_02200880[palSet]; }

u16 BR_RES_GetSetParam(u32 palSet){if(palSet>=8)GF_PANIC_Fail(PM_LANG_JA(d_02200D48, str_ja_02200E8C),PM_SRC_LINE(0, 0x45A),PM_LANG_JA(d_02200D48, str_ja_02200F28));return *(const u32*)((char *)d_022008E0+palSet*4);}
