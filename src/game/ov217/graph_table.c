/*
 * file:     graph_table.c
 * unit:     yes
 * function: GRAPHTABLE_GetEntryId, GRAPHTABLE_GetEntryRed, GRAPHTABLE_GetEntryGreen, GRAPHTABLE_GetEntryBlue, GRAPHTABLE_FindGroup, GRAPHTABLE_FindEntry
 * address:  0x021C2644
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from arrow.c by tools/splitfile.py.
 *
 * symbols:
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 *   GRAPHTABLE_GetEntryRed 0x021C2654 thumb ov217
 *   GRAPHTABLE_GetEntryGreen 0x021C2664 thumb ov217
 *   GRAPHTABLE_GetEntryBlue 0x021C2674 thumb ov217
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 */
#include "arrow.h"
#include "research_graph_table.h"

u32 GRAPHTABLE_GetEntryId(const struct GraphTable *table, u32 group, u8 entry);

u32 GRAPHTABLE_GetEntryRed(const struct GraphTable *table, u32 group, u32 entry);

u32 GRAPHTABLE_GetEntryGreen(const struct GraphTable *table, u32 group, u32 entry);

u32 GRAPHTABLE_GetEntryBlue(const struct GraphTable *table, u32 group, u32 entry);

u32 GRAPHTABLE_FindGroup(const struct GraphTable *table, u32 key);

u32 GRAPHTABLE_FindEntry(const struct GraphTable *table, u8 key, u8 entryId);

/* Returns the id of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryId(const struct GraphTable *table, u32 group, u8 entry)
{
    return table->groups[group].entries[entry].id;
}

/* Returns the red component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryRed(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].red;
}

/* Returns the green component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryGreen(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].green;
}

/* Returns the blue component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryBlue(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].blue;
}

/* Returns the index of the group with the given key, or zero. */
u32 GRAPHTABLE_FindGroup(const struct GraphTable *table, u32 key)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (table->groups[i].key == key)
            return (u8)i;
    }
    return 0;
}

/* Returns the index of the entry with the given id in the group with the given key, or zero. */
u32 GRAPHTABLE_FindEntry(const struct GraphTable *table, u8 key, u8 entryId)
{
    s32 i;
    const struct GraphTableGroup *group;
    group = &table->groups[GRAPHTABLE_FindGroup(table, key)];
    for (i = 0; i < group->entryCount; i++) {
        if (entryId == group->entries[i].id)
            return (u8)i;
    }
    return 0;
}
