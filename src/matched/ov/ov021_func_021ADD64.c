/*
 * function: func_021ADD64
 * address:  0x021ADD64
 * packet:   pkt_ov021_021ADD64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

extern void func_02047204(u32 a);

void func_021ADD64(u32 a, Q *q)
{
    if (q->f1c == 0) {
        func_02047204(q->f4);
        q->f1c = 1;
    }
}
