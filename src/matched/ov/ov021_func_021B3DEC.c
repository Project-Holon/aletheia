/*
 * function: func_021B3DEC
 * address:  0x021B3DEC
 * packet:   pkt_ov021_021B3DEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00357.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern const Rect d_021D96E0;
extern const Rect d_021D96E8;
extern const Rect d_021D96F0;
extern const Rect d_021D96F8;
extern const Rect d_021D9700;

void func_021B3DEC(char *w)
{
    ((struct Obj00357 *)w)->f1C0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1D8, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1DC, &d_021D96E0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C4 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96E8, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1C8 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F0, 0, ((struct Obj00357 *)w)->f4);
    ((struct Obj00357 *)w)->f1CC = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1E4, ((struct Obj00357 *)w)->f1D4,
                                        ((struct Obj00357 *)w)->f1E8, &d_021D96F8, 0, ((struct Obj00357 *)w)->f4);
    func_0204B92C((struct Obj *)((struct Obj00357 *)w)->f1CC, 1);
    ((struct Obj00357 *)w)->f1D0 = (int)func_0204B294((void *)((struct Obj00357 *)w)->f1BC, ((struct Obj00357 *)w)->f1F0, ((struct Obj00357 *)w)->f1EC,
                                        ((struct Obj00357 *)w)->f1F4, &d_021D9700, 0, ((struct Obj00357 *)w)->f4);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C4, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1C8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00357 *)w)->f1CC, 0);
}
