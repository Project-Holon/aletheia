/*
 * function: func_02156BAC
 * address:  0x02156BAC
 * packet:   pkt_02156BAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One-shot state test: only when the mode word is 1, the arm9 predicate
 * agrees and the flag is clear does the flag get set.
 *
 * symbols:
 *   func_0200FB24   0x0200FB24  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0200FB24(int);

void func_02156BAC(void *p)
{
    int v = *(int *)((char *)p + 0x14);

    if (v == 1) {
        if (func_0200FB24(v)) {
            if (*(int *)((char *)p + 0x50) == 0) {
                *(int *)((char *)p + 0x50) = 1;
            }
        }
    }
}

