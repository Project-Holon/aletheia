/*
 * file:     btl_main.c
 * unit:     yes
 * function: func_021B6100, func_021B6434, func_021B64CC, func_021B6500, func_021B66D4, func_021B6804, func_021B6818, func_021B6848, func_021B68D8, func_021B6954, func_021B6994, func_021B69FC, func_021B6A3C, func_021B6A70, func_021B6AAC, func_021B6C08, func_021B6C5C, func_021B6DD0, func_021B7050, func_021B71D4, func_021B734C, func_021B73C4, func_021B7488, func_021B7518, func_021B75A8, func_021B7758, func_021B7968, func_021B7BB0, func_021B7CB4, func_021B7E18, func_021B8070, func_021B81DC, func_021B835C, func_021B83F4, func_021B8434, func_021B84D8, func_021B8548, func_021B8564, func_021B8588, func_021B8590, func_021B85A0, func_021B85A8, func_021B85DC, func_021B85EC, func_021B8630, func_021B8640, func_021B8670, func_021B86A0, func_021B86B8, func_021B86C0, func_021B86C8, func_021B86DC, func_021B86E4, func_021B8714, func_021B871C, func_021B8724, func_021B873C, func_021B8748, func_021B8750, func_021B8778, func_021B87E8, func_021B8834, func_021B88EC, func_021B8B78, func_021B8B9C, func_021B8BC4, func_021B8BD0, func_021B8BEC, func_021B8C20, func_021B8C38, func_021B8C50, func_021B8C5C
 * address:  0x021B6100
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Battle main module (BTL_MAIN; the file name is a guess, no __FILE__ string before btl_server.c).
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_021E8DC4 0x021E8DC4 thumb ov093
 *   func_021E88CC 0x021E88CC thumb ov093
 *   GFL_USE_IsMuteHookActive 0x020057C4 thumb
 *   GFL_USE_SetSleepVolumeHooks 0x020057AC thumb
 *   CONFIG_GetTextSpeed 0x02008374 thumb
 *   CONFIG_GetBattleScene 0x020083AC thumb
 *   CONFIG_GetBattleStyle 0x020083C8 thumb
 *   func_021EF958 0x021EF958 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021BA82C 0x021BA82C thumb ov093
 *   func_0203F258 0x0203F258 arm
 *   func_021D7840 0x021D7840 thumb ov093
 *   func_021CD6EC 0x021CD6EC thumb ov093
 *   func_021D7F88 0x021D7F88 thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D4150 0x021D4150 thumb ov093
 *   func_021D804C 0x021D804C thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4230 0x021D4230 thumb ov093
 *   func_021EEA30 0x021EEA30 thumb ov093
 *   func_021B9DB8 0x021B9DB8 thumb ov093
 *   func_021BA094 0x021BA094 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B9114 0x021B9114 thumb ov093
 *   func_021BA54C 0x021BA54C thumb ov093
 *   func_021BA6C0 0x021BA6C0 thumb ov093
 *   func_021BA878 0x021BA878 thumb ov093
 *   func_021BA2E4 0x021BA2E4 thumb ov093
 *   func_021EE894 0x021EE894 thumb ov093
 *   func_0207D55C 0x0207D55C arm
 *   func_0207D534 0x0207D534 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   func_021EF980 0x021EF980 thumb ov093
 *   func_021D4D5C 0x021D4D5C thumb ov093
 *   func_021D7894 0x021D7894 thumb ov093
 *   func_021BA0CC 0x021BA0CC thumb ov093
 *   func_021B9DE8 0x021B9DE8 thumb ov093
 *   func_021EEA54 0x021EEA54 thumb ov093
 *   func_021D4254 0x021D4254 thumb ov093
 *   func_021D8058 0x021D8058 thumb ov093
 *   func_021E8DF8 0x021E8DF8 thumb ov093
 *   func_021E88F8 0x021E88F8 thumb ov093
 *   func_02012EBC 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007C20 0x02007C20 thumb
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021BA710 0x021BA710 thumb ov093
 *   func_021BA128 0x021BA128 thumb ov093
 *   func_021B9E7C 0x021B9E7C thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 *   func_021E8F20 0x021E8F20 thumb ov093
 *   func_021CD95C 0x021CD95C thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021E9034 0x021E9034 thumb ov093
 *   func_021CD8E0 0x021CD8E0 thumb ov093
 *   func_021B9674 0x021B9674 thumb ov093
 *   func_021BAB5C 0x021BAB5C thumb ov093
 *   d_021EFD1C 0x021EFD1C data a4
 *   d_021EFD00 0x021EFD00 data a4
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb arm9
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb arm9
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb arm9
 *   GFL_USE_IsBgmFading 0x02005E50 thumb arm9
 *   RINGTONE_SYS_RegisterSleepCallbacks 0x02029F6C thumb arm9
 *   d_021EFD38 0x021EFD38 data a4
 *   d_021EFD54 0x021EFD54 data a4
 *   func_021D4294 0x021D4294 thumb ov093
 *   func_021D4348 0x021D4348 thumb ov093
 *   func_021D4360 0x021D4360 thumb ov093
 *   func_021D4378 0x021D4378 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D43B8 0x021D43B8 thumb ov093
 *   func_021D440C 0x021D440C thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D4438 0x021D4438 thumb ov093
 *   func_021D44CC 0x021D44CC thumb ov093
 *   func_021D4D24 0x021D4D24 thumb ov093
 *   func_021D4D64 0x021D4D64 thumb ov093
 *   func_021D4680 0x021D4680 thumb ov093
 *   func_021D4784 0x021D4784 thumb ov093
 *   func_021D47A4 0x021D47A4 thumb ov093
 *   func_021D4800 0x021D4800 thumb ov093
 *   func_021BA648 0x021BA648 thumb ov093
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_021D4808 0x021D4808 thumb ov093
 *   func_021D4898 0x021D4898 thumb ov093
 *   func_021D48CC 0x021D48CC thumb ov093
 *   func_021D4908 0x021D4908 thumb ov093
 *   func_021D49B0 0x021D49B0 thumb ov093
 *   func_021D49CC 0x021D49CC thumb ov093
 *   func_021D49E0 0x021D49E0 thumb ov093
 *   func_021D4A04 0x021D4A04 thumb ov093
 *   func_021B9EF0 0x021B9EF0 thumb ov093
 *   func_021BA670 0x021BA670 thumb ov093
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_020084D4 0x020084D4 thumb
 *   func_021D4500 0x021D4500 thumb ov093
 *   func_021D450C 0x021D450C thumb ov093
 *   func_021D45FC 0x021D45FC thumb ov093
 *   func_021D4648 0x021D4648 thumb ov093
 *   func_021D4674 0x021D4674 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021BA698 0x021BA698 thumb ov093
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021BAB9C 0x021BAB9C thumb ov093
 *   func_021CD97C 0x021CD97C thumb ov093
 *   func_021CDD94 0x021CDD94 thumb ov093
 *   func_021E908C 0x021E908C thumb ov093
 *   func_021BABDC 0x021BABDC thumb ov093
 *   func_021CD914 0x021CD914 thumb ov093
 *   func_02013080 0x02013080 thumb
 *   ov231_id 0x000000E7 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021809D8 0x021809D8 thumb ov231
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CF28 0x0200CF28 thumb
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_021B8CB0 0x021B8CB0 thumb ov093
 *   func_021B99F0 0x021B99F0 thumb ov093
 */
#include "btl_main_types.h"


#define REG_MASTER_BRIGHT_A 0x0400006C
#define REG_MASTER_BRIGHT_B 0x0400106C

struct PerapVoice;
struct MsgBank;
struct U16Vec;
struct GameData;
struct Config;
struct Party;

/* The proc instance: the work object allocated for it hangs off the end of the header. */
struct ProcHandle
{
  u32 header[5];
  void *work;
};


/*
 * Battle main work helpers: client and position arithmetic.
 *
 * Position ids: bit 0 is the side (0 = player side, 1 = enemy side) and
 * bits 1.. are the lane on that side (0..2). A client id follows the same
 * rule: bit 0 is the side of the client.
 */

extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct ProcHandle *proc, u32 size, u32 heapId);
extern void func_02082A7C(u32, void *, u32);
extern void func_021E8DC4(unsigned short heapId);
extern void func_021E88CC(void);
extern int GFL_USE_IsMuteHookActive(void);
extern void GFL_USE_SetSleepVolumeHooks(void);
extern u32 CONFIG_GetTextSpeed(struct Config *config);
extern u32 CONFIG_GetBattleScene(struct Config *config);
extern u32 CONFIG_GetBattleStyle(struct Config *config);
extern struct BtlField *func_021EF958(u32 heapId);
extern void func_021B93E0(struct BtlSide *side, struct BtlMain *main, u32 sideIndex);
extern void func_021BA82C(struct BattleSetupParam *setup);
extern void func_0203F258(struct BattleRngState *rng);
extern void func_021D7840(struct BattleRngState *rng, u32 heapId);
extern void func_021CD6EC(void);
extern u32 func_021D7F88(struct BattleSetupParam *setup);
extern void func_021D8230(struct BtlClientSet *set);
extern void func_021D4150(unsigned int netHandle, u16 mask, u16 heapId);
extern void func_021D804C(u32 heapId);
extern int func_021D4270(void);
extern int func_021D4230(void);
extern void func_021EEA30(int commPos);
extern void func_021B9DB8(struct BtlMain *main);
extern void func_021BA094(struct BtlMain *main);
extern void func_021BA1B4(struct BtlMain *main, int arg);
extern u8 func_021B9114(struct BtlMain *main);
extern int func_021BA54C(struct BtlMain *main);
extern void func_021BA6C0(struct BtlMain *main);
extern void func_021BA878(struct BtlMain *main);
extern void func_021BA2E4(struct BtlMain *main);
extern int func_021EE894(void *reader, u8 client);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0207D534(volatile u16 *reg, int level);
extern void func_021EF980(struct BtlField *field);
extern u32 func_020307B0(void *p);
extern void func_021D4D5C(void *p);
extern void func_021D7894(void);
extern void func_021BA0CC(struct BtlMain *main);
extern void func_021B9DE8(struct BtlMain *main);
extern void func_021EEA54(void);
extern void func_021D4254(void);
extern void func_021D8058(void);
extern void func_021E8DF8(void);
extern void GFL_USE_SetPlayersAudible(int, u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern void RINGTONE_SYS_RegisterSleepCallbacks(void);
extern void func_020315D4(struct ProcHandle *proc);
extern void func_020306F0(unsigned int);
extern void func_021E88F8(void);
extern void *func_02012EBC(struct GameData *gameData);
extern const struct PerapVoice *func_02007B44(void *sys);
extern struct PerapVoice *func_02007B20(u32 heapId);
extern void func_02007C20(struct PerapVoice *dest, const struct PerapVoice *src);
extern int func_021B997C(struct BtlMain *main, unsigned int client);
extern u8 func_021BA710(int ownClient, int client);
extern void func_021BA128(struct BtlMain *main, int client, struct Party *party);
extern void func_021B9E7C(struct BtlTrainerSlot *slot, struct BattleTrainerData *trainer);
extern void func_021B9E38(struct BtlTrainerSlot *slot, int heapId, void *playerStatus);
extern u32 func_0201AA18(void *party);
extern void func_021EE644(void *reader, void *recordBuffer, int size);
extern void func_021CD938(struct BtlClient *client, void *reader);
extern struct BtlvCore *func_021E8F20(struct BtlMain *main, struct BtlClient *client, struct BtlSide *side, int isComm, u16 heapId);
extern void func_021CD95C(struct BtlClient *client, struct BtlvCore *viewCore);
extern void func_021B9460(struct BtlSide *side, struct BtlMain *main, u8 slot);
extern struct BtlServer *func_021BA9C8(struct BtlMain *main, struct BattleRngState *rng, struct BtlSide *side, int isComm, u16 heapId);
extern struct BtlClient *func_021CD6F0(struct BtlMain *main, struct BtlSide *side, int unused, int netHandle, u16 clientId, u16 slotCount, u8 isOpponent, int isComm, int ownsSlots, struct BattleRngState *rng, u16 heapId);
extern u32 func_021CD978(struct BtlClient *client);
extern void func_021BAA94(struct BtlServer *server, int clientRef, u8 clientId, u8 slotCount);
extern void func_021BAB40(struct BtlServer *server);
extern void func_021E9034(struct BtlvCore *viewCore);
extern void func_021CD8E0(struct BtlClient *client);
extern void func_021B9674(struct BtlSide *side);
extern void func_021BAB5C(struct BtlServer *server);
extern int (*d_021EFD38[7])(struct BtlMain *, u32 *);
extern int func_021D4294(u16 v);
extern int func_021D4348(void);
extern int func_021D4360(void);
extern u8 func_021D4378(void);
extern int func_021BA1A8(struct BtlMain *main, int mask);
extern u32 func_021D43B8(u32 a);
extern int func_021D440C(void *);
extern void func_021D4AF4(int a);
extern int func_021D4B18(int a);
extern u8 func_021D4438(u32 a);
extern int func_021D44CC(void);
extern void *func_021D4D24(u32,u16);
extern void func_021D4D64(u32 *p, const void *src, u32 a);
extern u32 func_021D4680(u32 *a);
extern int func_021D4784(u32 a);
extern void *func_021D47A4(u8);
extern void func_021D4800(void);
extern void func_021BA648(struct BtlMain *main, u8 client, void *dst);
extern int POKE_REGULATION_GetDataSize(void);
extern int func_021D4808(u32 a);
extern int func_021D4898(void);
extern void *func_021D48CC(u8);
extern u32 func_021D4908(void *);
extern int func_021D49B0(void);
extern void *func_021D49CC(void);
extern void func_021D49E0(void);
extern void func_021D4A04(void);
extern void func_021B9EF0(struct BtlTrainerSlot *slot, const void *src);
extern void func_021BA670(struct BtlMain *main, u8 client, void *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(void *bank);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_021D4500(void);
extern u32 func_021D450C(u32 *);
extern int func_021D45FC(void);
extern u32 func_021D4648(u32 a);
extern void func_021D4674(void);
extern int func_021B9F70(struct BtlMain *main, int slot);
extern void func_021BA698(struct BtlMain *main, int client);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
extern void func_021BAACC(struct BtlServer *server, int unused, int netId, int clientId, u8 slotCount);
extern void func_021BAB10(struct BtlServer *server, u8 clientId, int slotCount);
extern void func_021CD960(struct BtlClient *client, struct BtlServer *server);
extern u8 func_021B9010(struct BtlMain *main, u8 clientId);
extern int func_021BAB9C(struct BtlServer *server);
extern int func_021CD97C(struct BtlClient *client);
extern void func_021CDD94(struct BtlClient *client, void *buf);
extern void func_021E908C(struct BtlvCore *viewCore);
extern void func_021BABDC(struct BtlServer *server, void *buf);
extern void func_021CD914(struct BtlClient *client);
extern signed char func_02013080(u32 idx);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern int func_021809D8(void);
extern u16 func_021D5444(void *mon);
extern int func_0200CED4(void *,unsigned int);
extern u16 func_0200CF28(void *zukanWork);
extern void *func_021D5844(void *);
extern void func_0200CFA0(void *zukanWork, void *mon);
extern u8 ov231_id[];
extern int (*d_021EFD54[7])(struct BtlMain *, u32 *);
extern u8 func_021B8CB0(struct BtlMain *main, u8 basePos);
extern u32 func_021B99F0(u32 basePos);

int func_021B6100(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main);
int func_021B6434(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main);
int func_021B64CC(struct BtlMain *main);
int func_021B6500(struct ProcHandle *proc, u32 *step, int unused, struct BtlMain *main);
void func_021B66D4(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B6804(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup);
u8 func_021B6818(struct BattleSetupParam *setup);
void func_021B6848(struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B68D8(struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B6954(struct BtlMain *main, int slot);
int func_021B6994(struct BtlMain *main, u32 clientId);
void func_021B69FC(struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B6A3C(struct BtlMain *main, struct BattleSetupParam *setup);
void func_021B6A70(struct BtlMain *main, struct BattleSetupParam *setup, int isComm);
int func_021B6AAC(u32 *unused, void *arg);
int func_021B6C08(u32 *unused, void *arg);
int func_021B6C5C(u32 *unused, void *arg);
int func_021B6DD0(u32 *unused, void *arg);
int func_021B7050(u32 *unused, void *arg);
int func_021B71D4(u32 *unused, void *arg);
int func_021B734C(u32 *step, void *arg);
int func_021B73C4(u32 *step, void *arg);
int func_021B7488(u32 *step, void *arg);
int func_021B7518(u32 *step, void *arg);
int func_021B75A8(struct BtlMain *main, u32 *state);
int func_021B7758(struct BtlMain *main, u32 *state);
int func_021B7968(struct BtlMain *main, u32 *state);
int func_021B7BB0(struct BtlMain *main, u32 *state);
int func_021B7CB4(struct BtlMain *main);
int func_021B7E18(struct BtlMain *main);
int func_021B8070(struct BtlMain *main);
int func_021B81DC(struct BtlMain *main);
int func_021B835C(struct BtlMain *main, int *step);
int func_021B83F4(struct BtlMain *main);
int func_021B8434(struct BtlMain *main);
int func_021B84D8(struct BtlMain *main);
void func_021B8548(struct BtlMain *main);
int func_021B8564(struct BtlMain *main);
u32 func_021B8588(struct BtlMain *main);
unsigned int func_021B8590(struct BtlMain *main);
u8 func_021B85A0(struct BtlMain *main);
int func_021B85A8(struct BtlMain *main);
int func_021B85DC(struct BtlMain *main);
int func_021B85EC(struct BtlMain *main);
u32 func_021B8630(struct BtlMain *main);
unsigned int func_021B8640(struct BtlMain *main);
unsigned int func_021B8670(struct BtlMain *main);
int func_021B86A0(struct BtlMain *main, unsigned int posIdx);
u32 func_021B86B8(struct BtlMain *main);
u8 func_021B86C0(struct BtlMain *main);
int func_021B86C8(struct BtlMain *main);
u16 func_021B86DC(struct BtlMain *main);
int func_021B86E4(struct BtlMain *main);
struct FieldSituation *func_021B8714(struct BtlMain *main);
int func_021B871C(struct BtlMain *main);
int func_021B8724(struct BtlMain *main, void *mon);
u32 func_021B873C(struct BtlMain *main);
u32 func_021B8748(struct BtlMain *main);
void func_021B8750(struct BtlMain *main, unsigned char doRegister, void *mon);
u8 func_021B8778(struct BtlMain *main, int code, u8 *out);
u8 func_021B87E8(struct BtlMain *main, u32 k, u32 v, u8 *out);
u8 func_021B8834(struct BtlMain *main, u32 rangeType, u8 basePos, u8 *out);
u8 func_021B88EC(struct BtlMain *main, u32 rangeType, u32 basePos, u8 *out);
unsigned int func_021B8B78(struct BtlMain *main, int clientId);
int func_021B8B9C(struct BtlMain *main, unsigned char clientId);
unsigned char func_021B8BC4(int unusedWork, unsigned int clientId);
int func_021B8BD0(struct BtlMain *main, unsigned char side);
u8 func_021B8BEC(struct BtlMain *main, u32 clientId, u8 nth);
u8 func_021B8C20(int rule, u32 basePos, u32 lane);
u8 func_021B8C38(u32 basePos, u32 lane);
u8 func_021B8C50(struct BtlMain *main, u32 basePos, int lane);
u8 func_021B8C5C(int rule, u32 basePos);


int func_021B6100(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main)
{
  u32 flagBit;
  u32 i;
  u32 battleStyle;
  int taskDone;
  switch (*step)
  {
    case 0:
      func_0203064C(1, 0x12, 0x20000);
      func_0203064C(1, 0x14, 0x8000);
      func_0203064C(1, 0x13, 0xab100);
      main = func_0203159C(proc, 0x474, 0x12);
      func_02082A7C(0, main, 0x474);
      func_021E8DC4(0x13);
      func_021E88CC();
      if (!GFL_USE_IsMuteHookActive())
      {
        GFL_USE_SetSleepVolumeHooks();
        main->flags.sleepHooksSet = 1;
      }
      main->heapId = 0x12;
      main->setup = setup;
      setup->resultValue[0] = 6;
      main->playerStatus = main->setup->playerStatus[0];
      main->limitTimeGame = main->setup->limitTimeGame;
      main->limitTimeCommand = main->setup->limitTimeCommand;
      main->flags.unusedBit3 = 0;
      main->flags.unusedBit4 = 0;
      main->flags.commLost = 0;
      main->flags.commLostHandled = 0;
      main->flags.keepBgm = 0;
      main->flags.unusedBit6 = 0;
      main->multiState = 0;
      main->tick = 0;
      flagBit = 0;
      main->viewCore = 0;
      main->outcome = 7;
      main->textSpeed = CONFIG_GetTextSpeed(main->setup->config);
      if (CONFIG_GetBattleScene(setup->config) == 0)
        flagBit = 1;
      main->flags.noBattleAnim = (u8) flagBit;
      main->field = func_021EF958(main->heapId);
      func_021B93E0(&main->sides[0], main, 0);
      func_021B93E0(&main->sides[1], main, 1);
      func_021BA82C(main->setup);
      main->tempBuffer = 0;
      main->netBuffer = 0;
      if (main->setup->ownsSlots == 0)
        func_0203F258(&main->rng);
      else
        main->rng = setup->rng;
      func_021D7840(&main->rng, main->heapId);
      func_021CD6EC();
      main->prizeMoney = func_021D7F88(setup);
      main->bonusMoney = 0;
      main->penaltyMoney = 0;
      if (main->setup->ownsSlots == 0)
      {
        for (i = 0; i < 4; i++)
          main->setup->voiceFlags[i] = 0;
      }
      func_021D8230(&main->defeatedClients);
      battleStyle = CONFIG_GetBattleStyle(setup->config);
      flagBit = 0;
      if (battleStyle != 0)
        flagBit = 1;
      main->isSetStyle = flagBit;
      func_021D4150(setup->netHandle, setup->levelCap, 0x14);
      func_021D804C(0x12);
      (*step)++;
      break;

    case 1:
      if (main->setup->netHandle != 0 && func_021D4270())
      {
        main->flags.commLost = 1;
        main->flags.commLostHandled = 1;
        return 1;
      }
      if (func_021D4230())
      {
        func_021EEA30(main->setup->commPos);
        func_021B66D4(&main->task, main, main->setup);
        main->subStep = 0;
        func_021B9DB8(main);
        func_021BA094(main);
        (*step)++;
      }
      break;

    case 2:
      if (main->task.current != 0)
      {
        if (main->task.current(&main->task.step, main->task.arg))
        {
          main->task.current = 0;
          main->task.step = 0;
        }
        taskDone = 0;
      }
      else if (main->task.queued != 0)
      {
        if (main->task.queued(&main->task.step, main->task.arg))
        {
          main->task.queued = 0;
          taskDone = 1;
        }
        else
          taskDone = 0;
      }
      else
        taskDone = 1;
      if (taskDone != 0)
      {
        if (main->flags.commLost != 0)
        {
          main->flags.commLostHandled = 1;
          return 1;
        }
        if (main->setup->competitor != 4)
          func_021BA1B4(main, 4);
        return 1;
      }
      break;
  }

  return 0;
}

int func_021B6434(struct ProcHandle *proc, u32 *step, struct BattleSetupParam *setup, struct BtlMain *main)
{
    u32 result;
    u32 recordDone;

    if (main->tick == 0) {
        return 1;
    }
    if (main->tick(main) != 0) {
        if (func_021B9114(main) == 0) {
            result = func_021BA54C(main);
            func_021BA6C0(main);
            func_021BA878(main);
            func_021BA2E4(main);
            switch (result) {
            case 1:
                main->setup->moneyDelta = main->prizeMoney + main->bonusMoney;
                break;
            case 0:
            case 2:
                main->setup->moneyDelta = -main->penaltyMoney;
                break;
            }
        } else {
            recordDone = func_021B64CC(main);
            main->setup->bits.recordComplete = recordDone;
        }
        return 1;
    }
    return 0;
}

int func_021B64CC(struct BtlMain *main)
{
    unsigned int client;
    for (client = 0; client < 4; client++) {
        if (func_021B8B9C(main, client)) {
            if (!func_021EE894(main->recordReader, client)) return 0;
        }
    }
    return 1;
}

static inline int runTask(struct BtlMain *main)
{
    if (main->task.current) {
        if (main->task.current(&main->task.step, main->task.arg)) {
            main->task.current = 0; main->task.step = 0;
        }
        return 0;
    }
    if (main->task.queued) {
        if (main->task.queued(&main->task.step, main->task.arg)) main->task.queued = 0;
        else return 0;
    }
    return 1;
}

/*
 * lever: cache each re-read fade level for the comparison and setter; associate callback integer offsets before adding the base.
 */
int func_021B6500(struct ProcHandle *proc, u32 *step, int unused, struct BtlMain *main)
{
    switch (*step) {
    case 0:
        if (!main->flags.keepBgm) GFL_USE_FadeOutBgm(30);
        main->fadeLevel = 0;
        if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_A) != 0) {
            main->fadeLevel = -16;
            func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, -16);
            func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, -16);
            *step += 2;
        } else *step += 1;
        break;
    case 1: {
        int level;
        level = main->fadeLevel;
        if (level > -16) {
            main->fadeLevel = level - 1;
            if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_A) > (level = main->fadeLevel))
                func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, level);
            if (func_0207D55C((volatile u16 *)REG_MASTER_BRIGHT_B) > (level = main->fadeLevel))
                func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, level);
        } else *step += 1;
        break;
    }
    case 2:
        if (!main->flags.keepBgm) {
            if (GFL_USE_IsBgmFading() == 0) { GFL_USE_CancelChangeAndStopBgm(); *step += 1; }
        } else *step += 1;
        break;
    case 3:
        if (main->field) { func_021EF980(main->field); main->field = 0; }
        if (main->tempBuffer) { func_020307B0(main->tempBuffer); main->tempBuffer = 0; }
        if (main->netBuffer) { func_021D4D5C(main->netBuffer); main->netBuffer = 0; }
        func_021D7894();
        func_021BA0CC(main);
        func_021B9DE8(main);
        func_021B6804(&main->task, main, main->setup);
        *step += 1;
        break;
    case 4:
        if (runTask(main)) {
            func_021EEA54(); func_021D4254(); func_021D8058();
            *step += 1;
        }
        break;
    case 5:
        func_021E8DF8();
        GFL_USE_SetPlayersAudible(1, 62);
        PM_VOICE_ResetMasterVolume();
        if (main->flags.sleepHooksSet) { RINGTONE_SYS_RegisterSleepCallbacks(); main->flags.sleepHooksSet = 0; }
        func_020315D4(proc);
        func_020306F0(19);
        func_020306F0(20);
        func_020306F0(18);
        func_021E88F8();
        return 1;
    }
    return 0;
}

