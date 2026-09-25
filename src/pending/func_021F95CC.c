/*
 * function: func_021F95CC
 * address:  0x021F95CC
 * packet:   pkt_021F95CC
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  23 bytes differ; if/else fall-through arm and register choice.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021F95CC(char *p, u8 v, int c)
{
    if (c == 1) {
        *(u8 *)(p + 0xF0) = v;
    } else {
        *(u8 *)(p + 0xF0) = 4;
        *(int *)(p + 0xEC) = 1;
    }
    return;
}
