/*
 * file:     worldtrade_sublcd.c
 * unit:     yes
 * function: WORLDTRADE_SUBLCD_CreateActors, WORLDTRADE_SUBLCD_StartAnimTaskA, WORLDTRADE_SUBLCD_SetActorAnim, WORLDTRADE_SUBLCD_AnimTaskA, WORLDTRADE_SUBLCD_StartAnimTaskB, WORLDTRADE_SUBLCD_AnimTaskB, WORLDTRADE_SUBLCD_SetActorSurfacePos, WORLDTRADE_SUBLCD_CheckButtonTouch, WORLDTRADE_SUBLCD_UpdateSlotPalettes, WORLDTRADE_SUBLCD_GetSlotAnimBase, WORLDTRADE_SUBLCD_UpdateSlotAnims, WORLDTRADE_SUBLCD_LoadPalette, WORLDTRADE_SUBLCD_LoadSlotPalette, WORLDTRADE_SUBLCD_FreeResources, WORLDTRADE_SUBLCD_MoveArrowToSlot, WORLDTRADE_SUBLCD_SetSlotActorPositions, WORLDTRADE_SUBLCD_SetSlotActorPositionsLower
 * address:  0x021FF6A4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_SUBLCD_CreateActors 0x021FF6A4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   WORLDTRADE_SUBLCD_FreeResources  0x021FFCD4  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositionsLower 0x021FFD74 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   tbl_022038A2   0x022038A2  data  a2
 *   TCB_AddTask 0x02030DA8 arm
 *   TCBL_GetOwnedWork 0x02030EE8 arm
 *   str_02203E44 0x02203E44 data a1
 *   d_022038BE 0x022038BE data a2
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   ARC_UTIL_LoadScreenDataFromArchive  0x02049E34  arm
 *   GXS_LoadOBJ 0x0207E804 arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   d_02203884 0x02203884 data a2
 *   d_02203892 0x02203892 data a1
 */
#include "worldtrade_types.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/arc_util.h"

#include "../arm9/os_cache.h"

#include "../arm9/clact.h"
struct TcbTask;

#include "../arm9/tcb_list.h"

struct Actor;





struct PtS;

struct S02030EE8;

typedef WorldtradeSubAnim Anim;




#include "../arm9/gfl_use.h"

#include "worldtrade.h"

#include "../arm9/touchpanel.h"

struct TcbSystem;

struct TcblSystem;

#include "../arm9/tcbl.h"



#include "../arm9/gx_load2d.h"


