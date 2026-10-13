/*
 * file:     pokemontrade_demo_middle.c
 * unit:     yes
 * function: func_021D6918, func_021D6AD4, func_021D6BA4, func_021D6C78, func_021D6CA8, func_021D6CC4, func_021D6E04, func_021D6E6C, func_021D6EAC, func_021D6ECC, func_021D6F0C, func_021D6F2C, func_021D6F90, func_021D7100, func_021D7118
 * address:  0x021D6918
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
 *   func_021D64F4  0x021D64F4  thumb  ov118
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D6734  0x021D6734  thumb  ov118
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D6738  0x021D6738  thumb  ov118
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   d_021D82C0     0x021D82C0  data
 *   d_021D8470     0x021D8470  data
 *   d_021D8880     0x021D8880  data
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
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
 *   func_021D66E8  0x021D66E8  thumb  ov118
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 *   d_021D7CDC     0x021D7CDC  data a4
 *   d_021D8398     0x021D8398  data a4
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *   func_021D6744  0x021D6744  thumb
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   func_021D6750  0x021D6750  thumb
 *   func_021DC720  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_021E3E40  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   func_021E5284  0x021E5284  thumb
 *   func_021E35A0  0x021E35A0  thumb ov119
 *   func_021E2F34  0x021E2F34  thumb
 *   func_021E2FB0  0x021E2FB0  thumb ov119
 *   func_021E2D70  0x021E2D70  thumb
 *   d_021D866C  0x021D866C  data
 *   func_021E3004  0x021E3004  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *   func_021D7130  0x021D7130  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 */
#include "../../matched/include/Obj05325.h"
#include "../../matched/include/Obj00984.h"
#include "../../matched/include/Obj01725.h"
#include "../../matched/include/Obj13881.h"
#include "../../matched/include/Obj01149.h"
#include "../../matched/include/Obj13882.h"
#include "../../matched/include/Obj22692.h"
#include "../../matched/include/Obj22693.h"
#include "../../matched/include/Obj13883.h"
#include "../../matched/include/Obj22694.h"
#include "../../matched/include/Obj22695.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22696.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define FLAG(i) (((int *)(p + 0x854))[i])
#define WORK (*(u8 **)(p + 0xc))
struct WordSet;
struct MsgBank;
struct IcaAnime;
struct Rec12;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u32 v[4];
} Quad;

