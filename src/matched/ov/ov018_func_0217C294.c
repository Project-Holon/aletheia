/*
 * function: INTRUDE_FIELD_GetMmdlParam0
 * address:  0x0217C294
 * packet:   pkt_0217C294
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of SCRCMD_SYMBOL_SelectObjectEntry (ov010) +0026 and
 * SCRCMD_SYMBOL_MoveObjectEntryToPairedBand (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 *
 * symbols:
 *   FLDMMDL_GetParam  0x0216D63C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_GetParam(char *a0, int a1);

int INTRUDE_FIELD_GetMmdlParam0(char *a0)
{
    return FLDMMDL_GetParam(a0, 0);
}
