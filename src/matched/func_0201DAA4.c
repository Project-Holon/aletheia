/*
 * function: func_0201DAA4
 * address:  0x0201DAA4
 * packet:   pkt_0201DA24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0024 ABS32 func_0201DBF4          : 0201DBF4 (thumb, from name) has no witness outside 0201DAA4..0201DADC +0034 ABS32 func_0201E938          : 0201E938 (arm, from name) has no witness outside 0201DAA4..0201DADC
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0201DBF4(void);
extern void func_0201DE40(void);
extern void func_0201E538(void);
extern void func_0201E738(void);
extern void func_0201E938(void);

void func_0201DAA4(char *p, int a, int b)
{
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 4) = (u32)func_0201DBF4;
    if (a == 1)
        *(u32 *)(p + 8) = (b == 1) ? (u32)func_0201DE40 : (u32)func_0201E538;
    else
        *(u32 *)(p + 8) = (b == 1) ? (u32)func_0201E738 : (u32)func_0201E938;
}
