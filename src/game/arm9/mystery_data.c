/*
 * file:     mystery_data.c
 * unit:     yes
 * function: sub_02009A34, sub_02009A54, sub_02009A74, sub_02009AE4, sub_02009B3C, sub_02009B80, sub_02009BB8, sub_02009C24, sub_02009CA8, func_02009CB0, func_02009CC0, sub_02009CE4, sub_02009D08, sub_02009D1C, sub_02009D50, sub_02009D9C, sub_02009DA4, sub_02009DB8, sub_02009DE8, sub_02009E40, sub_02009E54, sub_02009E74, sub_02009E8C, sub_02009EA8, sub_02009EB0, func_02009EC8, func_02009ED4, func_02009EDC, func_02009F0C, func_02009F1C, func_02009F50, func_02009F7C, func_02009FD4, func_0200A000, func_0200A034, func_0200A094, func_0200A0C8, func_0200A0E4, func_0200A104, func_0200A13C, func_0200A170, func_0200A1A8, func_0200A1E4, func_0200A21C, func_0200A254, func_0200A2B8, func_0200A2D8, func_0200A300, func_0200A338, func_0200A348, func_0200A350, sub_0200A358, func_0200A3D0, func_0200A3FC, func_0200A400, func_0200A418, func_0200A41C, func_0200A43C, func_0200A480, func_0200A49C, func_0200A4B8, func_0200A50C, func_0200A53C, func_0200A544, func_0200A5F8, func_0200A604, func_0200A628, func_0200A630, func_0200A640, func_0200A644, func_0200A680, func_0200A6BC, func_0200A6F8, func_0200A714, func_0200A73C, func_0200A750, func_0200A75C, func_0200A768, func_0200A780, func_0200A788, func_0200A7A0, func_0200A7AC, func_0200A7B8, func_0200A7C0, func_0200A7C8, func_0200A7D4, func_0200A7E0, func_0200A7EC, func_0200A7F8, func_0200A800, func_0200A81C, func_0200A828, func_0200A834, func_0200A840, func_0200A848, func_0200A864, func_0200A870, func_0200A884, func_0200A890, func_0200A898, func_0200A8A0, func_0200A8AC, func_0200A8C8, func_0200A8D0, func_0200A8E4, func_0200A8F8, func_0200A908, func_0200A930, sub_0200A940, sub_0200A9A4, sub_0200A9D4, func_0200AA00, sub_0200AA68, sub_0200AB04, sub_0200AB24, func_0200AB2C, func_0200AB50, func_0200ABE0, sub_0200AC14, func_0200ACD0, sub_0200AD00, func_0200AD6C, func_0200AD78, func_0200AD7C, func_0200AD8C, func_0200AD94, func_0200AD9C, func_0200ADB4, func_0200ADB8, func_0200ADD0, func_0200ADD8, func_0200ADE0, func_0200ADE8, func_0200ADF0, func_0200AE08, func_0200AE14, func_0200AE18, func_0200AE3C, func_0200AE54, func_0200AEE8, func_0200AFD4, func_0200B040, func_0200B074, func_0200B078, func_0200B110, func_0200B1A8, func_0200B1C4, func_0200B1D4, func_0200B1E0, func_0200B1F8, func_0200B204, func_0200B214, func_0200B254
 * address:  0x02009A34
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203F4E4  0x0203F4E4  arm
 *   DWC_CreateExchangeToken 0x020599BC  arm
 *   DWC_CheckValidConsole  0x02059760  arm
 *   DWC_CheckHasProfile    0x020597C8  arm
 *   DWC_GetGsProfileId     0x020598EC  arm
 *   MI_CpuMove   0x02083194  arm
 *   func_020071CC  0x020071CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021DFDC0    0x021DFDC0  thumb
 *   func_021DFE00    0x021DFE00  thumb
 *   g_020A71A4      0x020A71A4  data
 *   sub_020071EC   0x020071EC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEAC  0x021DFEAC  thumb  ov228
 *   ov_id_E4       0x000000E4  data
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   func_02161D98    0x02161D98  thumb  ov010
 *   func_02161EEC    0x02161EEC  thumb  ov010
 *   func_02161F00    0x02161F00  thumb  ov010
 *   sub_020056EC   0x020056EC  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   _u32_div_f     0x0209C2B0  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_020173EC 0x020173EC thumb
 *   func_0200ADF0_File  0x020A71B4  data
 */

struct SaveControl;
struct GameData;
struct MsgBank;
struct U16Vec;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* RTC calendar date (the RTCDate of config.c). */
struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

/* Trainer status record, 0x20 bytes (layout of config.c). */
struct MyStatus {
    u16 name[8];
    u32 id;
    u32 profile_id;
    u8  language;
    u8  version;
    u8  gender;
    u8  avatar_id;
    u8  outfit;
    u8  outfit_variant;
};

/*
 * Save block 0x1E, the Wi-Fi friend list (wifilist.c).  Two parallel arrays
 * of 32 slots: the DWC friend data and the per-friend record.
 */
struct DWCFriendData {
    u8 data[0xC];
};

struct WifiFriendInfo {
    u8  nameData[0x1C];
    u32 trainerId;
    u32 profileId;
    u16 battleWins;
    u16 battleLosses;
    u16 tradeCount;
    u16 lastYear;
    u8  lastMonth;
    u8  lastDay;
    u8  language;
    u8  gender : 2;
    u8  statusFlags : 6;
};

struct WifiList {
    u8 userData[0x40];                    /* DWC user data, at offset 0 */
    struct DWCFriendData friendData[0x20];
    struct WifiFriendInfo friendInfo[32];
    u8 reserved[4];
};

/*
 * Save block 0x1F, the trade partner history: the last 100 trade partners,
 * most recent first, and a trade counter that saturates at 99999.
 */
struct TradeHistory {
    struct MyStatus partners[100];
    u8  reserved[0xD0];
    u32 tradeCount;
};

/*
 * Mystery gift data (save block 0x22, 0xA94 bytes; 0x368 bytes when it is
 * read from the extra save of overlay 228): a 0x800-bit event flag table,
 * then 12 (or 3) gift cards of 0xCC bytes, then a 4-byte footer that holds
 * the checksum and the seed of the encryption key.
 */
struct MysteryCard {
    u8 body[0xB3];
    u8 giftType;                          /* 1..3 when the slot holds a card */
    u8 flags;                             /* bit 1: gift received */
    u8 tail[0x17];
};

/* Word view of one card: the slot copy needs a four-aligned type to be an
 * ldm/stm loop. */
struct MysteryCardImage {
    u32 words[0x33];
};

struct MysteryDataFooter {
    u16 checksum;
    u16 cryptSeed;
};

/* The 12-byte handle that func_0200A300 returns. */
struct MysteryData {
    u8   *buffer;
    u32   saveType;                       /* 1: main save block, 0: extra save */
    void *extraSave;                      /* overlay 228 work for saveType 0 */
};

/* A received gift packet: 0x2CE bytes of body and their CRC. */
struct MysteryGiftPacket {
    u8  body[0x2CE];
    u16 crc;
};

/*
 * Save block 0x2A, the musical save (0x2A4 bytes): a 100-entry prop
 * collection held as two bitmaps (owned, new), outfit and program tables,
 * and counters.
 */
struct MusicalOutfit {
    u8 pokeSlot;                          /* 10: none */
    u8 props[5];
};

struct MusicalProgram {
    u8 state;                             /* 4: initial */
    u8 data[3];
};

struct MusicalSave {
    u32 showcaseMonsNo : 16;
    u32 shotState : 5;
    u32 showcaseFlags : 11;
    u8  showcase[0x1AC];
    struct MusicalOutfit outfits[8];
    struct MusicalProgram programs[10];
    u8  stageData[0x4A];
    u16 showCount;
    u16 topRankCount;
    u16 fanPoints;
    u8  ownedProps[0x20];
    u8  newProps[0x20];
    u8  equippedProps[4];
    u8  selectedProgram;
    u8  scriptSetting;
    u8  hasDistData;
    u8  fittingSetting;
    u8  reserved[4];
};

/* Save block 0x2B, the musical shot (0x2DC bytes). */
struct MusicalShotPhoto {
    u8 data[0x1E8];
};

struct MusicalShot {
    struct MusicalShotPhoto photo;
    u16 title[10];
    u8  extraData[0xE0];
};

/*
 * Save block 0x2C, the infrared compatibility ranking (0x34C bytes): 30
 * entries sorted by score, then the slot of the last insert.
 */
struct IrcRankEntry {
    u16 name[8];
    u32 score : 7;
    u32 meetCount : 10;
    u32 gender : 1;
    u32 language : 4;
    u32 version : 4;
    u32 padding : 5;
    u32 isValid : 1;
    u32 trainerId;
    u16 profileWord;
    u8  profileByte;
    u8  profileBits : 6;
    u8  profileFlag : 1;
    u8  isNew : 1;
};

struct IrcRankSave {
    struct IrcRankEntry entries[30];
    u32 lastSlot : 8;
    u32 reserved : 24;
};

/* Save block 0x2E, the GTS deposit data (0xF8 bytes). */
struct WorldTradeData {
    u8  pokemon[0xDC];
    u8  depositInfo[0x10];
    u16 isDeposited;
    u16 returnBox;
    u32 lastTradeId;
    u32 lastSearchId;
};

/*
 * regulation.c: a 0xBC-byte battle rule set.  The get and set pair takes a
 * rule id 0..22; ids 9, 10 and 14 are the three bitmaps.
 */
struct Regulation {
    u8  cupNo;
    u8  ruleNo;
    u8  numLo;
    u8  numHi;
    u8  level;
    u8  levelRange;
    u16 levelTotal;
    u8  bothPoke;
    u8  bothItem;
    u8  vetoPokeBit[0x52];
    u8  vetoItemBit[0x4C];
    u16 mustPoke;
    u8  mustPokeForm;
    u8  shooter;
    u8  vetoShooterBit[7];
    u8  timeVs;
    u8  timeCommand;
    u8  nickname;
    u8  cameraMode;
    u8  unused;
    u8  showPoke;
    u8  showPokeTime;
    u8  battleType;
    u8  battleCount;
};

/* Shooter settings that REGULATION_GetShooterSettings fills. */
struct ShooterSettings {
    u8 vetoItemBit[7];
    u8 isEnabled;
};

/* A 0x160-byte regulation card: the rule set plus card data and a CRC. */
struct RegulationCard {
    struct Regulation rule;
    s32 cupId;
    u8  cupName[0x92];
    s16 romVersion;
    s8  startYear;
    s8  startMonth;
    s8  startDay;
    s8  endYear;
    s8  endMonth;
    s8  endDay;
    s8  status;
    s8  bgm;
    u8  sameMatch;
    u8  cardType;
    u16 crc;
};

/* The party a regulation card is entered with (0x1E bytes). */
struct RegulationParty {
    u16 monsNo[6];
    u8  formNo[6];
    u8  hasItemBits;
    u8  femaleBits;
    u8  reserved[10];
};

