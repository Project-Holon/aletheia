/*
 * file:     musical_dressup_sys_p07.c
 * unit:     yes
 * function: func_02156908, func_02156914, func_02156934, func_02156954
 * address:  0x02156908
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021572C0  0x021572C0  thumb  ov010
 *   func_02045C44  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 */
#include "../../matched/include/Obj12026.h"

struct Deal;
struct MsgBank;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct Work_02156908 {
    u8 pad00[0x38];
    void *f38;          /* 0x38 */
} Work_02156908;

typedef struct Rec6 {
    u16 id;
    u8 pad[4];
} Rec6;

typedef struct Member_02156934 {
    u8 pad00[0x14];
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
} Member_02156934;

typedef struct Party {
    u32 f00;
    Member_02156934 *members[4]; /* 0x04 */
} Party;

typedef struct Work_02156934 {
    u8 pad00[0x04];
    void *f04;          /* 0x04 */
    u8 pad08[0x14 - 0x08];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1C[0x30 - 0x1C];
    Party *party;       /* 0x30 */
    u8 pad34[0x40 - 0x34];
    void *f40;          /* 0x40 */
    u8 pad44[0x48 - 0x44];
    u8 f48;             /* 0x48 */
    u8 pad49[3];
    u8 f4C;             /* 0x4C */
} Work_02156934;

typedef struct Member_02156954 {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
    u16 score[4];       /* 0x4C */
} Member_02156954;

typedef struct Work_02156954 {
    u8 pad00[0x30];
    Party *party;       /* 0x30 */
} Work_02156954;

extern u8 func_021572C0(struct Deal *d);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
u8 func_02156908(Work_02156908 *w);
void *func_02156914(int a0, int a1);
u8 func_02156934(Work_02156934 *w, u8 idx);
u16 func_02156954(Work_02156954 *w);


u8 func_02156908(Work_02156908 *w)
{
    return func_021572C0(w->f38);
}


void *func_02156914(int a0, int a1)
{
    void *t4;
    struct MsgBank *t5;

a0 = ((struct Obj12026 *)a0)->f24;
a0 = ((struct Obj12026 *)a0)->f8;
    t5 = func_02045C44((const void *)a0, a1);
loc_0215691E:
a1 = 0;
    t4 = func_02045EC0(t5, a1);
loc_02156926:
    a0 = func_02045C04((struct Rec *)t5);
loc_0215692E:
    return t4;}


u8 func_02156934(Work_02156934 *w, u8 idx)
{
    u16 v;

    v = w->party->members[idx]->total;
    if (v < 0x100)
        return v;
    return 0xFF;
}


u16 func_02156954(Work_02156954 *w)
{
    u16 max = 0;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (max < w->party->members[i]->total)
            max = w->party->members[i]->total;
    }
    return max;
}
