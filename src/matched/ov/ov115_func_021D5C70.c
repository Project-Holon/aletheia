/*
 * function: WIFILOGIN_MSG_IsPrintDone
 * address: 0x021D5C70
 * packet: pkt_ov115_021D5C70
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 */
#include "../include/Obj08042.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct Blk {u8 first,pad[3]; u32 flags;} Blk;
extern int PRINTSYS_CTRL_Update(Blk *,void *);
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
int WIFILOGIN_MSG_IsPrintDone(u8 *p) { int result=1; if(((struct Obj08042 *)p)->f38) { result=PRINTSYS_CTRL_Update((Blk *)(p+60),((struct Obj08042 *)p)->f38); if(result) { PRINTSYS_PrintStreamDelete(((struct Obj08042 *)p)->f38); ((struct Obj08042 *)p)->f38=0; } } return result; }
