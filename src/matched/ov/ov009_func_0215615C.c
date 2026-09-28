/*
 * function: func_0215615C
 * address:  0x0215615C
 * packet:   pkt_ov009_0215615C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0215610C  0x0215610C  thumb  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_02176FD4  0x02176FD4  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *g_021A8264;
extern int func_0215610C(void);
extern u32 func_0216B908(void);
extern void func_02176FD4(u32, void *, u32);

int func_0215615C(u32 idx)
{
    if (*(u32 *)(g_021A8264 + 0x760) == 0 && func_0215610C() != 0
        && (func_0216B908() & 0xFFFE) != 0) {
        *(u32 *)(g_021A8264 + 0x760) = 1;
        *(u32 *)g_021A8264 = ((u32)*(u16 *)(g_021A8264 + 0x794) << 8) | 2;
        func_02176FD4(func_0216B908(), g_021A8264, 4);
        *(u32 *)(g_021A8264 + idx * 4 + 0x784) = 0;
        return 1;
    }
    return 0;
}
