/*
 * function: func_0216C7E0
 * address:  0x0216C7E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Writes the mode byte at +0x365 and clears the word at +0xae8 of the
 * current object.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data

 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;

void func_0216C7E0(unsigned char v)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    *(unsigned char *)(p + 0x365) = v;
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0xae8) = 0;
}


