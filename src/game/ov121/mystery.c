/*
 * file:     mystery.c
 * unit:     yes
 * function: func_021D6660, func_021D67D4, func_021D6888, func_021D6924, func_021D6948, func_021D694C, func_021D6AEC, func_021D6C28, func_021D6C58, func_021D6C60, func_021D6C84, func_021D6CEC, func_021D6CF4, func_021D6D38, func_021D6D50, func_021D6D6C, func_021D6D7C, func_021D6D80, func_021D6DB4, func_021D6DF4, func_021D6E3C, func_021D72F0, func_021D73DC, func_021D7814, func_021D7B4C, func_021D7CF4, func_021D7EAC, func_021D80C0, func_021D80F0, func_021D8138, func_021D8198, func_021D81B0, func_021D8380, func_021D83B0, func_021D83CC, func_021D83DC, func_021D849C, func_021D84D4, func_021D8C1C, func_021D8CA8, func_021D8D00, func_021D8D18, func_021D8D1C, func_021D8EA4, func_021D9138, func_021D91BC, func_021D9228, func_021D9238, func_021D9254, func_021D9288, func_021D928C, func_021D933C, func_021D93F4, func_021D9488, func_021D94B8, func_021D94C4, func_021D9554, func_021D9580
 * address:  0x021D6660
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A300 0x0200A300 thumb
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021DA854 0x021DA854 thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021DE2A0 0x021DE2A0 thumb ov121
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   ov114_id 0x00000072 data
 *   func_021DE2F0 0x021DE2F0 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02087BCC 0x02087BCC arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   func_021DE300 0x021DE300 thumb ov121
 *   func_021DA898 0x021DA898 thumb ov121
 *   func_021D9718 0x021D9718 thumb ov121
 *   func_021D972C 0x021D972C thumb ov121
 *   func_021D9738 0x021D9738 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021DA840 0x021DA840 thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040B94 0x02040B94 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02005728 0x02005728 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02049F34 0x02049F34 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_02050C04 0x02050C04 arm
 *   d_021DFB80 0x021DFB80 data ov121 a1
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *   func_020515CC  0x020515CC  arm
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0202EB44 0x0202EB44 thumb
 *   func_021DA84C 0x021DA84C thumb ov121
 *   func_021DE4D8 0x021DE4D8 thumb ov121
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_021DE3E0 0x021DE3E0 thumb ov121
 *   func_021DE4DC 0x021DE4DC thumb ov121
 *   func_021DEF6C 0x021DEF6C thumb ov121
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_020362DC 0x020362DC arm
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_021D9750 0x021D9750 thumb ov121
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   func_021D9790 0x021D9790 thumb ov121
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   func_0207D63C 0x0207D63C arm
 *   func_021DAC18 0x021DAC18 thumb ov121
 *   func_021DAEF0 0x021DAEF0 thumb ov121
 *   func_021DB008 0x021DB008 thumb ov121
 *   func_021DAE1C 0x021DAE1C thumb ov121
 *   func_021DAFCC 0x021DAFCC thumb ov121
 *   MYSTERY_DATA_HasCardSpace 0x0200A0C8 thumb
 *   MYSTERY_DATA_IsMainSave 0x0200A350 thumb
 *   PROCSYS_PushGlobal 0x020312CC arm
 *   func_0203D34C 0x0203D34C arm
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data a1
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 *   func_021DA038 0x021DA038 thumb ov121
 *   func_021DA148  0x021DA148  thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045808 0x02045808 arm
 *   func_0204989C 0x0204989C arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021DA4DC 0x021DA4DC thumb ov121
 *   func_020414EC 0x020414EC arm
 *   func_021DA698 0x021DA698 thumb ov121
 *   func_021DA6D0 0x021DA6D0 thumb ov121
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   d_021DF544 0x021DF544 data a4
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_020186C8 0x020186C8 thumb
 *   func_02017588 0x02017588 thumb
 *   func_02017E40 0x02017E40 thumb
 *   POKE_TOOL_SetDefaultMoves 0x02017FA8 thumb
 *   func_0201808C 0x0201808C thumb
 *   func_020180F4 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   func_02045A98 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_02082A48 0x02082A48 arm
 *   func_0204B688 0x0204B688 arm
 *   d_021DF4F2 0x021DF4F2 data a2
 *   d_021DF4FC 0x021DF4FC data a4
 *   d_0209DF08 0x0209DF08 data
 *   d_0209DF0C 0x0209DF0C data
 *   g_020A7370 0x020A7370 data a4
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   func_020061E4 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B528 0x0204B528 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02025538 0x02025538 thumb
 *   func_021DA8CC 0x021DA8CC thumb ov121
 *   func_021DA9EC 0x021DA9EC thumb ov121
 *   func_021DA9F0 0x021DA9F0 thumb ov121
 *   func_021DA994 0x021DA994 thumb ov121
 *   func_021DA978 0x021DA978 thumb ov121
 *   func_021DA958 0x021DA958 thumb ov121
 *   func_02025588 0x02025588 thumb
 *   func_021DA9F8 0x021DA9F8 thumb ov121
 *   POKEGRA_LoadCharDataPP 0x0202D6F4 thumb
 *   POKEGRA_ConvertCharTo2D 0x0202D214 thumb
 *   MYSTERY_DATA_CheckPacketCrc 0x0200A21C thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021DF5E4 0x021DF5E4 data a4
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   MYSTERY_DATA_AddCard  0x0200A034  thumb  arm9
 *   MYSTERY_DATA_IsEventFlag  0x0200A1A8  thumb  arm9
 *   MYSTERY_DATA_SetEventFlag  0x0200A1E4  thumb  arm9
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb  arm9
 *   GAME_DATA_Delete  0x02012704  thumb  arm9
 */
#include "../../matched/include/Obj02176.h"
#include "../../matched/include/Obj01402.h"
#include "../../matched/include/Obj01403.h"
#include "../../matched/include/Obj22851.h"
#include "../../matched/include/Obj10404.h"
#include "../../matched/include/Obj22852.h"
#include "../../matched/include/Obj10405.h"
#include "../../matched/include/Obj13938.h"
#include "../../matched/include/Obj22853.h"
#include "../../matched/include/Obj22854.h"
#include "../../matched/include/Obj22857.h"
#include "../../matched/include/Obj00326.h"
#include "../../matched/include/Obj13939.h"
#include "../../matched/include/Obj00297.h"
#include "../../matched/include/Obj00989.h"
#include "../../matched/include/Obj00827.h"
#include "../../matched/include/Obj00533.h"
#include "../../matched/include/Obj22858.h"
#include "../../matched/include/Obj22859.h"
#include "../../matched/include/Obj22860.h"
#include "../../matched/include/Obj22861.h"
#include "../../matched/include/Obj22862.h"
#include "../../matched/include/Obj22863.h"
#include "../../matched/include/Obj22864.h"
#include "../../matched/include/Obj22865.h"
#include "../../matched/include/Obj22866.h"
#include "../../matched/include/Obj10409.h"
#include "../../matched/include/Obj06446.h"
#include "../../matched/include/Obj04491.h"
#include "../../matched/include/Obj22867.h"
#include "../../matched/include/Obj08088.h"
#include "../../matched/include/Obj10410.h"
#include "../../matched/include/Obj22868.h"
#include "../../matched/include/Obj00498.h"
#include "../../matched/include/Obj00184.h"
#include "../../matched/include/Obj02833.h"
#include "../../matched/include/Obj06447.h"
#include "../../matched/include/Obj13941.h"
#include "../../matched/include/Obj10411.h"
#include "../../matched/include/Obj05354.h"
#include "../../matched/include/Obj02177.h"
#include "../../matched/include/Obj08089.h"
#include "../../matched/include/Obj02178.h"
#include "../../matched/include/Obj05355.h"
#include "../../matched/include/Obj04492.h"
#include "../../matched/include/Obj22870.h"
#include "../../matched/include/Obj22871.h"
#include "../../matched/include/Obj13942.h"
#include "../../matched/include/Obj13943.h"

#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
#define PALETTE ((void *)0x050003C0)
#define D(k) (*(u32 *)(desc+(k)))
#define H(k) (*(u16 *)(desc+(k)))
#define O(k) (*(u32 *)(out+(k)))
#define OH(k) (*(u16 *)(out+(k)))
#define REG (*(volatile u16 *)0x04000060)
struct Obj0203159C;
struct Big;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct S020315D4;
struct Obj;
struct RtcDate;
struct U16Vec;
struct Strbuf;
struct Actor;
struct Sub0200852CObj;
struct Mon;
struct Vec2;
struct Pt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { s16 x,y,z; u8 a,b; } Record;

typedef signed int     s32;

typedef struct {int y,m,d,week;} Date;

typedef struct {u8 bit:1;} Flag;

typedef struct { u32 w[12]; } Desc_021D7814;

typedef struct { u32 w[9]; } Desc_021D7B4C;

typedef struct { u32 w[9]; } Desc_021D6660;

typedef struct { int f0, f4, f8, fc, f10, f14, f18; u16 f1c, f1e, f20, f22; } Config_021D8138;

typedef struct { u32 w[9]; s16 h[7]; u16 pad; void *callback,*arg,*result; } Desc_021D8138;

typedef struct { int w[12]; } Config_021D83DC;

typedef unsigned long long u64;

typedef struct {s16 x,y,z;u8 a,b;} Point;

typedef struct {u8 iv[6];u16 move[4];Point point;void *resdesc;} Work;

typedef struct {s16 x,y;} Position;

typedef struct { short x,y,z; u8 a,b; } Pos;

