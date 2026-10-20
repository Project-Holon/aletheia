/*
 * file:     libaoss.c
 * unit:     yes
 * function: DWCi_AOSSlInit, DWCi_AOSSlEnd, DWCi_AOSSlStart, aossAlloc, aossFree
 * address:  0x021C07A8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      aossFree (libdwcutil.TWL.HYB.a libaoss.o, static void aossFree(void *ptr))
 * Free hook DWCi_AOSSlInit (DWCi_AOSSlInit) passes to AOSSi_InitLocal next to
 * aossAlloc (0x021C0954).
 *
 * symbols:
 *   DWCi_HEAPlAllocEx 0x021D6414 arm ov016
 *   MIi_CpuClear16 0x02082A48 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   AOSSi_InitLocal 0x021B84E4 thumb ov016
 *   OS_Terminate 0x02088234 arm
 *   aossAlloc 0x021C0954 arm ov016
 *   aossFree 0x021C0964 arm ov016
 *   gLibaossBlock1 0x021DE564 data
 *   sLibAossDefaultName 0x021DA468 data
 *   AOSSi_EndLocal 0x021B85A8  thumb  ov016
 *   DWCi_SETTINGlSetAoss  0x021CFABC  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gLibaossBlock2     0x021DE568  data
 *   AOSSi_Init     0x021B61D0  thumb  ov016
 *   DWCi_HEAPlFree2  0x021D647C  arm
 */
#define GAME_TYPES_U32_LONG
#include "../../matched/include/G_AossCtl.h"

#include "../types.h"

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
    u16 reserved106;
    short reserved108;
    u16 reserved10a;
    short reserved10c;
    short reserved10e;
    u8 mac[6];
    unsigned char state;      /* 0x116 */
    unsigned char area[1];    /* 0x117 */
} LibAossWork;

typedef struct AossCtl AossCtl;

#include "../arm9/mi_memory.h"
#include "../arm9/os_ownerinfo.h"
#include "aosslink.h"
#include "../arm9/os_terminate_processor.h"
extern void aossFree(void *ptr);
#include "setting.h"
#include "heap.h"
struct aoss_info;
#include "aoss.h"
void DWCi_AOSSlInit(void);
void DWCi_AOSSlEnd(int a);
int DWCi_AOSSlStart(void);
void *aossAlloc(unsigned long size);
void aossFree(void *ptr);
extern struct AossCtl gLibaossBlock1;
extern char sLibAossDefaultName[12];
extern void *gLibaossBlock2;

/*
 * sdk:      DWCi_AOSSlInit (libdwcutil.TWL.HYB.a(libaoss.o))
 */

void DWCi_AOSSlInit(void)
{
    Pi pi;

    gLibaossBlock1.work = DWCi_HEAPlAllocEx(0x26c, 4);
    gLibaossBlock1.status = 0;
    MIi_CpuClear16(0, &pi, sizeof(Pi));
    pi.version = 0x50;
    pi.len = 12;
    MI_CpuCopy8(sLibAossDefaultName, pi.name, 12);
    ((LibAossWork *)gLibaossBlock1.work)->kind = 3;
    ((LibAossWork *)gLibaossBlock1.work)->pi = pi;
    ((LibAossWork *)gLibaossBlock1.work)->reserved106 = 1;
    ((LibAossWork *)gLibaossBlock1.work)->reserved108 = -1;
    ((LibAossWork *)gLibaossBlock1.work)->reserved10a = 1;
    ((LibAossWork *)gLibaossBlock1.work)->reserved10c = -1;
    ((LibAossWork *)gLibaossBlock1.work)->reserved10e = -1;
    OS_GetMacAddress(((LibAossWork *)gLibaossBlock1.work)->mac);
    if (AOSSi_InitLocal(aossAlloc, aossFree))
        OS_Terminate();
}

void DWCi_AOSSlEnd(int a)
{
    AOSSi_EndLocal();
    if (a) {
        if (((LibAossWork *)gLibaossBlock1.work)->state == 0 && gLibaossBlock1.status == 1)
            DWCi_SETTINGlSetAoss(((LibAossWork *)gLibaossBlock1.work)->area);
    }
    DWCi_HEAPlFree_(&gLibaossBlock2);
}

int DWCi_AOSSlStart(void)
{
    if (AOSSi_Init(gLibaossBlock1.work) == 0) {
        gLibaossBlock1.status = 1;
        return 1;
    }
    if (((LibAossWork *)gLibaossBlock1.work)->state == 1 || (unsigned char)(((LibAossWork *)gLibaossBlock1.work)->state + 0xFD) <= 2)
        return 0;
    return 2;
}

void *aossAlloc(unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}

void aossFree(void *ptr)
{
    DWCi_HEAPlFree2(ptr);
}
