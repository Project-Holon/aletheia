/*
 * function: IRC_RESULT_Exit
 * address: 0x021B7730
 * packet: pkt_ov105_021B7730
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes after return, before 021B7778.
 * symbols:
 *   IRC_RESULT_ExitRankFade 0x021B8598 thumb ov105
 *   IRC_RESULT_ExitTextWindow 0x021B7D90 thumb ov105
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   IRC_RESULT_ExitScreen 0x021B78A0 thumb ov105
 *   IRC_RESULT_ExitTextSystem 0x021B7C6C thumb ov105
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj22237.h"
typedef unsigned char u8;
extern void IRC_RESULT_ExitRankFade(void *);
extern void IRC_RESULT_ExitTextWindow(unsigned char *p);
extern void IRC_APPBAR_Delete(void *p);
extern void IRC_RESULT_ExitScreen(unsigned char *p);
extern void IRC_RESULT_ExitTextSystem(unsigned char *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
int IRC_RESULT_Exit(int a,int b,int c,u8 *p) {
 IRC_RESULT_ExitRankFade(p+0x128); IRC_RESULT_ExitTextWindow(p+0xd4);
 IRC_APPBAR_Delete((void *)(((struct Obj22237 *)p)->f188)); IRC_RESULT_ExitTextWindow(p+0xc0);
 IRC_RESULT_ExitScreen(p); IRC_RESULT_ExitTextSystem(p+0xb0);
 func_020315D4((struct S020315D4 *)a); func_020306F0(60); return 1;
}
