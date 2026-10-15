/*
 * function: BOX2_SEQ_StateCloseItemD
 * address: 0x021E7D04
 * packet: pkt_ov170_021E7D04
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_StatePmVoiceMenuB 0x021E95F8 thumb ov170
 *   BOX2_SEQ_StatePmVoiceMenuC 0x021E96E8 thumb ov170
 *   BOX2_SEQ_StatePmVoiceMenuD 0x021E9848 thumb ov170
 *   BOX2_SEQ_StateWaitPrint 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23914.h"
#include "../include/Obj23915.h"
#include "../include/Obj23916.h"
#include "../include/Obj23917.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BOX2_SEQ_StatePmVoiceMenuB(u8 *);
extern int BOX2_SEQ_StatePmVoiceMenuC(u8 *);
extern int BOX2_SEQ_StatePmVoiceMenuD(u8 *);
extern int BOX2_SEQ_StateWaitPrint(int);
int BOX2_SEQ_StateCloseItemD(u8 *p){switch(((struct Obj23914 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24){case 2:((struct Obj23915 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=BOX2_SEQ_StatePmVoiceMenuB(p);break;case 3:((struct Obj23916 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=BOX2_SEQ_StatePmVoiceMenuC(p);break;case 4:((struct Obj23917 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA198=BOX2_SEQ_StatePmVoiceMenuD(p);break;}return BOX2_SEQ_StateWaitPrint((int)p);}
