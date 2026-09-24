/*
 * function: func_021BC678
 * address:  0x021BC678
 * packet:   pkt_021BC678
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *
 * Releases +0 and re-checks the handle at +8 for the two armed states at +0x10.
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

