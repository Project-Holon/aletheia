/*
 * function: func_02072794
 * address:  0x2072794
 * packet:   pkt_02071B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x02089754 and 0x02089774 each have no witness outside this range: their only caller is this function
 *
 * Both arms carry their own `pop {r3, pc}` in the original rather than a
 *  * cross-jumped shared tail, which is what the two-armed if/else gives.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02089754(u32);
extern void func_02089774(void);

void func_02072794(u32 v)
{
    if (v != 0) {
        func_02089754(0x40);
    } else {
        func_02089774();
    }
}
