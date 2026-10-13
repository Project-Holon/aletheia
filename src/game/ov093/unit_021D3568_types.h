#ifndef UNIT_021D3568_TYPES_H
#define UNIT_021D3568_TYPES_H
/*
 * Battle client work as the server command handlers of unit_021D3568.c see
 * it (partial view: only the fields these handlers read). Every handler has
 * the shape int handler(struct BtlClient *client, int *seq, u32 *args):
 * seq is the step counter of a multi-step command, args are the command
 * arguments the battle server queued; the return value is nonzero when the
 * command is finished.
 */
#include "btl_main_types.h"
#include "btl_pokeparam_types.h"

struct BtlvCore;
struct BtlPokeContainer;

struct BtlClient {
    struct BtlMain *main;               /* 0x000 */
    struct BtlPokeContainer *pokeContainer; /* 0x004 Pokemon and parties of all clients */
    u8 reserved008[0x54 - 0x08];
    struct BtlvCore *view;                  /* 0x054 battle view */
    u8 reserved058[0x138 - 0x58];
    u32 swapClientId;                       /* 0x138 client whose party is reordered */
    u32 swapFrom;                           /* 0x13C party index that comes in */
    u32 swapTo;                             /* 0x140 party index that goes out */
};

#endif
