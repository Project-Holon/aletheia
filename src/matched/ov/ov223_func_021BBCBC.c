/*
 * function: PSEL_GRAPHIC_StateExit
 * address: 0x021BBCBC
 * packet: pkt_ov223_021BBCBC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword clear at021BBCC2/021BBCC8 to04000050/04001050.
 * symbols:
 *   PSEL_ClearWin3 0x021BB35C thumb ov223
 *   PSEL_NopBgDelete 0x021BAC6C thumb ov223
 *   PSEL_ClearBgLayer2 0x021BABFC thumb ov223
 *   PSEL_DeleteListAnime 0x021B98F4 thumb ov223
 */
#include "../include/Obj05570.h"
extern void PSEL_ClearWin3(char *p);
extern void PSEL_DeleteListAnime(char *p);
extern void PSEL_NopBgDelete(unsigned char *);
extern int PSEL_ClearBgLayer2(unsigned char *);
int PSEL_GRAPHIC_StateExit(unsigned char *p){*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;PSEL_ClearWin3((char *)p);PSEL_NopBgDelete(p);PSEL_ClearBgLayer2(p);PSEL_DeleteListAnime((char *)p);((struct Obj05570 *)p)->f10=0;return 7;}
