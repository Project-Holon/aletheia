/*
 * file:     pokemontrade_demo_up.c
 * unit:     yes
 * function: func_021D4664, func_021D4820, func_021D48F0, func_021D49C4, func_021D49F4, func_021D4A34, func_021D4A54, func_021D4A94, func_021D4AB4, func_021D4B14, func_021D4C08, func_021D4C20, func_021D4C40, func_021D54F0, func_021D55AC, func_021D5628, func_021D5694, func_021D56E0, func_021D56E4, func_021D56F0, func_021D56FC, func_021D572C, func_021D5748, func_021D5888, func_021D58F0, func_021D5930, func_021D5950, func_021D5990, func_021D59B0, func_021D5A60, func_021D5B74, func_021D5B98, func_021D5BB8, func_021D64F4, func_021D6544, func_021D6600, func_021D667C, func_021D66E8, func_021D6734, func_021D6738, func_021D6744, func_021D6750, func_021D67D4, func_021D67F8
 * address:  0x021D4664
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4240  0x021D4240  thumb  ov118
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov118
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   d_021D7D00     0x021D7D00  data
 *   d_021D7DD8     0x021D7DD8  data
 *   d_021D86A0     0x021D86A0  data
 *   func_0203D34C  0x0203D34C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02041300  0x02041300  arm
 *   func_021E0FF4  0x021E0FF4  thumb  ov119
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021D4434  0x021D4434  thumb  ov118
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   BUTTON_MAN_GetUserData 0x02051A34 arm
 *   func_02011610 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   func_021D4490  0x021D4490  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   func_021D449C  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
 *   func_021DC720  0x021DC720  thumb
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021E3208  0x021E3208  thumb
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   d_021D7FD4  0x021D7FD4  data
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D434C  0x021D434C  thumb  ov118
 *   func_021D43C8  0x021D43C8  thumb  ov118
 *   func_021D4A48  0x021D4A48  thumb  ov118
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   func_020515CC  0x020515CC  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021DFB4C  0x021DFB4C  thumb  ov119
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   d_021D7CB4     0x021D7CB4  data
 *   d_021D7FEC     0x021D7FEC  data
 *   d_021D80C4     0x021D80C4  data
 *   d_021D8790     0x021D8790  data
 *   d_021D7CA8     0x021D7CA8  data
 *   func_020435F4  0x020435F4  arm
 *   d_021D82A4  0x021D82A4  data
 *   func_0207D658  0x0207D658  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D6918  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 */
#include "../../matched/include/Obj13873.h"
#include "../../matched/include/Obj22658.h"
#include "../../matched/include/Obj22659.h"
#include "../../matched/include/Obj13874.h"
#include "../../matched/include/Obj22660.h"
#include "../../matched/include/Obj22661.h"
#include "pokemontrade_demo_up.h"
#include "../../matched/include/Obj22665.h"
#include "../../matched/include/Obj22666.h"
#include "../../matched/include/Obj22667.h"
#include "../../matched/include/Obj22668.h"
#include "../../matched/include/Obj22669.h"
#include "../../matched/include/Obj01724.h"
#include "../../matched/include/Obj22670.h"
#include "../../matched/include/Obj22671.h"
#include "../../matched/include/Obj22672.h"
#include "../../matched/include/Obj13876.h"
#include "../../matched/include/Obj22675.h"
#include "../../matched/include/Obj22676.h"
#include "../../matched/include/Obj13877.h"
#include "../../matched/include/Obj22677.h"
#include "../../matched/include/Obj22678.h"
#include "../../matched/include/Obj22682.h"
#include "../../matched/include/Obj22683.h"
#include "../../matched/include/Obj22684.h"
#include "../../matched/include/Obj22685.h"
#include "../../matched/include/Obj22686.h"
#include "../../matched/include/Obj01725.h"
#include "../../matched/include/Obj22687.h"
#include "../../matched/include/Obj22688.h"
#include "../../matched/include/Obj22689.h"

