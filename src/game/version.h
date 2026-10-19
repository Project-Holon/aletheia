#ifndef GAME_VERSION_H
#define GAME_VERSION_H

/*
 * Which game the source is built for.  The build tools pass VERSION (tools/gamelink.py
 * --version white, or the environment variable ALETHEIA_VERSION=white); without it the
 * source is Pokemon Black.  A site that differs between the two games reads
 *
 *     #if VERSION == VERSION_WHITE
 *     ... White ...
 *     #else
 *     ... Black ...
 *     #endif
 */
#define VERSION_BLACK 1
#define VERSION_WHITE 2

#ifndef VERSION
#define VERSION VERSION_BLACK
#endif

/* Constants that differ between the two games (the value Black uses first). */
#if VERSION == VERSION_WHITE
#define PM_VERSION_ID 20            /* the game's version id */
#define MSG_PROFANITY_NOTICE 14     /* message index of the word-filter notice */
#define PM_VERSION_BIT 1            /* this game's bit in a per-version availability flag */
#define PM_VERSION_MASK 0x100000    /* 1 << PM_VERSION_ID, the version bit of the Wi-Fi flags */
#define PM_VERSION_LEGEND_SPECIES 0x284   /* the cover legendary: Zekrom */
#else
#define PM_VERSION_ID 21
#define MSG_PROFANITY_NOTICE 15
#define PM_VERSION_BIT 2
#define PM_VERSION_MASK 0x200000
#define PM_VERSION_LEGEND_SPECIES 0x283   /* the cover legendary: Reshiram */
#endif

#endif
