/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ProcExit
 * address: 0x021B7748
 * packet: pkt_ov103_021B7748
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B7750 reads display control register.
 * symbols:
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitTrail 0x021B9174 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitWindow 0x021B80E4 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitScene 0x021B78EC thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitText 0x021B7FC8 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitExchange 0x021B8B1C thumb ov103
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj22174.h"
typedef unsigned char u8;
extern void IRC_APPBAR_Delete(void *p);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(void *p);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitScene(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitText(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(u8 *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int IRC_COMPATIBLE_TOUCH_TEST_ProcExit(int a, int b, int c, u8 *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    IRC_APPBAR_Delete((void *)(((struct Obj22174 *)p)->fA38));
    IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(p + 0x198);
    IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(p + 0x748);
    IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(p + 0x184);
    IRC_COMPATIBLE_TOUCH_TEST_ExitScene(p);
    IRC_COMPATIBLE_TOUCH_TEST_ExitText(p + 0x174);
    IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(p + 0x75c);
    func_020315D4((struct S020315D4 *)a);
    GFL_HEAP_DeleteChecked(55);
    return 1;
}
