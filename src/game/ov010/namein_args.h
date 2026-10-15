#ifndef GAME_OV010_NAMEIN_ARGS_H
#define GAME_OV010_NAMEIN_ARGS_H
/*
 * NameInArgs: argument block of the name entry setup (NAMEIN_SETUP_*).
 *
 * Owner header, 0x2C bytes.  ov088/startmenu_types.h carried a partial 0x28
 * view (unusedHead / playerGender / unusedMid / name / saveIntr); it is folded
 * here.  Offset 0x04 is the species for a monster name and the player gender
 * for a player name (kind 0).  Offset 0x24 is the save interrupt pointer the
 * caller stores for the name entry proc; ov010 itself never reads it.
 */
struct Strbuf;
struct SaveControlIntr;

typedef struct NameInArgs {
    int kind;                          /* 0x00 */
    u16 species;                       /* 0x04: species, or player gender for kind 0 */
    u16 traits;                        /* 0x06: gender in the high byte, form in the low byte */
    void *mon;                         /* 0x08 */
    struct Strbuf *boxName;            /* 0x0C */
    void *boxManager;                  /* 0x10 */
    int boxIndex;                      /* 0x14 */
    int maxLen;                        /* 0x18 */
    int canceled;                      /* 0x1C */
    struct Strbuf *name;               /* 0x20 */
    struct SaveControlIntr *saveIntr;  /* 0x24 */
    void *pokedex;                     /* 0x28 */
} NameInArgs;

#endif
