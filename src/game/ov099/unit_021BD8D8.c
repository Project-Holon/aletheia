/*
 * file:     unit_021BD8D8.c
 * unit:     yes
 * function: func_021BD8D8, func_021BD924, func_021BD994, func_021BD9B4, func_021BD9F4, func_021BDA3C, func_021BDAA4, func_021BDAC8, func_021BDB08, func_021BDB30, func_021BDC0C, func_021BDC44, func_021BDCD0, func_021BDCE0, func_021BDCF4, func_021BDD0C, func_021BDD48, func_021BDD54, func_021BDD60, func_021BDD98, func_021BDDA8, func_021BDDB4, func_021BDDD0, func_021BDDF4, func_021BDE30, func_021BDE94, func_021BDF7C, func_021BE028, func_021BE030, func_021BE040, func_021BE21C, func_021BE244, func_021BE26C, func_021BE2A8, func_021BE2DC, func_021BE384, func_021BE3CC, func_021BE448, func_021BE4BC, func_021BE4EC, func_021BE4F0, func_021BE538, func_021BE53C, func_021BE5B4, func_021BE5B8, func_021BE600, func_021BE6B0, func_021BE6E4, func_021BE6F0, func_021BE788, func_021BE7EC, func_021BE900, func_021BE904, func_021BE94C, func_021BE96C, func_021BE9C8, func_021BEAEC, func_021BEB68, func_021BEBE8, func_021BEC60, func_021BED08, func_021BED3C, func_021BEDA0, func_021BEE64, func_021BEE94, func_021BEEBC, func_021BF000
 * address:  0x021BD8D8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C2864 0x021C2864 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   GFL_NET_NotifyUserEvent 0x0203D1E8 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_02039C68 0x02039C68 arm
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BC104 0x021BC104 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   func_020362DC 0x020362DC arm
 *   d_021C390C 0x021C390C data ov099 a4
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_0201283C  0x0201283C  thumb
 *   func_02009860  0x02009860  thumb
 *   func_020099C8  0x020099C8  thumb
 *   func_02009C24  0x02009C24  thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_CopyInitParam  0x0203D844  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   d_021C3B9C     0x021C3B9C  data
 *   func_021C27D0  0x021C27D0  thumb
 *   func_021C27D8  0x021C27D8  thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA1C 0x0201AA1C thumb
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02043534 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0204363C 0x0204363C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020434DC 0x020434DC arm
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   data_021C3AA0  0x021C3AA0  data
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020414C4 0x020414C4 arm
 *   func_0204047C 0x0204047C arm
 *   d_021C37F4 0x021C37F4 data a4
 *   d_021C396C 0x021C396C data a4
 *   d_021C382C 0x021C382C data a4
 *   d_021C384C 0x021C384C data a4
 *   d_021C386C 0x021C386C data a4
 *   d_021C38AC 0x021C38AC data a4
 *   d_021C38CC 0x021C38CC data a4
 *   d_021C392C 0x021C392C data a4
 *   d_021C394C 0x021C394C data a4
 *   func_021B9670 0x021B9670 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9A50  0x021B9A50  thumb  ov099
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_02042FB0  0x02042FB0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_021C27E8  0x021C27E8  thumb  ov099
 *   func_021C0C7C  0x021C0C7C  thumb  ov099
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   GFL_USE_GetTargetBgmNo 0x02005C4C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   sub_0204047C  0x0204047C  arm
 *   DWC_RAP_SetOwnStatus  0x0215683C  thumb  ov009
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021C1908 0x021C1908 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C2050 0x021C2050 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021B9B00 0x021B9B00 thumb ov099
 *   func_02009918 0x02009918 thumb
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   CLACT_FlushOamIfPending 0x0204A698 arm
 *   func_020452E8 0x020452E8 arm
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   func_021BB050 0x021BB050 thumb ov099
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DWC_RAP_ClearUserDataChanged 0x02156C98 thumb ov009
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 *   GFL_NET_STATE_IsWifiLoginOrConnected 0x0203C628 arm
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BAB04 0x021BAB04 thumb ov099
 *   func_02009A34 0x02009A34 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   DWC_RAP_SetAcceptFriendCallback 0x02155664 thumb ov009
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C0290 0x021C0290 thumb ov099
 *   func_02009A54 0x02009A54 thumb
 *   func_021B95A0 0x021B95A0 thumb ov099
 *   func_021B9900 0x021B9900 thumb ov099
 *   func_021C1A58 0x021C1A58 thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C205C 0x021C205C thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
#include "work_types.h"
#include "../../matched/include/Obj22042.h"
#include "../../matched/include/Obj05265.h"
#include "../../matched/include/Obj22044.h"
#include "../../matched/include/Obj22045.h"
#include "../../matched/include/Obj22046.h"
#include "../../matched/include/Obj22047.h"
#include "../../matched/include/Obj10207.h"
#include "../../matched/include/Obj18261.h"

struct Entry;
struct Link;
struct BigObj;
struct Sub020097BCObj;
struct Sub020097BCFriend;
struct Req;
struct GfFont;
struct MsgBank;
struct Node;
struct WordSet;
struct Bank;
struct Rec;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Obj;
struct Sub0200852CObj;
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u16 a, b; } Request;

typedef unsigned int   u32_021BD8D8;

typedef unsigned int   u32_021BD924;

typedef unsigned long  u32_021BD994;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BD9B4;

typedef unsigned int u32_021BD9F4;

typedef unsigned long  u32_021BDAA4;

typedef unsigned int   u32_021BDAC8;

typedef unsigned long  u32_021BDB08;

typedef unsigned int u32_021BDB30;

typedef unsigned int u32_021BDC0C;

typedef struct { int v[8]; } Table;

typedef unsigned int   u32_021BDC44;

typedef unsigned long  u32_021BDCD0;

typedef unsigned long  u32_021BDCE0;

typedef unsigned long  u32_021BDCF4;

typedef struct {
    char pad[0x48];
    int f48;                /* 0x48 */
} Snd;

typedef unsigned int   u32_021BDD0C;

typedef unsigned long  u32_021BDD48;

typedef struct {
    char pad[0x18];
    u8 f18;
} S_021BDD48;

typedef unsigned long  u32_021BDD54;

typedef unsigned long  u32_021BDD60;

typedef unsigned long  u32_021BDDA8;

typedef unsigned long  u32_021BDDB4;

typedef unsigned int u32_021BDDD0;

typedef unsigned int   u32_021BDDF4;

typedef unsigned int   u32_021BDE30;

typedef unsigned int u32_021BDE94;

typedef unsigned int   u32_021BDF7C;

typedef unsigned long  u32_021BE030;

typedef unsigned int u32_021BE040;

typedef struct { u32_021BE040 a, b, c, d; } Disp;

typedef struct { u32_021BE040 a, b, c, d; u8 e, f, g, h; u32_021BE040 i; u8 j, k, l, m; u32_021BE040 n; } Bg;

typedef unsigned long  u32_021BE21C;

typedef unsigned long  u32_021BE244;

typedef unsigned long  u32_021BE2A8;

typedef unsigned int u32_021BE2DC;

typedef unsigned long  u32_021BE384;

typedef struct {
    void *f00;
    char pad[4];
    void *f08;
    char pad2[4];
    u32_021BE384 f10;
    u32_021BE384 f14;
} S_021BE2DC;

typedef unsigned int u32_021BE3CC;

typedef unsigned int u32;

typedef unsigned int u32_021BE53C;

typedef unsigned int u32_021BE5B8;

typedef unsigned long u32_021BE600;

typedef unsigned long u32_021BE6B0;

typedef struct {
    char pad[0x1CC];
    u32_021BE6B0 f1CC;
} S;

typedef unsigned long  u32_021BE6E4;

typedef unsigned int u32_021BE6F0;

typedef struct {
    u32_021BE6F0 f0, f4;
    u8 pad8[12];
    u8 f14, f15, f16, f17, f18, f19, f1a;
    u8 bits0:2;
    u8 bits2:2;
    u8 bits4:4;
} State;

typedef unsigned int u32_021BE7EC;

typedef struct { u8 low : 2; u8 flag : 2; u8 high : 4; } Flags;

typedef unsigned int u32_021BE904;

typedef unsigned long  u32_021BE94C;

typedef unsigned int u32_021BE96C;

typedef unsigned int u32_021BE9C8;

typedef unsigned int   u32_021BEC60;

typedef unsigned int u32_021BED3C;

typedef unsigned int   u32_021BEDA0;

typedef unsigned long  u32_021BEE64;

typedef unsigned int u32_021BEE94;

typedef unsigned int   u32_021BEEBC;

