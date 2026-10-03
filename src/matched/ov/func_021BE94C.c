/*
 * function: func_021BE94C
 * address:  0x021BE94C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *
 * Runs the setup and stamps selector 3 when the guard answers true.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);

int func_021BE94C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        *(u32 *)(p + 0x1CC) = 3;
    }

    return v;
}
