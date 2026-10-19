/*
 * function: GAME_BEACON_BuildMyInfo
 * address:  0x02026D88
 * packet:   pkt_02026D88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The own-beacon builder: fills a BeaconRec from the player profile, the
 * save blocks and the DS owner info.  Layout it proves beyond the family
 * header: word +0 is four BYTES (+0 = 0xff, +1/+2 from 0x0200856C and
 * 0x02008570, +3 split 7:1 as u8 bitfields -- strb/ldrb, not word RMW);
 * word +0xC is 6:3:3:4:10:6 (bits 0..5 = 0x15, 6..8 from 0x02008554,
 * 9..11 from 0x0200C224, 12..15 the owner's favoriteColor, then the
 * trainer and top fields); +0x12 is seven halfwords filled like +0x20;
 * +0x50 takes ten bytes via MI_CpuCopy8; the scratch at sp+0x14 is the
 * 0x54-byte OSOwnerInfo.  Levers that mattered: stack order (save, tbl,
 * bag declared in that order) and func_02008550 answering a word that is
 * narrowed with an explicit (u8) before the 1-bit store.
 *
 * symbols:
 *   GAME_DATA_GetMyStatus    0x02012944  thumb
 *   GAME_DATA_GetSaveControl    0x02012EBC  thumb
 *   MISC_GetBlock    0x0200C0F0  thumb
 *   func_0200E6E8    0x0200E6E8  thumb
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   GAME_DATA_GetMyPlayerWork    0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId    0x02012AC8  thumb
 *   ZONEDATA_IsUnionRoom    0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair    0x02013CE0  thumb
 *   GAME_DATA_GetSpecialLocation    0x02012894  thumb
 *   SYMBOL_MAP_ResolveZoneId    0x02166C7C  thumb
 *   func_02008534    0x02008534  thumb
 *   func_02008550    0x02008550  thumb
 *   func_02008554    0x02008554  thumb
 *   func_0200856C    0x0200856C  thumb
 *   func_02008570    0x02008570  thumb
 *   MISC_GetResearchRank    0x0200C224  thumb
 *   MISC_GetGreetCount    0x0200C1C4  thumb
 *   MISC_GetThanksCount    0x0200C1DC  thumb
 *   GAME_DATA_GetPlayTime    0x02012FCC  thumb
 *   func_0200864C    0x0200864C  thumb
 *   func_02008650    0x02008650  thumb
 *   SYMBOL_SAVE_GetBitBlock    0x0200E394  thumb
 *   SYMBOL_SAVE_GetQuestionnaireBits    0x0200E3A0  thumb
 *   MI_CpuCopy8      0x02082D44  arm
 *   GREETING_SAVEDATA_GetSentence    0x0200E6FC  thumb
 *   GAME_BEACON_SetMyPms    0x020274B4  thumb
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   func_020084F4    0x020084F4  thumb
 *   MISC_GetGreetMessage    0x0200C1F4  thumb
 *   GAME_BEACON_ResetDetails    0x0202744C  thumb
 */
#include "../include/Obj15760.h"
typedef signed short   s16;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  language;
    u8  favoriteColor;
    u8  month;
    u8  day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

struct Src { u16 a; u16 b; u16 c; u16 d; };

struct Rec {
    u8  b00;
    u8  b01;
    u8  b02;
    u8  b03lo : 7;
    u8  b03hi : 1;

    u32 id    : 17;
    u32 mode  : 10;
    u32 f04hi : 5;

    u32 peer  : 17;
    u32 seq   : 5;
    u32 f08hi : 10;

    u32 c0    : 6;
    u32 c6    : 3;
    u32 c9    : 3;
    u32 c12   : 4;
    u32 trainer : 10;
    u32 f0chi : 6;

    u16 f10;
    u16 f12[7];
    u16 vec[8];
    u16 f30;
    u8  pad32[0x50 - 0x32];
    u8  f50[10];
};

