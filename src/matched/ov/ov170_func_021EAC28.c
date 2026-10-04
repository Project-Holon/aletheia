/*
 * function: func_021EAC28
 * address:  0x021EAC28
 * packet:   pkt_ov170_021EAC28
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
#include "../include/Obj00414.h"

typedef unsigned int u32;
typedef unsigned short u16;

struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32 print, void *bmp, short x, short y, u32 str, u32 font, u16 color);
extern void func_02045808(struct U16Vec *vec);

void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    u32 print;
    void *s;
    s = func_02045EC0(bank, idx);
    func_0201F250(((struct Obj00414 *)w)->f84, (void *)(*(u32 *)&((struct Obj00414 *)w)->f88), s);
    print = ((struct Obj00414 *)w)->f8C;
    func_0201C724(print, func_02045770(*(void **)(w + i * 8 + 0x94)), x, y, *(u32 *)&((struct Obj00414 *)w)->f88, font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    func_02045808(s);
}