static inline void startTask(struct BtlTask *task, struct BtlMain *main, BtlStepFn fn)
{
    task->current = fn; task->queued = 0; task->arg = main; task->step = 0;
}

void func_021B66D4(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup)
{
    u32 slot;
    for (slot = 0; slot < 6; slot++) main->slotClientIds[slot] = 4;
    if (!setup->commPos) {
        switch (setup->rule) {
        case 0: startTask(task, main, func_021B6AAC); return;
        case 1:
            if (!setup->multiMode) { startTask(task, main, func_021B6C5C); return; }
            else { startTask(task, main, func_021B6DD0); return; }
        case 2: startTask(task, main, func_021B7050); return;
        case 3: startTask(task, main, func_021B71D4); return;
        default: startTask(task, main, func_021B6AAC); return;
        }
    } else {
        switch (setup->rule) {
        case 0: startTask(task, main, func_021B734C); return;
        case 1: startTask(task, main, func_021B73C4); return;
        case 2: startTask(task, main, func_021B7518); return;
        case 3: startTask(task, main, func_021B7488); return;
        default: startTask(task, main, func_021B6AAC); return;
        }
    }
}

/*
 * size: 324
 * lever: initializer stores first, second, object, state; object-first reallocates all tails.
 */
void func_021B6804(struct BtlTask *task, struct BtlMain *main, struct BattleSetupParam *setup)
{
    startTask(task, main, func_021B6C08);
}

