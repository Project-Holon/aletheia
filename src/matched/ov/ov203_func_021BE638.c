/*
 * function: DEMO3D_ENGINE_SetMode
 * address: 0x021BE638
 * packet: pkt_ov203_021BE638
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj25317.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;

void DEMO3D_ENGINE_SetMode(char *p,int a) { ((struct Obj25317 *)p)->f8=a; }
