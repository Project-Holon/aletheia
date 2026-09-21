/*
 * function: func_020274C8
 * address:  0x020274C8
 * packet:   pkt_020274C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * Blocked on: literal.  Every concrete byte reproduces; the only unresolved
 * relocation is the ABS32 pool word 0x000000E7, an absolute overlay-id symbol
 * (ov231, matching the bl into func_021809D8 in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  The
 * value appears in no other literal pool, so its only witness is this
 * function's own pool word and no cut helps.
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_021809D8  0x021809D8  thumb ov231
 *   func_02034A5C  0x02034A5C  arm
 *   sub_020274F8   0x020274F8  thumb
 *   func_02005624  0x02005624  thumb
 *   ov231_id       0x000000E7  data
 */

typedef unsigned int u32;

extern char  ov231_id[];
extern void  func_02034AC4(void *id);
extern int   func_021809D8(void);
extern void  func_02034A5C(void *id);
extern void  sub_020274F8(void);
extern void  func_02005624(void *fn, u32 b, u32 c);

void func_020274C8(void)
{
    int r;

    func_02034AC4(ov231_id);
    r = func_021809D8();
    func_02034A5C(ov231_id);
    if (r == 0) {
        func_02005624(sub_020274F8, 0, 3);
    }
}