u8 func_021B6818(struct BattleSetupParam *setup)
{
    switch (setup->competitor) {
    case 0: return 0;
    case 1: return 0;
    case 2: return 0;
    case 3: return 1;
    default: return 0;
    }
}

void func_021B6848(struct BtlMain *main, struct BattleSetupParam *setup)
{
    u32 client;
    const struct PerapVoice *srcVoice;
    u8 voiceOrder[4];
    u8 ownClientId = setup->netId;

    client = 0;
    main->ownClientId = ownClientId;
    main->ownFirstSlot = func_021B8BEC(main, ownClientId, 0);
    func_021B68D8(main, setup);
    if (func_021B9114(main) == 0) {
        srcVoice = func_02007B44(func_02012EBC(setup->gameData));
        main->voices[0] = func_02007B20(main->heapId);
        func_02007C20(main->voices[0], srcVoice);
        main->setup->voiceFlags[0] = func_021B997C(main, client);
    } else {
        for (client = 0; client < 4; client++) {
            voiceOrder[func_021BA710(main->ownClientId, (u8)client)] = main->setup->voiceFlags[client];
        }
        for (client = 0; client < 4; client++) {
            main->setup->voiceFlags[client] = voiceOrder[client];
        }
    }
}

void func_021B68D8(struct BtlMain *main, struct BattleSetupParam *setup)
{
    int firstSrc, secondSrc, thirdSrc, fourthSrc;

    firstSrc = func_021BA710(main->ownClientId, 0);
    secondSrc = func_021BA710(main->ownClientId, 1);
    func_021BA128(main, 0, setup->party[firstSrc]);
    func_021BA128(main, 1, setup->party[secondSrc]);
    thirdSrc = func_021BA710(main->ownClientId, 2);
    fourthSrc = func_021BA710(main->ownClientId, 3);
    if (setup->party[thirdSrc] != 0) {
        func_021BA128(main, 2, setup->party[thirdSrc]);
    }
    if (setup->party[fourthSrc] != 0) {
        func_021BA128(main, 3, setup->party[fourthSrc]);
    }
}

void func_021B6954(struct BtlMain *main, int slot)
{
    struct BattleSetupParam *setup = main->setup;
    int source = func_021BA710(main->ownClientId, slot);
    struct BtlTrainerSlot *trainerSlot = &main->trainers[slot];
    struct BattleTrainerData *trainer = setup->trainerData[source];
    if (trainer->trainerId != 0)
        func_021B9E7C(trainerSlot, trainer);
    else
        func_021B9E38(trainerSlot, main->heapId, setup->playerStatus[source]);
}