extern void func_021D64F4(s8 *fade);
extern void func_021DFC68(void *p, int a1);
extern int func_021D6734(int);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021E64B8(void *p);
extern void func_021E4888(char *p);
extern void func_021E2680(char *p);
extern void func_021D6738(u8 *p, u32 v);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void func_021D8E84(void *p, int next);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021E0FF4(void *p, int a, int b);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int func_021E12AC(char *p);
extern void func_021E1098(char *p);
extern void func_021E36D8(void *p, int a);
extern void func_021D66E8(void *);
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021DFDA0(void *p);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);
extern int BUTTON_MAN_GetUserData(void *p);
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *, struct Rec12 *);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void func_021D6744(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void func_021D6750(u8 *p);
extern void func_021DC720(void *p);
extern void CLACT_ExitSystem(void);
extern void func_021E3E40(void *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E5284(void *p, int a);
extern void func_021E35A0(void *p, int a, int b, void *mon, int c);
extern void func_021E2F34(void *w);
extern void func_021E2FB0(char *p);
extern void func_021E2D70(void *w, int a);
extern void func_021E3004(char *p);
extern void func_021E3208(void *p, int a);
extern void func_021D7130(u8 *p);
void func_021D6918(u8 *p);
void func_021D6AD4(u8 *p);
void func_021D6BA4(u8 *p);
void func_021D6C78(void *p);
void func_021D6CA8(void *p, int a1);
void func_021D6CC4(void *a0, int a1);
void func_021D6E04(void *p, int idx);
void func_021D6E6C(void *obj, int on);
void func_021D6EAC(void *p);
void func_021D6ECC(void *obj, int on);
void func_021D6F0C(void *p);
void func_021D6F2C(u8 *p);
void func_021D6F90(u8 *p);
void func_021D7100(u8 *p);
void func_021D7118(u8 *p);
extern const u8 d_021D82C0[];
extern const u8 d_021D8470[];
extern u8 d_021D8880[];
extern const Quad d_021D7CDC;
extern const u32 d_021D8398[];
extern const char d_021D866C[];


void func_021D6918(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D64F4(*(s8 * *)&((struct Obj05325 *)p)->f818);
    func_021DFC68((void *)(((struct Obj05325 *)p)->f85C), (int)p);
    func_021DFC68((void *)(((struct Obj05325 *)p)->f860), (int)p);
    if (FRAME > func_021D6734(0x2A)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0);
        func_021E64B8(p);
        func_021E4888((char *)p);
        func_021E2680((char *)p);
        func_021D6738(p, 0);
        mon = func_021D8FA4(p, func_021D8AA8(p));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((void **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((struct Obj05325 *)p)->f11ED == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v1));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05325 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v1, d_021D8880, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D82C0, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v2));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05325 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v2, d_021D8880, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D8470, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D6BA4);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D6AD4(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00984 *)p)->f5F4);
    if (((struct Obj00984 *)p)->f118C == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x98, (void *)(((struct Obj00984 *)p)->f73C));
    } else if (((struct Obj00984 *)p)->f118C == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x9B, (void *)(((struct Obj00984 *)p)->f73C));
    } else if (((struct Obj00984 *)p)->f11ED != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x82, (void *)(((struct Obj00984 *)p)->f73C));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x81, (void *)(((struct Obj00984 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00984 *)p)->f724, 0, func_021D8FA4(p, func_021D8AA8(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00984 *)p)->f724), 1, (void *)(((struct Obj00984 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00984 *)p)->f724), (void *)(((struct Obj00984 *)p)->f738), (void *)(((struct Obj00984 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    func_021E0FF4(p, 1, 0);
    func_021E7208(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void func_021D6BA4(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D6AD4(p);
    }
    if (((struct Obj00984 *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC((char *)p) != 0) {
        func_021E1098((char *)p);
        if (((struct Obj00984 *)p)->f11ED == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D6F90);
    }
    func_021DFC68((void *)SLOT0, (int)p);
}


void func_021D6C78(void *p)
{
    func_021D66E8(p);
    func_021E3034(((struct Obj01725 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01725 *)p)->fC);
    func_020307B0(((struct Obj01725 *)p)->fC);
    ((struct Obj01725 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}


void func_021D6CA8(void *p, int a1)
{
    void *q = ((struct Obj13881 *)p)->f85C;
    if (q != 0) {
        func_020307B0(q);
        ((struct Obj13881 *)p)->f85C = 0;
    }
}


/*
 * Lever: own callee 021DFBB4 takes the table as argument four and u16 heap
 * as argument five. Correct order and a word-aligned three-word output
 * buffer settle the saved registers; nonzero 11F0 arms come first. Bare
 * aligned data hints resolve the contested table through sole-ref/data.
 *
 * Addresses are Black-image addresses.
 */
void func_021D6CC4(void *a0, int a1)
{
    void *x;
    u32 buf[3];

    x = func_021D8FA4(a0, 1 - func_021D8AA8(a0));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj01149 *)a0)->f11EE == 0) {
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x28, buf, (void *)d_021D8470, ((struct Obj01149 *)a0)->f5F4);
        return;
    } else {
        Quad t;
        u32 r6;

        t = d_021D7CDC;
        r6 = ((u32 *)((char *)a0 + 0x844))[t.v[a1]];
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)r6, (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)func_021DFBB4((void *)r6, (void *)0x12, buf, (void *)d_021D8398, ((struct Obj01149 *)a0)->f5F4);
    }
}


void func_021D6E04(void *p, int idx)
{
    u32 vec[3];
    MCSS_ResetVanishFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    MCSS_SetPosition((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    MCSS_SetAnmStopFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    MCSS_GetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    MCSS_SetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
}


void func_021D6E6C(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22692 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22693 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}


void func_021D6EAC(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D6E6C);
}


void func_021D6ECC(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22694 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22695 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}


void func_021D6F0C(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D6ECC);
}


void func_021D6F2C(u8 *p)
{
    u32 t;

    func_021D6744(p);
    FLAG(0) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(0), 0);
    FLAG(1) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(1), 0);
    if (func_021D8AA8(p)) {
        t = OBJ(0);
        OBJ(0) = OBJ(1);
        OBJ(1) = t;
    }
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D6750);
}


void func_021D6F90(u8 *p)
{
    func_021DC720(p);
    CLACT_ExitSystem();
    func_021E3E40(p);
    ((struct Obj00001 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D866C, 0x9D);
    *(u16 *)(WORK + 0xBA) = HEAP;
    func_021E5284(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    if (func_021D8AA8(p)) {
        func_021E35A0(p, 1, 0, func_021D8FA4(p, 1), 0);
        func_021E35A0(p, 2, 0, func_021D8FA4(p, 0), 0);
        func_021E35A0(p, 3, 1, func_021D8FA4(p, 1), 0);
    } else {
        func_021E36C8(p, 1, 0, func_021D8FA4(p, 1), 0);
        func_021E36C8(p, 2, 0, func_021D8FA4(p, 0), 0);
        func_021E36C8(p, 3, 1, func_021D8FA4(p, 1), 0);
    }
    MCSS_GetScale((void *)OBJ(0), (u32 *)(WORK + 0x60));
    MCSS_GetScale((void *)OBJ(1), (u32 *)(WORK + 0x6C));
    MCSS_GetScale((void *)OBJ(2), (u32 *)(WORK + 0x78));
    MCSS_GetScale((void *)OBJ(3), (u32 *)(WORK + 0x84));
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    func_021E2F34(WORK);
    func_021E2FB0((char *)WORK);
    func_021E2D70(WORK, 0);
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D7100);
}


void func_021D7100(u8 *p)
{
    func_021E3004(((struct Obj22696 *)p)->fC);
    func_021D8E84(p, (int)func_021D7118);
}


void func_021D7118(u8 *p)
{
    func_021E3208(p, 3);
    func_021D8E84(p, (int)func_021D7130);
}