#define FRAME (((TradeUp *)p)->frame)
#define OBJ(i) (((TradeUp *)p)->obj[i])
#define HEAP (((TradeUp *)p)->heap)
#define SLOT0 (((TradeUp *)p)->slot0)
#define SLOT1 (((TradeUp *)p)->slot1)
#define FADE (((TradeUp *)p)->fade)
struct WordSet;
struct MsgBank;
struct IcaAnime;
struct Rec12;
struct Bank;
struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
struct Entry;
struct Link;
struct McssFade;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef int s32_021D4C20;

typedef int s32_021D4C40;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef signed int     s32_021D5628;

typedef short s16;

typedef struct {
    u32 v[4];
} Quad;

typedef int s32_021D64F4;

typedef signed int     s32_021D667C;

extern void func_021D4240(s8 *fade);
extern void func_021DFC68(void *p, void *a1);
extern int func_021D4480(int);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021E64B8(void *p);
extern void func_021E4888(char *p);
extern void func_021E2680(char *p);
extern void func_021D4484(u8 *p, u32 v);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void MCSS_GetPosition(void *p, Vec *out);
extern void func_021DFD24(void *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021E0FF4(void *p, int a, int b);
extern void MCSS_SetPosition(void *p, Vec *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int func_021E12AC(char *p);
extern void func_021E1098(char *p);
extern void func_021E36D8(void *p, int a);
extern void func_021D4434(void *);
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021DFDA0(void *p);
extern int BUTTON_MAN_GetUserData(void *p);
extern unsigned int func_02011610(struct IcaAnime *p, struct Rec12 *dst);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void func_021D4490(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void func_021D449C(u8 *p);
extern void func_021DC720(void *p);
extern void func_0204A5AC(void);
extern void func_021E3E40(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern void func_021E3208(void *p, int a);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(char *p);
extern void func_021E2D70(void *w, int a);
extern void func_021E3004(char *p);
extern void func_021E3230(void *p);
extern void func_021D434C(void *);
extern void func_021D43C8(void *);
extern void func_021D4A48(void *, int);
extern void MCSS_SetPaletteFade(void *, u32, u32, s32_021D4C40, u32);
extern void MCSS_GetScale(void *, Vec *);
extern void MCSS_SetScale(void *, Vec *);
extern int func_020515CC(u32, int, void *, void *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_021DFB84(void *, int, Vec *, u32);
extern void func_021DFA60(u32 key);
extern void func_021DFB4C(void *, int, void *);
extern void *func_0201ADE4(u32 a, int b, u32 heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021D5628 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021D5628 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021D5628 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020435F4(u32 planes);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021E3BB0(char *p);
extern int func_021D8A24(void *p);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void func_02015F2C(void *obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(char *p);
extern void func_021E106C(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021D6918(u8 *p);
void func_021D4664(u8 *p);
void func_021D4820(u8 *p);
void func_021D48F0(u8 *p);
void func_021D49C4(void *p);
void func_021D49F4(void *obj, int on);
void func_021D4A34(void *p);
void func_021D4A54(void *obj, int on);
void func_021D4A94(void *p);
void func_021D4AB4(u8 *p);
void func_021D4B14(u8 *p);
void func_021D4C08(u8 *p);
void func_021D4C20(u8 *p);
void func_021D4C40(u8 *p);
void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D55AC(void *p);
void func_021D5628(void *p);
void func_021D5694(void *p);
int func_021D56E0(int a);
void func_021D56E4(u8 *p, u32 v);
void func_021D56F0(u8 *p);
void func_021D56FC(void *p);
void func_021D572C(u8 *p, int idx);
void func_021D5748(u8 *p, int idx);
void func_021D5888(u8 *p, int idx);
void func_021D58F0(void *obj, int on);
void func_021D5930(void *p);
void func_021D5950(void *obj, int on);
void func_021D5990(void *p);
void func_021D59B0(u8 *p);
void func_021D5A60(u8 *p);
void func_021D5B74(u8 *p);
void func_021D5B98(u8 *p);
void func_021D5BB8(u8 *p);
void func_021D64F4(s8 *fade);
void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D6600(void *p);
void func_021D667C(void *p);
void func_021D66E8(void *p);
int func_021D6734(int a);
void func_021D6738(u8 *p, u32 v);
void func_021D6744(u8 *p);
void func_021D6750(u8 *p);
void func_021D67D4(u8 *p);
void func_021D67F8(u8 *p);
extern const u8 d_021D7D00[];
extern const u8 d_021D7DD8[];
extern u8 d_021D86A0[];
extern const Vec d_021D7C90;
extern const char d_021D7FD4[];
extern const Quad d_021D7CB4;
extern const u8 d_021D7FEC[];
extern const u8 d_021D80C4[];
extern u8 d_021D8790[];
extern const Vec d_021D7CA8;
extern const char d_021D82A4[];
extern const char d_021D8650[];
extern const Vec d_021D7CC4;
extern const Vec d_021D7CD0;


#define WORK ((u8 *)((TradeUp *)p)->work)





void func_021D4664(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D4240(*(s8 * *)&((TradeUp *)p)->fade);
    func_021DFC68(((TradeUp *)p)->slot0, p);
    func_021DFC68(((TradeUp *)p)->slot1, p);
    if (FRAME > func_021D4480(0x2A)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0);
        func_021E64B8(p);
        func_021E4888((char *)p);
        func_021E2680((char *)p);
        func_021D4484(p, 0);
        mon = func_021D8FA4(p, func_021D8AA8(p));
        func_02017E1C(mon, 7, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            a = func_02017E1C(mon, 0xAB, 0);
            b = func_02017E1C(mon, 0x6F, 0);
            func_02006CAC((void **)(&buf));
            func_02006984(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (((TradeUp *)p)->f11ED == 0) {
            MCSS_GetPosition(OBJ(0), &v1);
            func_021DFD24(SLOT0);
            if (((TradeUp *)p)->f11EF != 0) {
                SLOT0 = func_021DFBB4(OBJ(0), (void *)0x14, &v1, d_021D86A0, HEAP);
            } else {
                SLOT0 = func_021DFBB4(OBJ(0), (void *)0x12, &v1, (void *)d_021D7D00, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            MCSS_SetAnmStopFlag(OBJ(2));
            MCSS_SetVanishFlag(OBJ(2));
        } else {
            MCSS_GetPosition(OBJ(0), &v2);
            func_021DFD24(SLOT0);
            if (((TradeUp *)p)->f11EF != 0) {
                SLOT0 = func_021DFBB4(OBJ(0), (void *)0x14, &v2, d_021D86A0, HEAP);
            } else {
                SLOT0 = func_021DFBB4(OBJ(0), (void *)0x28, &v2, (void *)d_021D7DD8, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D48F0);
    }
}





void func_021D4820(u8 *p)
{
    func_0203D34C(0, ((TradeUp *)p)->heap);
    if (((TradeUp *)p)->f118C == 6) {
        func_02045CAC((struct MsgBank *)(((TradeUp *)p)->f720), 0x98, (void *)(((TradeUp *)p)->f73C));
    } else if (((TradeUp *)p)->f118C == 8) {
        func_02045CAC((struct MsgBank *)(((TradeUp *)p)->f720), 0x9B, (void *)(((TradeUp *)p)->f73C));
    } else if (((TradeUp *)p)->f11ED != 0) {
        func_02045CAC((struct MsgBank *)(((TradeUp *)p)->f720), 0x82, (void *)(((TradeUp *)p)->f73C));
    } else {
        func_02045CAC((struct MsgBank *)(((TradeUp *)p)->f720), 0x81, (void *)(((TradeUp *)p)->f73C));
    }
    func_0201EEF4(((TradeUp *)p)->f724, 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((TradeUp *)p)->f724), 1, (void *)(((TradeUp *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((TradeUp *)p)->f724), (void *)(((TradeUp *)p)->f738), (void *)(((TradeUp *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}





void func_021D48F0(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D4820(p);
    }
    if (((TradeUp *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition(OBJ(0), &v);
        MCSS_SetPosition(OBJ(2), &v);
        MCSS_ResetVanishFlag(OBJ(2));
        MCSS_SetVanishFlag(OBJ(0));
        MCSS_ResetAnmStopFlag(OBJ(2));
        *(void **)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC((char *)p) != 0) {
        func_021E1098((char *)p);
        if (((TradeUp *)p)->f11ED == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D4B14);
    }
    func_021DFC68(SLOT0, p);
}





void func_021D49C4(void *p)
{
    func_021D4434(p);
    func_021E3034(((TradeUp *)p)->work, 6);
    func_021E2F2C(((TradeUp *)p)->work);
    func_020307B0(((TradeUp *)p)->work);
    ((TradeUp *)p)->work = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}




void func_021D49F4(void *obj, int on) {
 int buf[3]; Vec *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)BUTTON_MAN_GetUserData(obj);
 if (((struct Obj22658 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98!=0) {
 v=(Vec *)buf; v->x=0; v->y=0; v->z=0;
 func_02011610(((struct Obj22659 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98,(struct Rec12 *)v);
 BUTTON_MAN_SetEmitterPos(obj,v);
 }
 }
}





/*
 * Addresses are Black-image addresses.
 */
void func_021D4A34(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D49F4);
}





void func_021D4A54(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22660 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22661 *)(*(char * *)&((struct Obj13874 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, (Vec *)v);
        }
    }
}





void func_021D4A94(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D4A54);
}





void func_021D4AB4(u8 *p)
{
    func_021D4490(p);
    ((TradeUp *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((TradeUp *)p)->obj[0]), 0);
    if (((TradeUp *)p)->f118C == 6) {
        Vec v = d_021D7C90;
        MCSS_SetPosition((void *)(((TradeUp *)p)->obj[0]), &v);
    }
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D449C);
}





void func_021D4B14(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    ((TradeUp *)p)->f9C4 = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D7FD4, 0x98);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 3);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    MCSS_SetVanishFlag(OBJ(1));
    MCSS_SetVanishFlag(OBJ(2));
    MCSS_SetVanishFlag(OBJ(3));
    func_021E2F34(WORK);
    func_021E2FB0((char *)WORK);
    func_021E2D70(WORK, 1);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4C08);
}





void func_021D4C08(u8 *p)
{
    func_021E3004(((TradeUp *)p)->work);
    func_021D8E84(p, (int)func_021D4C20);
}


#undef WORK

#undef WORK
#define WORK ((u32 *)((TradeUp *)p)->work)





/*
 * Addresses are Black-image addresses.
 */
void func_021D4C20(u8 *p)
{
    func_021E3230(p);
    func_021E3208(p, 3);
    func_021D8E84(p, (int)func_021D4C40);
}





void func_021D4C40(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    func_021DFA60(FRAME);
    if (FRAME == func_021D4480(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(3)) {
        func_021D43C8(p);
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D4480(4)) {
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == func_021D4480(0x356)) {
        func_020515CC(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D4480(0x65)) {
        func_020515CC(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        func_020515CC(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D4480(0x356)) {
        func_020515CC(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D4480(0xE)) {
        func_020515CC(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x483)) {
        func_020515CC(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        func_020515CC(WORK[4], 4, func_021D4A34, p);
    }
    if (FRAME == func_021D4480(0x152)) {
        func_020515CC(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D4480(0x2BC)) {
        func_020515CC(WORK[6], 6, func_021D4A94, p);
    }
    if (FRAME == func_021D4480(0x47F)) {
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(0x10A)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0x14), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x12D) - 2) {
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (SLOT1 != 0) {
            func_020307B0(SLOT1);
            SLOT1 = 0;
        }
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    if (FRAME == func_021D4480(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D4480(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        MCSS_SetScale(OBJ(2), &v1);
    }
    if (FRAME == func_021D4480(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D4480(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        MCSS_SetScale(OBJ(3), &v2);
    }
    if (FRAME == func_021D4480(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        func_021DFB4C(SLOT0, func_021D4480(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        func_021DFB4C(SLOT1, func_021D4480(0x1C), &v3);
    }
    if (FRAME == func_021D4480(0x170)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D4480(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D4480(0x2E), &v4, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag(OBJ(0));
        MCSS_SetPaletteFade(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        MCSS_SetPosition(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D4480(0x67), &v5, HEAP);
        MCSS_GetScale(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        MCSS_SetScale(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        MCSS_SetPosition(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D4480(0x67), &v6, HEAP);
        MCSS_GetScale(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        MCSS_SetScale(OBJ(1), &v6);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1F8)) {
        func_021DFB4C(SLOT0, func_021D4480(0x80), (u8 *)SLOT0 + 0x28);
        func_021DFB4C(SLOT1, func_021D4480(0x80), (u8 *)SLOT1 + 0x28);
    }
    if (FRAME == func_021D4480(0x27D)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D4480(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D4480(7), &v7, HEAP);
    }
    func_021D4480(0x48B);
    if (FRAME == func_021D4480(0x48B + 3)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v8.x = 0;
        v8.y = -0x17000;
        v8.z = 0xA000;
        MCSS_SetPosition(OBJ(3), &v8);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x28B)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0xA), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x2B5)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x380)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x3CA)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x4C1)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    func_021DFC68(SLOT0, p);
    func_021DFC68(SLOT1, p);
}





void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = func_02017E1C(mon, 7, 0);
    a = func_02017E1C(mon, 0xAB, 0);
    b = func_02017E1C(mon, 0x6F, 0);
    egg = func_02017E1C(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)func_0201ADE4((u16)a, (u16)b, ((TradeUp *)p)->heap);
        flag = func_0201AE1C((const struct Personal *)h, 0x10);
        func_0201AE14((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}





void func_021D55AC(void *p)
{
    u32 v = ((struct Obj22665 *)((char *)((TradeUp *)p)->work))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22666 *)((char *)((TradeUp *)p)->work))->fB0 =
            (u32)func_0204B294((void *)((TradeUp *)p)->f9C4,
                          ((TradeUp *)p)->f8A8,
                          ((TradeUp *)p)->f88C,
                          ((TradeUp *)p)->f8BC,
                          &s, 0, ((TradeUp *)p)->heap);
        func_0204B92C((struct Obj *)((struct Obj22667 *)((char *)((TradeUp *)p)->work))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22668 *)((char *)((TradeUp *)p)->work))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}





void func_021D5628(void *p)
{
    void *h = func_020490F4(0x67, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f8BC = func_0204AF28(h, 1, 0, ((TradeUp *)p)->heap);
    func_02049238(h);
    ((struct Obj22669 *)((char *)((TradeUp *)p)->work))->fB0 = 0;
}





/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D5694 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
void func_021D5694(void *p)
{
    u8 *b = p;

    if (((struct Obj22670 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22671 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0);
    if (((struct Obj01724 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01724 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01724 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01724 *)b)->f8BC));
    }
    ((struct Obj01724 *)b)->f8A8 = 0;
    ((struct Obj01724 *)b)->f88C = 0;
    ((struct Obj01724 *)b)->f8BC = 0;
    ((struct Obj22672 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 = 0;
}





int func_021D56E0(int a) { return a; }





void func_021D56E4(u8 *p, u32 v) { ((TradeUp *)p)->frame = v; }





void func_021D56F0(u8 *p) { ((TradeUp *)p)->f1094 = 1; }





void func_021D56FC(void *p)
{
    func_021D5694(p);
    func_021E3034(((TradeUp *)p)->work, 6);
    func_021E2F2C(((TradeUp *)p)->work);
    func_020307B0(((TradeUp *)p)->work);
    ((TradeUp *)p)->work = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}





void func_021D572C(u8 *p, int idx)
{
    if (((TradeUp *)p)->slot0 != 0) {
        func_020307B0(((TradeUp *)p)->slot0);
        ((TradeUp *)p)->slot0 = 0;
    }
}

#undef WORK

#define WORK ((u8 *)((TradeUp *)p)->work)





/*
 * Addresses are Black-image addresses.
 */
void func_021D5748(u8 *p, int idx)
{
    void *x;
    Vec buf;

    x = func_021D8FA4(p, 1 - func_021D8AA8(p));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((TradeUp *)p)->f11EE == 0) {
        MCSS_GetPosition(((void **)(p + 0x844))[idx], &buf);
        func_021DFD24(((TradeUp *)p)->f868);
        if (((TradeUp *)p)->f11F0 != 0) {
            ((TradeUp *)p)->f868 = func_021DFBB4(((void **)(p + 0x844))[idx], (void *)0x14, &buf, d_021D8790, ((TradeUp *)p)->heap);
        } else {
            ((TradeUp *)p)->f868 = func_021DFBB4(((void **)(p + 0x844))[idx], (void *)0x28, &buf, (void *)d_021D80C4, ((TradeUp *)p)->heap);
        }
    } else {
        Quad t = d_021D7CB4;
        void *obj = ((TradeUp *)p)->obj[t.v[idx]];
        MCSS_GetPosition(((void **)(p + 0x844))[idx], &buf);
        func_021DFD24(((TradeUp *)p)->f868);
        if (((TradeUp *)p)->f11F0 != 0) {
            ((TradeUp *)p)->f868 = func_021DFBB4(obj, (void *)0x14, &buf, d_021D8790, ((TradeUp *)p)->heap);
        } else {
            ((TradeUp *)p)->f868 = func_021DFBB4(obj, (void *)0x12, &buf, (void *)d_021D7FEC, ((TradeUp *)p)->heap);
        }
    }
}





void func_021D5888(u8 *p, int idx)
{
    void **obj = ((TradeUp *)p)->obj;
    Vec v;

    MCSS_ResetVanishFlag((void *)obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    MCSS_SetPosition((void *)obj[idx], &v);
    MCSS_SetAnmStopFlag((void *)obj[idx]);
    MCSS_GetScale((void *)obj[idx], &v);
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    MCSS_SetScale((void *)obj[idx], &v);
}





void func_021D58F0(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22675 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22676 *)(*(char * *)&((struct Obj13876 *)w)->fC))->f98, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}





void func_021D5930(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D58F0);
}





void func_021D5950(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22677 *)(*(char * *)&((struct Obj13877 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            func_02011610(((struct Obj22678 *)(*(char * *)&((struct Obj13877 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}





void func_021D5990(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D5950);
}





void func_021D59B0(u8 *p)
{
    func_021D56F0(p);
    ((TradeUp *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((TradeUp *)p)->obj[0]), 0);
    MCSS_SetVanishFlag((void *)(((TradeUp *)p)->obj[0]));
    MCSS_SetVanishFlag((void *)(((TradeUp *)p)->obj[1]));
    if (((TradeUp *)p)->f118C == 6) {
        Vec v = d_021D7CA8;
        MCSS_SetPosition((void *)(((TradeUp *)p)->obj[0]), &v);
    }
    func_021E71F0(p, 0x11);
    func_021E7208(p, 0);
    func_021D54F0(p, p + 0x11ED, p + 0x11EF, ((TradeUp *)p)->f834, 1);
    func_021D54F0(p, p + 0x11EE, p + 0x11F0, ((TradeUp *)p)->f830, 0);
    func_021D8E84(p, (int)func_021D5A60);
}





void func_021D5A60(u8 *p)
{
    func_021DC720(p);
    func_0204A5AC();
    func_021E3E40(p);
    ((TradeUp *)p)->f9C4 = (int)func_0204B100(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D82A4, 0xA8);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    func_021E3208(p, 5);
    func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 1);
    func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 1);
    func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 1);
    MCSS_SetVanishFlag(OBJ(0));
    MCSS_SetVanishFlag(OBJ(1));
    MCSS_SetVanishFlag(OBJ(2));
    MCSS_SetVanishFlag(OBJ(3));
    func_021E2F34(WORK);
    func_021E2D70(WORK, 3);
    func_021E2FB0((char *)WORK);
    func_021D56E4(p, 0x2B5);
    func_021DFA60(((TradeUp *)p)->frame);
    func_021D8E84(p, (int)func_021D5B74);
    func_020435F4(0x18);
}


#undef WORK

#undef WORK
#define WORK ((u32 *)((TradeUp *)p)->work)







/*
 * Addresses are Black-image addresses.
 */
void func_021D5B74(u8 *p)
{
    func_021DFA60(((TradeUp *)p)->frame);
    func_021E3004(((TradeUp *)p)->work);
    func_021D8E84(p, (int)func_021D5B98);
}







void func_021D5B98(u8 *p)
{
    func_021DFA60(((TradeUp *)p)->frame);
    func_021D8E84(p, (int)func_021D5BB8);
}







void func_021D5BB8(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    func_021DFA60(FRAME);
    if (FRAME == func_021D56E0(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(3)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D56E0(4)) {
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D56E0(0x65)) {
        func_020515CC(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0xE)) {
        func_020515CC(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x483)) {
        func_020515CC(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[4], 4, func_021D5930, p);
    }
    if (FRAME == func_021D56E0(0x152)) {
        func_020515CC(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D56E0(0x2BC)) {
        func_020515CC(WORK[6], 6, func_021D5990, p);
    }
    if (FRAME == func_021D56E0(0x47F)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(0x10A)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x14), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x12D)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        MCSS_SetScale(OBJ(2), &v1);
    }
    if (FRAME == func_021D56E0(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        MCSS_SetScale(OBJ(3), &v2);
    }
    if (FRAME == func_021D56E0(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        func_021DFB4C(SLOT0, func_021D56E0(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        func_021DFB4C(SLOT1, func_021D56E0(0x1C), &v3);
    }
    if (FRAME == func_021D56E0(0x170)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0x2E), &v4, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag(OBJ(0));
        MCSS_SetPaletteFade(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        MCSS_SetPosition(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(0x67), &v5, HEAP);
        MCSS_GetScale(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        MCSS_SetScale(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        MCSS_SetPosition(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(0x67), &v6, HEAP);
        MCSS_GetScale(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        MCSS_SetScale(OBJ(1), &v6);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1F8)) {
        func_021DFB4C(SLOT0, func_021D56E0(0x80), (u8 *)SLOT0 + 0x28);
        func_021DFB4C(SLOT1, func_021D56E0(0x80), (u8 *)SLOT1 + 0x28);
    }
    if (FRAME == func_021D56E0(0x27D)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(7), &v7, HEAP);
    }
    func_021D56E0(0x48B);
    if (FRAME == func_021D56E0(0x48B + 3)) {
        if (((TradeUp *)p)->f11EE == 0) {
            func_021D5888(p, 3);
            func_021D5748(p, 3);
            MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
        } else {
            func_021D5888(p, 3);
            MCSS_SetVanishFlag(OBJ(3));
            func_021D5888(p, 1);
            func_021D5748(p, 3);
            MCSS_SetPaletteFade(OBJ(1), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == func_021D56E0(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D56E0(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (func_021D56E0(0x48E) < FRAME && ((TradeUp *)p)->f11EE != 0 && *(u32 *)&((TradeUp *)p)->f868 != 0
        && *(u32 *)(*(u32 *)&((TradeUp *)p)->f868 + 8) == 9) {
        MCSS_GetPosition(OBJ(1), &v8);
        MCSS_SetPosition(OBJ(3), &v8);
        MCSS_ResetVanishFlag(OBJ(3));
        MCSS_SetVanishFlag(OBJ(1));
        *(void **)((TradeUp *)p)->f868 = OBJ(3);
    }
    if (FRAME == func_021D56E0(0x4A0)) {
        MCSS_ResetAnmStopFlag(OBJ(3));
    }
    if (FRAME == func_021D56E0(0x28B)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0xA), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x2B5)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x380)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x3CA)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x4C1)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D56FC);
    }
    func_021DFC68(SLOT0, p);
    func_021DFC68(SLOT1, p);
    func_021DFC68(((TradeUp *)p)->f864, p);
    func_021DFC68(((TradeUp *)p)->f868, p);
}







void func_021D64F4(s8 *fade)
{
    s32_021D64F4 value;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        value = ((fade[3] - fade[2]) << 12) / fade[0];
        value = value * fade[1] / 4096;
        func_0207D658(0x04000050, 0x1E, value);
        func_0207D658(0x04001050, 0x1F, value);
    }
}







void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = func_02017E1C(mon, 7, 0);
    a = func_02017E1C(mon, 0xAB, 0);
    b = func_02017E1C(mon, 0x6F, 0);
    egg = func_02017E1C(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)func_0201ADE4((u16)a, (u16)b, ((TradeUp *)p)->heap);
        flag = func_0201AE1C((const struct Personal *)h, 0x10);
        func_0201AE14((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}







void func_021D6600(void *p)
{
    u32 v = ((struct Obj22682 *)((char *)((TradeUp *)p)->work))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22683 *)((char *)((TradeUp *)p)->work))->fB0 =
            (u32)func_0204B294((void *)((TradeUp *)p)->f9C4,
                          ((TradeUp *)p)->f8A8,
                          ((TradeUp *)p)->f88C,
                          ((TradeUp *)p)->f8BC,
                          &s, 0, ((TradeUp *)p)->heap);
        func_0204B92C((struct Obj *)((struct Obj22684 *)((char *)((TradeUp *)p)->work))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22685 *)((char *)((TradeUp *)p)->work))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}







void func_021D667C(void *p)
{
    void *h = func_020490F4(0x67, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((TradeUp *)p)->heap);
    ((TradeUp *)p)->f8BC = func_0204AF28(h, 1, 0, ((TradeUp *)p)->heap);
    func_02049238(h);
    ((struct Obj22686 *)((char *)((TradeUp *)p)->work))->fB0 = 0;
}







/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D66E8 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
void func_021D66E8(void *p)
{
    u8 *b = p;

    if (((struct Obj22687 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22688 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0);
    if (((struct Obj01725 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01725 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01725 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01725 *)b)->f8BC));
    }
    ((struct Obj01725 *)b)->f8A8 = 0;
    ((struct Obj01725 *)b)->f88C = 0;
    ((struct Obj01725 *)b)->f8BC = 0;
    ((struct Obj22689 *)((u8 *)((struct Obj01725 *)b)->fC))->fB0 = 0;
}






int func_021D6734(int a) { return a; }






void func_021D6738(u8 *p, u32 v) { ((TradeUp *)p)->frame = v; }






void func_021D6744(u8 *p) { ((TradeUp *)p)->f1094 = 1; }





void func_021D6750(u8 *p)
{
    func_021E3BB0((char *)p);
    if (((TradeUp *)p)->f854 == 1) {
        func_021D6544(p, p + 0x11ED, p + 0x11EF, ((TradeUp *)p)->f834, 1);
        func_021D6544(p, p + 0x11EE, p + 0x11F0, ((TradeUp *)p)->f830, 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 8);
            func_021D8E84(p, (int)func_021D67D4);
        } else {
            func_021D8E84(p, (int)func_021D67F8);
        }
    }
}





void func_021D67D4(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 8) != 0) {
        func_021D8E84(p, (int)func_021D67F8);
    }
}





void func_021D67F8(u8 *p)
{
    Vec a;
    Vec b;

    func_021D6738(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D8650, 0xF5);
    FADE[0] = func_021D6734(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D7CC4;
    func_021DFD24(SLOT0);
    SLOT0 = func_021DFB84(OBJ(0), func_021D6734(0x2A), &a, HEAP);
    b = d_021D7CD0;
    func_021DFD24(SLOT1);
    SLOT1 = func_021DFB84(OBJ(1), func_021D6734(0x54), &b, HEAP);
    func_02015F2C(OBJ(0), p, (void (*)(void))func_021DFD0C, 1);
    MCSS_SetPaletteFade(OBJ(1), 0, 0x10, (s8)(func_021D6734(0xE) / 16), 0);
    func_021E106C((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D6918);
}
