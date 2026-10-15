#ifndef ALETHEIA_ZUKAN_SEARCH_TYPES_H
#define ALETHEIA_ZUKAN_SEARCH_TYPES_H

/*
 * Shared records of the zukan search proc (ov211). zukan_search_proc.c creates
 * the 16-byte work; zukan_search_screen.c supplies the proc state handlers that
 * run on it.
 */

/* the owner/context the work points at (offset 0 of the work) */
struct ZukanSearchOwner {
    void *gameData;
    void *context;
    unsigned int state;
};

/* the 16-byte proc work allocated by ZUKAN_SEARCH_PROC_Create */
struct ZukanSearchWork {
    struct ZukanSearchOwner *owner;   /* 0x00 */
    void *vblankNode;                 /* 0x04 vblank callback node */
    unsigned short counter;           /* 0x08 input wait counter */
    unsigned char timer;              /* 0x0A animation timer */
    unsigned char state;              /* 0x0B animation state */
    unsigned int procState;           /* 0x0C proc framework state */
};

#endif
