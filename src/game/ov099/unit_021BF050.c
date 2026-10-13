/*
 * file:     unit_021BF050.c
 * unit:     yes
 * function: func_021BF050, func_021BF068, func_021BF084, func_021BF1CC, func_021BF24C, func_021BF280, func_021BF29C, func_021BF2C4, func_021BF6E0, func_021BF950, func_021BFA00, func_021BFA28, func_021BFAD0, func_021BFB04, func_021BFB90, func_021BFBBC, func_021BFC04, func_021BFC94, func_021BFCEC, func_021BFD68, func_021BFDA8, func_021BFDD0, func_021BFE54, func_021BFE9C, func_021BFED0, func_021BFF9C, func_021BFFE0, func_021C0078, func_021C0134, func_021C0138, func_021C013C, func_021C0140, func_021C017C, func_021C01A0, func_021C01CC, func_021C0254, func_021C0274, func_021C0290, func_021C02C8, func_021C047C, func_021C04A4, func_021C04D0, func_021C0528, func_021C0554, func_021C0618, func_021C0664, func_021C0698, func_021C0750, func_021C0858, func_021C08F8, func_021C09C0, func_021C0A94, func_021C0AEC, func_021C0C7C, func_021C0C88, func_021C0E60, func_021C0F70, func_021C105C, func_021C1060, func_021C1064, func_021C10A8, func_021C1154, func_021C11A0, func_021C1288, func_021C12D0, func_021C12EC, func_021C12FC, func_021C1334, func_021C1350, func_021C1374, func_021C13D0, func_021C143C, func_021C14A8, func_021C14EC, func_021C1510, func_021C158C, func_021C15C0, func_021C15FC, func_021C1614, func_021C1634, func_021C169C, func_021C16EC, func_021C1724, func_021C1768, func_021C17D4, func_021C17F4, func_021C18B4, func_021C18C8, func_021C1908, func_021C1968, func_021C19A8, func_021C19DC, func_021C1A14, func_021C1A30, func_021C1A44, func_021C1A58, func_021C1AC0, func_021C1B04, func_021C1BEC, func_021C1C10, func_021C1C64, func_021C1C70, func_021C1C9C, func_021C1CD4, func_021C1D1C, func_021C1F74, func_021C1FE8, func_021C2028, func_021C203C, func_021C2050, func_021C205C, func_021C207C, func_021C208C, func_021C2090, func_021C2224, func_021C2274, func_021C22E8, func_021C2370, func_021C23B8, func_021C23C0, func_021C23C8, func_021C23D8, func_021C2408, func_021C2438, func_021C24A4, func_021C24D4, func_021C24F0, func_021C2604, func_021C2724, func_021C27D0, func_021C27D4, func_021C27D8, func_021C27DC, func_021C27E0, func_021C27E8, func_021C27F8, func_021C2810, func_021C282C, func_021C2850, func_021C285C, func_021C2864
 * address:  0x021BF050
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
 *   DWC_RAP_GetNewClientAid  0x02156B8C  thumb  ov009
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B99F4 0x021B99F4 thumb ov099
 *   func_021BE244 0x021BE244 thumb ov099
 *   func_021B9968 0x021B9968 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_02082D44 0x02082D44 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE7EC  0x021BE7EC  thumb  ov099
 *   func_021BB2B0  0x021BB2B0  thumb  ov099
 *   func_021B98E4  0x021B98E4  thumb  ov099
 *   func_020221A4 0x020221A4 thumb
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_020362DC 0x020362DC arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_02005728 0x02005728 thumb
 *   func_0200616C 0x0200616C thumb
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021B9B54 0x021B9B54 thumb ov099
 *   func_021B98FC 0x021B98FC thumb ov099
 *   func_021B989C 0x021B989C thumb ov099
 *   func_021B98F0 0x021B98F0 thumb ov099
 *   func_021C2874 0x021C2874 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   func_021B96D0 0x021B96D0 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021B9B24 0x021B9B24 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_02006224 0x02006224 thumb
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009B80 0x02009B80 thumb
 *   DWC_RAP_GetVchatState 0x02156B68 thumb ov009
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_021BA828 0x021BA828 thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   DWC_RAP_IsVchatActive 0x021563EC thumb ov009
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_021BAD50  0x021BAD50  thumb  ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_021BB954 0x021BB954 thumb ov099
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021B9A60 0x021B9A60 thumb ov099
 *   func_021B9A70 0x021B9A70 thumb ov099
 *   func_021BDD60 0x021BDD60 thumb ov099
 *   d_021C3804 0x021C3804 data a4
 *   d_021C3818 0x021C3818 data a4
 *   func_021BAD74 0x021BAD74 thumb ov099
 *   func_021BDD98 0x021BDD98 thumb ov099
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   DWC_RAP_GetResult 0x02156D5C thumb ov009
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_020399B8 0x020399B8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_0200ED48 0x0200ED48 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_021BCC58  0x021BCC58  thumb  ov099
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_020414AC 0x020414AC arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   sub_0203CD98  0x0203CD98  arm
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB4EC  0x021BB4EC  thumb  ov099
 *   func_02043598 0x02043598 arm
 *   func_02051B84 0x02051B84 arm
 *   d_021C377C 0x021C377C data a4
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02051C6C 0x02051C6C arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021B9800 0x021B9800 thumb ov099
 *   func_021B984C 0x021B984C thumb ov099
 *   func_021BB2F0 0x021BB2F0 thumb ov099
 *   func_02051C88 0x02051C88 arm
 *   func_0203630C  0x0203630C  arm
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_021B6448  0x021B6448  thumb  ov067
 *   d_021C3720     0x021C3720  data   ov099
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02009864 0x02009864 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0  0x020410D0  arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_020099E4  0x020099E4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   DWC_RAP_GetFriendStatusData  0x02156860  thumb  ov009
 *   DWC_RAP_GetFriendStatus  0x02156874  thumb  ov009
 *   sub_0203C2B0  0x0203C2B0  arm
 *   func_021B98F8  0x021B98F8  thumb  ov099
 *   GFL_USE_SetBgmTrackVolume 0x02005F24 thumb
 *   GFL_USE_SetPlayerVolumes  0x02005CBC  thumb
 *   PM_VOICE_SetMasterVolume  0x02006734  thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   GFL_NET_SetUserArg 0x0203D668 arm
 *   func_021BCB8C 0x021BCB8C thumb ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200873C 0x0200873C thumb
 *   func_020434DC 0x020434DC arm
 *   func_021BB1A8 0x021BB1A8 thumb ov099
 *   func_021BDE94 0x021BDE94 thumb ov099
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_0203D34C 0x0203D34C arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_0202223C 0x0202223C thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_0204A600 0x0204A600 arm
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   d_021C3C0C 0x021C3C0C data a4
 *   func_021BA7F8 0x021BA7F8 thumb ov099
 *   func_0200AE08 0x0200AE08 thumb
 *   func_021BDF7C 0x021BDF7C thumb ov099
 *   func_021BCBB0 0x021BCBB0 thumb ov099
 *   func_021BB224 0x021BB224 thumb ov099
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02087C6C 0x02087C6C arm
 */
#include "work_types.h"
#include "../../matched/include/Obj22049.h"
#include "../../matched/include/Obj22050.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj22058.h"
#include "../../matched/include/Obj01386.h"
#include "../../matched/include/Obj02804.h"
#include "../../matched/include/Obj03736.h"
#include "../../matched/include/Obj06360.h"

struct Entry;
struct Sub020097BCObj;
struct Link;
struct Obj;
struct W;
struct Work;
struct Ent;
struct S;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct BigObj;
struct Sub020097BCFriend;
struct WordSet;
struct Ctx;
struct S_021C1A44;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj0203159C;
struct Sub02008700Obj;
struct PrintSys;
struct Tcbl;
struct Reg;
struct S020315D4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BF050;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BF050;

typedef int BOOL;

typedef signed int     s32_021BF084;

typedef unsigned int   u32_021BF084;

typedef unsigned int   u32_021BF1CC;

typedef unsigned long  u32_021BF24C;

typedef signed long    s32_021BF24C;

typedef unsigned long  u32_021BF280;

typedef signed long    s32_021BF280;

typedef unsigned long  u32_021BF29C;

typedef signed long    s32_021BF29C;

typedef unsigned int u32_021BF2C4;

typedef unsigned int u32_021BF6E0;

typedef unsigned int   u32_021BF950;

typedef unsigned int   u32_021BFB04;

typedef unsigned int   u32_021BFBBC;

typedef unsigned int u32;

typedef unsigned long  u32_021C017C;

typedef signed short   s16_021C0140;

typedef signed long    s32;

typedef unsigned long  u32_021C01A0;

typedef unsigned int   u32_021C01CC;

typedef unsigned long  u32_021C0254;

typedef unsigned long  u32_021C0274;

typedef unsigned int   u32_021C0290;

typedef unsigned int u32_021C02C8;

typedef unsigned long  u32_021C047C;

typedef unsigned long  u32_021C04A4;

typedef unsigned int   u32_021C04D0;

typedef enum { K274=0x274 } Off;

typedef unsigned long  u32_021C0528;

typedef unsigned int   u32_021C0554;

typedef signed int     s32_021C0698;

typedef struct { int v[5]; } Messages;

typedef enum { K242=0x242, K1e0=0x1e0 } Off_021C09C0;

typedef int s32_021C0A94;

typedef short s16_021C0698;

typedef unsigned int u32_021C0C7C;

typedef int s32_021C0C7C;

typedef unsigned long  u32_021C0C88;

struct P { char a[0x1cc]; u32_021C0C88 f1cc; char b[0x7c]; char f24c[4]; };

typedef signed int     s32_021C0C88;

typedef unsigned int   u32_021C1288;

typedef unsigned long  u32_021C12D0;

typedef unsigned int u32_021C12FC;

typedef unsigned long  u32_021C1334;

typedef unsigned long  u32_021C1350;

typedef struct {
    u16 f0;
    u16 f2;
    u32_021C1350 f4;
} H;

typedef unsigned int   u32_021C1374;

typedef struct { u16 a, b; unsigned c; } Request;

typedef unsigned int   u32_021C13D0;

typedef unsigned int   u32_021C143C;

typedef unsigned long  u32_021C14EC;

typedef unsigned int   u32_021C1510;

typedef unsigned int u32_021C158C;

typedef unsigned int u32_021C15C0;

typedef unsigned long  u32_021C15FC;

typedef unsigned long  u32_021C1614;

typedef unsigned int   u32_021C1634;

typedef unsigned int   u32_021C1768;

typedef unsigned long  u32_021C17D4;

typedef unsigned int   u32_021C17F4;

typedef unsigned long  u32_021C18B4;

typedef struct {
    char pad[0x46];
    u8 f46;                 /* 0x46 */
} Sub;

typedef struct {
    char pad[8];
    void *f8;               /* 0x008 */
    char pad0c[0x23c];
    Sub *f248;              /* 0x248 */
} Work;

typedef unsigned int u32_021C19A8;

typedef unsigned long  u32_021C19DC;

typedef unsigned long  u32_021C1A14;

typedef unsigned long  u32_021C1A30;

typedef unsigned long  u32_021C1A44;

typedef signed short   s16_021C1A44;

typedef signed long    s32_021C1A44;

typedef unsigned int   u32_021C1A58;

typedef unsigned int   u32_021C1AC0;

typedef unsigned int u32_021C1B04;

typedef signed int     s32_021C1B04;

typedef unsigned long  u32_021C1BEC;

typedef unsigned int u32_021C1C10;

typedef struct {
    char pad[0x8ef];
    u8 f8ef;                /* 0x8ef */
    char pad8f0[0xbc];
    void *f9ac;             /* 0x9ac */
} Work_021C1C10;

typedef unsigned long  u32_021C1C64;

typedef unsigned long  u32_021C1C70;

typedef unsigned int u32_021C1C9C;

typedef struct {
    char pad[0x8ed];
    u8 f8ed;                /* 0x8ed */
    u8 f8ee;                /* 0x8ee */
    u8 f8ef;                /* 0x8ef */
    u8 f8f0;                /* 0x8f0 */
    u8 f8f1;                /* 0x8f1 */
    u8 f8f2;                /* 0x8f2 */
} Work_021C1CD4;

typedef unsigned int u32_021C1D1C;

typedef unsigned int   u32_021C1F74;

typedef struct {
    char pad[0x8f8];
    void *windows[8];
    void *pairs[8][2];
} Work_021C1F74;

typedef unsigned long  u32_021C1FE8;

typedef unsigned long  u32_021C2028;

typedef unsigned long  u32_021C203C;

typedef unsigned long  u32_021C2050;

typedef unsigned long  u32_021C205C;

typedef unsigned long  u32_021C207C;

typedef unsigned int u32_021C2090;

typedef unsigned int u32_021C2224;

typedef short s16_021C2274;

typedef struct {
    int pad00;
    void *f4;               /* 0x04 */
    char pad08[0xd4];
    int fdc;                /* 0xdc */
    char pade0[0x10];
    int ff0;                /* 0xf0 */
    char padf4[0x8b0 - 0xf4];
    int f8b0;               /* 0x8b0 */
} Work_021C1A44;

typedef int s32_021C2370;

typedef unsigned long  u32_021C23C0;

typedef signed short   s16_021C23C0;

typedef unsigned long  u32_021C23C8;

typedef unsigned long  u32_021C23D8;

typedef unsigned long  u32_021C2408;

typedef unsigned int   u32_021C2438;

typedef struct {
    char pad[0x1340];
    u8 f1340;
    u8 f1341;
    u8 f1342;
    u8 f1343;
} Work_021C24A4;

typedef unsigned int   u32_021C24A4;

typedef unsigned long  u32_021C24D4;

typedef unsigned int u32_021C24F0;

typedef int (*Handler)(char *,int);

typedef unsigned int   u32_021C2604;

typedef unsigned int   u32_021C2724;

typedef unsigned long  u32_021C27D0;

typedef struct {
    char pad[0x18];
    u8 f18;
} S_021C27D0;

typedef unsigned long  u32_021C27D4;

typedef struct {
    char pad[0x18];
    u8 f18;
} S_021C27D4;

typedef unsigned long  u32_021C27D8;

typedef struct {
    char pad[0x17];
    u8 f17;
} S_021C27D8;

typedef unsigned long  u32_021C27DC;

typedef struct {
    char pad[0x17];
    u8 f17;
} S_021C27DC;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S_021C27E0;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S_021C27E8;

typedef struct {
    char pad[0x1C];
    u8 f1C;
} S_021C1A44;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S_021C2850;

