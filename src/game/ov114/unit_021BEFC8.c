/*
 * file:     unit_021BEFC8.c
 * unit:     yes
 * function: func_021BEFC8, func_021BEFCC, func_021BEFD8
 * address:  0x021BEFC8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B58  0x021B9B58  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021B9B58(void);
extern void func_02086078(void);
void func_021BEFC8(void);
void func_021BEFCC(void);
void func_021BEFD8(void);

/*
 * Empty ARM stub: `bx lr`.
 */
void func_021BEFC8(void)
{
}


/*
 * unblocked: func_021B9B58 (the ARM veneer `ldr ip,[pc]; bx ip; .word
 *   0x02086028`, printed as a .word run in ov114) was matched as the same
 *   far-tail-call shape and filed as pkt_ov114_021B9B58; the ABS32 site then
 *   attests as `matched, overlay`.
 *
 * Tail-call thunk to the ARM stub at 0x021B9B58.
 */
void func_021BEFCC(void)
{
    func_021B9B58();
}


/*
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */
void func_021BEFD8(void)
{
    func_02086078();
}
