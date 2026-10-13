/*
 * function: GAME_BEACON_ACCESSOR_RegisterRecordWords
 * address:  0x02165FCC
 * packet:   pkt_ov010_02165FCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Print a record into a text window: its name into slot 0, then the
 * type-specific value (number, string or item) into slots 1 and 2.
 *
 * symbols:
 *   func_0201F31C  0x0201F31C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F104  0x0201F104  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0201F1E0  0x0201F1E0  thumb
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetFreeText  0x02165D8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionNo  0x02165E24  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionMonsNo  0x02165E34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionItemNo  0x02165E78  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCountValue  0x02165E8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionMonsNo  0x02165E9C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionItemNo  0x02165EAC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetNickname  0x02165ECC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionTrainerNo  0x02165F30  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPresetEventValue  0x02165F64  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionSpecialValue  0x02165F74  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionWordValue  0x02165F84  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionByteValue  0x02165F94  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionHalfwordValue  0x02165FA4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCheckIndex  0x02165FB4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Rec Rec;

typedef signed int     s32;
struct U16Vec;
struct WordSet;
extern void func_0201F31C(struct WordSet *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
struct WordSet;
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F104(struct WordSet *p, u32 i, u32 a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void func_0201F1E0(struct WordSet *p, u32 i, u32 v);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct Rec *r, void *buf);
extern u8 GAME_BEACON_ACCESSOR_GetSex(struct Rec *r);
extern int GAME_BEACON_ACCESSOR_GetFreeText(int a0, int a1);
extern u16 GAME_BEACON_ACCESSOR_GetActionNo(Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetActionItemNo(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetActionCountValue(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetDistributionMonsNo(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(struct Rec *r);
extern void GAME_BEACON_ACCESSOR_GetNickname(struct Rec *r, void *buf);
extern u16 GAME_BEACON_ACCESSOR_GetActionTrainerNo(struct Rec *r);
extern u32 GAME_BEACON_ACCESSOR_GetPresetEventValue(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetActionSpecialValue(struct Rec *r);
extern u32 GAME_BEACON_ACCESSOR_GetActionWordValue(struct Rec *r);
extern u8 GAME_BEACON_ACCESSOR_GetActionByteValue(struct Rec *r);
extern u16 GAME_BEACON_ACCESSOR_GetActionHalfwordValue(struct Rec *r);
extern u8 GAME_BEACON_ACCESSOR_GetActionCheckIndex(u16 type);

void GAME_BEACON_ACCESSOR_RegisterRecordWords(Rec *r, void *win, u32 heap)
{
    void *str;
    u8 kind;
    u32 v;

    func_0201F31C(win);
    str = STRBUF_Create(0x21, heap);
    if (str == 0)
        return;
    GAME_BEACON_ACCESSOR_GetPlayerName(r, str);
    func_0201EE0C(win, 0, str, 0, 1, 2);
    kind = GAME_BEACON_ACCESSOR_GetActionCheckIndex(GAME_BEACON_ACCESSOR_GetActionNo(r));
    switch (kind) {
    case 1:
        v = GAME_BEACON_ACCESSOR_GetActionTrainerNo(r);
        func_0201F104(win, 1, v);
        func_0201F134(win, 2, v);
        break;
    case 2:
    case 4:
        func_0201EE60(win, 1, GAME_BEACON_ACCESSOR_GetActionMonsNo(r));
        if (kind == 2)
            break;
    case 3:
        GAME_BEACON_ACCESSOR_GetNickname(r, str);
        func_0201EE0C(win, 2, str, 0, 1, 2);
        break;
    case 5:
        func_0201EF4C(win, 1, GAME_BEACON_ACCESSOR_GetActionItemNo(r));
        break;
    case 6:
        func_0201EFA4(win, 1, GAME_BEACON_ACCESSOR_GetActionSpecialValue(r), 3, 0, 1);
        break;
    case 7:
        func_0201EFA4(win, 1, GAME_BEACON_ACCESSOR_GetPresetEventValue(r), 3, 0, 1);
        break;
    case 8:
        func_0201EE60(win, 1, GAME_BEACON_ACCESSOR_GetDistributionMonsNo(r));
        break;
    case 9:
        func_0201EF40(win, 1, GAME_BEACON_ACCESSOR_GetDistributionItemNo(r));
        break;
    case 10:
        func_0201EF34(win, 1, GAME_BEACON_ACCESSOR_GetActionCountValue(r));
        break;
    case 11:
        func_0201EFA4(win, 1, GAME_BEACON_ACCESSOR_GetActionWordValue(r), 1, 0, 1);
        break;
    case 12:
        func_0201F1E0(win, 1, GAME_BEACON_ACCESSOR_GetActionByteValue(r));
        break;
    case 13:
        func_0201F184(win, 1, GAME_BEACON_ACCESSOR_GetActionHalfwordValue(r));
        break;
    case 14:
        GAME_BEACON_ACCESSOR_GetFreeText((int)r, (int)str);
        func_0201EE0C(win, 1, str, GAME_BEACON_ACCESSOR_GetSex(r), 1, 2);
        break;
    case 15:
        break;
    }
    STRBUF_Delete(str);
}
