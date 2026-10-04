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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

extern int func_0204B294(int, int, int, int, const Rect *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B3DC(int, int);
extern const Rect d_021D96E0;
extern const Rect d_021D96E8;
extern const Rect d_021D96F0;
extern const Rect d_021D96F8;
extern const Rect d_021D9700;

void func_021B3DEC(char *w)
{
    *(int *)(w + 0x1C0) = func_0204B294(*(int *)(w + 0x1BC), *(int *)(w + 0x1D8), *(int *)(w + 0x1D4),
                                        *(int *)(w + 0x1DC), &d_021D96E0, 0, *(u16 *)(w + 4));
    *(int *)(w + 0x1C4) = func_0204B294(*(int *)(w + 0x1BC), *(int *)(w + 0x1E4), *(int *)(w + 0x1D4),
                                        *(int *)(w + 0x1E8), &d_021D96E8, 0, *(u16 *)(w + 4));
    *(int *)(w + 0x1C8) = func_0204B294(*(int *)(w + 0x1BC), *(int *)(w + 0x1E4), *(int *)(w + 0x1D4),
                                        *(int *)(w + 0x1E8), &d_021D96F0, 0, *(u16 *)(w + 4));
    *(int *)(w + 0x1CC) = func_0204B294(*(int *)(w + 0x1BC), *(int *)(w + 0x1E4), *(int *)(w + 0x1D4),
                                        *(int *)(w + 0x1E8), &d_021D96F8, 0, *(u16 *)(w + 4));
    func_0204B92C((struct Obj *)*(int *)(w + 0x1CC), 1);
    *(int *)(w + 0x1D0) = func_0204B294(*(int *)(w + 0x1BC), *(int *)(w + 0x1F0), *(int *)(w + 0x1EC),
                                        *(int *)(w + 0x1F4), &d_021D9700, 0, *(u16 *)(w + 4));
    func_0204B3DC(*(int *)(w + 0x1C4), 0);
    func_0204B3DC(*(int *)(w + 0x1C8), 0);
    func_0204B3DC(*(int *)(w + 0x1CC), 0);
}