extern void func_021C2864(void *, u8);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32_021BD8D8 b, u32_021BD8D8 c, u32_021BD8D8 d);
extern unsigned int func_021BCBD8(char *p, int m);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern u32_021BD9B4 func_02039CB4(struct Link *, u32_021BD9B4, u32_021BD9B4);
extern void func_021C18C8(char *p, int kind, int value);
extern void GFL_NET_SetAutoExit(u8 a0);
extern int GFL_NET_SetLoginOption(int);
extern int GFL_NET_IsParentAid();
extern void func_021BAAB8(char *, int, int);
extern int GFL_NET_NotifyUserEvent(unsigned int unused, void *arg);
extern void func_021BA874(void *, int);
extern void func_021BC090(char *);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern int func_021BA928();
extern void func_021BA828(char *p);
extern void func_0201DD68(void);
extern u32_021BDAC8 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BC104(char *);
extern void func_021C24A4(void *, int);
extern void func_021BAADC(char *, int, int);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BDB30 *mask);
extern int func_021BCBBC(int, int, int *);
extern void *GFL_NET_GetInitParam(void);
extern u32_021BDC0C func_020362DC(void);
extern int func_021C23C8(void *a, void *b);
extern void func_021C23D8(char *, int);
extern u32_021BDCD0 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);
extern int OS_IsRunOnTwl(void);
extern void GFL_NET_StartSession(struct Req *req, u32_021BDD0C a2, u32_021BDD0C a3);
extern void GFL_NET_CopyInitParam(void *dst);
extern u8 func_021C27D0(S_021BDD48 *s);
extern u8 func_021C27D8(S_021BDD48 *s);
extern u32_021BDDD0 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern u32_021BDDD0 func_0201AA1C(void *);
extern void GFL_NET_SetWaitMode(int);
extern void func_02030EAC(struct Node *n);
extern void func_02043534(u32_021BDE94);
extern void BG_SYS_SetSubVisiblePlanes(u32_021BDE94);
extern void *func_020490F4(u32_021BDE94 id, u32_021BDE94 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct WordSet *func_0201EC64(u32_021BDE94 heap);
extern struct MsgBank *func_02045B38(u32_021BDE94 resident, u32_021BDE94 arcId, u32_021BDE94 fileId, u32_021BDE94 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32_021BDE94 heapId);
extern void func_0204363C(u32_021BDE94);
extern void BMP_WIN_Init(u16);
extern void *func_020056A0(u32_021BDE94, u32_021BDE94, u32_021BDE94);
extern void func_020434DC(u32_021BDE94, u32_021BDE94);
extern void func_021BB42C(void *p);
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern int func_021B96CC(int *p);
extern int func_021C1A44(char *p);
extern void func_021C1AC0(char *p);
extern void CLACT_DeleteRenderer(void *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_021BB0B4(char *p);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32_021BDF7C GF_FONT_Delete(void *ptr);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32_021BE040 bgId, const struct BgTemplate *tmpl, u32_021BE040 type);
extern void func_020414AC(u32_021BE040);
extern void func_020409B4(u32_021BE040);
extern void func_02040C14(u32_021BE040, u32_021BE040, u32_021BE040, u32_021BE040);
extern void func_020414C4(u32_021BE040 idx);
extern void func_0204047C(int, u16);
extern void func_021B9670(char *);
extern void func_021C203C(char *,int);
extern void func_02082BCC(void *,int,int);
extern u8 func_021B9A50(char *p);
extern void func_02049B68(void *a, u32_021BE2DC b, u32_021BE2DC c, u32_021BE2DC d, u32_021BE2DC e, u16 f);
extern u32_021BE2DC func_02049740(void *a0, u32_021BE2DC a1, u32_021BE2DC a2, u32_021BE2DC a3, u32_021BE2DC a4, u16 flags);
extern void *func_02049E74(void *a0, u32_021BE2DC a1, u32_021BE2DC a2, u32_021BE2DC a3, u16 a4);
extern void *func_02049EF4(void *, u32_021BE2DC, u32_021BE2DC, void **, u16);
extern u32_021BE384 func_020307B0(void *p);
extern void func_0203FB44(u32_021BE384 layer, u32_021BE384 offset, u32_021BE384 size);
extern void func_02042FB0(u32_021BE3CC idx, u32_021BE3CC x, u32_021BE3CC y, u16 value);
extern void func_02041B6C(u32_021BE3CC bit);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C27E8(void *, u8);
extern void func_021C0C7C(void);
extern void BG_SYS_SetSubPlaneVisible(u32_021BE53C mask, u32_021BE53C enable);
extern void func_02049B40(u32_021BE53C a, u32_021BE53C b, u32_021BE53C c, u32_021BE53C d, u32_021BE53C e, u16 f);
extern void *func_0201F5DC(void *a0, u32_021BE53C a1, u32_021BE53C a2, u32_021BE53C a3);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32_021BE5B8 arg, u32_021BE5B8 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32_021BE5B8 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32_021BE5B8 a1, u32_021BE5B8 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_021C24D4(u8 *p, int v);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int DWC_RAP_IsDisconnected(void);
extern void DWC_RAP_StopVchat(void);
extern u32_021BE600 GFL_USE_GetTargetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void sub_0204047C(int idx, unsigned short val);
extern int DWC_RAP_SetOwnStatus(char *a, int b);
extern u8 *func_02012944(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32_021BE6F0 func_02008530(const struct Sub0200852CObj *obj);
extern u32_021BE6F0 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_021C1908(char *, int, int);
extern unsigned char func_021C23C0(void *a);
extern int func_021C23B8(int i);
extern u8 func_021C2050(char *p, int i);
extern int func_021C27E0(void *);
extern void func_021B9B00(void *, char *, u8);
extern void func_02009918(struct Sub020097BCObj *obj, u32_021BE7EC i, u32_021BE7EC field, u32_021BE7EC value);
extern int func_021BA8BC(void *p);
extern int GFL_NET_Exit(int a0);
extern u32_021BE9C8 GFL_NET_IsIdle(void);
extern void CLACT_FlushOamIfPending(void);
extern u32_021BE9C8 func_020452E8(struct Descriptor *d);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32_021BE9C8 BMP_MENUWORK_Delete(void *p);
extern void func_021BB050(void *);
extern void GFL_NET_STATE_WifiStartMatch(void);
extern unsigned char DWC_RAP_IsUserDataChanged(void);
extern int GFL_NET_STATE_IsWifiLoginState(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
extern void DWC_RAP_ClearUserDataChanged(int v);
extern void POKE_REGULATION_DeleteText(void *);
extern int GFL_NET_STATE_IsWifiLoginOrConnected(void);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
extern u32_021BEC60 GFL_NET_IsConnectMember(u32_021BEC60 index);
extern void GFL_NET_STATE_WifiDisconnect(u32_021BEC60 a);
extern unsigned int func_0202EB0C(void);
extern void func_021BAB04(void *p, int message);
extern u32_021BED3C func_02009A34(struct Sub020097BCObj *obj);
extern u32_021BEDA0 BMP_WIN_Create(u32_021BEDA0 layer, u32_021BEDA0 a, u32_021BEDA0 b, u32_021BEDA0 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void DWC_RAP_SetAcceptFriendCallback(void (*callback)(void));
extern void func_021C19A8(char *);
extern void func_021C0290(char *);
extern u32_021BEEBC func_02009A54(struct Sub020097BCObj *obj);
extern void func_021B95A0(char *p, int heap, u32_021BEEBC x2, u32_021BEEBC x3, u32_021BEEBC a4, u32_021BEEBC a5, u32_021BEEBC a6, u32_021BEEBC a7);
extern u8 *func_021B9900(u8 *p, int v);
extern void func_021C1A58(char *,int,int);
extern int func_021C282C(u8 *p);
extern void func_021C205C(u8 *p, int v);
extern void func_021C2408(char *);
int func_021BD8D8(char *p, int ret);
int func_021BD924(char *p, int v);
int func_021BD97C(char *p, int v);
int func_021BD994(void *v, int b);
int func_021BD9B4(char *p, int v);
int func_021BD9F4(char *p, int v);
int func_021BDA3C(char *p, int v);
int func_021BDAA4(char *p, int v);
int func_021BDAC8(char *p, int result);
int func_021BDB08(char *p, int v);
int func_021BDB30(char *p, int v);
int func_021BDC0C(char *p, int v);
int func_021BDC44(char *p, int v);
void func_021BDCD0(char *p);
void func_021BDCE0(char *p);
void func_021BDCF4(int a, int b, char *p);
void func_021BDD0C(void *p, int on);
int func_021BDD48(int unused, S_021BDD48 *s);
int func_021BDD54(int unused, S_021BDD48 *s);
int func_021BDD60(int x);
int func_021BDD98(int x);
BOOL func_021BDDA8(int x);
BOOL func_021BDDB4(int a, void *b);
int func_021BDDD0(char *p);
int func_021BDDF4(char *p);
void func_021BDE30(void *p, int kind, int value);
void func_021BDE94(char *p);
void func_021BDF7C(char *p);
void func_021BE028(void);
void func_021BE030(void);
void func_021BE040(u16 heap);
void func_021BE21C(char *p, void *v);
void func_021BE244(char *p, void *v);
void func_021BE26C(char *p);
void *func_021BE2A8(char *p, int key);
void func_021BE2DC(char *p, int a, int b);
void func_021BE384(S_021BE2DC *s);
void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BE3CC d, int e);
int func_021BE448(unsigned int a, int b);
void func_021BE4BC(char *p,int a,u8 b,u8 c,int d,unsigned int e,int f);
int func_021BE4EC(int a);
int func_021BE4F0(char *p, int v);
void func_021BE538(char *p);
void func_021BE53C(char *p, int v);
void func_021BE5B4(void *a0);
void func_021BE5B8(char *p, void *a1);
int func_021BE600(char *p, int ret);
int func_021BE6B0(S *s, int b);
void func_021BE6E4(char *s);
void func_021BE6F0(char *p, int a, int b);
int func_021BE788(char *p);
int func_021BE7EC(char *p);
void func_021BE900(char *p);
int func_021BE904(char *p, int v);
int func_021BE94C(char *p, int v);
int func_021BE96C(char *p, int v);
int func_021BE9C8(char *p, int v);
int func_021BEAEC(char *p, int ret);
int func_021BEB68(char *p, int ret);
int func_021BEBE8(char *p, int result);
int func_021BEC60(char *p, int ret);
int func_021BED08(char *p,int ret);
int func_021BED3C(char *p, int ret);
void func_021BEDA0(char *p);
BOOL func_021BEE64(void *a, char *b);
int func_021BEE94(u32_021BEE94 p, int a);
void func_021BEEBC(char *p);
int func_021BF000(char *p,int ret);
extern const Table d_021C390C;
extern Snd d_021C3B9C;
extern u8 data_021C3AA0[];
extern const Disp d_021C37F4;
extern const Bg d_021C396C, d_021C382C, d_021C384C, d_021C386C;
extern const Bg d_021C38AC, d_021C38CC, d_021C392C, d_021C394C;
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];


int func_021BD8D8(char *p, int ret)
{
    Request request;
    request.a = func_021BDD54((int)p, (S_021BDD48 *)((Ov099Work *)p)->f8);
    request.b = 1 - ((struct Obj22042 *)((char *)((Ov099Work *)p)->f248))->f46;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa03, 4, (unsigned)&request) != 0) {
        ((Ov099Work *)p)->f1CC = 0x81;
        func_021C2864(((Ov099Work *)p)->f8, request.b);
    }
    return ret;
}


