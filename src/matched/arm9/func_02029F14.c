/*
 * function: RINGTONE_SYS_Create
 * address:  0x02029F14
 * packet:   pkt_02029E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02029F6C label
 * blocker:  020A76BC literal
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sRingtoneSysFileName     0x020A76BC  data
 *   gRingtone     0x02146944  data
 *   RINGTONE_SYS_RegisterSleepCallbacks  0x02029F6C  thumb
 */
#include "../include/Obj11304.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char   sRingtoneSysFileName[];
extern u32   *gRingtone;
extern void   RINGTONE_SYS_RegisterSleepCallbacks(void);

u32 *RINGTONE_SYS_Create(u32 a0, u32 a1)
{
    u32 *p = func_02030734(a0, 0xc, 1, sRingtoneSysFileName, 0x72);

    ((struct Obj11304 *)p)->f4 = 0;
    p[2] = a1;
    gRingtone = p;
    RINGTONE_SYS_RegisterSleepCallbacks();
    return p;
}
