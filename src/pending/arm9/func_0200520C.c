/*
 * function: func_0200520C
 * address:  0x0200520C
 * packet:   pkt_0200520C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *
 * One of the three callers of the boot path's scene switch (.text init
 * helpers): run func_02005640, set bit 0 of the word at the end of the
 * arm9_autoload1_main_twl region, then enter mode 3.
 *
 * The address is *two* pool words, not one: the listing writes
 * 0x02FE0000 (`arm9_autoload1_main_twl+0x0`) and the plain literal 0x3FF8,
 * and the load is a register-offset `ldr r2, [r3, r1]`.  That split is the
 * tell that the source named the linker-defined region symbol and added a
 * byte offset to it rather than writing the absolute address: a constant
 * 0x02FE3FF8 pools as a single word with no relocation at all (47 other
 * sites in the image hold 0x02FE3000 outright).  Same finding as
 * src/pending/sub_02030534.c's header, where the base is 0x02FE0000 and the
 * offset 0x3000 fits an `add`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200520C.c \
 *       --func func_0200520C --addr 0x0200520C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02005640(void);
extern void func_02082594(int mode);
extern u32  SDK_AUTOLOAD_MAIN_TWL_START[];

void func_0200520C(void)
{
    func_02005640();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
    func_02082594(3);
}
