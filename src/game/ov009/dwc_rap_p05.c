/*
 * file:     dwc_rap_p05.c
 * unit:     yes
 * function: func_02155674, func_02155678
 * address:  0x02155674
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    char pad[0x7a5];
    u8 b7a5;
} G;

void func_02155674(void);
u8 func_02155678(void);
extern G *d_021A8264;

/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by func_0215568C / func_0215580C.
 */
void func_02155674(void)
{
}


/*
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 */
u8 func_02155678(void)
{
    return d_021A8264->b7a5;
}
