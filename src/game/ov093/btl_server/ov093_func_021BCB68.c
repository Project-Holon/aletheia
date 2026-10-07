/*
 * function: func_021BCB68
 * address:  0x021BCB68
 * packet:   pkt_ov093_021BCB68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * unlabelled leaf (push {r3, r4}); filed as the blocker of func_021BCB14.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

int func_021BCB68(S *p, E *cur)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur)
            return (u8)i;
    }
    return n;
}