extern int func_02034AC4(int id);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, int);
extern void *GAME_DATA_Create(u16 id);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A300(void *, void *, void *);
extern u8 *func_021D9624(int arg, u16 heap);
extern unsigned func_021D9744(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_021DA854(void *, void *, u16);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void *func_021DE2A0(void *arg, int heap);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void func_021DE2F0(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021DA890(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021D96C4(u8 *p);
extern void func_0200A338(void *);
extern void GAME_DATA_Delete(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_02087BCC(u32 parameter);
extern void func_02034A5C(int);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021DE300(char *p);
extern void func_021DA898(char *p);
extern void func_021D9718(u8 *p);
extern void func_021D972C(char *p);
extern void func_021D9738(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021D9E50(u8 *p);
extern int func_021DA2C8(u8 *p);
extern int func_021DA840(void **);
extern int func_021DA8AC(u32 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68();
extern void func_02049658();
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_02005728(u32 range);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0204ADEC(void *,void *,int);
extern s32 func_021DAAA4(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(int, int, int, int);
extern int func_020515CC(int *p, int a, int b, int c);
extern void func_021D9F08(u8 *,int,int,int);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021DE308(char *,unsigned);
extern int func_021DE3E0(void *);
extern int func_021DE4DC(u8 *p, void *a, u32 b);
extern int func_021DEF6C(char *,void *,u16);
extern int func_021DE500(void *);
extern void func_021DE550(char *p);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8C4(u32 *p);
extern int func_021DA178(char *);
extern unsigned func_021D9FF8(u8 *p);
extern u32 func_020362DC(void);
extern void func_0203F4E4(struct RtcDate *date);
extern int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit);
extern int MYSTERY_DATA_AddCard(void *p, void *arg);
extern void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx);
extern u32 MYSTERY_DATA_HasCardSpace(u8 *p);
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *);
extern int func_0200A104(char *p, unsigned int idx);
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern int func_0202EB44(void);
extern void *func_021DE4D8(char *p);
extern void func_021DA84C(u8 *p, u32 i, u32 value);
extern void func_021D9750(u8 *p);
extern void MYSTERY_DATA_SaveStart(void *a0, int a1);
extern int MYSTERY_DATA_SaveMain(void *a0, int a1);
extern void func_021D9790(char *p);
extern void *func_021DCFC8(Desc_021D7814 *,u16);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_StepIntro(char *p);
extern void MYSTERY_ALBUM_StartIntro(u8 *p);
extern int MYSTERY_ALBUM_IsIntroIdle(char *p);
extern void func_0207D63C(void *,int,int,int,int);
extern void *func_021DAC18(Desc_021D7B4C *,int);
extern void func_021DAEF0(struct Obj *obj);
extern int func_021DB008(char *p);
extern void func_021DAE1C(struct Obj *obj);
extern void func_021DAFCC(char *p);
extern void PROCSYS_PushGlobal(u32,u32,u32);
extern void func_0203D34C(u32,u32);
extern void MYSTERY_ALBUM_Delete(char *);
extern void func_021DD1FC(void **);
extern void func_021DA8B8(u32 *p);
extern void *func_021DA038(Config_021D8138 *, int);
extern void func_021DA148(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204989C(int,int,int,int,int,int,int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void *func_021DA4DC(Desc_021D8138 *,int);
extern void func_020414EC(unsigned);
extern void func_021DA698(u8 *p);
extern int func_021DA6D0(unsigned char *);
extern void *func_021DA1BC(int,Config_021D83DC *,int,int,int,void *,void *,void *,int);
extern void func_021DA2A8(u8 *p);
extern void func_021DA280(u8 *p);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_020056EC(u32);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16,u16,u32,u32,u32);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *,u32,u32);
extern u32 POKE_TOOL_SetDefaultMoves(void *);
extern u32 func_0201808C(void *,u32);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *,u32,u32);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_020185F0(void *);
extern void func_0202F2AC(void *,u32,u32,u32,u32);
extern void func_020185C4(void *);
extern u32 func_02017E1C(void *,u32,u32);
extern int func_0202D7C8(int);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_0202D8D0(int,void *,int,int,u16,u16);
extern u32 func_0202D9A4(u32,u32,u32,u32,u16);
extern int func_0202D934(int,void *,int,int,u16);
extern u32 func_02020E60(u32 item, u32 which);
extern void func_02082A48(u32,void *,u32);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void func_020061E4(u32 a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B53C(const struct Actor *actor, struct Pt *out);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021DA8CC(const char *p, u16 a, u16 b, int c, u8 d, int e, void *f, void *g, u16 heap);
extern void func_021DA9EC(u8 *p, int a);
extern void func_021DA9F0(u32 *p, u32 a, u32 b, u32 c);
extern void func_021DA994(char *p, int a, int b, int c);
extern void func_021DA978(char *p);
extern void func_021DA958(unsigned char *p);
extern void func_02025588(void *);
extern int func_021DA9F8(u8 *p);
extern u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3);
extern void POKEGRA_ConvertCharTo2D(void *,u16);
extern int MYSTERY_DATA_CheckPacketCrc(u8 *obj);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
int func_021D6660(void *a, u32 b, u32 c);
int func_021D67D4(void *a, int b, int c, char *p);
int func_021D6888(int a, int b, int c, char *p);
void func_021D6924(u16 *p,u16 heap);
void func_021D6948(void *a0);
void func_021D694C(u16 *p,int mode);
void func_021D6AEC(char *p, void *owner, u16 heap);
void func_021D6C28(u8 *p);
void *func_021D6C58(u8 *p,int i);
void func_021D6C60(u8 *p,int heap);
void func_021D6C84(u8 *p);
void func_021D6CEC(u8 *p);
void func_021D6CF4(int *p, int heap);
void func_021D6D38(void *p);
void func_021D6D50(int *p, int a, int b, int c);
int func_021D6D6C(void **p, int x);
void *func_021D6D7C(u8 *p);
void func_021D6D80(void *a,int b,u8 *p);
void func_021D6DB4(void *a, int *state);
void func_021D6DF4(void *a, int *state);
void func_021D6E3C(void *task,u32 *state,u8 *p);
void func_021D72F0(void *a, int *state, char *p);
void func_021D73DC(void *task,u32 *state,u8 *p);
void func_021D7814(void *task,u32 *state,u8 *p);
void func_021D7B4C(void *task,u32 *state,u8 *p);
void func_021D7CF4(void *task,u32 *state,u8 *p);
void func_021D7EAC(void *task,u32 *state,u8 *p);
void func_021D80C0(void *p,int n,char *q);
void func_021D80F0(void *a, int *state, u8 *p);
void func_021D8138(u8 *p, int unused, int heap);
void func_021D8198(char *p);
void func_021D81B0(u8 *p,u32 which,int heap);
void func_021D8380(char *p);
int func_021D83B0(char *p);
void func_021D83CC(char *p);
void func_021D83DC(u8 *p,int heap);
void func_021D849C(char *p);
void func_021D84D4(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *a5,void *a6,u16 heap);
void func_021D8C1C(u8 *p,int mode);
void func_021D8CA8(u8 *p);
void func_021D8D00(char *p);
int func_021D8D18(char *p);
void func_021D8D1C(u8 *p);
void func_021D8EA4(u8 *p);
void func_021D9138(u8 *p);
void func_021D91BC(u8 *p,void *q,u16 h);
void func_021D9228(void *p);
void func_021D9238(char *p);
void func_021D9254(char *p,int n);
void func_021D9288(unsigned *p,unsigned v);
void func_021D928C(u8 *p);
void func_021D933C(u8 *p);
void func_021D93F4(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap);
void func_021D9488(void **p);
int func_021D94B8(char *p);
unsigned func_021D94C4(int id,int heap);
int func_021D9554(char *p,int n);
void func_021D9580(void);
extern char ov114_id[];
extern char ov_id[];
extern const char d_021DFB80[];
extern const int gNetSaveMainProc[];
extern char ov115_id[];
extern const Config_021D83DC d_021DF544;
extern const u16 d_021DF4F2[];
extern const u32 d_021DF4FC[];
extern const u8 d_0209DF08;
extern const u8 d_0209DF0C;
extern void *g_020A7370;
extern const int d_021DF5E4[];





int func_021D6660(void *a, u32 b, u32 c)
{
    u8 *p;
    func_02034AC4((int)ov114_id);
    func_0203064C(1, 29, 0xA0000);
    p = func_0203159C(a, 0x69C, 29);
    func_02082BCC(p, 0, 0x69C);
    *(u32 *)(p + 0x3B4) = c;
    *(void **)(p + 0x3B8) = GAME_DATA_Create(29);
    *(void **)(p + 0x3BC) = func_0200A300(func_02012EBC(*(void **)(p + 0x3B8)), (void *)1, (void *)29);
    *(u8 **)(p + 0x394) = func_021D9624(1, 29);
    func_021D6924((u16 *)(p + 0x390), 29);
    func_021D6AEC((char *)(p + 0x294), (void *)func_021D9744((char *)*(u8 **)(p + 0x394)), 29);
    *(void **)(p + 0x398) = func_0201D7EC(23, 0, 0, 0, 29);
    *(u32 *)(p + 0x39C) = func_0201C440((void *)29);
    *(void **)(p + 0x3A4) = func_02045B38(0, 2, 0x50, 29);
    *(void **)(p + 0x3A0) = func_02045B38(0, 3, 0x9E, 29);
    *(void **)(p + 0x3A8) = func_0201EC64(29);
    *(void **)(p + 0x290) = func_021DA854(p, (void *)func_021D6D80, 29);
    *(void **)(p + 0x284) = func_021D9CA4(1, 15, *(void **)(p + 0x39C), *(void **)(p + 0x398), 29);
    func_021D9FFC(*(u8 **)(p + 0x284), 10, 14);
    *(void **)(p + 0x3B0) = func_021DE2A0(func_02012EBC(*(void **)(p + 0x3B8)), 29);
    func_021D91BC(p + 0x138, p + 0x294, 29);
    func_021D9254((char *)p + 0x138, 0);
    func_021D9288((unsigned int *)(p + 0x138), 1);
    GFL_USE_CancelChangeAndPlayBgm(1154, 0xFFFF);
    return 1;
}





int func_021D67D4(void *a, int b, int c, char *p)
{
    func_021D9228(p + 0x138);
    func_021DE2F0(((struct Obj02176 *)p)->f3B0);
    if (((struct Obj02176 *)p)->f284) func_021D9E04(((struct Obj02176 *)p)->f284);
    func_021DA890(((struct Obj02176 *)p)->f290);
    func_0201ED04(((struct Obj02176 *)p)->f3A8);
    func_02045C04(((struct Obj02176 *)p)->f3A0);
    func_02045C04(((struct Obj02176 *)p)->f3A4);
    func_0201C4C0(((struct Obj02176 *)p)->f39C);
    func_0201D83C(((struct Obj02176 *)p)->f398);
    func_021D6C28((u8 *)(p + 0x294));
    func_021D6948(p + 0x390);
    func_021D96C4(((struct Obj02176 *)p)->f394);
    func_0200A338(((struct Obj02176 *)p)->f3BC);
    GAME_DATA_Delete(((struct Obj02176 *)p)->f3B8);
    func_020315D4(a);
    func_020306F0(29);
    func_02087BCC(0);
    func_02034A5C((int)ov_id);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}





/*
 * follower: two zero padding bytes at 0x021D6922.
 */
int func_021D6888(int a, int b, int c, char *p)
{
    func_021DE300(((struct Obj01402 *)p)->f3B0);
    func_021DA898(((struct Obj01402 *)p)->f290);
    if (((struct Obj01402 *)p)->f394) {
        func_021D9718(((struct Obj01402 *)p)->f394);
        func_021D972C(((struct Obj01402 *)p)->f394);
        func_021D9738(((struct Obj01402 *)p)->f394);
    }
    func_021D9238(p + 0x138);
    func_0201C4E4(((struct Obj01402 *)p)->f39C);
    if (((struct Obj01402 *)p)->f284) func_021D9E50(((struct Obj01402 *)p)->f284);
    if (((struct Obj01402 *)p)->f28C) func_021DA2C8(((struct Obj01402 *)p)->f28C);
    if (((struct Obj01402 *)p)->f288) func_021DA2C8(((struct Obj01402 *)p)->f288);
    if (((struct Obj01402 *)p)->f270) func_021DA840(*(void ** *)&((struct Obj01402 *)p)->f270);
    if (func_021DA8AC(((struct Obj01402 *)p)->f290)) return 1;
    return 0;
}





/*
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021D6924(u16 *p,u16 heap)
{
    func_02082BCC(p,0,2);
    *p=heap;
    func_021D694C(p,0);
    func_02040588(6,1);
}





void func_021D6948(void *a0) { }





void func_021D694C(u16 *p,int mode)
{
    u16 heap=(*p&0x7fff)|0x8000;
    void *arc;
    switch (mode) {
    case 0:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,0,0,0,heap);
        func_02049B68(arc,6,4,0,128,heap);
        func_02049B68(arc,7,4,32,32,heap);
        func_02049658(arc,15,3,0,0,0,heap);
        func_02049658(arc,15,7,0,0,0,heap);
        func_020498F4(arc,31,3,0,0,0,heap);
        func_020498F4(arc,31,7,0,0,0,heap);
        func_02049238(arc);
        arc=func_020490F4(23,heap);
        func_02049B68(arc,5,0,480,32,heap);
        func_02049B68(arc,5,4,480,32,heap);
        func_02049238(arc);
        func_0201F5BC(1,10,14,0,heap);
        func_0201F5BC(0,1,13,0,heap);
        func_02040B94(1,32,0,heap);
        func_02040B94(0,32,0,heap);
        break;
    case 1:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,4,0,192,heap);
        func_02049658(arc,15,6,0,0,0,heap);
        func_020498F4(arc,21,6,0,0,0,heap);
        func_02049238(arc);
        break;
    case 2:
        arc=func_020490F4(34,heap);
        func_02049658(arc,11,2,0,0,0,heap);
        func_020498F4(arc,28,2,0,0,0,heap);
        func_02049238(arc);
        break;
    }
}





/*
 * follower: two zero padding bytes at 0x021D6C26.
 * lever: spell the object slot as p+i*4+16; data precedes allocation in local declarations.
 * interfaces: ABF0 and B294 leave r0 live and this caller consumes it despite legacy void definitions.
 */
void func_021D6AEC(char *p, void *owner, u16 heap)
{
    void *res;
    Record point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj01403 *)p)->f0=func_0204ABF0(arc,8,2,0,heap);
    *(int *)&((struct Obj01403 *)p)->f8=func_0204AF28(arc,34,37,heap);
    *(int *)&((struct Obj01403 *)p)->f4=func_0204A6C8(arc,16,0,2,heap);
    allocation=func_02049F78(arc,8,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22851 *)res)->fC;
    func_02082D44(data,p+0xda,32);
    data+=32;
    func_02082D44(data,p+0xba,32);
    func_020307B0(allocation);
    func_02049238(arc);
    func_02082BCC(&point,0,8);
    ((struct Obj01403 *)p)->fC=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->fC,0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=func_02005728(256);
        point.y=func_02005728(256)-bound;
        point.b=3;
        point.z=func_02005728(6)+3;
        *(void **)(p+i*4+16)=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
        func_0204B3DC(*(void **)(p+i*4+16),0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    ((struct Obj01403 *)p)->f94=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->f94,0);
}





void func_021D6C28(u8 *p)
{
    int i;
    void *q;
    for(i=0;i<35;i++){
        q=*(void **)(p+i*4+12);
        if(q) func_0204B3B4(q);
    }
    func_0204ADA4((u32)(((struct Obj10404 *)p)->f0));
    func_0204A8D4((u32)(((struct Obj10404 *)p)->f4));
    func_0204AFD8((u32)(((struct Obj10404 *)p)->f8));
}





void *func_021D6C58(u8 *p,int i) { return *(void **)(p+i*4+12); }





void func_021D6C60(u8 *p,int heap)
{
    void *out;
    void *raw;
    raw=func_02049F34(34,8,(u32)(&out),heap);
    func_0204ADEC(((struct Obj22852 *)p)->f0,out,7);
    func_020307B0(raw);
}





static inline int wrap(int n, u16 *p)
{
    if (*p + n >= 65536) return *p + n - 65536;
    return *(volatile u16 *)&((struct Obj10405 *)p)->f0 + n;
}





/*
 * follower: two zero padding bytes at 0x021D6CEA.
 * volatile: 0x021D6C8E and 0x021D6CA6 read the same halfword; only the latter access is volatile.
 */
void func_021D6C84(u8 *p)
{
    int i;
    ((struct Obj13938 *)p)->f98 = wrap(1024, (u16 *)(p + 0x98));
    for (i = 0; i < 5; i++)
        func_021DAAA4(14, (u16 *)(p + 0x9a) + i, ((struct Obj13938 *)p)->f98, 0, (u8)i, *(u16 *)(p + 0xba + i * 2), *(u16 *)(p + 0xda + i * 2));
}





void func_021D6CEC(u8 *p) { ((struct Obj22853 *)p)->f98=0; }





void func_021D6CF4(int *p, int heap)
{
    void *v;
    func_02082BCC(p, 0, 16);
    p[3] = 1;
    v = func_02030734(heap, 0x4800, 0, d_021DFB80, 0x482);
    p[2] = (int)v;
    p[0] = (int)func_02050C04((int)v, 0x4800, 1, heap);
}






/*
 * Addresses are Black-image addresses.
 */
void func_021D6D38(void *p)
{
    func_020307B0(((struct Obj22854 *)p)->f8);
    func_02082BCC(p, 0, 0x10);
}






/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void func_021D6D50(int *p, int a, int b, int c)
{
    int x = func_0205121C(a, b, c);
    func_02051230(*p, x, 1, 0);
}






int func_021D6D6C(void **p, int x)
{
    return func_020515CC(*p, x, 0, (int)p);
}





void *func_021D6D7C(u8 *p) { return ((struct Obj22857 *)p)->fC; }





void func_021D6D80(void *a,int b,u8 *p)
{
    func_021D9F08(*(u8 * *)&((struct Obj00326 *)p)->f284,((struct Obj00326 *)p)->f3A4,79,0);
    func_021D81B0(p,0,29);
    func_021DA8B0(a,(u32)func_021D6DB4);
}





void func_021D6DB4(void *a, int *state)
{
    switch (*state) {
    case 0: func_0204E720(3, 16, 0, 0); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2: func_021DA8B0(a, (u32)func_021D6E3C); break;
    }
}





void func_021D6DF4(void *a, int *state)
{
    switch (*state) {
    case 0: func_0204E720(12, 0, 16, 0); GFL_USE_FadeOutBgm(8); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2: func_021DA8B0(a, (u32)func_021D80C0); break;
    }
}





void func_021D6E3C(void *task,u32 *state,u8 *p)
{
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(W(968)) {W(968)=0;*state=2;break;}
        func_021D9F08(P(644),W(932),79,0);
        if(P(624)==0) func_021D81B0(p,0,29);
        *state=1;break;
    case 1:
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            func_021D8380((char *)p);
            flag=(MYSTERY_DATA_HasCardSpace(P(956))==0);
            if(flag) {
                for(i=0;i<MYSTERY_DATA_GetCardSlotNum(P(956));i++) {
                    if(func_0200A104(P(956),i)) all=0;
                }
            }
            if(flag) {
                if(all) {
                    if(MYSTERY_DATA_IsMainSave(P(956))==0) id=146;
                    else id=137;
                    func_021D9F08(P(644),W(932),id,1);
                    func_021DA8C0(task,0);*state=19;
                } else *state=16;
            } else {
                if(func_0202EB44()==0) func_021DA8B0(task,(u32)func_021D80F0);
                else *state=2;
            }
        } else if(v==1) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D7B4C);
        } else if(v==2) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D72F0);
        } else if(v==3) func_021DA8B0(task,(u32)func_021D6DF4);
        else break;
        }
        break;
    case 2:
        func_021D9F08(P(644),W(932),83,1);
        func_021DA8C0(task,3);*state=19;break;
    case 3:func_021D8138(p,0,29);*state=4;break;
    case 4:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:func_021DE308(P(944),1);*state=6;break;
    case 6:if(func_021DE3E0(P(944))==2) *state=7;break;
    case 7:
        func_021D8380((char *)p);func_021D81B0(p,1,29);
        func_021D9F08(P(644),W(932),86,0);*state=8;break;
    case 8:
        if(((u32)func_021DE4D8(P(944)))&32) func_021DA84C(P(624),0,1);
        else func_021DA84C(P(624),0,0);
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        func_021D8380((char *)p);
        switch(v) {
        case 0:W(940)=0;*state=9;break;
        case 1:W(940)=1;*state=12;break;
        case 2:W(940)=2;*state=9;break;
        case 3:*state=14;break;
        }
        }
        break;
    case 9:
        switch(W(940)) {
        case 0:func_021D9F08(P(644),W(932),96,1);func_021DA8C0(task,10);*state=19;break;
        case 1:break;
        case 2:func_021D9F08(P(644),W(932),102,1);func_021DA8C0(task,10);*state=19;break;
        }
        break;
    case 10:func_021D8138(p,0,29);*state=11;break;
    case 11:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(func_021DE3E0(P(944))==2) {func_021DE308(P(944),3);*state=13;}
        break;
    case 13:
        if(func_021DE3E0(P(944))==0) {
            if(W(940)==1) func_021DA8B0(task,(u32)func_021D7EAC);
            else func_021DA8B0(task,(u32)func_021D73DC);
        }
        break;
    case 14:
        if(func_021DE3E0(P(944))==2) {func_021DE308(P(944),3);*state=15;}
        else *state=0;
        break;
    case 15:if(func_021DE3E0(P(944))==0) *state=0;break;
    case 16:
        func_021D9F08(P(644),W(932),141,1);
        func_021DA8C0(task,17);*state=19;break;
    case 17:func_021D8138(p,0,29);*state=18;break;
    case 18:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) func_021DA8B0(task,(u32)func_021D7CF4);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(func_021D9FF8(P(644))) func_021DA8C4(task);break;
    }
}




void func_021D72F0(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 126, 0);
        func_021D81B0((u8 *)p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = func_021D83B0(p);
        if (result == -1) break;
        func_021D8380(p);
        if (result == 0) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 132, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 1) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 133, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 2) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 134, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 3) {
            func_021DA8B0(a, (u32)func_021D6E3C);
        }
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00326 *)p)->f284)) func_021DA8C4(a);
        break;
    }
}




void func_021D73DC(void *task,u32 *state,u8 *p)
{
    int v,flag;
    Date date;
    switch(*state) {
    case 0:
        switch(W(940)) {
        case 1:func_021DE308(P(944),4);break;
        case 0:func_021DE308(P(944),7);break;
        case 2:func_021DE308(P(944),10);break;
        }
        func_021D9F08(P(644),W(932),105,0);
        W(964)=0;*state=1;break;
    case 1:
        if(func_021DE3E0(P(944))==0) {
            v=func_021DE4DC(P(944),p+972,720);
            if(v==1) {
                v=func_021DEF6C((char *)p+972,P(952),32797);
                if(func_021D9554((char *)(p+972),v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=func_021DE500(P(944));
        switch(v) {case 1:case 2:func_021DE550(P(944));func_021DA8B0(task,(u32)func_021D6E3C);break;}
        if((func_020362DC()&2) || W(964)++>7200) {
            flag=0;
            switch(W(940)) {
            case 1:
                if(func_021DE3E0(P(944))==4) {func_021DE308(P(944),5);flag=1;}break;
            case 0:
                if(func_021DE3E0(P(944))==8) {func_021DE308(P(944),9);flag=1;}break;
            case 2:
                if(func_021DE3E0(P(944))==11) {func_021DE308(P(944),12);flag=1;}break;
            }
            if(flag) {*state=2;W(964)=0;}
        }
        break;
    case 2:
        func_021D9F08(P(644),W(932),136,2);
        func_021DA8C0(task,3);*state=14;break;
    case 3:
        W(964)++;
        if(func_021DE3E0(P(944))==0 && W(964)>30) {
            W(964)=0;
            func_021D9F08(P(644),W(932),139,1);
            func_021DA8C0(task,4);*state=14;
        }
        break;
    case 4:func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 5:
        func_021D81B0(p,2,29);func_021D83DC(p,29);
        func_021D9F08(P(644),W(932),106,0);*state=6;break;
    case 6:
        flag=0;v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            func_021D9F08(P(644),W(932),110,1);
            func_021DA8C0(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(func_020362DC()&2) flag=1;
        if(flag) {
            func_021D9F08(P(644),W(932),107,1);
            func_021DA8C0(task,9);*state=14;
        }
        break;
    case 7:func_021D8138(p,0,29);*state=8;break;
    case 8:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);
                if(((Flag *)(p+1152))->bit && MYSTERY_DATA_IsEventFlag(P(956),((struct Obj13939 *)p)->f47C)) {*state=11;break;}
                func_0203F4E4((struct RtcDate *)(&date));
                W(1144)=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                MYSTERY_DATA_AddCard(P(956),p+972);
                MYSTERY_DATA_SetEventFlag(P(956),((struct Obj13939 *)p)->f47C);
                func_021DA8B0(task,(u32)func_021D7814);
            } else if(v==1) *state=5;
        }
        break;
    case 9:func_021D8138(p,0,29);*state=10;break;
    case 10:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) {
                func_021D8380((char *)p);func_021D849C((char *)p);
                func_021DA8B0(task,(u32)func_021D6E3C);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        func_021D9F08(P(644),W(932),138,1);
        func_021DA8C0(task,13);*state=14;break;
    case 12:
        func_021D9F08(P(644),W(932),144,1);
        func_021DA8C0(task,13);*state=14;break;
    case 13:
        func_021D8380((char *)p);func_021D849C((char *)p);
        func_021DA8B0(task,(u32)func_021D6E3C);break;
    case 14:
        if(func_021D9FF8(P(644))) func_021DA8C4(task);
        break;
    }
}




/*
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 */
void func_021D7814(void *task,u32 *state,u8 *p)
{
    Desc_021D7814 d;
    switch (*state) {
    case 0:
        func_021D9750(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        func_021D84D4(p+12,(void *)func_021D9744(((struct Obj00297 *)p)->f394),p+972,(void *)(*(int *)&((struct Obj00297 *)p)->f3B8),p+660,p+912,p+312,29);
        func_021D8C1C(p+12,0);
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,113,2);
        *state=1;
        break;
    case 1:
        func_02040588(0,1);
        *state=2;
        break;
    case 2:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=3;
        break;
    case 3:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=4;
        break;
    case 4:
        MYSTERY_DATA_SaveStart(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8));
        *state=5;
        break;
    case 5:
        if (MYSTERY_DATA_SaveMain(((struct Obj00297 *)p)->f3BC,(int)(((struct Obj00297 *)p)->f3B8))==2) *state=6;
        break;
    case 6:
        func_021D8C1C(p+12,1);
        *state=7;
        break;
    case 7:
        func_021D8D00((char *)(p+12));
        if (func_021D8D18((char *)(p+12))) *state=8;
        break;
    case 8:
        func_021D9F08(((struct Obj00297 *)p)->f284,((struct Obj00297 *)p)->f3A4,114,1);
        *state=9;
        break;
    case 9:
        if (func_021D9FF8(((struct Obj00297 *)p)->f284)) *state=10;
        break;
    case 10:
        func_021D8CA8(p+12);
        func_021D9E04(((struct Obj00297 *)p)->f284);
        ((struct Obj00297 *)p)->f284=0;
        func_021D8380((char *)p);
        *(volatile u16 *)0x04000050=0;
        func_021D9790(((struct Obj00297 *)p)->f394);
        func_02040588(1,1);
        func_02040588(3,1);
        *state=11;
        break;
    case 11:
        func_02040588(0,1);
        *state=12;
        break;
    case 12:
        func_02040588(1,0);
        func_02082BCC(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)func_021D9744(((struct Obj00297 *)p)->f394);
        d.w[7]=*(u32 *)&((struct Obj00297 *)p)->f3BC;
        d.w[8]=*(u32 *)&((struct Obj00297 *)p)->f3A4;
        d.w[9]=((struct Obj00297 *)p)->f398;
        d.w[10]=((struct Obj00297 *)p)->f39C;
        d.w[11]=((struct Obj00297 *)p)->f3A8;
        ((struct Obj00297 *)p)->f4=func_021DCFC8(&d,29);
        ((struct Obj00297 *)p)->f0=func_021DD24C(p+972,((struct Obj00297 *)p)->f4,((struct Obj00297 *)p)->f3B8,29);
        MYSTERY_ALBUM_RequestSetup(((struct Obj00297 *)p)->f0,0);
        *state=13;
        break;
    case 13:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        MYSTERY_ALBUM_StartIntro(((struct Obj00297 *)p)->f0);
        *state=14;
        break;
    case 14:
        MYSTERY_ALBUM_StepIntro(((struct Obj00297 *)p)->f0);
        if (MYSTERY_ALBUM_IsIntroIdle(((struct Obj00297 *)p)->f0)) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=15;
        }
        break;
    case 15:
        if (func_020362DC()&1) *state=18;
        if ((((struct Obj00297 *)p)->f3C4)++>240) {
            ((struct Obj00297 *)p)->f3C4=0;
            *state=16;
        }
        break;
    case 16:
        func_021D93F4(p+612,p+660,(int)func_021D9744(((struct Obj00297 *)p)->f394),*(int *)&((struct Obj00297 *)p)->f39C,((struct Obj00297 *)p)->f3A4,155,*(int *)&((struct Obj00297 *)p)->f398,29);
        func_021D94B8((char *)(p+612));
        *state=17;
        break;
    case 17:
        func_021D94B8((char *)(p+612));
        if (func_020362DC()&1) {
            func_021D9488((void **)(p+612));
            *state=18;
        }
        break;
    case 18:
        func_021DA8B0(task,(u32)func_021D6DF4);
        break;
    }
}




void func_021D7B4C(void *task,u32 *state,u8 *p)
{
    Desc_021D7B4C d;
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,-1);
        func_021DA8C0(task,1);
        *state=8;
        break;
    case 1:
        func_021D9288((unsigned int *)(p+312),0);
        func_021D8380((char *)p);
        func_021D9E04(((struct Obj00989 *)p)->f284);
        ((struct Obj00989 *)p)->f284=0;
        func_02082BCC(&d,0,36);
        d.w[0]=0;
        d.w[2]=(u32)func_021D9744(((struct Obj00989 *)p)->f394);
        d.w[3]=((struct Obj00989 *)p)->f3BC;
        d.w[4]=*(u32 *)&((struct Obj00989 *)p)->f398;
        d.w[5]=*(u32 *)&((struct Obj00989 *)p)->f39C;
        d.w[6]=((struct Obj00989 *)p)->f3A8;
        d.w[7]=((struct Obj00989 *)p)->f3A4;
        d.w[8]=((struct Obj00989 *)p)->f3B8;
        ((struct Obj00989 *)p)->f8=func_021DAC18(&d,29);
        *state=2;
        break;
    case 2:
        func_0204E720(3,16,0,-1);
        func_021DA8C0(task,3);
        *state=8;
        break;
    case 3:
        func_021DAEF0(((struct Obj00989 *)p)->f8);
        if(func_021DB008(((struct Obj00989 *)p)->f8)) *state=4;
        break;
    case 4:
        func_0204E720(3,0,16,0);
        func_021DA8C0(task,5);
        *state=8;
        break;
    case 5:
        func_021D9288((unsigned int *)(p+312),1);
        func_021DAE1C(((struct Obj00989 *)p)->f8);
        ((struct Obj00989 *)p)->f8=0;
        func_021D694C((u16 *)(p+912),0);
        func_021D6C60(p+660,29);
        ((struct Obj00989 *)p)->f284=func_021D9CA4(1,15,((struct Obj00989 *)p)->f39C,((struct Obj00989 *)p)->f398,29);
        func_021D9FFC(((struct Obj00989 *)p)->f284,10,14);
        func_021D81B0(p,0,29);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        *state=6;
        break;
    case 6:
        func_0204E720(3,16,0,0);
        func_021DA8C0(task,7);
        *state=8;
        break;
    case 7:
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    case 8:
        if(!func_0204E804()) func_021DA8C4(task);
        break;
    }
    if(((struct Obj00989 *)p)->f8) func_021DAFCC(((struct Obj00989 *)p)->f8);
}