extern int DWC_RAP_GetNewClientAid(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern int func_021BE788(char *);
extern s32_021BF084 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
extern void *func_021BE2A8(char *,int);
extern void func_021B99F4(char *,void *);
extern void func_021BE244(char *,void *);
extern void *func_021B9968(char *,int,int);
extern void func_021BE21C(char *,void *);
extern int func_02082D44(void *,void *,int);
extern void func_020061E4(u32_021BF084 a);
extern int func_021BE7EC(char *p);
extern void func_021BB2B0(char *p, int v);
extern void func_021B98E4(int a, u8 *b);
extern u32_021BF2C4 func_020221A4(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern void GFL_NET_STATE_SetError(int, u32_021BF2C4, u32_021BF2C4, u32_021BF2C4);
extern void GFL_NET_STATE_WifiDisconnect(u32_021BF2C4 a);
extern u32_021BF2C4 func_020362DC(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void func_0203D7BC(u8 a0);
extern u32_021BF2C4 func_02005728(u32_021BF2C4);
extern void func_0200616C(void *arg, int i);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern s16 DWC_RAP_GetVchatEnabled(void);
extern void func_021BE900(char *);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BAEDC(char *);
extern void func_021B9B54(char *);
extern u32_021BF2C4 func_021B98FC(char *);
extern void func_021B989C(void *, void *);
extern void func_021B98F0(void *p);
extern int func_021C2874(void *);
extern u32 func_021BDD48(char *, void *);
extern u32 func_021BDD54(char *, void *);
extern int func_021BDDA8(int x);
extern int func_021BF03C(char *);
extern u32_021BF2C4 func_021B96D0(char *);
extern void func_021B9B64(char *);
extern void func_021B9B24(char *);
extern u8 func_021B97F4(char *);
extern int func_021BA928();
extern int func_02006224(u32_021BF950 a0);
extern void func_021BDE30(void *p, int kind, int value);
extern void func_021BC090(char *);
extern void func_021BA8EC(char *);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int DWC_RAP_GetVchatState(char *);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BFBBC d, int e);
extern void func_021BA828(char *);
extern u32 func_021BA858(char *p);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern int DWC_RAP_IsVchatActive(void);
extern unsigned func_02039CB4(struct Link *,unsigned,unsigned);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void DWC_RAP_StopVchat(void);
extern void func_021BDD0C(void *p, int on);
extern int func_021B96CC(int *p);
extern void func_021B9AE0(void *w, u8 *s);
extern int func_021BE4F0(char *,int);
extern void func_021BAD50(int a);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *,u16 *,u16 *);
extern u32_021C0290 func_0201F868(void *p);
extern u32_021C02C8 POKEPARTY_GetAliveNonEggCount(void *);
extern int func_020200CC(struct Obj *);
extern void func_021BB954(char *, int);
extern int func_021BDDD0(char *);
extern int func_0202EB14(void);
extern u32_021C02C8 func_0202EB0C(void);
extern void func_0203D1E8(u32, void *);
extern unsigned char func_021B9A60(char *p);
extern void func_021B9A70(void *, struct Ent *, int);
extern int func_021BDD60(int);
extern void func_021BAD74(char *);
extern int func_021BDD98(int);
extern void func_021BCC4C(void *a);
extern int func_021BDDF4(char *p);
extern unsigned DWC_RAP_GetResult(void);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
extern void func_021BE6E4(char *);
extern void func_021BA7D8(void *p);
extern u32 func_020399B8(u8 *p);
extern void func_02082BCC(void *, int, int);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039ACC(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32_021C1288 i);
extern void func_02008494(void *, void *);
extern void *func_0200ED48(void *);
extern u32_021C1288 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32_021C1288 val);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_021BCC58(char *p, u32_021C1334 x);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern unsigned func_021BCBD8(char *, int);
extern u32_021C143C func_0203D378();
extern u32_021C1510 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern int func_0200F4E4(void *o);
extern void func_020414AC(int);
extern int func_0203CEAC(int a0);
extern int func_0203CD98(void);
extern void func_02009B3C(struct Sub020097BCObj *obj);
extern void func_0201DD68(void);
extern int sub_0203CD98(void);
extern void func_021BB42C();
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern void func_02043598(u32_021C1A58 mask, u32_021C1A58 enable);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern struct WordSet *func_0201EC64(u32_021C1A58 heap);
extern void func_02051C6C(void *);
extern u32_021C1AC0 func_0201ED04(struct WordSet *p);
extern u32_021C1B04 func_021B9800(void *);
extern u32_021C1B04 func_021B984C(void *);
extern void func_021BB2F0(char *, int);
extern s32_021C1B04 func_02051C88(struct Ctx *c);
extern void func_021B63D0(struct S_021C1A44 *p);
extern int func_021B6448(u8 *p);
extern unsigned int func_0203630C(void);
extern void func_02049B68(void *a, u32_021C1D1C b, u32_021C1D1C c, u32_021C1D1C d, u32_021C1D1C e, u16 f);
extern u32_021C1D1C func_02049740(void *a0, u32_021C1D1C a1, u32_021C1D1C a2, u32_021C1D1C a3, u32_021C1D1C a4, u16 flags);
extern u32_021C1D1C func_02049658(void *a, u32_021C1D1C b, u32_021C1D1C c, u32_021C1D1C d, u32_021C1D1C e, u32_021C1D1C f, u16 g);
extern u32_021C1D1C func_02049990(void *a0, u32_021C1D1C a1, u32_021C1D1C a2, u32_021C1D1C a3, u32_021C1D1C a4, u32_021C1D1C a5, u32_021C1D1C a6, u16 a7);
extern void *func_02049EF4(void *h, u32_021C1D1C a1, u32_021C1D1C a2, void **out, u16 heap);
extern void func_02049B40(u32_021C1D1C h, u32_021C1D1C a, u32_021C1D1C c, u32_021C1D1C d, u32_021C1D1C e, u16 heap);
extern void *func_020450F0(int, u8, u8, int, u8, u8, u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32_021C1D1C index);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32_021C1F74 func_020307B0(void *p);
extern u32_021C2090 func_02009864(const struct Sub020097BCObj *obj, u32_021C2090 i, u32_021C2090 field);
extern void func_02041B6C(u32_021C2090 bit);
extern void func_020410D0(u32_021C2224 index, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 a3, u8 a4, u32_021C2224 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_0201DD78(u32_021C1A44 r, u32_021C1A44 g, u32_021C1A44 b);
extern void func_02045CAC(struct MsgBank *bank, u32_021C1A44 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *, s16_021C2274, s16_021C2274, void *, void *);
extern void func_021BE4BC(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_0201EE0C(struct WordSet *p, u32_021C1A44 i, const void *src, u32_021C1A44 n, u32_021C1A44 f, u32_021C1A44 c);
extern int DWC_RAP_GetFriendStatusData(int i);
extern unsigned char DWC_RAP_GetFriendStatus(int i);
extern int sub_0203C2B0(int a);
extern void func_021B98F8(char *p, int b);
extern void GFL_USE_SetBgmTrackVolume(u32_021C2438 a0, u32_021C2438 a1);
extern void GFL_USE_SetPlayerVolumes(u32_021C24A4 value, u32_021C24A4 mask);
extern void PM_VOICE_SetMasterVolume(int v);
extern void func_0203064C(u32_021C24F0, u32_021C24F0, u32_021C24F0);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021C24F0 size, u32_021C24F0 heap);
extern void GFL_NET_SetUserArg(u32_021C24F0);
extern int func_021BCB8C(void *);
extern void *func_02012934(const struct BigObj *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_020434DC(u32_021C24F0, u32_021C24F0);
extern void func_021BB1A8(char *);
extern void func_021BDE94(char *);
extern void func_021BE6F0(char *, int, int);
extern void func_0203D34C(u32_021C24F0, u32_021C24F0);
extern int DWC_RAPCOMMON_HandleNetError(int,int);
extern unsigned int func_0200FB24(void);
extern void func_021BC0C4(char *);
extern void func_021BB0B4(char *);
extern void func_0202223C(unsigned int,unsigned int);
extern void func_0202208C(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void func_0204A600(void *);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);
extern void func_020310C4(struct Tcbl *p);
extern u32_021C2604 func_0201C4E4(struct PrintSys *ps);
extern void func_021BA7F8(char *);
extern void func_0200AE08(const struct Reg *src, struct Reg *dest);
extern void func_021BDF7C(char *);
extern void func_021BCBB0(void *);
extern void func_021BB224(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32_021C2724 heap);
extern void func_02087C6C(void *);
BOOL func_021BF050(char *p);
BOOL func_021BF068(char *a0);
int func_021BF084(char *p);
void func_021BF1CC(char *p);
void func_021BF24C(u8 *p, int v);
void func_021BF280(void *a, void *b);
void func_021BF29C(char *p);
int func_021BF2C4(char *p, int ret);
int func_021BF6E0(char *p,int ret);
int func_021BF950(char *p, int ret);
int func_021BFA00(char *p, int ret);
int func_021BFA28(char *p, int ret);
int func_021BFAD0(char *p,int ret);
int func_021BFB04(char *p, int ret);
int func_021BFB90(char *p, int ret);
void func_021BFBBC(char *p);
int func_021BFC04(char *p, int ret);
int func_021BFC94(char *p, int ret);
int func_021BFCEC(char *p, int ret);
int func_021BFD68(char *p, int ret);
int func_021BFDA8(char *p, int ret);
int func_021BFDD0(char *p,int ret);
int func_021BFE54(char *p, int ret);
int func_021BFE9C(char *p,int ret);
int func_021BFED0(char *p,int ret);
int func_021BFF9C(char *p, int ret);
int func_021BFFE0(char *p,int ret);
int func_021C0078(char *p,int ret);
int func_021C0134(int a, int b);
int func_021C0138(int a, int b);
int func_021C013C(int a, int b);
int func_021C0140(char *p,int ret);
int func_021C017C(char *p, int v);
int func_021C01A0(char *p, int v);
int func_021C01CC(char *p,int ret);
int func_021C0254(char *p, int v);
int func_021C0274(char *p, int v);
void func_021C0290(char *p);
int func_021C02C8(char *p, int ret);
int func_021C047C(char *p, int v);
int func_021C04A4(char *p, int v);
int func_021C04D0(char *p,int ret);
int func_021C0528(char *p, int v);
int func_021C0554(char *p,int ret);
int func_021C0618(char *p,int ret);
int func_021C0664(char *p,int ret);
int func_021C0698(char *p,int ret);
int func_021C0750(char *p, int ret);
int func_021C0858(char *p,int ret);
int func_021C08F8(char *p);
int func_021C09C0(char *p, int ret);
int func_021C0A94(char *p,int ret);
int func_021C0AEC(char *p, int ret);
void func_021C0C7C(void);
int func_021C0C88(char *p, int v);
int func_021C0E60(char *p, int ret);
int func_021C0F70(char *p, int ret);
int func_021C105C(int a, int b);
int func_021C1060(int a, int b);
int func_021C1064(char *p,int ret);
int func_021C10A0(char *p,int ret);
int func_021C10A4(char *p,int ret);
int func_021C10A8(char *p, int ret);
int func_021C1154(char *p);
int func_021C11A0(char *p, int ret);
void func_021C1288(int index, int unused, void *src, char *p, int handle);
void func_021C12CC(void);
void func_021C12D0(int a, int b, int c, u8 *d, int e);
u32 func_021C12EC(int i, u8 *p);
void func_021C12FC(int a,int b,u8 *data,char *p,int handle);
void func_021C1334(int a, int b, int *p, void *q, int e);
void func_021C1350(int a, int b, H *h, char *d);
int func_021C1374(char *p, int ret);
int func_021C13D0(char *p, int ret);
int func_021C143C(char *p, int ret);
int func_021C14A8(char *p, int ret);
BOOL func_021C14EC(char *p);
int func_021C1510(char *p, int ret);
int func_021C158C(char *p,int ret);
int func_021C15B4(char *p,int ret);
int func_021C15C0(char *p,int ret);
int func_021C15FC(char *p, int v);
int func_021C1614(char *p, int v);
int func_021C1634(char *p, int ret);
int func_021C169C(char *p, int ret);
int func_021C16EC(char *p,int ret);
int func_021C1724(char *p, int ret);
int func_021C1768(char *p, int ret);
int func_021C17D4(char *p, int v);
int func_021C17F4(char *p, int state);
int func_021C18B4(int a, int b);
void func_021C18C8(char *p, int kind, int value);
void func_021C1908(char *p, int kind, int value);
u8 func_021C1968(Work *w);
void func_021C19A8(char *p);
void func_021C19DC(char *p, int v);
void func_021C1A14(char *p, int b, void *c);
void func_021C1A30(u8 *p, int v);
BOOL func_021C1A44(char *p);
void func_021C1A58(char *p, int a, int heap);
void func_021C1AC0(char *p);
u8 func_021C1B04(char *p, int heap);
void func_021C1BEC(u8 *p);
int func_021C1C10(Work_021C1C10 *w);
u8 func_021C1C64(char *p);
void func_021C1C70(char *p);
void func_021C1C9C(u32_021C1C9C a,int b,u32_021C1C9C p);
void func_021C1CD4(Work_021C1CD4 *w);
void func_021C1D1C(u8 *p, void *a, int heap);
void func_021C1F74(char *p);
void func_021C1FE8(u16 *p, u16 d);
void func_021C2028(char *p, int i, u8 v);
void func_021C203C(char *p, int i);
u8 func_021C2050(char *p, int i);
void func_021C205C(u8 *p, int v);
void func_021C207C(char *p);
void func_021C208C(char *a0);
void func_021C2090(char *p);
void func_021C2224(char *p, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 mode, u8 slot);
void func_021C2274(char *p, void *window, int id, int slot, int i);
void func_021C22E8(char *p, void *unused, int id, int flag, int x, int y);
void func_021C2370(Work_021C1A44 *w, int id);
int func_021C23B8(int i);
unsigned char func_021C23C0(void *a);
int func_021C23C8(void *a, void *b);
void func_021C23D8(char *p, int v);
void func_021C2408(char *p);
int func_021C2438(char *p);
void func_021C24A4(Work_021C24A4 *w, int v);
void func_021C24D4(u8 *p, int v);
int func_021C24F0(void *obj, int unused, char *args);
int func_021C2604(int task,int *state,int unused,char *p);
int func_021C2724(void *task, int unused, char *output, char *p);
u8 func_021C27D0(S_021C27D0 *s);
void func_021C27D4(S_021C27D4 *s, u8 v);
u8 func_021C27D8(S_021C27D8 *s);
void func_021C27DC(S_021C27DC *s, u8 v);
u8 func_021C27E0(S_021C27E0 *s);
void func_021C27E8(S_021C27E8 *s, u8 v);
BOOL func_021C27F8(char *p, char *q);
void func_021C2810(S_021C1A44 *s, char *q);
int func_021C282C(u8 *p);
void func_021C2850(char *p);
int func_021C285C(S_021C2850 *s);
void func_021C2864(S_021C2850 *s, u8 v);
extern Messages d_021C3804, d_021C3818;
extern const int d_021C377C[];
extern const u8 d_021C3720[];
extern const Handler d_021C3C0C[];











/*
 * True unless the arm9 predicate answers -1.
 *
 * Unblocked by matching DWC_RAP_GetNewClientAid (ov009, EXACT): the +0002 call site now
 * attests as `matched`.  The old `ov172` hint was simply wrong -- 0x02156B8C
 * is not inside ov172's window; the address is coherent Thumb code in ov009
 * (ov010 holds the tail of another function there).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BF050.c --func func_021BF050 --addr 0x021BF050 \n    --region ov099 --thumb --cc dsi/1.1p1
 */
BOOL func_021BF050(char *p)
{
    if (DWC_RAP_GetNewClientAid() != -1) {
        return 1;
    }

    return 0;
}











/*
 * Channel-id predicate: true when GFL_NET_STATE_GetWifiState() answers 3, 4 or 5.
 * `push {r3, lr}; blx; cmp r0, #3; beq; cmp r0, #4; beq; cmp r0, #5; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * Now EXACT*.  The old blocker (0x0203C3EC had no witness) is gone: it was
 * matched in arm9 (src/matched/GFL_NET_STATE_GetWifiState.c, shard pkt_0203C3EC), so
 * `attest_matched` resolves the BLX field.  The remaining residue was codegen:
 * the old `v == 3 || v == 4 || v == 5` source folded to a range test, and a
 * chain of separate `if`s oriented the true arm last.  A bare `switch (v)`
 * with fallthrough case labels 3/4/5 lays the true arm out first, exactly as
 * the original does; the 26 bytes all agree.  The inferred extent ran to 28
 * because the next function (0x021BF082) has no func_ label.
 */
BOOL func_021BF068(char *a0)
{
    int v = GFL_NET_STATE_GetWifiState();

    switch (v) {
    case 3:
    case 4:
    case 5:
        return 1;
    }
    return 0;
}










/*
 * lever: duplicated calls in the final if/else-if preserve the branch-to-branch tail.
 */
int func_021BF084(char *p)
{
    int ret=func_021BE788(p);
    int removed=0;
    int added=0;
    int i,j,found;
    void *v;
    char *s;
    if(func_0203EFC8((const u8 *)(p+0x10),(const u8 *)(p+0x30),32)){
        for(i=0;i<32;i++){
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+j+0x10)==*(u8 *)(p+i+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x30)){
                v=func_021BE2A8(p,*(u8 *)(p+i+0x30));
                if(v){
                    func_021B99F4(p+0x274,v);
                    func_021BE244(p,v);
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                    func_021C1A14(p,*(u8 *)(p+i+0x30),(void *)33);
                    added=1;
                }else{
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                }
            }
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+i+0x10)==*(u8 *)(p+j+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x10)){
                s=(char *)func_021C23B8(*(u8 *)(p+i+0x10)-1);
                v=func_021B9968(p+0x274,((struct Obj22049 *)s)->f14,*(u8 *)(p+i+0x10));
                if(v){
                    func_021C2028(p,*(u8 *)(p+i+0x10),2);
                    func_021BE21C(p,v);
                    removed=1;
                }else{
                    func_021C2028(p,*(u8 *)(p+i+0x10),1);
                }
            }
        }
        func_02082D44(p+0x10,p+0x30,32);
        if(removed || added)func_021C207C(p);
        if(removed==1){func_020061E4(0x676);}
        else if(added==1){func_020061E4(0x676);}
    }
    return ret;
}










