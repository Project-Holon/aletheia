/*
 * function: func_021F84BC
 * address:  0x021F84BC
 * packet:   pkt_021F84BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   tbl_0220307C   0x0220307C  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const int tbl_0220307C[];

extern void func_02034714(const char *expr, u32 line, const char *file);

void func_021F84BC(u32 i, int *start, int *end)
{
    if (i >= 0x1B) {
        func_02034714((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[i];
    *end = tbl_0220307C[i + 1];
}
