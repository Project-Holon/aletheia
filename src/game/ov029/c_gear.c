/*
 * file:     c_gear.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEF8, func_021EFF00, func_021EFF58, func_021F0000, func_021F0064, func_021F009C, func_021F0194, func_021F020C, func_021F0298, func_021F0300, func_021F0370, func_021F0390, func_021F05B4, func_021F05D0, func_021F06B8, func_021F0728, func_021F07AC, func_021F07EC, func_021F0824, func_021F0858, func_021F088C, func_021F08BC, func_021F09B4, func_021F09DC, func_021F0A0C, func_021F0A38, func_021F0A68, func_021F0AA0, func_021F0AC8, func_021F0AE0, func_021F0B00, func_021F0B7C, func_021F0B88, func_021F0C00, func_021F0C68, func_021F0C70, func_021F0CA0, func_021F0CB8, func_021F0CDC, func_021F0CF0, func_021F0D00, func_021F0D08, func_021F0D10, func_021F0D14, func_021F0D48, func_021F0D80, func_021F0DB4, func_021F0E70, func_021F0EB0, func_021F0F28, func_021F0F70, func_021F0FB0, func_021F0FF0, func_021F1000, func_021F1010, func_021F1060, func_021F11B4, func_021F122C, func_021F1290, func_021F133C, func_021F13FC, func_021F1458, func_021F1574, func_021F15FC, func_021F1624, func_021F1740, func_021F1758, func_021F18F0, func_021F1910, func_021F1950, func_021F1A44, func_021F1A64, func_021F1B30, func_021F1B50, func_021F1BBC, func_021F1BE4, func_021F1C0C, func_021F1CD8, func_021F1DB0, func_021F1DE8, func_021F1E98, func_021F1F24, func_021F1F70, func_021F1F80, func_021F20AC, func_021F2130, func_021F2180, func_021F21B4, func_021F21F8, func_021F2370, func_021F23CC, func_021F24C0, func_021F24FC, func_021F2508, func_021F251C, func_021F26E0, func_021F279C, func_021F27D8, func_021F2848, func_021F2980, func_021F2984, func_021F2994, func_021F29D8, func_021F2AB8, func_021F2AD4, func_021F2AEC, func_021F2B9C, func_021F2BB8, func_021F2BD4, CTRDG_IsAgbCartridge, func_021F2C10, func_021F2C78, func_021F2CD4, func_021F2CD8, func_021F2CF4, func_021F2D10, func_021F2D30, func_021F2D50, func_021F2D84, func_021F2DA8, func_021F2DC8, func_021F2E10, func_021F2E5C, func_021F2E68, func_021F2E8C, func_021F2EEC, func_021F2F60, func_021F3098, func_021F30C8, func_021F30EC, func_021F3118, func_021F3144, func_021F3190
 * address:  0x021EFEC0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   CLACT_SetActorSurfacePosAxis  0x0204B49C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   func_0204B98C 0x0204B98C arm
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 *   d_021F31BC     0x021F31BC  data  ov029  a2
 *   d_021F31AB     0x021F31AB  data  ov029  a1
 *   d_021F31B0     0x021F31B0  data  ov029  a1
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02158630  0x02158630  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F31EC     0x021F31EC  data  ov029  a4
 *   d_021F31F8     0x021F31F8  data  ov029  a4
 *   d_021F3255     0x021F3255  data  ov029  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3292 0x021F3292 data ov029 a1
 *   d_021F3204 0x021F3204 data ov029 a1
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   func_02082BCC 0x02082BCC arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F323C     0x021F323C  data  a1
 *   d_021F32B3 0x021F32B3 data a1
 *   d_021F3344     0x021F3344  data  a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D55C 0x0207D55C arm
 *   func_0201210C 0x0201210C thumb
 *   func_02189A48 0x02189A48 thumb ov021
 *   PALANM_GetDefaultWork  0x02021728  thumb
 *   func_02021730  0x02021730  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F31B6     0x021F31B6  data  a2
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_ForceStopFade 0x02021B18 thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   d_021F3324     0x021F3324  data  a4
 *   d_021F331C     0x021F331C  data  a4
 *   d_021F3410     0x021F3410  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F348C     0x021F348C  data  a4
 *   d_021F3334     0x021F3334  data  a4
 *   func_0204162C  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   func_020091AC  0x020091AC  thumb
 *   d_021F332C     0x021F332C  data  a4
 *   func_02049F78  0x02049F78  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F32E0     0x021F32E0  data  a4
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   GFL_NET_RestartWithTimeout  0x0203D88C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   d_021F338C     0x021F338C  data  ov029  a4
 *   d_021F33AC     0x021F33AC  data  a4
 *   d_021F336C     0x021F336C  data  ov029  a4
 *   func_0207D63C 0x0207D63C arm
 *   func_020355D8  0x020355D8  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0203FB44  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_0204B954  0x0204B954  arm
 *   func_02043598  0x02043598  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_0204BA20  0x0204BA20  arm
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   GAME_BEACON_GetReceiveCount  0x02026C8C  thumb
 *   GAME_BEACON_GetNextNewLogIndex  0x02026CA0  thumb
 *   GAME_BEACON_GetLogByReceiveNo  0x02026C78  thumb
 *   func_02165CD8  0x02165CD8  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02051B84  0x02051B84  arm
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020403F4  0x020403F4  arm
 *   UI_GetPowerState 0x0203568C arm
 *   d_021F3520 0x021F3520 data a1
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0204B404  0x0204B404  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_02051C88  0x02051C88  arm
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020072CC  0x020072CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02009210  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   func_0200C6F0  0x0200C6F0  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040AE0  0x02040AE0  arm
 *   func_0200734C  0x0200734C  thumb
 *   d_021F3554     0x021F3554  data  a4
 *   func_02030D28  0x02030D28  arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02009100  0x02009100  thumb
 *   func_02021518  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02035010  0x02035010  arm
 *   func_02035040  0x02035040  arm
 *   func_020120D8  0x020120D8  thumb
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02158614  0x02158614  thumb  ov010
 *   GFL_NET_RestartNoTimeout  0x0203D8AC  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_02049238  0x02049238  arm
 *   func_020056EC  0x020056EC  thumb
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb
 *   func_0202223C  0x0202223C  thumb
 *   WIPE_ResetBrightness  0x02022230  thumb
 *   func_02009110 0x02009110 thumb
 *   func_02009134 0x02009134 thumb
 *   func_02009160 0x02009160 thumb
 *   d_021F3224     0x021F3224  data  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124AC  0x020124AC  thumb
 *   EVENT_GSYNC_Entry  0x02154668  thumb  ov000
 *   abs_id_0       0x00000000  data
 *   func_021559E4  0x021559E4  thumb  ov010
 *   func_0215FBF4  0x0215FBF4  thumb  ov010
 *   func_02167044  0x02167044  thumb  ov010
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_02014808  0x02014808  thumb
 *   abs_id_124     0x0000007C  data
 *   d_021D4D40     0x021D4D40  data  ov124  a4
 *   func_021D297C  0x021D297C  thumb  ov021
 *   func_0201235C  0x0201235C  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   CTRDGi_IsAgbCartridgeAtInit 0x02035c60 arm
 *   func_020091FC  0x020091FC  thumb
 *   func_0204932C  0x0204932C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

#include "c_gear_types.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT (*(volatile u16 *)0x04001050)
#define REG_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)

typedef enum { Zero } ZeroValue;

struct GameEvent;
struct GameData;
struct PlayerSettings;
struct SaveData;
struct SaveCtrl;
struct CustomBgBuffer;
struct SoundSys;
struct BeaconLog;

struct BgTemplate {
    u32 x;
    u32 y;
    u32 bufSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 areaOver;
    u8 bgMode;
    u8 priority;
    u8 mosaic;
    u8 padding;
    u32 reserved;
};

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

extern void func_0204B878(struct Actor *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern struct Actor *func_0204B294(struct ActorSystem *system, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Actor *p, u32 v);
extern void func_0204B3DC(struct Actor *p, u32 v);
extern u16 CLACT_GetActorAnimSeqCount(struct Actor *p);
extern u32 CLACT_GetActorAnimFrame(struct Actor *p);
extern u32 func_0204B98C(struct Actor *a);
extern void *func_02012138(const struct GameSystem *gameSystem);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_0201283C(const void *gameData);
extern u32 func_0201058C(void *key);
extern int func_02158630(void *eventWork);
extern void PALANM_CopyToSlot(struct PalAnm *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02082BCC(void *, int, int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(unsigned int index);
extern unsigned int func_020221A4(void);
extern int func_0207D55C(volatile u16 *reg);
extern void *func_0201210C(const struct GameSystem *p);
extern int func_02189A48(void *gameData);
extern char *PALANM_GetDefaultWork(struct PalAnm *palAnm, int bank);
extern char *func_02021730(struct PalAnm *palAnm, int bank);
extern void func_02021F64(u16 *src, u16 *dst, int count, int weight, u16 color);
extern void func_02082D44(void *src, void *dst, int n);
extern int PALANM_RequestFade(struct PalAnm *palAnm, u16 mask, u16 color, s16 step, u8 startLevel, u8 endLevel, u16 tint, struct FadeCtx *fadeCtx);
extern void PALANM_ForceStopFade(struct PalAnm *o);
extern u32 PALANM_GetFadeRequestBits(const struct PalAnm *palAnm);
extern u32 func_0204162C(int channel);
extern void func_020091AC(struct HexMap *obj, int row, int col, int kind, int marked, int flagged);
extern void *func_02049F78(void *archive, u32 member, CGearFileInfo **outFile, u32 heapId);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void GFL_NET_RestartWithTimeout(u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_0207D63C(u32, int, int, int, int);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointCont(int *outX, int *outY);
extern void func_020061E4(u32 id);
extern int func_021F2DA8(CGearWork *work);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020090E8(struct HexMap *obj, u8 value);
extern void CLACT_SetActorAnimIndex(struct Actor *actor, int index);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_02043598(u32 mask, u32 enable);
extern int OS_IsRunOnTwl(void);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Actor *p);
extern u32 GAME_BEACON_GetReceiveCount(void);
extern int GAME_BEACON_GetNextNewLogIndex(int *p);
extern void *GAME_BEACON_GetLogByReceiveNo(int n);
extern u8 func_02165CD8(struct BeaconLog *p);
extern struct PlayerSettings *func_02012944(void *gameData);
extern unsigned char func_02008550(const struct PlayerSettings *obj);
extern unsigned char func_020090F0(const struct HexMap *obj);
extern struct ActorSystem *func_0204B100(int count, unsigned char flag, u32 heapId);
extern struct ActorResources *func_0204B034(const char *name, u32 flag, u32 heapId);
extern void func_0204B258(struct ActorSystem *system, struct ActorResources *resources);
extern struct ButtonTask *func_02051B84(const char *name, void (*callback)(int, int, CGearWork *), CGearWork *work, u32 heapId);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02051C6C(struct ButtonTask *task);
extern void func_0204B084(struct ActorResources *resources);
extern u32 func_0204B1CC(struct ActorSystem *bank);
extern void func_020403F4(u32 i);
extern int UI_GetPowerState(void);
extern void func_0203F4CC(RtcTime *time);
extern void func_0204B404(struct Actor *actor, const CGearPos *delta, u32 which);
extern void CLACT_SetActorDrawPriority(struct Actor *node, u32 val);
extern s32 func_02051C88(struct ButtonTask *task);
extern void func_021F2D50(CGearWork *work);
extern void func_021F2DC8(CGearWork *work);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern struct SaveCtrl *func_02012EBC(void *gameData);
extern u32 func_020072CC(struct SaveCtrl *sv, u32 id, u8 heap, void *buf, u32 size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern struct HexMap *func_02009210(void *saveSys);
extern u16 func_0200910C(const struct HexMap *obj);
extern u32 func_0200C6F0(const u8 *bgData);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_0200734C(struct SaveCtrl *sv, u32 id);
extern void func_02030D28(struct FadeCtx *ctx);
extern void PALANM_TransferPalettes(struct PalAnm *p);
extern u32 func_0201214C(const struct GameSystem *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02030CB0(u32 n);
extern struct FadeCtx *func_02030CBC(u32 capacity, void *mem);
extern u8 func_02009100(const struct HexMap *obj);
extern struct PalAnm *func_02021518(u32 heapId);
extern void PALANM_SetAutoTransfer(struct PalAnm *o, int v);
extern void func_0202155C(struct PalAnm *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnm *slots, u32 bank, u32 off, u32 size);
extern struct VBlankTask *func_020056A0(void (*callback)(void *, CGearWork *), CGearWork *work, int priority);
extern void func_02035010(void (*callback)(CGearWork *), CGearWork *work);
extern void func_02035040(void (*callback)(CGearWork *), CGearWork *work);
extern void func_021F2E10(CGearWork *work, CGearFadeFx *fx);
extern int func_020120D8(const struct GameSystem *gameSystem);
extern void func_021F3144(CGearWork *work, int powerOn);
extern void func_021F2D84(CGearWork *work);
extern int func_021585E0(void *eventWork);
extern void func_02158614(void *p);
extern void func_021F2E5C(CGearFadeFx *fx);
extern void GFL_NET_RestartNoTimeout(void);
extern void func_020215A0(struct PalAnm *slots, u32 idx);
extern u32 func_02021540(struct PalAnm *palAnm);
extern void func_02030DA4(struct FadeCtx *ctx);
extern void func_02030EAC(struct VBlankTask *task);
extern struct SoundSys *func_02012A30(const void *gameData);
extern void func_02028A70(struct SoundSys *sys);
extern void func_02049238(void *archive);
extern u32 func_020056EC(u32 range);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void func_0202223C(u32 a, u32 color);
extern void WIPE_ResetBrightness(u32 which);
extern void func_021F3098(CGearWork *work);
extern void func_021F3118(CGearWork *work);
extern struct GameEvent *func_021F2EEC(CGearWork *work, int kind);
void func_021F2CD4(CGearWork *work);
extern u32 func_02009110(const struct HexMap *obj, int row, int col);
extern int func_02009134(const struct HexMap *obj, int row, int col);
extern u32 func_02009160(const struct HexMap *obj, int row, int col, int kind);
int func_021EFEC0(int col, int row);
void func_021EFEE4(CGearWork *work, CGearStepFunc stepFunc);
void func_021EFEF8(CGearWork *work, CGearStepFunc stepFunc, int line);
void func_021EFF00(int col, int row, int *outCols, int *outRows);
void func_021EFF58(CGearWork *work, int col, int row);
CGearActorSlot *func_021F0000(CGearWork *work);
int func_021F0064(CGearWork *work, int col, int row);
int func_021F009C(CGearWork *work);
void func_021F0194(CGearWork *work);
int func_021F020C(const CGearWork *work, int touchX, int touchY, int *outCol, int *outRow);
void func_021F0298(CGearWork *work);
void func_021F0300(CGearWork *work);
void func_021F0370(CGearWork *work);
void func_021F0390(CGearWork *work, int tabKind, int slot, int resetPriorities, int modeEnabled);
int func_021F05B4(CGearWork *work);
void func_021F05D0(CGearWork *work);
void func_021F06B8(CGearWork *work, int mode, int variant);
void func_021F0728(CGearWork *work);
void func_021F07AC(CGearWork *work, int slot, CGearTabTimer *timer);
void func_021F07EC(CGearWork *work, int slot, CGearTabTimer *timer);
void func_021F0824(CGearWork *work, int slot, CGearTabTimer *timer);
void func_021F0858(CGearWork *work, int slot, CGearTabTimer *timer);
void func_021F088C(CGearWork *work, int slot, CGearTabTimer *timer);
void func_021F08BC(CGearWork *work, int slot, int step, int steps);
void func_021F09B4(CGearWork *work, const u8 *paletteFile, int bank);
int func_021F09DC(CGearWork *work, int slot, int paletteIndex, int kind, int wantedKind, int wantedSlot);
void func_021F0A0C(CGearWork *work);
void func_021F0A38(CGearWork *work);
int func_021F0A68(CGearWork *work);
void func_021F0AA0(CGearWork *work);
void func_021F0AC8(CGearTile *tile, int col, int row);
void func_021F0AE0(CGearTile *tile, CGearWork *work, int surfaceVariant);
void func_021F0B00(CGearTile *tile, CGearWork *work, int palRow, int mode, int variant, u16 stepPeriod);
void func_021F0B7C(CGearTile *tile);
void func_021F0B88(CGearTile *tile, CGearWork *work);
void func_021F0C00(CGearTile *tile, int step);
int func_021F0C68(CGearTile *tile);
int func_021F0C70(CGearWork *work, int palRow, int col, int row);
void func_021F0CA0(CGearTabTimer *timer, u16 limit, u8 stagger, u8 resetOnFire);
void func_021F0CB8(CGearTabTimer *timer);
int func_021F0CDC(CGearTabTimer *timer, int slot);
void func_021F0CF0(CGearTabTimer *timer, int slot);
void func_021F0D00(CGearTabTimer *timer, int slot);
u16 func_021F0D08(CGearTabTimer *timer, int slot);
void func_021F0D10(CGearTabTimer *timer, char running);
void func_021F0D14(int col, int row, int *outX, int *outY);
int func_021F0D48(CGearWork *work);
int func_021F0D80(CGearWork *work, int kind);
void func_021F0DB4(CGearWork *work, int commEnabled);
void func_021F0E70(CGearWork *work);
void func_021F0EB0(CGearWork *work, int faded);
void func_021F0F28(CGearWork *work, int faded);
void func_021F0F70(CGearWork *work);
void func_021F0FB0(CGearWork *work);
void func_021F0FF0(CGearWork *work);
int func_021F1000(CGearWork *work);
void func_021F1010(CGearWork *work);
int func_021F1060(CGearWork *work);
int func_021F11B4(CGearWork *work);
void func_021F122C(CGearWork *work);
void func_021F1290(CGearWork *work, int col, int row, int kind);
int func_021F133C(CGearWork *work, int kind, int *outX, int *outY);
void func_021F13FC(CGearWork *work);
u32 func_021F1458(CGearWork *work, int theme, int skin, int loadPalettes);
void func_021F1574(CGearWork *work, int theme);
void func_021F15FC(CGearWork *work, int customBgLoaded);
void func_021F1624(CGearWork *work);
void func_021F1740(CGearWork *work);
void func_021F1758(CGearWork *work, int key);
void func_021F18F0(int key, int buttonState, CGearWork *work);
void func_021F1910(CGearWork *work, int paintMode);
void func_021F1950(CGearWork *work);
void func_021F1A44(CGearWork *work, int visible);
void func_021F1A64(CGearWork *work, int visible);
void func_021F1B30(CGearWork *work, int visible);
void func_021F1B50(CGearWork *work);
void func_021F1BBC(CGearWork *work);
int func_021F1BE4(CGearWork *work);
void func_021F1C0C(CGearWork *work);
void func_021F1CD8(CGearWork *work);
void func_021F1DB0(CGearWork *work);
void func_021F1DE8(CGearWork *work, int introMode);
void func_021F1E98(CGearWork *work);
void func_021F1F24(CGearWork *work);
u8 func_021F1F70(void);
void func_021F1F80(CGearWork *work);
void func_021F20AC(CGearWork *work);
void func_021F2130(CGearWork *work);
void func_021F2180(CGearWork *work);
void func_021F21B4(CGearWork *work);
void func_021F21F8(CGearWork *work);
void func_021F2370(CGearWork *work);
int func_021F23CC(CGearWork *work, struct GameSystem *gameSystem);
void func_021F24C0(CGearWork *work);
void func_021F24FC(CGearWork *work);
void func_021F2508(void *task, CGearWork *work);
void func_021F251C(CGearWork *work, struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode);
void func_021F26E0(CGearWork *work);
CGearWork *func_021F279C(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode);
CGearWork *func_021F27D8(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, void (*callback)(int), int callbackArg, int introMode);
void func_021F2848(CGearWork *work, u8 powerOn);
void func_021F2980(void);
void func_021F2984(CGearWork *work);
int func_021F2994(CGearWork *work);
struct GameEvent *func_021F29D8(CGearWork *work, int enabled);
int func_021F2AB8(CGearWork *work);
void func_021F2AD4(CGearWork *work);
void func_021F2AEC(CGearWork *work, struct HexMap *hexMap, int col, int row, int kind);
u32 func_021F2B9C(const CGearWork *work, int col, int row);
int func_021F2BB8(const CGearWork *work, int col, int row);
int func_021F2BD4(const CGearWork *work, int col, int row, int kind);
extern CGearParityPair d_021F333C;
extern CGearParityPair d_021F334C;
extern u16 d_021F31BC[];
extern u8 d_021F31AB[];
extern u8 d_021F31B0[];
extern const u32 d_021F31EC[];
extern const int d_021F31F8[];
extern u8 d_021F3255[];
extern unsigned char d_021F3292[];
extern unsigned char d_021F3204[];
extern const u8 d_021F31A8[];
extern const u8 d_021F323C[];
extern const unsigned char d_021F32B3[][9];
extern const CGearParityPair d_021F3344;
extern u16 d_021F31B6[];
extern const CGearParityPair d_021F3324;
extern const CGearParityPair d_021F331C;
extern const CGearFlashStep d_021F3410[];
extern const u16 d_021F31D4[];
extern const CGearFlashStep d_021F348C[];
extern const CGearParityPair d_021F3334;
extern const CGearTileBases d_021F3354;
extern const int d_021F332C[2];
extern const int d_021F31E0[];
extern const int d_021F32E0[][3];
extern const int d_021F31C8[];
extern const int d_021F33CC[];
extern struct BgTemplate d_021F338C;
extern struct BgTemplate d_021F33AC;
extern struct BgTemplate d_021F336C;
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];
extern char d_021F3214[];
extern char d_021F3272[];
extern const u8 d_021F3520[];
extern const char d_021F3554[];
typedef struct GameEvent *(*GameEventCreatorFn)(struct GameSystem *gameSystem, void *arg);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, void *handler, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameEvent *func_020124AC(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg);
extern struct GameEvent *EVENT_GSYNC_Entry(struct GameSystem *gameSystem, void *arg);
extern struct GameEvent *func_021559E4(struct GameSystem *gameSystem, void *fieldMap, int a, int b);
extern struct GameEvent *func_0215FBF4(struct GameSystem *gameSystem, void *fieldMap, int a, int b);
extern struct GameEvent *func_02167044(struct GameSystem *gameSystem, void *fieldMap);
extern struct GameEvent *func_021945A4(struct GameSystem *gameSystem, void *fieldMap, u32 a);
extern struct GameEvent *func_02014808(struct GameSystem *gameSystem, void *fieldMap, u32 overlayId, const void *procData, void *procWork, void (*callback)(void *), void *callbackWork);
extern struct GameEvent *func_021D297C(struct GameSystem *gameSystem);
extern void func_0201235C(struct GameEvent *now, struct GameEvent *next);
extern int func_0203CD98(void);
int func_021F2C10(CGearWork *work);
int func_021F2C78(CGearWork *work);
void func_021F2CD8(CGearWork *work);
void func_021F2CF4(CGearWork *work);
void func_021F2D10(CGearWork *work);
void func_021F2D30(CGearWork *work);
void func_021F2E68(CGearFadeFx *fx, int palette);
int func_021F2E8C(CGearFadeFx *fx);
struct GameEvent *func_021F2EEC(CGearWork *work, int kind);
int func_021F2F60(struct GameEvent *event, int *seq, CGearEventWork *req);
void func_021F30C8(CGearWork *work);
int func_021F30EC(CGearWork *work);
extern const unsigned int d_021F3224[];
/* Overlay ids are absolute link-time symbols (pool words), so no literal. */
extern u8 abs_id_0[];
extern u8 abs_id_124[];
extern const u8 d_021D4D40[];
struct ArcFile;
struct HexMap;
void func_021F3190(struct HexMap *hexMap, struct ArcFile *arc, int skinIndex, int heapId);
int CTRDG_IsAgbCartridge(CGearWork *work);
extern int CTRDGi_IsAgbCartridgeAtInit(void);
extern void *func_020091FC(void *cgearSave);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);