void func_021BF1CC(char *p)
{
    int changed = 0;
    int i;
    void *v;
    char *s;
    for (i = 0; i < 32; i++) {
        if (*(u8 *)(p + i + 0x10) && !func_021BE2A8(p, *(u8 *)(p + i + 0x10))) {
            s = (char *)func_021C23B8(*(u8 *)(p + i + 0x10) - 1);
            v = func_021B9968(p + 0x274, ((struct Obj22050 *)s)->f14, *(u8 *)(p + i + 0x10));
            if (v) {
                func_021C2028(p, *(u8 *)(p + i + 0x10), 2);
                func_021BE21C(p, v);
                *(u8 *)(p + i + 0x50) = 0;
                *(u8 *)(p + i + 0x70) = 0;
                *(u8 *)(p + i + 0x90) = 0;
                changed = 1;
            }
        }
    }
    if (changed == 1) func_020061E4(0x676);
}











/*
 * Under a positive answer from func_021BE7EC, routes on the flag at +0x8EF:
 * hands the selector to func_021BB2B0 when set, otherwise raises the word at
 * +0x8F4 and calls func_021C2090.
 */
void func_021BF24C(u8 *p, int v)
{
    if (func_021BE7EC((char *)p) <= 0) {
        return;
    }

    if (p[0x8EF] != 0) {
        func_021BB2B0((char *)p, v);
        return;
    }

    ((Ov099Work *)p)->f8F4 = 1;
    func_021C2090((char *)p);
}











void func_021BF280(void *a, void *b)
{
    func_021BF084(a);
    func_021BF24C(a, (int)b);
    func_021BF1CC(a);
}











/*
 * Releases the block 0x274 bytes in once for every occupied slot of the
 * 0x21-entry pointer table at +0x814.  The slot value is the SECOND argument of
 * func_021B98E4, which is why the image loads it into r1 and keeps it live into
 * the call; that liveness, not an allocator quirk, is the byte the lane before
 * this one measured as a residue.
 */
void func_021BF29C(char *p)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        void *v = *(void **)(p + i * 4 + 0x814);

        if (v != 0) {
            func_021B98E4((int)(p + 0x274), v);
        }
    }
}










/*
 *   ov099_func_021BFB04.c, itself copied from ov099_func_021BEB68.c
 *   (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 * shape: the nested record test preserves its branch-to-branch;
 *   the named call-result value fixes cmp r0,r1 at +0176.
 * prototype: 021C1968 tail forwards the result read by this caller;
 *   0203D7B0/0203D7BC keep the visible r0 argument; 021C2864's
 *   r1 stays full-width because neither call site truncates it.
 */
