/*
 * function: func_0219B440
 * address:  0x0219B440
 * packet:   pkt_ov021_0219B440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * func_0219B414 (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the word read at p+0x10 and tail-dispatches through it.
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   data_021D5278  0x021D5278  data   ov021  a4
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;
extern u16 func_0216D5A8(u8 *p);
extern int (*const data_021D5278[])(char *);

int func_0219B440(char *a)
{
    int i = func_0216D5A8((u8 *)a);

    return data_021D5278[i](a);
}
