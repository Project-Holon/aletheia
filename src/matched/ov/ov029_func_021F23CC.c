/*
 * function: C_GEAR_LoadCustomBackground
 * address:  0x021F23CC
 * packet:   pkt_ov029_021F23CC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * base is a u32 holding (u16)p->f14 and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   func_02009210  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   MUSICAL_DIST_SAVE_IsFooterSet  0x0200C6F0  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040AE0  0x02040AE0  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021F3554     0x021F3554  data  a4
 */
#include "../include/Obj20396.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021F3554;

extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
struct Big;
struct Ctx;
struct Sub02009210Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct Ctrl;
extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct Ctrl *sv, u32 id, u8 heap, void *buf, u32 size);
struct Sub020090B0Obj;
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern u16 func_0200910C(const struct Sub020090B0Obj *obj);
struct Buf2000;
extern u32 MUSICAL_DIST_SAVE_IsFooterSet(struct Buf2000 *p);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern u32 BG_SYS_GetBuf(int channel);
extern void func_020409B4(u32 a);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *sv, u32 id);
extern u32 func_020307B0(void *p);

int C_GEAR_LoadCustomBackground(u8 *p, int a)
{
    int result;
    u32 h;
    u16 crc;
    u32 base;
    u16 x;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = func_02030734(0x70, 0x3000, 0, (const char *)&d_021F3554, 0x104E);
    h = (u32)GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)a));
    if (SAVE_CONTROL_LoadExtraSaveWithBuffer((struct Ctrl *)h, 4, 0x70, buf, 0x3000) == 1) {
        crc = GF_STANDARD_SetupCalc(buf, 0x2600);
        x = func_0200910C((const struct Sub020090B0Obj *)func_02009210((void *)h));
        base = (u16)((struct Obj20396 *)p)->f14;
        if (crc == x && MUSICAL_DIST_SAVE_IsFooterSet((struct Buf2000 *)buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                func_02040B1C(6, buf + i * 0x220, 0x220, base + (i + 5) * 0x20);
            }
            func_02040E78(6, buf + 0x1FE0, 0x20, 0x140);
            func_02040AE0(5, buf + 0x2000, 0x600);
            pal = (u16 *)BG_SYS_GetBuf(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)base;
            }
            func_020409B4(5);
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 4);
    func_020307B0(buf);
    return result;
}