int func_021BF2C4(char *p, int ret)
{
    u32_021BF2C4 action = 0, kind;
    int index, i, key, value;
    void *record;
    *(u8 *)(p + 0x1356) = 0;
    if (func_020221A4() == 0) return ret;
    if (GFL_NET_STATE_IsFatalError()) { func_021BE900(p); return ret; }
    if (*(int *)(p + 0x1f0) != -1) {
        if (++*(int *)(p + 0x1c8) > 0xe10) { GFL_NET_STATE_SetError(0, 0, 0, 0x3f1); return ret; }
    }
    if (GFL_NET_STATE_GetWifiState() == 4) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 21;
        func_021C18C8(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        return ret;
    }
    func_021BF280(p, (void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p + 0x274);
    if (func_021B98FC(p + 0x274) == 0) {
        if (DWC_RAP_GetNewClientAid() == -1 && (func_020362DC() & 0x400)) {
            if (func_021C1968((Work *)p)) func_021BAADC(p, 57, 0);
            else func_021BAADC(p, 58, 0);
            func_020061E4(0x54c);
            func_021BAEDC(p);
            *(int *)(p + 0x1cc) = 12;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        key = func_021C1B04(p, 33);
        record = func_021BE2A8(p, key);
        if (key != 0) {
            if (record != 0) func_021B989C(p + 0x274, record);
            else { func_021BF29C(p); func_021B98F0(p + 0x274); }
        } else { func_021BF29C(p); func_021B98F0(p + 0x274); }
    }
    for (i = 0; i < 32; i++) {
        index = func_02005728(32);
        if (func_021C27F8(*(void **)(p + 8), (char *)func_021C23B8(index)) != 0) {
            value = func_021C2874((void *)func_021C23B8(index));
            if (value != *(*(u8 **)(p + 0x248) + index + 0x24)) {
            func_021BDD48(p, (void *)func_021C23B8(index));
            func_021BDD54(p, (void *)func_021C23B8(index));
            *(u16 *)(p + 0x242) = index + 1;
            func_0200616C((void *)0x806, 0);
            *(int *)(p + 0x1cc) = 63;
            return ret;
            }
        }
    }
    if (func_021BF03C(p) && *(int *)(p + 0x1f0) != -1) {
        func_0200616C((void *)0x806, 0);
        GFL_NET_SetAutoExit(1);
        func_0203D7BC(1);
        *(int *)(p + 0x1cc) = 40;
        return ret;
    }
    if (*(int *)(p + 0x1f0) == -1 && DWC_RAP_GetNewClientAid() != -1) {
        index = DWC_RAP_GetNewClientAid();
        *(int *)(p + 0x1f0) = index;
        func_021BA874(p, index);
        if (!*(u8 *)(p + 0x1351)) func_021BAAB8(p, 46, 0);
        *(int *)(p + 0x1c8) = 0;
    } else if (*(int *)(p + 0x1f0) != -1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0((S_021C27E0 *)(*(void **)(p + 8))));
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        GFL_NET_STATE_WifiDisconnect(1);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (func_021BF068(p) && *(int *)(p + 0x1f0) != -1) {
        func_021BA874(p, DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (DWC_RAP_GetVchatEnabled() == 1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0((S_021C27E0 *)(*(void **)(p + 8))));
    }
    kind = func_021BDD48(p, *(void **)(p + 8));
    if (*(int *)(p + 0x1f0) == -1) {
        if ((func_020362DC() & 2) && func_021BDDA8(kind)) {
            func_020061E4(0x54c);
            *(int *)(p + 0x1cc) = 31;
            func_021C19DC(p, 33);
            return ret;
        }
        action = func_021B96D0(p + 0x274);
        func_021B9B64(p + 0x274);
    }
    switch (action) {
    case 0: return ret;
    case 1:
        func_020061E4(0x54c);
        if (func_021BDDA8(kind)) *(int *)(p + 0x1cc) = 31;
        else {
            *(int *)(p + 0x1d0) = 0;
            *(int *)(p + 0x1cc) = 49;
            func_021BAAB8(p, 25, 1);
        }
        func_021C1A30((u8 *)p, 33);
        return ret;
    case 3:
        if (kind == 1) {
            *(int *)(p + 0x135c) = 1;
            func_020061E4(0x54c);
            func_021B9B24(p + 0x274);
            *(int *)(p + 0x1cc) = 28;
            func_021C1A30((u8 *)p, 33);
            *(u8 *)(p + 0x1351) = 0;
            return ret;
        }
        break;
    case 2:
        if (kind == 1) {
            index = func_021B97F4(p + 0x274);
            func_020061E4(0x54c);
            func_02082D44((void *)func_021C23B8(index - 1), p + 0x24c, 32);
            *(int *)(p + 0x1cc) = 34;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        break;
    }
    return ret;
}










int func_021BF6E0(char *p,int ret)
{
    unsigned action=0,kind;
    int index;
    if(((Ov099Work *)p)->f1F0!=-1){
        if(++((Ov099Work *)p)->f1C8>0xe10){GFL_NET_STATE_SetError(0,0,0,0x3f1);return ret;}
    }
    func_021BA928(p);
    ((Ov099Work *)p)->f1356=0;
    func_021BF280(p,(void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p+0x274);
    if(func_021BF03C(p) && ((Ov099Work *)p)->f1F0!=-1){
        func_0200616C((void *)0x806,0);
        GFL_NET_SetAutoExit(1);
        func_0203D7BC(1);
        ((Ov099Work *)p)->f1CC=40;
        return ret;
    }
    if(func_021BF068(p) && ((Ov099Work *)p)->f1F0!=-1){
        func_021BA874(p,DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p,15,0);
        ((Ov099Work *)p)->f1CC=19;
        return ret;
    }
    if(((Ov099Work *)p)->f1F0==-1 && DWC_RAP_GetNewClientAid()!=-1){
        index=DWC_RAP_GetNewClientAid();
        ((Ov099Work *)p)->f1F0=index;
        func_021BA874(p,index);
        if(!((Ov099Work *)p)->f1351)func_021BAAB8(p,46,0);
        ((Ov099Work *)p)->f1C8=0;
    }else if(DWC_RAP_GetCanceledPeerIndex()!=-1){
        func_021BA874(p,DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p,15,0);
        ((Ov099Work *)p)->f1CC=19;
        return ret;
    }
    kind=func_021BDD48(p,((Ov099Work *)p)->f8);
    if(((Ov099Work *)p)->f1F0==-1){
        if((func_020362DC()&2) && func_021BDDA8(kind)){
            func_020061E4(0x54c);
            ((Ov099Work *)p)->f1CC=31;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        action=func_021B96D0(p+0x274);
        func_021B9B64(p+0x274);
    }
    switch(action){
    case 0:return ret;
    case 1:
        func_020061E4(0x54c);
        if(func_021BDDA8(kind)){
            ((Ov099Work *)p)->f1CC=31;
        }else{
            ((Ov099Work *)p)->f1D0=0;
            ((Ov099Work *)p)->f1CC=49;
            func_021BAAB8(p,25,1);
        }
        func_021C1A30((u8 *)p,33);
        return ret;
    case 3:
        if(kind==1){
            ((Ov099Work *)p)->f135C=1;
            func_020061E4(0x54c);
            func_021B9B24(p+0x274);
            ((Ov099Work *)p)->f1CC=28;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    case 2:
        if(kind==1){
            index=func_021B97F4(p+0x274);
            func_020061E4(0x54c);
            func_02082D44((void *)func_021C23B8(index-1),p+0x24c,32);
            ((Ov099Work *)p)->f1CC=34;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    }
    return ret;
}










/*
 * lever: pointer addition spells base + index + 0x24, avoiding indexed strb.
 */
int func_021BF950(char *p, int ret)
{
    int i = ((Ov099Work *)p)->f242 - 1;
    if (func_02006224(0)) return ret;
    *((u8 *)((Ov099Work *)p)->f248 + i + 0x24) = func_021C2874((void *)func_021C23B8(i));
    if (i >= 0 && i < 32 && func_021C23C8(p, (void *)i)) {
        ((Ov099Work *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 4, 3);
        func_021C18C8(p, 4, 3);
        func_021C19DC(p, 0x21);
        func_021BA874(p, i);
        ((Ov099Work *)p)->f1C4 = 0xe10;
        func_021BAADC(p, 0x5e, 0);
        func_021BC090(p);
        ((Ov099Work *)p)->f1CC = 0x25;
        ((Ov099Work *)p)->f1350 = ((Ov099Work *)p)->f242;
        return ret;
    }
    ((Ov099Work *)p)->f1CC = 0xb;
    return ret;
}










int func_021BFA00(char *p, int ret) {
 if (func_020362DC()) { ((Ov099Work *)p)->f1CC=11; func_021C2408(p); func_021BA8EC(p); }
 return ret;
}










int func_021BFA28(char *p, int ret)
{
    void *s;
    unsigned v;
    s = (void *)func_021C23B8(((Ov099Work *)p)->f242 - 1);
    func_021C27E0((S_021C27E0 *)s);
    v = func_021BDD48(p, s);
    ((Ov099Work *)p)->f1C4 -= 1;
    if (((Ov099Work *)p)->f1C4 < 0) {
        ((Ov099Work *)p)->f1CC = 0x3d;
    } else if (v != 1 && v != 2) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 0xd, 0);
        ((Ov099Work *)p)->f1CC = 0x13;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        func_021BA8EC(p);
        func_021C282C(((Ov099Work *)p)->f8);
        ((Ov099Work *)p)->f1351 = 0;
        func_021C18C8(p, 4, 4);
        ((Ov099Work *)p)->f1355 = 0;
        ((Ov099Work *)p)->f1CC = 0x10;
        func_021C24A4((Work_021C24A4 *)p, 0);
        func_021BAADC(p, 0x7b, 0);
    }
    return ret;
}










/*
 * Extent ends with two-byte alignment padding at 0x021BFB02.
 */
int func_021BFAD0(char *p,int ret) {
 func_021BA874(p,DWC_RAP_GetTargetFriendIndex());
 func_021BAAB8(p,11,0);
 func_021C18C8(p,4,4);
 ((Ov099Work *)p)->f1CC=15;
 return ret;
}










int func_021BFB04(char *p, int ret)
{
    if (GFL_NET_STATE_IsFatalError()) {
        func_021BE900(p);
        return ret;
    }
    if (DWC_RAP_GetTargetFriendIndex() < 0) {
        func_021BAAB8(p, 0x10, 0);
        *(int *)(p + 0x1cc) = 0x13;
        return ret;
    }
    if (func_021BA928(p)) {
        if (func_020362DC() & 3) {
            func_021BA8EC(p);
            func_021BAADC(p, 0x7b, 0);
            func_021C18C8(p, 4, 4);
            func_021C24A4((Work_021C24A4 *)p, 0);
            *(u8 *)(p + 0x1355) = 0;
            *(int *)(p + 0x1cc) = 0x10;
        } else {
            func_021BFB90(p, ret);
        }
    }
    return ret;
}










int func_021BFB90(char *p, int ret) {
 func_02039C68((struct Link *)func_020399A8(),19,10);
 func_02009B80(((Ov099Work *)p)->f4,DWC_RAP_GetTargetFriendIndex());
 ((Ov099Work *)p)->f1CC=149;
 return ret;
}










void func_021BFBBC(char *p)
{
    if (DWC_RAP_GetVchatState(p)) {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x3c, 0);
    } else {
        func_021BE3CC(p + 0x898, 1, 2, 1, 0x33, 0);
    }
}










int func_021BFC04(char *p, int ret)
{
    void *s = (void *)func_021C23B8(DWC_RAP_GetTargetFriendIndex());
    func_021BDD48(p, s);
    func_021BDD54(p, s);
    func_021BF280(p, (void *)0x21);
    func_021C1BEC((u8 *)p);
    if (func_020362DC() & 2) {
        func_021BAAB8(p, 0x11, 0);
        ((Ov099Work *)p)->f1CC = 0x11;
    } else if (((Ov099Work *)p)->f1355) {
        func_021BA8EC(p);
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 0x10, 0);
        ((Ov099Work *)p)->f1E0 = 0x3c;
        ((Ov099Work *)p)->f1CC = 0x94;
    } else {
        func_021BFBBC(p);
    }
    return ret;
}










int func_021BFC94(char *p, int ret)
{
    func_021BFBBC(p);
    if (func_021BA928(p)) {
        if (((Ov099Work *)p)->f1355) {
            func_021BA8EC(p);
            func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
            func_021BAAB8(p, 0x10, 0);
            ((Ov099Work *)p)->f1E0 = 0x3c;
            ((Ov099Work *)p)->f1CC = 0x94;
        } else {
            func_021BA828(p);
            ((Ov099Work *)p)->f1CC = 0x12;
        }
    }
    return ret;
}









int func_021BFCEC(char *p, int ret)
{
    int v;
    func_021BFBBC(p);
    v = func_021BA858(p);
    if (v == -1) {
        if (((Ov099Work *)p)->f1355) {
            func_021BA8EC(p);
            BMP_MENU_DeleteYesNo(((Ov099Work *)p)->f108);
            ((Ov099Work *)p)->f108 = 0;
            func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
            func_021BAAB8(p, 0x10, 0);
            ((Ov099Work *)p)->f1E0 = 0x3c;
            ((Ov099Work *)p)->f1CC = 0x94;
        }
    } else if (v == 0) {
        ((Ov099Work *)p)->f1CC = 0x92;
    } else {
        func_021BAADC(p, 0x7b, 0);
        ((Ov099Work *)p)->f1CC = 0x10;
    }
    return ret;
}









int func_021BFD68(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_0203D3A8(func_020399A8(), 0xa08, 0, 0)) {
        func_02039C68((struct Link *)func_020399A8(), 0x12, 0xa);
        ((Ov099Work *)p)->f1CC = 0x93;
    }
    return ret;
}








/*
 * Extent ends with two-byte alignment padding at 0x021BFDCE.
 */
int func_021BFDA8(char *p, int ret) {
 if (!DWC_RAP_IsVchatActive()) { func_02039C68((struct Link *)func_020399A8(),24,10); ((Ov099Work *)p)->f1CC=172; }
 return ret;
}








int func_021BFDD0(char *p,int ret) {
    ((Ov099Work *)p)->f1355=0;
    if(func_02039CB4((struct Link *)func_020399A8(),18,10) || GFL_NET_HANDLE_GetNegotiationNum()!=2) {
        if((unsigned)(((Ov099Work *)p)->f135C-3)<=1){
            DWC_RAP_StopVchat();
            func_021C24A4((Work_021C24A4 *)p,127);
            func_021BA8EC(p);
            func_021C18C8(p,3,3);
            ((Ov099Work *)p)->f1CC=154;
        } else {
            func_021C18C8(p,1,2);
            GFL_NET_SetAutoExit(0); func_0203D7BC(0);
            func_02039C68((struct Link *)func_020399A8(),21,10);
            ((Ov099Work *)p)->f1CC=159;
        }
    }
    return ret;
}








int func_021BFE54(char *p, int ret) {
    if (func_02039CB4((struct Link *)func_020399A8(),21,10) || GFL_NET_HANDLE_GetNegotiationNum()!=2) {
        GFL_NET_STATE_WifiDisconnect(1);
        ((Ov099Work *)p)->f1F0=-1;
        ((Ov099Work *)p)->f1E0=20;
        func_021BA8EC(p);
        ((Ov099Work *)p)->f1CC=57;
    }
    return ret;
}








int func_021BFE9C(char *p,int ret) {
 if (!func_021BA928(p)) return ret;
 if (--((Ov099Work *)p)->f1E0<0) {
  func_02039C68((struct Link *)func_020399A8(),18,10);
  ((Ov099Work *)p)->f1CC=147;
 }
 return ret;
}






int func_021BFED0(char *p,int ret)
{
    if(GFL_NET_STATE_IsFatalError()){func_021BE900(p);return ret;}
    if(func_021BDD48(p,*(void **)(p+8))!=1)func_021C18C8(p,1,2);
    if(!func_021BA928(p)){*(int *)(p+0x1e0)=30;return ret;}
    --*(int *)(p+0x1e0);
    if((func_020362DC()&3)||!*(int *)(p+0x1e0)){
        func_021BA8EC(p);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021BDD0C(p,0);
        if(!func_021B96CC((int *)(p+0x274))){
            *(int *)(p+0x1e0)=20;
            *(int *)(p+0x1cc)=57;
        }else{
            func_021C19A8(p);
            func_021BAEDC(p);
            *(int *)(p+0x1f0)=-1;
            *(int *)(p+0x1cc)=11;
            func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
            func_021C2408(p);
        }
    }
    return ret;
}






int func_021BFF9C(char *p, int ret) {
    if (!func_021BA928(p, ret)) return ret;
    if (func_020362DC() & 3) {
        func_021BA8EC(p);
        func_021C18C8(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        ((Ov099Work *)p)->f1E0=20;
        ((Ov099Work *)p)->f1CC=57;
    }
    return ret;
}






int func_021BFFE0(char *p,int ret) {
    if(++((Ov099Work *)p)->f1E0<=240)return ret;
    func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
    func_021BA8EC(p);
    func_021C18C8(p,1,2);
    GFL_NET_STATE_WifiDisconnect(1);
    func_021BDD0C(p,0);
    if(!func_021B96CC((int *)(p+0x274))){
        ((Ov099Work *)p)->f1CC=func_021BE4F0(p,0);
    } else {
        func_021C19A8(p);
        func_021BAEDC(p);
        ((Ov099Work *)p)->f1F0=-1;
        ((Ov099Work *)p)->f1CC=11;
        func_021C2408(p);
    }
    return ret;
}




/*
 * extent: lead is 188 bytes; 021C0134, 021C0138, 021C013C are Thumb return-second-argument
 *   followers, each 08 1c 70 47 (adds r0,r1,#0; bx lr), not padding. ARM9 cap forbids filing them.
 *   _pNetState 0x021469DC data resolves, GFL_NET_STATE_FatalError 0x0203CADC arm remains unresolved.
 *   typedef struct { int pad[2]; void (*callback)(void); } Object;
 *   extern Object *_pNetState;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if(_pNetState && _pNetState->callback==GFL_NET_STATE_FatalError)return 1;
 *       return 0;
 *   }
 *   file_020A7BA8 0x020A7BA8 data; message_020A7C7C 0x020A7C7C data;
 *   func_02034714 0x02034714 arm.
 *   extern const char file_020A7BA8[];
 *   extern const char message_020A7C7C[];
 *   extern void func_02034714(const char *,unsigned,const char *);
 *   void GFL_NET_STATE_FatalError(void) {
 *       func_02034714(file_020A7BA8,0x8d8,message_020A7C7C);
 *   }
 * diagnosis: caller-only tu --suggest-split MATCH 188 bytes; no viable split.
 */
int func_021C0078(char *p,int ret)
{
    if(GFL_NET_STATE_IsFatalError()){func_021BE900(p);return ret;}
    if(!func_021BA928(p)){*(int *)(p+0x1e0)=30;return ret;}
    --*(int *)(p+0x1e0);
    if((func_020362DC()&3)||!*(int *)(p+0x1e0)){
        func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
        func_021BA8EC(p);
        func_021C18C8(p,1,2);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021BDD0C(p,0);
        if(!func_021B96CC((int *)(p+0x274))){
            *(int *)(p+0x1cc)=func_021BE4F0(p,0);
        }else{
            func_021C19A8(p);
            func_021BAEDC(p);
            *(int *)(p+0x1f0)=-1;
            *(int *)(p+0x1cc)=11;
            func_021C2408(p);
        }
    }
    return ret;
}





int func_021C0134(int a, int b) { return b; }





int func_021C0138(int a, int b) { return b; }





int func_021C013C(int a, int b) { return b; }








int func_021C0140(char *p,int ret) {
 if (((Ov099Work *)p)->f1E0>0) { --((Ov099Work *)p)->f1E0; return ret; }
 if (func_020362DC()&3) {
  func_021BAAB8(p,26,1);
  ((Ov099Work *)p)->f1CC=51;
  ((Ov099Work *)p)->f1E0=1;
 }
 return ret;
}









int func_021C017C(char *p, int v)
{
    func_021B9B64(p + 0x274);
    func_021BAAB8(p, 7, 0);
    ((Ov099Work *)p)->f1CC = 0x20;
    return v;
}









/*
 * Re-arms the block 0x274 bytes in, then runs the setup and stamps selector
 * 0x21 when the guard answers true; returns the selector.
 */
int func_021C01A0(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 0x21;
    }

    return v;
}








int func_021C01CC(char *p,int ret) {
    int r=func_021BA858(p);
    func_021B9B64(p+0x274);
    if(((Ov099Work *)p)->f1F0==-1 && DWC_RAP_GetNewClientAid()!=-1){
        if(r==-1){BMP_MENU_DeleteYesNo((u8 *)((int)((Ov099Work *)p)->f108)); ((Ov099Work *)p)->f108=0;}
        r=1;
    }
    if(r==-1)return ret;
    if(r==0){
        func_021C18C8(p,1,2);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021BDD0C(p,0);
        func_021C2408(p);
        ((Ov099Work *)p)->f1CC=11;
    }else {
        func_021BAADC(p,6,0);
        ((Ov099Work *)p)->f1CC=158;
    }
    return ret;
}









/*
 * Runs the setup, stamps selector 0x83 and re-arms the block 0x274 bytes in.
 */
int func_021C0254(char *p, int v)
{
    func_021BAD50((int)p);
    ((Ov099Work *)p)->f1CC = 0x83;
    func_021B9B64(p + 0x274);
    return v;
}









int func_021C0274(char *p, int v)
{
    func_021BAAB8(p, 5, 0);
    ((Ov099Work *)p)->f1CC = 0x1D;
    return v;
}








/*
 * Extent ends with two-byte alignment padding at 0x021C02C6.
 */
void func_021C0290(char *p) {
 if (((Ov099Work *)p)->f1A4) {
  ((Ov099Work *)p)->f1A4=(void *)func_021BA8BC(((Ov099Work *)p)->f1A4);
  func_0202020C((struct Obj *)((Ov099Work *)p)->fBC,0,(u16 *)(p+0x23c));
  func_0201F868(((Ov099Work *)p)->fB8);
  func_021BA8EC(p);
 }
}








int func_021C02C8(char *p, int ret)
{
    u32_021C02C8 choice;
    u8 *q;
    POKEPARTY_GetAliveNonEggCount(((struct Obj00008 *)p)->fC8);
    func_021B9B64(p + 0x274);
    if (!func_021BA928((struct W *)p)) return ret;
    choice = func_020200CC(*(struct Obj * *)&((struct Obj00008 *)p)->fBC);
    switch (choice) {
    case (u32_021C02C8)-1:
        return ret;
    case (u32_021C02C8)-2:
        ((struct Obj00008 *)p)->f1CC = 11;
        func_021C0290(p);
        func_021C2408(p);
        return ret;
    case 7:
        func_021C0290(p);
        q = *(u8 * *)&((struct Obj00008 *)p)->f248;
        ((struct Obj00008 *)p)->f134C = q[0x21];
        ((struct Obj00008 *)p)->f134E = q[0x22];
        q[0x48] = q[0x20];
        func_021BB954(p, 1);
        ((struct Obj00008 *)p)->f1CC = 0x54;
        return ret;
    case 4:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        func_021C0290(p);
        func_021C23C8(p, (void *)-1);
        ((struct Obj00008 *)p)->f1CC = 0x9e;
        break;
    case 6:
        if (func_021BDDD0(p) == 0) {
            *(int *)&((struct Obj00008 *)p)->f1A4 = func_021BA8BC(((struct Obj00008 *)p)->f1A4);
            func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC, 0, (u16 *)(p + 0x23c));
            func_0201F868(((struct Obj00008 *)p)->fB8);
            func_021BA8EC(p);
            func_021BAAB8(p, 0x79, 0);
            ((struct Obj00008 *)p)->f1CC = 0x71;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 5:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        if (func_0202EB14() == 0 && func_0202EB0C() != 0) {
            func_021C0290(p);
            func_021BAAB8(p, 0x95, 0);
            ((struct Obj00008 *)p)->f1CC = 0xa0;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            ((struct Obj00008 *)p)->f1CC = 0x9e;
        }
        break;
    case 0: case 1: case 2: case 3: default:
        break;
    }
    func_021C23D8(p, 1);
    ((struct Obj00008 *)p)->f1E0 = 0;
    ((struct Obj00008 *)p)->f246 = choice;
    ((struct Obj00008 *)p)->f1CC = 0xad;
    return ret;
}









/*
 * Ages the counter at +0x1E0 and, when it underflows, hands the halfword at
 * +0x246 to func_021C18C8 with mode 2 and stamps selector 0x9E.  The image
 * branches on the subs flags themselves (bpl), so the condition is the
 * decremented value, written as a prefix -- on the dereference.
 */
int func_021C047C(char *p, int v)
{
    if (--((Ov099Work *)p)->f1E0 < 0) {
        func_021C18C8(p, 2, ((Ov099Work *)p)->f246);
        ((Ov099Work *)p)->f1CC = 0x9E;
    }

    return v;
}








/*
 * The same re-arm and stamp as func_021C01A0 with selector 0xA1.
 */
int func_021C04A4(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 0xA1;
    }

    return v;
}







int func_021C04D0(char *p,int ret) {
    int r;
    Off o;
    r=func_021BA858(p);
    o=K274;
    func_021B9B64(p+o);
    if(r==-1)return ret;
    if(r==0){
        func_021C23C8(p,(void *)(-1));
        func_021C18C8(p,2,5);
        func_021C23D8(p,1);
        *(int *)(p+(o-0xa8))=158;
    } else {
        func_021C2408(p);
        func_021BA8EC(p);
        *(int *)(p+(o-0xa8))=11;
    }
    return ret;
}








/*
 * The same re-arm and stamp as func_021C01A0 with selector 0xA3.
 */
int func_021C0528(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 0xA3;
    }

    return v;
}







/*
 * note (2026-10-05, wD9r lane82): the enum-typed offset local and the enum inline helper (stand-ins)
 *   are removed. The real form is a pointer local `st = p + 0x24c;` set as the first statement and
 *   passed to the first func_021C27E0; the other uses are plain p + 0x274, p + 0x1cc and p + 0x1f0.
 *   mwcc keeps 0x24C in r6 and derives the other offsets from it, as in the image. EXACT in c99 and c.
 */
int func_021C0554(char *p,int ret) {
    int i;
    int r;
    void *q;
    char *st;
    st=p+0x24c;
    i=func_021B97F4(p+0x274);
    r=func_021BA858(p);
    q=func_021BE2A8(p,i);
    func_021B9B64(p+0x274);
    if(r==-1)return ret;
    if(r==0){
        ((Ov099Work *)p)->f135C=2;
        if(func_021C27E0((S_021C27E0 *)st)==func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8))){
            *(int *)(p+0x1cc)=118;
        }else{
            if(func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8)))func_021BAAB8(p,73,0);
            else func_021BAAB8(p,72,0);
            ((Ov099Work *)p)->f1CC=55;
        }
    } else {
        func_021BA8EC(p);
        func_021C18C8(p,1,2);
        *(int *)(p+0x1f0)=-1;
        func_021C2408(p);
        *(int *)(p+0x1cc)=11;
        if(q)func_021B9AE0(p+0x274,q);
    }
    return ret;
}






int func_021C0618(char *p,int ret) {
    if (!func_021BA928(p,ret)) return ret;
    if(func_020362DC()) {
        func_021BA8EC(p);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021C18C8(p,1,2);
        ((Ov099Work *)p)->f1F0=-1;
        func_021C2408(p);
        ((Ov099Work *)p)->f1CC=11;
    }
    return ret;
}






int func_021C0664(char *p,int ret){func_021BA8EC(p);GFL_NET_STATE_WifiDisconnect(1);func_021C18C8(p,1,2);((Ov099Work *)p)->f1F0=-1;func_021C2408(p);((Ov099Work *)p)->f1CC=11;return ret;}










int func_021C0698(char *p,int ret) {
    int r;
    Off o=K274;
    func_021B9B64(p+o);
    if(!func_021BA928(p))return ret;
    r=func_020200CC((struct Obj *)((int)((Ov099Work *)p)->fBC));
    switch(r) {
    case -1: return ret;
    case -2:
        func_020061E4(1356);
        *(int *)(p+(o-0xa8))=28;
        break;
    default:
        func_020061E4(1356);
        func_021C18C8(p,2,r);
        *(int *)(p+(o-0xa8))=11;
        func_021BA8EC(p);
        break;
    }
    if(((Ov099Work *)p)->f1CC==11){func_021C23C8(p,(void *)(-1));func_021C23D8(p,1);}
    ((Ov099Work *)p)->f1A4=(void *)func_021BA8BC(((Ov099Work *)p)->f1A4);
    func_0202020C((struct Obj *)((int)((Ov099Work *)p)->fBC),0,(u16 *)(p+0x234+2* ((Ov099Work *)p)->f240));
    func_0201F868((void *)((int)((Ov099Work *)p)->fB8));
    return ret;
}










