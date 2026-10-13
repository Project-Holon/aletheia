/*
 * function: func_02212854
 * address: 0x02212854
 * packet: pkt_ov199_02212854
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: EA04 consumes the live return register from E9F4, with no new setup.
 * lever: derive an integer offset before adding the base, then reduce the enum.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_0200EA04 0x0200EA04 thumb
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   d_02213D04 0x02213D04 data a1 ov199
 */
#include "../include/Obj06657.h"
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, int, int);
typedef unsigned short u16;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E9F4(void *p);
extern int func_0200EA04(int);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned, unsigned);
extern const char d_02213D04[];
typedef enum { tag_2854 = 0x2c0 } Offset2854;
int *func_02212854(int unused, unsigned heap, char *ctx)
{
    Offset2854 offset = tag_2854;
    int *p = func_02030734(heap, 0x44, 0, d_02213D04, tag_2854);
    MI_CpuFill8(p, 0, 0x44);
    p[2] = (int)(ctx + 4);
    p[3] = ((struct Obj06657 *)ctx)->f20;
    p[0] = ((struct Obj06657 *)ctx)->f1C - 2;
    p[5] = ((struct Obj06657 *)ctx)->f28;
    p[6] = ((struct Obj06657 *)ctx)->f2C;
    p[7] = (int)(ctx + 0x40);
    p[8] = (int)(ctx + (offset - 0xf4));
    offset -= 0xf0;
    p[9] = (int)(ctx + offset);
    p[15] = (int)(ctx + 0x7d4);
    p[10] = (int)(ctx + 0x8a8);
    p[11] = (int)(ctx + 0x1b4);
    p[12] = (int)(ctx + 0x224);
    p[13] = (int)(ctx + 0x22c);
    p[14] = (int)(ctx + 0x778);
    p[16] = (int)(ctx + 0x8ac);
    {
        void *q = GAME_DATA_GetSaveControl(((struct Obj06657 *)ctx)->f4);
        p[4] = func_0200EA04((int)func_0200E9F4(q));
    }
    if (GFL_USE_GetBgmNo() != 0x487) GFL_USE_CancelChangeAndPlayBgm(0x487, 0xffff);
    return p;
}