int func_021BD924(char *p, int v)
{
    int t;
    if (((Ov099Work *)p)->f1352 == 6) {
        ((Ov099Work *)p)->f1353 = 0x4d;
        ((Ov099Work *)p)->f1CC = 0x8a;
    } else {
        if (((Ov099Work *)p)->f135C == 3 || ((Ov099Work *)p)->f135C == 1) {
            t = func_021BCBD8(p, 1);
        } else {
            t = func_021BCBD8(p, 0);
        }
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa06, 4, (u32_021BD924)(&t)) != 0) {
            ((Ov099Work *)p)->f1CC = 0x82;
        }
    }
    return v;
}


int func_021BD97C(char *p, int v)
{
    ((Ov099Work *)p)->f1353 = 0x5e;
    ((Ov099Work *)p)->f1CC = 0x8a;
    return v;
}



/*
 * The result of the first arm9 call is the first argument of the second.
 * Returns the second argument.
 */
int func_021BD994(void *v, int b)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0x0A);
    ((Ov099Work *)v)->f1CC = 0x8B;

    return b;
}


int func_021BD9B4(char *p, int v)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa05, 1, (u32_021BD9B4)(p + 0x1353)) != 0) {
            ((Ov099Work *)p)->f1CC = 0x48;
        }
    }
    return v;
}


int func_021BD9F4(char *p, int v)
{
    int zero;
    func_021C18C8(p, 1, 2);
    zero = 0;
    ((Ov099Work *)p)->f135C = zero;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        func_021BAAB8(p, 0x73, zero);
    } else {
        func_021BAAB8(p, 0x7c, zero);
    }
    ((Ov099Work *)p)->f1CC = 0x8e;
    return v;
}


int func_021BDA3C(char *p, int v)
{
    int zero;
    zero = 0;
    if (GFL_NET_IsParentAid(GFL_NET_NotifyUserEvent((unsigned int)GFL_NET_HANDLE_GetCurrentHandle(), 0)) == 0) {
        func_021BA874(p, ((Ov099Work *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, zero);
        ((Ov099Work *)p)->f1CC = 0xaa;
    } else {
        func_021BA874(p, ((Ov099Work *)p)->f242 - 1);
        func_021BAAB8(p, 0x4c, zero);
        func_021BC090(p);
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10);
        ((Ov099Work *)p)->f1CC = 0x49;
    }
    return v;
}



int func_021BDAA4(char *p, int v)
{
    if (func_021BA928(p) == 0) {
        return v;
    }

    func_021BA828(p);
    ((Ov099Work *)p)->f1CC = 0xAB;
    return v;
}


/*
 * lever: unsigned byte stores materialize 0xa8 as movs, rather than a signed subtraction.
 */
int func_021BDAC8(char *p, int result)
{
    int v;
    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1) return result;
    if (v == 0) ((Ov099Work *)p)->f1353 = 0x44;
    else ((Ov099Work *)p)->f1353 = 0xa8;
    func_021BA8EC(p);
    ((Ov099Work *)p)->f1CC = 0x8a;
    return result;
}



int func_021BDB08(char *p, int v)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xA) == 0) {
        return v;
    }

    ((Ov099Work *)p)->f1CC = 0x79;
    return v;
}