int func_021B6994(struct BtlMain *main, u32 clientId)
{
    struct BattleSetupParam *setup = main->setup;
    struct Party *partner;

    switch (setup->rule) {
    case 0:
        return 1;
    case 3:
        return 1;
    case 2:
        return 3;
    case 1:
        if (setup->multiMode == 0) {
            return 2;
        }
        if (setup->competitor == 3) {
            return 1;
        }
        partner = setup->party[(u8)((clientId + 2) & 3)];
        if (partner != 0 && (int)func_0201AA18(partner) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}

void func_021B69FC(struct BtlMain *main, struct BattleSetupParam *setup)
{
    if (setup->ownsSlots == 0) {
        func_021B9E38(&main->trainers[0], main->heapId, main->playerStatus);
        func_021B9E7C(&main->trainers[1], setup->trainerData[1]);
    } else {
        func_021B6954(main, 0);
        func_021B6954(main, 1);
    }
}

void func_021B6A3C(struct BtlMain *main, struct BattleSetupParam *setup)
{
    if (setup->ownsSlots) {
        func_021EE644(main->recordReader, setup->recordBuffer, setup->recordSize);
        func_021CD938(main->clients[0], main->recordReader);
        func_021CD938(main->clients[1], main->recordReader);
    }
}

/*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
void func_021B6A70(struct BtlMain *main, struct BattleSetupParam *setup, int isComm)
{
    struct BtlClient *client;
    struct BtlvCore *viewCore;
    if (setup->ownsSlots)
        client = main->clients[setup->netId];
    else
        client = main->clients[0];
    viewCore = func_021E8F20(main, client, &main->sides[0], isComm, 0x13);
    main->viewCore = viewCore;
    func_021CD95C(client, viewCore);
}

int func_021B6AAC(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = func_021B6818(setup);
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    func_021B6848(main, setup);
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    func_021B69FC(main, setup);
    main->clients[0] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
    func_021B6A70(main, setup, isComm);
    func_021BAA94(main->server, func_021CD978(main->clients[0]), 0, 1);
    func_021BAA94(main->server, func_021CD978(main->clients[1]), 1, 1);
    func_021BAB40(main->server);
    main->tick = func_021B83F4;
    return 1;
}

int func_021B6C08(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    u32 client;

    if (main->viewCore != 0) {
        func_021E9034(main->viewCore);
        main->viewCore = 0;
    }
    for (client = 0; client < 4; client++) {
        if (main->clients[client] != 0) {
            func_021CD8E0(main->clients[client]);
        }
    }
    func_021B9674(&main->sides[0]);
    func_021B9674(&main->sides[1]);
    if (main->server != 0) {
        func_021BAB5C(main->server);
    }
    if (main->subServer != 0) {
        func_021BAB5C(main->subServer);
    }
    return 1;
}

int func_021B6C5C(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = func_021B6818(setup);
    main->ownClientId = 0;
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    func_021B6848(main, setup);
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    func_021B69FC(main, setup);
    main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 0, 2, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 1, 2, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
    func_021B6A70(main, setup, isComm);
    func_021BAA94(main->server, func_021CD978(main->clients[0]), 0, 2);
    func_021BAA94(main->server, func_021CD978(main->clients[1]), 1, 2);
    func_021BAB40(main->server);
    main->tick = func_021B83F4;
    return 1;
}

/*
 * lever: the boolean passed narrow is an int local; isComm declared after sideBlock puts it at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`sideBlock = main;` before `sideBlock = &main->sides[0];`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
int func_021B6DD0(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int client;
    u8 slotCount;
    int isOpponent;
    struct BtlSide *sideBlock;
    struct BattleRngState *rngState;
    int isComm;
    setup = main->setup;
    isComm = func_021B6818(setup);
    main->ownClientId = 0;
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[2] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[3] = 1;
    switch (setup->multiMode) {
    case 0: break;
    case 1: case 2: case 3:
        main->slotClientIds[2] = 2;
        main->slotClientIds[3] = 3;
        main->clientCount = 4;
        break;
    case 4:
        main->slotClientIds[3] = 3;
        main->clientCount = 3;
        break;
    }
    func_021B6848(main, setup);
    func_021B93E0(&main->sides[0], main, 0);
    func_021B93E0(&main->sides[1], main, 1);
    for (client = 0; client < 4; client++) {
        if (func_021B8B9C(main, client)) {
            func_021B9460(&main->sides[0], main, client);
            func_021B9460(&main->sides[1], main, client);
        }
    }
    if (!setup->ownsSlots) {
        func_021B9E38(&main->trainers[0], main->heapId, main->playerStatus);
        func_021B9E7C(&main->trainers[1], setup->trainerData[1]);
        if (func_021B8B9C(main, 2)) func_021B9E7C(&main->trainers[2], setup->trainerData[2]);
        if (func_021B8B9C(main, 3)) func_021B9E7C(&main->trainers[3], setup->trainerData[3]);
    } else {
        for (client = 0; client < 4; client++) {
            if (func_021B8B9C(main, client)) func_021B6954(main, (u8)client);
        }
    }
    main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    rngState = &main->rng;
    sideBlock = &main->sides[0];
    for (client = 0; client < 4; client++) {
        if (func_021B8B9C(main, client)) {
            slotCount = func_021B8B78(main, (u8)client);
            isOpponent = 0;
            if (client != 0) isOpponent = 1;
            main->clients[client] = func_021CD6F0(main, sideBlock, 0, setup->netHandle, client, slotCount, isOpponent, isComm, setup->ownsSlots, rngState, main->heapId);
        }
    }
    if (setup->ownsSlots) {
        func_021EE644(main->recordReader, setup->recordBuffer, setup->recordSize);
        for (client = 0; client < 4; client++) {
            if (func_021B8B9C(main, client)) func_021CD938(main->clients[client], main->recordReader);
        }
    }
    func_021B6A70(main, setup, isComm);
    for (client = 0; client < 4; client++) {
        if (func_021B8B9C(main, client)) {
            slotCount = func_021B8B78(main, (u8)client);
            func_021BAA94(main->server, func_021CD978(main->clients[client]), client, slotCount);
        }
    }
    func_021BAB40(main->server);
    main->tick = func_021B83F4;
    return 1;
}

int func_021B7050(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = func_021B6818(setup);
    main->clientCount = 2;
    main->hostsServer = 1;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    main->slotClientIds[4] = 0;
    main->slotClientIds[5] = 1;
    func_021B6848(main, setup);
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    func_021B69FC(main, setup);
    main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    main->clients[0] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 0, 3, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 1, 3, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
    func_021B6A70(main, setup, isComm);
    func_021BAA94(main->server, func_021CD978(main->clients[0]), 0, 3);
    func_021BAA94(main->server, func_021CD978(main->clients[1]), 1, 3);
    func_021BAB40(main->server);
    main->tick = func_021B83F4;
    return 1;
}

int func_021B71D4(u32 *unused, void *arg)
{
    struct BtlMain *main = arg;
    struct BattleSetupParam *setup;
    int isComm;
    setup = main->setup;
    isComm = func_021B6818(setup);
    main->clientCount = 2;
    main->slotClientIds[0] = 0;
    main->slotClientIds[1] = 1;
    main->slotClientIds[2] = 0;
    main->slotClientIds[3] = 1;
    main->slotClientIds[4] = 0;
    main->slotClientIds[5] = 1;
    func_021B6848(main, setup);
    func_021B93E0(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 0);
    func_021B9460(&main->sides[0], main, 1);
    func_021B93E0(&main->sides[1], main, 1);
    func_021B9460(&main->sides[1], main, 0);
    func_021B9460(&main->sides[1], main, 1);
    main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
    main->hostsServer = 1;
    func_021B69FC(main, setup);
    main->clients[0] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 0, 1, 0, isComm, setup->ownsSlots, &main->rng, main->heapId);
    main->clients[1] = func_021CD6F0(main, &main->sides[0], 0, setup->netHandle, 1, 1, 1, isComm, setup->ownsSlots, &main->rng, main->heapId);
    func_021B6A3C(main, setup);
    func_021B6A70(main, setup, isComm);
    func_021BAA94(main->server, func_021CD978(main->clients[0]), 0, 1);
    func_021BAA94(main->server, func_021CD978(main->clients[1]), 1, 1);
    func_021BAB40(main->server);
    main->tick = func_021B83F4;
    return 1;
}

extern int (*d_021EFD1C[7])(struct BtlMain *, u32 *);

int func_021B734C(u32 *step, void *arg)
{
    struct BtlMain *main = arg;
    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = func_021B8BEC(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if (*step < 7) {
        if (d_021EFD1C[*step](main, &main->subStep) != 0) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}

extern int (*d_021EFD00[7])(struct BtlMain *, u32 *);

int func_021B73C4(u32 *step, void *arg)
{
    struct BtlMain *main = arg;
    if (*step == 0) {
        switch (main->setup->multiMode) {
        case 0:
        default:
            main->clientCount = 2;
            main->slotClientIds[0] = 0;
            main->slotClientIds[1] = 1;
            main->slotClientIds[2] = 0;
            main->slotClientIds[3] = 1;
            break;
        case 2:
            main->multiState = 2;
        case 1:
            main->clientCount = 4;
            main->slotClientIds[0] = 0;
            main->slotClientIds[1] = 1;
            main->slotClientIds[2] = 2;
            main->slotClientIds[3] = 3;
            break;
        }
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = func_021B8BEC(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if (*step < 7) {
        if (d_021EFD00[*step](main, &main->subStep) != 0) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}


int func_021B7488(u32 *step, void *arg)
{
    struct BtlMain *main = arg;

    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->slotClientIds[2] = 0;
        main->slotClientIds[3] = 1;
        main->slotClientIds[4] = 0;
        main->slotClientIds[5] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = func_021B8BEC(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if ((u32)*step < 7) {
        if (d_021EFD38[*step](main, &main->subStep)) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}






int func_021B7518(u32 *step, void *arg)
{
    struct BtlMain *main = arg;

    if (*step == 0) {
        main->clientCount = 2;
        main->slotClientIds[0] = 0;
        main->slotClientIds[1] = 1;
        main->slotClientIds[2] = 0;
        main->slotClientIds[3] = 1;
        main->slotClientIds[4] = 0;
        main->slotClientIds[5] = 1;
        main->ownClientId = main->setup->netId;
        main->ownFirstSlot = func_021B8BEC(main, main->ownClientId, 0);
        *step = *step + 1;
        return 0;
    }
    if ((u32)*step < 7) {
        if (d_021EFD54[*step](main, &main->subStep)) {
            main->subStep = 0;
            *step = *step + 1;
        }
        return 0;
    }
    return 1;
}




int func_021B75A8(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_021D4294(main->ownClientId)) ++*state;
        break;
    case 1:
        if (func_021D4348()) {
            main->pad46A = 0;
            main->hostsServer = func_021D4360();
            main->setup->resultValue[1] = func_021D4378();
            if (func_021D4360()) *state = 2;
            else *state = 3;
        }
        break;
    case 2:
        *(struct BattleRngState *)&main->ruleExchange = main->rng;
        main->ruleExchange.resultCount = main->setup->resultCount;
        main->ruleExchange.limitTimeGame = main->setup->limitTimeGame;
        main->ruleExchange.limitTimeCommand = main->setup->limitTimeCommand;
        if (func_021BA1A8(main, 0x1000)) {
            main->ruleExchange.textSpeed = main->textSpeed;
            main->ruleExchange.sceneOff = main->flags.noBattleAnim;
        } else {
            main->ruleExchange.textSpeed = 2;
            main->ruleExchange.sceneOff = 1;
        }
        if (func_021D43B8((u32)&main->ruleExchange)) ++*state;
        break;
    case 3:
        if (func_021D440C(&main->ruleExchange)) {
            setup = main->setup;
            setup->resultCount = main->ruleExchange.resultCount;
            setup->rng = *(struct BattleRngState *)&main->ruleExchange;
            main->rng = *(struct BattleRngState *)&main->ruleExchange;
            main->flags.noBattleAnim = main->ruleExchange.sceneOff;
            main->textSpeed = main->ruleExchange.textSpeed;
            main->limitTimeGame = main->ruleExchange.limitTimeGame;
            main->limitTimeCommand = main->ruleExchange.limitTimeCommand;
            return 1;
        }
        break;
    }
    return 0;
}




/*
 * lever: slot starts at 1 and is conditionally assigned 3; ternary reverses the short branch.
 */
int func_021B7758(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    struct BtlSide *side;
    int slot;
    setup = main->setup;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4((u8)2);
        ++*state;
        break;
    case 1:
        if (func_021D4B18((u8)2)) ++*state;
        break;
    case 2:
        if (func_021D4438((u32)(setup->party[0]))) ++*state;
        break;
    case 3:
        if (func_021D44CC()) {
            if (!main->multiState) *state = 10;
            else {
                if (main->hostsServer) {
                    main->netBuffer = func_021D4D24(POKE_REGULATION_GetDataSize(), (main->heapId & 0x7fff) | 0x8000);
                }
                main->exchangeIndex = 0;
                ++*state;
            }
        }
        break;
    case 4:
        slot = 1;
        if (main->exchangeIndex) slot = 3;
        main->exchangeSlot = slot;
        if (main->hostsServer) func_021D4D64(main->netBuffer, setup->party[main->exchangeSlot], main->exchangeSlot);
        func_021D4AF4((u8)(main->exchangeIndex + 6));
        ++*state;
        break;
    case 5:
        if (func_021D4B18((u8)(main->exchangeIndex + 6))) ++*state;
        break;
    case 6:
        if (!main->hostsServer || func_021D4680(main->netBuffer)) ++*state;
        break;
    case 7:
        if (func_021D4784(main->exchangeSlot)) {
            ++main->exchangeIndex;
            if (main->exchangeIndex >= main->multiState) {
                if (main->hostsServer) {
                    func_021D4D5C(main->netBuffer);
                    main->netBuffer = 0;
                }
                *state = 10;
            } else *state = 4;
        }
        break;
    case 10:
        func_021B93E0(&main->sides[0], main, 0);
        side = &main->sides[0];
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(main, i)) {
                func_021BA128(main, (u8)i, func_021D47A4(i));
                func_021BA648(main, i, func_021D47A4(i));
                func_021B9460(side, main, i);
            }
        }
        ++*state;
        break;
    case 11:
        func_021B93E0(&main->sides[1], main, 1);
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(main, i)) func_021B9460(&main->sides[1], main, i);
        }
        ++*state;
        break;
    case 12:
        func_021D4800();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}




