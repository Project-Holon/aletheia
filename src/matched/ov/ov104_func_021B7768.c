/*
 * function: IRC_RHYTHM_Exit
 * address: 0x021B7768
 * packet: pkt_ov104_021B7768
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B7784 writes the hardware register at 0x04000050.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   IRC_RHYTHM_ExitParticles 0x021B8ADC thumb ov104
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   IRC_RHYTHM_ExitNetSync 0x021B874C thumb ov104
 *   IRC_RHYTHM_ExitCountdown 0x021B80F8 thumb ov104
 *   IRC_RHYTHM_ExitPulse 0x021B8EA4 thumb ov104
 *   IRC_RHYTHM_ExitTextWindow 0x021B7EC8 thumb ov104
 *   IRC_RHYTHM_ExitScreen 0x021B7940 thumb ov104
 *   IRC_RHYTHM_ExitTextSystem 0x021B7DAC thumb ov104
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj13741.h"
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void IRC_RHYTHM_ExitParticles(void *);
extern void IRC_APPBAR_Delete(void *p);
extern void IRC_RHYTHM_ExitNetSync(u8 *p);
extern void IRC_RHYTHM_ExitCountdown(void *);
extern void IRC_RHYTHM_ExitPulse(void *);
extern void IRC_RHYTHM_ExitTextWindow(u8 *p);
extern void IRC_RHYTHM_ExitScreen(u8 *p);
extern void IRC_RHYTHM_ExitTextSystem(u8 *p);
struct Proc;
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
int IRC_RHYTHM_Exit(int a,int b,int c,u8 *p) {
 func_02030EAC((struct Node *)(((struct Obj13741 *)p)->f8A4));IRC_RHYTHM_ExitParticles(p+0x278);
 *(volatile unsigned short *)0x04000050=0;
 IRC_APPBAR_Delete((void *)(((struct Obj13741 *)p)->f7AC));IRC_RHYTHM_ExitNetSync(p+0xe0);IRC_RHYTHM_ExitCountdown(p+0x7b0);IRC_RHYTHM_ExitPulse(p+0x7cc);IRC_RHYTHM_ExitTextWindow(p+0x7f0);IRC_RHYTHM_ExitTextWindow(p+0x7dc);IRC_RHYTHM_ExitTextWindow(p+0xcc);IRC_RHYTHM_ExitScreen(p);IRC_RHYTHM_ExitTextSystem(p+0xbc);func_020315D4((struct Proc *)a);GFL_HEAP_DeleteChecked(56);return 1;
}
