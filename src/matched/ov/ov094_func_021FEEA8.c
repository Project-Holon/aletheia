/*
 * function: BTLV_MCSS_AddPoke
 * address: 0x021FEEA8
 * packet: pkt_ov094_021FEEA8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; b34 is one two-bit assignment.
 * blocker: ARM9 0x02015D94 and 0x02015D88 have no outside witness.
 * Verified scratch C, EXACT (blocker_02015D94_r1.log):
 * void MCSS_SetShadowOffset(char *p, int *src) {
 *     *(int *)(p + 0x17c) = src[0];
 *     *(int *)(p + 0x180) = src[1];
 *     *(int *)(p + 0x184) = src[2];
 * }
 * Verified scratch C, EXACT (blocker_02015D88_r1.log):
 * typedef unsigned short u16;
 * void MCSS_SetShadowRotateZ(char *p, u16 value) { *(u16 *)(p + 0x17a) = value; }
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetShadowAlpha 0x02015FD4 thumb
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   MCSS_SetShadowRotateZ 0x02015D88 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   BTLV_MCSS_MakeAddWorkFromPoke 0x022003EC thumb ov094
 *   BTLV_MCSS_CalcSlotPosition 0x022018A8 thumb ov094
 *   BTLV_MCSS_SetSpriteWorkFlagForRule 0x0220055C thumb ov094
 *   BTLV_MCSS_LookupShadowEntry 0x02201A20 thumb ov094
 *   BTLV_MCSS_ApplySlotScale 0x022006B4 thumb ov094
 *   BTLV_MCSS_IdleAnimCallback 0x02201718 thumb ov094
 */
#include "../include/Obj13604.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { Vec orient, pos; } Vectors;
typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b34 : 2;
    unsigned int b5 : 1;
} Flags;
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
struct Obj;
struct Rec;
struct Sub150;
extern u32 POKE_TOOL_IsShiny(void *p);
extern u32 POKE_TOOL_GetPersonalParam(u16, u16, u32);
extern int BGWINFRM_GetScaleRank(u32, u32);
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void MCSS_SetShadowAlpha(char *p, int v);
extern void MCSS_SetShadowOffset(char *p, int *src);
extern void MCSS_SetShadowRotateZ(char *p, u16 value);
extern void MCSS_SetAnimCallback(void *, u32, void *, u32);
extern void BTLV_MCSS_MakeAddWorkFromPoke(void *, void *, int *, int);
extern void BTLV_MCSS_CalcSlotPosition(void *, Vec *, int);
extern void BTLV_MCSS_SetSpriteWorkFlagForRule(void *, int, int);
extern int BTLV_MCSS_LookupShadowEntry(int a, int b, int *o1, u16 *o2, int *o3);
extern void BTLV_MCSS_ApplySlotScale(void *, int);
extern void BTLV_MCSS_IdleAnimCallback(int i);
void BTLV_MCSS_AddPoke(char *w, void *src, int key)
{
    int i;
    int off;
    int visible;
    u16 angle;
    Vectors vectors;
    u32 a, b;
    for (i = 0; i < 14; i++) {
        if (*(void **)(w + i * 0x5c + 8) == 0)
            break;
    }
    if (key < 14 && i < 14) {
        off = i * 0x5c;
        *(int *)(w + 0x48 + off) = 0;
        ((Flags *)(w + 0x54 + off))->b0 = 0;
        ((Flags *)(w + 0x54 + off))->b1 = 0;
        ((Flags *)(w + 0x54 + off))->b5 = 0;
        ((Flags *)(w + 0x54 + off))->b2 = ((struct Obj13604 *)w)->f534;
        *(int *)(w + 0x50 + off) = key;
        *(u32 *)(w + 0x3c + off) = POKE_TOOL_GetPartyValue(src, 0, 0);
        *(u32 *)(w + 0x44 + off) = POKE_TOOL_GetPartyValue(src, 0x98, 0);
        if (POKE_TOOL_IsShiny(src) == 1)
            *(int *)(w + 0x48 + off) |= 2;
        BTLV_MCSS_MakeAddWorkFromPoke(w, src, (int *)(w + 0xc + off), key);
        BTLV_MCSS_CalcSlotPosition(w, &vectors.pos, key);
        *(void **)(w + 8 + off) = MCSS_Add(((struct Obj13604 *)w)->f4, vectors.pos.x, vectors.pos.y, vectors.pos.z, (void *)((u32)w + 0xc + off));
        BTLV_MCSS_SetSpriteWorkFlagForRule(w, key, 1);
        *(u32 *)(w + 0x34 + off) = POKE_TOOL_GetPartyValue(src, 5, 0);
        *(u32 *)(w + 0x38 + off) = POKE_TOOL_GetPartyValue(src, 0x6f, 0);
        *(u16 *)(w + 0x40 + off) = POKE_TOOL_GetPersonalParam(*(u32 *)(w + 0x34 + off), *(u32 *)(w + 0x38 + off), 0x26);
        a = POKE_TOOL_GetPartyValue(src, 0xa0, 0);
        b = POKE_TOOL_GetPartyValue(src, 0xa1, 0);
        *(u16 *)(w + 0x42 + off) = BGWINFRM_GetScaleRank(a, b);
        if (BTLV_MCSS_LookupShadowEntry(*(int *)(w + 0x34 + off), key, (int *)(&vectors.orient), &angle, &visible) == 0) {
            vectors.orient.x = -0x400;
            vectors.orient.y = 0;
            vectors.orient.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            MCSS_SetShadowAlpha(*(void **)(w + 8 + off), 0);
        else {
            MCSS_SetShadowOffset(*(void **)(w + 8 + off), (int *)(&vectors.orient));
            MCSS_SetShadowRotateZ(*(void **)(w + 8 + off), angle);
        }
        ((Flags *)(w + 0x54 + off))->b34 = 3;
        BTLV_MCSS_ApplySlotScale(w, key);
        MCSS_SetAnimCallback(*(void **)(w + 8 + off), i, (void *)BTLV_MCSS_IdleAnimCallback, 1);
    }
}
