/*
 * function: func_021DCFA8
 * address: 0x021DCFA8
 * packet: pkt_ov171_021DCFA8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj14287.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 WIPE_SYS_EndCheck(void);
int func_021DCFA8(u8*p){if(func_0201C6B4(*(void* *)&((struct Obj14287 *)p)->fB6C)==1 && WIPE_SYS_EndCheck()==1)return ((struct Obj14287 *)p)->fC74;return 2;}
