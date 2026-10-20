/*
 * file:     rakuraku.c
 * unit:     yes
 * function: DWCi_RAKUlInit, DWCi_RAKUlEnd, DWCi_RAKUlGetState, DWCi_RAKUlSetResult, cbConfig, memAlloc, DWCi_RAKUl_memFree
 * address:  0x021C1488
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlFree_                0x021D6438  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_RakurakuATERMi_ApConfigStart  0x021BC63C  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   OS_Sleep  0x02085A38  arm
 *   gRakuStatus  0x021DE594  data
 *   DWCi_RAKUl_memFree  0x021C1624  arm  ov016
 *   cbConfig  0x021C15FC  arm  ov016
 *   memAlloc  0x021C1614  arm  ov016
 *   ATERMi_ApConfigEnd 0x021BC724 thumb
 *   DWCi_RakurakuATERMi_ApConfigGetResult  0x021BC7F0  thumb  ov016
 *   DWCi_SETTINGlSetRaku  0x021CF9BC  arm  ov016
 *   DWCi_HEAPlFree2  0x021D647C  arm  ov016
 */
#include "../arm9/os_terminate_processor.h"
#include "../types.h"
#include "../arm9/os_thread.h"
extern void DWCi_RAKUl_memFree(void *ptr);
extern int ATERMi_ApConfigEnd(void);
#include "heap.h"
extern int DWCi_RakurakuATERMi_ApConfigGetResult(int a);
#include "setting.h"
void DWCi_RAKUlInit(void);
void DWCi_RAKUlEnd(void);
int DWCi_RAKUlGetState(void);
void DWCi_RAKUlSetResult(void);
/* Easy-setup (raku raku) work block: allocated once, the first word is the state. */
typedef struct {
    int state;
    int info0;
    int info1;
} RakuStatus;
extern int DWCi_RakurakuATERMi_ApConfigStart(int priority, int maxAps, void (*notify)(RakuStatus *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
void cbConfig(RakuStatus *status);
extern RakuStatus *gRakuStatus;

/*
 * sdk:      DWCi_RAKUlInit (libdwcutil.TWL.HYB.a(rakuraku.o))
 */

static void *memAlloc(unsigned long size);
void DWCi_RAKUlInit(void)
{
	gRakuStatus = DWCi_HEAPlAllocEx(sizeof(RakuStatus), -4);
	if (DWCi_RakurakuATERMi_ApConfigStart(0xf, 0x40, cbConfig, memAlloc, DWCi_RAKUl_memFree, 0x800) != 1)
		OS_Terminate();
	OS_Sleep(10);
}

/*
 * Post the event at 0x021DE594 when ATERMi_ApConfigEnd does not report one.
 * Addresses are Black-image addresses.
 */
void DWCi_RAKUlEnd(void)
{
    if (ATERMi_ApConfigEnd() != 1)
        OS_Terminate();
    DWCi_HEAPlFree_((void **)&gRakuStatus);
}

/*
 * sdk:      DWCi_RAKUlGetState (libdwcutil.TWL.HYB.a(rakuraku.o))
 */
int DWCi_RAKUlGetState(void)
{
	int aossResult[0x3a];

	switch (gRakuStatus->state) {
	case 0:
	case 1:
	case 3:
	case 5:
		return 0;
	case 2:
		return 1;
	case 4:
		return 2;
	case 6:
		if (DWCi_RakurakuATERMi_ApConfigGetResult((int)aossResult) != 1)
			OS_Terminate();
		if (aossResult[8] >= 0 && aossResult[8] <= 3 && aossResult[9] == 1)
			return 3;
		return 5;
	case 7:
		return 4;
	}
	/* states above 7 skip every case and leave r0 as the caller had it; a `return 0;` here changes the bytes (docs/DEBT.tsv, missing-return) */
}

/*
 * sdk:      DWCi_RAKUlSetResult (libdwcutil.TWL.HYB.a(rakuraku.o))
 */
void DWCi_RAKUlSetResult(void)
{
	char aossResult[0xe8];

	if (DWCi_RakurakuATERMi_ApConfigGetResult((int)aossResult) != 1)
		OS_Terminate();
	DWCi_SETTINGlSetRaku(aossResult);
}

void cbConfig(RakuStatus *status)
{
    *gRakuStatus = *status;
}

static void *memAlloc(unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}

void DWCi_RAKUl_memFree(void *mem)
{
    DWCi_HEAPlFree2(mem);
}