int func_021EFEC0(int col, int row)
{
    if (col % 2 == 0) {
        if (row < 3)
            return 1;
    } else {
        if (row < 4)
            return 1;
    }
    return 0;
}






void func_021EFEE4(CGearWork *work, CGearStepFunc stepFunc)
{
    work->stepFunc = stepFunc;
    work->phaseTimer = 0;
    work->phase = 0;
}







/*
 * evidence: func_021EFEE4 is ov029's own code (a store leaf ending in bx lr
 * after the bx lr at 0x021EFEE0), inside ov029's window, so only ov029 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov029's own listing.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021EFEF8(CGearWork *work, CGearStepFunc stepFunc, int line)
{
    func_021EFEE4(work, stepFunc);
}






void func_021EFF00(int col, int row, int *outCols, int *outRows)
{
    int parity = col % 2;

    if (parity == 0) {
        outCols[0] = col;
        outRows[0] = row - 1;
        outCols[1] = col;
        outRows[1] = row + 1;
        outCols[2] = col + 1;
        outRows[2] = row;
        outCols[3] = col + 1;
        outRows[3] = row - 1;
        outCols[4] = col - 1;
        outRows[4] = row;
        outCols[5] = col - 1;
        outRows[5] = row - 1;
    } else {
        outCols[0] = col;
        outRows[0] = row - 1;
        outCols[1] = col;
        outRows[1] = row + 1;
        outCols[2] = col + 1;
        outRows[2] = row;
        outCols[3] = col + 1;
        outRows[3] = row + 1;
        outCols[4] = col - 1;
        outRows[4] = row;
        outCols[5] = col - 1;
        outRows[5] = row + 1;
    }
}







void func_021EFF58(CGearWork *work, int col, int row)
{
    CGearActorDesc desc;
    int screenX;
    int screenY;
    CGearActorSlot *slot;

    func_021F0D14(col, row, &screenX, &screenY);
    desc.x = screenX * 8 + 16;
    desc.y = screenY * 8 + 16;
    desc.animIndex = work->rippleKind + 10;
    desc.palOffset = 0;
    desc.surface = 2;
    slot = func_021F0000(work);
    if (slot->actor != 0) {
        func_0204B878(slot->actor, desc.animIndex);
        func_0204B9A0(slot->actor);
        CLACT_SetActorSurfacePosAxis(slot->actor, desc.x, 0, 0);
        CLACT_SetActorSurfacePosAxis(slot->actor, desc.y, 0, 1);
    } else {
        slot->actor = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes, work->spriteAnimRes, &desc, 0, work->heapId);
        func_0204B92C(slot->actor, 1);
        func_0204B3DC(slot->actor, 1);
    }
    slot->col = col;
    slot->row = row;
}







CGearActorSlot *func_021F0000(CGearWork *work)
{
    int bestSeq = -1;
    int bestFrame = -1;
    int bestIdx = 0;
    int i;
    int animSeq;
    int animFrame;

    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor == 0) {
            return &work->actorSlots[i];
        }
        animSeq = CLACT_GetActorAnimSeqCount(work->actorSlots[i].actor);
        animFrame = CLACT_GetActorAnimFrame(work->actorSlots[i].actor);
        if (animSeq > bestSeq || (animSeq == bestSeq && animFrame > bestFrame)) {
            bestSeq = animSeq;
            bestFrame = animFrame;
            bestIdx = i;
        }
    }
    return &work->actorSlots[bestIdx];
}






int func_021F0064(CGearWork *work, int col, int row)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0 && work->actorSlots[i].col == col && work->actorSlots[i].row == row) {
            if (func_0204B98C(work->actorSlots[i].actor) != 0) return 0;
        }
    }
    return 1;
}







int func_021F009C(CGearWork *work)
{
    int y;
    int x;
    int k;
    int neighborCols[6];
    int neighborRows[6];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            if (work->grid[x][y] == 4 && func_021F0064(work, x, y) != 0) {
                work->grid[x][y] = 5;
            }
            if (work->grid[x][y] == 2) {
                func_021EFF58(work, x, y);
                work->grid[x][y] = 3;
            }
        }
    }
    work->rippleStep++;
    if (work->rippleStep >= 16) {
        return 1;
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            if (work->grid[x][y] == 3) {
                work->grid[x][y] = 4;
                func_021EFF00(x, y, neighborCols, neighborRows);
                for (k = 0; k < 6; k++) {
                    if (neighborCols[k] >= 0 && neighborCols[k] < 9 && neighborRows[k] >= 0 && neighborRows[k] < 4) {
                        if (work->grid[neighborCols[k]][neighborRows[k]] == 1) {
                            work->grid[neighborCols[k]][neighborRows[k]] = 2;
                        } else if (work->grid[neighborCols[k]][neighborRows[k]] == 0) {
                            work->grid[neighborCols[k]][neighborRows[k]] = 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}







void func_021F0194(CGearWork *work)
{
    int kind;
    int j;
    int i;

    kind = func_021F2B9C(work, work->selectedCol, work->selectedRow);
    work->rippleKind = kind;
    i = 0;
    work->rippleStep = i;
    for (; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (kind == func_021F2B9C(work, j, i)) {
                work->grid[j][i] = 1;
            }
        }
    }
    work->grid[work->selectedCol][work->selectedRow] = 2;
    func_021F009C(work);
}







/*
 * note 2026-10-05 (wD6 lane14): closed by reusing parameter a for x (the early
 * `adds r4,r1,#0` copy), b for the b/8 - lo[m] intermediate, and two 8-byte
 * struct copies of the tables (ldm r5,{r3,r5}).
 */
