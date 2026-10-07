/*
 * file:     musical_dressup_sys_p08.c
 * unit:     yes
 * function: func_02156978, func_0215699C
 * address:  0x02156978
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct Member {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
    u16 score[4];       /* 0x4C */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work_02156978 {
    u8 pad00[0x30];
    Party *party;       /* 0x30 */
} Work_02156978;

typedef struct Work_0215699C {
    u8 pad00[0x48];
    u8 order[4];        /* 0x48 */
} Work_0215699C;

u16 func_02156978(Work_02156978 *w);
u8 func_0215699C(Work_0215699C *w, u8 i);


u16 func_02156978(Work_02156978 *w)
{
    u16 min = 0xFF;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (min > w->party->members[i]->total)
            min = w->party->members[i]->total;
    }
    return min;
}


u8 func_0215699C(Work_0215699C *w, u8 i)
{
    return w->order[i];
}
