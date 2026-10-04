/*
 * function: func_0216749C
 * address:  0x0216749C
 * packet:   pkt_ov010_0216749C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fetches list page `page` (0: the first twenty entries, 1..3: ten-entry
 * pages, 4 and up: twenty-entry pages); answers its start index and the
 * number of used entries in *n.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0216742C  0x0216742C  thumb  ov010
 *   func_02167444  0x02167444  thumb  ov010
 *   func_0216745C  0x0216745C  thumb  ov010
 *   func_0216747C  0x0216747C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u16 func_0216742C(Entry32 *list, Entry32 *out, u32 cap, u8 *n);
extern int func_02167444(int a0, int a1, int a2, int a3);
extern u16 func_0216745C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
extern u16 func_0216747C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);

u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n)
{
    u8 more;
    u16 start;

    more = 0;
    MI_CpuFill8(out, 0, cap * 4);
    if (page == 0) {
        start = func_0216742C(list, out, cap, n);
        out += 10;
        cap -= 10;
        func_02167444((int)list, (int)out, cap, (int)(&more));
        *n += more;
    } else if (page >= 1 && page < 4) {
        start = func_0216745C(list, out, cap, page - 1, n);
    } else {
        start = func_0216747C(list, out, cap, page - 4, n);
    }
    return start;
}
