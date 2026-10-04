/*
 * function: func_021BADBC
 * address: 0x021BADBC
 * packet: pkt_ov072_021BADBC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj03666.h"
typedef unsigned char u8;
struct Obj;
extern void func_0204B3DC(struct Obj *obj, unsigned int v);
typedef unsigned short u16;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BADBC(char *p, int v) { ((struct Obj03666 *)p)->f32=v; if(((struct Obj03666 *)p)->f32!=255) { if(((struct Obj03666 *)p)->f0) { func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,1); func_0204B878((struct Obj *)(((struct Obj03666 *)p)->f0),((struct Obj03666 *)p)->f32); } } else { if(((struct Obj03666 *)p)->f0) func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,0); } }