/*
 * lever: evaluating the third input before the call keeps 274 out of a callee-saved register.
 * note (2026-10-05, wD9r lane82): the enum-typed inline address helpers (stand-ins) are removed.
 *   The real form is a pointer local `st = p + 0x24c;` set as the first statement (before
 *   selector = 0) and passed to func_021BDD48/func_021BDD54; the two 0x274 uses are plain p + 0x274.
 *   Each use rebuilds `movs #0x93; lsls #2`, as in the image. EXACT in c99 and c. Writing the 0x274
 *   uses as st + 0x28 gives DIFF (252 of 264 bytes), with st first or second.
 * prototype-evidence: B9A60 tail-forwards to ov127 C4A8C, returning its byte
 *   consumed as B9A70's third argument. BDD48/54 return bytes through their
 *   full getter bodies; caller explicitly narrows to u16 before comparisons.
 * bounds: selector starts zero and is set only to 1,2,3,4; both tables have five words.
 */
int func_021C0750(char *p, int ret)
{
    Messages a, b;
    int selector, n, message, graphic;
    void *q;
    u16 kind, other;
    char *st;
    st = p + 0x24c;
    selector = 0;
    func_0203D1E8((u32)func_020399A8(), 0);
    n = func_021B97F4((char *)(p + 0x274));
    q = func_021BE2A8(p, n);
    graphic = func_021B9A60(func_021BE2A8(p, 0));
    func_021B9A70(p + 0x274, q, graphic);
    kind = (u16)func_021BDD48(p, (struct S *)st);
    other = (u16)func_021BDD54(p, (struct S *)st);
    func_021BA874(p, n - 1);
    if (other == 6) selector = 1;
    else if (other == 5) selector = 2;
    else if (other == 4) selector = 3;
    else if (func_021BDD60(other)) selector = 4;
    switch (kind) {
    case 0:
        message = 0x59;
        break;
    case 1:
        ((Ov099Work *)p)->f1CC = 11;
        func_021C08F8(p);
        return ret;
    case 2:
        a = d_021C3804;
        message = a.v[selector];
        break;
    case 4:
        b = d_021C3818;
        message = b.v[selector];
        break;
    case 5:
        message = 0x59;
        break;
    case 3:
    default:
        message = 0x59;
        break;
    }
    func_021BAAB8(p, message, 0);
    ((Ov099Work *)p)->f1CC = 0x23;
    return ret;
}









/*
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log); no retry of the integrator's blocker.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 * note (2026-10-04, lane17): lane17 wave D2: leaf func_021BDD98 (16 bytes, range test) filed EXACT as src/matched/ov/ov099_func_021BDD98.c. The 0x021BDD98 relocation still reports no witness because it has no shard yet; re-run after the integrator registers the leaf. Body and other 10 relocations are byte-correct.
 * note (2026-10-05, wD9r lane82): the enum-typed offset local (a stand-in) is removed. The real
 *   form is a pointer local `st = p + 0x24c;` set as the first statement and passed to
 *   func_021BDD48/func_021BDD54; the other uses are plain p + 0x274 and p + 0x1cc. mwcc keeps 0x24C
 *   in r5 and derives 0x274/0x1CC from it, as in the image. EXACT in c99 and c. Writing the other
 *   uses as st + 0x28 / st - 0x80 gives DIFF.
 */
int func_021C0858(char *p,int ret) {
    void *q; unsigned r; int v;
    char *st;
    st=p+0x24c;
    if(GFL_NET_STATE_IsFatalError()){func_021BE900(p);return ret;}
    q=func_021BE2A8(p,func_021B97F4((char *)(p+0x274)));
    if(!func_021BA928(p))return ret;
    r=func_021BDD48(p, (struct S *)st);
    v=func_021BDD54(p, (struct S *)st);
    switch(r) {
    case 1: func_021BAD74(p); *(int *)(p+0x1cc)=64;break;
    case 2: case 5:
        if(func_021BDD98(v)){func_021BAD74(p);*(int *)(p+0x1cc)=36;break;}
    case 0: case 3: case 4: default:
        func_021B9AE0(p+0x274,q);
        *(int *)(p+0x1cc)=113;
        break;
    }
    return ret;
}








/*
 * lever: enum offset K274 with p+(off-delta) preserves register-offset
 *   stores; unparenthesized p+off-delta gave DIFF20/200.
 * prototype-evidence: C23B8 forwards the index to ov009 56860 and returns
 *   its address in r0; C23C8's final 0203C2B0 body returns the consumed bool.
 *   BDD48 retains the visibly loaded unused first input.
 */
int func_021C08F8(char *p)
{
    int n;
    int index;
    struct S *state;
    u32 kind;
    Off off = K274;
    n = func_021B97F4((char *)(p + off));
    *(u16 *)(p + (off - 0x32)) = n;
    if (n != 0) {
        POKEPARTY_GetAliveNonEggCount(((Ov099Work *)p)->fC8);
        index = n - 1;
        state = (struct S *)func_021C23B8(index);
        kind = func_021BDD48(p, state);
        func_021C27E0((S_021C27E0 *)state);
        if (kind == 6) return 0;
        if (func_021C23C8(p, (void *)-1)) {
            func_021C2810((S_021C1A44 *)((struct S *)((Ov099Work *)p)->f8), (char *)func_021C23B8(index));
            *(int *)(p + (off - 0xb0)) = 0xe10;
            func_021BDE30(p, 3, 3);
            func_021C18C8(p, 3, 3);
            func_021BA874(p, n - 1);
            ((Ov099Work *)p)->f1351 = n;
            func_021BAADC(p, 14, 0);
            func_021BC090(p);
            *(int *)(p + (off - 0xa8)) = 0x88;
        } else {
            func_021BA874(p, n - 1);
            func_021BAAB8(p, 13, 0);
            *(int *)(p + (off - 0xa8)) = 0x15;
        }
    }
    return 1;
}







static inline int Step(int *dst, int old)
{
    int n;
    n = (int)((u32)old + 1);
    *dst = n;
    return n;
}







/*
 * lever: separate unsigned word increment and store use raw +0x1e0 addresses;
 *   casting the result to int preserves the original signed modulo.
 * retry: wave76 R24 fresh pass; EXACT in 1 scratch run. Earlier types300 consumed.
 * prototype-evidence: C23C0 forwards index to ov009 56874, whose full body
 *   returns the tested byte. C23B8 forwards index to ov009 56860 and returns
 *   its address. 362DC's own unit returns a pointer, compared by its u32 bits.
 * arithmetic-evidence: unsigned counter increment preserves original wrapping
 *   add; signed interpretation supplies original signed modulo and comparison.
 */
int func_021C09C0(char *p, int ret)
{
    Off_021C09C0 off;
    u32 counter;
    func_021BA928((char *)((struct W *)p));
    if (DWC_RAP_GetNewClientAid() != -1) ((Ov099Work *)p)->f1CC = 11;
    off = K242;
    if (func_021C23C0((void *)(*(u16 *)(p + off) - 1)) == 0) {
        func_021BA874(p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 15, 0);
        *(int *)(p + (off - 0x76)) = 0x13;
        return ret;
    }
    counter = (u32)((Ov099Work *)p)->f1E0 + 1u;
    ((Ov099Work *)p)->f1E0 = counter;
    if ((int)counter % 900 == 0) {
        func_021C2810((S_021C1A44 *)((struct S *)((Ov099Work *)p)->f8), (char *)func_021C23B8(*(u16 *)(p + off) - 1));
        func_021C18C8(p, 3, 3);
    }
    off = K1e0;
    if (*(int *)(p + off) > 3600) {
        func_021BA874(p, *(u16 *)(p + (off + 0x62)) - 1);
        func_021BAAB8(p, 15, 0);
        *(int *)(p + (off - 0x14)) = 0x13;
        return ret;
    }
    if ((u32)func_020362DC() == 2) {
        func_021BAAB8(p, 0x47, 0);
        func_021BA828(p);
        *(int *)(p + (off - 0x14)) = 0x89;
    }
    return ret;
}







int func_021C0A94(char *p,int ret) {
    int r;
    if(!func_021BA928(p,ret))return ret;
    r=func_021BA858(p);
    if(r==-1)return ret;
    if(r==0){
        func_021BAAB8(p,74,0);
        ((Ov099Work *)p)->f1CC=21;
    }else {
        func_021BA8EC(p);
        func_021BAAB8(p,14,0);
        func_021BC090(p);
        ((Ov099Work *)p)->f1CC=136;
    }
    return ret;
}







/*
 *   021C0B16 is the only open site, every other relocation resolves.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 * note: the earlier DIFF338 came from a guard-then-return spelling of the
 *   record compare; the image places the mismatch arm (021C0BDE) before the
 *   early return (021C0BFC), so the test is written as `!= || !=` with the
 *   return in the else.
 * volatile: none.
 */
int func_021C0AEC(char *p, int ret)
{
    int changed;
    s32_021C0A94 choice;
    int n;
    u8 *q;
    int state;
    int other;
    changed = 0;
    choice = func_020200CC(*(struct Obj **)(p + 0xbc));
    n = func_021B97F4((char *)(p + 0x274));
    q = func_021BE2A8(p, n);
    if (GFL_NET_STATE_IsFatalError()) {
        *(int *)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
        func_0202020C(*(struct Obj **)(p + 0xbc), 0, 0);
        func_0201F868(*(void **)(p + 0xb8));
        if (q)
            func_021B9AE0(p + 0x274, q);
        func_021BE900(p);
        return ret;
    }
    switch (choice) {
    case -1:
        if (q == 0) {
            func_0202020C(*(struct Obj **)(p + 0xbc), 0, 0);
            func_021BA874(p, n - 1);
            func_021BAAB8(p, 13, 0);
            *(int *)(p + 0x1cc) = 0x15;
            changed = 1;
        } else {
            state = func_021C23B8(n - 1);
            func_021BDD48(p, (struct S *)((void *)state));
            changed = func_021C27E0((S_021C27E0 *)((struct S *)((void *)state)));
            other = func_021BDD54(p, (struct S *)((void *)state));
            if (other != func_021BDD54(p, (struct S *)(p + 0x24c)) || changed != func_021C27E0((S_021C27E0 *)((struct S *)(p + 0x24c)))) {
                func_021BA874(p, n - 1);
                func_021BAAB8(p, 13, 0);
                *(int *)(p + 0x1cc) = 0x15;
                changed = 1;
            } else {
                return ret;
            }
        }
        break;
    case -2:
        func_020061E4(0x551);
        *(int *)(p + 0x1cc) = 11;
        break;
    default:
        func_020061E4(0x54c);
        if (choice == 1) {
            *(int *)(p + 0x1cc) = 11;
            func_021C08F8(p);
        } else if (choice == 2) {
            *(int *)(p + 0x1cc) = 0x2e;
        }
        break;
    }
    if (changed == 0)
        func_021BA8EC(p);
    *(int *)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
    func_0202020C(*(struct Obj **)(p + 0xbc), 0, 0);
    func_0201F868(*(void **)(p + 0xb8));
    if (q)
        func_021B9AE0(p + 0x274, q);
    return ret;
}






/*
 * Unblocked (was MATCH on one witness).
 * +0008 ABS32 DWC_RAP_SetVchatEnabled          -> resolved as `matched` by
 * src/matched/ov009_func_02156BC4.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 decodes to a pop with no push), declared
 * as `DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009` below.
 */
void func_021C0C7C(void) { DWC_RAP_SetVchatEnabled(0); }







/*
 * note: 2026-10-05 (wD9r lane72): EXACT 472/472, 31 of 31 relocations. The fix is a pointer local
 *   `st = p + 0x24c;` set at the top of the function (before the first call) and passed to
 *   func_021BDD54 and to the first func_021C27E0. With the field address written at each use, mwcc
 *   made 0x24C one constant temp in r6 and derived 0x1CC from it (`subs r6,#0x80`) in the r4 == 5 and
 *   0x76 paths. The early pointer local is propagated after that pass, so each use rebuilds
 *   `movs #0x93; lsls #2` and every 0x1CC store is fresh, as in the image. Same idiom as ov223
 *   021BB18C (docs/idioms/a-spilled-offset-derived-at-the-top-is-an-early-pointer-local.md). The
 *   pointer set just before the func_021BDD54 call instead gives 464 B DIFF. Earlier DIFF notes
 *   (wD4 to wD9r) tried struct fields, raw and integer offsets, inline helpers, switch and goto shapes;
 *   the enum-local form from lane61 is not used.
 */
int func_021C0C88(char *p, int v)
{
    int r6;
    int r4;
    int r7;
    char *st;
    u16 t;

    st = p + 0x24c;
    r6 = func_020200CC((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)));
    if (func_021BF050(p)) {
        r6 = -2;
    }
    t = func_021B97F4((char *)(p + 0x274));
    *(u16 *)(p + 0x242) = t;
    r7 = (int)func_021BE2A8(p, t);
    if (GFL_NET_STATE_IsFatalError()) {
        *(u32_021C0C88 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32_021C0C88 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32_021C0C88 *)(p + 0xb8)));
        if (r7) {
            func_021B9AE0(p + 0x274, (u8 *)r7);
        }
        func_021BE900(p);
        return v;
    }
    if (r6 != -1) {
        func_021BA8EC(p);
        *(u32_021C0C88 *)(p + 0x1a4) = func_021BA8BC((void *)(*(u32_021C0C88 *)(p + 0x1a4)));
        func_0202020C((struct Obj *)(*(u32_021C0C88 *)(p + 0xbc)), 0, 0);
        func_0201F868((void *)(*(u32_021C0C88 *)(p + 0xb8)));
    }
    switch (r6) {
    case -1:
        return v;
    case -2:
        func_020061E4(0x551);
        ((struct P *)p)->f1cc = 0xb;
        goto end;
    }
    func_020061E4(0x54c);
    r4 = func_021BDD54(p, (struct S *)st);
    if (r4 == 5 && !func_0202EB14() && func_0202EB0C()) {
        func_021BAAB8(p, 0x95, 0);
        ((struct P *)p)->f1cc = 0xa2;
        return v;
    }
    if (r4 == 6 && !func_021BDDD0(p)) {
        func_021BAAB8(p, 0x79, 0);
        ((struct P *)p)->f1cc = 0x71;
        goto end;
    }
    if (func_021BDD60(r4)) {
        *(u16 *)(p + 0x134c) = (r4 - 7) / 2;
        *(u16 *)(p + 0x134e) = (r4 - 7) % 2;
        func_021BCC4C(p);
        if (!func_021BDDF4(p)) {
            func_021BAAB8(p, 0x68, 0);
            ((struct P *)p)->f1cc = 0x71;
        }
    }
    *(u32_021C0C88 *)(p + 0x135c) = 2;
    r4 = func_021C27E0((S_021C27E0 *)((struct S *)st));
    if (r4 == func_021C27E0((S_021C27E0 *)((struct S *)(*(void **)(p + 8))))) {
        ((struct P *)p)->f1cc = 0x76;
    } else {
        if (func_021C27E0((S_021C27E0 *)((struct S *)(*(void **)(p + 8))))) {
            func_021BAAB8(p, 0x49, 0);
        } else {
            func_021BAAB8(p, 0x48, 0);
        }
        ((struct P *)p)->f1cc = 0x37;
    }
end:
    if (r7) {
        func_021B9AE0(p + 0x274, (u8 *)r7);
    }
    return v;
}






/*
 * lever: signed int locals with the witnessed byte return prevent index-minus-one hoisting.
 * prototype: C23B8 forwards the visible index to 56860 and returns its pointer.
 */
