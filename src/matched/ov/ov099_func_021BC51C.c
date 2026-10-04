/*
 * function: func_021BC51C
 * address: 0x021BC51C
 * packet: pkt_ov099_021BC51C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow at 0x021BC542.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 * prototype-evidence: r1 is forwarded unchanged from entry into BA928.
 */
#include "../include/Obj00008.h"
typedef unsigned int u32;
extern int func_021BA928(void *, int);
extern u32 func_020362DC(void);
int func_021BC51C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (func_020362DC() != 0) *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x44;
    return ret;
}
