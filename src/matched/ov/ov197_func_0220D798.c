/*
 * function: func_0220D798
 * address: 0x0220D798
 * packet: pkt_ov197_0220D798
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj03906.h"
#include "../include/Obj25110.h"
#include "../include/Obj25111.h"
#include "../include/Obj25112.h"
#include "../include/Obj25113.h"
struct MsgBank;struct WordSet;struct U16Vec;
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct WordSet *GF_FONT_Create_EC64(unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
extern struct U16Vec *STRBUF_Create(unsigned,unsigned);
void func_0220D798(char *p){*(struct MsgBank * *)&((struct Obj03906 *)p)->fC=func_02045B38(0,2,17,((struct Obj25110 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct WordSet * *)&((struct Obj03906 *)p)->f10=GF_FONT_Create_EC64(((struct Obj25111 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);((struct Obj03906 *)p)->f18=PRINTSYS_QUE_Create((void *)((struct Obj25112 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);*(struct U16Vec * *)&((struct Obj03906 *)p)->f14=STRBUF_Create(512,((struct Obj25113 *)(*(char * *)&((struct Obj03906 *)p)->f0))->fC);}
