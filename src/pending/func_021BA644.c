/*
 * function: func_021BA644
 * address:  0x021BA644
 * packet:   pkt_021BA644
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  21 bytes differ; original builds -1 via subs off a zero register, mwcc folds to mvns.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021BA644(char *p)
{
    u32 z = 0;

    *(int *)(p + 0x24) = z - 1;
    *(int *)(p + 0x28) = z - 1;
    *(int *)(p + 0x20) = z;
    *(u8 *)(p + 0x40) = 0xFF;
    *(int *)(p + 0x44) = z;
}
