/*
 * file:     unit_021C1488.c
 * unit:     yes
 * function: func_021C1488, func_021C14F4, func_021C1518, func_021C15D0, func_021C15FC, func_021C1614, DWCi_RAKUl_memFree
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021BC63C  0x021BC63C  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   func_02085A38  0x02085A38  arm
 *   gRakuStatus  0x021DE594  data
 *   DWCi_RAKUl_memFree  0x021C1624  arm  ov016
 *   func_021C15FC  0x021C15FC  arm  ov016
 *   func_021C1614  0x021C1614  arm  ov016
 *   func_021BC724 0x021BC724 thumb
 *   func_021BC7F0  0x021BC7F0  thumb  ov016
 *   func_021CF9BC  0x021CF9BC  arm  ov016
 *   DWCi_HEAPlAllocEx            0x021D6414  arm
 *   func_021D647C  0x021D647C  arm  ov016
 */
extern void *func_021D6414(unsigned long size, int align);
extern void OS_Terminate(void);
extern void func_02085A38(unsigned long msec);
extern void DWCi_RAKUl_memFree(void *ptr);
extern int func_021BC724(void);
extern void func_021D6438(void **mem);
extern int func_021BC7F0(int a);
extern void func_021CF9BC(void *param);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
void func_021C1488(void);
void func_021C14F4(void);
int func_021C1518(void);
void func_021C15D0(void);
/* Easy-setup (raku raku) work block: allocated once, the first word is the state. */
typedef struct {
    int state;
    int info0;
    int info1;
} RakuStatus;
extern int func_021BC63C(int priority, int maxAps, void (*notify)(RakuStatus *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
void cbConfig(RakuStatus *status);
static void *memAlloc(unsigned long size);
extern RakuStatus *gRakuStatus;
extern void func_021D647C(void *mem);
void DWCi_RAKUl_memFree(void *mem);


/*
 * sdk:      DWCi_RAKUlInit (libdwcutil.TWL.HYB.a(rakuraku.o))
 */
void func_021C1488(void)
{
	gRakuStatus = func_021D6414(sizeof(RakuStatus), -4);
	if (func_021BC63C(0xf, 0x40, cbConfig, memAlloc, DWCi_RAKUl_memFree, 0x800) != 1)
		OS_Terminate();
	func_02085A38(10);
}


/*
 * Post the event at 0x021DE594 when func_021BC724 does not report one.
 * Addresses are Black-image addresses.
 */
void func_021C14F4(void)
{
    if (func_021BC724() != 1)
        OS_Terminate();
    func_021D6438((void **)&gRakuStatus);
}


/*
 * sdk:      DWCi_RAKUlGetState (libdwcutil.TWL.HYB.a(rakuraku.o))
 */
int func_021C1518(void)
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
		if (func_021BC7F0((int)aossResult) != 1)
			OS_Terminate();
		if (aossResult[8] >= 0 && aossResult[8] <= 3 && aossResult[9] == 1)
			return 3;
		return 5;
	case 7:
		return 4;
	}
}


/*
 * sdk:      DWCi_RAKUlSetResult (libdwcutil.TWL.HYB.a(rakuraku.o))
 */
void func_021C15D0(void)
{
	char aossResult[0xe8];

	if (func_021BC7F0((int)aossResult) != 1)
		OS_Terminate();
	func_021CF9BC(aossResult);
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
    func_021D647C(mem);
}
