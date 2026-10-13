/*
 * function: DWCi_AOSSlInit
 * address:  0x021C07A8
 * packet:   pkt_ov016_021C07A8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AOSSlInit (libdwcutil.TWL.HYB.a(libaoss.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx 0x021D6414 arm ov016
 *   MIi_CpuClear16 0x02082A48 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   AOSSi_InitLocal 0x021B84E4 thumb ov016
 *   OS_Terminate 0x02088234 arm
 *   func_021C0954 0x021C0954 arm ov016
 *   func_021C0964 0x021C0964 arm ov016
 *   gLibaossBlock1 0x021DE564 data
 *   sLibAossDefaultName 0x021DA468 data
 */

#include "../include/G_AossCtl.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 version;
    u8 pad1;
    u16 len;
    char name[12];
    char rest[0xf4];
} Pi;

typedef struct {
    u16 kind;
    Pi pi;
    u16 f106;
    short f108;
    u16 f10a;
    short f10c;
    short f10e;
    u8 mac[6];
} Work;

extern struct AossCtl gLibaossBlock1;
extern char sLibAossDefaultName[12];

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void OS_GetMacAddress(u8 *mac);
extern int AOSSi_InitLocal(void *(*alloc)(u32), void (*free)(void *));
extern void OS_Terminate(void);
extern void *func_021C0954(u32 size);
extern void func_021C0964(void *ptr);

void DWCi_AOSSlInit(void)
{
    Pi pi;

    gLibaossBlock1.work = DWCi_HEAPlAllocEx(0x26c, 4);
    gLibaossBlock1.status = 0;
    MIi_CpuClear16(0, &pi, sizeof(Pi));
    pi.version = 0x50;
    pi.len = 12;
    MI_CpuCopy8(sLibAossDefaultName, pi.name, 12);
    ((Work *)gLibaossBlock1.work)->kind = 3;
    ((Work *)gLibaossBlock1.work)->pi = pi;
    ((Work *)gLibaossBlock1.work)->f106 = 1;
    ((Work *)gLibaossBlock1.work)->f108 = -1;
    ((Work *)gLibaossBlock1.work)->f10a = 1;
    ((Work *)gLibaossBlock1.work)->f10c = -1;
    ((Work *)gLibaossBlock1.work)->f10e = -1;
    OS_GetMacAddress(((Work *)gLibaossBlock1.work)->mac);
    if (AOSSi_InitLocal(func_021C0954, func_021C0964))
        OS_Terminate();
}
