/*
 * function: func_0219ADEC
 * address:  0x0219ADEC
 * packet:   pkt_ov021_0219ADEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u8 a; s8 b; u8 c[3]; u8 f; } St;

void func_0219ADEC(St *p)
{
    if (p->f == 1) {
        p->b--;
        if (p->b < 0) {
            p->b = 3;
        }
    } else {
        p->b++;
    }
}
