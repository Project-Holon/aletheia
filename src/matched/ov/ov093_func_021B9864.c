/*
 * function: func_021B9864
 * address:  0x021B9864
 * packet:   pkt_ov093_021B9864
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair that disasm.py did not label.
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021B9B94(void *);
typedef unsigned int u32;
extern u8 *func_021B9C00(void *p, u32 i);
extern u8 func_021D5440(u8 *p);

int func_021B9864(int a, int b, int c)
{
    char *p = (char *)(a + 4) + b * 0x1c;
    unsigned int n = func_021B9B94(p);
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (c == func_021D5440((u8 *)func_021B9C00(p, (unsigned char)i)))
            return i;
    }
    return -1;
}
