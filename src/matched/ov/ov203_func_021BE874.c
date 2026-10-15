/*
 * function: DEMO3D_DATA_BuildTable
 * address: 0x021BE874
 * packet: pkt_ov203_021BE874
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_GetPair 0x021BE8F4 thumb ov203
 *   d_021C1868 0x021C1868 data a4
 */
#include "../include/Obj08376.h"
#include "../include/Obj08377.h"
#include "../include/Obj25320.h"
typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;
typedef struct Pair { const unsigned short *ids; unsigned count; } Pair;
typedef struct Group { const Pair *pairs; unsigned count; } Group;
typedef struct Selector { const Group *groups; unsigned short count, selector; } Selector;
typedef struct Row { const Selector *selectors; unsigned words[4]; } Row;
extern const Row d_021C1868[];
typedef unsigned char  u8;
extern void *DEMO3D_DATA_GetPair(char *p, u8 *q);
void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type)
{
    Entry *entries = *(Entry * *)&((struct Obj08376 *)ctx)->f0;
    char *extra = *(char * *)&((struct Obj08376 *)ctx)->f8;
    unsigned choice = 0;
    const Group *group;
    int i;
    const Pair *pair;
    group = DEMO3D_DATA_GetPair((char *)(&d_021C1868[*(unsigned *)config].selectors[type]), (u8 *)config);
    if (group->count > 1) choice = *(const unsigned char *)&((struct Obj08377 *)config)->f9;
    if (choice >= group->count) choice = 0;
    pair = &group->pairs[choice];
    ((struct Obj08376 *)ctx)->f4 = pair->count;
    for (i = 0; i < 6; i++) {
        if (i < pair->count) entries[i].id = pair->ids[i];
        else entries[i].id = 0;
    }
    ((struct Obj08376 *)ctx)->fC = 1;
    ((struct Obj25320 *)extra)->fC = pair->count - 1;
}