int func_021F020C(const CGearWork *work, int touchX, int touchY, int *outCol, int *outRow)
{
    int row;
    CGearParityPair rowOffset;
    CGearParityPair rowCount;
    int kind = 5;
    int parity;

    rowOffset = d_021F333C;
    rowCount = d_021F334C;
    touchX = (touchX / 8 + 2) / 4;
    if (touchX < 0) {
        return 5;
    }
    parity = touchX % 2;
    touchY = touchY / 8 - rowOffset.value[parity];
    if (touchY < 0) {
        return 5;
    }
    row = touchY / 4;
    if (touchX < 9 && row < rowCount.value[parity]) {
        kind = func_021F2B9C(work, touchX, row);
    }
    *outCol = touchX;
    *outRow = row;
    return kind;
}







void func_021F0298(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&timers[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i == 0) {
            func_021F0D10(&timers[i], 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(work, i, j, 0, 0);
        }
    }
}







void func_021F0300(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&timers[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i != 0) {
            func_021F0D10(&timers[i], 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(work, i, j, 1, work->tabMode);
        }
    }
}






void func_021F0370(CGearWork *work)
{
    int i;
    for (i = 0; i < 3; i++) func_021F08BC(work, i, 0, 31);
}







/*
 * `const` on the two key/row tables schedules the second table's pool load
 * above the `[sp]` stack-argument store in the cycle loop (14 bytes out
 * without it). The four-way reset is `s18 = s8 = sc = s14 = 0`: the chain
 * stores right to left.
 */
void func_021F0390(CGearWork *work, int tabKind, int slot, int resetPriorities, int modeEnabled)
{
    void *eventWork;
    int keyGroups;
    int keysHeld;
    int linkMode;
    int kind4;
    int kind3;
    int i;
    int kind2;
    int kind1;
    u32 padKeys;
    int cycleIdx;

    eventWork = func_02012138(work->gameSystem);
    keyGroups = 0;
    keysHeld = 1;
    kind1 = 1;
    kind4 = 4;
    kind3 = 3;
    kind2 = 2;
    if (resetPriorities != 0) {
        kind4 = kind1 = kind2 = kind3 = 0;
    }
    padKeys = func_0201058C(func_0201283C(func_020120F4(work->gameSystem)));
    linkMode = func_02158630(eventWork);
    if (modeEnabled != 0) {
        if (linkMode == 3) {
            func_021F09DC(work, 2, 3, kind3, tabKind, slot);
        } else if (padKeys & 8) {
            keyGroups |= 4;
            func_021F09DC(work, 2, 2, kind3, tabKind, slot);
        }
    }
    if (keyGroups == 0) {
        keysHeld = 0;
        if (padKeys & 2) {
            keyGroups |= 2;
        }
        if (padKeys & 0x3c) {
            keyGroups |= 4;
        }
        if (padKeys & 0x3c0) {
            keyGroups |= 8;
        }
        if (padKeys & 0x40) {
            func_021F09DC(work, 1, 3, kind2, tabKind, slot);
        } else if (padKeys & 0x100) {
            func_021F09DC(work, 1, 0, kind2, tabKind, slot);
        } else if (padKeys & 0x80) {
            func_021F09DC(work, 1, 1, kind2, tabKind, slot);
        } else if (padKeys & 0x200) {
            func_021F09DC(work, 1, 0, kind2, tabKind, slot);
        }
        if (linkMode != 0) {
            if (linkMode != 3) {
                func_021F09DC(work, 2, 3, kind2, tabKind, slot);
            }
        } else {
            for (i = 0; i < 3; i++) {
                work->keyCycle = (work->keyCycle + 1) % 3;
                cycleIdx = work->keyCycle;
                if ((d_021F31EC[cycleIdx] & padKeys) || (cycleIdx == 2 && work->beaconPending != 0)) {
                    if (func_021F09DC(work, 2, d_021F31F8[cycleIdx], kind2, tabKind, slot) != 0) {
                        if (work->keyCycle == 2) {
                            work->beaconPending = 0;
                        }
                        break;
                    }
                }
            }
            if (i == 3) {
                func_021F09DC(work, 2, 8, kind1, tabKind, slot);
            }
        }
    }
    if (keysHeld == 0) {
        func_021F09DC(work, 0, 6, kind1, tabKind, slot);
        if (!(keyGroups & 8)) {
            func_021F09DC(work, 1, 7, kind1, tabKind, slot);
        }
        if (!(keyGroups & 4)) {
            func_021F09DC(work, 2, 8, kind1, tabKind, slot);
        }
    } else {
        func_021F09DC(work, 0, 5, kind4, tabKind, slot);
        func_021F09DC(work, 1, 5, kind4, tabKind, slot);
    }
}






int func_021F05B4(CGearWork *work)
{
    if (work->tabVariant == 1 && work->tabMode == 1) return 1;
    return 0;
}







void func_021F05D0(CGearWork *work)
{
    CGearTabTimer *timers2;
    CGearTabTimer *timers;
    int i;
    int j;
    int flag;

    flag = 0;
    for (i = 0; i < 5; i++) {
        timers = work->tabTimers;
        func_021F0CB8(&timers[i]);
        for (j = 0; j < 3; j++) {
            if (func_021F0CDC(&timers[i], j) || work->refreshFlag) {
                func_021F0390(work, i, j, 0, work->tabMode);
                if (i == 0) {
                    flag = 1;
                }
                if (func_021F0CDC(&timers[i], j)) {
                    func_021F0CF0(&timers[i], j);
                }
            }
        }
    }
    if (flag) {
        timers2 = work->tabTimers;
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                func_021F0D10(&timers2[i], 1);
                for (j = 0; j < 3; j++) {
                    func_021F0390(work, i, j, 0, work->tabMode);
                }
            } else {
                func_021F0D10(&timers2[i], 0);
            }
        }
    }
    work->refreshFlag = 0;
}