void WORLDTRADE_SUBLCD_CreateActors(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_StartAnimTaskA(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_SetActorAnim(WorldtradeSubAnim *p, u32 v);

void WORLDTRADE_SUBLCD_AnimTaskA(struct TcbTask *task, void *arg);

void WORLDTRADE_SUBLCD_StartAnimTaskB(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_AnimTaskB(struct TcbTask *task, void *arg);

void WORLDTRADE_SUBLCD_SetActorSurfacePos(struct ClactActor *a, int b, int c);

int WORLDTRADE_SUBLCD_CheckButtonTouch(int n);

void WORLDTRADE_SUBLCD_UpdateSlotPalettes(WorldtradeWork *p, int count, int flag);

int WORLDTRADE_SUBLCD_GetSlotAnimBase(int i);

void WORLDTRADE_SUBLCD_UpdateSlotAnims(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_LoadPalette(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_LoadSlotPalette(NNSG2dCharacterData **chr, McssPlttData *q, int k, int n, int unused4);

void WORLDTRADE_SUBLCD_FreeResources(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_MoveArrowToSlot(WorldtradeWork *p, int i, int dy);

void WORLDTRADE_SUBLCD_SetSlotActorPositions(WorldtradeWork *p);

void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(WorldtradeWork *p);

extern const WorldtradePos tbl_022038A2[];

extern const char str_02203E44[];

extern char d_022038BE;

extern const u16 d_02203884[];

extern const u8 d_02203892[];

/*
 * Create the screen's sprites after loading their graphics
 * (WORLDTRADE_SUBLCD_LoadPalette): the header sprite, seven list sprites placed from the
 * position table with palettes 2..8, the arrow sprite and the page
 * sprite, then record the position of each of the first eight sprites
 * at +0xEC4.
 */
void WORLDTRADE_SUBLCD_CreateActors(WorldtradeWork *p)
{
    Local s;
    SPos pos;
    int i;

    WORLDTRADE_SUBLCD_LoadPalette((WorldtradeWork *)p);
    s.a = 0x80;
    s.b = 0x82;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    p->spr[0] = CLACT_CreateActor((struct Unit *)p->res_res.unit, p->res_res.primaryChar, p->res_res.primaryPlt, p->res_res.primaryCell, (const struct ActorInitParam *)&s, 1, 0x48);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->spr[0], 1);
    CLACT_SetActorBgPriority((struct ClactActor *)p->spr[0], 2);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->spr[0], 3);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->spr[0], 1);
    for (i = 0; i < 7; i++) {
        p->spr[i + 1] = CLACT_CreateActor((struct Unit *)p->res_res.unit, p->res_res.slotChar, p->res_res.slotPlt, p->res_res.slotCell, (const struct ActorInitParam *)&s, 1, 0x48);
        CLACT_SetActorAutoAnim((struct ClactActor *)p->spr[i + 1], 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->spr[i + 1], i * 4 + 0xE);
        CLACT_SetActorDrawEnable((struct ClactActor *)p->spr[i + 1], 0);
        WORLDTRADE_SUBLCD_SetActorSurfacePos((struct ClactActor *)p->spr[i + 1], tbl_022038A2[i].x, tbl_022038A2[i].y);
        CLACT_SetActorBgPriority((struct ClactActor *)p->spr[i + 1], 2);
        CLACT_SetActorPaletteOffset((struct ClactActor *)p->spr[i + 1], (u8)(i + 2), 1);
    }
    p->arrow = CLACT_CreateActor((struct Unit *)p->res_res.unit, p->res_res.slotChar, p->res_res.slotPlt, p->res_res.slotCell, (const struct ActorInitParam *)&s, 1, 0x48);
    CLACT_SetActorAutoAnim(p->arrow, 1);
    CLACT_SetActorAnimSeq(p->arrow, 0x2b);
    CLACT_SetActorDrawEnable(p->arrow, 0);
    WORLDTRADE_SUBLCD_SetActorSurfacePos(p->arrow, 0x80, 0x56);
    CLACT_SetActorBgPriority(p->arrow, 1);
    p->scrollBarObj = CLACT_CreateActor((struct Unit *)p->res_res.unit, p->res_res.slotChar, p->res_res.slotPlt, p->res_res.slotCell, (const struct ActorInitParam *)&s, 1, 0x48);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->scrollBarObj, 1);
    CLACT_SetActorAnimSeq((struct ClactActor *)p->scrollBarObj, 0x2a);
    WORLDTRADE_SetActorSurfacePos((void *)p->scrollBarObj, 0x37, p->pageNum + 0xa8);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->scrollBarObj, 0);
    for (i = 0; i < 8; i++) {
        CLACT_GetActorSurfacePos((struct ClactActor *)p->spr[i], (struct ClactVec2 *)&pos, 1);
        p->pos_spos8[i].x = pos.x;
        p->pos_spos8[i].y = pos.y;
    }
}

void WORLDTRADE_SUBLCD_StartAnimTaskA(WorldtradeWork *p)
{
    Anim *a;
    WORLDTRADE_SUBLCD_CreateActors((WorldtradeWork *)p);
    p->animTaskData = GFL_HEAP_Alloc(0x48, sizeof(WorldtradeSubAnim), 0, str_02203E44, 0xD4);
    p->animTask = TCB_AddTask((struct TcbSystem *)p->rec_p, WORLDTRADE_SUBLCD_AnimTaskA, (void *)p->animTaskData, 5);
    a = (Anim *)TCBL_GetOwnedWork(p->animTask);
    a->state = 0;
    a->y = -40;
    a->p = p;
    p->active = 0;
    WORLDTRADE_SUBLCD_SetActorAnim(a, 0);
    GFL_USE_PlaySeDefaultVolume(0x790);
}

/*
 * Tail call into CLACT_SetActorAnimSeq with the object at +0xd0c and a u16 value.
 */
void WORLDTRADE_SUBLCD_SetActorAnim(WorldtradeSubAnim *p, u32 animSeq)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)p->p->spr[0], (u16)animSeq);
}