int func_021B7968(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    void *bank;
    void *defaultName;
    void *nameStr;
    u16 *src;
    u16 *dst;
    u16 buf[16];
    int slot;
    setup = main->setup;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4((u8)4);
        ++*state;
        break;
    case 1:
        if (func_021D4B18((u8)4)) ++*state;
        break;
    case 2:
        if (func_021D4808((u32)(main->playerStatus))) ++*state;
        break;
    case 3:
        if (func_021D4898()) {
            for (i = 0; i < main->clientCount; ++i) {
                void *status = func_021D48CC(i);
                if (status) {
                    func_021B9E38(&main->trainers[i], main->heapId, status);
                    if (i != main->ownClientId && setup->bits.hidePlayerNames) {
                        int j;
                        bank = func_02045B38(0, 2, 0x51, main->heapId);
                        nameStr = func_02045EC0(bank, 15);
                        func_02045C04(bank);
                        src = STRBUF_GetChars(nameStr);
                        for (j = 0; j < 15 && (u32)j < func_020458F8(nameStr); ++j) buf[j] = src[j];
                        dst = buf;
                        dst[j] = func_02045A98();
                        func_02045808(nameStr);
                        func_020084D4((u32)(main->trainers[i].handle), dst);
                        func_02045808(main->trainers[i].name);
                        bank = func_02045B38(0, 2, 0x51, main->heapId);
                        defaultName = func_02045EC0(bank, 15);
                        func_02045C04(bank);
                        main->trainers[i].name = defaultName;
                    }
                    func_021BA670(main, i, main->trainers[i].handle);
                }
            }
            ++*state;
        }
        break;
    case 4:
        if (!main->multiState) *state = 10;
        else { main->exchangeIndex = 0; ++*state; }
        break;
    case 5:
        func_021D4AF4((u8)(main->exchangeIndex + 8));
        ++*state;
        break;
    case 6:
        if (func_021D4B18((u8)(main->exchangeIndex + 8))) ++*state;
        break;
    case 7:
        slot = 1;
        if (main->exchangeIndex) slot = 3;
        main->exchangeSlot = slot;
        if (main->hostsServer && !func_021D4908(setup->trainerData[main->exchangeSlot])) break;
        ++*state;
    case 8:
        if (func_021D49B0()) {
            func_021B9EF0(&main->trainers[main->exchangeSlot], func_021D49CC());
            func_021D49E0();
            ++main->exchangeIndex;
            if (main->exchangeIndex >= main->multiState) *state = 10;
            else *state = 5;
        }
        break;
    case 10:
        func_021D4A04();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}




int func_021B7BB0(struct BtlMain *main, u32 *state)
{
    struct BattleSetupParam *setup;
    u32 i;
    const struct PerapVoice *src;
    setup = main->setup;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4500();
        func_021D4AF4(3);
        ++*state;
        break;
    case 1:
        if (func_021D4B18(3)) ++*state;
        break;
    case 2:
        if (func_021D450C((u32 *)func_02007B44(func_02012EBC(setup->gameData)))) ++*state;
        break;
    case 3:
        if (func_021D45FC()) {
            for (i = 0; i < 4; ++i) {
                if (func_021B8B9C(main, i) && !func_021B9F70(main, (u8)i)) {
                    src = (void *)func_021D4648((u8)i);
                    if (src) {
                        main->voices[i] = func_02007B20(main->heapId);
                        func_02082D44(src, main->voices[i], func_02007B00());
                    }
                }
                func_021BA698(main, (u8)i);
            }
            func_021D4674();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




int func_021B7CB4(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    int isComm;
    u32 i, flag;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = (int)func_021B6818(setup);
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        func_021BAA94(main->server, func_021CD978(main->clients[clientId]), clientId, 1);
        flag = 1;
        if (clientId != 0) flag = 0;
        func_021BAACC(main->server, setup->commPos, setup->netHandle, (u8)flag, 1);
    } else {
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(main, i))
                func_021BAB10(main->subServer, i, 1);
        }
        func_021CD960(main->clients[clientId], main->subServer);
    }
    return 1;
}




/*
 * Twin of func_021B8070 and func_021B7CB4 (same callees). The locals clientId, slotCount
 * and isComm must be u8 and func_021B6818 must return u8 (it returns only 0 or 1): mwcc keeps
 * the reload of a spilled narrow local below the outgoing stack stores, see
 * docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md. With an int
 * isComm it hoisted the reload and the argument setup order differed (69 bytes).
 */
int func_021B7E18(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    u8 slotCount;
    u8 isComm;
    u32 i;
    u8 x;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = func_021B6818(setup);
    slotCount = (setup->multiMode == 0) ? 2 : 1;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)slotCount, 0, isComm, (u8)0, &main->rng, main->heapId);
        func_021BAA94(main->server, func_021CD978(main->clients[clientId]), clientId, slotCount);
        if (setup->multiMode == 2) {
            x = func_021B9010(main, clientId);
            main->clients[1] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, 1, (u8)slotCount, 1, isComm, (u8)0, &main->rng, main->heapId);
            func_021BAA94(main->server, func_021CD978(main->clients[1]), 1, slotCount);
            main->clients[3] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, 3, (u8)slotCount, 1, isComm, (u8)0, &main->rng, main->heapId);
            func_021BAA94(main->server, func_021CD978(main->clients[3]), 3, slotCount);
            func_021BAACC(main->server, setup->commPos, setup->netHandle, (u8)x, slotCount);
        } else {
            for (i = 0; i < main->clientCount; i++) {
                if (i != clientId)
                    func_021BAACC(main->server, setup->commPos, setup->netHandle, (u8)i, slotCount);
            }
        }
    } else {
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)slotCount, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(main, i))
                func_021BAB10(main->subServer, i, func_021B6994(main, (u8)i));
        }
        func_021CD960(main->clients[clientId], main->subServer);
    }
    return 1;
}





int func_021B8070(struct BtlMain *main)
{
    struct BattleSetupParam *setup;
    u8 clientId;
    int isComm;
    u32 i, flag;
    setup = main->setup;
    clientId = main->ownClientId;
    isComm = (int)func_021B6818(setup);
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)3, 0, isComm, (u8)0, &main->rng, main->heapId);
        func_021BAA94(main->server, func_021CD978(main->clients[clientId]), clientId, 3);
        flag = 0;
        if (clientId == 0) flag = 1;
        func_021BAACC(main->server, setup->commPos, setup->netHandle, (u8)flag, 3);
    } else {
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)3, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(main, i))
                func_021BAB10(main->subServer, i, func_021B6994(main, (u8)i));
        }
        func_021CD960(main->clients[clientId], main->subServer);
    }
    return 1;
}