/* Save block 0x2F, the battle competition save (0x2FC bytes). */
struct BattleCompetitionSave {
    struct RegulationCard cards[2];
    struct RegulationParty parties[2];
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuMove(const void *src, void *dest, u32 size);
extern void MIi_CpuClearFast(u32 data, void *dest, u32 size);
extern void func_0203F4E4(struct RTCDate *date);
extern s32  func_0203F540(struct RTCDate *date);
extern void DWC_CreateExchangeToken(void *userData, void *friendData);
extern int  DWC_GetGsProfileId(void *userData, void *friendData);
extern int  DWC_CheckValidConsole(void *userData);
extern int  DWC_CheckHasProfile(void *userData);
extern void *func_020071CC(struct SaveControl *save, u32 blockId);
extern u8   sub_020071EC(const struct SaveControl *save);
extern u32  sub_02008530(const struct MyStatus *status);
extern u8   sub_02008550(const struct MyStatus *status);
extern const void *sub_020084F4(const void *status);
extern int  sub_02008468(void);
extern u8   sub_02008554(const struct MyStatus *status);
extern void sub_02008558(struct MyStatus *status, u8 value);
extern u8   sub_0200855C(const struct MyStatus *status);
extern u16  func_0203F1FC(const void *data, u32 size);
extern u32  func_0203F2FC(const void *data, u32 size);
extern void func_0203F328(void *data, u32 size, u32 key);
extern void func_0203F37C(void *data, u32 size, u32 key);
extern void func_021DFDC0(void *extraSave);
extern int  func_02012DAC(struct GameData *gameData);
extern int  func_021DFE00(void *extraSave);
extern int  func_02012DD0(struct GameData *gameData);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32  func_020307B0(void *p);
extern int  func_02034AC4(int overlayId);
extern void func_02034A5C(int overlayId);
extern void *func_021DFC20(u32 heapId);
extern u8   func_021DFE90(u8 *extraSave);
extern void *func_021DFEAC(u8 *extraSave);
extern void func_021DFDB8(void *extraSave);
extern void func_02161D98(char *photo);
extern void func_02161EEC(u16 *title);
extern void func_02161F00(void *extraData);
extern u32  sub_020056EC(u32 range);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32  func_020173EC(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32  func_02045C04(struct MsgBank *bank);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct WifiList *sub_02009860(struct WifiList *list);
u32 sub_02009864(const struct WifiList *list, u32 i, u32 field);
struct WifiFriendInfo *sub_020099D4(struct WifiList *list, int i);
int sub_02009A1C(struct WifiList *list, u32 i);
u32 sub_02009A34(struct WifiList *list);
u32 sub_02009A54(struct WifiList *list);
void sub_02009A74(struct WifiList *list, u32 slot);
void sub_02009AE4(struct WifiList *list, u32 dest, u32 src);
void sub_02009B3C(struct WifiList *list);
void sub_02009B80(struct WifiList *list, int slot);
void sub_02009BB8(struct WifiList *list, int slot, int wins, int losses, int trades);
void sub_02009C24(struct WifiList *list, int src, int dest);
void sub_02009CA8(void *userData, void *friendData);
void func_02009CB0(struct WifiList *list, void *token);
int func_02009CC0(struct WifiList *list);
u32 sub_02009CE4(struct WifiList *list);
struct WifiList *sub_02009D08(struct SaveControl *save);
int sub_02009D1C(struct WifiList *list, struct MyStatus *status, u32 *outSlot);
int sub_02009D50(struct WifiList *list, const void *name, u32 id, u32 outfitVariant, u32 *outSlot);
u32 sub_02009D9C(void);
void sub_02009DA4(struct TradeHistory *history);
int sub_02009DB8(struct TradeHistory *history, u32 id);
void sub_02009DE8(struct TradeHistory *history, struct MyStatus *status);
u32 sub_02009E40(struct TradeHistory *history, u32 slot);
struct MyStatus *sub_02009E54(struct TradeHistory *history, u32 slot);
u32 sub_02009E74(struct TradeHistory *history, u32 id);
int sub_02009E8C(struct TradeHistory *history);
u32 sub_02009EA8(const struct TradeHistory *history);
void sub_02009EB0(struct TradeHistory *history);
struct TradeHistory *func_02009EC8(struct SaveControl *save);
u32 func_02009ED4(void);
void func_02009EDC(u8 *buffer);
u32 func_02009F0C(u32 giftType);
int func_02009F1C(struct MysteryData *data);
int func_02009F50(struct MysteryData *data, u32 slot);
void func_02009F7C(struct MysteryData *data, u32 slot);
struct MysteryCard *func_02009FD4(struct MysteryData *data, u32 slot);
int func_0200A000(struct MysteryData *data, u32 slot, void *out);
int func_0200A034(struct MysteryData *data, const void *card);
void func_0200A094(struct MysteryData *data, u32 slot);
u32 func_0200A0C8(struct MysteryData *data);
u32 func_0200A0E4(struct MysteryData *data, u32 slot);
int func_0200A104(struct MysteryData *data, u32 slot);
void func_0200A13C(struct MysteryData *data, u32 slot);
int func_0200A170(struct MysteryData *data);
int func_0200A1A8(struct MysteryData *data, u32 flag);
void func_0200A1E4(struct MysteryData *data, u32 flag);
int func_0200A21C(struct MysteryGiftPacket *packet);
void func_0200A254(struct MysteryData *data, u32 slotA, u32 slotB);
void func_0200A2B8(struct MysteryData *data, struct GameData *gameData);
int func_0200A2D8(struct MysteryData *data, struct GameData *gameData);
struct MysteryData *func_0200A300(struct SaveControl *save, int mode, u32 heapId);
void func_0200A338(struct MysteryData *data);
u32 func_0200A348(struct MysteryData *data);
int func_0200A350(struct MysteryData *data);
void sub_0200A358(struct MysteryData *data, struct SaveControl *save, int mode, int heapId);
void func_0200A3D0(struct MysteryData *data);
u32 func_0200A3FC(struct MysteryData *data);
u32 func_0200A400(struct MysteryData *data);
u8 *func_0200A418(struct MysteryData *data);
u8 *func_0200A41C(struct MysteryData *data);
struct MysteryCard *func_0200A43C(struct MysteryData *data, u32 slot);
void func_0200A480(struct MysteryData *data);
void func_0200A49C(struct MysteryData *data);
void func_0200A4B8(u8 *buffer, u32 saveType);
void func_0200A50C(u8 *buffer, u32 saveType);
u32 func_0200A53C(void);
void func_0200A544(struct MusicalSave *musical);
struct MusicalSave *func_0200A5F8(struct SaveControl *save);
void func_0200A604(struct MusicalSave *musical);
struct MusicalOutfit *func_0200A628(struct MusicalSave *musical);
u32 func_0200A630(struct MusicalSave *musical);
void func_0200A640(void);
u32 func_0200A644(struct MusicalSave *musical, u8 prop);
u32 func_0200A680(struct MusicalSave *musical, u8 prop);
void func_0200A6BC(struct MusicalSave *musical, u32 prop);
void func_0200A6F8(struct MusicalSave *musical);
u32 func_0200A714(struct MusicalSave *musical);
u32 func_0200A73C(struct MusicalSave *musical);
struct MusicalProgram *func_0200A750(struct MusicalSave *musical, u32 index);
u16 func_0200A75C(struct MusicalSave *musical);
void func_0200A768(struct MusicalSave *musical);
u16 func_0200A780(struct MusicalSave *musical);
void func_0200A788(struct MusicalSave *musical);
u8 func_0200A7A0(struct MusicalSave *musical, u32 index);
void func_0200A7AC(struct MusicalSave *musical, u32 index, u8 prop);
u8 func_0200A7B8(struct MusicalSave *musical);
void func_0200A7C0(struct MusicalSave *musical, u8 value);
u8 func_0200A7C8(struct MusicalSave *musical);
void func_0200A7D4(struct MusicalSave *musical, u8 value);
u8 func_0200A7E0(struct MusicalSave *musical);
void func_0200A7EC(struct MusicalSave *musical, u8 value);
u8 *func_0200A7F8(struct MusicalSave *musical);
void func_0200A800(struct MusicalSave *musical, s32 delta);
u16 func_0200A81C(struct MusicalSave *musical);
u32 func_0200A828(struct MusicalSave *musical);
void func_0200A834(struct MusicalSave *musical, u8 value);
u32 func_0200A840(void);
void func_0200A848(struct MusicalShot *shot);
struct MusicalShot *func_0200A864(struct SaveControl *save);
void func_0200A870(struct MusicalShotPhoto *dest, const struct MusicalShotPhoto *src);
void func_0200A884(const struct MusicalShotPhoto *src, struct MusicalShotPhoto *dest);
u16 *func_0200A890(struct MusicalShot *shot);
u8 *func_0200A898(struct MusicalShot *shot);
struct IrcRankSave *func_0200A8A0(struct SaveControl *save);
s32 func_0200A8AC(struct IrcRankSave *rank);
struct IrcRankEntry *func_0200A8C8(struct IrcRankSave *rank, u32 index);
u8 func_0200A8D0(struct IrcRankSave *rank, u32 index);
u16 func_0200A8E4(struct IrcRankSave *rank, u32 index);
u32 func_0200A8F8(struct IrcRankSave *rank, u32 index);
void func_0200A908(const struct IrcRankEntry *entries, u32 index, u16 *outWord, u8 *outByte, u8 *outBits, u8 *outFlag);
u8 func_0200A930(struct IrcRankSave *rank);
int sub_0200A940(struct IrcRankSave *rank, u32 month, u32 day, struct RTCDate *today);
int sub_0200A9A4(struct IrcRankEntry *entries, u32 trainerId);
int sub_0200A9D4(struct IrcRankEntry *entries, u32 trainerId);
u8 func_0200AA00(u32 month, u32 day, struct RTCDate *today);
u8 sub_0200AA68(struct IrcRankSave *rank, const void *name, u16 score, u8 gender,
                u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);
void sub_0200AB04(struct IrcRankEntry *entries);
int sub_0200AB24(void);
void func_0200AB2C(struct IrcRankSave *rank);
u8 func_0200AB50(struct IrcRankEntry *list, s32 count, struct IrcRankEntry *entry);
int func_0200ABE0(struct IrcRankEntry *list, int count, struct IrcRankEntry *entry);
void sub_0200AC14(struct IrcRankEntry *entry, const void *name, u32 score, u32 meetCount,
                  u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);
struct IrcRankEntry *func_0200ACD0(struct IrcRankEntry *list, int count, int trainerId);
void sub_0200AD00(struct IrcRankEntry *list, int total, struct IrcRankEntry *entry);
struct WorldTradeData *func_0200AD6C(struct SaveControl *save);
int func_0200AD78(void);
void func_0200AD7C(struct WorldTradeData *trade);
u16 func_0200AD8C(const struct WorldTradeData *trade);
void func_0200AD94(struct WorldTradeData *trade, u16 isDeposited);
void func_0200AD9C(struct WorldTradeData *trade, void *outPokemon);
void func_0200ADB4(void);
void func_0200ADB8(struct WorldTradeData *trade, const void *pokemon, u32 boxPos);
void func_0200ADD0(struct WorldTradeData *trade, u32 tradeId);
void func_0200ADD8(struct WorldTradeData *trade, u32 searchId);
u16 func_0200ADE0(struct WorldTradeData *trade);
u32 func_0200ADE8(void);
struct Regulation *func_0200ADF0(u32 heapId);
void func_0200AE08(const struct Regulation *src, struct Regulation *dest);
void func_0200AE14(void);
void func_0200AE18(struct Regulation *rule, void *dest);
void *func_0200AE3C(struct Regulation *rule, u32 heapId);
u32 func_0200AE54(struct Regulation *rule, u32 id);
void func_0200AEE8(struct Regulation *rule, u32 id, s32 value);
u32 func_0200AFD4(struct Regulation *rule, u32 id, s32 bit);
void func_0200B040(struct Regulation *rule, struct ShooterSettings *out);
u8 *func_0200B074(struct RegulationCard *card);
s32 func_0200B078(struct RegulationCard *card, u32 id);
void func_0200B110(struct RegulationCard *card, u32 id, s32 value);
u32 func_0200B1A8(struct RegulationCard *card);
u16 func_0200B1C4(struct RegulationCard *card);
struct RegulationCard *func_0200B1D4(struct RegulationCard *cards, u32 index);
void func_0200B1E0(struct RegulationCard *cards, u32 index, const struct RegulationCard *src);
void func_0200B1F8(struct RegulationParty *party);
struct RegulationParty *func_0200B204(struct BattleCompetitionSave *competition, u32 index);
s32 func_0200B214(struct RegulationParty *party, u32 id, u8 member);
void func_0200B254(struct RegulationParty *party, int id, u8 member, s32 value);
extern char g_020A71A4[];
extern u8   ov_id_E4[];
extern s16  tbl_020A1B38[];
extern const char func_0200ADF0_File[];


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009B3C, sub_02009B80, sub_02009BB8
 *
 * alias: wifilist.c's list maintenance.  The two parallel arrays of
 * src/matched/unit_02009860.c hold 32 slots each, an 0x0C-byte DWC friend
 * record at +0x40 and an 0x30-byte entry at +0x1C0, and every function here
 * moves both together.
 *
 * sub_02009B3C is the compaction pass and is the one worth reading.  It scans
 * the 32 slots keeping `j` at the first hole it has seen, and when it finds a
 * used slot after a hole it moves it down with sub_02009AE4 and then sets
 * `i = -1` so the `i++` restarts the scan from zero.  The compiler cross-jumps
 * the two assignments to `j`: the restart arm's `j = -1` and the hole arm's
 * `j = i` become one `adds r5, r4, #0` reached from both, which is only
 * correct because `i` has just been set to -1 on the first path.  Reading that
 * shared instruction as a single statement is what makes the restart visible.
 *
 * -1 costs three materialisations here, one in a register and two in stack
 * slots, because the function is out of callee-saved registers: the same
 * constant is the loop's sentinel, the value assigned to `i`, and the value
 * compared against in the other arm.
 *
 * The tail of sub_02009A74 is where the shape of the source is visible.  It
 * clears slot 31 of both arrays, and the original reaches it as base plus
 * offset in two separate adds: `list + 0x1C0` and then `+ 0x5D0`, with the
 * friend array's `+ 0x174` derived from that same 0x5D0 by a `lsrs #2`.
 * Written as `&list->friendInfo[31]` the compiler folds the two constants into one
 * 0x790 and the tail is 34 bytes different; only a local pointer, assigned
 * from the array *after* the loop and indexed with the literal 31, keeps them
 * apart.  Assigning the same pointers before the loop is wrong too: they then
 * stay live in callee-saved registers and the reload of `obj` from its stack
 * slot disappears.
 *
 * sub_02009B80 stamps the entry with the date.  func_0203F4E4 fills a 0x10-byte
 * record on the stack whose first three words are year, month and day, and the
 * year is stored as `year + 2000`, which is the `movs r0, #0x7D; lsls r0, #4`
 * in front of the `strh`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009A34.c \
 *       --addr 0x02009A34 --thumb
 */
u32 sub_02009A34(struct WifiList *list)
{
    int i;
    u32 count = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(list, i) != 0) {
            count++;
        }
    }
    return count;
}


