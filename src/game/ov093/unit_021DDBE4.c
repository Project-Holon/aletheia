/*
 * file:     unit_021DDBE4.c
 * function: func_021DDBE4, func_021DDBF8
 * address:  0x021DDBE4
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F17EC     0x021F17EC  data   ov093  a4
 *   func_021DDBE4   0x021DDBE4  thumb
 *   func_021DDCD8   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xd; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DDBE4  shape F2: two stack constants (0xd, 0) */
void func_021DDBE4(int a, int b, int c, int d)
{
    func_021DDCD8(a, b, c, d, 0xd, 0);
}


extern int d_021F17EC[];
int *func_021DDBF8(int *p);

int *func_021DDBF8(int *p)
{
    *p = 2;
    return d_021F17EC;
}
