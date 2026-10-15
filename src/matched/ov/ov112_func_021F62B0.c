/*
 * function: MUSICAL_MCSS_SetMCAnim
 * address: 0x021F62B0
 * packet: pkt_ov112_021F62B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NNS_G2dGetAnimSequenceByIdx 0x020627D8 arm
 *   MUSICAL_MCSS_InitMCAnim 0x021F659C thumb ov112
 *   NNS_G2dSetAnimSequenceToMCAnimation 0x0206469C arm
 */
#include "../include/Obj00722.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct AnimBank;
struct AnimSequence;
extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx); extern void MUSICAL_MCSS_InitMCAnim(char *,int); extern void NNS_G2dSetAnimSequenceToMCAnimation(void *,void *);
void MUSICAL_MCSS_SetMCAnim(char *p,u32 n) {void *a; a=NNS_G2dGetAnimSequenceByIdx(((struct Obj00722 *)p)->f1C,n);MUSICAL_MCSS_InitMCAnim(p,1);NNS_G2dSetAnimSequenceToMCAnimation(p+40,a);}
