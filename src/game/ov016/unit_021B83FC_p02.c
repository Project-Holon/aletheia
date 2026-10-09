/*
 * file:     unit_021B83FC_p02.c
 * unit:     yes
 * function: func_021B84AC, alarmCallback, alarmCallback_021B84D0
 * address:  0x021B84AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B83FC   0x021B83FC  thumb  ov016
 *   OS_SendMessage               0x02085DBC  arm
 *   d_021DCE40                   0x021DCE40  data
 */
#include "../../matched/include/G_OSMessageQueue.h"

extern void func_021B83FC(int, int *);
extern void OS_SendMessage(void);
void func_021B84AC(int *p, int a, int c);
asm void alarmCallback(void);
asm void alarmCallback_021B84D0(void);
extern struct OSMessageQueue d_021DCE40;



/*
 * Store c, then tail-call func_021B83FC with a and p+1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B84AC.c \
 *       --func func_021B84AC --addr 0x021B84AC --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B84AC(int *p, int a, int c)
{
    *p = c;
    func_021B83FC(a, p + 1);
}



asm void alarmCallback(void)
{
	LDR R3, =OS_SendMessage
	ADD R1, R0, #0
	LDR R0, =0x021DCE40
	MOV R2, #0
	BX R3
}


asm void alarmCallback_021B84D0(void)
{
	LDR R3, =OS_SendMessage
	ADD R1, R0, #0
	LDR R0, =0x021DCE40
	MOV R2, #0
	BX R3
}
