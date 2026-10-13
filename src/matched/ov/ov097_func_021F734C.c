/*
 * function: VS_MULTI_LIST_CreateBgFrames
 * address: 0x021F734C
 * packet: pkt_ov097_021F734C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BGWINFRM_SetFrameData 0x0202CAC4 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   func_0204162C 0x0204162C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020414EC 0x020414EC arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   gVsMultiListSrcName 0x021F78C0 data a4
 */
#include "../include/Obj21995.h"
#include "../include/Obj21996.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
struct WinMgr;
struct Pair { void *data; u32 other; };
struct P {
    u8 *parent; u32 pad04; struct WinMgr *window; u8 pad0c[20];
    struct Pair images[6]; u8 pad50[0xa8]; void *mons[6];
};
extern const char gVsMultiListSrcName[];
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u32 func_0204162C(int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void func_020414EC(u32);
extern void MIi_CpuCopy16(const void *, void *, u32);
void VS_MULTI_LIST_CreateBgFrames(struct P *p)
{
    u16 i;
    u8 *palette, *buf;
    p->window = BGWINFRM_Create(2, 12, 0x71);
    for (i = 0; i < 6; i++) {
        BGWINFRM_AddFrame(p->window, i, 1, 16, 6);
        BGWINFRM_AddFrame(p->window, i + 6, 0, 16, 6);
        BGWINFRM_PutBmpWin(p->window, i + 6, p->images[i].data);
    }
    palette = (u8 *)func_0204162C(1);
    buf = func_02030734(0x8071, 0xc0, 0, gVsMultiListSrcName, 0x606);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + i * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (p->mons[i]) BGWINFRM_SetFrameData(p->window, i, buf);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + (i + 18) * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (!p->mons[i]) BGWINFRM_SetFrameData(p->window, i, buf);
    func_020307B0(buf);
    func_020414EC(1);
    if (((struct Obj21995 *)(p->parent))->f8 == 0) {
        for (i = 3; i < 6; i++) if (p->mons[i]) BGWINFRM_ChangePalette(p->window, i, 0, 0, 16, 6, 5);
    } else {
        for (i = 0; i < 3; i++) if (p->mons[i]) BGWINFRM_ChangePalette(p->window, i, 0, 0, 16, 6, 5);
    }
    if (((struct Obj21996 *)(p->parent))->f8 == 0) {
        BGWINFRM_PutFrame(p->window, 0, 0, 0);
        BGWINFRM_PutFrame(p->window, 1, 0, 6);
        BGWINFRM_PutFrame(p->window, 2, 0, 12);
        BGWINFRM_PutFrame(p->window, 6, 0, 0);
        BGWINFRM_PutFrame(p->window, 7, 0, 6);
        BGWINFRM_PutFrame(p->window, 8, 0, 12);
        BGWINFRM_PutFrame(p->window, 3, 32, 1);
        BGWINFRM_PutFrame(p->window, 4, 32, 7);
        BGWINFRM_PutFrame(p->window, 5, 32, 13);
        BGWINFRM_PutFrame(p->window, 9, 32, 1);
        BGWINFRM_PutFrame(p->window, 10, 32, 7);
        BGWINFRM_PutFrame(p->window, 11, 32, 13);
    } else {
        BGWINFRM_PutFrame(p->window, 0, -16, 0);
        BGWINFRM_PutFrame(p->window, 1, -16, 6);
        BGWINFRM_PutFrame(p->window, 2, -16, 12);
        BGWINFRM_PutFrame(p->window, 6, -16, 0);
        BGWINFRM_PutFrame(p->window, 7, -16, 6);
        BGWINFRM_PutFrame(p->window, 8, -16, 12);
        BGWINFRM_PutFrame(p->window, 3, 16, 1);
        BGWINFRM_PutFrame(p->window, 4, 16, 7);
        BGWINFRM_PutFrame(p->window, 5, 16, 13);
        BGWINFRM_PutFrame(p->window, 9, 16, 1);
        BGWINFRM_PutFrame(p->window, 10, 16, 7);
        BGWINFRM_PutFrame(p->window, 11, 16, 13);
    }
}
