/*
 * file:     p_sta_oam_p33.c
 * unit:     yes
 * function: func_021DB9FC, func_021DBA14
 * address:  0x021DB9FC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021DC2B8 0x021DC2B8 data a1
 */
#include "../../matched/include/Obj14078.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021DB9FC(void *a, void *b, u8 *p);
void func_021DBA14(u8 *a,u8 *b);
extern const u8 d_021DC2B8[][2];


/*
 * Addresses are Black-image addresses.
 */
void func_021DB9FC(void *a, void *b, u8 *p)
{
    func_0204B3DC(((struct Obj14078 *)p)->f8, 0);
    func_0204B3DC(((struct Obj14078 *)p)->fC, 0);
}

void func_021DBA14(u8 *a,u8 *b) {
    if (*a<5) {
        b[0]=d_021DC2B8[*a][1]*8;
        b[1]=b[0]+32;
        b[2]=d_021DC2B8[*a][0]*8;
        b[3]=b[2]+136;
    } else { b[0]=0;b[1]=0;b[2]=0;b[3]=0; }
}
