#ifndef RESEARCH_GRAPH_TABLE_H
#define RESEARCH_GRAPH_TABLE_H

#include "research_types.h"

/* One entry of a graph group: an identifier and a colour, 12 bytes. */
struct GraphTableEntry {
    u16 id;
    u8 red;
    u8 green;
    u8 blue;
    u8 tailBytes[7];                    /* fixed record tail, never read by this overlay, see open_items */
};

/* One group of the graph table, 0xD4 bytes: a key, an entry count and 17 entries. */
struct GraphTableGroup {
    u8 key;
    u8 entryCount;
    u8 tailBytes[6];                    /* fixed record tail, never read by this overlay, see open_items */
    struct GraphTableEntry entries[17];
};

/* Table of three groups at offset 0x38 of the research graph object, 0x280 bytes. */
struct GraphTable {
    u8 header[4];                       /* table header, never read by this overlay, see open_items */
    struct GraphTableGroup groups[3];
};

#endif
