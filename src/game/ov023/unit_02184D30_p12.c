/*
 * file:     unit_02184D30_p12.c
 * unit:     yes
 * function: func_02186958, func_02186988, func_021869C0
 * address:  0x02186958
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02186938 0x02186938 thumb ov023
 */
#include "../../matched/include/Obj05109.h"
#include "../../matched/include/Obj13028.h"

typedef unsigned char u8;

typedef struct { u8 b[4]; u8 lo:3; u8 mid:3; u8 hi:2; u8 b5; } Rec_02186958;

typedef struct { u8 b[4]; u8 lo:3; u8 mid:3; u8 hi:2; u8 b5; } Rec_02186988;

typedef struct { Rec_02186988 r[5]; } Grp;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec_021869C0;

extern void func_02186938(Rec_02186958 *);
void func_02186958(char *p);
void func_02186988(Rec_02186988 *s, char *p, int i);
void func_021869C0(Rec_021869C0 *d, char *p);

void func_02186958(char *p)
{
    if (((struct Obj05109 *)p)->fBB8 != ((struct Obj05109 *)p)->fBBC) {
        func_02186938((Rec_02186958 *)(p + ((struct Obj05109 *)p)->fBB8 * 30));
        ((struct Obj05109 *)p)->fBB8 += 1;
        if (((struct Obj05109 *)p)->fBB8 >= 100) ((struct Obj05109 *)p)->fBB8 = 0;
    }
}

void func_02186988(Rec_02186988 *s, char *p, int i)
{
    ((Grp *)p)[*(int *)(p + 0xBBC)].r[i] = *s;
}


void func_021869C0(Rec_021869C0 *d, char *p)
{
    int i = ((struct Obj13028 *)p)->fBB8;

    if (i != ((struct Obj13028 *)p)->fBBC) {
        *d = *(Rec_021869C0 *)(p + i * 30);
    } else {
        d->mid = 0;
    }
}