void func_021D7CF4(void *task,u32 *state,u8 *p)
{
    Desc_021D6660 d;
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,-1);
        func_021DA8C0(task,1);
        *state=8;
        break;
    case 1:
        func_021D9288((unsigned int *)(p+312),0);
        func_021D8380((char *)p);
        func_021D9E04(((struct Obj00827 *)p)->f284);
        ((struct Obj00827 *)p)->f284=0;
        func_02082BCC(&d,0,36);
        d.w[0]=1;
        d.w[2]=(u32)func_021D9744(((struct Obj00827 *)p)->f394);
        d.w[3]=*(u32 *)&((struct Obj00827 *)p)->f3BC;
        d.w[4]=*(u32 *)&((struct Obj00827 *)p)->f398;
        d.w[5]=*(u32 *)&((struct Obj00827 *)p)->f39C;
        d.w[6]=((struct Obj00827 *)p)->f3A8;
        d.w[7]=((struct Obj00827 *)p)->f3A4;
        d.w[8]=((struct Obj00827 *)p)->f3B8;
        ((struct Obj00827 *)p)->f8=func_021DAC18((Desc_021D7B4C *)&d, 29);
        *state=2;
        break;
    case 2:
        func_0204E720(3,16,0,-1);
        func_021DA8C0(task,3);
        *state=8;
        break;
    case 3:
        func_021DAEF0(((struct Obj00827 *)p)->f8);
        if(func_021DB008(((struct Obj00827 *)p)->f8)) *state=4;
        break;
    case 4:
        func_0204E720(3,0,16,0);
        func_021DA8C0(task,5);
        *state=8;
        break;
    case 5:
        func_021D9288((unsigned int *)(p+312),1);
        func_021DAE1C(((struct Obj00827 *)p)->f8);
        ((struct Obj00827 *)p)->f8=0;
        func_021D694C((u16 *)(p+912),0);
        func_021D6C60(p+660,29);
        ((struct Obj00827 *)p)->f284=func_021D9CA4(1,15,((struct Obj00827 *)p)->f39C,((struct Obj00827 *)p)->f398,29);
        func_021D9FFC(((struct Obj00827 *)p)->f284,10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_021D81B0(p,0,29);
        *state=6;
        break;
    case 6:
        func_0204E720(3,16,0,0);
        func_021DA8C0(task,7);
        *state=8;
        break;
    case 7:
        ((struct Obj00827 *)p)->f3C8=(void *)MYSTERY_DATA_HasCardSpace(((struct Obj00827 *)p)->f3BC);
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    case 8:
        if(!func_0204E804()) func_021DA8C4(task);
        break;
    }
    if(((struct Obj00827 *)p)->f8) func_021DAFCC(((struct Obj00827 *)p)->f8);
}



