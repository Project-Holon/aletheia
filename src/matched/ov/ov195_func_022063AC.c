/*
 * function: func_022063AC
 * address:  0x022063AC
 * packet:   pkt_022063AC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);

void func_022063AC(char *a, u32 v)
{
    u32 buf[3];
    u8 i;

    for (i = 0; i < 2; i++) {
        char *p = a + i * 4;
        if (*(u32 *)(p + 0x50) != 0) {
            func_02015C30((void *)(*(u32 *)(p + 0x50)), buf);
            buf[0] = v;
            func_02015C48((void *)(*(u32 *)(p + 0x50)), buf);
        }
    }
}
