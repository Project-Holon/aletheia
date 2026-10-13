/*
 * function: TRCARD_SYS_StateStartEditProc
 * address: 0x0216F2E0
 * packet: pkt_ov010_0216F2E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_Create 0x02031324 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   PROCSYS_Push 0x02031348 arm
 *   gPmsInputProcData 0x021C39D4 data ov110 a4
 *   ov110_id 0x0000006E data a1
 * Interface: 02031324 veneer forwards heap in r0 and returns allocation from
 * 02031354; 02031348 forwards all four arguments to 020314F4.
 */
#include "../include/Obj01640.h"
#include "../include/Obj19155.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *PROCSYS_Create(int a0);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void PROCSYS_Push(void *,u32,const void *,void *);
extern const u32 gPmsInputProcData[];
extern char ov110_id[];
int TRCARD_SYS_StateStartEditProc(char *p) { if (((struct Obj01640 *)p)->f8==0) ((struct Obj01640 *)p)->f8=PROCSYS_Create((u16)(((struct Obj01640 *)p)->f0)); ((struct Obj01640 *)p)->fC=GAME_DATA_GetSaveControl(((struct Obj19155 *)(*(char * *)&((struct Obj01640 *)p)->f18))->f4); PROCSYS_Push(((struct Obj01640 *)p)->f8,(u32)ov110_id,gPmsInputProcData,p+12); return 4; }
