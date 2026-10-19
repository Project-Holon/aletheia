/*
 * function: P_STA_INFO_DrawMemo
 * address: 0x021D8288
 * packet: pkt_ov131_021D8288
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 relaunch R8. The 0 passed as the number style to the
 *   later SetNumber calls is the same u8 local that later holds the best
 *   row index (stack slot 0x14); max is seeded from it before the table
 *   copies, and the loop counter is zeroed before the row lookup.
 *   WORDSET_Create takes an int heap here (no u8 narrowing in the caller).
 * symbols:
 *   P_STA_INFO_GetPlaceName 0x021D8784 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   d_021DC24C 0x021DC24C data
 *   d_021DC264 0x021DC264 data
 *   POKE_TOOL_IsBoxOwnedByPlayer  0x02018488  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   GF_FONT_CountLine  0x0201D2C8  thumb  arm9
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   SAVE_EVENT_CheckStage  0x0202F498  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
#include "../include/Obj00112.h"
#include "../include/Obj01547.h"
#include "../include/Obj23146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern u32 POKE_TOOL_GetBoxValue(void *, u32, u32);
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern int SAVE_EVENT_CheckStage(void *a0, int a1);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 POKE_TOOL_IsBoxOwnedByPlayer(void *, void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 GF_FONT_CountLine(struct StrObj *s);
extern void *P_STA_INFO_GetPlaceName(void *, u8 *, u32);
extern const u32 d_021DC24C[6];
extern const u8 d_021DC264[6][6];

struct Tbl6 { u32 v[6]; };
struct Tbl36 { u8 v[6][6]; };

void P_STA_INFO_DrawMemo(u8 *a, u8 *p, void *mon)
{
    void *s6c;
    void *s68;
    u32 v5c;
    int y;
    u32 known;
    u32 isEgg;
    u32 v4c;
    u32 v48;
    u32 v44;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u32 v2c;
    u32 v28;
    u32 v24;
    u32 v20;
    u32 flags;
    void *str;
    void *ws;
    void *t;
    u32 f96;
    u32 fl0;
    u32 fl1;
    u32 fl2;
    u32 fl3;
    u16 msg;
    u16 msgAlt;
    u8 best;

    y = 0;
    isEgg = POKE_TOOL_GetBoxValue(mon, 0x4c, 0);
    v5c = POKE_TOOL_GetBoxValue(mon, 0x70, 0);
    v4c = POKE_TOOL_GetBoxValue(mon, 9, 0);
    v48 = POKE_TOOL_GetBoxValue(mon, 0x8f, 0);
    v44 = POKE_TOOL_GetBoxValue(mon, 0x90, 0);
    v40 = POKE_TOOL_GetBoxValue(mon, 0x91, 0);
    v3c = POKE_TOOL_GetBoxValue(mon, 0x92, 0);
    v38 = POKE_TOOL_GetBoxValue(mon, 0x93, 0);
    v34 = POKE_TOOL_GetBoxValue(mon, 0x94, 0);
    v30 = POKE_TOOL_GetBoxValue(mon, 0x99, 0);
    v2c = POKE_TOOL_GetBoxValue(mon, 0x6d, 0);
    v28 = POKE_TOOL_GetBoxValue(mon, 0x77, 0);
    v24 = POKE_TOOL_GetBoxValue(mon, 0, 0);
    v20 = POKE_TOOL_GetBoxValue(mon, 0x95, 0);
    f96 = POKE_TOOL_GetBoxValue(mon, 0x96, 0);
    fl0 = SAVE_EVENT_CheckStage(mon, 0);
    fl1 = SAVE_EVENT_CheckStage(mon, 1);
    fl2 = SAVE_EVENT_CheckStage(mon, 2);
    fl3 = SAVE_EVENT_CheckStage(mon, 3);
    flags = fl0 | fl1 | fl2 | fl3;
    known = POKE_TOOL_IsBoxOwnedByPlayer(mon, GAME_DATA_GetMyStatus(((struct Obj23146 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f8));

    if (isEgg == 0) {
        t = func_02045EC0(((struct Obj01547 *)p)->f38, v5c);
        PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84, (u32)BMP_WIN_GetBmp(((struct Obj01547 *)p)->f34), (s16)1, (s16)1, (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        STRBUF_Delete(t);
        y = 0x10;
    }
    str = STRBUF_Create(0x100, ((struct Obj00112 *)a)->f0);
    ws = WORDSET_Create(10, 0x20, ((struct Obj00112 *)a)->f0);
    if (isEgg == 0) {
        if (f96 == 0x7531) {
            msgAlt = 0x29;
            msg = 0x2b;
            if (v2c == 1) {
                msgAlt = 0x2d;
                msg = 0x2f;
            }
            switch (v28) {
            case 1: case 2: case 3:
                f96 = 0x7536;
                break;
            case 4: case 5:
                f96 = 0x7534;
                break;
            case 7: case 8:
                f96 = 0x7535;
                msg = msgAlt;
                break;
            case 10: case 11: case 12:
                f96 = 0x7537;
                msg = msgAlt;
                break;
            case 15:
                f96 = 0x7538;
                break;
            default:
                v20 = 0x7539;
                msg = msgAlt;
                break;
            }
        } else if (f96 >= 0x753a && f96 <= 0x753d && flags == 1) {
            switch (f96 - 0x753a) {
            case 0: msg = 0x31; break;
            case 1: msg = 0x32; break;
            case 2: msg = 0x33; break;
            case 3: msg = 0x34; break;
            }
        } else if (v2c == 0) {
            if (v20 == 0) {
                if (f96 == 0x7532) {
                    msg = 0x1b;
                } else {
                    msg = 0x19;
                }
            } else if (v20 <= 60000) {
                msg = 0x1d;
            } else {
                msg = 0x1f;
            }
        } else {
            msg = 0x21;
            if (v20 != 0) {
                msg = 0x23;
            }
        }
        if (known == 0) {
            if (f96 < 0x753a || f96 > 0x753d) {
                msg++;
            }
        }
    } else if (v2c == 0) {
        if (known == 1) {
            msg = 0x53;
        } else {
            msg = 0x54;
        }
    } else {
        msg = 0x55;
        if (known != 1) {
            msg = 0x56;
        }
    }
    s68 = P_STA_INFO_GetPlaceName(a, p, v20);
    s6c = P_STA_INFO_GetPlaceName(a, p, f96);
    WORDSET_SetSlotNumber(ws, 0, v3c, 2, 2, 1);
    best = 0;
    WORDSET_SetSlotNumber(ws, 1, v38, 2, best, 1);
    WORDSET_SetSlotNumber(ws, 2, v34, 2, best, 1);
    WORDSET_SetSlotNumber(ws, 3, v30, 3, best, 1);
    WORDSET_SetSlotTag(ws, 4, s6c, 0, 1, 2);
    WORDSET_SetSlotNumber(ws, 5, v48, 2, 2, 1);
    WORDSET_SetSlotNumber(ws, 6, v44, 2, best, 1);
    WORDSET_SetSlotNumber(ws, 7, v40, 2, best, 1);
    WORDSET_SetSlotTag(ws, 8, s68, best, 1, 2);
    t = func_02045EC0(((struct Obj01547 *)p)->f38, msg);
    WORDSET_CopyTaggedText(ws, str, t);
    PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84, (u32)BMP_WIN_GetBmp(((struct Obj01547 *)p)->f34), (s16)1, (s16)(y + 1), (u32)str, (u32)(((struct Obj00112 *)a)->f80), 0x440);
    WORDSET_Delete(ws);
    y += GF_FONT_CountLine(str) << 4;
    STRBUF_Delete(s68);
    STRBUF_Delete(s6c);
    STRBUF_Delete(t);
    STRBUF_Delete(str);
    if (isEgg == 0) {
        struct Tbl6 ids;
        struct Tbl36 rows;
        u8 max;
        u8 i;
        const u8 *row;
        u32 v;
        max = best;
        ids = *(const struct Tbl6 *)d_021DC24C;
        rows = *(const struct Tbl36 *)d_021DC264;
        i = 0;
        row = rows.v[(u8)(v24 % 6)];
        for (; i < 6; i++) {
            v = POKE_TOOL_GetBoxValue(mon, ids.v[row[i]], 0);
            if (max < v) {
                max = v;
                best = row[i];
            }
        }
        t = func_02045EC0(((struct Obj01547 *)p)->f38, best * 5 + 0x35 + max % 5);
        PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84, (u32)BMP_WIN_GetBmp(((struct Obj01547 *)p)->f34), (s16)1, (s16)(y + 1), (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        STRBUF_Delete(t);
    } else {
        u32 id;
        if (v4c <= 5) {
            id = 0x57;
        } else if (v4c <= 10) {
            id = 0x58;
        } else if (v4c <= 40) {
            id = 0x59;
        } else {
            id = 0x5a;
        }
        t = func_02045EC0(((struct Obj01547 *)p)->f38, id);
        PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84, (u32)BMP_WIN_GetBmp(((struct Obj01547 *)p)->f34), (s16)1, (s16)(y + 1), (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        STRBUF_Delete(t);
    }
}
