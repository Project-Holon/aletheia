/*
 * file:     worldtrade_box_p22.c
 * unit:     yes
 * function: func_021F8154, func_021F8178
 * address:  0x021F8154
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   g_0220301C     0x0220301C  data
 *   g_02202FC4     0x02202FC4  data
 */
#include "../../matched/include/G_0220301C.h"

struct MsgBank;
struct U16Vec;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 unk; s16 key; s16 val; } Entry;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);
extern struct G_0220301C g_0220301C[12];
extern Entry g_02202FC4[11];


void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g)
{
    func_021F8178(win, bank, idx, e, 0, y, color, alt, (u32)g);
}


void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g)
{
    Entry *tab;
    void *str;

    if (idx != -1) {
        tab = ((Entry *)g_0220301C);
        if (alt != 0) {
            tab = g_02202FC4;
        }
        str = func_02045EC0(bank, tab[idx].unk);
        func_021F91A0(win, (u32)str, x, y, e, color, g);
        func_02045808(str);
    }
}
