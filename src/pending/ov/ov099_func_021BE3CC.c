/*
 * function: func_021BE3CC
 * address:  0x021BE3CC
 * packet:   pkt_ov099_021BE3CC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note: 2026-10-05 (wD6 lane13): DIFF 14 bytes (was 43, size now 124). Logic fix: ptr = base + (d & 0xF) * 2 (u16 elements, the image scales twice). Callers pass b, c as u8 and a sixth argument: b, c are u8 parameters now (stack order of b, c fixed). The call result goes into t and x = t << 12 after ptr (x spill store late, as in the image). Residue: p r5 / base r4 (image p r4 / base r5) and the schedule around the ptr add. Tried: statement orders of row/stride/ptr (worse), a struct for p (same), base declared first (same).
 *
 * note: 2026-10-05 (wD5 lane17): not changed. Re-read the listing: the image stores b and c to [sp],[sp,#4] before copying p to r4, and a to [sp,#0x18] after copying it to r0; p is r4 and base r5 (ours the reverse). No new compile tried beyond the earlier declaration-order variants.
 *
 * note (2026-10-04): DIFF, 120 vs 124 bytes, same instruction mix. Semantics and the four spill slots (x=sp+8, ptr=sp+0xc, stride=sp+0x10, row=sp+0x14, set by reverse declaration order) now match. Residue: register colouring (original p=r4, base=r5, ours p=r5, base=r4), original stores b,c to the stack before loading base, and uses r2/r1 temps instead of r0 for the row/stride math. Declaration-order variants of i/j did not change it.
 *
 * note (2026-10-04, lane17): lane17 wave D2: re-read, no new change. Same residue (colouring p/base swap, early b,c stack stores).
 *
 * note: 2026-10-05 (wD4 lane20): not changed; no new hypothesis beyond the 2026-10-04 notes.
 * symbols:
 *   func_021BE4EC  0x021BE4EC  thumb  ov099
 *   func_02042FB0  0x02042FB0  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BE4EC(u32 a);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void func_02041B6C(u32 bit);

void func_021BE3CC(char *p, u32 a, u8 b, u8 c, u32 d, int e)
{
    int row;
    u32 stride;
    u16 *ptr;
    int x;
    u16 *base;
    int i, j;
    int t;

    base = (u16 *)(*(char **)(p + 4) + 0xC);
    t = func_021BE4EC(a);
    row = (d >> 4) * 2;
    stride = (u32)**(u16 **)(p + 4) >> 3;
    ptr = base + (d & 0xF) * 2;
    x = t << 12;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02042FB0(a, j + b, i + c, x + ptr[(row + i) * stride + j]);
        }
    }
    func_02041B6C((u8)a);
}