void func_021F06B8(CGearWork *work, int mode, int variant)
{
    CGearTabTimer *timers;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        func_021F08BC(work, i, 0, 0x1f);
    }
    timers = work->tabTimers;
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            func_021F0D00(&timers[j], k);
        }
    }
    work->tabMode = mode;
    work->refreshFlag = 1;
    work->tabActive = 1;
    work->tabFrame = 0;
    work->tabVariant = variant;
}







void func_021F0728(CGearWork *work)
{
    CGearTabTimer *timers = work->tabTimers;
    int i;

    for (i = 0; i < 3; i++) {
        u8 kind = work->tabState[i];

        switch (kind) {
        case 3:
            func_021F07AC(work, i, &timers[kind]);
            break;
        case 1:
            func_021F07EC(work, i, &timers[kind]);
            break;
        case 2:
            func_021F0824(work, i, &timers[kind]);
            break;
        case 0:
            func_021F0858(work, i, &timers[kind]);
            break;
        case 4:
            func_021F088C(work, i, &timers[kind]);
            break;
        }
    }
}







void func_021F07AC(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = func_021F0D08(timer, slot);
    if (value > 0x24 || value < 4) return;
    value = (u16)(value - 4);
    value = (unsigned)(((int)value % 8) * 28) >> 3;
    value = d_021F3255[value];
    func_021F08BC(work, slot, value, 0x1f);
}






void func_021F07EC(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = func_021F0D08(timer, slot);
    if (value > 112 || value < 12) return;
    value = (unsigned)((unsigned short)(value - 12)) * 28 / 100;
    value = d_021F3255[value];
    func_021F08BC(work, slot, value, 31);
}






void func_021F0824(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = func_021F0D08(timer, slot);
    if (value > 78 || value < 8) return;
    value = (unsigned)((unsigned short)(value - 8)) * 32 / 70;
    value = d_021F3292[value];
    func_021F08BC(work, slot, value, 31);
}






void func_021F0858(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = func_021F0D08(timer, slot);
    if (value > 20) return;
    value = (unsigned)(((int)value % 10) * 28) / 10;
    value = d_021F3255[value];
    func_021F08BC(work, slot, value, 31);
}






void func_021F088C(CGearWork *work, int slot, CGearTabTimer *timer)
{
    unsigned int value = func_021F0D08(timer, slot);
    if (value > 15) return;
    value = (unsigned)(value * 12) / 15;
    value = d_021F3204[value];
    func_021F08BC(work, slot, value, 31);
}







void func_021F08BC(CGearWork *work, int slot, int step, int steps)
{
    int colorIdx;
    int channel;
    int base;
    int delta;

    for (colorIdx = 0; colorIdx < 5; colorIdx++) {
        work->blendPalette[slot][colorIdx] = 0;
        for (channel = 0; channel < 3; channel++) {
            base = (work->basePalette[slot][colorIdx] >> (channel * 5)) & 0x1f;
            delta = ((work->targetPalette[work->targetPalIndex[slot]][colorIdx] >> (channel * 5)) & 0x1f) - base;
            work->blendPalette[slot][colorIdx] |= ((base + delta * step / steps) & 0x1f) << (channel * 5);
        }
        PALANM_CopyToSlot(work->palAnm, &work->blendPalette[slot][colorIdx], 1, (u16)(d_021F31A8[slot] + (colorIdx + 1) * 16), 2);
    }
}






void func_021F09B4(CGearWork *work, const u8 *paletteFile, int bank)
{
    int i;
    for (i = 0; i < 5; i++) work->targetPalette[bank][i] = ((const u16 *)(paletteFile + bank * 32 + 0x16))[i];
}






int func_021F09DC(CGearWork *work, int slot, int paletteIndex, int kind, int wantedKind, int wantedSlot)
{
    if (kind == wantedKind && slot == wantedSlot) {
        work->targetPalIndex[slot] = paletteIndex;
        work->tabState[slot] = kind;
        return 1;
    }
    return 0;
}






void func_021F0A0C(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0AC8(&work->tiles[i][j], i, j);
    }
}






void func_021F0A38(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0B88(&work->tiles[i][j], work);
    }
}






int func_021F0A68(CGearWork *work)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (func_021F0C68(&work->tiles[i][j])) {
                result = 1;
                break;
            }
        }
    }
    return result;
}






void func_021F0AA0(CGearWork *work)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            func_021F0B7C(&work->tiles[i][j]);
        }
    }
}




void func_021F0AC8(CGearTile *tile, int col, int row)
{
    func_02082BCC(tile, 0, 8);
    tile->col = col;
    tile->row = row;
}



void func_021F0AE0(CGearTile *tile, CGearWork *work, int surfaceVariant)
{
    tile->palRow = 0;
    func_021F1290(work, tile->col, tile->row, surfaceVariant);
    func_021F0C00(tile, 0);
}



/*
 * note:     `t = 0` must come first: set after the stores, the third parameter stays in r2
 *           instead of moving to r1 at entry (27 bytes out).
 */
void func_021F0B00(CGearTile *tile, CGearWork *work, int palRow, int mode, int variant, u16 stepPeriod)
{
    int lastStep;

    lastStep = 0;
    tile->palRow = palRow;
    tile->tick = 0;
    tile->active = 1;
    tile->stepPeriod = stepPeriod;
    if (mode == 0) {
        tile->stopStep = 0;
    } else if (mode == 1) {
        tile->stopStep = 4;
    } else if (mode == 2) {
        tile->stopStep = func_021F0C70(work, palRow, tile->col, tile->row);
        tile->tick = stepPeriod * 5;
        lastStep = 4;
    }
    func_021F1290(work, tile->col, tile->row, variant);
    func_021F0C00(tile, lastStep);
}










void func_021F0B7C(CGearTile *tile)
{
    tile->active = 0;
}










void func_021F0B88(CGearTile *tile, CGearWork *work)
{
    unsigned int step;
    int redraw;

    if (tile->active) {
        tile->tick = tile->tick + 1;
        step = tile->tick / tile->stepPeriod;
        redraw = 0;
        if (step >= 5) {
            step = 4 - step % 5;
            if (step == tile->stopStep)
                tile->active = 0;
        }
        if (step < 5) {
            if (tile->tick % tile->stepPeriod == 0)
                redraw = 1;
        }
        if (redraw)
            func_021F0C00(tile, step);
    }
}










void func_021F0C00(CGearTile *tile, int step)
{
    int tileX, tileY, width;
    int palette;

    palette = (d_021F323C + tile->palRow * 5)[step];
    func_021F0D14(tile->col, tile->row, &tileX, &tileY);
    width = 4;
    if (tileX < 0) {
        width = tileX + 4;
        tileX = 0;
    } else if (tileX + 4 > 0x20) {
        width = 0x20 - tileX;
    }
    func_020413B0(4, tileX, tileY, width, 4, palette);
    func_020409B4(4);
}









int func_021F0C68(CGearTile *tile)
{
    return tile->active;
}









int func_021F0C70(CGearWork *work, int palRow, int col, int row)
{
    if (func_021F2BB8(work, col, row)) return d_021F32B3[palRow][4];
    return d_021F32B3[palRow][col];
}









/*
 * lever: enum zero and f2,f4,f0,f6 logical store order recover the
 * original scheduling; the previous f2,f0,f4,f6 order differed at two stores.
 */
void func_021F0CA0(CGearTabTimer *timer, u16 limit, u8 stagger, u8 resetOnFire)
{
    ZeroValue zero;
    zero = Zero;
    timer->count[1] = stagger;
    timer->count[2] = zero;
    timer->count[0] = stagger * 2;
    timer->limit = limit;
    timer->resetOnFire = resetOnFire;
    timer->running = 1;
}









void func_021F0CB8(CGearTabTimer *timer)
{
    int i;
    if (timer->running) {
        for (i = 0; i < 3; i++) {
            if (timer->count[i] < timer->limit)
                timer->count[i]++;
        }
    }
}









int func_021F0CDC(CGearTabTimer *timer, int slot)
{
    if (timer->count[slot] >= timer->limit) return 1;
    return 0;
}









void func_021F0CF0(CGearTabTimer *timer, int slot)
{
    if (timer->resetOnFire != 0) timer->count[slot] = 0;
}









void func_021F0D00(CGearTabTimer *timer, int slot)
{
    timer->count[slot] = 0;
}










u16 func_021F0D08(CGearTabTimer *timer, int slot)
{
    return timer->count[slot];
}










void func_021F0D10(CGearTabTimer *timer, char running)
{
    timer->running = running;
}










void func_021F0D14(int col, int row, int *outX, int *outY)
{
    CGearParityPair rowShift = d_021F3344;
    *outX = col * 4 - 2;
    *outY = rowShift.value[col % 2] + row * 4;
}









/*
 * 2026-10-04 (wD2 lane 09): bytes are identical; only the relocation at +0024 is open.
 * Filed the callee as matched ov021_func_02189A48.c (EXACT, returns *(u32 *)(p+0x144)).
 * The tool still reports no independent witness for 02189A48 (3 overlays overlap).
 * Needs the integrator to regenerate the witness index, nothing left in the source.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 */
int func_021F0D48(CGearWork *work)
{
    if (!func_020221A4()) return 0;
    if (func_0207D55C(&REG_DB_MASTER_BRIGHT)) return 0;
    if (!func_02189A48(func_0201210C(work->gameSystem))) return 1;
    return 0;
}









int func_021F0D80(CGearWork *work, int kind)
{
    int j, i, count;
    if (kind == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (kind == func_021F2B9C(work, j, i)) count++;
        }
    }
    return count;
}










void func_021F0DB4(CGearWork *work, int commEnabled)
{
    char *srcPal, *dstPal;
    int i;

    if (commEnabled == 0) {
        srcPal = PALANM_GetDefaultWork(work->palAnm, 3);
        dstPal = func_02021730(work->palAnm, 3);
        for (i = 0; i < 14; i++) {
            if (0xFBEE & (1 << i)) {
                func_02021F64((u16 *)(srcPal + i * 0x20), (u16 *)(srcPal + i * 0x20), 0x10, 8,
                              d_021F31B6[work->colorTheme]);
                func_02082D44(srcPal + i * 0x20, dstPal + i * 0x20, 0x20);
            }
        }
        srcPal = PALANM_GetDefaultWork(work->palAnm, 1);
        dstPal = func_02021730(work->palAnm, 1);
        for (i = 0; i < 14; i++) {
            if (0x3E & (1 << i)) {
                func_02021F64((u16 *)(srcPal + i * 0x20), (u16 *)(srcPal + i * 0x20), 0x10, 8,
                              d_021F31B6[work->colorTheme]);
                func_02082D44(srcPal + i * 0x20, dstPal + i * 0x20, 0x20);
            }
        }
    }
}










