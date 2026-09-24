/*
 * function: func_021BC678
 * address:  0x021BC678
 * packet:   pkt_021BC678
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)
 *
 * Re-runs the +8 check when the +0x10 state is 2 or 3.
 *
 * BLOCKED.  MATCH: every concrete byte right (68 of 68), two relocation sites.
 * The call at +0x26 targets 02021ED8, which the ARM9 listing prints as a
 * literal-pool word (pool_02021ED4 holds 0x00892146 there) and never labels,
 * so 29 overlay call sites and no func_ label; the site stays wildcarded.
 * Not a source problem: same class as func_021BDCDC's 0204047C.
 */


extern void func_02030D28(int);
extern int func_02021ED8(int);

void func_021BC678(char *p)
{
    func_02030D28(*(int *)p);
    switch (*(int *)(p + 0x10)) {
    case 0:
    case 1:
        break;
    case 2:
        if (func_02021ED8(*(int *)(p + 8)) == 0)
            *(int *)(p + 0x10) = 0;
        break;
    case 3:
        if (func_02021ED8(*(int *)(p + 8)) == 0)
            *(int *)(p + 0x10) = 1;
        break;
    }
}
