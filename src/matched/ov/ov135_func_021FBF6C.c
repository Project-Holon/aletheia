/*
 * function: func_021FBF6C
 * address:  0x021FBF6C
 * packet:   pkt_021FBF6C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_021FB240  0x021FB240  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x1C];
    u32 item;
    u8 pad20[0x2C - 0x20];
    u32 f2C;
} Menu;

extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
extern u32 func_020307B0(void *p);

int func_021FBF6C(Menu *m, u32 idx)
{
    u32 n;
    int start;
    int end;
    u16 *list;
    int r;

    list = func_021F8498(0x48, 0, &n);
    func_021F84BC(idx, &start, &end);
    n = end - start;
    r = func_021FB240(m->f2C, m->item, n, list, start, end);
    func_020307B0(list);
    return r;
}