void func_021D7EAC(void *task,u32 *state,u8 *p)
{
    int result;
    result=func_021DE500(((struct Obj00533 *)p)->f3B0);
    switch(result) {
    case 1: case 2:
        func_021DE550(((struct Obj00533 *)p)->f3B0);
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    }
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,0);
        *state=1; return;
    case 1:
        if(!func_0204E804()) {
            func_021D9288((unsigned int *)(p+312),0);
            *state=2; return;
        }
        break;
    case 2:
        if(((struct Obj00533 *)p)->f284) {
            func_021D9E04(((struct Obj00533 *)p)->f284);
            ((struct Obj00533 *)p)->f284=0;
        }
        func_021D6C28(p+660);
        func_021D6948(p+912);
        func_021D96C4(((struct Obj00533 *)p)->f394);
        ((struct Obj00533 *)p)->f394=0;
        *state=3; return;
    case 3:
        *(u8 * *)&((struct Obj00533 *)p)->f3C0=func_02030734(29,40,0,d_021DFB80,2664);
        func_02082BCC(((struct Obj00533 *)p)->f3C0,0,40);
        ((struct Obj22858 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f0=((struct Obj00533 *)p)->f3B8;
        ((struct Obj22859 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f4=0;
        ((struct Obj22860 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f8=1;
        ((struct Obj22861 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f10=0;
        ((struct Obj22862 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f18=0;
        ((struct Obj22863 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->fC=9;
        if(!MYSTERY_DATA_IsMainSave(((struct Obj00533 *)p)->f3BC)) ((struct Obj22864 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=2;
        else ((struct Obj22865 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f14=0;
        PROCSYS_PushGlobal((u32)ov115_id,(u32)gNetSaveMainProc,(u32)((struct Obj00533 *)p)->f3C0);
        *state=5; return;
    case 5:
        ((struct Obj00533 *)p)->f394=func_021D9624(1,29);
        func_021D6924((u16 *)(p+912),29);
        func_021D6AEC((char *)(p+660),(void *)func_021D9744(((struct Obj00533 *)p)->f394),29);
        ((struct Obj00533 *)p)->f284=func_021D9CA4(1,15,((struct Obj00533 *)p)->f39C,((struct Obj00533 *)p)->f398,29);
        func_021D9FFC(((struct Obj00533 *)p)->f284,10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_0203D34C(1,29);
        GFL_USE_CancelChangeAndPlayBgm(1154,65535);
        func_021D9288((unsigned int *)(p+312),1);
        *state=4; return;
    case 4:
        *state=6; return;
    case 6:
        func_0204E720(3,16,0,0);
        *state=7; return;
    case 7:
        if(!func_0204E804()) { *state=8; return; }
        break;
    case 8:
        if(!((struct Obj22866 *)(*(u8 * *)&((struct Obj00533 *)p)->f3C0))->f1C) func_021DA8B0(task,(u32)func_021D73DC);
        else func_021DA8B0(task,(u32)func_021D6E3C);
        func_020307B0(((struct Obj00533 *)p)->f3C0);
        break;
    }
}



void func_021D80C0(void *p,int n,char *q) {
 func_021D8198(q);func_021D8380(q);func_021D849C(q);
 if(*(char * *)&((struct Obj00326 *)q)->f0) {MYSTERY_ALBUM_Delete(*(char * *)&((struct Obj00326 *)q)->f0);func_021DD1FC(*(void ** *)&((struct Obj00326 *)q)->f4);}
 func_021DA8B8(p);
}



void func_021D80F0(void *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_021D9F08(*(u8 * *)&((struct Obj10409 *)p)->f284, ((struct Obj10409 *)p)->f3A0, 22, 1); *state = 1; break;
    case 1: if (func_021D9FF8(((struct Obj10409 *)p)->f284)) func_021DA8B0(a, (u32)func_021D6E3C); break;
    }
}


/*
 * follower: two zero padding bytes at 0x021D8196.
 */
void func_021D8138(u8 *p, int unused, int heap)
{
    Config_021D8138 c;
    if (*(int *)&((struct Obj00326 *)p)->f260 == 0) {
        func_02082BCC(&c, 0, 0x24);
        c.f0 = ((struct Obj00326 *)p)->f3A4;
        c.f4 = *(int *)&((struct Obj00326 *)p)->f398;
        c.f8 = *(int *)&((struct Obj00326 *)p)->f39C;
        c.fc = 0x54;
        c.f10 = 0x55;
        c.f18 = 2;
        c.f1c = 0;
        c.f1e = 15;
        c.f20 = 14;
        c.f22 = 1;
        ((struct Obj00326 *)p)->f260 = func_021DA038(&c, heap);
    }
}



void func_021D8198(char *p)
{
    void *x = ((struct Obj00326 *)p)->f260;
    if (x != 0) {
        func_021DA148(x);
        *(u32 *)&((struct Obj00326 *)p)->f260 = 0;
    }
}


void func_021D81B0(u8 *p,u32 which,int heap)
{
    Desc_021D8138 d;
    void *archive;
    int i;
    if(((struct Obj00326 *)p)->f270) return;
    func_02082BCC(&d,0,64);
    d.w[1]=((struct Obj00326 *)p)->f398;
    d.w[2]=((struct Obj00326 *)p)->f39C;
    d.w[3]=(u32)func_021D6C58(p+660,0);
    d.h[0]=1;
    d.h[1]=15;
    d.h[2]=2;
    d.h[3]=4;
    d.callback=func_021D83CC;
    d.arg=p;
    d.h[4]=0;
    d.h[5]=0;
    d.h[6]=0;
    d.result=p+628+which*4;
    switch(which) {
    case 0:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=80; d.w[5]=81; d.w[6]=131; d.w[7]=82; d.w[8]=4;
        break;
    case 1:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=87; d.w[5]=88; d.w[6]=89; d.w[7]=90; d.w[8]=4;
        break;
    case 2:
        d.w[0]=0;
        d.w[4]=(u32)func_020457B0(37,heap);
        func_02045994((struct Strbuf *)d.w[4],(const u16 *)(p+1068),37);
        d.w[8]=1;
        d.h[4]=-1;
        d.h[5]=-2;
        d.h[6]=10;
        break;
    case 3:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=127; d.w[5]=128; d.w[6]=129; d.w[7]=130; d.w[8]=4;
        break;
    }
    archive=func_020490F4(34,heap);
    func_02049B68(archive,6,0,0,160,heap);
    func_02049658(archive,15,2,0,0,0,heap);
    if(which==2) func_0204989C(34,30,2,0,0,0,heap);
    else func_0204989C(34,29,2,0,0,0,heap);
    func_02049238(archive);
    func_020413B0(2,0,0,32,24,4);
    func_020409B4(2);
    func_02040588(2,1);
    ((struct Obj00326 *)p)->f270=func_021DA4DC(&d,heap);
    if(!d.w[0]) {
        for(i=0;i<4;i++) {
            if(d.w[4+i]) func_02045808((void *)d.w[4+i]);
        }
    }
    func_0207D63C((void *)0x04000050,4,24,15,3);
    func_021D6CEC(p+660);
}


void func_021D8380(char *p) {
 if(((struct Obj00326 *)p)->f270!=0) {func_020414EC(2);func_020409B4(2);func_02040588(2,0);func_021DA698(((struct Obj00326 *)p)->f270);*(unsigned *)&((struct Obj00326 *)p)->f270=0;}
}


int func_021D83B0(char *p) {
 int n=func_021DA6D0(*(unsigned char * *)&((struct Obj00326 *)p)->f270);
 func_021D6C84((u8 *)(p+0x294));
 return n;
}


/*
 * leaf: sole callback blocker of 021D81B0; root claim granted.
 */
void func_021D83CC(char *p)
{
    func_021D6CEC((u8 *)(p+660));
}


/*
 * volatile: hardware argument 04001050 passed to blend helper
 */
void func_021D83DC(u8 *p,int heap)
{
    Config_021D83DC c;
    if(((struct Obj06446 *)p)->f28C==0) {
        c=d_021DF544;
        c.w[2]=(int)func_020457B0(37,heap);
        func_02045994((struct Strbuf *)c.w[2],(const unsigned short *)(p+1068),37);
        c.w[8]=(int)func_020457B0(253,heap);
        func_02045994((struct Strbuf *)c.w[8],(const unsigned short *)(p+1180),253);
        ((struct Obj06446 *)p)->f28C=func_021DA1BC(0,&c,2,4,15,((struct Obj06446 *)p)->f39C,((struct Obj06446 *)p)->f3A4,((struct Obj06446 *)p)->f398,heap);
        func_02045808((void *)c.w[2]);
        func_02045808((void *)c.w[8]);
        func_021D694C((u16 *)(p+912),1);
        func_020409B4(6);
        func_02040588(6,1);
        func_0207D63C((void *)0x04001050,4,24,15,3);
    }
}


void func_021D849C(char *p) {
 if(((struct Obj00326 *)p)->f28C) {
  *(unsigned short *)0x04001050=0;
  func_021DA2A8(((struct Obj00326 *)p)->f28C);func_021DA280(((struct Obj00326 *)p)->f28C);
  *(unsigned *)&((struct Obj00326 *)p)->f28C=0;
  func_020409B4(4);func_02040588(6,0);
 }
}


/*
 * note 2026-10-05 (wave D9r lane P7): real extent is 0x744 bytes (1860); the 2004-byte
 *   listing extent includes the filed follower func_021D8C1C. Compiled size now equals
 *   the original (1860 bytes); 1055 concrete bytes still differ, almost all from two
 *   small layout residues that shift every later branch target by 2 bytes.
 *   Fixed this wave (from the older draft in docs/notes/pkt_ov121_021D84D4.c.txt):
 *   frame 0x64 -> 0x68 and push {r3-r7} (clamp local zero, arc spilled to its slot,
 *   zero set after the 0202D8D0 statement so the scheduler hoists it next to the call);
 *   D(8) tested as if(D(8)!=0) first (gives the beq over a lone b stub);
 *   the desc[90] > 2 arm written A-first (if(v<=2) set(v); else {v=f(); set(v);}) gives
 *   the bhi over b with the tail cross-jumped; the H(30)==0 failure block written inline
 *   with the failed label inside it; ability default is mon=0; goto image (original
 *   skips the free); move[i] read as a raw u16 at base+i*2 gives add sp/adds #2/ldrh [r0,r1].
 *   Remaining residue: (1) the default arm and the H(74)==0 arm are single b stubs into
 *   the H(30) failure block in the original (b 3F2 and b 3EC); here the copies are not
 *   cross-jumped (default keeps movs r6 + b, H(74) is a plain beq); (2) 02017588's
 *   arguments load id before level in the original (ldr r2,[sp,#0x1c] then r1); (3) the
 *   0186C8 call argument order: original stores [sp,#4] before the zero high word
 *   [sp,#0x34] and loads r2 after the lsls; (4) str r7,[sp] (day) comes after the r2/r3
 *   setup before 0202F2AC in the original.
 *   Tried (about 18 compiles): u64 id local (worse, 1165), separate move array (worse),
 *   separate base local for 020185F0 (no change), pragma scheduling off (no change),
 *   H74 arm written out (merges only blx..b, +8 bytes), value arm B-first (no b stub).
 *   Idioms checked: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy
 *   (default/H74 stubs still not merged), a-shared-exit-block-is-written-out-in-each-arm
 *   (gave the D8 and value stubs), two-arms-write-the-tail-out-and-the-third-branches-back-into-one
 *   (H74 copy not merged), a-call-before-a-goto-into-the-shared-tail-is-cross-jumped-to-its-bl (no).
 *   Callee prototypes: 020185F0 returns its argument in r0 (stub bx lr), as in the older draft.
 *   Pragma check (per brief): opt_lifetimes off 994 B differ (1864 size), opt_propagation off 1719,
 *   opt_common_subs off 1422, opt_dead_assignments off 1055, peephole off 1055, scheduling off no change.
 *   None closes it, so none is filed. Total compiles this lane: 24.
 * note 2026-10-05 (wave D9r lane P7b): 1055 -> 32 concrete bytes differ (size 1864 = the
 *   real extent; the final literal 0x2CA at +0x744 is shared with the original). Fix: the H(74)==0
 *   arm is a written-out copy of the failure block, `if(H(74)==0){func_020307B0(allocated);mon=0;
 *   goto image;}`, not `goto failed` (the copy is cross-jumped into the b stub, the ability
 *   default arm then also becomes the b stub, as in the original; matched twin
 *   ov010_func_02157E9C does the same for its nick and OT-name arms). Also id is now a u64 local
 *   with a separate u32 otId (`id = otId;` before 020173F0), day is u8, as in that twin.
 *   Residue (all instruction-order, no register or slot difference): (1) 020173F0 loads r1 (level)
 *   before r2 (id); (2) 0186C8 arms: ldrb r2,[desc+0x1c] and the str [sp,4]/[sp,0x34] order;
 *   (3) str r7,[sp] (day) before the r2/r3 setup of 0202F2AC instead of last.
 *   Tried this lane (about 17 compiles, plus a static inline wrapper for 0202F2AC (identical)): `default: goto nomon;` with a label inside the
 *   H(30) block (mwcc hangs, killed), function-level labels (default becomes bls table; b, worse),
 *   020173F0 prototype with u16 level (adds lsls/lsrs, worse), u16 level local (slot order
 *   changes, worse), static inline wrapper for 020173F0 (identical output), passing otId
 *   instead of id (identical), 020186C8 third parameter u8 (identical), u8 day (identical),
 *   pragma scheduling off and peephole off (identical). Non-const desc fixes the ldrb placement
 *   in the 0186C8 arms but hoists str [sp,4] above the species load and moves the H(26) load in
 *   02017588 (36 bytes, not kept). Idioms checked: a-conditional-branch-onto-an-unconditional-b-
 *   is-a-cross-jumped-tail-copy (the written-out copy form closes the stubs), a-goto-join-loses-
 *   the-registers-that-repeating-the-tail-in-each-arm-keeps (goto failed loses the stub),
 *   an-inline-wrappers-arguments-are-evaluated-last-to-first (no change),
 *   an-inline-call-argument-is-scheduled-per-site-a-local-is-not (no change),
 *   a-jump-table-bounds-check-turns-into-bls-and-b-when-the-default-is-out-of-range (explains
 *   the default b stub being local).
 * note 2026-10-05 (wave D9r lane P7c): 32 -> 14 concrete bytes differ (size 1864). Fixes from
 *   the matched twins (ov010 02157E9C, ov121 021DD24C): (a) gender is u8, ability and selector
 *   u32 (twin locals; cleared the whole 0186C8 arm residue, 14 B); (b) 020173F0 is called as
 *   in 021DD24C with an explicit zero high word and a u16 level: proto (u16,u16,u32,u32,u32),
 *   call f(species,level,otId,0,tag), with `id=otId;` just before it (the u64 copy is only for
 *   02017588), and level and tag are u16 locals (this gave the original r2-before-r1 loads and
 *   the slot order; a u32 level or the 4-arg u64 form load r1 first).
 *   Remaining residue (one hunk, 2 instructions): `str r7,[sp]` (day) before the call to
 *   0202F2AC sits right after the bl of 020185F0 here; the original (and the twin) emit it
 *   last, after `adds r1,r6,#0`. Tried this lane (about 20 compiles, all no change unless
 *   noted): place as ternary, place inline in the call, u16 place, int w = D(172) date word,
 *   u32 day, day declared first, 0202F2AC proto with u8 day (same), proto u16,u16,u8,u8 (worse),
 *   day inline as (u8)D(172) (worse, 47), place before the date block (worse), day after place
 *   (worse), pragma scheduling off and peephole off (no change).
 *   Idioms checked: a-spilled-constant-high-word-is-a-u32-copied-into-a-u64-before-the-call
 *   (already applied: closed the id copy, and its twin gave the explicit-0 call form).
 * note 2026-10-05 (wave D9r lane P7d): CLOSED, EXACT* (c99 and c). 14 -> 0 B. The date
 *   year local is u32 (`u32 year;` with `year=(u16)((int)D(172)>>16)`), not u16: a spilled
 *   narrow local keeps its reload below the outgoing stack-argument store, a spilled u32
 *   local has its reload hoisted above it, so `str r7,[sp]` (day) now comes last, after
 *   `adds r1,r6,#0`, as in the original (docs/idioms/a-reload-kept-below-outgoing-stack-
 *   stores-is-a-narrow-local.md read the other way round). Compiles this lane: 3.
 */
void func_021D84D4(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *a5,void *a6,u16 heap)
{
    u32 palette;
    void *buf,*mon,*allocated,*str;
    u8 *base;
    int i;
    u32 selector;
    Work work;
    u32 arc;
    u32 month;
    u32 year;
    u32 ability;
    u8 gender;
    int clamp;
    u64 random;
    u32 species,otId;
    u16 level,tag;
    u64 id;
    u32 packed,j,place,value;
    u8 day;
    func_02082BCC(out,0,300);
    O(40)=(u32)a6;O(36)=(u32)a5;OH(0)=heap;O(276)=(u32)desc;OH(296)=0;OH(298)=0;
    if(desc[714]) palette=3;
    else palette=d_021DF4F2[desc[179]];
    buf=func_02049F34(34,2,(u32)&work.resdesc,heap);
    base=*(u8 **)((u8 *)work.resdesc+12);
    func_02082D44(base,out+146,32);
    func_02082D44(base+palette*32,out+114,32);
    func_020307B0(buf);
    for(i=0;i<32;i++) func_0204B6F4(func_021D6C58(list,i+1),(u8)palette,0);
    switch(desc[179]) {
    case 1:
        mon=0;
        tag=(u16)((heap&0x7FFF)|0x8000);
        level=desc[91];otId=D(0);species=H(26);gender=desc[53];ability=desc[54];
        work.iv[0]=desc[67];work.iv[1]=desc[68];work.iv[2]=desc[69];
        work.iv[3]=desc[71];work.iv[4]=desc[72];work.iv[5]=desc[70];
        work.move[0]=H(18);work.move[1]=H(20);work.move[2]=H(22);work.move[3]=H(24);
        if(desc[179]!=1 || species>649 || species==0 || level>100 || H(16)>626) goto image;
        if(level==0) level=(u16)(func_020056EC(100)+1);
        if(D(0)==0) otId=func_02008530((const struct Sub0200852CObj *)func_02012944(save));
        if(gender==255) gender=2;
        for(i=0;i<6;i++) if(work.iv[i]==255) work.iv[i]=func_020056EC(32);
        id=otId;
        allocated=func_020173F0(species,level,otId,0,tag);
        packed=(work.iv[0]&31)|((u32)work.iv[1]<<27>>22)|((u32)work.iv[2]<<27>>17)|
               ((u32)work.iv[3]<<27>>12)|((u32)work.iv[4]<<27>>7)|((u32)work.iv[5]<<27>>2);
        if(ability==4) ability=(u8)func_020056EC(3);
        switch(ability) {
        case 0:selector=0;break;
        case 1:selector=1;break;
        case 2:selector=0;break;
        case 3:selector=2;break;
        default:mon=0;goto image;
        }
        if(D(8)!=0) random=D(8);
        else {
            if(desc[55]==0) random=func_020186C8(otId,(u16)species,desc[28],gender,selector,0);
            else if(desc[55]==1) random=func_020186C8(otId,(u16)species,desc[28],gender,selector,2);
            else if(desc[55]==2) random=func_020186C8(otId,(u16)species,desc[28],gender,selector,1);
        }
        func_02017588(allocated,H(26),level,id,packed,random);
        func_02017E40(allocated,6,H(16));POKE_TOOL_SetDefaultMoves(allocated);
        for(i=0;i<4;i++) {
            value=*(u16 *)((u8 *)&work.move[0]+i*2);
            if(value!=0 && value<560 && func_0201808C(allocated,value)==65535) func_020180F4(allocated,value);
        }
        if(D(8)==0 && ability==2) func_02018A00(allocated,species,desc[28]);
        func_02017E40(allocated,111,desc[28]);
        if(H(14)!=0 && H(14)<=25) func_02017E40(allocated,152,H(14));
        else func_02017E40(allocated,152,4);
        if(desc[60]!=0) func_02017E40(allocated,153,desc[60]);
        func_02017E40(allocated,19,desc[61]);func_02017E40(allocated,20,desc[62]);
        func_02017E40(allocated,21,desc[63]);func_02017E40(allocated,22,desc[64]);
        func_02017E40(allocated,23,desc[65]);func_02017E40(allocated,24,desc[65]);
        for(j=0;j<15;j++) if(H(12)&(1<<j)) func_02017E40(allocated,d_021DF4FC[j],1);
        if(D(4)==0) func_02017E40(allocated,119,d_0209DF08);
        else func_02017E40(allocated,119,D(4));
        if(desc[29]==0) func_02017E40(allocated,12,d_0209DF0C);
        else func_02017E40(allocated,12,desc[29]);
        if(H(30)==0) {
        failed: func_020307B0(allocated);
        nomon: mon=0;goto image;
        }
        if(H(30)!=func_02045A98()) func_02017E40(allocated,116,(u32)(desc+30));
        value=desc[52];
        if(value==255) value=(u8)func_020056EC(25);
        func_02017E40(allocated,112,value);
        func_02017E40(allocated,149,H(56));func_02017E40(allocated,150,H(58));
        if(H(74)==0) {func_020307B0(allocated);mon=0;goto image;}
        if(H(74)==func_02045A98()) func_02017E40(allocated,142,(u32)func_020084F4(func_02012944(save)));
        else func_02017E40(allocated,142,(u32)(desc+74));
        value=desc[90];
        if(value<=2) func_02017E40(allocated,154,value);
        else {value=func_02008550((const struct Sub0200852CObj *)func_02012944(save));func_02017E40(allocated,154,value);}
        if(desc[92]) {
            func_02017E40(allocated,76,1);
            str=func_02045EC0(g_020A7370,650);
            func_02017E40(allocated,115,(u32)str);
            func_02045808(str);func_02017E40(allocated,9,10);
        }
        year=(u16)((int)D(172)>>16);month=(u8)((int)D(172)>>8);day=(u8)D(172);
        if(desc[92]) place=H(56);else place=H(58);
        func_0202F2AC(func_020185F0(allocated),place,year-2000,month,day);
        func_020185C4(allocated);
        if(func_02017E1C(allocated,3,0)!=0) {func_020307B0(allocated);mon=0;}
        else mon=allocated;
        goto image;
    image:
        arc=func_0202D7C8(heap);
        O(12)=func_0202D8D0((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,448,heap);
        clamp=0;
        O(20)=func_0202D9A4((u32)POKE_TOOL_GetBoxParam(mon),0,2,0,heap);
        O(16)=func_0202D934((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,heap);
        OH(296)=func_021D94C4((int)POKE_TOOL_GetBoxParam(mon),heap)-48;
        if(*(s16 *)(out+296)>48) clamp=48;
        else if(*(s16 *)(out+296)>=0) clamp=*(s16 *)(out+296);
        OH(296)=clamp;
        func_02049238((void *)arc);func_020307B0(mon);
        break;
    case 2:
        arc=(u32)func_020490F4(25,heap);
        O(12)=func_0204ABF0((void *)arc,func_02020E60((u16)D(0),2),0,448,heap);
        O(20)=func_0204AF28((void *)arc,1,0,heap);
        O(16)=func_0204A6C8((void *)arc,func_02020E60((u16)D(0),1),0,0,heap);
        func_02049238((void *)arc);OH(298)=4;OH(296)=8;
        break;
    case 3:
        arc=(u32)func_020490F4(34,heap);
        O(12)=func_0204ABF0((void *)arc,3,0,448,heap);
        O(20)=func_0204AF28((void *)arc,33,36,heap);
        O(16)=func_0204A6C8((void *)arc,12,0,0,heap);
        func_02049238((void *)arc);OH(296)=8;
        break;
    }
    if(desc[714]) {
        func_02082D44(PALETTE,out+242,32);
        func_02082A48(32767,PALETTE,32);
        func_02082D44(PALETTE,out+210,32);
    }
    func_02082BCC(&work.point,0,8);
    work.point.x=*(s16 *)(out+298)+128;work.point.y=-96;work.point.b=2;
    O(4)=(u32)func_0204B294((void *)((u32)owner),O(16),O(12),O(20),&work.point,0,heap);
    func_0204B3DC((void *)O(4),0);
    if(desc[714]) func_0204B688((void *)O(4),1);
}


static inline void GX_SetVisibleWnd(int window)
{
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(window<<13);
}


static inline void G2_SetWnd0InsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x04000048=(u16)tmp;
}


static inline void G2_SetWndOutsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=(u16)tmp;
}


static inline void G2_SetWnd0Position(int x1,int y1,int x2,int y2)
{
    *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}


/*
 * volatile: hardware reads/writes at 021D8C4E..021D8C8A: DISPCNT, WININ, WINOUT, WIN0H/V.
 */
void func_021D8C1C(u8 *p,int mode)
{
    ((struct Obj04491 *)p)->f8=0;
    ((struct Obj04491 *)p)->f20=0;
    ((struct Obj04491 *)p)->f18=0;
    switch(mode) {
    case 0:
        if (((struct Obj22867 *)(*(u8 * *)&((struct Obj04491 *)p)->f114))->f2CA) *(void (**)(u8 *))(p+44)=func_021D8EA4;
        else *(void (**)(u8 *))(p+44)=func_021D8D1C;
        break;
    case 1:
        *(void (**)(u8 *))(p+44)=func_021D9138;
        break;
    }
    GX_SetVisibleWnd(1);
    G2_SetWnd0InsidePlane(15,1);
    G2_SetWndOutsidePlane(31,1);
    G2_SetWnd0Position(0,168,255,192);
}


/*
 * volatile: hardware access at 021D8CB2
 */
void func_021D8CA8(u8 *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(func_021D6D7C(p+280)) func_021D6D38(p+280);
    func_02040588(2,0);
    func_0204B3B4(((struct Obj08088 *)p)->f4);
    func_0204ADA4((u32)(((struct Obj08088 *)p)->fC));
    func_0204A8D4((u32)(((struct Obj08088 *)p)->f10));
    func_0204AFD8((u32)(((struct Obj08088 *)p)->f14));
    func_02082BCC(p,0,300);
}



void func_021D8D00(char *p)
{
    if (*(void (**)(void))(p + 0x2c) != 0) {
        (*(void (**)(char *))(p + 0x2c))(p);
        if (((struct Obj10410 *)p)->f8 != 0)
            *(u32 *)&((struct Obj10410 *)p)->f2C = 0;
    }
}


int func_021D8D18(char *p)
{
    return ((struct Obj22868 *)p)->f8;
}


/*
 * volatile: hardware stores at 021D8D9A and 021D8DEC.
 */
void func_021D8D1C(u8 *p)
{
    s16 y;
    switch(((struct Obj00498 *)p)->f20) {
    case 0:
        func_02040588(2,0);
        func_021D694C(((struct Obj00498 *)p)->f24,2);
        ((struct Obj00498 *)p)->f20=1;
        return;
    case 1:
        func_0207D63C((void *)0x04000050,4,8,0,16);
        func_02040588(2,1);
        ((struct Obj00498 *)p)->f18=0;
        ((struct Obj00498 *)p)->f20=2;
        return;
    case 2: {
        u32 n=(((struct Obj00498 *)p)->f18*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((struct Obj00498 *)p)->f30=(((struct Obj00498 *)p)->f18*32767u)/120u;
        func_021DAB50((void *)15,(u16 *)(p+50),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        func_021DAB50((void *)31,(u16 *)(p+82),((struct Obj00498 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((struct Obj00498 *)p)->f18)++>120) {
            *(volatile u16 *)0x04000050=0;
            func_021D9254(((struct Obj00498 *)p)->f28,1);
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=3;
            return;
        }
        break;
    }
    case 3:
        if((((struct Obj00498 *)p)->f18)++>180) {
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=4;
            return;
        }
        break;
    case 4:
        y=((214-((struct Obj00498 *)p)->f128)*((struct Obj00498 *)p)->f18)/60u-96;
        CLACT_SetActorSurfacePosAxis(((struct Obj00498 *)p)->f4,y,0,1);
        if(y>=-48 && y<=192) func_0204B3DC(((struct Obj00498 *)p)->f4,1);
        if((((struct Obj00498 *)p)->f18)++>=60) {
            func_020061E4(1649);
            func_021D9254(((struct Obj00498 *)p)->f28,0);
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=5;
            return;
        }
        break;
    case 5:
        if((((struct Obj00498 *)p)->f18)++>60) {
            ((struct Obj00498 *)p)->f18=0;
            ((struct Obj00498 *)p)->f20=6;
            return;
        }
        break;
    case 6:
        ((struct Obj00498 *)p)->f8=1;
        break;
    }
}


/*
 * volatile: hardware stores at 021D8F44, 021D8F96, 021D9062, 021D908E, 021D9116.
 */
void func_021D8EA4(u8 *p)
{
    Position pos;
    switch(((struct Obj00184 *)p)->f20) {
    case 0:
        func_021D6CF4((int *)(p+0x118),((struct Obj00184 *)p)->f0);
        func_021D6D50((int *)(p+0x118),0x22,0x26,((struct Obj00184 *)p)->f0);
        func_02040588(2,0);
        func_021D694C(*(u16 * *)&((struct Obj00184 *)p)->f24,2);
        ((struct Obj00184 *)p)->f20=1;
        return;
    case 1:
        func_0207D63C((void *)0x04000050,4,8,0,16);
        func_02040588(2,1);
        ((struct Obj00184 *)p)->f18=0;
        ((struct Obj00184 *)p)->f20=2;
        return;
    case 2: {
        u32 n=(((struct Obj00184 *)p)->f18*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((struct Obj00184 *)p)->f30=(((struct Obj00184 *)p)->f18*32767u)/120u;
        func_021DAB50((void *)15,(u16 *)(p+50),((struct Obj00184 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        func_021DAB50((void *)31,(u16 *)(p+82),((struct Obj00184 *)p)->f30,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((struct Obj00184 *)p)->f18)++>120) {
            *(volatile u16 *)0x04000050=0;
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=3;
            return;
        }
        break;
    }
    case 3:
        if((((struct Obj00184 *)p)->f18)++>180) {
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=6;
            func_0207D63C((void *)0x04000050,1,31,0,16);
            func_021D6D6C((void **)(p+0x118),0);
            func_021D6D6C((void **)(p+0x118),1);
            func_021D6D6C((void **)(p+0x118),2);
            func_020061E4(0x794);
            return;
        }
        break;
    case 6:
        if((((struct Obj00184 *)p)->f18)++>120) {
            func_020061E4(0x795);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=4;
            func_021D9254(((struct Obj00184 *)p)->f28,1);
            return;
        }
        break;
    case 4:
        pos.x=128;
        pos.y=118-((struct Obj00184 *)p)->f128;
        func_0204B404(((struct Obj00184 *)p)->f4,(const struct Vec2 *)(&pos),0);
        func_0204B3DC(((struct Obj00184 *)p)->f4,1);
        ((struct Obj00184 *)p)->f1C=0;
        ((struct Obj00184 *)p)->f20=5;
        return;
    case 5: {
        u32 n=(((struct Obj00184 *)p)->f1C*16u)/10u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        (((struct Obj00184 *)p)->f18)++;
        if((((struct Obj00184 *)p)->f1C)++>10) {
            ((struct Obj00184 *)p)->f1C=0;
            ((struct Obj00184 *)p)->f20=7;
            return;
        }
        break;
    }
    case 7:
        if((((struct Obj00184 *)p)->f18)++>90) {
            *(volatile u16 *)0x04000050=0;
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=8;
            return;
        }
        break;
    case 8:
        if((((struct Obj00184 *)p)->f18)++>10) {
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=9;
            return;
        }
        break;
    case 9:
        ((struct Obj00184 *)p)->f30=(((struct Obj00184 *)p)->f18*32767u)/120u;
        func_021DAB50((void *)14,(u16 *)(p+178),((struct Obj00184 *)p)->f30,14,(const u16 *)(p+242),(const u16 *)(p+210));
        if((((struct Obj00184 *)p)->f18)++>120) {
            func_021D9254(((struct Obj00184 *)p)->f28,0);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=10;
            return;
        }
        break;
    case 10:
        if((((struct Obj00184 *)p)->f18)++>60) {
            func_020061E4(0x671);
            ((struct Obj00184 *)p)->f18=0;
            ((struct Obj00184 *)p)->f20=11;
            return;
        }
        break;
    case 11:
        *(volatile u16 *)0x04000050=0;
        ((struct Obj00184 *)p)->f8=1;
        break;
    }
}


void func_021D9138(u8 *p)
{
    switch(((struct Obj02833 *)p)->f20) {
    case 0: ((struct Obj02833 *)p)->f20=1; return;
    case 1:
        ((struct Obj02833 *)p)->f30=(((struct Obj02833 *)p)->f18*32767u)/60u;
        func_021DAB50((void *)15,(u16 *)(p+50),((struct Obj02833 *)p)->f30,0,(const u16 *)(p+146),(const u16 *)(p+114));
        func_021DAB50((void *)31,(u16 *)(p+82),((struct Obj02833 *)p)->f30,0,(const u16 *)(p+146),(const u16 *)(p+114));
        if((((struct Obj02833 *)p)->f18)++ >60) {
            ((struct Obj02833 *)p)->f18=0;
            ((struct Obj02833 *)p)->f20=2;
            return;
        }
        break;
    case 2: ((struct Obj02833 *)p)->f8=1; break;
    }
}


void func_021D91BC(u8 *p,void *q,u16 h)
{
    int i;
    u8 *r;
    s16 xy[2];
    func_02082BCC(p,0,296);
    ((struct Obj06447 *)p)->f10=-819;
    ((struct Obj06447 *)p)->f118=q;
    ((struct Obj06447 *)p)->f14=-819;
    ((struct Obj06447 *)p)->f124=h;
    for(i=0;i<32;i++) {
        func_0204B53C(func_021D6C58(((struct Obj06447 *)p)->f118,i+1),(struct Pt *)xy);
        r=p+i*4;
        ((struct Obj13941 *)r)->f18=xy[1]<<12;
        ((struct Obj13941 *)r)->f98=func_02005728(4096)+6554;
    }
}



void func_021D9228(void *p)
{
    func_02082BCC(p, 0, 0x128);
}



void func_021D9238(char *p)
{
    if (((struct Obj10411 *)p)->f4 != 0 && ((struct Obj10411 *)p)->f0 != 0) {
        void (*fp)(char *) = *(void (**)(char *))(p + 0x11c);
        if (fp != 0)
            fp(p);
    }
}


void func_021D9254(char *p,int n) {
 ((struct Obj05354 *)p)->f0=1;
 ((struct Obj05354 *)p)->f8=0;
 ((struct Obj05354 *)p)->f14=((struct Obj05354 *)p)->f10;
 switch(n) {case 0: ((struct Obj05354 *)p)->f11C=(unsigned)func_021D928C;break;case 1:((struct Obj05354 *)p)->f11C=(unsigned)func_021D933C;break;}
}


void func_021D9288(unsigned *p,unsigned v) { p[1]=v; }


void func_021D928C(u8 *p)
{
    int i;
    void *sprite;
    u8 *q;
    s16 xy[2];
    if(((struct Obj02177 *)p)->f10!=-819) {
        int base=((struct Obj02177 *)p)->f14;
        ((struct Obj02177 *)p)->f10=base+((-819-base)*((struct Obj02177 *)p)->f8)/60;
        if((((struct Obj02177 *)p)->f8)++>60) ((struct Obj02177 *)p)->f10=-819;
    }
    for(i=0;i<32;i++) {
        sprite=func_021D6C58(((struct Obj02177 *)p)->f118,i+1);
        if(func_0204B3F4(sprite)) {
            q=p+i*4;
            ((struct Obj08089 *)q)->f18=((struct Obj08089 *)q)->f18+((struct Obj08089 *)q)->f98;
            func_0204B53C(sprite,(struct Pt *)xy);
            xy[1]=((struct Obj08089 *)q)->f18>>12;
            func_0204B528(sprite,(const struct Pt *)xy);
            if(xy[1]>=0 && xy[1]<=208) func_0204B3DC(sprite,1);
            else func_0204B3DC(sprite,0);
        }
    }
    ((struct Obj02177 *)p)->fC=((struct Obj02177 *)p)->fC+((struct Obj02177 *)p)->f10;
    func_02041EE4(3,3,((struct Obj02177 *)p)->fC>>12);
    func_02041EE4(7,3,((struct Obj02177 *)p)->fC>>12);
}


void func_021D933C(u8 *p)
{
    int i;
    u8 *q;
    void *sprite;
    s16 xy[2];
    if(((struct Obj02178 *)p)->f10!=-16384) {
        int base=((struct Obj02178 *)p)->f14;
        ((struct Obj02178 *)p)->f10=base+((-16384-base)*((struct Obj02178 *)p)->f8)/60;
        if((((struct Obj02178 *)p)->f8)++>60) ((struct Obj02178 *)p)->f10=-16384;
    }
    for(i=0;i<32;i++) {
        q=p+i*4;
        ((struct Obj05355 *)q)->f18=((struct Obj05355 *)q)->f18+((struct Obj05355 *)q)->f98;
        if(((struct Obj05355 *)q)->f18>=851968) ((struct Obj05355 *)q)->f18=-65536;
        sprite=func_021D6C58(((struct Obj02178 *)p)->f118,i+1);
        func_0204B53C(sprite,(struct Pt *)xy);
        xy[1]=((struct Obj05355 *)q)->f18>>12;
        func_0204B528(sprite,(const struct Pt *)xy);
        if(xy[1]>=0 && xy[1]<=208) func_0204B3DC(sprite,1);
        else func_0204B3DC(sprite,0);
    }
    ((struct Obj02178 *)p)->fC=((struct Obj02178 *)p)->fC+((struct Obj02178 *)p)->f10;
    func_02041EE4(3,3,((struct Obj02178 *)p)->fC>>12);
    func_02041EE4(7,3,((struct Obj02178 *)p)->fC>>12);
}


/*
 * extent: two zero alignment bytes at 021D9486; next function starts 021D9488.
 */
void func_021D93F4(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap)
{
    Pos pos;
    func_02082BCC(p,0,12);
    *(const void * *)&((struct Obj04492 *)p)->f8=q;
    ((struct Obj04492 *)p)->f0=func_02025538(heap,(void *)n);
    func_02082BCC(&pos,0,8);
    pos.x=96; pos.y=169; pos.a=0; pos.b=0;
    ((struct Obj04492 *)p)->f4=func_021DA8CC((const char *)(&pos),8,2,(int)(*(void *const *)&((struct Obj22870 *)q)->f0),3,0,((struct Obj04492 *)p)->f0,(void *)k,heap);
    func_021DA9EC(((struct Obj04492 *)p)->f4,1120);
    func_021DA9F0(((struct Obj04492 *)p)->f4,0,0,1);
    func_021DA994(((struct Obj04492 *)p)->f4,x,y,z);
    func_0204B3DC(func_021D6C58((u8 *)q,34),1);
}


void func_021D9488(void **p) {
 func_021DA978(p[1]);func_0204B3DC(func_021D6C58(p[2],34),0);func_021DA958(p[1]);func_02025588(p[0]);func_02082BCC(p,0,12);
}


/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int func_021D94B8(char *p)
{
    return func_021DA9F8(((struct Obj22871 *)p)->f4);
}


unsigned func_021D94C4(int id,int heap)
{
    unsigned result=48;
    int found=0;
    int row,col,bit;
    void *object;
    void *allocation;
    u8 *table;
    heap=(heap&32767)|32768;
    allocation=(void *)POKEGRA_LoadCharDataPP(&object,(void *)id,(int)0,(u16)heap);
    POKEGRA_ConvertCharTo2D(object,heap);
    for(row=11;row>=0;row--) {
        for(col=0;col<12;col++) {
            unsigned *p=(unsigned *)(*(u8 * *)&((struct Obj13942 *)object)->f14+(row*12+col)*32);
            for(bit=7;bit>=0;bit--) {
                if(p[bit]) {
                    unsigned index=row*8+bit;
                    if(result<index) result=index;
                    found=1;
                }
            }
        }
        if(found) break;
    }
    func_020307B0(allocation);
    return result;
}


int func_021D9554(char *p,int n) {
 if(MYSTERY_DATA_CheckPacketCrc((u8 *)p)!=0 && n==0 && (((struct Obj13943 *)p)->fCC==0 || (((struct Obj13943 *)p)->fCC&0x200000)!=0)) return 1;
 return 0;
}


/*
 * volatile: hardware rereads at 021D959A..021D95CA
 */
void func_021D9580(void)
{
    unsigned i;
    func_020434DC(1,0);
    *(volatile u16 *)0x04000008=(u16)(*(volatile u16 *)0x04000008 &~3);
    REG=(u16)((REG&~0x3002)|2);
    REG&=(u16)~0x3010;
    REG&=(u16)~0x3004;
    REG=(u16)((REG&~0x3000)|8);
    REG&=(u16)~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(d_021DF5E4+i*2));
    func_02046BE0(0,0);
}
