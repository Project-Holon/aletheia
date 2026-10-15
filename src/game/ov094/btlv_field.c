/*
 * file:     btlv_field.c
 * unit:     yes
 * function: BTLV_FIELD_Create, BTLV_FIELD_Delete, BTLV_FIELD_UpdateAnims, BTLV_FIELD_Draw, BTLV_FIELD_InitEntry, BTLV_FIELD_IsEffectActive, BTLV_FIELD_SetState
 * address:  0x021F6B04
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
 *   sub_02030734 0x02030734 arm
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
 *   sub_020307B0 0x020307B0 arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   gBtlvFieldFileName 0x0220AC50 data ov094 a1
 *   BTLV_EFFECT_UpdateTexturePaletteFade 0x021F9364 thumb ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_field_shared_types.h"

extern void *sub_02030734(u32, u32, int, const char *, u16);

extern void *ARC_TOOL_LoadMember(u32, u32, u32);

extern G3dResource *G3D_SYSTEM_CreateResourceArc(u32, u32);

extern int G3D_SYSTEM_TransVramTexture(G3dResource *);

extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *, u32, G3dResource *);

extern G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *, const G3dResource *, u32);

extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *, G3dAnime **, int);

extern int G3D_SYSTEM_EnableObjectAnime(G3dObject *, u32 idx);

extern void MTX_Identity33_(int *rotate);

extern void *G3D_SYSTEM_GetResourceFile(G3dResource *);

extern NNSG3dResTex *NNS_G3dGetTex(void *file);

extern u32 sub_020307B0(void *p);

extern void G3D_SYSTEM_DeleteAnime(G3dAnime *);

extern void G3D_SYSTEM_DeleteResource(G3dResource *);

extern u32 func_020307B0(void *p);

extern void G3D_SYSTEM_DeleteObject(G3dObject *);

extern void G3D_SYSTEM_DeleteRender(G3dRender *);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *, int idx, int amount);

extern void G3D_SYSTEM_DrawObject(G3dObject *, G3dObjectStatus *);

BtlvField *BTLV_FIELD_Create(int unused, int group, u8 variant, u16 heap);

void BTLV_FIELD_Delete(BtlvField *field);

void BTLV_FIELD_UpdateAnims(BtlvField *field);

void BTLV_FIELD_Draw(BtlvField *field);

void BTLV_FIELD_InitEntry(BtlvField *field, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color);

int BTLV_FIELD_IsEffectActive(BtlvField *field);

void BTLV_FIELD_SetState(BtlvField *field, u32 hide);

void BTLV_EFFECT_UpdateTexturePaletteFade(BtlvPalFade *fade);

extern const char gBtlvFieldFileName[];

/*
 * Lever: u8 variant spills at entry before the other parameter copies;
 * int variant moves that spill three instructions later (8 differing bytes).
 * The ov094 caller at 021F76D6 passes the byte-derived selector.
 */
BtlvField *BTLV_FIELD_Create(int unused, int group, u8 variant, u16 heap)
{
    BtlvField *field;
    int (*table)[4][4];
    int i, j;
    int bytes;
    field = sub_02030734(heap, 0x70, 1, gBtlvFieldFileName, 0x56);
    table = ARC_TOOL_LoadMember(0x98, 1, (u16)((heap & 0x7fff) | 0x8000));
    field->heap = heap;
    if (table[group][0][variant] != -1)
        field->resource = G3D_SYSTEM_CreateResourceArc(11, table[group][0][variant]);
    else
        field->resource = G3D_SYSTEM_CreateResourceArc(11, table[group][0][0]);
    G3D_SYSTEM_TransVramTexture(field->resource);
    field->animCount = 0;
    for (i = 1; i < 4; i++)
        if (table[group][i][variant] != -1) field->animCount++;
    field->render = G3D_SYSTEM_CreateRender(field->resource, 0, field->resource);
    j = 0;
    if (field->animCount != 0) {
        field->animResource = sub_02030734(field->heap, field->animCount * 4, 0, gBtlvFieldFileName, 0x7e);
        field->anime = sub_02030734(field->heap, field->animCount * 4, 0, gBtlvFieldFileName, 0x7f);
        field->animState = sub_02030734(field->heap, field->animCount * 16, 1, gBtlvFieldFileName, 0x80);
        for (i = 1; i < 4; i++) {
            if (table[group][i][variant] != -1) {
                field->animResource[j] = G3D_SYSTEM_CreateResourceArc(11, table[group][i][variant]);
                field->anime[j] = G3D_SYSTEM_CreateAnime(field->render, field->animResource[j], 0);
                field->animState[j].kind = BTLV_ANIM_LOOP;
                j++;
            }
        }
        field->object = G3D_SYSTEM_CreateObject(field->render, field->anime, (u16)field->animCount);
        for (j = 0; j < field->animCount; j++) G3D_SYSTEM_EnableObjectAnime(field->object, (u16)j);
    } else {
        field->object = G3D_SYSTEM_CreateObject(field->render, 0, (u16)0);
    }
    field->status.trans.x = 0;
    field->status.trans.y = 0;
    field->status.trans.z = 0;
    field->status.scale.x = 0x1000;
    field->status.scale.y = 0x1000;
    field->status.scale.z = 0x1000;
    MTX_Identity33_(field->status.rotate);
    bytes = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(field->resource))->plttInfo.sizePltt * 8;
    field->palFade.resources = sub_02030734(field->heap, 4, 0, gBtlvFieldFileName, 0xaa);
    field->palFade.palettes = sub_02030734(field->heap, 4, 0, gBtlvFieldFileName, 0xab);
    *field->palFade.resources = field->resource;
    *field->palFade.palettes = sub_02030734(field->heap, bytes, 0, gBtlvFieldFileName, 0xae);
    field->palFade.enabled = 0;
    field->palFade.count = 1;
    sub_020307B0(table);
    return field;
}

