/*
 * file:     script_work_p17.c
 * unit:     yes
 * function: func_021590FC, func_02159104, func_0215910C, func_02159114, func_0215911C
 * address:  0x021590FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17640.h"
#include "../../matched/include/Obj18756.h"
#include "../../matched/include/Obj18757.h"
#include "../../matched/include/Obj17641.h"
#include "../../matched/include/Obj17642.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

u32 func_021590FC(void *p);
void func_02159104(u8 *p, u32 v);
u32 func_0215910C(void *p);
void *func_02159114(void *p, u32 v);
u32 func_0215911C(void *p);


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590FC.c \
 *       --func func_021590FC --addr 0x021590FC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_021590FC(void *p) { return ((struct Obj17640 *)p)->f13C; }


/*
 * Store of a word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02159104(u8 *p, u32 v)
{
    ((struct Obj18756 *)p)->f140 = v;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021D1A54/021D1A74/021D1AB0: reads the word at +0x140.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215910C(void *p)
{
    return ((struct Obj18757 *)p)->f140;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159114.c \
 *       --func func_02159114 --addr 0x02159114 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02159114(void *p, u32 v) { ((struct Obj17641 *)p)->f144 = v;  return p; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215911C.c \
 *       --func func_0215911C --addr 0x0215911C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215911C(void *p) { return ((struct Obj17642 *)p)->f144; }
