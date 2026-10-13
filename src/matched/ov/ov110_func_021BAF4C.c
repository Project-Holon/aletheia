/*
 * function: func_021BAF4C
 * address: 0x021BAF4C
 * packet: pkt_ov110_021BAF4C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   MSGSEARCH_Delete 0x021B6CCC thumb ov067
 */
#include "../include/Obj13778.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Rec;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void MSGSEARCH_Delete(int *);
void func_021BAF4C(unsigned p) { int i; STRBUF_Delete(((struct Obj13778 *)p)->fAD0);MSGSEARCH_Delete(*(int * *)&((struct Obj13778 *)p)->f78);for(i=0;i<27;i++)MSGDATA_Delete(*(void **)(p+i*4+0xc));func_020307B0((void *)p); }
