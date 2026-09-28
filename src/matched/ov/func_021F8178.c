/*
 * function: func_021F8178
 * address:  0x021F8178
 * packet:   pkt_021F8178
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   g_0220301C     0x0220301C  data
 *   g_02202FC4     0x02202FC4  data
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 unk; s16 key; s16 val; } Entry;
extern Entry g_0220301C[12];
extern Entry g_02202FC4[11];

extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, u32 g);

void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g)
{
    Entry *tab;
    void *str;

    if (idx != -1) {
        tab = g_0220301C;
        if (alt != 0) {
            tab = g_02202FC4;
        }
        str = func_02045EC0(bank, tab[idx].unk);
        func_021F91A0(win, str, x, y, e, color, g);
        func_02045808(str);
    }
}