void func_021F0E70(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, -120, 0, 0x10,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void func_021F0EB0(CGearWork *work, int faded)
{
    int endLevel = 8;
    if (faded == 0)
        endLevel = 0;
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
    PALANM_RequestFade(work->palAnm, 2, 0x3E, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void func_021F0F28(CGearWork *work, int faded)
{
    int endLevel = 8;
    if (faded == 0)
        endLevel = 0;
    PALANM_RequestFade(work->palAnm, 8, 0x3C0, -120, 0, endLevel,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void func_021F0F70(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, 1, 0, 0x10,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}










void func_021F0FB0(CGearWork *work)
{
    PALANM_RequestFade(work->palAnm, 8, 0xFFFF, 1, 0x10, 0,
                  d_021F31B6[work->colorTheme], work->fadeCtx);
}









/*
 * extent: followed by existing ov029_func_021F1000.c.
 */
void func_021F0FF0(CGearWork *work)
{
    PALANM_ForceStopFade(work->palAnm);
}










int func_021F1000(CGearWork *work)
{
    return PALANM_GetFadeRequestBits(work->palAnm);
}









void func_021F1010(CGearWork *work)
{
    CGearParityPair columnRows = d_021F3324;
    int i, j, rows;

    for (i = 0; i < 9; i++) {
        rows = columnRows.value[i % 2];
        for (j = 0; j < rows; j++)
            func_021F1290(work, i, j, 0);
    }
    func_020409B4(4);
}









int func_021F1060(CGearWork *work)
{
    CGearParityPair columnRows = d_021F331C;
    int i, j, rows;
    unsigned int stepIdx;
    const CGearFlashStep *step;
    int kind;
    int tileRow;
    int tileCol;

    switch (work->phase) {
    case 0:
        for (i = 0; i < 9; i++) {
            rows = columnRows.value[i % 2];
            for (j = 0; j < rows; j++)
                func_021F0B00(&work->tiles[i][j], work, 4, 1, 4, 2);
        }
        work->phase++;
        break;
    case 1:
        if (func_021F0A68(work) == 0)
            work->phase++;
        break;
    case 2:
        for (stepIdx = 0; stepIdx < 0x1F; stepIdx++) {
            step = &d_021F3410[stepIdx];
            if (work->phaseTimer == d_021F3410[stepIdx].startTick) {
                tileRow = step->row;
                tileCol = step->col;
                kind = func_021F2B9C(work, tileCol, tileRow);
                func_021F0B00(&work->tiles[tileCol][tileRow], work, (u8)d_021F31D4[kind], 2, kind, step->stepPeriod);
            }
        }
        if (work->phaseTimer >= 4) {
            func_021F0FB0(work);
            func_021F1A44(work, 1);
            work->phase++;
        }
        work->phaseTimer++;
        break;
    case 3:
        if (func_021F0A68(work) == 0 && func_021F1000(work) == 0)
            return 1;
        break;
    }
    func_021F0A38(work);
    return 0;
}









/*
 * The byte phaseTimer must be spelled out at each use (no cached pointer
 * local): a local pointer makes the increment reload the pool constant.
 */
int func_021F11B4(CGearWork *work)
{
    unsigned int i;

    if (work->phaseTimer <= 0x7E) {
        for (i = 0; i < 0x24; i++) {
            if (work->phaseTimer == d_021F348C[i].startTick)
                func_021F0B00(&work->tiles[d_021F348C[i].col][d_021F348C[i].row],
                              work, 4, 0, 4, d_021F348C[i].stepPeriod);
        }
        work->phaseTimer = work->phaseTimer + 1;
    } else {
        if (func_021F0A68(work) == 0)
            return 1;
    }
    func_021F0A38(work);
    return 0;
}









void func_021F122C(CGearWork *work)
{
    CGearParityPair columnRows = d_021F3334;
    int i, j, rows;

    i = 0;
    for (; i < 9; i++) {
        rows = columnRows.value[i % 2];
        for (j = 0; j < rows; j++)
            func_021F0AE0(&work->tiles[i][j], work, 4);
    }
}









/*
 * note 2026-10-05 (wD7 lane15): closed. The table entry is a named block local (w = t.w[c]) in the
 *   store block. mwcc puts a named local first in `w + o` (adds r0,r0,r4); the plain t.w[c] load
 *   is a temp and goes second, which was the last 2-byte residue.
 */
void func_021F1290(CGearWork *work, int col, int row, int kind)
{
    CGearTileBases tileBases = d_021F3354;
    int mapCol, mapRow, mapRowIdx, palRow, palette, i, mapColIdx, j;
    u16 *tilemap;

    tilemap = (u16 *)func_0204162C(4);
    func_021F0D14(col, row, &mapCol, &mapRow);
    palRow = d_021F31D4[kind];
    palette = func_021F0C70(work, palRow, col, row);
    mapRowIdx = mapRow;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *mapLine = tilemap + mapRowIdx * 32;
        mapColIdx = mapCol;
        for (j = 0; j < 4; j++) {
            if (mapColIdx >= 0 && mapColIdx < 0x20) {
                int w = tileBases.base[kind];
                mapLine[mapColIdx] = (w + o + j) | ((d_021F323C + palRow * 5)[palette] << 12);
            }
            mapColIdx++;
        }
        mapRowIdx++;
    }
}









int func_021F133C(CGearWork *work, int kind, int *outX, int *outY)
{
    int firstCol = 0;
    int firstRow = 0;
    int found = 0;
    int col;
    int row;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 9; col++) {
            if (kind == func_021F2B9C(work, col, row)) {
                if (found == 0) {
                    firstCol = col;
                    firstRow = row;
                    found = 1;
                }
                if (func_021F2BB8(work, col, row)) {
                    func_021F0D14(col, row, outX, outY);
                    return 1;
                }
                if (func_021F2BD4(work, col, row, kind)) {
                    firstCol = col;
                    firstRow = row;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        func_021F0D14(firstCol, firstRow, outX, outY);
        func_020091AC(work->hexMap, firstCol, firstRow, kind, 1, 0);
        func_021F1290(work, firstCol, firstRow, kind);
        func_020409B4(4);
        return 1;
    }
    return 0;
}









void func_021F13FC(CGearWork *work)
{
    int columnRows[2];
    int i;
    int j;
    int rows;

    columnRows[0] = d_021F332C[0];
    columnRows[1] = d_021F332C[1];
    for (i = 0; i < 9; i++) {
        rows = columnRows[i % 2];
        for (j = 0; j < rows; j++)
            func_021F1290(work, i, j, func_021F2B9C(work, i, j));
    }
    func_020409B4(4);
}









/*
 * The basePalette table must be a struct member (u16 [3][5]); a raw cast keeps
 * the table address in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 */
u32 func_021F1458(CGearWork *work, int theme, int skin, int loadPalettes)
{
    int colorIdx;
    void *handle;
    CGearFileInfo *file;
    u8 *fileData;
    int slot;
    int k;
    u32 charSize;
    u32 charBase;

    if (loadPalettes) {
        handle = func_02049F78(work->archive, d_021F31E0[theme], &file, 0x8070);
        func_020862F0(file->data, file->size);
        func_0207E468(file->data, 0, file->size);
        fileData = file->data;
        for (colorIdx = 0; colorIdx < 5; colorIdx++) {
            for (slot = 0; slot < 3; slot++) {
                work->basePalette[slot][colorIdx] = ((u16 *)(fileData + (colorIdx + 1) * 0x20))[d_021F31A8[slot]];
            }
        }
        func_020307B0(handle);
        handle = func_02049F78(work->archive, 0x17, &file, 0x8070);
        for (k = 0; k < 9; k++) {
            func_021F09B4(work, file->data, k);
        }
        func_020307B0(handle);
    }
    charSize = 0x5000;
    charBase = func_0203FA08(6, charSize, 0);
    work->bgCharBlock = (u16)charBase | (charSize << 16);
    func_02049658(work->archive, d_021F32E0[skin][theme], 6, charBase, 0, 0, 0x70);
    return func_02049990(work->archive, 2, 6, 0, (u16)work->bgCharBlock, 0, 0, 0x70);
}









/*
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and the destination pointer stepped by 4.
 */
void func_021F1574(CGearWork *work, int theme)
{
    int i;
    void *handle;
    CGearFileInfo *file;
    int *base;

    i = 0;
    work->spritePlttRes = func_0204ABF0(work->archive, d_021F31C8[theme], 1, 0, 0x70);
    work->spriteCharRes = func_0204A6C8(work->archive, 0x16, 0, 1, 0x70);
    work->spriteAnimRes = func_0204AF28(work->archive, 0x15, 0x14, work->heapId);
    handle = func_02049F78(work->archive, 0x18, &file, work->heapId);
    base = (int *)file->data;
    for (; i < 17; i++) {
        work->beaconColors[i] = base[d_021F33CC[i]];
    }
    func_020307B0(handle);
    GFL_NET_RestartWithTimeout(0xda, 0xe);
    func_0203D34C(0, work->heapId);
}








void func_021F15FC(CGearWork *work, int customBgLoaded)
{
    if (customBgLoaded == 0)
        func_02049990(work->archive, 1, 5, 0, (u16)work->bgCharBlock, 0, 0, 0x70);
}









/*
 * volatile: 0x021F1722 ldr / 0x021F1726 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write, hardware register)
 *
 * Twin of ov030 func_021EFF54 (same three BgTemplate blocks), plus the
 * func_021F1740 call and the sub-screen window-mask clear. d_021F33AC's
 * ov029 hint is contested by another overlay, so its line carries only a4.
 */
void func_021F1624(CGearWork *work)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588(i, 0);
    }
    {
        struct BgTemplate t = d_021F338C;
        func_0203FCA0(6, &t, 0);
        func_02040588(6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F33AC;
        func_0203FCA0(5, &t, 0);
        func_02040588(5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F336C;
        func_0203FCA0(4, &t, 0);
        func_02040588(4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
    func_021F1740(work);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}








void func_021F1740(CGearWork *work)
{
    func_0207D63C(0x04001050, 2, 0x15, 9, 0x10);
}









/*
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * func_021EFEC0 is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 */
void func_021F1758(CGearWork *work, int key)
{
    int touchCol;
    int touchRow;
    int touchX;
    int touchY;
    int kind;
    u32 bgChar;

    if (work->commEnabled == 0 && key != 6 && key != 0)
        return;
    if (work->command != 0)
        return;
    func_020355D8(1);
    switch (key) {
    case 0:
        TOUCHPANEL_GetPointCont(&touchX, &touchY);
        kind = func_021F020C(work, touchX, touchY, &touchCol, &touchRow);
        if (work->paintMode != 0) {
            work->touchX = touchX;
            work->touchY = touchY;
            if ((func_021F0D80(work, kind) > 1 || kind == 4) && func_021EFEC0(touchCol, touchRow) != 0) {
                func_021F2AEC(work, work->hexMap, touchCol, touchRow, (kind + 1) % 5);
                func_020409B4(4);
                func_020061E4(0x628);
            }
        } else if (func_021F2DA8(work) == 0) {
            work->selectedCol = touchCol;
            work->selectedRow = touchRow;
            switch (kind) {
            case 1:
                work->command = 1;
                break;
            case 3:
                work->command = 6;
                break;
            case 2:
                work->command = 5;
                break;
            }
        }
        break;
    case 1:
        func_020061E4(0x628);
        work->paintMode ^= 1;
        func_021F1910(work, work->paintMode);
        break;
    case 2:
        work->command = 0xC;
        break;
    case 3:
        work->command = 7;
        break;
    case 4:
        work->command = 0xB;
        break;
    case 5:
        func_020061E4(0x628);
        bgChar = work->bgCharBlock;
        func_0203FB44(6, (u16)bgChar, (u16)(bgChar >> 16));
        work->skinIndex++;
        work->skinIndex = work->skinIndex % 5;
        func_020090E8(work->hexMap, work->skinIndex);
        func_021F1458(work, work->colorTheme, work->skinIndex, 0);
        func_021F13FC(work);
        func_021F1A44(work, 1);
        break;
    case 6:
        work->command = 0xD;
        break;
    }
}








void func_021F18F0(int key, int buttonState, CGearWork *work)
{
    if (func_021F2DA8(work) == 0 && buttonState == 0)
        func_021F1758(work, key);
}









void func_021F1910(CGearWork *work, int paintMode)
{
    if (paintMode) {
        CLACT_SetActorAnimIndex(work->hudActors[9], 0);
        func_0204B954(work->hudActors[9], 0x2000);
        func_0204B92C(work->hudActors[9], 1);
    } else {
        func_0204B92C(work->hudActors[9], 0);
        CLACT_SetActorAnimIndex(work->hudActors[9], 1);
    }
}









void func_021F1950(CGearWork *work)
{
    int i;
    int j;
    CGearActorDesc desc;

    func_02043598(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        desc.x = d_021F3531[i];
        desc.y = d_021F353C[i];
        desc.animIndex = d_021F3526[i];
        if (desc.animIndex == 6 && OS_IsRunOnTwl()) {
            desc.animIndex = 7;
        }
        desc.palOffset = 0;
        desc.surface = 2;
        work->hudActors[i] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        func_0204B3DC(work->hudActors[i], 0);
        func_0204BA20(work->hudActors[i], 0);
    }
    func_021F1910(work, 0);
    for (j = 0; j < 3; j++) {
        desc.x = 8;
        desc.y = 8;
        desc.animIndex = d_021F3548[j];
        desc.palOffset = 0;
        desc.surface = 2;
        work->tileMarkerActors[j] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        func_0204B3DC(work->tileMarkerActors[j], 0);
        func_0204BA20(work->tileMarkerActors[j], 0);
    }
    func_021F1F80(work);
    func_021F20AC(work);
}








void func_021F1A44(CGearWork *work, int visible)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B3DC(work->tileMarkerActors[i], visible);
}









void func_021F1A64(CGearWork *work, int visible)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0) {
            func_0204B3DC(work->actorSlots[i].actor, visible);
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->tileMarkerActors[i] != 0 && work->commEnabled != 0) {
            func_0204B3DC(work->tileMarkerActors[i], visible);
        }
    }
    for (i = 0; i < 11; i++) {
        if (work->hudActors[i] != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (work->commEnabled != 0) {
                    func_0204B3DC(work->hudActors[i], visible);
                }
            } else {
                func_0204B3DC(work->hudActors[i], visible);
            }
        }
    }
    if (work->barActors[0] != 0 && work->commEnabled != 0) {
        func_0204B3DC(work->barActors[0], visible);
    }
    if (work->barActors[1] != 0 && work->commEnabled != 0) {
        func_0204B3DC(work->barActors[1], visible);
    }
    if (work->barActors[2] != 0 && work->commEnabled != 0) {
        func_0204B3DC(work->barActors[2], visible);
    }
    if (visible == 1) {
        func_021F1F80(work);
    }
}








void func_021F1B30(CGearWork *work, int visible)
{
    int i;
    for (i = 0; i < 18; i++)
        func_0204B3DC(work->splashActors[i], visible);
}









void func_021F1B50(CGearWork *work)
{
    int i;
    CGearActorDesc desc;

    for (i = 0; i < 18; i++) {
        desc.x = 0x80;
        desc.y = 0x60;
        desc.animIndex = i + 0x12;
        desc.palOffset = 0;
        desc.surface = 2;
        work->splashActors[i] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                work->spriteAnimRes, &desc, 0, work->heapId);
        func_0204B3DC(work->splashActors[i], 0);
        func_0204B954(work->splashActors[i], 0x2000);
        func_0204B9A0(work->splashActors[i]);
        func_0204B92C(work->splashActors[i], 1);
    }
}








void func_021F1BBC(CGearWork *work)
{
    int i;
    if (work->splashActors[0] != 0) {
        for (i = 0; i < 18; i++) {
            func_0204B3B4(work->splashActors[i]);
            work->splashActors[i] = 0;
        }
    }
}








int func_021F1BE4(CGearWork *work)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (func_0204B98C(work->splashActors[i]) == 1)
            return 0;
    }
    return 1;
}