void WORLDTRADE_SUBLCD_AnimTaskA(struct TcbTask *task, void *arg)
{
    Anim *anim = arg;
    WorldtradeWork *p;
    p = anim->p;
    switch (anim->state) {
    case 0:
        if (anim->y > 160) {
            anim->y = 160;
            anim->state = 1;
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 1);
        }
        anim->y += 2;
        WORLDTRADE_SUBLCD_SetActorSurfacePos((struct ClactActor *)p->spr[0], 128, anim->y);
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct ClactActor *)p->spr[0]) == 0) {
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 2);
            anim->state = 2;
        }
        break;
    case 2:
        if (anim->y <= 138) {
            anim->y = 138;
            anim->state = 3;
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 3);
        } else {
            anim->y--;
        }
        WORLDTRADE_SUBLCD_SetActorSurfacePos((struct ClactActor *)p->spr[0], 128, anim->y);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x55C);
        anim->p->active = 1;
        GFL_HEAP_Free(anim);
        TCB_DeleteTask(task);
        break;
    }
}

void WORLDTRADE_SUBLCD_StartAnimTaskB(WorldtradeWork *p)
{
    Anim *a;
    p->animTaskData = GFL_HEAP_Alloc(0x48, sizeof(WorldtradeSubAnim), 0, str_02203E44, 0x150);
    p->animTask = TCB_AddTask((struct TcbSystem *)p->rec_p, WORLDTRADE_SUBLCD_AnimTaskB, (void *)p->animTaskData, 5);
    a = (Anim *)TCBL_GetOwnedWork(p->animTask);
    a->state = 0;
    a->y = 0x8A;
    a->p = p;
    WORLDTRADE_SUBLCD_SetActorAnim(a, 5);
    GFL_USE_PlaySeDefaultVolume(0x55D);
}

void WORLDTRADE_SUBLCD_AnimTaskB(struct TcbTask *task, void *arg)
{
    Anim *anim = arg;
    WorldtradeWork *p;
    p = anim->p;
    switch (anim->state) {
    case 0:
        if (anim->y > 160) {
            anim->y = 160;
            anim->state = 1;
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 6);
        }
        anim->y++;
        WORLDTRADE_SUBLCD_SetActorSurfacePos((struct ClactActor *)p->spr[0], 128, anim->y);
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct ClactActor *)p->spr[0]) == 0) {
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 0);
            anim->state = 2;
            GFL_USE_PlaySeDefaultVolume(0x791);
        }
        break;
    case 2:
        if (anim->y < -20) {
            anim->state = 3;
            WORLDTRADE_SUBLCD_SetActorAnim(anim, 3);
        }
        anim->y -= 2;
        WORLDTRADE_SUBLCD_SetActorSurfacePos((struct ClactActor *)p->spr[0], 128, anim->y);
        break;
    case 3:
        p->active = 1;
        GFL_HEAP_Free(anim);
        TCB_DeleteTask(task);
        break;
    }
}

/*
 * Send a one-entry u16 table {(u16)(b - 8), c}
/*
 * Send a one-entry u16 table {(u16)(b - 8), c} to CLACT_AddActorSurfacePos.
 */
void WORLDTRADE_SUBLCD_SetActorSurfacePos(struct ClactActor *obj, int x, int y)
{
    u16 t[2];

    t[0] = x;
    t[1] = y - 8;
    CLACT_AddActorSurfacePos((struct ClactActor *)obj, (const struct ClactVec2 *)t, 1);
}

int WORLDTRADE_SUBLCD_CheckButtonTouch(int count) { int r=TOUCHPANEL_HitTrg((const TouchHitTable *)&d_022038BE); if(r==-1 || r>=count) return -1; return r; }

/*
 * lever: signed offset locals b then a, with two literal assignments each,
 * reproduce the dead stack stores; compound updates reverse the first pair.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`a = 0xE5C;` before `a = 0xEA0;`; `b = 0x302;` before `b = 0x32E;`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void WORLDTRADE_SUBLCD_UpdateSlotPalettes(WorldtradeWork *p, int count, int flag)
{
    int i;
    int b, a;
    if (count != 0 && flag == 1) GFL_USE_PlaySeDefaultVolume(0x676);
    a = 0xEA0;
    b = 0x32E;
    for (i = 0; i < 7; i++) {
        if (i < count) {
            WORLDTRADE_SUBLCD_LoadSlotPalette((NNSG2dCharacterData **)((u8 *)&((struct WorldtradeWork *)p)->chr), (McssPlttData *)(p->palData), i, p->ent[i + 1].trainerView, p->ent[i + 1].sex);
            if (flag != 0) CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)p->spr[i + 1]), i * 4 + 14);
            else CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)p->spr[i + 1]), i * 4 + 17);
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)p->spr[i + 1]), 1);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)p->spr[i + 1]), 0);
        }
    }
}

/*
 * Index helper: returns index times 4 plus 0xe.
 */