void BTLV_FIELD_Delete(BtlvField *field)
{
    int i;

    G3D_SYSTEM_DeleteObject(field->object);
    if (field->animCount != 0) {
        for (i = 0; i < field->animCount; i++) {
            G3D_SYSTEM_DeleteAnime(field->anime[i]);
            G3D_SYSTEM_DeleteResource(field->animResource[i]);
        }
        func_020307B0(field->animState);
        func_020307B0(field->anime);
        func_020307B0(field->animResource);
    }
    G3D_SYSTEM_DeleteRender(field->render);
    G3D_SYSTEM_DeleteResource(field->resource);
    func_020307B0(*field->palFade.palettes);
    func_020307B0(field->palFade.palettes);
    func_020307B0(field->palFade.resources);
    func_020307B0(field);
}

/*
 * Lever: the `adds r6, r4, #0` before the loop is a zero (r4 is 0 there) that
 * the loop-back branch skips; it is the constant 0 (default amount and the
 * cleared field), not a copy of i. The flag word is a bitfield (lsls/lsrs).
 */
void BTLV_FIELD_UpdateAnims(BtlvField *field)
{
    int i;
    int amount;

    if (field->skipUpdate) {
        field->skipUpdate = 0;
        return;
    }
    if (field->animCount != 0) {
        for (i = 0; i < field->animCount; i++) {
            BtlvAnimState *state;

            state = &field->animState[i];
            amount = 0;
            switch (state->kind) {
            case BTLV_ANIM_LOOP:
                amount = 0x1000;
                break;
            case BTLV_ANIM_TIMED:
                if (state->armed == 1) {
                    amount = state->speed;
                    state->updatesLeft--;
                    if (field->animState[i].updatesLeft == 0)
                        field->animState[i].armed = 0;
                }
                break;
            }
            if (amount != 0)
                G3D_SYSTEM_LoopObjectAnimeFrame(field->object, (u16)i, amount);
        }
    }
    BTLV_EFFECT_UpdateTexturePaletteFade(&field->palFade);
}

/*
 * Draws the field unless it is hidden.
 */
void BTLV_FIELD_Draw(BtlvField *field)
{
    if (!field->hidden)
        G3D_SYSTEM_DrawObject(field->object, &field->status);
}

void BTLV_FIELD_InitEntry(BtlvField *field, unsigned char startLevel, unsigned char targetLevel, unsigned char interval, unsigned short color)
{
    field->palFade.enabled = 1;
    field->palFade.current = startLevel;
    field->palFade.target = targetLevel;
    field->palFade.wait = 0;
    field->palFade.interval = interval;
    field->palFade.color = color;
}

int BTLV_FIELD_IsEffectActive(BtlvField *field)
{
    return field->palFade.enabled != 0;
}

/*
 * Unlabelled leaf, filed as the blocker of ov094 BTLV_EFFECT_SetStageLayerEnable (lane S22).
 */
void BTLV_FIELD_SetState(BtlvField *field, u32 hide)
{
    field->hidden = hide;
}
