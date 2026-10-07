/*
 * file:     btlv_effvm_p16.c
 * unit:     yes
 * function: func_021F8298, func_021F8324
 * address:  0x021F8298
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_021F69E8  0x021F69E8  thumb  ov094
 *   func_021F6DEC  0x021F6DEC  thumb  ov094
 *   func_0202173C  0x0202173C  thumb
 *   func_021F6A18  0x021F6A18  thumb  ov094
 *   func_021F6E1C  0x021F6E1C  thumb  ov094
 *   func_02021ED8  0x02021ED8  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

extern void func_021F69E8(u32 obj, u8 b, u8 c, int d, u16 e);
extern void func_021F6DEC(u32 obj, u8 b, u8 c, int d, u16 e);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern int func_021F6A18(char *p);
extern int func_021F6E1C(char *p);
extern u32 func_02021ED8(const char *ptr);
void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);
int func_021F8324(u32 a);
extern char *d_0220AF20;


void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e)
{
    if (a == 0 || a == 2 || a == 4)
        func_021F69E8(*(u32 *)(d_0220AF20 + 0x194), b, c, d, e);
    if (a == 1 || a == 2 || a == 4)
        func_021F6DEC(*(u32 *)(d_0220AF20 + 0x198), b, c, d, e);
    if (a - 3 <= 1)
        func_0202173C(*(void **)(d_0220AF20 + 0x18C), 1, 0xFF00, (s8)d, b, c, e, *(void **)d_0220AF20);
}


int func_021F8324(u32 a)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (a == 0 || a == 2 || a == 4)
        x = func_021F6A18((char *)(*(u32 *)(d_0220AF20 + 0x194)));
    if (a == 1 || a == 2 || a == 4)
        y = func_021F6E1C((char *)(*(u32 *)(d_0220AF20 + 0x198)));
    if (a - 3 <= 1) {
        z = func_02021ED8((const char *)(*(int *)(d_0220AF20 + 0x18C))) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}
