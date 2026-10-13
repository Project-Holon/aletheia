/*
 * function: func_021B99A4
 * address: 0x021B99A4
 * packet: pkt_ov110_021B99A4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two-byte zero alignment padding follows the compiled function.
 * symbols:
 *   PMS_WORD_GetString 0x02024810 thumb
 */
#include "../include/Obj22312.h"
extern void PMS_WORD_GetString(char *,int,int);
void func_021B99A4(unsigned int a,unsigned int b,unsigned int c,int d) { unsigned int value; value=*(unsigned int *)(a+b*4+0x38); PMS_WORD_GetString(*(char * *)&((struct Obj22312 *)a)->f4,*(unsigned short *)(a+(value+c)*2+0x68),d); }