int func_021BDB30(char *p, int v)
{
    u16 state;
    int out;
    state = (u16)func_021BDD54((int)p, (S_021BDD48 *)((Ov099Work *)p)->f8);
    switch (state) {
    case 4:
        GFL_NET_GetInitParam();
        func_021BC104(p);
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
        ((Ov099Work *)p)->f1355 = 0;
        ((Ov099Work *)p)->f1CC = 0x10;
        return v;
    case 5:
        ((Ov099Work *)p)->f1D0 = state;
        return 2;
    case 6:
        func_021BC104(p);
        ((Ov099Work *)p)->f1D0 = state;
        return 2;
    default:
        GFL_NET_NotifyUserEvent((u32_021BDB30)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        if (GFL_NET_IsParentAid()) {
            if (func_021BCB70((void *)(((Ov099Work *)p)->f1348), (const struct BigObj *)((int)((Ov099Work *)p)->fC4), (u32_021BDB30 *)(&out)) &&
                func_021BCBBC(((Ov099Work *)p)->f1348, ((Ov099Work *)p)->fCC, &out)) {
                func_021BAAB8(p, 0x68, 0);
                ((Ov099Work *)p)->f1CC = 0x74;
                return v;
            }
            ((Ov099Work *)p)->f1CC = 0x5b;
        } else {
            func_02039C68((void *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
            ((Ov099Work *)p)->f1CC = 0x49;
        }
        return v;
    }
}


int func_021BDC0C(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        ((Ov099Work *)p)->f1353 = 0x4a;
        ((Ov099Work *)p)->f1CC = 0x8a;
    }
    return v;
}


int func_021BDC44(char *p, int v)
{
    Table t;
    func_021BCBD8(p, 1);
    if (func_021BDDF4(p) == 0) {
        func_021BAAB8(p, 0x68, 0);
        ((Ov099Work *)p)->f1CC = 0x63;
        return v;
    }
    t = d_021C390C;
    func_021C18C8(p, 2, (u16)t.v[((Ov099Work *)p)->f134E + ((Ov099Work *)p)->f134C * 2]);
    func_021C23C8(p, (void *)(-1));
    ((Ov099Work *)p)->f1CC = 0x9e;
    func_021C23D8(p, 1);
    return v;
}



/*
 * Hands the handle at +0xC4 to one arm9 accessor and its result to another.
 */
void func_021BDCD0(char *p)
{
    func_02009860((struct Sub020097BCObj *)func_0201283C(((Ov099Work *)p)->fC4));
}



/*
 * Two arm9 calls: the pointer at +0xC4 goes through the first and the answer into the second with a zero selector.
 */
void func_021BDCE0(char *p)
{
    func_020099C8((struct Sub020097BCObj *)func_0201283C(((Ov099Work *)p)->fC4), 0);
}



/*
 * Same handle at +0xC4 of the third argument, its accessor result forwarded
 * together with the first two arguments.
 */
void func_021BDCF4(int a, int b, char *p)
{
    func_02009C24((struct Sub020097BCObj *)func_0201283C(((Ov099Work *)p)->fC4), a, b);
}



void func_021BDD0C(void *p, int on)
{
    if (OS_IsRunOnTwl())
        d_021C3B9C.f48 = 0x79000;
    else
        d_021C3B9C.f48 = 0x5e400;
    if (on)
        GFL_NET_StartSession((struct Req *)(&d_021C3B9C), 0, (u32_021BDD0C)p);
    else
        GFL_NET_CopyInitParam(&d_021C3B9C);
}




int func_021BDD48(int unused, S_021BDD48 *s)
{
    return func_021C27D0((S_021BDD48 *)s);
}




/*
 * Tail call onto the byte getter func_021C27D8 on the second argument.
 */
int func_021BDD54(int unused, S_021BDD48 *s)
{
    return func_021C27D8((S_021BDD48 *)s);
}




int func_021BDD60(int x)
{
    switch (x) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 1;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        return 0;
    }
}



int func_021BDD98(int x) {
    if (x < 15 && x > 3) return 1;
    return 0;
}




/*
 * True when the argument is 2.
 */
BOOL func_021BDDA8(int x)
{
    if (x == 2) {
        return 1;
    }

    return 0;
}




/*
 * True when the arm9 predicate accepts b and the selector is 4.
 */
BOOL func_021BDDB4(int a, void *b)
{
    if (func_021BDD60((int)b) != 0 && a == 4) {
        return 1;
    }

    return 0;
}



int func_021BDDD0(char *p)
{
    func_0201293C(((Ov099Work *)p)->fC4);
    if ((int)func_0201AA1C(func_02012934(((Ov099Work *)p)->fC4)) >= 2) return 1;
    return 0;
}



int func_021BDDF4(char *p) {
 int out;
 if (func_021BCB70((void *)(((Ov099Work *)p)->f1348),(const struct BigObj *)((int)((Ov099Work *)p)->fC4),(u32_021BDDF4 *)(&out)) && func_021BCBBC(((Ov099Work *)p)->f1348,((Ov099Work *)p)->fCC,&out)) return 0;
 return 1;
}



void func_021BDE30(void *p, int kind, int value)
{
    if (kind == 1) {
        GFL_NET_SetWaitMode(0);
        func_021BDD0C(p, 0);
    } else {
        if (func_021BDDB4(kind, (void *)value)) GFL_NET_SetWaitMode(1);
    }
    switch (kind) {
    case 2:
    case 5:
        GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        return;
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        break;
    }
}



/*
 * prototypes: 49238 SDK asm reads r0 despite its void(void) declaration; caller-visible handle preserved. Empty 021BE5B4 preserves caller-loaded live r0; 021BE5B8 preserves visible r1 despite no body read.
 * volatile: RMW display registers read at 021BDEB4/021BDEC0 and written at 021BDEBC/021BDEC4.
 */
void func_021BDE94(char *p)
{
    void *h;
    if (((Ov099Work *)p)->f0 != 0) func_02030EAC(((Ov099Work *)p)->f0);
    func_02043534(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u32_021BDE94 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32_021BDE94 *)0x04001000 &= 0xffffe0ff;
    h = func_020490F4(0x21, 0x21);
    ((Ov099Work *)p)->fDC = func_0201EC64(0x21);
    ((Ov099Work *)p)->fE0 = func_02045B38(0, 2, 0xd1, 0x21);
    ((Ov099Work *)p)->fE4 = func_02045B38(0, 2, 0xe8, 0x21);
    ((Ov099Work *)p)->fE8 = GF_FONT_Create(0x17, 0, 0, 0, 0x21);
    ((Ov099Work *)p)->fEC = GF_FONT_Create(0x17, 3, 0, 0, 0x21);
    func_0204363C(1);
    func_021BE030();
    func_021BE040(0x21);
    BMP_WIN_Init(0x21);
    func_021BE53C(p, (int)h);
    ((Ov099Work *)p)->f0 = func_020056A0((u32_021BDE94)func_021BE028, (u32_021BDE94)p, 1);
    func_021BE5B4(((Ov099Work *)p)->f0);
    func_021BE5B8(p, h);
    func_020434DC(0x10, 1);
    ARC_TOOL_DeleteHandle(h);
}



void func_021BDF7C(char *p)
{
    if (((Ov099Work *)p)->f0 != 0) func_02030EAC(((Ov099Work *)p)->f0);
    func_021BB42C(p);
    func_021BB4D0(p);
    func_021BB4EC(p);
    if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
    if (func_021C1A44(p) == 1) func_021C1AC0(p);
    func_021BE384((S_021BE2DC *)(p + 0x898));
    CLACT_DeleteRenderer(((Ov099Work *)p)->f114);
    CLACT_DeleteUnit(((Ov099Work *)p)->f110);
    CLACT_ExitSystem();
    func_021BB0B4(p);
    func_021BE538(p);
    BMP_WIN_Exit();
    func_0203F9B4();
    MSGDATA_Delete(((Ov099Work *)p)->fE4);
    MSGDATA_Delete(((Ov099Work *)p)->fE0);
    func_0201ED04(((Ov099Work *)p)->fDC);
    GF_FONT_Delete(((Ov099Work *)p)->fEC);
    GF_FONT_Delete(((Ov099Work *)p)->fE8);
}



void func_021BE028(void)
{
    CLACT_VBlankSystem();
}




void func_021BE030(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)data_021C3AA0);
}



void func_021BE040(u16 heap)
{
    Disp d;
    Bg b0, b1, b2, b3, b4, b5, b6, b7;
    int i;
    func_0203F8F4(heap);
    d = d_021C37F4;
    func_0203FC28((struct DispConfig *)(&d));
    b0 = d_021C396C;
    i = 0;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414AC(0);
    func_020409B4(0);
    b1 = d_021C382C;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    func_020414AC(1);
    func_020409B4(1);
    b2 = d_021C384C;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
    func_02040C14(2, 0, 1, 0);
    func_020414AC(2);
    func_020409B4(2);
    b3 = d_021C386C;
    func_0203FCA0(3, (const struct BgTemplate *)(&b3), 0);
    func_020414AC(3);
    func_020409B4(3);
    b4 = d_021C38AC;
    func_0203FCA0(4, (const struct BgTemplate *)(&b4), 0);
    func_020414AC(4);
    b5 = d_021C38CC;
    func_0203FCA0(5, (const struct BgTemplate *)(&b5), 0);
    func_020414AC(5);
    b6 = d_021C392C;
    func_0203FCA0(6, (const struct BgTemplate *)(&b6), 0);
    func_020414AC(6);
    b7 = d_021C394C;
    func_0203FCA0(7, (const struct BgTemplate *)(&b7), 0);
    func_020414AC(7);
    for (; i < 7; i++) func_020414C4((u8)i);
    func_0204047C(0, 3);
    func_0204047C(1, 1);
    func_0204047C(3, 1);
    func_0204047C(2, 0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}




void func_021BE21C(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == 0) {
            *(void **)(p + i * 4 + 0x814) = v;
            return;
        }
    }
}




/*
 * Clears the first slot of the table at +0x814 that holds v.
 */
void func_021BE244(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == v) {
            *(void **)(p + i * 4 + 0x814) = 0;
            return;
        }
    }
}



void func_021BE26C(char *p) {
 int i;
 func_021B9670(p+0x274);
 for (i=0;i<33;i++) {
  *(int *)((unsigned int)p+(unsigned int)i*4+0x814)=0;
  func_021C203C(p,i+1);
 }
 func_02082BCC(p+0x50,0,32);
}




void *func_021BE2A8(char *p, int key)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(u32_021BE2A8 *)(p + i * 4 + 0x814) != 0 &&
            func_021B9A50(*(char **)(p + i * 4 + 0x814)) == key) {
            return *(void **)(p + 0x814 + i * 4);
        }
    }
    return 0;
}



