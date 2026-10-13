/*
 * function: TOUCHPANEL_Create
 * address:  0x020357E0
 * packet:   pkt_020357E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Allocates the touched-icon work object (0x7c bytes), clears it, brings
 * the touch panel up and stores the calibration handed back by
 * TP_GetUserInfo.  When the user has no stored calibration (the call does
 * not answer 1) the four halfwords are filled with the firmware defaults
 * 0x2ae / 0x58c / 0xe25 / 0x1208; 0x58c is materialised as
 * `0x510 + 0x7c` because the size constant is still live in r6.  The
 * object pointer is published at 0x021469C4 and returned.
 *
 * The two bytes at +0x75/+0x76 are the state and the blinking flag of the
 * icon driver; the u16 pair at +0x58 is cleared before the panel is up.
 *
 * symbols:
 *   str_020A798C   0x020A798C  data
 *   g_021469C4     0x021469C4  data
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   TP_Init              0x0208A924  arm
 *   TP_GetUserInfo       0x0208A998  arm
 *   TP_SetCalibrateParam 0x0208AA2C  arm
 */
#include "../include/Obj07103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char str_020A798C[];
extern void *g_021469C4;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  TP_Init(void);
extern int   TP_GetUserInfo(u16 *info);
extern void  TP_SetCalibrateParam(u16 *info);

void *TOUCHPANEL_Create(u32 id)
{
    u16 info[4];
    void *p = func_02030734(id, 0x7c, 0, str_020A798C, 0x83);

    MI_CpuFill8(p, 0, 0x7c);
    ((struct Obj07103 *)p)->f58 = 0;
    ((struct Obj07103 *)p)->f5A = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    ((struct Obj07103 *)p)->f75 = 4;
    ((struct Obj07103 *)p)->f76 = 0;
    g_021469C4 = p;
    return p;
}
