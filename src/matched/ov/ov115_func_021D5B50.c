/*
 * function: func_021D5B50
 * address:  0x021D5B50
 * packet:   pkt_ov115_021D5B50
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B5C  0x021D5B5C  thumb  ov115
 */
#include "../include/Obj22602.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct MsgBank;
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
void func_021D5B50(void *p, int b) { func_021D5B5C(p, (struct MsgBank *)(((struct Obj22602 *)p)->f1C), b); }
