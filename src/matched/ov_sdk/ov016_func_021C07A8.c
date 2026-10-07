/*
 * function: func_021C07A8
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
 *   func_021D6414 0x021D6414 arm ov016
 *   MIi_CpuClear16 0x02082A48 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02087C6C 0x02087C6C arm
 *   func_021B84E4 0x021B84E4 thumb ov016
 *   func_02088234 0x02088234 arm
 *   func_021C0954 0x021C0954 arm ov016
 *   func_021C0964 0x021C0964 arm ov016
 *   g_021DE564 0x021DE564 data
 *   g_021DA468 0x021DA468 data
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

extern struct AossCtl g_021DE564;
extern char g_021DA468[12];

extern void *func_021D6414(u32 size, int alignment);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern void func_02087C6C(u8 *mac);
extern int func_021B84E4(void *(*alloc)(u32), void (*free)(void *));
extern void func_02088234(void);
extern void *func_021C0954(u32 size);
extern void func_021C0964(void *ptr);

void func_021C07A8(void)
{
    Pi pi;

    g_021DE564.work = func_021D6414(0x26c, 4);
    g_021DE564.status = 0;
    MIi_CpuClear16(0, &pi, sizeof(Pi));
    pi.version = 0x50;
    pi.len = 12;
    func_02082D44(g_021DA468, pi.name, 12);
    ((Work *)g_021DE564.work)->kind = 3;
    ((Work *)g_021DE564.work)->pi = pi;
    ((Work *)g_021DE564.work)->f106 = 1;
    ((Work *)g_021DE564.work)->f108 = -1;
    ((Work *)g_021DE564.work)->f10a = 1;
    ((Work *)g_021DE564.work)->f10c = -1;
    ((Work *)g_021DE564.work)->f10e = -1;
    func_02087C6C(((Work *)g_021DE564.work)->mac);
    if (func_021B84E4(func_021C0954, func_021C0964))
        func_02088234();
}
