/*
 * function: func_021BE62C
 * address: 0x021BE62C
 * packet: pkt_ov203_021BE62C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ICA_ANIME_GetFrameNum 0x02011608 thumb
 */
#include "../include/Obj25316.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
struct Obj11244;
extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);
u32 func_021BE62C(char *p) { return ICA_ANIME_GetFrameNum(((struct Obj25316 *)p)->f18); }
