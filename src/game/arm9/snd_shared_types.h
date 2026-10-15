/*
 * snd_shared_types.h: shared types of the arm9 snd_*.c cluster.
 *
 * SNDSharedWork is the ARM7/ARM9 shared work block that SNDi_SharedWork
 * points at: the command tag a reply is posted under, the player and channel
 * status the main CPU polls, and the per-player and global sequence
 * variables.  snd_command.c and snd_work.c both need it; this is its one
 * owner.  Raw types keep the layout independent of each file's base typedefs.
 */
#ifndef SND_SHARED_TYPES_H
#define SND_SHARED_TYPES_H

typedef struct SNDSharedWork {
    unsigned int finishedTag;       /* 0x00: tag of the last finished command */
    unsigned int playerStatus;      /* 0x04 */
    unsigned short channelStatus;   /* 0x08 */
    unsigned short captureStatus;   /* 0x0a */
    unsigned int padding[5];        /* 0x0c */
    struct {
        short variable[16];         /* per-player sequence variable */
        unsigned int tickCounter;   /* 0x20: frames left on this player */
    } player[16];                   /* 0x20 */
    short globalVariable[16];       /* 0x260 */
} SNDSharedWork;

#endif
