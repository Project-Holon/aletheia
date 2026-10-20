#ifndef GF_FONT_SHARED_TYPES_H
#define GF_FONT_SHARED_TYPES_H

struct Strbuf;

struct WordSet;

struct WordTag;

#include "../types.h"
#include "../arm9/strbuf_types.h"


struct WordTag {
    u8 reserved00[3];
    u8 grammarCase : 7;
    u8 isSingular : 1;
    u8 addsMarker;
};

struct WordSlot {
    struct WordTag tag;
    struct Strbuf *text;
};

struct WordSet {
    u32 slotCount;
    u32 heapId;
    struct WordSlot *slots;
    struct Strbuf *scratch;
};

#endif