void func_021BE2DC(char *p, int a, int b)
{
    func_02049B68((void *)a, 4, 0, 0x100, 0x80, b);
    func_02049B68((void *)a, 4, 4, 0x100, 0x80, b);
    ((struct Obj05265 *)p)->f10 = func_02049740((void *)a, 13, 1, 0, 0, b);
    ((struct Obj05265 *)p)->f14 = func_02049740((void *)a, 13, 6, 0, 0, b);
    if (((struct Obj05265 *)p)->f8 == 0) {
        ((struct Obj05265 *)p)->f8 = func_02049E74((void *)a, 13, 0, (u32_021BE2DC)(p + 12), b);
    }
    if (((struct Obj05265 *)p)->f0 == 0) {
        ((struct Obj05265 *)p)->f0 = func_02049EF4((void *)a, 21, 0, (void **)(p + 4), b);
    }
}




void func_021BE384(S_021BE2DC *s)
{
    if (s->f00 != 0) {
        func_020307B0(s->f00);
        s->f00 = 0;
    }

    if (s->f08 != 0) {
        func_020307B0(s->f08);
        s->f08 = 0;
    }

    func_0203FB44(1, (u16)s->f10, (u16)(s->f10 >> 16));
    func_0203FB44(6, (u16)s->f14, (u16)(s->f14 >> 16));
}




void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BE3CC d, int e)
{
    int row;
    u32_021BE3CC stride;
    u16 *base;
    int i, j;
    int t;

    base = (u16 *)(*(char **)(p + 4) + 0xC);
    t = func_021BE4EC(a);
    row = (d >> 4) * 2;
    stride = (u32_021BE3CC)**(u16 **)(p + 4) >> 3;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02042FB0(a, j + b, i + c, (t << 12) + (base + (d & 0xF) * 2)[(row + i) * stride + j]);
        }
    }
    func_02041B6C((u8)a);
}



int func_021BE448(unsigned int a, int b)
{
    int r = 15;
    switch (a) {
    case 4:
        if (b == 2) r = 4;
        else r = 3;
        break;
    case 5:
        if (b == 2) r = 6;
        else r = 5;
        break;
    case 6:
        if (b == 2) r = 10;
        else r = 9;
        break;
    case 2: r = 2; break;
    case 0: r = 15; break;
    case 3: r = 1; break;
    default:
        if (func_021BDD60(a) != 0) {
            if (b == 2) r = 8;
            else r = 7;
        } else if (a >= 15) {
            r = 14;
        }
        break;
    }
    return r;
}



/*
 * Extent ends with two-byte alignment padding at 0x021BE4EA.
 */
void func_021BE4BC(char *p,int a,u8 b,u8 c,int d,unsigned int e,int f) {
 int value;
 value=func_021BE448(e,d);
 func_021BE3CC(p,a,b,c,value+f,0);
}



/*
 * Returns the constant 8.
 */
int func_021BE4EC(int a)
{
    return 8;
}




int func_021BE4F0(char *p, int v)
{
    if (v != 0)
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x21);
    func_021C27E8(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C2864(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C0C7C();
    return 9;
}



void func_021BE538(char *p)
{
}




void func_021BE53C(char *p, int v)
{
    u32_021BE53C k = 0xF;
    func_020434DC(0xF, 1);
    BG_SYS_SetSubPlaneVisible(0xD, 1);
    func_021BE2DC(p + 0x898, v, 0x21);
    func_02049B40(0x17, 5, 0, k << 5, 0x20, 0x21);
    *(void **)(p + 0x1330) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1334) = func_0201F5DC((void *)2, 0xE, 0, 0x21);
    *(void **)(p + 0x1338) = func_0201F5DC((void *)1, 0xE, 0, 0x21);
}



/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021BE5B4(void *a0)
{
}




/*
 * note: 2026-10-05 (wD6 lane13): EXACT. func_0204B258 takes two arguments (bank, p); the second is the
 * value stored at p + 0x114. The 0x110/0x114 offsets are plain literals: mwcc derives them from the 0x64
 * count constant by itself.
 */
void func_021BE5B8(char *p, void *a1)
{
    CLACT_InitSystem((const struct Cfg *)d_021C3740, (u32_021BE5B8)d_021C3AA0, 0x21);
    *(void **)(p + 0x110) = CLACT_CreateUnit(0x64, 0, 0x21);
    *(void **)(p + 0x114) = CLACT_CreateRenderer(d_021C375C, 2, 0x21);
    func_0204B258(*(void **)(p + 0x110), *(void **)(p + 0x114));
}



int func_021BE600(char *p, int ret)
{
    if (((struct Obj22044 *)((char *)((Ov099Work *)p)->f248))->fC) {
        func_021C24D4((u8 *)p, 4);
        func_02009B80(((Ov099Work *)p)->f4, DWC_RAP_GetTargetFriendIndex());
        if ((unsigned)(((Ov099Work *)p)->f135C - 3) <= 1 && !DWC_RAP_IsDisconnected()) {
            DWC_RAP_StopVchat();
            func_021BEEBC(p);
            ((Ov099Work *)p)->f242 = ((struct Obj22045 *)((char *)((Ov099Work *)p)->f248))->f47;
            func_021C18C8(p, 4, 3);
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xa);
            ((Ov099Work *)p)->f1CC = 0xac;
        } else {
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x12, 0xa);
            ((Ov099Work *)p)->f1CC = 0x93;
        }
    } else {
        ((Ov099Work *)p)->f1CC = 9;
        func_021C24D4((u8 *)p, 1);
    }
    if (GFL_USE_GetTargetBgmNo() != 0x424) GFL_USE_CancelChangeAndPlayBgm(0x424, 0xffff);
    return ret;
}




int func_021BE6B0(S *s, int b)
{
    sub_0204047C(0, 3);
    sub_0204047C(1, 1);
    sub_0204047C(3, 1);
    sub_0204047C(2, 0);
    s->f1CC = 6;

    return b;
}




/*
 * Hands the pointer at +0x08 to the ov009 routine with selector 0x20.
 */
void func_021BE6E4(char *s)
{
    DWC_RAP_SetOwnStatus(((Ov099Work *)s)->f8, 0x20);
}



/*
 * extent: two zero padding bytes at 0x021BE786.
 * lever: a named u8 local narrows the accessor result before bitfield masking.
 */
