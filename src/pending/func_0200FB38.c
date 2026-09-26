/*
 * function: func_0200FB38
 * address:  0x0200FB38
 * packet:   pkt_0200FB38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Unlabelled Thumb leaf accessor: if the u32 at +0x2c of the object at
 * g_020A729C is 1, set it to 2.
 *
 * NOT EXACT for 5 bytes: a pure r0/r1 swap.  The original keeps the record
 * base in r0 and the loaded field in r1 (`ldr r0,[pc,#0xc]; ldr r1,[r0,
 * #0x2c]; cmp r1,#1; ... str r1,[r0,#0x2c]`); mwcc folds the address into r1
 * and the field into r0 (`ldr r1,[pc,#0xc]; ldr r0,[r1,#0x2c]`).  Every
 * spelling tried (pointer local, struct member, volatile, const pointer,
 * separate value local, comma-reversed compare, byte-base plus offset) folds
 * the same way.  The pool word and ABS32 relocation are correct.
 *
 * symbols:
 *   func_0200FB38  0x0200FB38  thumb
 *   g_020A729C     0x020A729C  data  a4
 */

extern unsigned char g_020A729C;

void func_0200FB38(void)
{
    unsigned int *p = (unsigned int *)(&g_020A729C);

    if (p[0xB] == 1) {
        p[0xB] = 2;
    }
}
