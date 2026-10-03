/*
 * function: func_021D7AA8
 * address: 0x021D7AA8
 * packet: pkt_ov116_021D7AA8
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ov114 ARM 021C93D0 has no outside code-start witness. It is vendor/Ilias-owned: adjacent SDK EXT_TestResetCounter at 021C93BC (libext/ext_scrntest.o) uses same datum 021D4084; no SDK row exists for query leaf. TU/split cannot produce a viable partition.
 * symbols:
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021C93D0(void);
extern void func_021C9634(void);
extern void func_021D70E4(u8 *);
void func_021D7AA8(u8 *p)
{
    if (func_021C93D0() == 0) {
        func_021C9634();
        func_021D70E4(p + 0x182c);
    }
}
