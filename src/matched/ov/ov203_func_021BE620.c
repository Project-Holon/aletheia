/*
 * function: DEMO3D_ENGINE_GetFrame
 * address: 0x021BE620
 * packet: pkt_ov203_021BE620
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ICA_ANIME_GetFrame 0x0201160C thumb
 */
#include "../include/Obj25315.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
struct Obj11245;
extern u32 ICA_ANIME_GetFrame(struct Obj11245 *p);
int DEMO3D_ENGINE_GetFrame(char *p) { return ICA_ANIME_GetFrame(((struct Obj25315 *)p)->f18); }