void func_021F1C0C(CGearWork *work)
{
    CGearActorDesc desc;

    desc.x = 0x68;
    desc.y = 0xaa;
    desc.animIndex = 0x28;
    desc.palOffset = 0;
    desc.surface = 2;
    work->barActors[0] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    func_0204B3DC(work->barActors[0], 0);
    func_0204BA20(work->barActors[0], 0);

    desc.x = 0x68;
    desc.y = 0xaa;
    desc.animIndex = 0x27;
    desc.palOffset = 0x14;
    desc.surface = 2;
    work->barActors[1] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    func_0204B3DC(work->barActors[1], 0);
    func_0204BA20(work->barActors[1], 0);

    desc.x = 0x22;
    desc.y = 0xaa;
    desc.animIndex = 0x10;
    desc.palOffset = 0;
    desc.surface = 2;
    work->barActors[2] = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                                        work->spriteAnimRes, &desc, 0, work->heapId);
    func_0204B3DC(work->barActors[2], 0);
    func_0204BA20(work->barActors[2], 0);
}









void func_021F1CD8(CGearWork *work)
{
    int receiveNo;
    int slotCount;
    int attempt;
    int newLogIdx;
    void *log;

    slotCount = 0;
    if (work->commEnabled == 0) {
        return;
    }
    if (func_021F05B4(work) != 0) {
        return;
    }
    receiveNo = GAME_BEACON_GetReceiveCount();
    if (work->beaconPending == 0) {
        newLogIdx = 0;
        if (GAME_BEACON_GetNextNewLogIndex(&newLogIdx) != 30) {
            work->beaconPending = 1;
        }
    }
    receiveNo--;
    for (attempt = 0; attempt < 30; attempt++) {
        if (slotCount >= 10) {
            break;
        }
        if (receiveNo < 0) {
            PALANM_CopyToSlot(work->palAnm, &work->beaconColors[16], 3, (u16)(d_021F33CC[slotCount] * 2 + 0x60), 4);
            slotCount++;
        } else {
            log = GAME_BEACON_GetLogByReceiveNo(receiveNo);
            if (log != 0) {
                PALANM_CopyToSlot(work->palAnm, &work->beaconColors[func_02165CD8(log)], 3,
                              (u16)(d_021F33CC[slotCount] * 2 + 0x60), 4);
                slotCount++;
            }
            receiveNo--;
        }
    }
}








void func_021F1DB0(CGearWork *work)
{
    if (work->barActors[0] != 0) {
        func_0204B3B4(work->barActors[0]);
        work->barActors[0] = 0;
    }
    if (work->barActors[1] != 0)
        func_0204B3B4(work->barActors[1]);
    if (work->barActors[2] != 0) {
        func_0204B3B4(work->barActors[2]);
        work->barActors[2] = 0;
    }
}









void func_021F1DE8(CGearWork *work, int introMode)
{
    int z;

    work->colorTheme = func_02008550(func_02012944(func_020120F4(work->gameSystem)));
    work->skinIndex = func_020090F0(work->hexMap);
    z = 0;
    work->spriteSystem = func_0204B100(0x44, 0, work->heapId);
    work->spriteResList = func_0204B034(d_021F3214, 1, work->heapId);
    func_0204B258(work->spriteSystem, work->spriteResList);
    func_021F1458(work, work->colorTheme, work->skinIndex, 1);
    func_021F1574(work, work->colorTheme);
    func_021F1950(work);
    func_021F1C0C(work);
    work->buttonTask = func_02051B84(d_021F3272, func_021F18F0, work, work->heapId);
    if (introMode) {
        func_021F1010(work);
        func_021F1A64(work, z);
    } else {
        func_021F13FC(work);
        func_021F1A64(work, 1);
        func_021F1A44(work, 1);
    }
}









void func_021F1E98(CGearWork *work)
{
    int i;
    unsigned int v;

    func_021F1DB0(work);
    func_021F1BBC(work);
    for (i = 0; i < 11; i++) {
        if (work->hudActors[i] != 0) {
            func_0204B3B4(work->hudActors[i]);
            work->hudActors[i] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->tileMarkerActors[i] != 0) {
            func_0204B3B4(work->tileMarkerActors[i]);
            work->tileMarkerActors[i] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor != 0) {
            func_0204B3B4(work->actorSlots[i].actor);
            work->actorSlots[i].actor = 0;
        }
    }
    func_0204AFD8(work->spriteAnimRes);
    func_0204A8D4(work->spriteCharRes);
    func_0204ADA4(work->spritePlttRes);
    v = work->bgCharBlock;
    func_0203FB44(6, (unsigned short)v, (unsigned short)(v >> 16));
}








void func_021F1F24(CGearWork *work)
{
    if (work->buttonTask)
        func_02051C6C(work->buttonTask);
    func_021F1E98(work);
    func_0204B084(work->spriteResList);
    func_0204B1CC(work->spriteSystem);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
}







u8 func_021F1F70(void)
{
    return d_021F3520[UI_GetPowerState()];
}








static inline void SetActorAnimFrame(struct Actor *actor, int frame)
{
    if (frame != CLACT_GetActorAnimSeqCount(actor)) {
        CLACT_SetActorAnimIndex(actor, (u16)frame);
    }
}








void func_021F1F80(CGearWork *work)
{
    RtcTime time;
    struct Actor *actor;
    int digit;

    func_0203F4CC(&time);
    func_0204B3DC(work->hudActors[0], 0);

    actor = work->hudActors[1];
    digit = time.hour / 10;
    SetActorAnimFrame(actor, digit);
    if (digit == 0) {
        func_0204B3DC(actor, 0);
    } else {
        func_0204B3DC(actor, 1);
    }

    actor = work->hudActors[2];
    digit = time.hour % 10;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[3];
    digit = time.second & 1;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[4];
    digit = time.minute / 10;
    SetActorAnimFrame(actor, digit);
    actor = work->hudActors[5];
    digit = time.minute % 10;
    SetActorAnimFrame(actor, digit);

    actor = work->hudActors[6];
    if (OS_IsRunOnTwl()) {
        SetActorAnimFrame(actor, func_021F1F70());
    } else {
        SetActorAnimFrame(actor, UI_GetPowerState() == 5);
    }
}








void func_021F20AC(CGearWork *work)
{
    int i;
    int pixelX;
    int pixelY;
    CGearPos pos;

    for (i = 0; i < 3; i++) {
        if (func_021F133C(work, i + 1, &pixelX, &pixelY)) {
            pixelX = pixelX * 8;
            pixelY = pixelY * 8;
            pos.x = pixelX + 0x10;
            pos.y = pixelY + 0xf;
            func_0204B404(work->tileMarkerActors[i], &pos, 0);
            pixelX += 0x20;
            CLACT_SetActorDrawPriority(work->tileMarkerActors[i], (pixelX / 8) & 0xff);
        } else {
            pos.x = -0x40;
            pos.y = 0;
            func_0204B404(work->tileMarkerActors[i], &pos, 0);
        }
    }
}








void func_021F2130(CGearWork *work)
{
    func_02051C88(work->buttonTask);
    func_021F2D50(work);
    func_021F2DC8(work);
    func_021F1F80(work);
    if (func_021F2DA8(work) == 0) {
        if (work->commEnabled) {
            func_021F05D0(work);
            func_021F0728(work);
            func_021F1CD8(work);
        }
    } else {
        work->command = 0;
    }
}







void func_021F2180(CGearWork *work)
{
    if (work->endCallback != 0)
        (work->endCallback)(work->endCallbackArg);
    work->endCallback = 0;
    work->endCallbackArg = 0;
    if (func_021F0D48(work))
        func_021F2130(work);
}








void func_021F21B4(CGearWork *work)
{
    void (*callback)(int);

    if (func_021F1060(work) == 0) {
        callback = work->endCallback;
        if (callback)
            callback(work->endCallbackArg);
        work->endCallback = 0;
        work->endCallbackArg = 0;
        return;
    }
    func_021F0300(work);
    func_021EFEF8(work, func_021F2180, 0xF92);
}








