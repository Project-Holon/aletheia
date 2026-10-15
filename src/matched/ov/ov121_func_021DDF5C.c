/*
 * function: MYSTERY_ALBUM_StartIntro
 * address: 0x021DDF5C
 * packet: pkt_ov121_021DDF5C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 */
#include "../include/Obj10421.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *);
void MYSTERY_ALBUM_StartIntro(u8 *p) { if(MYSTERY_ALBUM_GetEntryKind(p)==1 && ((struct Obj10421 *)p)->fDC==0) { ((struct Obj10421 *)p)->fDC=1; ((struct Obj10421 *)p)->fDE=0; } }
