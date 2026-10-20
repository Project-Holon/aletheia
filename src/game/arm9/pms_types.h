#ifndef GAME_ARM9_PMS_TYPES_H
#define GAME_ARM9_PMS_TYPES_H

/* pmsi_param.c, pms_word.c: one easy-chat sentence (8 bytes): a sentence
 * type, a sentence index inside that type and the two words that fill its
 * blanks (0xFFFF = empty). */
typedef struct PmsData {
    unsigned short sentenceType;
    unsigned short sentenceId;
    unsigned short word[2];
} PmsData;

#endif
