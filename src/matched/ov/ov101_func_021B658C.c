/*
 * function: COMPATIBLE_IRC_SYS_BuildProfile
 * address: 0x021B658C
 * packet: pkt_ov101_021B658C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pack the words with unsigned left/right shift pairs; u8 casts
 *   keep separate truncation shifts and add eight bytes.
 * symbols:
 *   OS_GetOwnerInfo 0x02087C88 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; unsigned char low:4; unsigned char high:4; u8 tail[32]; } Data;
typedef struct Config { u8 bytes[0x54]; } Config;
typedef struct Four { int a,b,c,d; } Four;
struct OSOwnerInfo;
struct RtcDate;
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *,void *);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
void COMPATIBLE_IRC_SYS_BuildProfile(void *p,Data *out)
{
    Config config;
    Four four;
    void *sub;
    void *record;
    int flag;
    OS_GetOwnerInfo((struct OSOwnerInfo *)(&config));
    sub=GAMESYSTEM_GetGameData(p);
    p=GAME_DATA_GetMyStatus(sub);
    out->f04=config.bytes[2];
    out->f05=config.bytes[3];
    MYSTATUS_Copy(p,out->tail);
    record=POKEPARTY_GetMember(GAME_DATA_GetMyParty(sub),0);
    flag=0;
    out->f06=POKE_TOOL_GetPartyValue(record,5,0);
    out->f08=POKE_TOOL_GetPartyValue(record,111,0);
    out->f09=POKE_TOOL_GetPartyValue(record,110,0);
    out->f0a=POKE_TOOL_GetPartyValue(record,76,0);
    GF_STANDARD_GetCachedDate((struct RtcDate *)(&four));
    if(four.c == 14) flag=1;
    out->low=(u8)flag;
    out->f00=((u32)four.a << 24) | (((u32)four.b << 24) >> 8) | (((u32)four.c << 24) >> 16) | four.d;
}