u32 sub_02009A54(struct WifiList *list)
{
    int i;
    u32 end = 0;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(list, i) != 0) {
            end = i + 1;
        }
    }
    return end;
}


void sub_02009A74(struct WifiList *list, u32 slot)
{
    struct WifiFriendInfo *infos;
    struct DWCFriendData *friends;

    if (slot >= 0x20) {
        return;
    }
    for (; (int)slot < 0x1F; slot++) {
        MI_CpuCopy8(&list->friendInfo[slot + 1], &list->friendInfo[slot],
                    sizeof(list->friendInfo[0]));
        MI_CpuCopy8(&list->friendData[slot + 1], &list->friendData[slot],
                    sizeof(list->friendData[0]));
    }
    infos = list->friendInfo;
    friends = list->friendData;
    MI_CpuFill8(&infos[0x1F], 0, sizeof(infos[0]));
    MI_CpuFill8(&friends[0x1F], 0, sizeof(friends[0]));
}


void sub_02009AE4(struct WifiList *list, u32 dest, u32 src)
{
    MI_CpuCopy8(&list->friendInfo[src], &list->friendInfo[dest], sizeof(list->friendInfo[0]));
    MI_CpuCopy8(&list->friendData[src], &list->friendData[dest], sizeof(list->friendData[0]));
    MI_CpuFill8(&list->friendInfo[src], 0, sizeof(list->friendInfo[0]));
    MI_CpuFill8(&list->friendData[src], 0, sizeof(list->friendData[0]));
}


void sub_02009B3C(struct WifiList *list)
{
    int i;
    int hole = -1;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(list, i) != 0) {
            if (hole != -1) {
                sub_02009AE4(list, hole, i);
                i = -1;
                hole = -1;
            }
        } else {
            if (hole == -1) {
                hole = i;
            }
        }
    }
}


void sub_02009B80(struct WifiList *list, int slot)
{
    struct RTCDate date;

    func_0203F4E4(&date);
    list->friendInfo[slot].lastYear = date.year + 2000;
    list->friendInfo[slot].lastMonth = date.month;
    list->friendInfo[slot].lastDay = date.day;
}


