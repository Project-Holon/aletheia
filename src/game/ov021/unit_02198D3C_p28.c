/*
 * file:     unit_02198D3C_p28.c
 * unit:     yes
 * function: func_0219B440, func_0219B45C
 * address:  0x0219B440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   data_021D5278  0x021D5278  data   ov021  a4
 *   d_021D52CC  0x021D52CC  data  a4
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef void (*Handler)(u32);

extern u16 func_0216D5A8(u8 *p);
int func_0219B440(char *a);
void func_0219B45C(u32 a);
extern Handler d_021D52CC[];

extern int (*const data_021D5278[])(char *);


/*
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * func_0219B414 (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the word read at p+0x10 and tail-dispatches through it.
 */
int func_0219B440(char *a)
{
    int i = func_0216D5A8((u8 *)a);

    return data_021D5278[i](a);
}


void func_0219B45C(u32 a)
{
    d_021D52CC[func_0216D5A8((u8 *)a)](a);
}