int func_021B81DC(struct BtlMain *main)
{
    u8 clientId;
    struct BattleSetupParam *setup;
    int isComm;
    u32 i;
    clientId = main->ownClientId;
    setup = main->setup;
    isComm = (int)func_021B6818(setup);
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (main->hostsServer) {
        main->server = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        func_021BAA94(main->server, func_021CD978(main->clients[clientId]), clientId, 1);
        for (i = 0; i < main->clientCount; i++) {
            if (i != clientId)
                func_021BAACC(main->server, setup->commPos, setup->netHandle, (u8)i, 1);
        }
    } else {
        main->clients[clientId] = func_021CD6F0(main, &main->sides[0], setup->commPos, setup->netHandle, clientId, (u8)1, 0, isComm, (u8)0, &main->rng, main->heapId);
        main->subServer = func_021BA9C8(main, &main->rng, &main->sides[1], isComm, main->heapId);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(main, i))
                func_021BAB10(main->subServer, i, func_021B6994(main, (u8)i));
        }
        func_021CD960(main->clients[clientId], main->subServer);
    }
    return 1;
}





int func_021B835C(struct BtlMain *main, int *step)
{
    int isComm;
    struct BtlvCore *viewCore;
    if (func_021D4270()) {
        main->flags.commLost = 1;
        return 1;
    }
    if (*step == 0) {
        isComm = func_021B6818(main->setup);
        viewCore = func_021E8F20(main, main->clients[main->ownClientId], &main->sides[0], isComm, 0x13);
        main->viewCore = viewCore;
        func_021CD95C(main->clients[main->ownClientId], viewCore);
        if (main->hostsServer) {
            main->tick = func_021B8434;
            func_021BAB40(main->server);
        } else {
            main->tick = func_021B84D8;
        }
        *step = *step + 1;
    } else {
        return 1;
    }
    return 0;
}






int func_021B83F4(struct BtlMain *main)
{
    int i, found = 0;
    func_021BAB9C(main->server);
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 &&
            func_021CD97C(main->clients[i]) != 0) {
            func_021CDD94(main->clients[i], &main->defeatedClients);
            found = 1;
        }
    }
    func_021E908C(main->viewCore);
    return found;
}






int func_021B8434(struct BtlMain *main)
{
    int r, i;
    if (main->flags.commLost == 0) {
        if (func_021D4270()) {
            main->flags.commLost = 1;
            func_021B8548(main);
        }
    } else if (main->flags.commLostHandled != 0) {
        return 1;
    }
    r = func_021BAB9C(main->server);
    if (r) {
        func_021BABDC(main->server, &main->defeatedClients);
    }
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 && main->clientReady[i] == 0) {
            main->clientReady[i] = func_021CD97C(main->clients[i]);
        }
    }
    if (func_021B8564(main)) {
        func_021CDD94(main->clients[main->ownClientId], &main->defeatedClients);
        r = 1;
    }
    func_021E908C(main->viewCore);
    return r;
}






int func_021B84D8(struct BtlMain *main)
{
    int r, i;
    if (main->flags.commLost == 0) {
        if (func_021D4270()) {
            main->flags.commLost = 1;
            func_021B8548(main);
        }
    } else if (main->flags.commLostHandled != 0) {
        return 1;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 &&
            func_021CD97C(main->clients[i]) != 0) {
            func_021CDD94(main->clients[i], &main->defeatedClients);
            r = 1;
        }
    }
    func_021E908C(main->viewCore);
    return r;
}





void func_021B8548(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        void *client = main->clients[i];
        if (client) func_021CD914(client);
    }
}





int func_021B8564(struct BtlMain *main)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (main->clients[i] != 0 && main->clientReady[i] == 0) return 0;
    }
    return 1;
}






u32 func_021B8588(struct BtlMain *main)
{
    return main->setup->rule;
}





unsigned int func_021B8590(struct BtlMain *main) { return main->flags.noBattleAnim; }






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x80; ldrb r0, [r0]; bx lr.
 */
u8 func_021B85A0(struct BtlMain *main) { return main->setup->badgeCount; }





/*
 * note 2026-10-05: the arm9 witness src/matched/arm9/CONFIG_GetBattleStyle.c exists (EXACT); the only wildcard is that bl, so this lifts to EXACT after the integrator regenerates the manifest/labels.
 */
int func_021B85A8(struct BtlMain *main)
{
    if (func_021B86B8(main) == 1 && func_021B8588(main) == 0 && func_021B86C0(main) == 0 && CONFIG_GetBattleStyle(main->setup->config) == 0) return 1;
    return 0;
}





int func_021B85DC(struct BtlMain *main) { return func_02013080(main->textSpeed); }






int func_021B85EC(struct BtlMain *main)
{
    int r;
    if (main->setup->competitor <= 1) {
        func_02034AC4((int)ov231_id);
        r = func_021809D8();
        func_02034A5C((int)ov231_id);
        if (r == 0) {
            return 0;
        }
        if (func_021BA1A8(main, 0x200) == 0) {
            return 1;
        }
    }
    return 0;
}






/* 021B8630  first round: the guard "competitor > 1 return 0" came back bls.  The image
 * takes the guard, so the guarded read is the fall-through arm. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldr r1, [r0]; ldr r0, [r1]; cmp r0, #1; bhi loc_021B863C; ldr r0, [r1, #0x70]; bx lr; movs r0, #0; bx lr.
 */
u32 func_021B8630(struct BtlMain *main)
{
    struct BattleSetupParam *setup = main->setup;
    if (setup->competitor <= 1)
        return setup->pmsWork;
    return 0;
}





unsigned int func_021B8640(struct BtlMain *main) { switch (main->setup->rule) { case 0:return 1; case 1:return 3; case 2:return 5; case 3:return 5; default:return 5; } }





unsigned int func_021B8670(struct BtlMain *main) { switch (main->setup->rule) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }





int func_021B86A0(struct BtlMain *main, unsigned int posIdx) { if (posIdx < func_021B8670(main)*2) return 1; return 0; }





u32 func_021B86B8(struct BtlMain *main)
{
    return main->setup->competitor;
}






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x20; ldrb r0, [r0]; bx lr.
 */
u8 func_021B86C0(struct BtlMain *main) { return main->setup->commPos; }





/*
 * The SDK symbol list names 0x021B86CA CTRDGi_IsTaskBusy(pt), the busy-flag test (pt->busy != 0).
 * That address lies inside this function (adds #0x22 after the ldr): it is not a separate entry.
 * The final two zero bytes are alignment padding before the next function.
 */
int func_021B86C8(struct BtlMain *main) { if (main->setup->multiMode) return 1; return 0; }





u16 func_021B86DC(struct BtlMain *main)
{
    return main->setup->bgmWin;
}


int func_021B86E4(struct BtlMain *main) { switch(main->setup->competitor) { case 0:return 0; case 1:return 1; case 2:return 2; case 3:return 2; default:return 1; } }


struct FieldSituation *func_021B8714(struct BtlMain *main)
{
    return &main->setup->fieldSituation;
}



int func_021B871C(struct BtlMain *main)
{
    return (int)main->playerStatus;
}


int func_021B8724(struct BtlMain *main, void *mon) { unsigned int species=func_021D5444(mon); return func_0200CED4(main->setup->zukanWork,species); }


u32 func_021B873C(struct BtlMain *main)
{
    return func_0200CF28((struct Blk37 *)(main->setup->zukanWork));
}



u32 func_021B8748(struct BtlMain *main)
{
    return (u32)main->setup->gameData;
}


void func_021B8750(struct BtlMain *main, unsigned char doRegister, void *mon) { if(func_021B86B8(main)<=1 && doRegister!=0) func_0200CFA0(main->setup->zukanWork,func_021D5844(mon)); }



