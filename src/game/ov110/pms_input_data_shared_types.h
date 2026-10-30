#ifndef PMS_INPUT_DATA_SHARED_TYPES_H
#define PMS_INPUT_DATA_SHARED_TYPES_H

#include "../types.h"
#include "../version.h"

#define PMS_INPUT_DATA_CATEGORY_COUNT 12
/* Japanese sorts the words by 45 kana initials, the other languages by 27 letters. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define PMS_INPUT_DATA_INITIAL_COUNT 45
#else
#define PMS_INPUT_DATA_INITIAL_COUNT 27
#endif
#define PMS_INPUT_DATA_SEEN_BYTES 226

struct PmsWordSys;

struct PmsInputData {
    void *saveData;
    struct PmsWordSys *wordSys;
    int categoryCount[PMS_INPUT_DATA_CATEGORY_COUNT];
    int categoryStart[PMS_INPUT_DATA_CATEGORY_COUNT];
    u16 categoryWords[1804];
    int initialCount[PMS_INPUT_DATA_INITIAL_COUNT];
    int initialStart[PMS_INPUT_DATA_INITIAL_COUNT];
    u16 initialWords[1803];
    u8 seenBits[PMS_INPUT_DATA_SEEN_BYTES];
};

#endif