void func_021BE6F0(char *p, int a, int b)
{
    void *q;
    u8 t;
    q = func_02012944(((Ov099Work *)p)->fC4);
    ((State *)((Ov099Work *)p)->f8)->f15 = 0x15;
    ((State *)((Ov099Work *)p)->f8)->f16 = 2;
    t = (int)func_02008550(q);
    ((State *)((Ov099Work *)p)->f8)->bits2 = t;
    ((State *)((Ov099Work *)p)->f8)->f14 = func_02008554(q);
    func_021C1908(p, a, b);
    ((State *)((Ov099Work *)p)->f8)->f19 = func_0200856C(q);
    ((State *)((Ov099Work *)p)->f8)->f1a = func_02008570(q);
    func_021C27E8(((Ov099Work *)p)->f8, ((struct Obj22046 *)((char *)((Ov099Work *)p)->f248))->f46);
    func_021C2864(((Ov099Work *)p)->f8, ((struct Obj22047 *)((char *)((Ov099Work *)p)->f248))->f46);
    ((State *)((Ov099Work *)p)->f8)->f4 = func_02008530(q);
    ((State *)((Ov099Work *)p)->f8)->f0 = func_0200853C(q);
    func_021BE6E4(p);
}



int func_021BE788(char *p)
{
    int count = 0;
    int i;
    unsigned value;
    for (i = 0; i < 32; i++) {
        *(u8 *)(p + i + 0x10) = 0;
        if (((Ov099Work *)p)->f132A > i && func_021C23C0((void *)i)) {
            value = func_021BDD48((int)p, (S_021BDD48 *)func_021C23B8(i));
            if (value != 0 && value < 6) {
                *(u8 *)(p + count + 0x10) = i + 1;
                count++;
            } else if (func_021C2050(p, i + 1)) {
                func_021C203C(p, i + 1);
            }
        }
    }
    return count;
}


/*
 * lever: byte bitfield preserves the original left/right shift extraction; declaration order preserves local stack slots.
 * prototypes: C23B8 own tail forwarder void(void) preserves loaded index and live pointer return; C23C0 own void forwarder leaves R0 live for the original test; BDD48/BDD54 own u8 returns are widened to preserve original explicit result truncations.
 */
int func_021BE7EC(char *p)
{
    int count = 0;
    int i;
    char *s, *h;
    u8 a, b;
    int old, next;
    for (i = 0; i < 32; i++) {
        s = (char *)func_021C23B8(i);
        a = (u8)func_021BDD48((int)p, (S_021BDD48 *)s);
        b = (u8)func_021BDD54((int)p, (S_021BDD48 *)s);
        if (func_021C23C0((void *)i) == 0) a = 0;
        if (a != *(u8 *)(p + i + 0x50) ||
            b != *(u8 *)(p + i + 0x70) ||
            *(u8 *)(p + i + 0x90) != func_021C27E0(s)) {
            h = func_021BE2A8(p, i + 1);
            if (h != 0) {
                old = func_021BDDA8(*(u8 *)(p + i + 0x50));
                next = func_021BDDA8(a);
                if (old == 1 && next == 0) func_021B9B00(p + 0x274, h, 0);
                else if (old == 0 && next == 1) func_021B9B00(p + 0x274, h, 1);
                func_02009918(((Ov099Work *)p)->f4, i, 8, ((struct Obj10207 *)s)->f14);
                func_02009918(((Ov099Work *)p)->f4, i, 9, ((Flags *)(s + 0x1b))->flag);
                func_02009918(((Ov099Work *)p)->f4, i, 1, ((struct Obj10207 *)s)->f0);
                func_02009918(((Ov099Work *)p)->f4, i, 0, ((struct Obj10207 *)s)->f4);
            }
            *(u8 *)(p + i + 0x50) = a;
            *(u8 *)(p + i + 0x70) = b;
            *(u8 *)(p + i + 0x90) = func_021C27E0(s);
            count++;
        }
    }
    return count;
}


void func_021BE900(char *p)
{
}



int func_021BE904(char *p, int v)
{
    int n = *(int *)(p + 0x1E0);
    if (n > 0) {
        *(int *)(p + 0x1E0) = n - 1;
        return v;
    }
    if (func_020362DC() & 3) {
        *(int *)(p + 0x19C) = func_021BA8BC((void *)(*(int *)(p + 0x19C)));
        func_021BAAB8(p, 0x37, 0);
        *(int *)(p + 0x1CC) = 2;
    }
    return v;
}



/*
 * Runs the setup and stamps selector 3 when the guard answers true.
 */
int func_021BE94C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 3;
    }

    return v;
}


/*
 * extent: two trailing zero padding bytes at 0x021BE9C6.
 */
int func_021BE96C(char *p, int v)
{
    int t;
    int zero;
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        GFL_NET_Exit(0);
        func_021C18C8(p, 1, 2);
        ((Ov099Work *)p)->f1CC = 4;
    } else {
        func_021C18C8(p, 1, 2);
        zero = 0;
        GFL_NET_Exit(0);
        ((Ov099Work *)p)->f1D0 = zero;
        ((Ov099Work *)p)->f1CC = 0x1a;
    }
    func_021BA8EC(p);
    return v;
}


int func_021BE9C8(char *p, int v)
{
    void *h;
    if (GFL_NET_IsIdle() == 0) {
        if (func_021B96CC((int *)(p + 0x274)) == 1) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x21);
            func_021BE26C(p);
            CLACT_FlushOamIfPending();
        }
        if (func_021C1A44(p) == 1) func_021C1AC0(p);
        ((Ov099Work *)p)->f198 = (void *)func_021BA8BC(((Ov099Work *)p)->f198);
        func_020414AC(3);
        h = func_020490F4(0x21, 0x21);
        func_021BE53C(p, (int)h);
        ARC_TOOL_DeleteHandle(h);
        ((Ov099Work *)p)->f1328 = 1;
        if (((Ov099Work *)p)->fB0 != 0) {
            func_020452E8(((Ov099Work *)p)->f1A0);
            BMP_MENULIST_Delete(((Ov099Work *)p)->fB4, 0, 0);
            ((Ov099Work *)p)->fB4 = 0;
            BMP_MENUWORK_Delete(((Ov099Work *)p)->fB0);
            ((Ov099Work *)p)->fB0 = 0;
        }
        func_02082BCC(p + 0x10, 0, 0x20);
        func_02082BCC(p + 0x30, 0, 0x20);
        func_02082BCC(p + 0x50, 0, 0x20);
        func_02082BCC(p + 0x70, 0, 0x20);
        func_02082BCC(p + 0x90, 0, 0x20);
        func_021BB050(p);
        func_021BDD0C(p, 0);
        GFL_NET_STATE_WifiStartMatch();
        func_021BAAB8(p, 0x17, 1);
        ((Ov099Work *)p)->f1CC = 5;
    }
    return v;
}


int func_021BEAEC(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (DWC_RAP_IsUserDataChanged()) {
        *(int *)(p + 0x1cc) = 0x3c;
        func_021BAAB8(p, 0x1e, 1);
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else {
        if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) func_021BE900(p);
    }
    return ret;
}