u8 func_021B8778(struct BtlMain *main, int code, u8 *out)
{
    u8 hi = code >> 8;
    u8 lo = code;

    if (hi == 0) {
        *out = lo;
        return *out != 6;
    }
    if (lo != 6) {
        switch (main->setup->rule) {
        case 0:
        default:
            return func_021B87E8(main, hi, lo, out);
        case 1:
            return func_021B8834(main, hi, lo, out);
        case 2:
            return func_021B88EC(main, hi, lo, out);
        case 3:
            return func_021B87E8(main, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}



u8 func_021B87E8(struct BtlMain *main, u32 k, u32 v, u8 *out)
{
    switch (k) {
    case 0:
    case 4:
    case 7:
    default:
        return 0;
    case 1:
    case 2:
    case 6:
        *out = func_021B8C50(main, v, 0);
        break;
    case 3:
        *out = v;
        break;
    case 5:
    case 8:
        out[0] = 0;
        out[1] = 1;
        return 2;
    }
    return 1;
}


/*
 * Double battle: fill out[] with the positions that a range kind reaches
 * from basePos and return how many were written.
 */
u8 func_021B8834(struct BtlMain *main, u32 rangeType, u8 basePos, u8 *out)
{
    u8 tmp;

    switch (rangeType) {
    case BTL_RANGE_DEFAULT:
    default:
        return 0;
    case BTL_RANGE_ENEMIES_IN_REACH:
    case BTL_RANGE_ALL_ENEMIES:
        out[0] = func_021B8C50(main, basePos, 0);
        out[1] = func_021B8C50(main, basePos, 1);
        return 2;
    case BTL_RANGE_OTHERS_IN_REACH:
        out[0] = func_021B8C50(main, basePos, 0);
        out[1] = func_021B8C50(main, basePos, 1);
        out[2] = func_021B8CB0(main, basePos);
        return 3;
    case BTL_RANGE_SELF_AND_ALLIES_IN_REACH:
        out[0] = basePos;
        out[1] = func_021B8CB0(main, basePos);
        if (out[0] > out[1]) {
            tmp = out[0];
            out[0] = out[1];
            out[1] = tmp;
        }
        return 2;
    case BTL_RANGE_ALLIES_IN_REACH:
    case BTL_RANGE_ALLIES_IN_REACH_ALT:
        out[0] = func_021B8CB0(main, basePos);
        return 1;
    case BTL_RANGE_ALL_ALLIES:
        out[0] = basePos;
        out[1] = func_021B8CB0(main, basePos);
        return 2;
    case BTL_RANGE_ALL_IN_REACH:
    case BTL_RANGE_EVERY_POSITION:
        out[0] = 0;
        out[1] = 1;
        out[2] = 2;
        out[3] = 3;
        return 4;
    }
}


/*
 * Triple battle: fill out[] with the positions that a range kind reaches
 * from basePos and return how many were written. A position in the middle
 * row (func_021B99F0) reaches all three lanes of the other side; a position
 * in an outer row reaches the centre lane and the lane that faces it.
 * The facing-lane swap is written out in each case, as in the original.
 */
u8 func_021B88EC(struct BtlMain *main, u32 rangeType, u32 basePos, u8 *out)
{
    u8 inMiddleRow = func_021B99F0(basePos);
    u8 facingLane;

    switch (rangeType) {
    case BTL_RANGE_DEFAULT:
    case BTL_RANGE_ENEMIES_IN_REACH:
    default:
        if (inMiddleRow) {
            out[0] = func_021B8C50(main, basePos, 0);
            out[1] = func_021B8C50(main, basePos, 1);
            out[2] = func_021B8C50(main, basePos, 2);
            return 3;
        }
        out[0] = func_021B8C50(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = func_021B8C20(2, basePos, facingLane);
        return 2;
    case BTL_RANGE_ALL_ENEMIES:
        out[0] = func_021B8C50(main, basePos, 0);
        out[1] = func_021B8C50(main, basePos, 1);
        out[2] = func_021B8C50(main, basePos, 2);
        return 3;
    case BTL_RANGE_ALL_ALLIES:
        out[0] = func_021B8C38(basePos, 0);
        out[1] = func_021B8C38(basePos, 1);
        out[2] = func_021B8C38(basePos, 2);
        return 3;
    case BTL_RANGE_EVERY_POSITION:
        out[0] = func_021B8C50(main, basePos, 0);
        out[1] = func_021B8C50(main, basePos, 1);
        out[2] = func_021B8C50(main, basePos, 2);
        out[3] = func_021B8C38(basePos, 0);
        out[4] = func_021B8C38(basePos, 1);
        out[5] = func_021B8C38(basePos, 2);
        return 6;
    case BTL_RANGE_OTHERS_IN_REACH:
        if (inMiddleRow) {
            out[0] = func_021B8C50(main, basePos, 0);
            out[1] = func_021B8C50(main, basePos, 1);
            out[2] = func_021B8C50(main, basePos, 2);
            out[3] = func_021B8C38(basePos, 0);
            out[4] = func_021B8C38(basePos, 2);
            return 5;
        }
        out[0] = func_021B8C50(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = func_021B8C20(2, basePos, facingLane);
        out[2] = func_021B8C38(basePos, 1);
        return 3;
    case BTL_RANGE_SELF_AND_ALLIES_IN_REACH:
        if (inMiddleRow) {
            out[0] = basePos;
            out[1] = func_021B8C38(basePos, 0);
            out[2] = func_021B8C38(basePos, 2);
            return 3;
        }
        out[0] = basePos;
        out[1] = func_021B8C38(basePos, 1);
        return 2;
    case BTL_RANGE_ALLIES_IN_REACH_ALT:
        if (inMiddleRow) {
            out[0] = func_021B8C38(basePos, 0);
            out[1] = func_021B8C38(basePos, 2);
            return 2;
        }
        out[0] = func_021B8C38(basePos, 1);
        return 1;
    case BTL_RANGE_ALLIES_IN_REACH:
        if (inMiddleRow) {
            out[0] = func_021B8C38(basePos, 0);
            out[1] = func_021B8C38(basePos, 2);
            return 2;
        }
        out[0] = func_021B8C38(basePos, 1);
        return 1;
    case BTL_RANGE_ALL_IN_REACH:
        if (inMiddleRow) {
            out[0] = func_021B8C50(main, basePos, 0);
            out[1] = func_021B8C50(main, basePos, 1);
            out[2] = func_021B8C50(main, basePos, 2);
            out[3] = func_021B8C38(basePos, 0);
            out[4] = func_021B8C38(basePos, 2);
            out[5] = basePos;
            return 6;
        }
        out[0] = func_021B8C50(main, basePos, 1);
        facingLane = (u8)(basePos >> 1);
        if (facingLane == 0) facingLane = 2;
        else if (facingLane == 2) facingLane = 0;
        out[1] = func_021B8C20(2, basePos, facingLane);
        out[2] = func_021B8C38(basePos, 1);
        out[3] = basePos;
        return 4;
    }
}


/* Number of trainer entries that are controlled by clientId. */
unsigned int func_021B8B78(struct BtlMain *main, int clientId)
{
    unsigned int count;
    unsigned int i;

    i = 0;
    count = 0;
    for (; i < 6; i++) {
        if (clientId == main->slotClientIds[i]) {
            count++;
        }
    }
    return count;
}

/* Nonzero when clientId (0..3) controls at least one trainer entry. */
int func_021B8B9C(struct BtlMain *main, unsigned char clientId)
{
    unsigned int i;

    if (clientId < 4) {
        for (i = 0; i < 6; i++) {
            if (clientId == main->slotClientIds[i]) {
                return 1;
            }
        }
    }
    return 0;
}

/* Side of a client: bit 0 of its id. The main pointer is not read. */
unsigned char func_021B8BC4(int unusedWork, unsigned int clientId)
{
    (void)unusedWork;
    return clientId & 1;
}

/* Nonzero when side is the side of the local network id. */
int func_021B8BD0(struct BtlMain *main, unsigned char side)
{
    if (side == func_021B8BC4((int)main, main->ownClientId)) {
        return 1;
    }
    return 0;
}


/* Index of the nth trainer entry that clientId controls, or 6 when none. */
u8 func_021B8BEC(struct BtlMain *main, u32 clientId, u8 nth)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (clientId == main->slotClientIds[i]) {
            if (nth == 0) {
                return i;
            }
            nth--;
        }
    }
    return 6;
}


/*
 * Position of a lane on the side opposite to basePos. The rule argument is
 * not read here; it keeps the call shape of func_021B8C50.
 */
u8 func_021B8C20(int rule, u32 basePos, u32 lane)
{
    if ((basePos & 1) == 0) {
        return lane * 2 + 1;
    }
    return lane * 2;
}


/* Position of a lane on the same side as basePos. */
u8 func_021B8C38(u32 basePos, u32 lane)
{
    if ((basePos & 1) == 0) {
        return lane * 2;
    }
    return lane * 2 + 1;
}


/* Enemy side lane position, with the battle rule taken from the setup. */
u8 func_021B8C50(struct BtlMain *main, u32 basePos, int lane)
{
    return func_021B8C20(main->setup->rule, basePos, lane);
}


/* Position that faces basePos across the field, by battle rule. */
u8 func_021B8C5C(int rule, u32 basePos)
{
    u8 lane;

    switch (rule) {
    default:
    case 0:
        return func_021B8C20(rule, basePos, 0);
    case 1:
        lane = basePos >> 1;
        return func_021B8C20(rule, basePos, (u8)(1 ^ lane));
    case 2:
        lane = basePos >> 1;
        if (lane == 0) {
            lane = 2;
        } else if (lane == 2) {
            lane = 0;
        }
        return func_021B8C20(rule, basePos, lane);
    case 3:
        return func_021B8C20(rule, basePos, 0);
    }
}
