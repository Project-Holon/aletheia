/*
 * function: func_020274C8
 * address:  0x020274C8
 * packet:   pkt_020274C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT*. The pooled overlay-id site
 *           ov231_id (231) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * The ABS32 pool word 0x000000E7 is an absolute overlay-id symbol (ov231,
 * matching the bl into func_021809D8 in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * EXACT* because the listing extent (84 bytes) runs over the follower
 * sub_020274F8.
 *
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
extern int   func_02034AC4(signed int id);
extern int   func_021809D8(void);
extern void  func_02034A5C(int id);
extern void  sub_020274F8(void);
extern void  func_02005624(void *fn, u32 b, u32 c);

void func_020274C8(void)
{
    int r;

    func_02034AC4((int)ov231_id);
    r = func_021809D8();
    func_02034A5C((int)ov231_id);
    if (r == 0) {
        func_02005624(sub_020274F8, 0, 3);
    }
}
