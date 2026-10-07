/*
 * file:     unit_0216A1F4_p02.c
 * unit:     yes
 * function: func_0216A3B8, func_0216A404, func_0216A42C, func_0216A460
 * address:  0x0216A3B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *   stpLoginCnt    0x021AA874  data
 *   func_02178E70  0x02178E70  arm  ov009
 *   func_02178DA4  0x02178DA4  arm  ov009
 *   g_021AA874  0x021AA874  data
 *   func_02178EF4  0x02178EF4  arm  ov009
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02059F54(int error, int errorCode);
extern void func_02178EF4(void);
void func_0216A3B8(int error, int errorCode);
void func_0216A404(void);
void func_0216A42C(void);
int func_0216A460(int result);
extern char *stpLoginCnt;


/*
 * sdk:      DWCi_StopLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_HandleGPError (0x0216BD04).
 */
void func_0216A3B8(int error, int errorCode)
{
    if (stpLoginCnt == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (*(int *)(stpLoginCnt + 0x14) != 0) {
        (*(void (*)(int, int, int))(*(int *)(stpLoginCnt + 0x14)))(error, 0,
            *(int *)(stpLoginCnt + 0x18));
    }
    func_0216A42C();
}


/*
 * Clears the word at 0x021AA874 after func_02178DA4 when func_02178E70 reports zero.
 */
void func_0216A404(void)
{
    extern int g_021AA874;
    int func_02178E70(void);
    void func_02178DA4(void);
    if (func_02178E70() == 0) func_02178DA4();
    g_021AA874 = 0;
}


/*
 * sdk:      DWCi_CloseLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_StopLogin (0x0216A3B8).
 */
void func_0216A42C(void)
{
    if (stpLoginCnt == 0) return;
    func_02178EF4();
    *(int *)(stpLoginCnt + 4) = 0;
    *(int *)(stpLoginCnt + 0x30) = 0;
}


/*
 * sdk:      DWCi_HandleGPError (libdwcmatch.TWL.HYB.a(dwc_login.o))
 */
int func_0216A460(int result)
{
	int dwcError;
	int errorCode;

	if (result == 0)
		return 0;
	switch (result) {
	case 1:
		dwcError = 9;
		errorCode = -1;
		break;
	case 2:
		dwcError = 9;
		errorCode = -2;
		break;
	case 3:
		dwcError = 6;
		errorCode = -10;
		break;
	case 4:
		dwcError = 6;
		errorCode = -20;
		break;
	}
	func_0216A3B8(dwcError, errorCode - 61000);
	return result;
}