/*
 * extent: 126 bytes code followed by two zero alignment bytes.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   int GFL_NET_STATE_IsWifiLoginState(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_WifiLoginMain;
 *   }
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 */
int func_021BEB68(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (DWC_RAP_IsUserDataChanged()) {
        GAME_DATA_SaveStart((int)(*(void **)(p + 0xc4)));
        *(int *)(p + 0x1cc) = 0x3e;
        return ret;
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else {
        if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) func_021BE900(p);
    }
    return ret;
}


int func_021BEBE8(char *p, int result)
{
    int v;
    if (DWC_RAP_IsUserDataChanged()) {
        v = GAME_DATA_SaveMain(*(u8 **)(p + 0xc4));
        switch (v) {
        default:
            DWC_RAP_ClearUserDataChanged(v);
            break;
        case 0:
        case 1:
            return result;
        }
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (*(int *)(p + 0x1e8) != 0) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        func_021BE900(p);
    }
    return result;
}


int func_021BEC60(char *p, int ret)
{
    if (*(int *)(p + 0x1e0) > 0) {
        *(int *)(p + 0x1e0) -= 1;
        return ret;
    }
    if (*(void **)(p + 0x1344)) {
        POKE_REGULATION_DeleteText(*(void **)(p + 0x1344));
        *(void **)(p + 0x1344) = 0;
    }
    if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        func_021BE900(p);
    } else {
        if (GFL_NET_STATE_IsWifiLoginOrConnected()) {
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
            goto done;
        } else {
            if (GFL_NET_STATE_GetWifiState() < 4 && !GFL_NET_STATE_IsWifiDisconnectFinal() && GFL_NET_IsConnectMember(0xff)) goto done;
            GFL_NET_STATE_WifiDisconnect(1);
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
        }
        *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
    }
done:
    return ret;
}


/*
 * Extent ends with two-byte alignment padding at 0x021BED3A.
 */
int func_021BED08(char *p,int ret) {
 func_021BA8EC(p);
 if (func_0202EB0C()) func_021BAB04(p,44);
 else func_021BAB04(p,19);
 ((Ov099Work *)p)->f1CC=8;
 ((Ov099Work *)p)->f1E8=0;
 return ret;
}


int func_021BED3C(char *p, int ret)
{
    if (func_020362DC() & 3) {
        if (!func_02009A34(((Ov099Work *)p)->f4)) {
            func_021BAAB8(p, 0x1a, 1);
            ((Ov099Work *)p)->f1CC = 0x33;
            ((Ov099Work *)p)->f1E0 = 1;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            ((Ov099Work *)p)->f1CC = func_021BE4F0(p, 0);
            ((Ov099Work *)p)->f19C = (void *)func_021BA8BC(((Ov099Work *)p)->f19C);
        }
    }
    return ret;
}


void func_021BEDA0(char *p)
{
    if (((Ov099Work *)p)->f194) func_020452E8(((Ov099Work *)p)->f194);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x21);
    ((Ov099Work *)p)->f198 = (void *)func_021BA8BC(((Ov099Work *)p)->f198);
    ((Ov099Work *)p)->f194 = (void *)BMP_WIN_Create(3, 1, 1, 0x1c, 2, 0xf, 1);
    ((Ov099Work *)p)->f198 = (void *)BMP_WIN_Create(2, 1, 1, 0x1c, 2, 0xf, 1);
    BMP_Clear(func_02045770(((Ov099Work *)p)->f194), 0xff);
    BMP_WIN_TransferChars(((Ov099Work *)p)->f194);
    BMP_Clear(func_02045770(((Ov099Work *)p)->f198), 0xff);
    BMP_WIN_TransferChars(((Ov099Work *)p)->f198);
    func_0201F73C(((Ov099Work *)p)->f198, 1, (u16)((int)((Ov099Work *)p)->f1334), 0xe);
}



/*
 * True when the two objects - the one at +0x08 of b and the one func_021C23B8
 * returns - agree under func_021C27D8 after both have been released through
 * func_021C27D0.
 */
BOOL func_021BEE64(void *a, char *b)
{
    void *x = ((struct Obj18261 *)b)->f8;
    void *y = (void *)func_021C23B8((int)a);

    func_021C27D0(x);
    func_021C27D0(y);

    if (func_021C27D8(x) == func_021C27D8(y)) {
        return 1;
    }

    return 0;
}


int func_021BEE94(u32_021BEE94 p, int a) {
    if (!GFL_NET_STATE_IsFatalError() && !GFL_NET_STATE_IsWifiLoginOrConnected()) return a;
    *(u32_021BEE94 *)(p+460) = 10;
    return a;
}


/*
 * lever: a named enabled result before kind initialization preserves call/store scheduling.
 */
void func_021BEEBC(char *p)
{
    void *h;
    int kind, enabled;
    DWC_RAP_SetAcceptFriendCallback((void (*)(void))func_021BEE64);
    h=func_020490F4(33,33);
    func_021C19A8(p);
    func_021C0290(p);
    func_02082BCC(p+0x30,0,32);
    if(((Ov099Work *)p)->fB0){
        func_020452E8(((Ov099Work *)p)->f1A0);
        BMP_MENULIST_Delete(((Ov099Work *)p)->fB4,0,0);
        ((Ov099Work *)p)->fB4=0;
        BMP_MENUWORK_Delete(((Ov099Work *)p)->fB0);
        ((Ov099Work *)p)->fB0=0;
    }
    if(!func_021B96CC((int *)(p+0x274))){
        enabled=func_02008550((const struct Sub0200852CObj *)func_02012944(((Ov099Work *)p)->fC4));
        kind=16;
        if(enabled)kind=17;
        ((Ov099Work *)p)->f132A=func_02009A54(((Ov099Work *)p)->f4);
        func_021B95A0(p+0x274,33,(u32_021BEEBC)h,kind,((Ov099Work *)p)->f132A,33,(u32_021BEEBC)(((Ov099Work *)p)->f110),(u32_021BEEBC)(((Ov099Work *)p)->f114));
        func_021BE21C(p,func_021B9900((u8 *)(p+0x274),kind));
    }
    if(!func_021C1A44(p))func_021C1A58(p,(int)h,33);
    func_021C282C(((Ov099Work *)p)->f8);
    ((Ov099Work *)p)->f1351=0;
    func_021C205C((u8 *)p,33);
    func_021BA8EC(p);
    func_021BE788(p);
    func_021BEDA0(p);
    func_021BDD0C(p,0);
    ((Ov099Work *)p)->f1F0=-1;
    ARC_TOOL_DeleteHandle(h);
    WIPE_SYS_Start(0,1,1,0,6,1,33);
}


int func_021BF000(char *p,int ret) {
 func_021BEEBC(p);
 func_021C18C8(p,1,2);
 func_021BDE30(p,1,2);
 ((Ov099Work *)p)->f1CC=11;
 func_021C2408(p);
 GFL_NET_SetAutoExit(0);
 GFL_NET_SetLoginOption(0);
 return ret;
}
