/*
 * function: RESEARCH_GRAPH_GetEntryValue
 * address:  0x021BF854
 * packet:   pkt_ov217_021BF854
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_GetEntryValueA 0x021BF878 thumb ov217
 *   RESEARCH_GRAPH_GetEntryValueB 0x021BF894 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25946.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetEntryValueA(void *p);
extern u32 RESEARCH_GRAPH_GetEntryValueB(void *p);
u32 RESEARCH_GRAPH_GetEntryValue(char *p)
{
    switch (((struct Obj25946 *)p)->f2CC) {
    case 0:
        return RESEARCH_GRAPH_GetEntryValueA(p);
    case 1:
        return RESEARCH_GRAPH_GetEntryValueB(p);
    }
    return 0;
}