int WORLDTRADE_SUBLCD_GetSlotAnimBase(int slot)
{
    return (slot << 2) + 0xe;
}

/*
 * tail: 021FFC16..021FFC18 is two-byte zero alignment padding.
 */
void WORLDTRADE_SUBLCD_UpdateSlotAnims(WorldtradeWork *p)
{
    int i;
    for (i = 0; i < 7; i++) {
#if LANGUAGE == LANGUAGE_JAPANESE
        /* The Japanese cartridge checks neither the actor nor its current animation. */
        if (CLACT_GetActorDrawEnable((struct ClactActor *)((struct Actor *)p->spr[i + 1])) != 0) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)p->spr[i + 1]), WORLDTRADE_SUBLCD_GetSlotAnimBase(i) + 1);
        }
#else
        if (p->spr[i + 1] != 0) {
            int a;
            a = CLACT_GetActorAnimSeq((struct ClactActor *)((struct Actor *)p->spr[i + 1]));
            if (a != WORLDTRADE_SUBLCD_GetSlotAnimBase(i) + 1) {
                if (CLACT_GetActorDrawEnable((struct ClactActor *)((struct Actor *)p->spr[i + 1])) != 0) {
                    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)p->spr[i + 1]), WORLDTRADE_SUBLCD_GetSlotAnimBase(i) + 1);
                }
            }
        }
#endif
    }
}

/*
 * Load the palette (archive 0x20, file 0, out at +0xEA0, handle at
 * +0xE9C) and the 16 character files 0x31.. (handles at +0xE1C, char
 * data at +0xE5C) from archive 0x20 on heap 0x48, then flush the first
 * 0x200 bytes of each character block.
 */
void WORLDTRADE_SUBLCD_LoadPalette(WorldtradeWork *p)
{
    int i;

    p->main = ARC_UTIL_LoadPaletteBlockFromArchive(0x20, 0, (&p->palData), 0x48);
    for (i = 0; i < 16; i++) {
        p->buf[i] = ARC_UTIL_LoadScreenDataFromArchive(0x20, i + 0x31, 0, (&p->chr[i]), 0x48);
    }
    for (i = 0; i < 16; i++) {
        DC_FlushRange(p->chr[i]->pRawData, 0x200);
    }
}

void WORLDTRADE_SUBLCD_LoadSlotPalette(NNSG2dCharacterData **chr, McssPlttData *plttData, int slot, int iconIndex, int unused4)
{
    u8 *dst;
    if (iconIndex > 16) iconIndex = 16;
    else if (iconIndex < 0) iconIndex = 0;
    dst = plttData->data;
    GXS_LoadOBJ(chr[iconIndex]->pRawData, d_02203884[slot], 512);
    GXS_LoadOBJPltt(dst + d_02203892[iconIndex] * 32, (slot + 2) * 32, 32);
}

void WORLDTRADE_SUBLCD_FreeResources(WorldtradeWork *p)
{
    int i;

    if (p->active != 0) {
        if (p->main != 0) {
            GFL_HEAP_Free(p->main);
            p->main = 0;
        }
        for (i = 0; i < 16; i++) {
            if (p->buf[i] != 0) {
                GFL_HEAP_Free(p->buf[i]);
                p->buf[i] = 0;
            }
        }
    }
}

void WORLDTRADE_SUBLCD_MoveArrowToSlot(WorldtradeWork *p, int slot, int dy)
{
    WORLDTRADE_SUBLCD_SetActorSurfacePos(p->arrow, tbl_022038A2[slot].x, dy + (tbl_022038A2[slot].y + 0x20));
}

void WORLDTRADE_SUBLCD_SetSlotActorPositions(WorldtradeWork *p) {int i;for(i=0;i<8;i++) {void *v=(void *)p->spr[i];if(v) WORLDTRADE_SetActorSurfacePos(v, p->pos_spos8[i].x, p->pos_spos8[i].y);}}

void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(WorldtradeWork *p) {int i;for(i=0;i<8;i++) {void *v=(void *)p->spr[i];if(v) WORLDTRADE_SetActorSurfacePos(v, p->pos_spos8[i].x, p->pos_spos8[i].y+32);}}