int func_021C0E60(char *p, int ret)
{
    int index;
    void *state;
    int kind, value, flag;
    index = ((Ov099Work *)p)->f242;
    POKEPARTY_GetAliveNonEggCount(((Ov099Work *)p)->fC8);
    if (((Ov099Work *)p)->f242 == 0) {
        func_021BAAB8(p, 0x4a, 0);
        ((Ov099Work *)p)->f1CC = 21;
    }
    state = (void *)func_021C23B8(index - 1);
    kind = func_021BDD48(p, (struct S *)state);
    value = func_021BDD54(p, (struct S *)state);
    flag = func_021C27E0((S_021C27E0 *)((struct S *)state));
    if (kind != func_021BDD48(p, (struct S *)(p + 0x24c)) ||
        value != func_021BDD54(p, (struct S *)(p + 0x24c)) ||
        flag != func_021C27E0((S_021C27E0 *)((struct S *)(p + 0x24c))) || kind == 6) {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((Ov099Work *)p)->f1CC = 21;
        return ret;
    }
    func_021C23C0((void *)(index - 1));
    if (func_021C23C8(p, (void *)(index - 1))) {
        ((Ov099Work *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 3, value);
        func_021C18C8(p, 3, value);
        func_021BA874(p, index - 1);
        func_021BAADC(p, 14, 0);
        func_021BC090(p);
        ((Ov099Work *)p)->f242 = index;
        ((Ov099Work *)p)->f1CC = 37;
    } else {
        func_021BA874(p, index - 1);
        func_021BAAB8(p, 13, 0);
        ((Ov099Work *)p)->f1CC = 21;
    }
    return ret;
}






/*
 *   extern char *d_021469DC;
 *   int GFL_NET_STATE_IsWifiDisconnectFinal(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   but its function: header lists only CF4; no duplicate leaf permitted.
 * extent-policy: no follower C filed while ARM9 also blocks this caller.
 * extent: 236-byte lead followed by two 4-byte return-r1 stubs at 105C/1060.
 * prototype: D7B0/D7BC preserve the caller's visible integer input through veneers.
 */
int func_021C0F70(char *p, int ret)
{
    void *selection;
    func_021BA928(p);
    if (--*(int *)(p + 0x1c4) < 0) {
        selection = func_021BE2A8(p, func_021B97F4((char *)(p + 0x274)));
        if (selection) func_021B9AE0(p + 0x274, selection);
        *(int *)(p + 0x1cc) = 61;
    } else if (GFL_NET_STATE_GetWifiState() == 5) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (DWC_RAP_GetResult() == 5) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 12, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (DWC_RAP_GetResult() == 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        func_021C282C(*(unsigned char **)(p + 8));
        func_021BE6E4(p);
        func_021BDD48(p, (struct S *)(*(void **)(p + 8)));
        *(int *)(p + 0x1cc) = 41;
        func_021BA8EC(p);
        func_021BA7D8(p);
        *(int *)(p + 0x1e0) = 30;
        GFL_NET_SetAutoExit(1);
        func_0203D7BC(1);
    }
    return ret;
}





int func_021C105C(int a, int b) { return b; }





int func_021C1060(int a, int b) { return b; }




int func_021C1064(char *p,int ret) {
    func_021C19A8(p);
    func_021C18C8(p,1,2);
    GFL_NET_STATE_WifiDisconnect(1);
    ((Ov099Work *)p)->f1F0=-1;
    ((Ov099Work *)p)->f1CC=11;
    func_021C2408(p);
    func_021BA8EC(p);
    return ret;
}




int func_021C10A0(char *p,int ret){return ret;}




int func_021C10A4(char *p,int ret){return ret;}




int func_021C10A8(char *p, int ret)
{
    int zero = 0;
    void *s;
    if (func_02006224(0) != 0) return ret;
    if (func_021C23C0((void *)DWC_RAP_GetTargetFriendIndex()) == 0) {
        func_021BA874(p, ((Ov099Work *)p)->f1F0);
        func_021BAAB8(p, 15, zero);
        ((Ov099Work *)p)->f1CC = 19;
        return ret;
    }
    s = (void *)func_021C23B8(DWC_RAP_GetTargetFriendIndex());
    func_021BDD48(p, ((Ov099Work *)p)->f8);
    func_021BDD48(p, s);
    func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8));
    ((Ov099Work *)p)->f242 = DWC_RAP_GetTargetFriendIndex() + 1;
    if (((Ov099Work *)p)->f1351 == 0) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 8, zero);
    }
    func_021BA7D8(p);
    ((Ov099Work *)p)->f1CC = 41;
    ((Ov099Work *)p)->f1E0 = 30;
    return ret;
}




int func_021C1154(char *p)
{
    if (GFL_NET_STATE_GetWifiState() >= 3) {
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else {
        if (GFL_NET_STATE_IsFatalError() != 0) func_021BE900(p);
        else return 0;
    }
    *(unsigned short *)(p + 0x244) = 0;
    return 1;
}




/*
 * extent: 021C1286..021C1288 is two zero alignment bytes.
 *   extern char *d_021469DC;
 *   int GFL_NET_STATE_IsWifiDisconnectFinal(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 * prototype: 399A8 leaves a live pointer consumed by 399B8, 39C68 and 3D1A4.
 */
int func_021C11A0(char *p, int ret)
{
    func_021BA928(p);
    if (GFL_NET_STATE_GetWifiState() >= 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        if (*(u16 *)(p + 0x244) != 0) {
            func_021BAAB8(p, 0x44, 0);
        } else {
            func_021BA874(p, *(int *)(p + 0x1f0));
            func_021BAAB8(p, 15, 0);
        }
        *(u16 *)(p + 0x244) = 0;
        *(int *)(p + 0x1cc) = 19;
    } else if (func_021C1154(p) == 0) {
        if (*(int *)(p + 0x1e0) > 1) --*(int *)(p + 0x1e0);
        if (*(int *)(p + 0x1e0) == 0) {
            if (func_020399B8((u8 *)func_020399A8()) != 0) {
                func_02082BCC(p + 0x1f4, 0, 0x40);
                func_02039C68((struct Link *)func_020399A8(), 14, 10);
                *(u16 *)(p + 0x244) = 0;
                func_021BAAB8(p, 0x45, 0);
                func_021BC090(p);
                *(int *)(p + 0x1cc) = 0x2a;
            }
        } else if (*(int *)(p + 0x1e0) == 1) {
            if (func_0203D1A4((struct Link *)func_020399A8()) != 0) {
                if (func_02039ACC() == 1) *(int *)(p + 0x1e0) = 0;
            } else if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && func_02039ACC() == 1) {
                *(int *)(p + 0x1e0) = 0;
            }
        }
    }
    return ret;
}




/*
 * size: 72
 * follower: empty return at 0x021C12CC.
 */
void func_021C1288(int index, int unused, void *src, char *p, int handle)
{
    void *q;
    void *list;
    if (handle == (int)func_020399A8()) {
        q = func_02012950(((Ov099Work *)p)->fC4, index);
        func_02008494(src, q);
        list = func_0200ED48(((Ov099Work *)p)->fC0);
        func_0200ED54(list, func_02008530(q));
    }
}




void func_021C12CC(void) {}





void func_021C12D0(int a, int b, int c, u8 *d, int e)
{
    if ((int)GFL_NET_HANDLE_GetCurrentHandle() == e) {
        d[0x1355] = 1;
    }
}




u32 func_021C12EC(int i, u8 *p) { u8 *q = *(u8 **)(p + 0x248); return *(u32 *)(q + i * 4 + 0x14); }








void func_021C12FC(int a,int b,u8 *data,char *p,int handle){if(handle==(int)func_020399A8()){if(((Ov099Work *)p)->f1CC==0x48){((Ov099Work *)p)->f1357=*data;func_02039C68((struct Link *)func_020399A8(),0x1a,10);}else ((Ov099Work *)p)->f1CC=21;}}









/*
 * When the fifth argument matches the arm9 predicate, applies the first word of the third to the fourth.
 */
void func_021C1334(int a, int b, int *p, void *q, int e)
{
    if (e == (int)func_020399A8()) {
        func_021BCC58(q, *p);
    }
}









/*
 * Stamps the record of slot a from the three lead fields of h.
 */
void func_021C1350(int a, int b, H *h, char *d)
{
    *(u16 *)(d + a * 2 + 0x1F4) = h->f0;
    *(u8 *)(*(char **)(d + 0x1F4 + 0x54) + a + 0x44) = h->f2;
    func_021BCC58(d, h->f4);
}








int func_021C1374(char *p, int ret)
{
    int h;
    unsigned count;
    void *q;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 14, 10) != 0) {
            h = (int)func_020399A8();
            count = func_02008468();
            q = func_02012944(((Ov099Work *)p)->fC4);
            if (func_0203D3A8((void *)h, (u16)0xa04, (u16)count, (u32_021C1374)q) != 0) {
                func_021BA8EC(p);
                ((Ov099Work *)p)->f1CC = 135;
            }
        }
    }
    return ret;
}








int func_021C13D0(char *p, int ret)
{
    Request request;
    func_021BDD48(p, ((Ov099Work *)p)->f8);
    request.a = func_021BDD54(p, ((Ov099Work *)p)->f8);
    if (((Ov099Work *)p)->f1356 != 0) {
        request.b = ((Ov099Work *)p)->f1356 - 1;
        ((Ov099Work *)p)->f1356 = 0;
    } else {
        request.b = *((u8 *)((Ov099Work *)p)->f248 + 0x46);
    }
    request.c = func_021BCBD8(p, 1);
    if (func_0203D3A8(func_020399A8(), 0xa03, 8, (u32_021C13D0)(&request)) != 0)
        ((Ov099Work *)p)->f1CC = 43;
    return ret;
}








/*
 * lever: bind the narrowed callee result before comparing the indexed field.
 */
int func_021C143C(char *p, int ret)
{
    int index = 0;
    u16 value;
    if (func_0203D378() != 0) index = 1;
    if (func_021C1154(p) == 0) {
        if (((u16 *)(p + 0x1f4))[index] != 0) {
            value = func_021BDD54(p, ((Ov099Work *)p)->f8);
            if (value == ((u16 *)(p + 0x1f4))[index]) {
                func_02039C68((struct Link *)func_020399A8(), 15, 10);
                ((Ov099Work *)p)->f1CC = 44;
            } else {
                func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
                func_021BAAB8(p, 13, 0);
                ((Ov099Work *)p)->f1CC = 19;
            }
        }
    }
    return ret;
}








int func_021C14A8(char *p, int ret)
{
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 15, 10) != 0) {
            GFL_NET_SetAutoExit(1);
            func_0203D7BC(1);
            func_02039C68((struct Link *)func_020399A8(), 18, 10);
            ((Ov099Work *)p)->f1CC = 45;
        }
    }
    return ret;
}








/*
 * True when the guard answers true or the pointer 0x190 bytes in is still unset.
 */
BOOL func_021C14EC(char *p)
{
    if (func_021BA928(p) != 0) {
        return 1;
    }

    if (((Ov099Work *)p)->f190 == 0) {
        return 1;
    }

    return 0;
}







int func_021C1510(char *p, int ret)
{
    void *s;
    unsigned count;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 18, 10) != 0) {
            if (func_021C14EC(p) == 1) {
                func_0200F4E4(func_020099C8((struct Sub020097BCObj *)func_0201283C(((Ov099Work *)p)->fC4), 0));
                func_021BA8EC(p);
                s = (void *)func_021C23B8(DWC_RAP_GetTargetFriendIndex());
                func_021BDD48(p, s);
                count = func_021BDD54(p, s);
                if (count == 3) {
                    ((Ov099Work *)p)->f1CC = 65;
                } else {
                    func_021C18C8(p, 4, count);
                    ((Ov099Work *)p)->f1CC = 115;
                }
            }
        }
    }
    return ret;
}







int func_021C158C(char *p,int ret){func_020414AC(3);((Ov099Work *)p)->f1358=0;((Ov099Work *)p)->f1CC=func_021BE4F0(p,0);return ret;}







int func_021C15B4(char *p,int ret){((Ov099Work *)p)->f1CC=47;return ret;}







/*
 * Extent remainder: two-byte alignment padding.
 */
int func_021C15C0(char *p,int ret){if(!func_021BA928(p))return ret;if(func_021BF03C(p))((Ov099Work *)p)->f1CC=48;if(func_020362DC()&3)((Ov099Work *)p)->f1CC=48;return ret;}







/*
 * Runs the setup for selector 0x0B and stamps it 0x1CC bytes in.
 */
int func_021C15FC(char *p, int v)
{
    func_021BA8EC(p);
    ((Ov099Work *)p)->f1CC = 0x0B;
    return v;
}







/*
 * Runs the setup and stamps selector 0x32 when the guard answers true.
 */
int func_021C1614(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 0x32;
    }

    return v;
}






int func_021C1634(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        ((Ov099Work *)p)->f108 = 0;
        func_021BAAB8(p, 26, 1);
        ((Ov099Work *)p)->f1CC = 51;
        ((Ov099Work *)p)->f1E0 = 1;
    } else {
        ((Ov099Work *)p)->f108 = 0;
        func_021BA8EC(p);
        ((Ov099Work *)p)->f1CC = 11;
        func_021C2408(p);
    }
    return ret;
}






/*
 * follower: two zero alignment bytes at 0x021C16EA.
 * lever: func_0203CEAC receives the live zero in r0.
 */
int func_021C169C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (((Ov099Work *)p)->f1E0 == 1) {
        ((Ov099Work *)p)->f1E0 = 0;
        func_0203CEAC(0);
    }
    if (func_0203CD98() == 0) {
        func_02009B3C(((Ov099Work *)p)->f4);
        func_021BAAB8(p, 27, 1);
        ((Ov099Work *)p)->f1CC = 52;
        ((Ov099Work *)p)->f1E0 = 30;
    }
    return ret;
}





int func_021C16EC(char *p,int ret){if(!func_021BA928(p))return ret;if(--((Ov099Work *)p)->f1E0==0){((Ov099Work *)p)->f1D0=0;((Ov099Work *)p)->f1CC=26;func_021BA8EC(p);}return ret;}





int func_021C1724(char *p, int ret)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 16, 10) == 0) return ret;
    GFL_NET_SetAutoExit(0);
    func_0203D7BC(1);
    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 54;
    }
    return ret;
}






/*
 * follower: two zero alignment bytes at 0x021C17D2.
 */
int func_021C1768(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        func_021BAAB8(p, 76, 0);
        func_021BC090(p);
        ((Ov099Work *)p)->f244 = 1;
        ((Ov099Work *)p)->f1CC = 41;
        ((Ov099Work *)p)->f1E0 = 30;
    } else {
        func_021BA8EC(p);
        GFL_NET_STATE_WifiDisconnect(1);
        ((Ov099Work *)p)->f1E0 = 20;
        ((Ov099Work *)p)->f1CC = 57;
    }
    return ret;
}







int func_021C17D4(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        ((Ov099Work *)p)->f1CC = 0x38;
    }

    return v;
}






/*
 * lever: func_021C27E0 returns u8, eliminating the redundant narrowing at 021C1848.
 */
int func_021C17F4(char *p, int state)
{
    void *selection;
    int result;
    selection = func_021BE2A8(p, func_021B97F4(p + 0x274));
    func_0201DD68();
    result = func_021BA858(p);
    if (result == -1) return state;
    if (result == 0) {
        func_021C27E8(((Ov099Work *)p)->f8, 1 - func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8)));
        func_021C2864(((Ov099Work *)p)->f8, func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8)));
        ((Ov099Work *)p)->f1356 = 2 - ((struct Obj22058 *)((char *)((Ov099Work *)p)->f248))->f46;
        ((Ov099Work *)p)->f1CC = 118;
    } else {
        ((Ov099Work *)p)->f135C = 0;
        func_021C18C8(p, 1, 2);
        ((Ov099Work *)p)->f1F0 = -1;
        if (selection != 0) func_021B9AE0(p + 0x274, selection);
        func_021C19A8(p);
        func_021BAEDC(p);
        ((Ov099Work *)p)->f1CC = 11;
    }
    func_021BA8EC(p);
    return state;
}







/*
 * Returns the second argument, or 2 when sub_0203CD98 reports 0.
 */
int func_021C18B4(int a, int b)
{
    int r = b;

    if (sub_0203CD98() == 0) {
        r = 2;
    }

    return r;
}






void func_021C18C8(char *p, int kind, int value)
{
    if ((u8 *)((Ov099Work *)p)->f8 != 0) {
        if (kind == 1 && value == 2) func_021C282C((u8 *)((Ov099Work *)p)->f8);
        if (kind == 4 && value < 3) func_02009B80(((Ov099Work *)p)->f4, DWC_RAP_GetTargetFriendIndex());
        func_021C1908(p, kind, value);
        func_021BE6E4(p);
    }
}






void func_021C1908(char *p, int kind, int value)
{
    int old;
    int oldvalue;
    if (((Ov099Work *)p)->f8 != 0) {
        old = func_021BDD48(p, ((Ov099Work *)p)->f8);
        oldvalue = func_021BDD54(p, ((Ov099Work *)p)->f8);
        if (old != kind || oldvalue != value) {
            func_021BDE30(p, kind, value);
            func_021C27D4(((Ov099Work *)p)->f8, kind);
            func_021C27DC(((Ov099Work *)p)->f8, value);
            if (!(value == 5 && kind == 4)) {
                if (kind != 4) func_021C24A4((Work_021C24A4 *)p, 127);
            }
        }
        func_021BAEDC(p);
    }
}







