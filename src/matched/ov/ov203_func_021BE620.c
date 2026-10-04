/*
 * function: func_021BE620
 * address: 0x021BE620
 * packet: pkt_ov203_021BE620
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201160C 0x0201160C thumb
 */
#include "../include/Obj25315.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern u32 func_0201160C(void *);
u32 func_021BE620(char *p) { return func_0201160C(((struct Obj25315 *)p)->f18); }