void func_021F21F8(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        func_021F1010(work);
        func_021F0370(work);
        func_021F1A64(work, 0);
        (work->phase)++;
        return;
    case 1:
        if (func_021F0D48(work)) {
            func_021F1B50(work);
            func_021F1B30(work, 1);
            (work->phase)++;
            return;
        }
        break;
    case 2:
        if (func_021F1BE4(work)) {
            func_021F0F70(work);
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 3:
        if (CTRDG_IsAgbCartridge(work)) {
            func_021F0FF0(work);
            work->phase = 7;
            return;
        }
        if (work->phaseTimer < 8) {
            (work->phaseTimer)++;
            return;
        }
        func_021F1B30(work, 0);
        func_021F1BBC(work);
        func_021F0E70(work);
        (work->phase)++;
        work->phaseTimer = 0;
        return;
    case 4:
        if (CTRDG_IsAgbCartridge(work)) {
            work->phase = 7;
            return;
        }
        if (func_021F11B4(work) == 1) {
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 5:
        if (CTRDG_IsAgbCartridge(work)) {
            work->phase = 7;
            return;
        }
        (work->phaseTimer)++;
        if (work->phaseTimer >= 8) {
            func_021F122C(work);
            work->phaseTimer = 0;
            (work->phase)++;
            return;
        }
        break;
    case 6:
        (work->phaseTimer)++;
        if (work->phaseTimer >= 8) {
            func_021F1A64(work, 1);
            func_021F1A44(work, 0);
            func_021EFEF8(work, func_021F21B4, 0x100b);
            return;
        }
        break;
    case 7:
        func_021F1BBC(work);
        func_021F0E70(work);
        func_021F0AA0(work);
        func_021F122C(work);
        work->phaseTimer = 8;
        work->phase = 6;
        break;
    }
}








void func_021F2370(CGearWork *work)
{
    if (work->phaseTimer == 0) {
        func_021F0E70(work);
        func_021F1A64(work, 1);
        func_021F1A44(work, 0);
        func_021F1BBC(work);
        func_021F1010(work);
        func_021F0370(work);
    }
    work->phaseTimer += 1;
    if (work->phaseTimer >= 0x10) {
        work->phaseTimer = 0;
        func_021EFEF8(work, func_021F21B4, 0x1041);
    }
}








/*
 * base is a u32 holding (u16)work->bgCharBlock and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 */
int func_021F23CC(CGearWork *work, struct GameSystem *gameSystem)
{
    int result;
    struct SaveCtrl *saveSys;
    u16 crc;
    u32 charBase;
    u16 savedCrc;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = func_02030734(0x70, 0x3000, 0, d_021F3554, 0x104E);
    saveSys = func_02012EBC(func_020120F4(gameSystem));
    if (func_020072CC(saveSys, 4, 0x70, buf, 0x3000) == 1) {
        crc = func_0203F1FC(buf, 0x2600);
        savedCrc = func_0200910C(func_02009210(saveSys));
        charBase = (u16)work->bgCharBlock;
        if (crc == savedCrc && func_0200C6F0(buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                func_02040B1C(6, buf + i * 0x220, 0x220, charBase + (i + 5) * 0x20);
            }
            func_02040E78(6, buf + 0x1FE0, 0x20, 0x140);
            func_02040AE0(5, buf + 0x2000, 0x600);
            pal = (u16 *)func_0204162C(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)charBase;
            }
            func_020409B4(5);
        }
    }
    func_0200734C(saveSys, 4);
    func_020307B0(buf);
    return result;
}








void func_021F24C0(CGearWork *work)
{
    func_021F0FF0(work);
    if (work->fadeCtx != 0)
        func_02030D28(work->fadeCtx);
    func_021F0E70(work);
    func_021F1010(work);
    if (work->fadeCtx != 0)
        func_02030D28(work->fadeCtx);
    work->commEvent = 1;
}







void func_021F24FC(CGearWork *work)
{
    work->commEvent = 2;
}







void func_021F2508(void *task, CGearWork *work)
{
    if (work->palAnm != 0)
        PALANM_TransferPalettes(work->palAnm);
}






/*
 * 2026-10-05 (wave D5 lane 02): arm9 func_02035010/func_02035040 and their setters func_02035004/func_02035034 are now filed in src/matched/arm9/; the wrappers show MATCH only until the labels exist. Re-run after the integrator labels them.
 * 2026-10-04 (wD2 lane 09): bytes are identical; 3 of 41 relocations open.
 * Filed leaf func_021F24FC as matched ov029_func_021F24FC.c (EXACT).
 * Open: ABS32 +01C0 to 021F24FC (witness index not yet regenerated),
 * and THM_CALL +0128/+0130 to unlabelled arm9 02035010 and 02035040 (arm9 wrappers:
 * r2=*(0x021469BC), tail call to 02035004/02035034 style stubs, no source or label yet).
 *
 * Byte-correct.  Blocked by two unlabelled ARM9 leaves (the integrator's), so the
 * overlay leaf 0x021F24FC is not filed either:
 *   +0128 func_02035010 (arm): verified MATCH with `one --arm`, capped
 *     only by its own unlabelled tail-call target 0x02035004
 *     (str r1,[r0,#0x14]; str r2,[r0,#0x28]; bx lr):
 *       extern void *d_021469BC;
 *       void func_02035010(void *cb, void *arg)
 *       { func_02035004(d_021469BC, cb, arg); }
 *   +0130 func_02035040 (arm): the same wrapper over 0x02035034
 *     (str r1,[r0,#0x10]; str r2,[r0,#0x28]; bx lr), MATCH likewise:
 *       void func_02035040(void *cb, void *arg)
 *       { func_02035034(d_021469BC, cb, arg); }
 *   +01C0 ABS32 func_021F24FC (ov029): unlabelled leaf
 *     `void func_021F24FC(CGearWork *work) { work->commEvent = 2; }` (ldr r1,=0x451;
 *     movs r2,#2; strb r2,[r0,r1]; bx lr).
 * Levers: r = 0 at the top shares the zero register with the command/lastCommand
 * stores; t = 1 assigned after the func_02021518 store keeps t in a stack
 * slot and 0x1C0 in r7; commEnabled is a u8 field (ldrb); func_021F3144's second
 * argument is int here (no narrowing before the call).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040 (no source change possible here).
 */
void func_021F251C(CGearWork *work, struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode)
{
    int customBgLoaded = 0;
    int powerOn;
    void *eventWork;

    work->heapId = 0x70;
    work->hexMap = hexMap;
    work->parentWork = parentWork;
    work->gameSystem = gameSystem;
    work->powerOn = 1;
    work->commEnabled = func_0201214C(gameSystem);
    work->agbSlotPresent = 1;
    work->command = 0;
    work->lastCommand = 0;
    work->archive = func_020490F4(0x1e, 0x70);
    work->fadeMem = func_02030734(0x70, func_02030CB0(4), 1, d_021F3554, 4280);
    work->fadeCtx = func_02030CBC(4, work->fadeMem);
    if (introMode != 0) {
        func_021EFEF8(work, func_021F21F8, 4284);
    } else {
        func_021F0298(work);
        func_021EFEF8(work, func_021F2180, 4287);
    }
    func_021F1624(work);
    func_021F1DE8(work, introMode);
    if (func_02009100(work->hexMap) != 0)
        customBgLoaded = func_021F23CC(work, gameSystem);
    func_021F15FC(work, customBgLoaded);
    func_021F0A0C(work);
    work->palAnm = func_02021518(0x70);
    powerOn = 1;
    PALANM_SetAutoTransfer(work->palAnm, 1);
    func_0202155C(work->palAnm, 3, 0x1C0, 0x70);
    func_0202155C(work->palAnm, 1, 0x1C0, 0x70);
    func_020216D4(work->palAnm, 3, 0, 0x1C0);
    func_020216D4(work->palAnm, 1, 0, 0x1C0);
    func_021F0DB4(work, work->commEnabled);
    PALANM_TransferPalettes(work->palAnm);
    work->palTransferTask = func_020056A0(func_021F2508, work, 1);
    func_02035010(func_021F24C0, work);
    func_02035040(func_021F24FC, work);
    func_021F2E10(work, &work->fadeFx);
    func_021F1CD8(work);
    func_021F1F80(work);
    if (introMode == 0) {
        if (func_020120D8(gameSystem) != 0)
            powerOn = 0;
        func_021F3144(work, powerOn);
        func_021F2D84(work);
    } else {
        func_021F21F8(work);
    }
    if (work->fadeCtx != 0)
        func_02030D28(work->fadeCtx);
    eventWork = func_02012138(gameSystem);
    if (eventWork != 0 && func_021585E0(eventWork) == 2)
        func_02158614(eventWork);
}






void func_021F26E0(CGearWork *work)
{
    void *r = func_02012138(work->gameSystem);

    if (r != 0) {
        if (func_021585E0(r) == 2)
            func_02158614(r);
    }
    func_021F2E5C(&work->fadeFx);
    func_02035010(0, 0);
    func_02035040(0, 0);
    GFL_NET_RestartNoTimeout();
    func_0203D34C(0, work->heapId);
    func_020215A0(work->palAnm, 3);
    func_020215A0(work->palAnm, 1);
    func_02021540(work->palAnm);
    func_02030DA4(work->fadeCtx);
    func_020307B0(work->fadeMem);
    func_02030EAC(work->palTransferTask);
    if (work->lastCommand != 5) {
        func_02028A70(func_02012A30(func_020120F4(work->gameSystem)));
    }
    func_02049238(work->archive);
    func_021F1F24(work);
    REG_DB_BLDCNT = 0;
    func_02082BCC(work, 0, sizeof(CGearWork));
}





CGearWork *func_021F279C(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, int introMode)
{
    CGearWork *work;
    work = func_02030734(0x70, sizeof(CGearWork), 1, d_021F3554, 0x1147);
    func_021F251C(work, hexMap, parentWork, gameSystem, introMode);
    return work;
}





CGearWork *func_021F27D8(struct HexMap *hexMap, int parentWork, struct GameSystem *gameSystem, void (*callback)(int), int callbackArg, int introMode)
{
    CGearWork *work = func_021F279C(hexMap, parentWork, gameSystem, introMode);

    work->endCallback = callback;
    work->endCallbackArg = callbackArg;
    if (introMode != 0) {
        func_021EFEF8(work, func_021F21F8, 0x1160);
        work->agbSlotPresent = 0;
    } else {
        if (work->endCallback != 0)
            (work->endCallback)(work->endCallbackArg);
        work->endCallback = 0;
        work->endCallbackArg = 0;
    }
    func_021F3190(hexMap, work->archive, func_020056EC(10), 0x70);
    func_021F20AC(work);
    return work;
}





/*
 * The listing extent (316 B) runs over an unlabelled 4-byte follower at
 * 0x021F2980 (`bx lr`); the function is 312 B.  func_021F3144's second
 * argument is this function's r1, forwarded untouched.
 */
void func_021F2848(CGearWork *work, u8 powerOn)
{
    int linkMode;
    u32 padKeys;
    struct SoundSys *soundSys;

    if (work->commEvent == 1)
        return;

    func_021F3144(work, powerOn);
    if (func_021F2DA8(work) == 0) {
        linkMode = func_02158630(func_02012138(work->gameSystem));
        if (linkMode == 3) {
            if (work->callTabShown == 0) {
                func_021F06B8(work, 1, 0);
                work->callTabShown = 1;
            }
        } else {
            if (work->callTabShown == 1) {
                func_021F06B8(work, 0, 0);
                work->callTabShown = 0;
            }
        }
        if (linkMode == 0) {
            padKeys = func_0201058C(func_0201283C(func_020120F4(work->gameSystem)));
            soundSys = func_02012A30(func_020120F4(work->gameSystem));
            if (padKeys & 8) {
                if (work->ringtoneActive == 0) {
                    work->ringtoneActive = 1;
                    func_021F06B8(work, 1, 1);
                }
                FIELD_SOUND_SYSTEM_StartRingtone(soundSys);
            } else if ((padKeys & 8) == 0 && work->ringtoneActive != 0) {
                func_02028A70(soundSys);
                work->ringtoneActive = 0;
                func_021F06B8(work, 0, 0);
            }
        }
    }

    if (work->commEvent == 2) {
        work->commEvent = 0;
        if (func_021F2DA8(work) == 0) {
            func_021EFEF8(work, func_021F2370, 0x11C5);
        } else {
            func_021F1BBC(work);
            func_021F1A64(work, 1);
            func_021F13FC(work);
            func_021F0EB0(work, func_021F2DA8(work));
            func_021F0298(work);
            func_021EFEF8(work, func_021F2180, 0x11D4);
        }
    }

    if (work->stepFunc != 0)
        work->stepFunc(work);
    if (work->fadeCtx != 0)
        func_02030D28(work->fadeCtx);
}




void func_021F2980(void)
{
}


void func_021F2984(CGearWork *work)
{
    func_021F26E0(work);
    func_020307B0(work);
}





