/*
 * function: INTRUDE_COMM_VIEW_OnScanResult
 * address: 0x021D5110
 * packet: pkt_ov122_021D5110
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetScanResult 0x0203CF10 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   INTRUDE_COMM_VIEW_SetFoundPeerMac 0x021D50B4 thumb ov122
 *   INTRUDE_COMM_VIEW_ClearFoundPeerMac 0x021D50DC thumb ov122
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb  arm9
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb  arm9
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StopRingtone  0x02028A70  thumb  arm9
 */
#include "../include/Obj00208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern int func_020107FC(void *);
extern u32 GFL_NET_GetScanResult(u32 a);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct SoundSys;
struct Strbuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_02041B6C(u32 bit);
extern void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p, u32 n);
extern void STRBUF_Delete(struct U16Vec *vec);
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void FIELD_SOUND_SYSTEM_StopRingtone(struct SoundSys *sys);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *);
void INTRUDE_COMM_VIEW_OnScanResult(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC((void *)GAME_DATA_GetWifiList(((struct Obj00208 *)p)->f350));
    if (index != -1) {
        record = (void *)GFL_NET_GetScanResult(index);
        text = STRBUF_Create(200, ((struct Obj00208 *)p)->fC);
        STRBUF_SetStringN(text, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
        if (!CLACT_GetActorDrawEnable(((struct Obj00208 *)p)->f3A0)) {
            STRBUF_SetStringN(((struct Obj00208 *)p)->f58, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
            BMP_Clear(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0, 0, ((struct Obj00208 *)p)->f58, ((struct Obj00208 *)p)->f4C, 0x39e3);
            BMP_WIN_TransferChars(((struct Obj00208 *)p)->f3C);
            BMP_WIN_MakeScreen(((struct Obj00208 *)p)->f3C);
            CLACT_SetActorDrawEnable(((struct Obj00208 *)p)->f3A0, 1);
            func_02041B6C(5);
            INTRUDE_COMM_VIEW_SetFoundPeerMac(p, index);
        }
        STRBUF_Delete(text);
        FIELD_SOUND_SYSTEM_StartRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(((struct Obj00208 *)p)->f350));
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 15)
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f39C, 16);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 11) {
            CLACT_SetActorAutoAnim(((struct Obj00208 *)p)->f394, 1);
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f394, 19);
        }
    } else {
        FIELD_SOUND_SYSTEM_StopRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(((struct Obj00208 *)p)->f350));
        CLACT_SetActorDrawEnable(((struct Obj00208 *)p)->f3A0, 0);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0);
        BMP_WIN_TransferChars(((struct Obj00208 *)p)->f3C);
        INTRUDE_COMM_VIEW_ClearFoundPeerMac(p);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 19) {
            CLACT_SetActorAutoAnim(((struct Obj00208 *)p)->f394, 0);
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f394, 11);
        }
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 16)
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f39C, 15);
    }
}
