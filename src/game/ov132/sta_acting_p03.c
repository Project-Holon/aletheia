/*
 * file:     sta_acting_p03.c
 * unit:     yes
 * function: func_021F8D88, func_021F8DA0
 * address:  0x021F8D88
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02157364  0x02157364  thumb  ov010
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj14083.h"
#include "../../matched/include/Obj23181.h"

struct BgTemplate;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef short s16;

extern u8 func_02157364(char *a0);
extern void func_021F6FB0(void *, int);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
void func_021F8D88(u8 *p, u32 a1);
void func_021F8DA0(const struct BgTemplate *p,u32 id,u32 type);


/*
 * Unblocked by matching func_02157364 (ov010, EXACT, Thumb): the +0008 call
 * site now attests as `matched`. ov009 holds ARM code at that address; ov010
 * is the coherent Thumb leaf, so the declaration is thumb/ov010 (the earlier
 * `arm` was wrong).
 *
 * Addresses are Black-image addresses.
 */
void func_021F8D88(u8 *p, u32 a1)
{
    int v = func_02157364(((struct Obj23181 *)((u8 *)((struct Obj14083 *)p)->f30))->f14);
    func_021F6FB0(((struct Obj14083 *)p)->f3C, v);
}

void func_021F8DA0(const struct BgTemplate *p,u32 id,u32 type) { func_0203FCA0(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }
