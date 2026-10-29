#ifndef GAME_VERSION_H
#define GAME_VERSION_H

/*
 * Which game the source is built for.  The build tools pass VERSION and LANGUAGE (tools/gamelink.py
 * --target white_fr, or the environment variable ALETHEIA_TARGET=white_fr; the names are in
 * tools/targets.py); without them the source is Pokemon Black in English.  A site that differs
 * between the two games reads
 *
 *     #if VERSION == VERSION_WHITE
 *     ... White ...
 *     #else
 *     ... Black ...
 *     #endif
 *
 * A site that differs between languages reads  #if LANGUAGE == LANGUAGE_FRENCH.
 */
#define VERSION_BLACK 1
#define VERSION_WHITE 2

#ifndef VERSION
#define VERSION VERSION_BLACK
#endif

/* The game's own language ids (the language field of the player record). */
#define LANGUAGE_JAPANESE 1
#define LANGUAGE_ENGLISH 2
#define LANGUAGE_FRENCH 3
#define LANGUAGE_ITALIAN 4
#define LANGUAGE_GERMAN 5
#define LANGUAGE_SPANISH 7

#ifndef LANGUAGE
#define LANGUAGE LANGUAGE_ENGLISH
#endif

#define PM_LANG_ID LANGUAGE         /* the cartridge's language id */

/* French, Italian and German write a month as its name in dates; English and Spanish as a
 * number.  Some screens keep their own rule (wifibattlematch_view.c, gimmick_obj_elboard.c). */
#define PM_LANG_MONTH_AS_NAME (LANGUAGE == LANGUAGE_FRENCH || LANGUAGE == LANGUAGE_ITALIAN || LANGUAGE == LANGUAGE_GERMAN)

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

/* Wi-Fi match key: players are matched only with the same language and version. */
#define PM_LANG_VERSION_KEY ((PM_LANG_ID << 16) | PM_VERSION_ID)

#endif