struct Big;
struct BigObj;
struct Blk34;
struct PlayTime;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_GetBlock(void *p);
extern void *func_0200E6E8(u32 a);
extern void  OS_GetOwnerInfo(OSOwnerInfo *info);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
struct Rec0200E6FC;
extern u32 ZONEDATA_IsUnionRoom(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u32 id);
extern struct Rec1C *GAME_DATA_GetSpecialLocation(const struct BigObj *p);
extern u32   SYMBOL_MAP_ResolveZoneId(void *sys, u16 m);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 MISC_GetResearchRank(struct Blk34 *p);
extern u32 MISC_GetGreetCount(struct Blk34 *p);
extern u32 MISC_GetThanksCount(struct Blk34 *p);
extern int GAME_DATA_GetPlayTime(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *SYMBOL_SAVE_GetBitBlock(void *p);
extern void *SYMBOL_SAVE_GetQuestionnaireBits(void *p);
extern void  MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void GREETING_SAVEDATA_GetSentence(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void GAME_BEACON_SetMyPms(u32 a0);
extern u16   STRBUF_GetEosChar(void);
extern u16  *func_020084F4(void *p);
extern u16 *MISC_GetGreetMessage(struct Blk34 *p);
extern void GAME_BEACON_ResetDetails(void *dst);

void GAME_BEACON_BuildMyInfo(struct Rec *o, void *sys)
{
    void *save;
    void *tbl;
    void *bag;
    void *prof;
    void *st;
    struct Src src;
    OSOwnerInfo info;
    u16 *q;
    u16 v;
    int i;

    prof = GAME_DATA_GetMyStatus(sys);
    save = GAME_DATA_GetSaveControl(sys);
    tbl = MISC_GetBlock(save);
    bag = func_0200E6E8((u32)save);
    OS_GetOwnerInfo(&info);

    o->b00 = 0xff;
    o->mode = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(sys));
    if ((int)ZONEDATA_IsUnionRoom((u16)o->mode) == 1 || (int)ZONEDATA_IsZone96Pair((u16)o->mode) == 1) {
        o->mode = ((struct Obj15760 *)((u8 *)GAME_DATA_GetSpecialLocation(sys)))->f4;
    }
    o->f08hi = SYMBOL_MAP_ResolveZoneId(sys, o->mode);
    o->b03lo = 0x30;
    o->f10 = func_02008534(prof);
    o->c12 = info.favoriteColor;
    o->b03hi = (u8)(u32)func_02008550(prof);
    if (o->b03hi == 0) {
        o->c6 = func_02008554(prof);
    } else {
        o->c6 = func_02008554(prof) - 8;
    }
    o->c0 = 0x15;
    o->f04hi = 2;
    o->b01 = func_0200856C(prof);
    o->b02 = func_02008570(prof);
    o->c9 = MISC_GetResearchRank(tbl);
    o->peer = MISC_GetGreetCount(tbl);
    o->id = MISC_GetThanksCount(tbl);
    st = (void *)GAME_DATA_GetPlayTime((int)sys);
    o->trainer = func_0200864C(st);
    o->f0chi = func_02008650(st);
    MI_CpuCopy8(SYMBOL_SAVE_GetQuestionnaireBits(SYMBOL_SAVE_GetBitBlock(save)), o->f50, 10);
    GREETING_SAVEDATA_GetSentence(bag, 0, (struct Rec0200E6FC *)(&src));
    GAME_BEACON_SetMyPms((u32)(&src));
    v = STRBUF_GetEosChar();
    q = func_020084F4(prof);
    for (i = 0; i < 7; i++) {
        o->f12[i] = q[i];
        if (v == q[i])
            break;
    }
    q = MISC_GetGreetMessage(tbl);
    for (i = 0; i < 8; i++) {
        o->vec[i] = q[i];
        if (v == q[i])
            break;
    }
    GAME_BEACON_ResetDetails(o);
    o->f30 = 0;
}
