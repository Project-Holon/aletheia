/*
 * function: SCRCMD_SetPartnerWords
 * address:  0x021CFDBC
 * packet:   pkt_ov021_021CFDBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   func_0200973C  0x0200973C  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   BMP_OAM_GetRecordValue  0x02025B64  thumb
 *   func_02008570  0x02008570  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   func_02009634  0x02009634  thumb
 *   WORDSET_Callback  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   WORDSET_SetSlotFromMsg2B  0x0201F198  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub0200852CObj;
struct Sub02009470Ent;
struct Sub02009470Obj;
struct WordSet;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
struct WordSet;
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern u8 BMP_OAM_GetRecordValue(u32 v);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern void WORDSET_SetSlotFromMsg2B(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

void SCRCMD_SetPartnerWords(void *ws, u32 h, u32 x)
{
    u32 g, e, v;
    u8 k;

    g = (u32)func_02009470(GAME_DATA_GetSaveControl((struct Big *)h));
    k = *((u8 *)GAME_DATA_GetSaveSyncBlock(h));
    e = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    WORDSET_SetSlotFromMsgE7(ws, 0, k);
    if (BMP_OAM_GetRecordValue(k)) {
        WORDSET_DeleteMsgdataF094(ws, 1, k, func_02008570((const struct Sub0200852CObj *)e));
    }
    WORDSET_SetSlotMyStatus(ws, 3, GAME_DATA_GetMyStatus((void *)h));
    WORDSET_Callback(ws, 5, func_02009634((const struct Sub02009470Obj *)g, x, 0));
    WORDSET_SetSlotFromMsg2B(ws, 6, func_02009628((const struct Sub02009470Obj *)g));
    WORDSET_SetSlotMyStatus(ws, 7, (void *)e);
    v = func_02009634((const struct Sub02009470Obj *)g, x, 3);
    if (v == 0) {
        v = 1;
    }
    WORDSET_SetSlotNumber(ws, 8, v, 3, 0, 1);
    WORDSET_Callback(ws, 9, func_02009634((const struct Sub02009470Obj *)g, x, 1));
    k = func_02009634((const struct Sub02009470Obj *)g, x, 2);
    WORDSET_SetSlotFromMsg2B(ws, 10, k);
}