u8 func_021C1968(Work *w)
{
    w->f248->f46 = 1 - w->f248->f46;
    func_021C27E8(w->f8, w->f248->f46);
    func_021C2864(w->f8, w->f248->f46);
    func_021BE6E4((char *)w);
    return func_021C27E0((S_021C27E0 *)(w->f8));
}





void func_021C19A8(char *p){func_021C24A4((Work_021C24A4 *)p,127);func_021C27E8(((Ov099Work *)p)->f8,*(u8 *)((u32_021C19A8)((Ov099Work *)p)->f248+0x46));func_021C2864(((Ov099Work *)p)->f8,*(u8 *)((u32_021C19A8)((Ov099Work *)p)->f248+0x46));func_021BE6E4(p);func_021C27E0((S_021C27E0 *)(((Ov099Work *)p)->f8));}






/*
 * The ordered teardown of the block: five one-argument steps on p, the re-arm
 * of the 0x274-offset sub-object, and finally func_021C205C with the selector.
 */
void func_021C19DC(char *p, int v)
{
    func_021BB42C(p, v);
    func_021BB4D0(p);
    func_021BB4EC(p);
    func_021C1C70(p);
    func_021BF29C(p);
    func_021B98F0(p + 0x274);
    func_021C205C((u8 *)p, v);
}






/*
 * When the byte 0x8ED bytes in matches, hands the block and the third argument on.
 */
void func_021C1A14(char *p, int b, void *c)
{
    if (b == func_021C1C64(p)) {
        func_021C19DC(p, (int)c);
    }
}






/*
 * When the byte 0x8EF bytes in is set, hands the block and the selector to
 * func_021C19DC.  The selector is live into the call, which is why the image
 * materialises the 0x8EF constant in r2 rather than r1.
 */
void func_021C1A30(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        func_021C19DC((char *)p, v);
    }
}














/*
 * True when the word 0x8C8 bytes into the block is set.
 */
BOOL func_021C1A44(char *p)
{
    if ((unsigned int)((Ov099Work *)p)->f8C8 != 0) {
        return 1;
    }

    return 0;
}













void func_021C1A58(char *p, int a, int heap)
{
    func_02082BCC(p + 0x8b0, 0, 0xf4);
    func_02043598(7, 1);
    func_02043598(8, 0);
    ((Ov099Work *)p)->f8C8 = func_02051B84((u8 *)d_021C377C, (int)func_021C1C9C, (int)p, heap);
    ((Ov099Work *)p)->f8B0 = func_0201EC64((u16)heap);
    func_021C1D1C((u8 *)p, (void *)a, heap);
    ((Ov099Work *)p)->f8F4 = 1;
    func_021C208C(p);
    func_021C2090(p);
}













void func_021C1AC0(char *p)
{
    if (func_021C1A44(p)) {
        func_021C1F74(p);
        func_02051C6C(((Ov099Work *)p)->f8C8);
        ((Ov099Work *)p)->f8C8 = 0;
        func_0201ED04(((Ov099Work *)p)->f8B0);
        ((Ov099Work *)p)->f8B0 = 0;
        func_02043598(1, 1);
        func_02043598(14, 0);
    }
}













/*
 * lever: byte addition of 254 emits adds #0xfe; subtraction emits subs #2.
 * prototype: B9800/B984C leave their C4864 result live; this caller reads r0.
 */
u8 func_021C1B04(char *p, int heap)
{
    u32_021C1B04 first, second;
    first = func_021B9800(p + 0x274);
    second = func_021B984C(p + 0x274);
    if (second >= 3 && second <= 6) first = second;
    if (first >= 3 && first <= 6 && ((Ov099Work *)p)->f8EC != first - 3) {
        ((Ov099Work *)p)->f8EC = first - 3;
        func_021C208C(p);
        ((Ov099Work *)p)->f8F1 = 1;
        ((Ov099Work *)p)->f8F4 = 1;
    }
    if (((Ov099Work *)p)->f8EF == 1) {
        ((Ov099Work *)p)->f8EF = 2;
        func_021BB2F0(p, heap);
    }
    if (((Ov099Work *)p)->f8EF == 0) {
        func_021BB42C(p);
        func_021BB4D0(p);
        func_021BB4EC(p);
        func_02051C88(((Ov099Work *)p)->f8C8);
        func_021C1CD4((Work_021C1CD4 *)p);
        if (((Ov099Work *)p)->f8F1 == 1) {
            func_021C2090(p);
            ((Ov099Work *)p)->f8F1 = 0;
        }
    }
    if ((u8)(((Ov099Work *)p)->f8EF + 254) <= 1 && func_021C1C10((Work_021C1C10 *)p) == 1) {
        ((Ov099Work *)p)->f8ED = 0;
        ((Ov099Work *)p)->f8EE = 0;
        ((Ov099Work *)p)->f8F1 = 1;
        ((Ov099Work *)p)->f8F4 = 1;
        func_021C19DC(p, heap);
        ((Ov099Work *)p)->f8EF = 0;
        ((Ov099Work *)p)->f8F4 = 1;
    }
    return ((Ov099Work *)p)->f8ED;
}














/*
 * When the flag at +0x8EF is clear and the selector at +0x8F1 is 1, runs
 * func_021C2090 on the block and clears the selector.
 */
void func_021C1BEC(u8 *p)
{
    if (p[0x8EF] != 0) {
        return;
    }

    if (p[0x8F1] != 1) {
        return;
    }

    func_021C2090((char *)p);
    p[0x8F1] = 0;
}














int func_021C1C10(Work_021C1C10 *w)
{
    if (w->f8ef == 3)
        return 0;
    if (w->f9ac != 0) {
        func_021B63D0(w->f9ac);
        if (func_021B6448(w->f9ac) == 1)
            return 1;
    }
    if ((func_0203630C() & 0xf0) || (func_020362DC() & 0x403))
        return 1;
    return 0;
}














/*
 * Byte getter 0x8ED bytes into the block.
 */
u8 func_021C1C64(char *p)
{
    return ((Ov099Work *)p)->f8ED;
}














/*
 * Clears the flag block 0x8ED bytes in and sets the keep flag when the entry test answers 1.
 */
void func_021C1C70(char *p)
{
    if (func_021C1A44(p) != 1) {
        return;
    }

    p[0x8ED] = 0;
    p[0x8EE] = 0;
    p[0x8EF] = 0;
    p[0x8F1] = 1;
    ((Ov099Work *)p)->f8F4 = 1;
}













void func_021C1C9C(u32_021C1C9C a,int b,u32_021C1C9C p){u32_021C1C9C offset;offset=a+(((Ov099Work *)p)->f8EC<<3);if(*(u8 *)(p+offset+0x8cc)==2 && ((Ov099Work *)p)->f8ED==0 && b==0){((Ov099Work *)p)->f8ED=offset+1;func_020061E4(1356);}}














void func_021C1CD4(Work_021C1CD4 *w)
{
    if (w->f8ed) {
        w->f8ee = d_021C3720[w->f8f2];
        w->f8f2++;
        w->f8f1 = 1;
        if (w->f8f2 >= 16) {
            w->f8f2 = 0;
            w->f8ee = 0;
            w->f8ef = 1;
        }
    }
}














/*
 * note: 2026-10-05 (wD9r lane29): EXACT. y = i % 4 and x = i / 4 as plain locals, with the scaling written at each use
 *   ((x << 4) + 4, y * 6 + 1), and no q local (`*(void **)(p + i * 4 + 0x8F8)` at each use). The multiplied forms
 *   become CSE temps computed at the call, so y*6 and x<<4 stay in r7/r5 and p + i*4 is the spilled value.
 * note: 2026-10-05 (wD9r lane05): not changed, 284 bytes. Tried: inner call result in a local r before the store
 *   (282 B, address then computed after the call); q2 = p + i*8 (or q reused) before the inner loop; y as
 *   `y = i % 4; y *= 6;`, `6 * (i % 4)`, x as `x = i / 4; x <<= 4;`; `x++; y++;` before the inner loop with x/y in
 *   the call; x and y (and q) declared in the loop block (all 284); x computed before y (330). The image hoists
 *   (u8)(y+1), x+1, p+i*8 in that order; ours p+i*8, x+1, (u8)(y+1).
 * note: 2026-10-05 (wD8 lane05): not changed, 284 bytes. Re-read: image keeps y r7, x r5 across the three first-block
 *   calls and spills q (2 uses after the call: the store value is forwarded to func_02045770). Tried: the first call result in a local
 *   r stored to q + 0x8F8 and passed to func_02045770 (same 284 bytes); q computed before y and x (330, as wD6).
 *
 * note: 2026-10-05 (wD7 lane09): not changed, 284 bytes. Re-read the loop: the image keeps y = (i % 4) * 6 in r7 (adds r7,r1; muls r7,r0,r7), x in r5, the 0x8F8 pool offset in r6 and j in r4 (j = 0 set before the 3B5C call); p is spilled at [sp,#0x10], q = p + i*4 at [sp,#0x14], p + i*8 at [sp,#0x18], x + 1 at [sp,#0x1c], i at [sp,#0x20], (u8)(y + 1) at [sp,#0x24], 0x918 at [sp,#0x28] (stored twice, x = r6; x += 0x20). So the image spills q (3 uses) and keeps y (2 uses). Tried: q inline as p + i*4 + 0x8F8 (same 284), q as ((void **)(p + 0x8F8))[i] (308), y and/or x declared u32_021C1A44 (same).
 * note: 2026-10-05 (wD6 lane13): not improved, 284 bytes (size 600 matches now). Tried: q = p + i*4 first in the body (330 B), q inline with x and y locals (284 B), x inline (293 B). y stays the spilled value; the image spills q. The 0x8F8 offset is held in r6 and 0x918 copies are derived from it in both builds.
 * 2026-10-04 (wave D3 lane 20): 596 of 600 bytes. Everything up to the loop matches. In the loop
 * body the original keeps x = ((i >> 1) / 4) << 4 in r5 and spills q = p + i*4 to sp+0x14;
 * this draft does the reverse (x spilled to sp+0x18, q in r5). i sits at sp+0x20 in the
 * original and sp+0x1c here: the original has one more spilled loop invariant. Tried: local
 * declaration order, no q local, a struct with a[8] and b[8][2] arrays (identical output).
 * Zero stack arguments come from i = 0 (ldr from the i slot), kept. y = (i % 4) * 6.
 *
 * 2026-10-05 (wave D4 lane 04): DIFF, 313 bytes. func_020450F0 third parameter is u8 here (the
 * original truncates y + 1 with lsls/lsrs #0x18 in both calls and hoists the inner (u8)(y + 1) to
 * [sp,#0x24]); x written inline as (i / 4 << 4) (a CSE temp in r5, as in the original); q and r
 * locals removed. i is now at [sp,#0x20] as in the original. Residue: y = (i % 4) * 6 spilled to
 * [sp,#0x1c]; the original keeps y in r7 and spills p + i*4 to [sp,#0x14]; size still 596 vs 600.
 * Tried: y inline too (y + 1 then CSEs, wrong), y declared first or last, register y.
 * 2026-10-05 (wave D5 lane 08): DIFF, 284 bytes (size still 596 vs 600). Logic fix: the original computes
 *   x = (i / 4) << 4 (asrs #1; lsrs #0x1e; adds; asrs #2 is the signed /4 idiom), not (i >> 1) / 4.
 *   Named locals x and q = p + i*4 now give the original order (u8)(y + 1), x, q. Residue: y spilled to
 *   [sp,#0x18] with x in r7 and q in r5; the original keeps y in r7, x in r5 and spills q to [sp,#0x14]
 *   (i at [sp,#0x20]). With x and q inline (no locals) x is in r5 and i at [sp,#0x20] but y is spilled.
 * note: 2026-10-05 (wD9 lane11): not changed, 284 bytes. Tried: declaration orders q,y,x / y,x,q / q,x,y,i,j
 *   (all 284, the colouring does not follow declaration order here); the inner j loop as a static inline
 *   Inner(p, i, x, y) (284); q written inline (CSE gives the same r5 temp, 284). Slot map: image q 0x14, p+i*8 0x18,
 *   x+1 0x1c, i 0x20, (u8)(y+1) 0x24, 0x918 0x28; ours y 0x18, p+i*8 0x14, i 0x1c, x+1 0x20 (x+1 and i swapped too).
 */
void func_021C1D1C(u8 *p, void *a, int heap)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    func_02049B68(a, 6, 4, 0, 0x100, heap);
    *(u32_021C1D1C *)(p + 0x9A8) = func_02049740(a, 0xe, 4, 0, i, heap);
    func_02049658(a, 0xf, 6, 0x80, i, i, heap);
    func_02049990(a, 0x16, 4, 0, (u16)*(u32_021C1D1C *)(p + 0x9A8), i, i, heap);
    *(void **)(p + 0x8B4) = func_02049EF4(a, 0x17, 0, (void **)(p + 0x8B8), heap);
    func_021C1FE8(*(u16 **)(p + 0x8B8), 0x80);
    *(void **)(p + 0x8BC) = func_02049EF4(a, 0x19, 0, (void **)(p + 0x8C0), heap);
    func_021C1FE8(*(u16 **)(p + 0x8C0), 0x80);
    func_02049B40(0x17, 5, 4, 0xf << 5, 0x20, heap);
    for (i = 0; i < 8; i++) {
        y = i % 4;
        x = i / 4;
        *(void **)(p + i * 4 + 0x8F8) = func_020450F0(7, (x << 4) + 4, y * 6 + 1, 9, 3, 0xf, 1);
        func_02043B5C(func_02045770(*(void **)(p + i * 4 + 0x8F8)), 0);
        func_02045334(*(void **)(p + i * 4 + 0x8F8));

        for (j = 0; j < 2; j++) {
            *(void **)(p + i * 8 + j * 4 + 0x918) = func_020450F0(5, (x << 4) + 1 + j * 12, y * 6 + 1, 2, 3, 0xf, 1);
            func_02043B5C(func_02045770(*(void **)(p + i * 8 + j * 4 + 0x918)), 0);
            func_02045334(*(void **)(p + i * 8 + j * 4 + 0x918));
        }
    }
    *(void **)(p + 0x958) = func_020450F0(7, 1, 1, 0x1e, 2, 0xf, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x958)), 0);
    func_02045374(*(void **)(p + 0x958));
    func_02045334(*(void **)(p + 0x958));
    *(void **)(p + 0x95C) = func_020450F0(7, 1, 5, 0x1e, 0x11, 0xf, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x95C)), 0);
    func_02045374(*(void **)(p + 0x95C));
    func_02045334(*(void **)(p + 0x95C));
    func_020409B4(4);
    func_020409B4(7);
}













void func_021C1F74(char *p)
{
    int i;
    int j;
    for (i = 0; i < 8; i++) {
        func_020452E8(((Work_021C1F74 *)p)->windows[i]);
        for (j = 0; j < 2; j++) func_020452E8(((Work_021C1F74 *)p)->pairs[i][j]);
    }
    func_020452E8(((Ov099Work *)p)->f958);
    func_020452E8(((Ov099Work *)p)->f95C);
    func_020307B0(((Ov099Work *)p)->f8B4);
    func_020307B0(((Ov099Work *)p)->f8BC);
}














/*
 * Adds d to each halfword of the w x h block at +0x0C, where w and h are
 * the two header halfwords at +0 and +2 shifted right by three.
 *
 * The register split is a source-shape fact, not allocator taste.  Reading
 * the header into named u16 locals first (`w0 = p[0]; h0 = p[1];`) and only
 * then shifting into the int sizes (`(u32_021C1A44)w0 >> 3`) is what gives the
 * image's two-instruction prologue tail - the raw halfwords stay in r1/r0
 * while the shifts write fresh r3/r7, and r1 is then free for the i
 * counter.  Shifting straight off `p[0] >> 3` reuses r1 for the width and
 * pushes i into r2, seven register-name residues over 14 bytes.
 * The (u32_021C1A44) cast on the shifted operand is required for `lsrs` (a bare
 * u16-promoted shift gives `asrs`), and the int counters keep the two
 * signed `ble`/`blt` the image has.
 */
