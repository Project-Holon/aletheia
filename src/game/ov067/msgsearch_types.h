#ifndef GAME_OV067_MSGSEARCH_TYPES_H
#define GAME_OV067_MSGSEARCH_TYPES_H

/*
 * Object types of the message prefix search (msgsearch.c).
 * Needs u32 to be defined before it is included.
 */

struct StrBuf;
struct MsgBank;

/* Byte size of the MsgSearch fields in front of bank[]. */
#define MSGSEARCH_HEADER_SIZE 8

/* Search object: a scratch string for the message being compared and the banks to search. */
typedef struct {
    struct StrBuf *scratch;
    u32 bankCount;
    struct MsgBank *bank[1];
} MsgSearch;

/* One match: the bank and the message index inside it. */
typedef struct {
    u32 bankIndex;
    u32 messageIndex;
} MsgSearchHit;

#endif
