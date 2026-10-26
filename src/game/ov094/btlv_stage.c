/*
 * file:     btlv_stage.c
 * unit:     yes
 * function: BTLV_STAGE_Create, BTLV_STAGE_Delete, BTLV_STAGE_UpdateLayerAnims, BTLV_STAGE_DrawLayers, BTLV_STAGE_StartTint, BTLV_STAGE_IsTintActive, BTLV_STAGE_SetLayerHidden, BTLV_STAGE_ArmLayerEntry, BTLV_STAGE_IsAnyLayerArmed
 * address:  0x021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gBtlvStageFileName 0x0220AC40 data
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   BTLV_EFFECT_UpdateTexturePaletteFade 0x021F9364 thumb ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

#include "../arm9/g3d_system.h"






#include "../arm9/fx_mtx33.h"


#include "../arm9/nns_g3d_res.h"

#include "../arm9/g3x.h"









BtlvStage *BTLV_STAGE_Create(int mode, int group, int variant, u16 heap);

void BTLV_STAGE_Delete(BtlvStage *stage);

void BTLV_STAGE_UpdateLayerAnims(BtlvStage *stage);

void BTLV_STAGE_DrawLayers(BtlvStage *stage);

void BTLV_STAGE_StartTint(BtlvStage *stage, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);

int BTLV_STAGE_IsTintActive(BtlvStage *stage);

void BTLV_STAGE_SetLayerHidden(BtlvStage *stage, u32 side, u32 hide);

void BTLV_STAGE_ArmLayerEntry(BtlvStage *stage, int side, int anim, int speed, int updates);

int BTLV_STAGE_IsAnyLayerArmed(BtlvStage *stage);

#include "btlv_effect.h"

extern const char gBtlvStageFileName[];

BtlvStage *BTLV_STAGE_Create(int mode, int group, int variant, u16 heap)
{
    BtlvStage *stage;
    BtlvStageFiles *table;
    int i, k, m;
    int bytes;
    stage = GFL_HEAP_Alloc(heap, sizeof(*stage), 1, gBtlvStageFileName, 0x63);
    table = ARC_TOOL_LoadMember(0x98, 2, (u16)((heap & 0x7fff) | 0x8000));
    stage->heap = heap;
    if (mode == 3)
        stage->resource = G3D_SYSTEM_CreateResourceArc(11, 0x56);
    else if (table[group].fileId[0][variant] != -1)
        stage->resource = G3D_SYSTEM_CreateResourceArc(11, table[group].fileId[0][variant]);
    else
        stage->resource = G3D_SYSTEM_CreateResourceArc(11, table[group].fileId[0][0]);
    G3D_SYSTEM_TransVramTexture(stage->resource);
    stage->animCount = 0;
    for (i = 1; i < 4; i++)
        if (table[group].fileId[i][variant] != -1) stage->animCount++;
    stage->render[0] = G3D_SYSTEM_CreateRender(stage->resource, 0, stage->resource);
    stage->render[1] = G3D_SYSTEM_CreateRender(stage->resource, 0, stage->resource);
    if (mode == 3) {
        stage->animCount = 1;
        stage->animResource = GFL_HEAP_Alloc(stage->heap, sizeof(*stage->animResource), 0, gBtlvStageFileName, 0x93);
        *stage->animResource = G3D_SYSTEM_CreateResourceArc(11, 0x57);
        for (i = 0; i < 2; i++) {
            stage->anime[i] = GFL_HEAP_Alloc(stage->heap, sizeof(*stage->anime[i]), 0, gBtlvStageFileName, 0x98);
            stage->animState[i] = GFL_HEAP_Alloc(stage->heap, 0x10, 1, gBtlvStageFileName, 0x99);
            *stage->anime[i] = G3D_SYSTEM_CreateAnime(stage->render[i], *stage->animResource, 0);
            stage->animState[i]->kind = BTLV_ANIM_TIMED;
            stage->object[i] = G3D_SYSTEM_CreateObject(stage->render[i], stage->anime[i], (u16)stage->animCount);
            G3D_SYSTEM_EnableObjectAnime(stage->object[i], (u16)0);
        }
    } else if (stage->animCount != 0) {
        stage->animResource = GFL_HEAP_Alloc(stage->heap, stage->animCount * sizeof(*stage->animResource), 0, gBtlvStageFileName, 0xa7);
        for (i = 0; i < 2; i++) {
            stage->anime[i] = GFL_HEAP_Alloc(stage->heap, stage->animCount * sizeof(*stage->anime[i]), 0, gBtlvStageFileName, 0xab);
            stage->animState[i] = GFL_HEAP_Alloc(stage->heap, stage->animCount * 16, 1, gBtlvStageFileName, 0xac);
        }
        k = 0;
        for (i = 1; i < 4; i++) {
            if (table[group].fileId[i][variant] != -1) {
                stage->animResource[k] = G3D_SYSTEM_CreateResourceArc(11, table[group].fileId[i][variant]);
                for (m = 0; m < 2; m++) {
                    stage->anime[m][k] = G3D_SYSTEM_CreateAnime(stage->render[m], stage->animResource[k], 0);
                    stage->animState[m][k].kind = BTLV_ANIM_LOOP;
                }
                k++;
            }
        }
        for (i = 0; i < 2; i++) {
            stage->object[i] = G3D_SYSTEM_CreateObject(stage->render[i], stage->anime[i], (u16)stage->animCount);
            for (m = 0; m < stage->animCount; m++) G3D_SYSTEM_EnableObjectAnime(stage->object[i], (u16)m);
        }
    } else {
        stage->object[0] = G3D_SYSTEM_CreateObject(stage->render[0], 0, (u16)0);
        stage->object[1] = G3D_SYSTEM_CreateObject(stage->render[1], 0, (u16)0);
    }
    bytes = ((NNSG3dResTex *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(stage->resource)))->plttInfo.sizePltt * 8;
    stage->palFade.resources = GFL_HEAP_Alloc(stage->heap, sizeof(*stage->palFade.resources), 0, gBtlvStageFileName, 0xd6);
    stage->palFade.palettes = GFL_HEAP_Alloc(stage->heap, sizeof(*stage->palFade.palettes), 0, gBtlvStageFileName, 0xd7);
    *stage->palFade.resources = stage->resource;
    *stage->palFade.palettes = GFL_HEAP_Alloc(stage->heap, bytes, 0, gBtlvStageFileName, 0xda);
    stage->palFade.enabled = 0;
    stage->palFade.count = 1;
    stage->status[0].trans.x = 0;
    stage->status[0].trans.y = 0;
    stage->status[0].trans.z = 0x572f;
    stage->status[0].scale.x = 0x1000;
    stage->status[0].scale.y = 0x1000;
    stage->status[0].scale.z = 0x1000;
    MTX_Identity33_(&stage->status[0].rotate);
    stage->status[1].trans.x = 0;
    stage->status[1].trans.y = 0;
    stage->status[1].trans.z = -0xcb7d;
    stage->status[1].scale.x = 0x1000;
    stage->status[1].scale.y = 0x1000;
    stage->status[1].scale.z = 0x1000;
    MTX_Identity33_(&stage->status[1].rotate);
    if (mode == 3) {
        stage->status[0].trans.z = 0xa000;
        stage->status[1].trans.z = -0xf000;
    }
    G3X_SetEdgeColorTable(&table[group]);
    GFL_HEAP_Free(table);
    return stage;
}

void BTLV_STAGE_Delete(BtlvStage *stage)
{
    int i;
    int side;

    if (stage->animCount != 0) {
        for (i = 0; i < stage->animCount; i++) {
            for (side = 0; side < 2; side++)
                G3D_SYSTEM_DeleteAnime(stage->anime[side][i]);
            G3D_SYSTEM_DeleteResource(stage->animResource[i]);
        }
        for (side = 0; side < 2; side++) {
            GFL_HEAP_Free(stage->anime[side]);
            GFL_HEAP_Free(stage->animState[side]);
        }
        GFL_HEAP_Free(stage->animResource);
    }
    for (side = 0; side < 2; side++) {
        G3D_SYSTEM_DeleteObject(stage->object[side]);
        G3D_SYSTEM_DeleteRender(stage->render[side]);
    }
    G3D_SYSTEM_DeleteResource(stage->resource);
    GFL_HEAP_Free(*stage->palFade.palettes);
    GFL_HEAP_Free(stage->palFade.palettes);
    GFL_HEAP_Free(stage->palFade.resources);
    GFL_HEAP_Free(stage);
}

void BTLV_STAGE_UpdateLayerAnims(BtlvStage *stage)
{
    int i;
    int side;
    int amount;

    if (stage->animCount != 0) {
        for (i = 0; i < stage->animCount; i++) {
            for (side = 0; side < 2; side++) {
                BtlvAnimState *state;

                state = (BtlvAnimState *)(i * 16 + (uptr)stage->animState[side]);
                amount = 0;
                switch (state->kind) {
                case BTLV_ANIM_LOOP:
                    amount = 0x1000;
                    break;
                case BTLV_ANIM_TIMED:
                    if (state->armed == 1) {
                        amount = state->speed;
                        state->updatesLeft--;
                        if (stage->animState[side][i].updatesLeft == 0)
                            stage->animState[side][i].armed = 0;
                    }
                    break;
                }
                if (amount != 0)
                    G3D_SYSTEM_LoopObjectAnimeFrame(stage->object[side], (u16)i, amount);
            }
        }
    }
    BTLV_EFFECT_UpdateTexturePaletteFade(&stage->palFade);
}

void BTLV_STAGE_DrawLayers(BtlvStage *stage)
{
    int side;

    for (side = 0; side < 2; side++) {
        if (!(stage->hiddenMask & (1 << side)))
            G3D_SYSTEM_DrawObject(stage->object[side], &stage->status[side]);
    }
}

void BTLV_STAGE_StartTint(BtlvStage *stage, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color)
{
    stage->palFade.enabled = 1;
    stage->palFade.current = startLevel;
    stage->palFade.target = targetLevel;
    stage->palFade.wait = 0;
    stage->palFade.interval = interval;
    stage->palFade.color = color;
}

int BTLV_STAGE_IsTintActive(BtlvStage *stage)
{
    return stage->palFade.enabled != 0;
}

void BTLV_STAGE_SetLayerHidden(BtlvStage *stage, u32 side, u32 hide)
{
    if (side == 2) {
        if (hide)
            stage->hiddenMask = 3;
        else
            stage->hiddenMask = 0;
    } else {
        if (hide)
            stage->hiddenMask = stage->hiddenMask | (1 << side);
        else
            stage->hiddenMask = stage->hiddenMask & ((1 << side) ^ 3);
    }
}

void BTLV_STAGE_ArmLayerEntry(BtlvStage *stage, int side, int anim, int speed, int updates)
{
    if (stage->animState[side][anim].kind == BTLV_ANIM_TIMED) {
        stage->animState[side][anim].armed = 1;
        stage->animState[side][anim].speed = speed;
        stage->animState[side][anim].updatesLeft = updates;
    }
}

int BTLV_STAGE_IsAnyLayerArmed(BtlvStage *stage)
{
    int i;

    for (i = 0; i < stage->animCount; i++) {
        if (stage->animState[0][i].armed == 1 || stage->animState[1][i].armed == 1)
            return 1;
    }
    return 0;
}
