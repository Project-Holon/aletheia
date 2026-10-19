/*
 * function: PLIST_PLATE_DrawMonInfo
 * address:  0x021BAB04
 * packet:   pkt_ov091_021BAB04
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   POKELIST_PrintExpandedTextMain  0x021B9CF4  thumb  ov091
 *   POKELIST_PrintTextMain  0x021B9C1C  thumb  ov091
 *   POKELIST_PrintTextSub  0x021B9C64  thumb  ov091
 *   POKELIST_PrintTextSubDirect  0x021B9CB0  thumb  ov091
 *   POKELIST_PrintExpandedTextSub  0x021B9D58  thumb  ov091
 *   POKELIST_PrintExpandedTextSubDirect  0x021B9DC0  thumb  ov091
 *   POKELIST_CheckEvolution  0x021B9BF4  thumb  ov091
 *   POKELIST_GetMoveLearnStatus  0x021B9AC8  thumb  ov091
 *   PLIST_PLATE_GetHpBarColor  0x021BB554  thumb  ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct WordSet;
struct Obj;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetStatusCondition(void *p);
extern u32 POKE_TOOL_CalcLevel(void *p);
extern u32 FILE_UTIL_IsMailItem(u16 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKELIST_PrintExpandedTextMain(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void POKELIST_PrintTextMain(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
extern void POKELIST_PrintTextSub(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
extern void POKELIST_PrintTextSubDirect(u8 *p, u32 win, u32 idx, u32 x, s16 y, u16 color);
extern void POKELIST_PrintExpandedTextSub(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern void POKELIST_PrintExpandedTextSubDirect(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern u32 POKELIST_CheckEvolution(u8 *p, void *mon, u32 param);
extern int POKELIST_GetMoveLearnStatus(u8 *p, void *mon, u8 bit);
extern int PLIST_PLATE_GetHpBarColor(u32 p);

#define W(o) (*(int *)(s + (o)))

void PLIST_PLATE_DrawMonInfo(u8 *a, u8 *s, int k)
{
    int f = 0;
    u32 ws;
    u32 ws2;
    u32 ws3;
    u32 code;
    u32 m;
    u32 r5;
    u32 r6;
    u32 v;
    u16 r;
    u8 *obj;

    if (*(int *)(*(u8 **)(a + 0x280) + 0x34) == 6 || *(int *)(a + 0x18) == 1) {
        f = 1;
    }
    if (k == 0) {
        ws = (u32)WORDSET_CreateDefault(*(u16 *)a);
        WORDSET_SetSlotMonNickname((struct WordSet *)ws, 0, *(void **)s);
        POKELIST_PrintExpandedTextMain(a, W(0x20), (void *)ws, 3, 0x29, 9, 0x440);
        WORDSET_Delete((struct WordSet *)ws);
    }
    if (k == 0) {
        if (POKE_TOOL_GetPartyValue(*(void **)s, 0xad, 0) == 1) {
            v = POKE_TOOL_GetPartyValue(*(void **)s, 0x6e, 0);
            if (v == 0) {
                POKELIST_PrintTextMain(a, W(0x20), (u16)7, 0x69, 9, 0x14c0);
            } else if (v == 1) {
                POKELIST_PrintTextMain(a, W(0x20), (u16)8, 0x69, 9, 0xc80);
            }
        }
    }
    if (f == 0) {
        if ((POKE_TOOL_GetStatusCondition(*(void **)s) == 0 && *(u16 *)(s + 6) != 0) || W(0x1c) != 8) {
            ws2 = (u32)WORDSET_CreateDefault(*(u16 *)a);
            WORDSET_SetSlotNumber((struct WordSet *)ws2, 0, POKE_TOOL_CalcLevel(*(void **)s), 3, 0, 1);
            if (k == 0) {
                POKELIST_PrintExpandedTextSub(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(a, W(0x20), (void *)ws2, 2, 9, 0x23, 0x440);
            }
            WORDSET_Delete((struct WordSet *)ws2);
            CLACT_SetActorDrawEnable((struct Obj *)W(0x40), 0);
        } else {
            if (*(u16 *)(s + 6) == 0) {
                CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 6);
            } else {
                switch (POKE_TOOL_GetStatusCondition(*(void **)s)) {
                case 1: CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 1); break;
                case 2: CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 3); break;
                case 3: CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 2); break;
                case 4: CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 5); break;
                case 5: CLACT_SetActorAnimSeq((struct Obj *)W(0x40), 4); break;
                }
            }
            CLACT_SetActorDrawEnable((struct Obj *)W(0x40), 1);
        }
    }
    m = W(0x1c);
    if (m != 8) {
        if (m == 6) {
            m = 0x81;
        } else if (m == 7) {
            m = 0x82;
        } else {
            m = m + 0x83;
        }
        POKELIST_PrintTextMain(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
        CLACT_SetActorDrawEnable((struct Obj *)W(0x38), 0);
    } else if (f == 1) {
        switch (POKELIST_GetMoveLearnStatus(a, *(void **)s, s[4])) {
        case 0:
        case 1: code = 0x89; break;
        case 2: code = 0x8a; break;
        case 3: code = 0x8b; break;
        }
        POKELIST_PrintTextMain(a, W(0x20), (u16)code, 0x1d, 0x1f, 0x440);
        CLACT_SetActorDrawEnable((struct Obj *)W(0x38), 0);
    } else {
        obj = *(u8 **)(a + 0x280);
        if (*(int *)(obj + 0x34) == 0x10) {
            v = POKELIST_CheckEvolution(a, *(void **)s, *(u16 *)(obj + 0x44));
            m = 0x8d;
            if (v != 0) {
                m = 0x8c;
            }
            POKELIST_PrintTextMain(a, W(0x20), (u16)m, 0x2e, 0x1f, 0x440);
            CLACT_SetActorDrawEnable((struct Obj *)W(0x38), 0);
        } else {
            ws2 = (u32)WORDSET_CreateDefault(*(u16 *)a);
            WORDSET_SetSlotNumber((struct WordSet *)ws2, 0, POKE_TOOL_GetPartyValue(*(void **)s, 0xa1, 0), 3, 0, 1);
            if (k == 0) {
                POKELIST_PrintExpandedTextSub(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(a, W(0x20), (void *)ws2, 4, 0x5b, 0x23, 0x440);
            }
            WORDSET_Delete((struct WordSet *)ws2);
            ws3 = (u32)WORDSET_CreateDefault(*(u16 *)a);
            WORDSET_SetSlotNumber((struct WordSet *)ws3, 0, *(u16 *)(s + 6), 3, 1, 1);
            if (k == 0) {
                POKELIST_PrintExpandedTextSub(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            } else {
                POKELIST_PrintExpandedTextSubDirect(a, W(0x20), (void *)ws3, 5, 0x39, 0x23, 0x440);
            }
            WORDSET_Delete((struct WordSet *)ws3);
            if (k == 0) {
                POKELIST_PrintTextSub(a, W(0x20), 6, 0x52, 0x23, 0x440);
            } else {
                POKELIST_PrintTextSubDirect(a, W(0x20), 6, 0x52, 0x23, 0x440);
            }
        }
    }
    r5 = POKE_TOOL_GetPartyValue(*(void **)s, 6, 0);
    if (r5 != 0) {
        CLACT_SetActorDrawEnable((struct Obj *)W(0x3c), 1);
        if (FILE_UTIL_IsMailItem(r5) == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)W(0x3c), 1);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)W(0x3c), 0);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)W(0x3c), 0);
    }
    r6 = PLIST_PLATE_GetHpBarColor((u32)s);
    r = 1;
    if (r6 == 3) {
        r = 0;
    } else if (POKE_TOOL_GetStatusCondition(*(void **)s) != 0) {
        r = 5;
    } else if (r6 == 2) {
        r = 4;
    } else if (r6 == 1) {
        r = 3;
    } else if (r6 == 0) {
        r = 2;
    }
    CLACT_SetActorAnimSeq((struct Obj *)W(0x30), r);
    W(0x18) = 1;
}
