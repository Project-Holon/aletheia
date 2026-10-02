/*
 * function: func_0217C294
 * address:  0x0217C294
 * packet:   pkt_0217C294
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_0216AC90 (ov010) +0026 and
 * func_0216ACCC (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 *
 * symbols:
 *   func_0216D63C  0x0216D63C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D63C(char *a0, int a1);

int func_0217C294(char *a0)
{
    return func_0216D63C(a0, 0);
}
