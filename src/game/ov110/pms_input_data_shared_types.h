#ifndef PMS_INPUT_DATA_SHARED_TYPES_H
#define PMS_INPUT_DATA_SHARED_TYPES_H

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#define PMS_INPUT_DATA_CATEGORY_COUNT 12
#define PMS_INPUT_DATA_INITIAL_COUNT 27
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
