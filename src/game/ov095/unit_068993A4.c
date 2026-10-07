/*
 * file:     unit_068993A4.c
 * unit:     yes
 * function: func_068993A4, func_068993B0
 * address:  0x068993A4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_0689D700 0x0689D700 data a4
 *   func_06899418  0x06899418  thumb
 *   func_06899428  0x06899428  thumb
 *   func_06899438  0x06899438  thumb
 *   func_06899448  0x06899448  thumb
 *   func_06899458  0x06899458  thumb
 *   func_06899468  0x06899468  thumb
 *   func_06899478  0x06899478  thumb
 *   func_06899488  0x06899488  thumb
 *   func_06899498  0x06899498  thumb
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_06899418(int a);
extern u8 func_06899428(u32 a);
extern int func_06899438(int a);
extern u32 func_06899448(u32 a, int b);
extern u32 func_06899458(u32 a);
extern int func_06899468(int a, int b);
extern int func_06899478(int a);
extern void func_06899488(int p, int n, int c);
extern void func_06899498(int p, int v);
void *func_068993A4(u32 *p);
void func_068993B0(int a0, int a1, u32 x);
extern u32 data_0689D700;

/*
 * Unlabelled store-and-return follower after veneer 0x06899394.
 */
void *func_068993A4(u32 *p) { *p = 1; return &data_0689D700; }


/*
 * note: recoup 2026-10-05: callee return types from matched definitions closed it. func_06899428 (func_021B9A40) returns u8, func_06899448 (sub_0201BD28) and func_06899458 (sub_0201C314) return u32, x is u32, h is u16. Earlier DIFF was a v/h colour swap caused by int declarations.
 */
void func_068993B0(int a0, int a1, u32 x)
{
    u8 v;
    u16 h;

    v = func_06899418(4);
    if (x == func_06899428(v)) {
        h = func_06899438(0x12);
        x = func_06899448(h, 0x1b);
        if (func_06899458(h) != 0) {
            if (x == 4 || x == 5) {
                if (func_06899468(0x40, 1) != 0) {
                    x = func_06899478(0x3f);
                    func_06899488(x, 2, 0x31d);
                    func_06899498(x, v);
                }
            }
        }
    }
}
