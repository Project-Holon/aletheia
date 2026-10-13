/*
 * function: FADE_SetSpeed
 * address:  0x0204E6F4
 * packet:   pkt_0204E6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter for +0x1c of the singleton reached through the pointer at
 * 0x02146A7C.  Same object as src/matched/unit_0204E720.c.
 *
 * symbols:
 *   g_02146A7C  0x02146A7C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FADE_SetSpeed.c \
 *       --func FADE_SetSpeed --addr 0x0204E6F4 --cc 1.1p1 --arm
 */

#include "../include/G_Run0204E720.h"

typedef signed int   s32;
typedef unsigned int u32;

extern struct Run0204E720 *g_02146A7C;

void FADE_SetSpeed(s32 a)
{
    g_02146A7C->unk1c = a;
}
