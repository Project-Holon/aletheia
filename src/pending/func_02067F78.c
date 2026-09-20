/*
 * function: func_02067F78
 * address:  0x02067F78
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_020698F8    0x020698F8  arm
 *   func_02069C00    0x02069C00  arm

 * Blocking class: label.  Every concrete byte is right; both relocation sites are
 * unresolved and both for the same reason: the `bl func_020698F8` at 0x02067F88 is
 * the only branch to 0x020698F8 in the image, and the pool word that stores
 * 0x02069C00 as a value (+0x20) is the only reference to that address anywhere, so
 * neither `label` nor `literal` has a witness outside this file's 32 bytes.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020698F8(u32 a, void *b);
extern u8 func_02069C00[];

void func_02067F78(void *a, u32 b)
{
    func_020698F8(b, a);
    ((u32 *)a)[1] = (u32)func_02069C00;
}
