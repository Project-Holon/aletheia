/*
 * function: func_02029DFC
 * address:  0x02029DFC
 * packet:   pkt_02029DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  02028900 label
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 func_02012A30(void);
extern void func_02028900(u32 a0);

void func_02029DFC(void)
{
    func_02028900(func_02012A30());
}
