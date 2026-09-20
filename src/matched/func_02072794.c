/*
 * function: func_02072794
 * address:  0x02072794
 * packet:   pkt_020728E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern void func_02089754(u32 v);
extern void func_02089774(void);

void func_02072794(u32 flag)
{
    if (flag != 0) {
        func_02089754(0x40);
    } else {
        func_02089774();
    }
}
