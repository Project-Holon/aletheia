/*
 * function: TRCARD_SYS_StateWaitCardProc
 * address: 0x0216F2B4
 * packet: pkt_ov010_0216F2B4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent: two-byte zero alignment padding at 0216F2DE.
 * symbols:
 *   TRCARD_SYS_RunChildProc 0x0216F088 thumb ov010
 */
#include "../include/Obj01640.h"
#include "../include/Obj19154.h"
extern int TRCARD_SYS_RunChildProc(int a0);
int TRCARD_SYS_StateWaitCardProc(char *p) { int v; if (!TRCARD_SYS_RunChildProc((int)(p+8))) return 2; v=((struct Obj19154 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC; if(v==1) return 3; if(v==2) return 5; return 7; }
