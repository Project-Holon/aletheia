/*
 * function: func_021C2C1C
 * address:  0x021C2C1C
 * packet:   pkt_021C2BF4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Moves the object at +0xB8 from state 1 to state 2.
 */


extern int func_02005E50(int);
extern void func_02005DE4(int);
extern void func_02005E64(void);

void func_021C2C1C(int unused, char *p)
{
    if (*(int *)(p + 0xb8) == 1) {
        if (func_02005E50(*(int *)(p + 0xb8)) == 0) {
            func_02005DE4(1);
            func_02005E64();
            *(int *)(p + 0xb8) = 2;
        }
    }
}