void sub_02009BB8(struct WifiList *list, int slot, int wins, int losses, int trades)
{
    if (slot < 0 || slot >= 0x20) {
        return;
    }
    list->friendInfo[slot].battleWins += (u16)wins;
    if (list->friendInfo[slot].battleWins > 9999) {
        list->friendInfo[slot].battleWins = 9999;
    }
    list->friendInfo[slot].battleLosses += (u16)losses;
    if (list->friendInfo[slot].battleLosses > 9999) {
        list->friendInfo[slot].battleLosses = 9999;
    }
    list->friendInfo[slot].tradeCount += (u16)trades;
    if (list->friendInfo[slot].tradeCount > 9999) {
        list->friendInfo[slot].tradeCount = 9999;
    }
    sub_02009B80(list, slot);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: wifilist.c.  sub_02009C24 folds one entry's three counters into
 * another's, clamping each at 9999 the way sub_02009BB8 does, and then clears
 * the entry it drained.
 *
 * The cut between this range and src/matched/unit_02009CB0.c is what makes
 * both halves EXACT.  DWC_CreateExchangeToken is reached from exactly two
 * places in the image, the pool word of sub_02009CA8 at 0x02009CAC and the
 * `blx` inside sub_02009CB0 at 0x02009CB8, and a range holding both leaves the
 * address with no witness at all.  Split, the `blx` attests this file's pool
 * word and the pool word attests that file's `blx`.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c  *       --addr 0x02009C24 --thumb
 */
void sub_02009C24(struct WifiList *list, int src, int dest)
{
    if (dest < 0 || dest >= 0x20) {
        return;
    }
    if (src < 0 || src >= 0x20) {
        return;
    }
    list->friendInfo[dest].battleWins += list->friendInfo[src].battleWins;
    if (list->friendInfo[dest].battleWins > 9999) {
        list->friendInfo[dest].battleWins = 9999;
    }
    list->friendInfo[dest].battleLosses += list->friendInfo[src].battleLosses;
    if (list->friendInfo[dest].battleLosses > 9999) {
        list->friendInfo[dest].battleLosses = 9999;
    }
    list->friendInfo[dest].tradeCount += list->friendInfo[src].tradeCount;
    if (list->friendInfo[dest].tradeCount > 9999) {
        list->friendInfo[dest].tradeCount = 9999;
    }
    MI_CpuFill8(&list->friendInfo[src], 0, sizeof(list->friendInfo[0]));
}


void sub_02009CA8(void *userData, void *friendData)
{
    DWC_CreateExchangeToken(userData, friendData);
}


void func_02009CB0(struct WifiList *list, void *token)
{
    DWC_CreateExchangeToken(sub_02009860(list), token);
}


/*
 * Compared as a unit rather than as a single function because the packet's
 * range runs two bytes past the last instruction: `match.py one` sees the
 * original as 36 bytes against the compiler's 34 and reports EXACT*, while
 * `tu` lays the section out and reproduces the linker's two-byte filler.
 */
int func_02009CC0(struct WifiList *list)
{
    u8 token[12];
    void *userData = sub_02009860(list);

    func_02009CB0(list, token);
    return DWC_GetGsProfileId(userData, token);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the DWC-facing end of wifilist.c.  sub_02009D08 is the one that names
 * the save block: it fetches block id 0x1E out of func_020071CC and hands it
 * straight to the entry accessor of src/matched/unit_02009860.c, so the wifi
 * friend list lives in block 0x1E.
 *
 * sub_02009860, the two-byte `bx lr` in src/matched/unit_02009860.c, is used
 * here the way sub_020084F4 is used in src/matched/unit_02008F48.c: its result
 * feeds the next call's first argument with no move in between, so it is an
 * identity accessor and is declared with the type that call needs.
 *
 * NEAR MISS, 0x02009CB0 and 0x02009CC0, 50 bytes, skipped for attestation and
 * not for codegen.  They are
 *
 *   void sub_02009CB0(struct WifiList *obj, void *out)
 *   {
 *       DWC_CreateExchangeToken(sub_02009860(obj), out);
 *   }
 *
 *   void sub_02009CC0(struct WifiList *obj)
 *   {
 *       u8 token[0xC];
 *       void *account = sub_02009860(obj);
 *
 *       sub_02009CB0(obj, token);
 *       DWC_GetGsProfileId(account, token);
 *   }
 *
 * and with sub_02009C24 they reproduce every concrete byte.  The chain that
 * blocks them is two links long.  DWC_CreateExchangeToken is reached from
 * exactly two places in the image: the pool word of sub_02009CA8 at 0x02009CAC
 * and the `blx` in sub_02009CB0 at 0x02009CB8.  Whichever of the two is in the
 * range, the other is its witness, so exactly one of them can be matched, and
 * src/matched/unit_02009C24.c takes sub_02009CA8 because that choice is what
 * lets its own pool word be attested by the `blx`.  sub_02009CB0 is then
 * unmatched, and the only branch to *it* anywhere in the image is the one in
 * sub_02009CC0, so sub_02009CC0 cannot be matched either.  Both close the day
 * anything else in the image calls either address.
 *
 * sub_02009D50 compares two call results against two parameters, and both
 * comparisons only come out `cmp r0, rN` when a named local holds the result:
 * written inline, in either operand order or as one `&&` chain, the compiler
 * normalises to `cmp rN, r0` and the file is two bytes wrong.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * sub_02009D50's second parameter is dead: nothing in it reads r1, and
 * sub_02009D1C still computes sub_020084F4(p) to pass there.  Leaving the
 * parameter out moves every argument and the function does not match, so the
 * dead argument is part of the shape.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009C24.c \
 *       --addr 0x02009C24 --thumb
 */
u32 sub_02009CE4(struct WifiList *list)
{
    void *userData = sub_02009860(list);

    if (DWC_CheckHasProfile(userData) != 0) {
        if (DWC_CheckValidConsole(userData) != 0) {
            return 1;
        }
    }
    return 0;
}


struct WifiList *sub_02009D08(struct SaveControl *save)
{
    struct WifiList *list = func_020071CC(save, 0x1E);

    sub_020099D4(list, 0);
    return list;
}


int sub_02009D1C(struct WifiList *list, struct MyStatus *status,
                 u32 *outSlot)
{
    u32 id = sub_02008530(status);
    u8 outfitVariant = sub_02008550(status);

    return sub_02009D50(list, sub_020084F4(status), id, outfitVariant, outSlot);
}


int sub_02009D50(struct WifiList *list, const void *name, u32 id,
                 u32 outfitVariant, u32 *outSlot)
{
    u8 i;
    u32 value;

    for (i = 0; i < 0x20; i++) {
        if (sub_02009A1C(list, i) == 1) {
            value = sub_02009864(list, i, 0);
            if (value == id) {
                value = sub_02009864(list, i, 9);
                if (value == outfitVariant) {
                    if (outSlot != 0) {
                        *outSlot = i;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the head of the next file after wifilist.c, a 0xD54-byte record whose
 * rest is in pkt_02009DB8.  Same opening as every other record here: a four
 * byte function returning the size over its own pool word, then a constructor
 * that clears exactly that many bytes.
 *
 * Unlike the 0x23 block in src/matched/unit_02009448.c, this constructor
 * *calls* the size function instead of spelling the constant a second time, so
 * the two files differ in the source and not only in the bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009D9C.c \
 *       --addr 0x02009D9C --thumb
 */
u32 sub_02009D9C(void)
{
    return sizeof(struct TradeHistory);
}


void sub_02009DA4(struct TradeHistory *history)
{
    MI_CpuFill8(history, 0, sub_02009D9C());
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009E74, sub_02009E8C, sub_02009EA8, sub_02009EB0
 *
 * alias: the body of the 0xD54-byte record whose head is
 * src/matched/unit_02009D9C.c.  It is a hundred-slot most-recently-used list
 * of the 0x20-byte object of src/matched/unit_0200852C.c, plus one counter:
 *
 *   +0x000  MyStatus[100]         0x20 bytes each
 *   +0xD50  u32                   a use count, saturating at 99999
 *
 * sub_02008468, four bytes returning 0x20, is the element size, and
 * sub_02009DE8 uses it for both of its block moves rather than spelling 0x20
 * out.  The insert shifts the whole list up by one slot with MI_CpuMove and
 * copies the new object into slot 0, so slot 0 is the most recent; when the
 * object is already in the list only its +0x1C byte is refreshed.
 *
 * sub_02009DB8 returns -1 for "not found", materialised as `movs r0, #0` and
 * `mvns r0, r0` rather than as a pool word, and every caller compares against
 * that same pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009DB8.c \
 *       --addr 0x02009DB8 --thumb
 */
int sub_02009DB8(struct TradeHistory *history, u32 id)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&history->partners[i]) != 0
            && id == sub_02008530(&history->partners[i])) {
            return i;
        }
    }
    return -1;
}


void sub_02009DE8(struct TradeHistory *history, struct MyStatus *status)
{
    u32 id = sub_02008530(status);
    u32 size = sub_02008468();
    int slot;

    if (id == 0) {
        return;
    }
    slot = sub_02009DB8(history, id);
    if (slot != -1) {
        sub_02008558(&history->partners[slot], sub_02008554(status));
        return;
    }
    MI_CpuMove(history->partners, &history->partners[1], size * 99);
    MI_CpuCopy8(status, history->partners, size);
}


u32 sub_02009E40(struct TradeHistory *history, u32 slot)
{
    if (slot >= 100) {
        slot = 0;
    }
    return sub_02008530(&history->partners[slot]);
}


struct MyStatus *sub_02009E54(struct TradeHistory *history, u32 slot)
{
    if (slot >= 100) {
        return 0;
    }
    if (sub_02009E40(history, slot) == 0) {
        return 0;
    }
    return &history->partners[slot];
}


u32 sub_02009E74(struct TradeHistory *history, u32 id)
{
    if (sub_02009DB8(history, id) != -1) {
        return 1;
    }
    return 0;
}


int sub_02009E8C(struct TradeHistory *history)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (sub_0200855C(&history->partners[i]) == 0) {
            break;
        }
    }
    return i;
}


u32 sub_02009EA8(const struct TradeHistory *history)
{
    return history->tradeCount;
}


void sub_02009EB0(struct TradeHistory *history)
{
    history->tradeCount = history->tradeCount + 1;
    if (history->tradeCount > 99999) {
        history->tradeCount = 99999;
    }
}


/*
 * Save-block getter for block 0x1F, the same one-line shape as
 * func_0200AD6C (block 0x2E): a tail call through the pool with the id in
 * r1. Seeded from ov120 (0x021D4A90, 0x021D4AC8), ov135 (0x02201B78) and
 * the ov175 root func_021D7E18 (0x021D827E).
 */
struct TradeHistory *func_02009EC8(struct SaveControl *save)
{
    return func_020071CC(save, 0x1f);
}


/*
 * Save-table size callback: returns 0xA94, the size of the block whose
 * init is func_02009EDC.  Pointer word 0x02009ED5 at 0x0209DBC4 (the
 * save table's (size, init, id) row for id 0x22).
 */
u32 func_02009ED4(void)
{
    return 0xA94;
}


void func_02009EDC(u8 *buffer)
{
    struct MysteryData data;

    MI_CpuFill8(&data, 0, sizeof(data));
    data.buffer = buffer;
    data.saveType = 1;
    MI_CpuFill8(buffer, 0, 0xa94);
    func_0200A480(&data);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02009F0C.c \\
 *       --func func_02009F0C --addr 0x02009F0C --thumb --cc 1.1p1
 */
u32 func_02009F0C(u32 giftType)
{
    if (giftType != 0 && giftType < 4) {
        return 1;
    }
    return 0;
}


int func_02009F1C(struct MysteryData *data)
{
    u32 i;
    u32 max = func_0200A400(data);

    for (i = 0; i < max; i++) {
        if (func_02009F0C(func_0200A43C(data, i)->giftType) == 0)
            return 1;
    }
    return 0;
}


int func_02009F50(struct MysteryData *data, u32 slot)
{
    struct MysteryCard *card = func_0200A43C(data, slot);
    func_0200A400(data);
    if (slot < 0xc && func_02009F0C(card->giftType) != 0)
        return 1;
    return 0;
}


void func_02009F7C(struct MysteryData *data, u32 slot)
{
    u32 i;
    u32 max = func_0200A400(data);
    if (func_02009F50(data, slot) != 0)
        return;
    for (i = slot; i < max - 1; i++) {
        void *dst = func_0200A43C(data, i);
        void *src = func_0200A43C(data, i + 1);
        /* word view: the copy is an ldm/stm loop only for a four-aligned type */
        *(struct MysteryCardImage *)dst = *(struct MysteryCardImage *)src;
    }
    MI_CpuFill8(func_0200A43C(data, i), 0, sizeof(struct MysteryCard));
}


struct MysteryCard *func_02009FD4(struct MysteryData *data, u32 slot)
{
    struct MysteryCard *card = func_0200A43C(data, slot);
    u32 max = func_0200A400(data);
    if (slot < max && func_02009F0C(card->giftType) != 0)
        return card;
    return 0;
}


int func_0200A000(struct MysteryData *data, u32 slot, void *out)
{
    struct MysteryCard *card;
    int found = 0;
    func_0200A400(data);
    func_0200A49C(data);
    card = func_02009FD4(data, slot);
    if (card != 0) {
        MI_CpuCopy8(card, out, sizeof(struct MysteryCard));
        found = 1;
    }
    func_0200A480(data);
    return found;
}


int func_0200A034(struct MysteryData *data, const void *card)
{
    u32 i;
    int added = 0;
    u32 max = func_0200A400(data);
    func_0200A49C(data);
    if (func_02009F1C(data) == 1) {
        for (i = 0; i < max; i++) {
            struct MysteryCard *slot = func_0200A43C(data, i);
            if (func_02009F0C(slot->giftType) == 0) {
                MI_CpuCopy8(card, slot, sizeof(struct MysteryCard));
                added = 1;
                break;
            }
        }
    }
    func_0200A480(data);
    return added;
}


void func_0200A094(struct MysteryData *data, u32 slot)
{
    u32 max = func_0200A400(data);
    func_0200A49C(data);
    if (slot < max) {
        struct MysteryCard *card = func_0200A43C(data, slot);
        card->giftType = 0;
        func_02009F7C(data, slot);
    }
    func_0200A480(data);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0C8.c \\
 *       --func func_0200A0C8 --addr 0x0200A0C8 --thumb --cc 1.1p1
 */
u32 func_0200A0C8(struct MysteryData *data)
{
    u32 hasSpace;

    func_0200A49C(data);
    hasSpace = func_02009F1C(data);
    func_0200A480(data);
    return hasSpace;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0E4.c \\
 *       --func func_0200A0E4 --addr 0x0200A0E4 --thumb --cc 1.1p1
 */
u32 func_0200A0E4(struct MysteryData *data, u32 slot)
{
    u32 exists;

    func_0200A49C(data);
    exists = func_02009F50(data, slot);
    func_0200A480(data);
    return exists;
}


int func_0200A104(struct MysteryData *data, u32 slot)
{
    int received = 0;
    u32 max = func_0200A400(data);
    func_0200A49C(data);
    if (slot < max) {
        struct MysteryCard *card = func_0200A43C(data, slot);
        if (((u32)card->flags << 0x1e) >> 0x1f)
            received = 1;
    }
    func_0200A480(data);
    return received;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A13C.c \\
 *       --func func_0200A13C --addr 0x0200A13C --thumb --cc 1.1p1
 */
void func_0200A13C(struct MysteryData *data, u32 slot)
{
    u32 max = func_0200A400(data);
    struct MysteryCard *card;

    func_0200A49C(data);
    if (slot < max) {
        card = func_0200A43C(data, slot);
        card->flags |= 2;
    }
    func_0200A480(data);
}


int func_0200A170(struct MysteryData *data)
{
    int found = 0;
    u32 i;
    u32 max = func_0200A400(data);
    func_0200A49C(data);
    for (i = 0; i < max; i++) {
        if (func_02009F50(data, i) == 1)
            found = 1;
    }
    func_0200A480(data);
    return found;
}


int func_0200A1A8(struct MysteryData *data, u32 flag)
{
    int set = 0;
    u8 *flags = func_0200A41C(data);
    func_0200A49C(data);
    if (flag < 0x800) {
        if (flags[flag >> 3] & (1 << (flag & 7)))
            set = 1;
    }
    func_0200A480(data);
    return set;
}


void func_0200A1E4(struct MysteryData *data, u32 flag)
{
    u8 *flags = func_0200A41C(data);
    func_0200A49C(data);
    if (flag < 0x800) {
        flags[flag >> 3] |= (u8)(1 << (flag & 7));
    }
    func_0200A480(data);
}


/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): declaration order i before n,
 *           and the counter n is unsigned (8 bytes)
 */
int func_0200A21C(struct MysteryGiftPacket *packet)
{
    int i;
    u32 spinLimit = 0x2d0;
    u32 spin = 0;

    do {
        for (i = 0; i < 16; i++) {
            spin++;
        }
    } while (spin < (int)spinLimit);
    return packet->crc == func_0203F1FC(packet, 0x2ce);
}


void func_0200A254(struct MysteryData *data, u32 slotA, u32 slotB)
{
    u8 swapCard[0xcc];
    func_0200A49C(data);
    if (func_02009F50(data, slotA) && func_02009F50(data, slotB)) {
        struct MysteryCard *cardA = func_02009FD4(data, slotA);
        struct MysteryCard *cardB = func_02009FD4(data, slotB);
        MI_CpuCopy8(cardA, swapCard, sizeof(struct MysteryCard));
        MI_CpuCopy8(cardB, cardA, sizeof(struct MysteryCard));
        MI_CpuCopy8(swapCard, cardB, sizeof(struct MysteryCard));
    }
    func_0200A480(data);
}


void func_0200A2B8(struct MysteryData *data, struct GameData *gameData)
{
    if (func_0200A350(data) == 0) {
        func_021DFDC0(data->extraSave);
    } else {
        func_02012DAC(gameData);
    }
}


int func_0200A2D8(struct MysteryData *data, struct GameData *gameData)
{
    if (func_0200A350(data) == 0) {
        if (func_021DFE00(data->extraSave) != 0)
            return 2;
        return 0;
    }
    return func_02012DD0(gameData);
}


struct MysteryData *func_0200A300(struct SaveControl *save, int mode, u32 heapId)
{
    struct MysteryData *data = func_02030734(heapId, sizeof(struct MysteryData), 0, g_020A71A4, 0x260);

    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
    sub_0200A358(data, save, mode, heapId);
    return data;
}


void func_0200A338(struct MysteryData *data)
{
    func_0200A3D0(data);
    func_020307B0(data);
}


/*
 * Four bytes of code and a pool word: the plain Thumb tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  It carries no label in the
 * generated listing (it saves nothing), so it was read out of the bytes; it
 * sits between func_0200A338 and func_0200A350 at the end of its packet.
 * Its target reads one object pointer in r0 and returns the unsigned count
 * used by the overlay callers.
 */
u32 func_0200A348(struct MysteryData *data)
{
    return func_0200A400(data);
}


int func_0200A350(struct MysteryData *data)
{
    return func_0200A3FC(data);
}


/*
 * note:     wave 16: promoted.  0x021DFE90 and 0x021DFEAC are unlabelled
 *           ov228 leaves (a byte getter at +0x378 and `p + 0xC`), now matched
 *           in src/matched/func_021DFE90.c / func_021DFEAC.c (shard
 *           ov228/pkt_021DFC20); the ov228 hints below make both sites
 *           `matched, overlay`.  func_021DFEAC's body reads r0, so its
 *           prototype now takes the pointer func_021DFC20 returned (the
 *           callee-arity lever; same bytes, it was a live leftover before).
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200A358.c.txt had this row at DIFF,
 * 112 bytes against 120, 91 concrete bytes out).  The note's C spelled the
 * dispatch on a2 as `if (a2 == 1) t = sub_020071EC(a1);` with `t` initialised
 * to 1.  The original is a SWITCH with an explicit empty-ish case 0:
 *
 *   0200A36A  cmp r4, #0 / beq  ->  0200A374: b 0200A37E  (t = 1)
 *   0200A36E  cmp r4, #1 / beq  ->  0200A376: bl 20071EC
 *   0200A372  b            ->  0200A37E: movs r0, #1      (default, t = 1)
 *
 * Two separate branch targets that both land on `movs r0, #1` is the tell of
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md read the other way
 * round: case 0 and the default arm are written out separately in the source
 * even though they do the same thing.  Writing the switch with case 0,
 * case 1 and default each assigning `t` recovers the missing 8 bytes AND the
 * register allocation -- the `if` form spilled a3 to `[sp]` where the
 * original keeps it in r7 -- and takes the row from 91 concrete bytes out to
 * zero in one edit.  The 0xE4 pool word is the same absolute linker symbol
 * func_0200A3D0 next door uses
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0200A358.c \
 *       --func sub_0200A358 --addr 0x0200A358 --cc 1.1p1 --thumb
 */
void sub_0200A358(struct MysteryData *data, struct SaveControl *save, int mode, int heapId)
{
    int inMainSave;
    void *work;

    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
    switch (mode) {
    case 0:
        inMainSave = 1;
        break;
    case 1:
        inMainSave = sub_020071EC(save);
        break;
    default:
        inMainSave = 1;
        break;
    }
    if (inMainSave != 0) {
        data->buffer = func_020071CC(save, 0x22);
        data->saveType = 1;
        return;
    }
    func_02034AC4((int)ov_id_E4);
    work = func_021DFC20(heapId);
    data->extraSave = work;
    data->buffer = func_021DFEAC(work);
    data->saveType = 0;
    if (func_021DFE90(data->extraSave) == 0) {
        MI_CpuFill8(data->buffer, 0, 0x368);
        func_0200A480(data);
    }
}


/*
 * note:     wave 16: promoted.  0x021DFDB8 is an unlabelled ov228 leaf, a
 *           one-argument tail call to the ARM heap free func_020307B0, now
 *           matched in src/matched/func_021DFDB8.c (shard ov228/pkt_021DFC20);
 *           the ov228 hint below makes the site `matched, overlay`.
 * Third pass, lane 1: this row was DIFF for two passes and is now byte-correct.
 * The residue was never a codegen difference.  The original's second call is
 *
 *   0200A3E4  04 48        ldr r0, [pc, #0x10]
 *   0200A3E6  2a f0 3a eb  blx #0x2034a5c
 *   ...
 *   0200A3F8  e4 00 00 00  0x000000E4
 *
 * a small constant loaded from the pool where `func_02034A5C(0xe4)` gives
 * `movs r0, #0xe4`.  That is the reading of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md: a pool
 * word holding a value too small to be an address is an `R_ARM_ABS32` against
 * an absolute symbol, i.e. 0xE4 is a linker-defined id, and declaring it and
 * passing it reproduces the original's pool word and all 44 bytes.  The
 * site resolves as `literal x2` (two other pool words in the image hold
 * 0x000000E4, e.g. 0x02007070), which is what confirms the reading.
 * Five numeric spellings were tried and all five give `movs`:
 * `0xe4`, `(u32)0xe4`, a macro, a `static const u32`, and a file-scope
 * `const u32`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0200A3D0.c \
 *       --func func_0200A3D0 --addr 0x0200A3D0 --cc 1.1p1 --thumb
 */
void func_0200A3D0(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        func_021DFDB8(data->extraSave);
        func_02034A5C((int)ov_id_E4);
        break;
    case 1:
        break;
    }
    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
}


#define HW_VBLANK_COUNT_BUF (*(volatile u32 *)0x02FFFC3C)


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A43C, func_0200A480, func_0200A49C, func_0200A4B8,
 *           func_0200A50C, func_0200A53C, func_0200A544, func_0200A5F8,
 *           func_0200A604, func_0200A628, func_0200A630, func_0200A640,
 *           func_0200A644, func_0200A680, func_0200A6BC
 *
 * 764 bytes, 0x0200A3FC..0x0200A6F8, 19 functions.  Five of the nineteen
 * carry no label in the generated listing (0x0200A53C, 0x0200A628,
 * 0x0200A630, 0x0200A640 and 0x0200A680): none of them saves lr, so
 * disasm.py's prologue sweep does not fire and the listing prints their
 * bytes as `.word` data in the middle of a literal pool.  They were read out
 * of those words.  0x0200A53C is the giveaway of the three: `movs r0, #0xa9;
 * lsls r0, #2; bx lr` returns 0x2A4, which is exactly the size the
 * constructor at 0x0200A544 clears, the same "a block file opens with a
 * function returning its own size" shape docs/MATCHING.md records for the
 * 0x0200857C run.
 *
 * This unit absorbs the previously matched single function
 * src/matched/sub_0200A6BC.c (0x0200A6BC, 60 bytes), which is its last
 * function.  Its legacy manifest entry is superseded by this unit.
 *
 * What the range is.  Two objects, and two layers.
 *
 * `struct MysteryData` is a twelve byte handle: a pointer to a block, a kind that is
 * only ever 0 or 1, and a third word.  Every accessor on it is a `switch`
 * over that kind with the default falling through to a zero return, and the
 * two arms are byte for byte identical in three of the four cases, so the
 * distinction is in the source and not in the code.  The 0x0200A4B8 /
 * 0x0200A50C pair stamps and clears a four byte header sitting at the end of
 * the block (offset 0x364 or 0xA90 for the two kinds), holding a 32-bit key
 * built out of a system word and handed to the pair of routines at
 * 0x0203F2FC / 0x0203F328 / 0x0203F37C.
 *
 * `struct MusicalSave` is a 0x2A4-byte record with two parallel 0x20-byte bitmaps at
 * 0x258 and 0x278.  0x0200A6BC sets the same bit in both, 0x0200A644 tests
 * the first and 0x0200A680 tests the second; the constructor at 0x0200A544
 * clears the record, seeds two arrays and then sets fifteen of those bits by
 * hand.  100 (0x64) is the bound on every one of the three, so 100 of the
 * 256 bits are in use.
 *
 * Three things in this unit cost time and are recorded under docs/idioms/:
 *
 *  - the assignment that both arms of a switch make is emitted once, at a
 *    merge point the default case jumps over.  Writing it after the switch
 *    instead puts the default's branch on that merge point and changes one
 *    branch target and the whole register allocation of the function.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - a repeated read of a hardware address has to be written as two named
 *    locals.  `(X << 8) | X` on a volatile lvalue interleaves the shift
 *    between the two loads; the original loads both and then shifts.  See
 *    docs/idioms/volatile-reread-needs-two-locals.md.
 *  - 0x02FFFC3C is a cast address constant and not an extern.  An `extern
 *    volatile u32` at that address produces an ABS32 relocation and puts the
 *    address in a different register.  Same idiom file as above.
 *
 * Near miss, left out of this unit deliberately: the function at
 * 0x0200A3D0, which is the one immediately before it and is almost certainly
 * part of the same original file.  Two separate reasons, either of which is
 * enough:
 *
 *  1. it calls 0x021DFDB8, which is an overlay address.  `attest()` now has a
 *     rule for those: a target inside an overlay per layout/layout.json is
 *     attested when that overlay's own listing carries a `func_` label at the
 *     address, the label's ISA is the declared ISA, and some branch outside
 *     the compared range targets it.  The third part holds here (a `bl` from
 *     0x02006F42 inside arm9_main and another from ov088 at 0x021BC378); the
 *     first does not.  0x021DFDB8 is inside seven overlays at once, because
 *     overlays share load windows, and they disagree about what is there:
 *     ov093 has an instruction in the middle of a function, ov119 a `movs`,
 *     ov170 a data word, ov228 an eight byte Thumb thunk.  None of them
 *     labels it, so nothing says which of the seven the call means and the
 *     relocation stays a wildcard.  (The thunk in ov228 is the linker's Thumb
 *     veneer shape, which the `veneer` class deliberately does not recognise:
 *     mwccarm emits those same eight bytes for a Thumb tail call.  See "The
 *     veneer class" in docs/MATCHING.md.)
 *  2. two concrete bytes are wrong regardless.  The original materialises the
 *     constant 0xE4 with `ldr r0, [pc, #0x10]` out of its own literal pool,
 *     where every spelling of the integer 228 tried here (decimal, hex,
 *     suffixed, cast, enumerator, `sizeof`, `offsetof`) compiles to `movs
 *     r0, #0xE4` under all nine front ends at every optimisation level.  The
 *     function immediately before it does the same thing with the same value,
 *     so whatever the construct is, it is used twice in a row and is not an
 *     accident.  The rest of the function is byte for byte right.
 */
u32 func_0200A3FC(struct MysteryData *data)
{
    return data->saveType;
}


u32 func_0200A400(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        return 3;
    case 1:
        return 12;
    }
    return 0;
}


u8 *func_0200A418(struct MysteryData *data)
{
    return data->buffer;
}


u8 *func_0200A41C(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        return func_0200A418(data);
    case 1:
        return func_0200A418(data);
    }
    return 0;
}


struct MysteryCard *func_0200A43C(struct MysteryData *data, u32 slot)
{
    func_0200A400(data);
    switch (data->saveType) {
    case 0:
        return (struct MysteryCard *)(func_0200A418(data) + 0x100 + slot * 0xCC);
    case 1:
        return (struct MysteryCard *)(func_0200A418(data) + 0x100 + slot * 0xCC);
    }
    return 0;
}


void func_0200A480(struct MysteryData *data)
{
    func_0200A4B8(func_0200A418(data), func_0200A3FC(data));
}


void func_0200A49C(struct MysteryData *data)
{
    func_0200A50C(func_0200A418(data), func_0200A3FC(data));
}


void func_0200A4B8(u8 *buffer, u32 saveType)
{
    u32 size;
    struct MysteryDataFooter *footer;
    u32 seedHigh, seedLow;

    switch (saveType) {
    case 0:
        size = 0x368;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    case 1:
        size = 0xA94;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    }
    seedHigh = HW_VBLANK_COUNT_BUF;
    seedLow = HW_VBLANK_COUNT_BUF;
    footer->cryptSeed = (u16)((seedHigh << 8) | seedLow);
    if (footer->cryptSeed == 0) {
        footer->cryptSeed = 1;
    }
    footer->checksum = func_0203F2FC(buffer, size - 4);
    func_0203F328(buffer, size - 4, footer->checksum + (footer->cryptSeed << 16));
}


void func_0200A50C(u8 *buffer, u32 saveType)
{
    u32 size;
    struct MysteryDataFooter *footer;

    switch (saveType) {
    case 0:
        size = 0x368;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    case 1:
        size = 0xA94;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    }
    func_0203F37C(buffer, size - 4, footer->checksum + (footer->cryptSeed << 16));
    footer->cryptSeed = 0;
}


u32 func_0200A53C(void)
{
    return sizeof(struct MusicalSave);
}


void func_0200A544(struct MusicalSave *musical)
{
    u8 i;

    MI_CpuFill8(musical, 0, sizeof(struct MusicalSave));
    func_0200A604(musical);
    for (i = 0; i < 10; i++) {
        musical->programs[i].state = 4;
    }
    musical->scriptSetting = 0;
    musical->hasDistData = 0;
    func_0200A6BC(musical, 0x30);
    func_0200A6BC(musical, 0x46);
    func_0200A6BC(musical, 0x53);
    func_0200A6BC(musical, 0x4B);
    func_0200A6BC(musical, 0x00);
    func_0200A6BC(musical, 0x01);
    func_0200A6BC(musical, 0x0A);
    func_0200A6BC(musical, 0x1C);
    func_0200A6BC(musical, 0x08);
    func_0200A6BC(musical, 0x3B);
    func_0200A6BC(musical, 0x3F);
    func_0200A6BC(musical, 0x42);
    func_0200A6BC(musical, 0x10);
    func_0200A6BC(musical, 0x59);
    func_0200A6BC(musical, 0x4C);
}


struct MusicalSave *func_0200A5F8(struct SaveControl *save)
{
    return func_020071CC(save, 0x2A);
}


void func_0200A604(struct MusicalSave *musical)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        musical->outfits[i].pokeSlot = 10;
    }
}


struct MusicalOutfit *func_0200A628(struct MusicalSave *musical)
{
    return musical->outfits;
}


u32 func_0200A630(struct MusicalSave *musical)
{
    return musical->shotState != 0;
}


void func_0200A640(void)
{
}


u32 func_0200A644(struct MusicalSave *musical, u8 prop)
{
    if (prop < 100) {
        u8 shift = (s32)prop % 8;
        u8 byte  = prop >> 3;
        if ((musical->ownedProps[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}


u32 func_0200A680(struct MusicalSave *musical, u8 prop)
{
    if (prop < 100) {
        u8 shift = (s32)prop % 8;
        u8 byte  = prop >> 3;
        if ((musical->newProps[byte] & (1 << shift)) > 0) {
            return 1;
        }
    }
    return 0;
}


void func_0200A6BC(struct MusicalSave *musical, u32 prop)
{
    u8 shift, byte;

    if (prop >= 100) {
        return;
    }
    shift = (s32)prop % 8;
    byte  = prop >> 3;
    musical->ownedProps[byte] |= (u8)(1 << shift);
    musical->newProps[byte] |= (u8)(1 << shift);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A75C, func_0200A768, func_0200A780, func_0200A788,
 *           func_0200A7A0, func_0200A7AC, func_0200A7B8, func_0200A7C0,
 *           func_0200A7C8, func_0200A7D4, func_0200A7E0, func_0200A7EC,
 *           func_0200A800, func_0200A7F8, func_0200A81C, func_0200A828,
 *           func_0200A834
 *
 * 328 bytes, 0x0200A6F8..0x0200A840, 21 functions, and the direct
 * continuation of src/matched/unit_0200A3FC.c: every one of them reaches the
 * same 0x2A4-byte `struct MusicalSave`, and the accessors here are what pin the last
 * quarter of its layout (three counters at 0x252, 0x254 and 0x256, a
 * four-entry byte array at 0x298 and four separate bytes at 0x29C..0x29F).
 *
 * Fourteen of the twenty-one carry no label in the generated listing: none of
 * them saves lr, so disasm.py's prologue sweep does not fire and the listing
 * prints their bytes as `.word` data.  They are the accessor half of the file
 * and were read out of those words, the same way the sixteen accessors of
 * unit_0200852C.c were.
 *
 * 0x0200A6F8 is the one docs/MATCHING.md already named under "The two
 * missing labels": the 28-byte loop that clears the second of the two
 * bitmaps func_0200A6BC sets a bit in.  It is in
 * layout/function_starts.txt, attested by the bl from ov133 at 0x021B62A2,
 * which is why it has a label here and its fourteen neighbours do not.
 *
 * 0x0200A714 counts how many of the 256 bit positions are set in the first
 * bitmap by calling func_0200A644 on every one of them, and 0x0200A73C asks
 * whether that count has reached 100, which is the same bound the three
 * bitmap routines in unit_0200A3FC.c check their index against.  So 100 is
 * the population of whatever the bitmap enumerates and this pair is its
 * "have you seen all of them" test.
 *
 * Two details pin source shapes here, both of them one-line fixes that look
 * like body diffs:
 *
 *  - in 0x0200A714 the accumulator has to be declared before the loop
 *    counter.  Declared the other way round the two locals swap registers,
 *    which is six differing bytes spread over the whole function and nothing
 *    else.  Same finding as docs/idioms/local-declaration-order-is-stack-
 *    order.md, one level up: the rule holds for register-allocated locals and
 *    not only for stack slots.
 *  - 0x0200A800 saturates at 0xFFFF, and the source tests `v < 0xFFFF` with
 *    the saturating store in the `else`.  Written the other way round the
 *    compiler emits `blt` where the original has `bge` and swaps the two
 *    stores, which is four bytes and reads as a different function.
 */
void func_0200A6F8(struct MusicalSave *musical)
{
    u8 i;

    for (i = 0; i < 0x20; i++) {
        musical->newProps[i] = 0;
    }
}


u32 func_0200A714(struct MusicalSave *musical)
{
    u32 count;
    s32 prop;

    count = 0;
    for (prop = 0; prop < 256; prop++) {
        if (func_0200A644(musical, (u8)prop) == 1) {
            count++;
        }
    }
    return count;
}


u32 func_0200A73C(struct MusicalSave *musical)
{
    if (func_0200A714(musical) == 100) {
        return 1;
    }
    return 0;
}


struct MusicalProgram *func_0200A750(struct MusicalSave *musical, u32 index)
{
    return &musical->programs[index];
}


u16 func_0200A75C(struct MusicalSave *musical)
{
    return musical->showCount;
}


void func_0200A768(struct MusicalSave *musical)
{
    if (musical->showCount < 0xFFFF) {
        musical->showCount++;
    }
}


u16 func_0200A780(struct MusicalSave *musical)
{
    return musical->topRankCount;
}


void func_0200A788(struct MusicalSave *musical)
{
    if (musical->topRankCount < 0xFFFF) {
        musical->topRankCount++;
    }
}


u8 func_0200A7A0(struct MusicalSave *musical, u32 index)
{
    return musical->equippedProps[index];
}


void func_0200A7AC(struct MusicalSave *musical, u32 index, u8 prop)
{
    musical->equippedProps[index] = prop;
}


u8 func_0200A7B8(struct MusicalSave *musical)
{
    return musical->selectedProgram;
}


void func_0200A7C0(struct MusicalSave *musical, u8 value)
{
    musical->selectedProgram = value;
}


u8 func_0200A7C8(struct MusicalSave *musical)
{
    return musical->scriptSetting;
}


void func_0200A7D4(struct MusicalSave *musical, u8 value)
{
    musical->scriptSetting = value;
}


u8 func_0200A7E0(struct MusicalSave *musical)
{
    return musical->hasDistData;
}


void func_0200A7EC(struct MusicalSave *musical, u8 value)
{
    musical->hasDistData = value;
}


u8 *func_0200A7F8(struct MusicalSave *musical)
{
    return musical->stageData;
}


void func_0200A800(struct MusicalSave *musical, s32 delta)
{
    s32 points = musical->fanPoints + delta;
    if (points < 0xFFFF) {
        musical->fanPoints = points;
    } else {
        musical->fanPoints = 0xFFFF;
    }
}


u16 func_0200A81C(struct MusicalSave *musical)
{
    return musical->fanPoints;
}


u32 func_0200A828(struct MusicalSave *musical)
{
    return musical->fittingSetting;
}


void func_0200A834(struct MusicalSave *musical, u8 value)
{
    musical->fittingSetting = value;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 8 bytes, 0x0200A840..0x0200A848, one function, which carries no label in
 * the generated listing: it is the three-instruction size getter that opens
 * every save block file in this region, and it has no prologue.
 *
 * The size it returns, 0x2DC, is what fixes the tail of the record.  The
 * constructor in the next function hands out the two sub-objects at +0x1E8
 * and +0x1FC, so the only free choice left is how much follows the second
 * one, and 0xE0 is what makes sizeof agree with the getter.
 *
 * Near miss, and the reason this unit stops at 0x0200A848: func_0200A848, 28
 * bytes, reproduces every concrete byte and caps at MATCH.  It is
 *
 *     void func_0200A848(struct MusicalShot *shot)
 *     {
 *         func_02161D98(&shot->photo);
 *         func_02161EEC(shot->title);
 *         func_02161F00(shot->extraData);
 *     }
 *
 * and all three callees live in overlay space.  0x02161D98 is attested by the
 * overlay-resident callee class (label x1, witness 0x02012674).  The other
 * two are not: 0x02161EEC has exactly two branch witnesses image wide, one of
 * them this call and the other 0x02186378, and 0x02161F00 has exactly one,
 * this call.  Neither address carries a func_ label in any overlay that
 * contains it, which is part 1 of the overlay rule, so neither can be
 * attested and no cut helps: the only witness is the call that needs it.  It
 * closes the day disasm.py labels either address.
 */
u32 func_0200A840(void)
{
    return sizeof(struct MusicalShot);
}


/*
 * note:     wave 16: promoted.  02161EEC is the unlabelled ov010 leaf now
 *           matched in src/matched/func_02161EEC.c (shard ov010/pkt_02161EEC),
 *           which attests the call as `matched, overlay` under the ov010
 *           hint below; 02161F00 resolves as sole-ref/code (overlay).
 */
void func_0200A848(struct MusicalShot *shot)
{
    func_02161D98((char *)&shot->photo);
    func_02161EEC(shot->title);
    func_02161F00(shot->extraData);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200A898, func_0200A8A0, func_0200A8AC, func_0200A8C8,
 *           func_0200A8D0, func_0200A8E4, func_0200A8F8
 *
 * 162 bytes, 0x0200A864..0x0200A906, 11 functions, six of which carry no
 * label in the generated listing.
 *
 * The object is a 0x34C-byte record holding thirty 0x1C-byte entries
 * followed by one word of flags; 30 * 0x1C is 0x348, which is exactly the
 * offset func_0200A930 reads that word at, so the array length and the
 * record size check against each other.  Each entry carries a packed word at
 * +0x10 whose fields this file reads one at a time: 7 bits at bit 0, 10 bits
 * at bit 7, one bit at bit 17, and one bit at bit 31 that func_0200A8AC
 * scans for to find how many entries are in use.
 *
 * The bit widths are not guesses.  Each getter is a `lsls`/`lsrs` pair whose
 * two shift counts give the field's position and width directly, and where
 * the return type is narrower than the field the compiler adds a second
 * truncating pair: func_0200A8D0's `lsls #25 / lsrs #25` is the 7-bit field
 * and its `lsls #24 / lsrs #24` is the `u8` return, and dropping either
 * changes two instructions.
 *
 * Near miss, and the reason this unit stops where it does: func_0200A908 at
 * 0x0200A908, 40 bytes, which unpacks four fields of one entry through four
 * out-parameters.  Two of the four are bitfields of the same byte at +0x1B,
 * and the original loads that byte exactly once, with `ldrb` into the
 * register that held the entry pointer, and then does each field's shift pair
 * immediately before its own store.  Writing the two reads directly is two
 * `ldrb`s, because the intervening store through a `u8 *` may alias the
 * struct and the compiler reloads; writing them into locals first gets the
 * single load but hoists both shift pairs above both stores.  Sixteen
 * spellings were tried (locals for each subset of the four outputs, a nested
 * one-byte bitfield struct copied to a local, the whole tail as a `u32`
 * bitfield container, and the shifts written out by hand), and the best of
 * them is sixteen bytes wrong in exactly that scheduling.  Every other byte
 * of the function is right.  The next unit therefore resumes at 0x0200A930.
 */
struct MusicalShot *func_0200A864(struct SaveControl *save)
{
    return func_020071CC(save, 0x2B);
}


void func_0200A870(struct MusicalShotPhoto *dest, const struct MusicalShotPhoto *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct MusicalShotPhoto));
}


void func_0200A884(const struct MusicalShotPhoto *src, struct MusicalShotPhoto *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct MusicalShotPhoto));
}


u16 *func_0200A890(struct MusicalShot *shot)
{
    return shot->title;
}


u8 *func_0200A898(struct MusicalShot *shot)
{
    return shot->extraData;
}


struct IrcRankSave *func_0200A8A0(struct SaveControl *save)
{
    return func_020071CC(save, 0x2C);
}


s32 func_0200A8AC(struct IrcRankSave *rank)
{
    s32 i;
    for (i = 0; i < 30; i++) {
        if (rank->entries[i].isValid == 0) {
            break;
        }
    }
    return i;
}


struct IrcRankEntry *func_0200A8C8(struct IrcRankSave *rank, u32 index)
{
    return &rank->entries[index];
}


u8 func_0200A8D0(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].score;
}


u16 func_0200A8E4(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].meetCount;
}


u32 func_0200A8F8(struct IrcRankSave *rank, u32 index)
{
    return rank->entries[index].gender;
}


/*
 * Unlabelled Thumb leaf: reads record i (28 bytes) and writes its u16, u8
 * and two bitfields to four out pointers.
 */
void func_0200A908(const struct IrcRankEntry *entries, u32 index, u16 *outWord, u8 *outByte, u8 *outBits, u8 *outFlag)
{
    *outWord = entries[index].profileWord;
    *outByte = entries[index].profileByte;
    *outBits = entries[index].profileBits;
    *outFlag = entries[index].profileFlag;
}


/*
 * Unlabelled Thumb leaf: low byte of the word at +0x348.
 */
u8 func_0200A930(struct IrcRankSave *rank)
{
    return rank->lastSlot;
}


int sub_0200A940(struct IrcRankSave *rank, u32 month, u32 day, struct RTCDate *today)
{
    u32 count = func_0200A8AC(rank);
    int target = func_0200AA00(month, day, today);
    int best = 0;
    u32 bestDiff = 0xffffffffu;
    u32 i;
    for (i = 0; i < count; i++) {
        int diff = func_0200A8D0(rank, i) - target;
        if (diff < 0) {
            diff = -diff;
        }
        if (bestDiff == diff) {
            u32 pick[2];
            pick[0] = (u32)best;
            pick[1] = (u32)i;
            best = (int)pick[sub_020056EC(2)];
        } else if (bestDiff > diff) {
            best = i;
            bestDiff = diff;
        }
    }
    return best;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The two helpers between func_0200A940 and func_0200AA00, both invisible
 * to the worklist: each saves registers but not lr and nothing branches to
 * either from outside, so disasm.py prints the pair as a single run of
 * `.word` (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * The 92 bytes here cover the whole gap.
 *
 * Both walk the same array of 0x1e records of 0x1c bytes that
 * func_0200A940 above them indexes, and both accept a record on the same
 * pair of tests: the u32 at +0x14 equal to the key and bit 31 of the u32
 * at +0x10 set.  The first returns bit 7 of the byte at +0x1b of the
 * matching record, the second returns 1.
 */
int sub_0200A9A4(struct IrcRankEntry *entries, u32 trainerId)
{
    int i;
    for (i = 0; i < 0x1e; i++) {
        if (entries[i].trainerId == trainerId && entries[i].isValid == 1)
            return entries[i].isNew;
    }
    return 0;
}


int sub_0200A9D4(struct IrcRankEntry *entries, u32 trainerId)
{
    int i;
    for (i = 0; i < 0x1e; i++) {
        if (entries[i].trainerId == trainerId && entries[i].isValid == 1)
            return 1;
    }
    return 0;
}


/*
 * A date interpolation: copy the caller's 16-byte date record onto the
 * stack (the `ldm/stm` pair of docs/idioms/aggregate-assignment-is-ldm-stm.md),
 * take its day number with func_0203F540, overwrite the two fields at +4 and
 * +8 with the two scalar arguments, take the day number again, and wrap the
 * difference into a year.  The tail is the fixed-point sine lookup
 * src/matched/func_0203F684.c already evidences -- the same 4096-entry signed
 * halfword table at 0x020A1B38 indexed at `2 * i`, with 30 in place of 360 --
 * scaled to a percentage: `(sin + 0x1000) * 50 >> 12`, truncated to u8.
 *
 * Two things were load-bearing and cost the run:
 *
 *  - `asrs r0, r0, #4` after the second (UNSIGNED) divide.  The division is
 *    _u32_div_f at both sites, so the expression is unsigned, but the shift
 *    is arithmetic: the quotient has to be bound to an `s32` local first.
 *    Writing the whole chain inline gives `lsrs`; making the division itself
 *    signed swaps the helper to _s32_div_f and loses the call.
 *  - `cmp r4, r0` and not `cmp r0, r4`: the guard is written `if (a >= b)`,
 *    naming the FIRST day number first.  The equivalent `if (b <= a)` is two
 *    bytes wrong (cmp operands swapped and blo becomes bhi).  This is
 *    docs/idioms/cmp-operand-order-names-the-temporary.md, and it is the same
 *    lever src/matched/func_0200ABE0.c in this family already records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA00.c \
 *       --func func_0200AA00 --addr 0x0200AA00 --cc 1.1p1 --thumb
 */
u8 func_0200AA00(u32 month, u32 day, struct RTCDate *today)
{
    struct RTCDate date = *today;
    u32 todayNum, dayNum;
    todayNum = func_0203F540(&date);
    date.month = month;
    date.day = day;
    dayNum = func_0203F540(&date);
    if (todayNum >= dayNum) {
        dayNum += 365;
    }
    {
        s32 phase = (s32)((((dayNum - todayNum) % 30) * 0xFFFF) / 30);
        return (u8)((tbl_020A1B38[2 * (phase >> 4)] + 0x1000) * 50 >> 12);
    }
}


/*
 * EXACT*: the listing extent is 196 bytes because the two unlabelled leaves
 * at 0x0200AB04 and 0x0200AB24 follow without a label; they are already
 * matched separately as src/matched/unit_0200AB04.c.  This file reproduces
 * the 154 bytes of sub_0200AA68 itself.
 *
 * The orchestrator of the family (see docs/families/mystery_data.h).  Find an
 * existing Entry with the caller's key (sub_0200ACD0), take its 10-bit
 * counter if there is one, build a fresh Entry on the stack from that counter
 * and the caller's eleven arguments (sub_0200AC14), insert it in key order
 * (sub_0200AB50) recording the slot in the low byte of the record's flag word
 * at +0x348, and if the new entry duplicates one already present
 * (sub_0200ABE0) bump every matching entry's counter (sub_0200AD00).  It
 * returns the slot back out of the flag word.
 *
 * This row was the "unfilable" one of docs/notes/pkt_0200AA00.c.txt (misfiled
 * under that name; it is about 0x0200AA68).  That note's verdict was that
 * every one of the five call sites is unwitnessed outside the compared range
 * and the row therefore caps at MATCH.  THAT IS NO LONGER TRUE, for two
 * independent reasons: all five callees are matched today, and the
 * `sole-ref/code` class introduced 2026-09-21 carries a code target that is
 * exactly a traced function start with no outside-branch requirement, which
 * is precisely the single-caller-callee shape here.  All five sites now
 * resolve as `sole-ref`, and the row is EXACT* rather than MATCH.
 *
 * Three declaration-level levers, none of them a statement shape:
 *
 *  1. sub_0200AC14 takes EIGHT SEPARATE SCALAR PARAMETERS, not one 0x20-byte
 *     struct by value (see the header of src/matched/func_0200AC14.c, which
 *     this wave re-read the same way).  Passing a struct makes this caller
 *     emit an ldm/stm block copy where the original stores each field into
 *     its own outgoing word with `str`; the scalar form is what produces the
 *     `ldrb r1, [r0, #4] / str r1, [sp, #8]` ladder at +0x28..+0x48.
 *  2. `a2` is u16, not u32.  This is the one the permuter found:
 *       --mode hill --budget 800 --types, 189 single mutations tried,
 *       191st compile: type:p(a2:u32->u16), 74 concrete bytes out -> 46,
 *       and it aligned the whole first 0x5C bytes of the function.
 *     Nothing about the disassembly says a2 is narrow directly; it says so
 *     only through the register allocation downstream of it, which is exactly
 *     the residue class permuter.py exists for.
 *  3. The +0x348 flag word is read and written as an 8-bit BITFIELD, not
 *     masked by hand.  `((Flags *)&r->f348)->b0 = sub_0200AB50(...)` gives
 *     the interleaved `lsls r0, #0x18 / ... / lsrs r0, #0x18 / orrs r0, r2`
 *     the original has; the hand-written `r->f348 = (r->f348 & ~0xff) | slot`
 *     hoists the truncation out of the mask work and is 4 bytes short.  The
 *     read at the end needs the same bitfield, which is where the SECOND
 *     `lsls #0x18 / lsrs #0x18` pair at +0x92 comes from -- a plain
 *     `(u8)(r->f348 & 0xff)` folds the two pairs into one.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA68.c \
 *       --func sub_0200AA68 --addr 0x0200AA68 --cc 1.1p1 --thumb
 */
u8 sub_0200AA68(struct IrcRankSave *rank, const void *name, u16 score, u8 gender,
                u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag)
{
    struct IrcRankEntry entry;
    struct IrcRankEntry *known;
    u16 meetCount = 0;
    known = func_0200ACD0(rank->entries, 30, trainerId);
    if (known != 0) {
        meetCount = known->meetCount;
    }
    sub_0200AC14(&entry, name, score, meetCount, gender, language, version, trainerId, profileWord, profileByte, profileBits, profileFlag);
    {
    rank->lastSlot = func_0200AB50(rank->entries, 30, &entry);
    }
    if (func_0200ABE0(rank->entries, 30, &entry) != 0) {
        sub_0200AD00(rank->entries, 30, &entry);
    }
    {
        u8 slot = rank->lastSlot;
        return slot;
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Two unlabelled leaves at the end of the packet, after func_0200AA68:
 * `push {r4, r5}` with no lr for the first, nothing at all for the second,
 * so both print as `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The first clears bit 7 of the byte at +0x1b of each of the same 0x1e
 * records of 0x1c bytes the two helpers at 0x0200A9A4 index (that byte's
 * bit 7 is the flag sub_0200A9A4 returns); the second is a four-byte
 * constant getter for 0x34c, which Thumb spells `movs r0, #0xd3; lsls
 * r0, r0, #2`.
 */
void sub_0200AB04(struct IrcRankEntry *entries)
{
    int i;
    for (i = 0; i < 0x1e; i++)
        entries[i].isNew = 0;
}


int sub_0200AB24(void)
{
    return sizeof(struct IrcRankSave);
}


void func_0200AB2C(struct IrcRankSave *rank)
{
    MI_CpuFill8(rank, 0, sizeof(struct IrcRankSave));
    rank->lastSlot = 0x7f;
}


u8 func_0200AB50(struct IrcRankEntry *list, s32 count, struct IrcRankEntry *entry)
{
    s32 i;
    s32 slot = -1;
    s32 k;
    for (i = 0; i < count; i++) {
        if (list[i].isValid != 0) {
            if (list[i].score > entry->score) continue;
        }
        slot = i;
        break;
    }
    if (slot == -1) return 0xff;
    for (k = count - 1; k > slot; k--) {
        if (list[k].meetCount != 0 || list[k - 1].meetCount != 0) MI_CpuCopy8(&list[k - 1], &list[k], sizeof(struct IrcRankEntry));
    }
    MI_CpuCopy8(entry, &list[slot], sizeof(struct IrcRankEntry));
    return slot;
}


/*
 * The comparison has to be written with the *caller's* object on the left
 * (`*(u32 *)(b + 0x14) == *(u32 *)(p + 0x14)`): both sides are loads, and the
 * one the source names first is the one that lands in `cmp`'s left slot, so
 * swapping them is one byte (`cmp r2, r5` against `cmp r5, r2`).  Leaving the
 * invariant load in the condition rather than hoisting it into a local is
 * also load-bearing: as a local it is materialised before the `n <= 0` guard
 * and the entry test moves.  EXACT*: the 2-byte linker filler at 0x0200AC12
 * is inside the packet but the listing extent runs to the next label.
 */
int func_0200ABE0(struct IrcRankEntry *list, int count, struct IrcRankEntry *entry)
{
    int i;
    for (i = 0; i < count; i++) {
        struct IrcRankEntry *other = &list[i];
        if (entry->trainerId == other->trainerId && other->isValid == 1)
            return 1;
    }
    return 0;
}


/*
 * The Entry constructor of the family (see docs/families/mystery_data.h):
 * clear the 0x1C-byte record, copy 8 halfwords from `src` into the first
 * 16 bytes with sub_0201F41C, then fill the packed word at +0x10, the key at
 * +0x14, the halfword at +0x18, the byte at +0x1A and the two bit-packed
 * fields of +0x1B, and finally set the top bit of +0x10 and bit 7 of +0x1B.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AC14.c.txt had this row at DIFF
 * with three independent residue groups, "no recoverable source in this note"
 * on the 2026-09-21 re-verify).  The note read the eight stack words at
 * sp+0x18..sp+0x34 as ONE 0x20-byte parameter block passed BY VALUE, because
 * the function takes its address once (`add r0, sp, #0x18`) and then reads
 * fields off it with `ldrb r1, [r0, #4]`, `ldrh r1, [r0, #0xc]` and so on.
 * That reading is wrong, and it is what produced all three residues.
 *
 * They are EIGHT SEPARATE SCALAR PARAMETERS of narrow types:
 *
 *     u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7
 *
 * Each occupies its own word of the incoming argument area (the ABI passes
 * every stack argument in a word slot regardless of width), so the OFFSETS
 * are identical to the struct reading and the disassembly cannot tell the two
 * apart by offset alone.  What tells them apart is the LOAD WIDTH: a struct
 * member of declared type u8 and a u8 parameter both read `ldrb`, but only
 * the scalar form lets the compiler base every one of them off a single
 * `add r0, sp, #0x18` while keeping p3 as a plain `ldr r0, [sp, #0x24]`
 * scheduled ahead of the +0x10 store -- which is residue 1 of the note,
 * unreachable from the struct form.  Residues 2 and 3 fall out with it: the
 * a3 insert accumulates into the keep register and the bit-6 insert keeps its
 * explicit `& 1` and `(u8)` cast, both of which the struct form folded.
 *
 * The permuter confirms the struct form is a dead end rather than a spelling
 * problem: on the 188-byte, 10-concrete-bytes-out struct version,
 *   --mode hill  --budget 800  --types: 158 single mutations, no improvement
 *   --mode anneal --budget 3000 --types: 3000 compiles in 204s, completely
 *   flat at asm=400 bytes-out=10 the whole way, never once leaving the
 *   plateau.
 * A residue no mutation of the statement shape can reach is a residue in the
 * DECLARATIONS, and re-reading the parameter list was what closed it.
 *
 * The bitfield widths of Self are the ones src/matched/unit_0200A864.c
 * already evidences for this family's Entry record (7 / 10 / 1 at +0x10,
 * 6 / 1 / 1 at +0x1B); the four extra sub-fields between them (4 / 4 / 5)
 * are read off this function's own mask pool words 0xFFFDFFFF, 0xFFC3FFFF
 * and 0xFC3FFFFF at 0x0200ACC0..0x0200ACCC.
 *
 * The top bit at the end must be written `(f10 & 0x7FFFFFFF) | 0x80000000`
 * -- which is what the `b6 : 1` bitfield assignment compiles to -- and not
 * `f10 |= 0x80000000`, which loses the `ldr r0, =0x7FFFFFFF / adds r0, r0, #1`
 * pair at +0x96.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AC14.c \
 *       --func sub_0200AC14 --addr 0x0200AC14 --cc 1.1p1 --thumb
 */
void sub_0200AC14(struct IrcRankEntry *entry, const void *name, u32 score, u32 meetCount,
                  u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag)
{
    MI_CpuFill8(entry, 0, sizeof(struct IrcRankEntry));
    sub_0201F41C(name, entry->name, 8);
    entry->score = score;
    entry->trainerId = trainerId;
    entry->gender = gender;
    entry->language = language;
    entry->version = version;
    entry->meetCount = meetCount;
    entry->profileWord = profileWord;
    entry->profileByte = profileByte;
    entry->profileBits = profileBits;
    entry->profileFlag = (u8)(profileFlag & 1u);
    entry->isValid = 1;
    entry->isNew = 1;
}


struct IrcRankEntry *func_0200ACD0(struct IrcRankEntry *list, int count, int trainerId)
{
    int i;
    for (i = 0; i < count; i++) {
        struct IrcRankEntry *other = &list[i];
        if (trainerId == other->trainerId) {
            if (other->isValid == 1)
                return other;
        }
    }
    return 0;
}


/*
 * EXACT*: the listing extent runs to 156 bytes because the function at
 * 0x0200AD6C that follows saves nothing and therefore carries no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); this file
 * reproduces the 108 bytes of sub_0200AD00 itself, code and both pool words.
 * The unlabelled follower at 0x0200AD6C should be seeded into
 * layout/function_starts.txt by the integrator.
 *
 * Another linear scan over the family's 0x1C-byte Entry records (see
 * docs/families/mystery_data.h): for every entry whose u32 at +0x14 matches
 * the reference's, bump the 10-bit counter at bit 7 of the packed word at
 * +0x10, set bit 7 of the byte at +0x1B, and clamp the counter to 999.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AD00.c.txt had this row at DIFF,
 * 104 bytes against 156, 94 concrete bytes out -- effectively a whole-function
 * mismatch).  The note's C did the field access by hand:
 *
 *     v = *(u32 *)(e + 0x10);
 *     *(u32 *)(e + 0x10) = (v & 0xfffe007fu) | ((((v >> 7) & 0x3ff) + 1) << 7);
 *
 * which compiles to `lsrs #7; ands <0x3ff>` for the read and a pool word for
 * the 0x3FF, three instructions and a constant the original never
 * materialises.  The original reads the field as `lsls #0xf / lsrs #0x16` and
 * writes it back as `lsls #0x16 / lsrs #0xf`: an EQUAL-width shift pair with
 * no matching type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md -- a 10-bit
 * unsigned BITFIELD at bit 7, not a hand-rolled mask.  Declaring the whole
 * packed word as the `struct Entry` bitfields the family header already
 * evidences (func_0200A8D0/A8E4/A8F8 in src/matched/unit_0200A864.c prove the
 * 7/10/1 widths) takes the row from 94 concrete bytes out to 2 in one edit,
 * and also drops the lr push: the hand-written version needed a spill the
 * bitfield form does not.
 *
 * The last two bytes were the operand order of the guard.  Both sides are
 * loads, and the side the SOURCE names first lands in the left register:
 * `ref->unk14 != e->unk14` gives `ldr r2, [r6, #0x14]` then `ldr r1, [r5,
 * #0x14]`, and the natural-reading `e->unk14 != ref->unk14` gives them the
 * other way round.  This is docs/idioms/cmp-operand-order-names-the-temporary.md
 * and it is the THIRD function in this family to turn on it
 * (src/matched/func_0200ABE0.c and src/matched/func_0200AA00.c are the others).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AD00.c \
 *       --func sub_0200AD00 --addr 0x0200AD00 --cc 1.1p1 --thumb
 */
void sub_0200AD00(struct IrcRankEntry *list, int total, struct IrcRankEntry *entry)
{
    int i;
    for (i = 0; i < total; i++) {
        struct IrcRankEntry *other = &list[i];
        u32 count;
        if (entry->trainerId != other->trainerId) {
            continue;
        }
        other->meetCount = other->meetCount + 1;
        other->isNew = 1;
        count = other->meetCount;
        if (count > 999) {
            count = 999;
        }
        other->meetCount = count;
    }
}


/*
 * Save-block getter for block 0x2E, the same one-line shape as
 * func_0200A864 / func_0200A8A0 (blocks 0x2B, 0x2C) in unit_0200A864.c:
 * a tail call through the pool with the id in r1.
 */
struct WorldTradeData *func_0200AD6C(struct SaveControl *save)
{
    return func_020071CC(save, 0x2e);
}


/*
 * note:     wave 17 lane untried_small: return 0xF8 (the size of a 0xF8-byte record); listing extent runs over the unlabelled neighbours 0x0200AD7C, 0x0200AD8C, 0x0200AD94.
 */
int func_0200AD78(void)
{
    return sizeof(struct WorldTradeData);
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower of func_0200AD78; clears a 0xF8-byte record with func_02082AC0 (tail call).
 */
void func_0200AD7C(struct WorldTradeData *trade)
{
    MIi_CpuClearFast(0, trade, sizeof(struct WorldTradeData));
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower; getter of the u16 at +0xEC (extent includes two bytes of padding).
 */
u16 func_0200AD8C(const struct WorldTradeData *trade)
{
    return trade->isDeposited;
}


/*
 * note:     wave 18 lane ties_b: unlabelled follower; setter of the u16 at +0xEC (extent includes two bytes of padding).
 */
void func_0200AD94(struct WorldTradeData *trade, u16 isDeposited)
{
    trade->isDeposited = isDeposited;
}


void func_0200AD9C(struct WorldTradeData *trade, void *outPokemon)
{
    u32 size = func_020173EC();
    MI_CpuCopy8(trade, outPokemon, size);
}


/*
 * Unlabelled Thumb leaf in the ARM9 module: an empty `bx lr` body.
 *
 * Addresses are Black-image addresses.
 */
void func_0200ADB4(void)
{
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200ADE8, func_0200ADF0, func_0200AE08, func_0200AE14,
 *           func_0200AE18, func_0200AE3C, func_0200AE54, func_0200AEE8,
 *           func_0200AFD4, func_0200B040, func_0200B074, func_0200B078,
 *           func_0200B110, func_0200B1A8, func_0200B1C4, func_0200B1D4,
 *           func_0200B1E0, func_0200B1F8, func_0200B204, func_0200B214,
 *           func_0200B254
 *
 * alias: the original source file is named in the image.  The constructor at
 * 0x0200ADF0 passes 0x020A71B4 to the debug allocator at 0x02030734, and the
 * bytes there spell "regulation.c"; the string before it is
 * "mystery_data.c", which is what the `string` attestation class uses to fix
 * the address without reading the pool word under test.  That makes this the
 * second original source file name this project has recovered, after
 * "playtime.c".  The functions keep their func_<address> names, because the
 * file identity is attested and the individual entry points are not.
 *
 * 1260 bytes, 0x0200ADB8..0x0200B2A4, 25 functions, eleven of which carry no
 * label in the generated listing.
 *
 * What a regulation is, read off the accessors: a 0xBC-byte record of
 * battle-rule settings.  The pair at 0x0200AE54 and 0x0200AEE8 is its whole
 * scalar interface, a get and a set indexed by a rule id in 0..22, and the
 * set carries the legal range of every rule: ids 0 to 3 take a value under 7,
 * 6 and 6 and 6; id 4 is capped at 100; id 6 at 600; ids 7, 8, 13, 17 and 19
 * are booleans; id 11 is a u16 under 651; id 20 is capped at 99.  Ids 9, 10
 * and 14 are missing from both tables because they are not scalars: they are
 * the three bitmaps at +0x0A, +0x5C and +0xAC that func_0200AFD4 tests a bit
 * of.  A second pair at 0x0200B078 and 0x0200B110 does the same job for a
 * larger record that contains this one at offset 0, over ids 1..12 and a set
 * of signed fields at 0x152..0x15D.  0x0200B1A8 checks the record against the
 * checksum stored at +0x15E.
 *
 * Four things here are worth naming:
 *
 *  - a dense switch becomes a PC-relative halfword jump table, and the whole
 *    of it, table included, comes out of ordinary C.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The table
 *    is what reads the case list back: an entry pointing at the common exit
 *    is a case that is absent from the source, which is how ids 9, 10 and 14
 *    above are known to be missing rather than empty.
 *  - func_0200B078 falls off the end of its switch with no return statement,
 *    and the original's default arm is a bare `bx lr` that returns the
 *    incoming pointer.  Adding a `return 0;` to make the C well-formed adds
 *    an instruction and moves every case body.
 *  - a 0x160-byte struct assignment is an inline eight-byte `ldm`/`stm` loop
 *    rather than a call, but only when the struct is four-aligned; declared
 *    as a `u8` array it is a byte loop instead.  See
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *  - `p->unk12 >> n` on a `u8` field is an *arithmetic* shift, because the
 *    field promotes to `int` before the shift.  Writing the field as `u32`,
 *    or casting, gives `lsrs` and two bytes wrong in func_0200B214.
 */
void func_0200ADB8(struct WorldTradeData *trade, const void *pokemon, u32 boxPos)
{
    MI_CpuCopy8(pokemon, trade, func_020173EC());
}


void func_0200ADD0(struct WorldTradeData *trade, u32 tradeId)
{
    trade->lastTradeId = tradeId;
}


void func_0200ADD8(struct WorldTradeData *trade, u32 searchId)
{
    trade->lastSearchId = searchId;
}


u16 func_0200ADE0(struct WorldTradeData *trade)
{
    return trade->returnBox;
}


u32 func_0200ADE8(void)
{
    return sizeof(struct BattleCompetitionSave);
}


struct Regulation *func_0200ADF0(u32 heapId)
{
    return func_02030734(heapId, sizeof(struct Regulation), 1, func_0200ADF0_File,
                         0x73);
}


void func_0200AE08(const struct Regulation *src, struct Regulation *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Regulation));
}


void func_0200AE14(void)
{
}


void func_0200AE18(struct Regulation *rule, void *dest)
{
    struct MsgBank *bank = func_02045B38(0, 2, 0xA6, 1);
    func_02045CAC(bank, rule->cupNo, dest);
    func_02045C04(bank);
}


void *func_0200AE3C(struct Regulation *rule, u32 heapId)
{
    void *name = func_020457B0(0x1A, heapId);
    func_0200AE18(rule, name);
    return name;
}


u32 func_0200AE54(struct Regulation *rule, u32 id)
{
    u32 value = 0;
    switch (id) {
    case 0:  value = rule->cupNo; break;
    case 1:  value = rule->ruleNo; break;
    case 2:  value = rule->numLo; break;
    case 3:  value = rule->numHi; break;
    case 4:  value = rule->level; break;
    case 5:  value = rule->levelRange; break;
    case 6:  value = rule->levelTotal; break;
    case 7:  value = rule->bothPoke; break;
    case 8:  value = rule->bothItem; break;
    case 11: value = rule->mustPoke; break;
    case 12: value = rule->mustPokeForm; break;
    case 13: value = rule->shooter; break;
    case 15: value = rule->timeVs; break;
    case 16: value = rule->timeCommand; break;
    case 17: value = rule->nickname; break;
    case 18: value = rule->cameraMode; break;
    case 19: value = rule->showPoke; break;
    case 20: value = rule->showPokeTime; break;
    case 21: value = rule->battleType; break;
    case 22: value = rule->battleCount; break;
    }
    return value;
}


void func_0200AEE8(struct Regulation *rule, u32 id, s32 value)
{
    switch (id) {
    case 0:  if (value < 7)     { rule->cupNo = value; } break;
    case 1:  if (value < 6)     { rule->ruleNo = value; } break;
    case 2:  if (value < 6)     { rule->numLo = value; } break;
    case 3:  if (value < 6)     { rule->numHi = value; } break;
    case 4:  if (value <= 100)  { rule->level = value; } break;
    case 5:  if (value <= 6)    { rule->levelRange = value; } break;
    case 6:  if (value <= 600)  { rule->levelTotal = value; } break;
    case 7:  if (value < 2)     { rule->bothPoke = value; } break;
    case 8:  if (value < 2)     { rule->bothItem = value; } break;
    case 11: if (value < 0x28B) { rule->mustPoke = value; } break;
    case 12: rule->mustPokeForm = value; break;
    case 13: if (value < 2)     { rule->shooter = value; } break;
    case 15: rule->timeVs = value; break;
    case 16: rule->timeCommand = value; break;
    case 17: if (value < 2)     { rule->nickname = value; } break;
    case 18: rule->cameraMode = value; break;
    case 19: if (value < 2)     { rule->showPoke = value; } break;
    case 20: if (value <= 0x63) { rule->showPokeTime = value; } break;
    case 21: if (value < 6)     { rule->battleType = value; } break;
    case 22: rule->battleCount = value; break;
    }
}


u32 func_0200AFD4(struct Regulation *rule, u32 id, s32 bit)
{
    s32 byte = bit / 8;
    s32 shift = bit % 8;
    switch (id) {
    case 9:
        if (rule->vetoPokeBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    case 10:
        if (rule->vetoItemBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    case 14:
        if (rule->vetoShooterBit[byte] & (1 << shift)) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_0200B040(struct Regulation *rule, struct ShooterSettings *out)
{
    MI_CpuFill8(out, 0, sizeof(struct ShooterSettings));
    out->isEnabled = func_0200AE54(rule, 13);
    if (out->isEnabled >= 2) {
        out->isEnabled = 1;
    }
    MI_CpuCopy8(rule->vetoShooterBit, out, 7);
}


u8 *func_0200B074(struct RegulationCard *card)
{
    return card->cupName;
}


s32 func_0200B078(struct RegulationCard *card, u32 id)
{
    switch (id) {
    case 1:  return card->cupId;
    case 2:  return card->romVersion;
    case 3:  return card->startYear;
    case 4:  return card->startMonth;
    case 5:  return card->startDay;
    case 6:  return card->endYear;
    case 7:  return card->endMonth;
    case 8:  return card->endDay;
    case 9:  return card->status;
    case 10: return card->bgm;
    case 11: return card->sameMatch;
    case 12: return card->cardType;
    }
}


void func_0200B110(struct RegulationCard *card, u32 id, s32 value)
{
    switch (id) {
    case 1:  card->cupId      = value; break;
    case 2:  card->romVersion = value; break;
    case 3:  card->startYear  = value; break;
    case 4:  card->startMonth = value; break;
    case 5:  card->startDay   = value; break;
    case 6:  card->endYear    = value; break;
    case 7:  card->endMonth   = value; break;
    case 8:  card->endDay     = value; break;
    case 9:  card->status     = value; break;
    case 10: card->bgm        = value; break;
    case 11: card->sameMatch  = value; break;
    case 12: card->cardType   = value; break;
    }
}


u32 func_0200B1A8(struct RegulationCard *card)
{
    if (card->crc == func_0200B1C4(card)) {
        return 1;
    }
    return 0;
}


u16 func_0200B1C4(struct RegulationCard *card)
{
    return func_0203F1FC(card, 0x15E);
}


struct RegulationCard *func_0200B1D4(struct RegulationCard *cards, u32 index)
{
    return &cards[index];
}


void func_0200B1E0(struct RegulationCard *cards, u32 index, const struct RegulationCard *src)
{
    cards[index] = *src;
}


void func_0200B1F8(struct RegulationParty *party)
{
    MI_CpuFill8(party, 0, sizeof(struct RegulationParty));
}


struct RegulationParty *func_0200B204(struct BattleCompetitionSave *competition, u32 index)
{
    return &competition->parties[index];
}


s32 func_0200B214(struct RegulationParty *party, u32 id, u8 member)
{
    switch (id) {
    case 0: return party->monsNo[member];
    case 1: return party->formNo[member];
    case 2: return (party->hasItemBits >> member) & 1;
    case 3: return (party->femaleBits >> member) & 1;
    }
    return 0;
}


void func_0200B254(struct RegulationParty *party, int id, u8 member, s32 value)
{
    switch (id) {
    case 0: party->monsNo[member] = value; break;
    case 1: party->formNo[member] = value; break;
    case 2: party->hasItemBits |= (u8)((value == 1) << member); break;
    case 3: party->femaleBits |= (u8)((value == 1) << member); break;
    }
}