void func_021C1FE8(u16 *p, u16 d)
{
    u16 *q = (u16 *)((u8 *)p + 0xC);
    u16 w0 = p[0];
    u16 h0 = p[1];
    int i, j;
    int w = (u32_021C1FE8)w0 >> 3;
    int h = (u32_021C1FE8)h0 >> 3;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            q[i * w + j] += d;
        }
    }
}













/*
 * Byte setter at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
void func_021C2028(char *p, int i, u8 v)
{
    *(u8 *)(p + i + 0x8CB) = v;
    ((Ov099Work *)p)->f8F1 = 1;
}













/*
 * Clears the byte at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
void func_021C203C(char *p, int i)
{
    *(u8 *)(p + i + 0x8CB) = 0;
    ((Ov099Work *)p)->f8F1 = 1;
}













u8 func_021C2050(char *p, int i)
{
    return *(u8 *)(p + i + 0x8CB);
}













/*
 * Routes on the flag byte 0x8EF bytes in: hands the selector on to func_021BB2F0
 * when it is set, otherwise raises the word at +0x8F4 and calls func_021C2090.
 * The selector stays live into the first branch, which is what keeps the 0x8EF
 * constant out of r1 and gives the image its `adds r1, r2, #5`.
 */
void func_021C205C(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        func_021BB2F0((char *)p, v);
        return;
    }

    ((Ov099Work *)p)->f8F4 = 1;
    func_021C2090((char *)p);
}













/*
 * Sets the word at +0x8F4 and the byte at +0x8F1.
 */
void func_021C207C(char *p)
{
    ((Ov099Work *)p)->f8F4 = 1;
    ((Ov099Work *)p)->f8F1 = 1;
}












/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021C208C(char *a0)
{
}













void func_021C2090(char *p)
{
    int i;
    int flag;
    int idx;
    int mode;
    int slot;
    int px;
    int py;
    int sel;

    if (*(int *)(p + 0x8F4) == 1) {
        *(int *)(p + 0x8F4) = 0;
        flag = 1;
        func_020414AC(7);
    } else {
        flag = 0;
    }
    for (i = 0; i < 8; i++) {
        idx = i + *(u8 *)(p + 0x8EC) * 8 + 1;
        if (*(u8 *)(p + 0x8CB + idx) != 0) {
            if (func_02009864(*(void **)(p + 4), idx - 1, 9) == 0) {
                mode = 0;
            } else {
                mode = 1;
            }
        } else {
            mode = 2;
        }
        px = i / 4;
        py = i % 4;
        if (idx == *(u8 *)(p + 0x8ED)) {
            slot = *(u8 *)(p + 0x8EE);
        } else {
            slot = 0;
        }
        if (idx == *(u8 *)(p + 0x8ED) || idx == *(u8 *)(p + 0x8F3)) {
            sel = 1;
        } else {
            sel = 0;
        }
        if (flag == 1 || sel == 1) {
            func_021C2224(p, (u8)(px * 16), (u8)(py * 6), (u8)mode, (u8)slot);
            if (mode != 2) {
                func_021C2274(p, *(void **)(p + i * 4 + 0x8F8), idx, slot, i);
                func_02045374(*(void **)(p + i * 4 + 0x8F8));
                func_021C22E8(p, p + 0x918 + i * 8, idx, slot, px * 16, py * 6);
            } else {
                int j;
                func_02043B5C(func_02045770(*(void **)(p + i * 4 + 0x8F8)), 0);
                func_02045334(*(void **)(p + i * 4 + 0x8F8));
                for (j = 0; j < 2; j++) {
                    func_02043B5C(func_02045770(*(void **)(p + i * 8 + j * 4 + 0x918)), 0);
                    func_02045334(*(void **)(p + i * 8 + j * 4 + 0x918));
                }
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(6);
    func_02043598(2, 1);
    func_02043598(8, 1);
}













void func_021C2224(char *p, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 mode, u8 slot)
{
    u16 x;
    u16 y;
    if (mode == 2) {
        x = 0;
        y = 0x12;
    } else {
        x = (u16)(mode << 4);
        y = (u16)(slot * 6);
    }
    func_020410D0(6, a1, a2, 0x10, 6, *(u32_021C2224 *)(p + 0x8B8) + 0xC, x, y, 0x20, 0x18);
}











void func_021C2274(char *p, void *window, int id, int slot, int i)
{
    func_02043B5C(func_02045770(window), 0);
    func_0201DD78(15, 2, 0);
    func_021C2370((Work_021C1A44 *)p, id - 1);
    func_02045CAC((void *)((Ov099Work *)p)->fE0, 33, ((Ov099Work *)p)->fF0);
    func_0201F250(((Ov099Work *)p)->f8B0, ((Ov099Work *)p)->fF8, ((Ov099Work *)p)->fF0);
    func_0201C7A4(func_02045770(window), 2, 8, ((Ov099Work *)p)->fF8, (void *)((Ov099Work *)p)->fE8);
    func_02045334(window);
}











void func_021C22E8(char *p, void *unused, int id, int flag, int x, int y)
{
    int offset;
    void *s;
    int kind;
    int value;
    int icon;
    offset = 0;
    if (flag != 0) offset = 16;
    s = (void *)func_021C23B8(id - 1);
    kind = func_021BDD48(p, s);
    value = func_021BDD54(p, s);
    func_021BE4BC(p + 0x898, 6, (u8)(x + 2), (u8)(y + 2), kind, (int)value, offset);
    if (func_021C285C(s)) icon = 15;
    else icon = 11;
    func_021BE3CC(p + 0x898, 6, x + 12, y + 2, (int)(icon + offset), 0);
    func_02041B6C(7);
}











void func_021C2370(Work_021C1A44 *w, int id)
{
    int r;

    if (id != -1) {
        r = func_02009864(w->f4, id, 9);
        func_020099E4(w->f4, id, (void *)w->ff0);
        func_0201EE0C((struct WordSet *)w->f8b0, 0, (const void *)w->ff0, r, 1, 2);
    }
}










/*
 * Unblocked (was MATCH on one witness).
 * +0004 ABS32 DWC_RAP_GetFriendStatusData          -> resolved as `matched` by
 * src/matched/ov009_func_02156860.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), declared as `DWC_RAP_GetFriendStatusData 0x02156860 thumb ov009` below.
 */
int func_021C23B8(int i) { return DWC_RAP_GetFriendStatusData(i); }










/*
 * Tail call thunk into ov009.
 */
unsigned char func_021C23C0(void *a)
{
    return DWC_RAP_GetFriendStatus((int)a);
}










/*
 * Two arm9/overlay calls, the first on the first argument and the second on the second.
 */
int func_021C23C8(void *a, void *b)
{
    func_021BA7D8(a);
    return sub_0203C2B0((int)b);
}










/*
 * Raises the state word at +0x9B4 once, re-arms the block 0x274 bytes in, and
 * runs the six/zero setup when the selector is 1.
 */
void func_021C23D8(char *p, int v)
{
    if (((Ov099Work *)p)->f9B4 != 0) {
        return;
    }

    ((Ov099Work *)p)->f9B4 = 1;
    func_021B98F8(p + 0x274, 1);

    if (v == 1) {
        func_021BAADC(p, 6, 0);
    }
}










/*
 * When the state word at +0x9B4 is 1, clears it and tears down the two sub-objects.
 */
void func_021C2408(char *p)
{
    if (((Ov099Work *)p)->f9B4 != 1) {
        return;
    }

    ((Ov099Work *)p)->f9B4 = 0;
    func_021BA8EC(p);
    func_021B98F8(p + 0x274, 0);
    ((Ov099Work *)p)->f135C = 0;
}









int func_021C2438(char *p)
{
    int remaining;
    int start;
    int delta;
    if (((Ov099Work *)p)->f1343 != 0) {
        --((Ov099Work *)p)->f1343;
        remaining = ((Ov099Work *)p)->f1343;
        if (remaining != 0) {
            start = ((Ov099Work *)p)->f1342;
            delta = start - ((Ov099Work *)p)->f1341;
            if (delta < 0) ((Ov099Work *)p)->f1340 = start + (-delta / 6) * remaining;
            else ((Ov099Work *)p)->f1340 = start - (delta / 6) * remaining;
            GFL_USE_SetBgmTrackVolume(0xffff, ((Ov099Work *)p)->f1340);
            return 0;
        }
        ((Ov099Work *)p)->f1340 = ((Ov099Work *)p)->f1342;
        GFL_USE_SetBgmTrackVolume(0xffff, ((Ov099Work *)p)->f1342);
    }
    return 1;
}









void func_021C24A4(Work_021C24A4 *w, int v)
{
    if (w->f1342 != v) {
        w->f1341 = w->f1340;
        w->f1343 = 6;
        w->f1342 = v;
        GFL_USE_SetPlayerVolumes(v, 0x3f);
        PM_VOICE_SetMasterVolume(v);
    }
}









/*
 * Stamps the byte at +0x1342 with 0x2A when the selector is 4 and 0x7F otherwise,
 * then copies it down to +0x1341.
 */
void func_021C24D4(u8 *p, int v)
{
    if (v == 4) {
        p[0x1342] = 0x2A;
    } else {
        p[0x1342] = 0x7F;
    }

    p[0x1341] = p[0x1342];
}








int func_021C24F0(void *obj, int unused, char *args)
{
    char *p;
    func_0203064C(1, 0x8021, 0xa4000);
    p = func_0203159C(obj, 0x1360, 0x21);
    func_02082BCC(p, 0, 0x1360);
    GFL_NET_SetUserArg((u32_021C24F0)p);
    ((struct Obj01386 *)p)->f8 = ((struct Obj02804 *)args)->f0;
    ((struct Obj01386 *)p)->fC0 = ((struct Obj02804 *)args)->f8;
    *(u32_021C24F0 *)&((struct Obj01386 *)p)->fC4 = ((struct Obj02804 *)args)->f4;
    ((struct Obj01386 *)p)->fCC = func_021BCB8C(((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fC8 = func_02012934(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->f4 = func_0201283C(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fD8 = (u32_021C24F0)func_0200873C((void *)(((struct Obj02804 *)args)->f8));
    ((struct Obj01386 *)p)->f1D8 = *(u32_021C24F0 *)&((struct Obj02804 *)args)->fC;
    ((struct Obj01386 *)p)->f135C = ((struct Obj02804 *)args)->f49;
    if (((struct Obj02804 *)args)->fC == 1) {
        ((struct Obj02804 *)args)->fC = 0;
        func_021C24D4((u8 *)p, 4);
    } else if (((struct Obj02804 *)args)->fC != 0) {
        func_021C24D4((u8 *)p, 4);
    } else {
        func_021C24D4((u8 *)p, 1);
    }
    ((struct Obj01386 *)p)->f1D0 = 0;
    ((struct Obj01386 *)p)->f1F0 = -1;
    *(char * *)&((struct Obj01386 *)p)->f248 = args;
    func_020434DC(15, 0);
    func_02043598(15, 0);
    func_021BB1A8(p);
    ((struct Obj01386 *)p)->f1CC = 0;
    func_021BDE94(p);
    if (((struct Obj02804 *)args)->fC == 0) func_021BE6F0(p, 1, 2);
    if (func_0203CD98() != 0) {
        func_021BA7D8(p);
        func_0203D34C(1, 0x21);
    }
    return 1;
}








int func_021C2604(int task,int *state,int unused,char *p) {
 u8 r,g,b;
 Handler fn;
 if(func_0203CD98()!=0) {
  switch(DWC_RAPCOMMON_HandleNetError(1,1)) {
   case 4:
    func_021BC0C4(p);func_021BB0B4(p);GFL_NET_SetAutoExit(0);func_0203D7BC(0);func_021C18C8(p,1,2);
    ((Ov099Work *)p)->f1E0=20;((Ov099Work *)p)->f1CC=0x39;return 0;
   case 2:
    func_0202223C(0,0);func_0202223C(1,0);((Ov099Work *)p)->f1D0=1;return 1;
  }
 }
 if(func_0200FB24()==0) {
  fn=d_021C3C0C[((Ov099Work *)p)->f1CC];
  if(fn!=0) {
   *state=fn(p,*state);
   if(*state==2) {func_0202208C(0,0,0,0,6,1,0x21);return 1;}
  }
 }
 if(((Ov099Work *)p)->f110!=0) func_0204A600(((Ov099Work *)p)->f110);
 if(((Ov099Work *)p)->f1B8!=0) {
  GF_FONT_GetTextColor(&r,&g,&b);func_0201DD78(1,2,15);func_020310C4(((Ov099Work *)p)->f1C0);func_0201DD78(r,g,b);func_0201C4E4(((Ov099Work *)p)->f1B8);
 }
 if(((Ov099Work *)p)->f1B4!=0) func_0201C4E4(((Ov099Work *)p)->f1B4);
 func_021C2438(p);return 0;
}








int func_021C2724(void *task, int unused, char *output, char *p)
{
    if (!func_021C2438(p)) return 0;
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_021BA7F8(p);
    ((struct Obj06360 *)output)->f49 = ((struct Obj03736 *)p)->f135C;
    if (((struct Obj03736 *)p)->f1348) {
        func_0200AE08(((struct Obj03736 *)p)->f1348, ((struct Obj06360 *)output)->f1C);
        func_020307B0(((struct Obj03736 *)p)->f1348);
        ((struct Obj03736 *)p)->f1348 = 0;
    }
    func_021BC0C4(p);
    func_021BDF7C(p);
    ((struct Obj06360 *)output)->f47 = ((struct Obj03736 *)p)->f242;
    ((struct Obj06360 *)output)->fC = ((struct Obj03736 *)p)->f1D0;
    if (func_0203CD98()) ((struct Obj06360 *)output)->f10 = DWC_RAP_GetTargetFriendIndex();
    func_021BCBB0(((struct Obj03736 *)p)->fCC);
    func_021BB224(p);
    func_020315D4(task);
    func_020306F0(33);
    return 1;
}









/*
 * Byte getter at +0x18.
 */
u8 func_021C27D0(S_021C27D0 *s)
{
    return s->f18;
}









/*
 * Byte setter at +0x18, the pair of func_021C27D0.
 */
void func_021C27D4(S_021C27D4 *s, u8 v)
{
    s->f18 = v;
}









/*
 * Byte getter at +0x17.
 */
u8 func_021C27D8(S_021C27D8 *s)
{
    return s->f17;
}








/*
 * Byte setter at +0x17, the pair of func_021C27D8.
 */
void func_021C27DC(S_021C27DC *s, u8 v)
{
    s->f17 = v;
}








/*
 * One-bit field at bit 1 of the byte at +0x1B: an `unsigned char` bitfield
 * container, which is why the read is `ldrb` + `lsls #0x1e` + `lsrs #0x1f`.
 */
u8 func_021C27E0(S_021C27E0 *s)
{
    return s->b1;
}








void func_021C27E8(S_021C27E8 *s, u8 v)
{
    s->b1 = v;
}








/*
 * True when the arm9 comparison of the two blocks, 0x0E and 8 bytes in, answers 0.
 */
BOOL func_021C27F8(char *p, char *q)
{
    if (func_0203EFC8((const u8 *)(p + 0xE), (const u8 *)(q + 8), 6) == 0) {
        return 1;
    }

    return 0;
}






/*
 * Bumps the counter at +0x1C and tails onto the arm9 routine with the block 8 bytes in.
 */
void func_021C2810(S_021C1A44 *s, char *q)
{
    s->f1C++;
    func_02082D44(q + 0xE, (char *)s + 8, 6);
}





int func_021C282C(u8 *p)
{
    u8 z[6] = {0, 0, 0, 0, 0, 0};

    return func_02082D44(z, p + 8, 6);
}




void func_021C2850(char *p) { func_02087C6C(p + 0xe); }





/*
 * One-bit field at bit 4 of the byte at +0x1B (`lsls #0x1b; lsrs #0x1f`).
 */
int func_021C285C(S_021C2850 *s)
{
    return s->b4;
}





/*
 * One-bit field at bit 4 of the byte at +0x1B, from a byte argument.
 */
void func_021C2864(S_021C2850 *s, u8 v)
{
    s->b4 = v;
}
