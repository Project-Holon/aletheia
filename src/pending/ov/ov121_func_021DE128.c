/*
 * function: func_021DE128
 * address: 0x021DE128
 * packet: pkt_ov121_021DE128
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P23 lane 10): 7/44 bytes differ (older draft 11/44). Only b and c are
 *   swapped (image b r7, c r4, d r6, p r5; build b r4, c r7). Best form returns the halfword
 *   read back from +2 (the image leaves it in r0 at the pop): `t = *(u16 *)(p+2); ... *(u16 *)p = t; ... return t;`.
 *   Return type u16, int, int t, u32 c/d, load placed late: all 7. Return written as `r = *(u16 *)p = *(u16 *)(p+2)`
 *   or `return *(u16 *)p`: 11. Tried and flat at 11: six per-function pragmas, int callee size parameter,
 *   p as char *, c/d as u32. Worse: int b (truncation added, 34), short b (37), u16 pointer array (34),
 *   struct pointer for the c/d pairs (30), b store moved after the c/d stores (16).
 *   int b alone gives the image colours (b r7, c r4, d r6) but adds lsls/lsrs; the image has u16 b with no
 *   truncation. The only caller (ov121 021DD9CC) declares this function void and ignores the result.
 * final push 2026-10-05 G3L4: still 7/44 (b/c swap only, b r4 c r7 vs image b r7 c r4). ~45 more compiles, all 7 unless noted:
 *   Pt struct by value (40), full struct view with int params (7), u16/int array views (7), local copies of b/c/d in
 *   every order (7), duplicate store of b (7/11), extra b store (colours unchanged), return b (19), int/u32 b (37/37),
 *   u8 b (7), K&R definition (39), q pointer for the c/d pairs (29), callee decls (void*,int,int), (void*,u32,u32),
 *   (u8*,u8,u32), (void*,int,u32) (all 7). Register choice did not move with use counts (b stayed r4 when c/d uses were cut or b
 *   uses raised), so it is a birth-order effect. Matched ov072 func_021BB3E8 and arm9 func_0200AC14 share the same prologue
 *   (r7,r4,r5,r6) but have no narrow arg, so give no source form for it. Return of the halfword in r0 is real: the caller
 *   ov121 021DD9CC declares void and ignores it (the result is a leftover of t); the u16 return form is kept.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32);
u16 func_021DE128(u8 *p,u16 b,int c,int d)
{
    u16 t;
    func_02082BCC(p,0,44);
    *(u16 *)(p+2)=b;
    *(u16 *)(p+10)=11;
    t=*(u16 *)(p+2);
    *(u16 *)(p+4)=b;
    *(int *)(p+20)=c;
    *(int *)(p+24)=d;
    *(int *)(p+28)=c;
    *(int *)(p+32)=d;
    *(u16 *)p=t;
    *(int *)(p+36)=c;
    *(int *)(p+40)=d;
    return t;
}