int func_021F2994(CGearWork *work)
{
    struct HexMap *hexMap = work->hexMap;
    int parentWork = work->parentWork;
    struct GameSystem *gameSystem = work->gameSystem;

    if (work->stepFunc == func_021F2180) {
        func_0202223C(1, 0);
        func_021F26E0(work);
        func_021F251C(work, hexMap, parentWork, gameSystem, 0);
        WIPE_ResetBrightness(1);
        return 1;
    }
    return 0;
}





/*
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = func_021F2EEC" tails are cross-jumped.
 */
struct GameEvent *func_021F29D8(CGearWork *work, int enabled)
{
    struct GameEvent *event = 0;
    void *handlerData;

    func_02012138(work->gameSystem);
    handlerData = func_0201210C(work->gameSystem);
    if (enabled == 0 || handlerData == 0)
        return 0;

    switch (work->command) {
    case 1:
    case 6:
        if (func_021F05B4(work) == 0) {
            func_020061E4(0x54E);
            event = func_021F2EEC(work, work->command);
        } else {
            func_020061E4(0x7E3);
            func_021F3098(work);
            func_021EFEF8(work, func_021F3118, 0x1238);
        }
        break;
    case 5:
        func_020061E4(0x54E);
        event = func_021F2EEC(work, work->command);
        break;
    case 12:
    case 13:
        func_020061E4(0x628);
        event = func_021F2EEC(work, work->command);
        break;
    case 7:
    case 11:
        if (func_021F05B4(work) == 0) {
            func_020061E4(0x628);
            event = func_021F2EEC(work, work->command);
        } else {
            func_020061E4(0x7E3);
        }
        break;
    }

    if (event != 0) {
        work->lastCommand = work->command;
        func_021EFEF8(work, func_021F2CD4, 0x1256);
    }
    work->command = 0;
    return event;
}





/*
 * Unlabelled leaf, sole blocker of ov021 func_0218A6E8.
 */
int func_021F2AB8(CGearWork *work)
{
    if (work == 0)
        return 0;
    if (work->lastCommand == 5)
        return 1;
    return 0;
}




void func_021F2AD4(CGearWork *work)
{
    if (work != 0) {
        work->ringtoneActive = 0;
        func_021F06B8(work, 0, 0);
    }
}





void func_021F2AEC(CGearWork *work, struct HexMap *hexMap, int col, int row, int kind)
{
    int scanRow;
    int scanCol;

    for (scanRow = 0; scanRow < 4; scanRow++) {
        for (scanCol = 0; scanCol < 9; scanCol++) {
            if (kind == func_021F2B9C(work, scanCol, scanRow)) {
                if (func_021F2BB8(work, scanCol, scanRow) != 0) {
                    func_020091AC(hexMap, scanCol, scanRow, kind, 0, 1);
                    func_021F1290(work, scanCol, scanRow, kind);
                } else if (func_021F2BD4(work, scanCol, scanRow, kind) != 0) {
                    func_020091AC(hexMap, scanCol, scanRow, kind, 0, 0);
                }
            }
        }
    }
    func_020091AC(hexMap, col, row, kind, 1, 0);
    func_021F1290(work, col, row, kind);
    func_020409B4(4);
    func_021F20AC(work);
}




u32 func_021F2B9C(const CGearWork *work, int col, int row)
{
    if (work->commEnabled != 0)
        return func_02009110(work->hexMap, col, row);
    return 0;
}




int func_021F2BB8(const CGearWork *work, int col, int row)
{
    if (work->commEnabled != 0)
        return func_02009134(work->hexMap, col, row);
    return 0;
}




int func_021F2BD4(const CGearWork *work, int col, int row, int kind)
{
    if (work->commEnabled != 0)
        return func_02009160(work->hexMap, col, row, kind);
    return 0;
}


int CTRDG_IsAgbCartridge(CGearWork *work)
{
    if (work->agbSlotPresent) {
        if (CTRDGi_IsAgbCartridgeAtInit())
            return 1;
    }
    return 0;
}




int func_021F2C10(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        func_0204B92C(work->hudActors[work->activeIcon], 1);
        func_0204B954(work->hudActors[work->activeIcon], 1 << 13);
        work->phase += 1;
        break;
    case 1:
        if (func_0204B98C(work->hudActors[work->activeIcon]) == 0)
            return 1;
        break;
    }
    return 0;
}


int func_021F2C78(CGearWork *work)
{
    switch (work->phase) {
    case 0:
        switch (work->activeIcon) {
        case 3:
            func_021F2E68(&work->fadeFx, 0x1c0);
            break;
        case 4:
            func_021F2E68(&work->fadeFx, 0x200);
            break;
        }
        work->phase += 1;
        break;
    case 1:
        if (func_021F2E8C(&work->fadeFx) != 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Unlabelled empty callback (bx lr), printed as a pool word; its only
 * referrer is the pool word in func_021F29D8, which it blocks.
 */
void func_021F2CD4(CGearWork *work)
{
}


void func_021F2CD8(CGearWork *work)
{
    if (work->offIndicator == 0) {
        work->offIndicator = 1;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void func_021F2CF4(CGearWork *work)
{
    if (work->commIndicator == 0) {
        work->commIndicator = 1;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void func_021F2D10(CGearWork *work)
{
    if (work->commIndicator != 0) {
        work->commIndicator = 0;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void func_021F2D30(CGearWork *work)
{
    if (work->offIndicator == 1) {
        work->offIndicator = 0;
        work->indicatorDirty = 1;
        work->indicatorTimer = 0;
    }
}

void func_021F2D50(CGearWork *work)
{
    if (work->indicatorDirty != 0) {
        work->indicatorTimer++;
        if (work->indicatorTimer >= 8) {
            func_021F0EB0(work, func_021F2DA8(work));
            work->indicatorDirty = 0;
        }
    }
}

void func_021F2D84(CGearWork *work)
{
    if (work->indicatorDirty != 0) {
        func_021F0EB0(work, func_021F2DA8(work));
        work->indicatorDirty = 0;
    }
}

int func_021F2DA8(CGearWork *work)
{
    if (work->offIndicator != 0)
        return 1;
    if (work->commIndicator != 0)
        return 1;
    return 0;
}


void func_021F2DC8(CGearWork *work)
{
    if (func_021F2DA8(work) == 0 && work->tabActive != 0) {
        work->tabFrame += 1;
        if (work->tabFrame >= 8) {
            if (func_021F05B4(work) != 0)
                func_021F0F28(work, 1);
            else
                func_021F0F28(work, 0);
            work->tabActive = 0;
        }
    }
}


void func_021F2E10(CGearWork *work, CGearFadeFx *fx)
{
    struct {
        unsigned short a;
        unsigned short b;
        unsigned short c;
        unsigned char d;
        unsigned char e;
    } header;

    header.a = 0;
    header.b = 0;
    header.c = 0x25;
    header.d = 0;
    header.e = 2;
    fx->actor = func_0204B294(work->spriteSystem, work->spriteCharRes, work->spritePlttRes,
                              work->spriteAnimRes, &header, 0, work->heapId);
    func_0204B3DC(fx->actor, 0);
    fx->palAnm = work->palAnm;
    fx->fadeCtx = work->fadeCtx;
}


void func_021F2E5C(CGearFadeFx *fx)
{
    func_0204B3B4(fx->actor);
}

void func_021F2E68(CGearFadeFx *fx, int palette)
{
    func_0204B9A0(fx->actor);
    func_0204B92C(fx->actor, 1);
    func_0204B954(fx->actor, 0x2000);
    fx->active = 1;
    fx->palette = palette;
}


int func_021F2E8C(CGearFadeFx *fx)
{
    if (fx->active == 0)
        return 1;
    if (func_0204B98C(fx->actor) == 0) {
        fx->active = 0;
        return 1;
    }
    PALANM_RequestFade(fx->palAnm, 8, fx->palette, -0x78, 0,
                       (u8)d_021F3224[CLACT_GetActorAnimSeqCount(fx->actor)], 0,
                       fx->fadeCtx);
    return 0;
}


struct GameEvent *func_021F2EEC(CGearWork *work, int kind)
{
    struct GameEvent *event = func_020122C0(work->gameSystem, 0, func_021F2F60, 8);
    CGearEventWork *req = func_020124E8(event);

    req->work = work;
    req->kind = kind;
    switch (kind) {
    case 1:
    case 5:
    case 6:
        func_021F0194(req->work);
        break;
    case 11:
        work->activeIcon = 4;
        break;
    case 7:
        work->activeIcon = 3;
        break;
    case 12:
        work->activeIcon = 8;
        break;
    case 13:
        work->activeIcon = 10;
        break;
    }
    return event;
}


int func_021F2F60(struct GameEvent *event, int *seq, CGearEventWork *req)
{
    CGearWork *work;
    void *fieldMap;
    int done;
    struct GameEvent *next;
    CGearSubprocArgs *args;

    work = req->work;
    done = 0;
    fieldMap = func_0201210C(work->gameSystem);
    switch (req->kind) {
    case 1:
    case 5:
    case 6:
        done = func_021F009C(req->work);
        break;
    case 7:
    case 11:
        done = func_021F2C78(req->work);
        break;
    case 12:
    case 13:
        done = func_021F2C10(req->work);
        break;
    }
    if (done == 0)
        return 0;

    switch (req->kind) {
    case 6:
        next = func_020124AC(work->gameSystem, (u32)abs_id_0, EVENT_GSYNC_Entry, fieldMap);
        break;
    case 1:
        next = func_021559E4(work->gameSystem, fieldMap, 0, 1);
        break;
    case 5:
        next = func_0215FBF4(work->gameSystem, fieldMap, 0, 1);
        break;
    case 11:
        next = func_02167044(work->gameSystem, fieldMap);
        break;
    case 7:
        next = func_021945A4(work->gameSystem, fieldMap, 4);
        break;
    case 12:
        args = func_02030734(4, 8, 1, d_021F3554, 0x14B7);
        args->playerData = (u8 *)func_02012944(func_020120F4(work->gameSystem));
        args->gameSystem = work->gameSystem;
        next = func_02014808(work->gameSystem, fieldMap, (u32)abs_id_124, d_021D4D40, args, 0, args);
        break;
    case 13:
        next = func_021D297C(work->gameSystem);
        break;
    }
    func_0201235C(event, next);
    return 0;
}

void func_021F3098(CGearWork *work)
{
    work->rippleKind = func_021F2B9C(work, work->selectedCol, work->selectedRow);
    work->rippleStep = 0;
    func_021EFF58(work, work->selectedCol, work->selectedRow);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021F30C8(CGearWork *work)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor) {
            func_0204B3B4(work->actorSlots[i].actor);
            work->actorSlots[i].actor = 0;
        }
    }
}

int func_021F30EC(CGearWork *work)
{
    int result = 1;
    int i;
    for (i = 0; i < 20; i++) {
        if (work->actorSlots[i].actor) {
            if (func_0204B98C(work->actorSlots[i].actor)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}

/*
 * interface: caller sets r2=0x1514 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 */
void func_021F3118(CGearWork *work)
{
    func_021F2130(work);
    if (func_021F30EC(work)) {
        func_021F30C8(work);
        func_021EFEF8(work, func_021F2180, 0x1514);
    }
}


void func_021F3144(CGearWork *work, int powerOn)
{
    if (func_0203CD98() == 0 && work->commEnabled != 0)
        func_021F2CF4(work);
    else
        func_021F2D10(work);
    if (work->powerOn != powerOn) {
        if (powerOn == 0)
            func_021F2CD8(work);
        else
            func_021F2D30(work);
        work->powerOn = powerOn;
    }
}


/* Reads archive member (skinIndex + 0x19) into the buffer of the C-Gear save. */
void func_021F3190(struct HexMap *hexMap, struct ArcFile *arc, int skinIndex, int heapId)
{
    void *skinBuffer = func_020091FC(hexMap);

    func_0204932C(arc, skinIndex + 0x19, skinBuffer);
}
