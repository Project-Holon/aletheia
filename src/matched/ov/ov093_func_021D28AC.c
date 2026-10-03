/*
 * function: func_021D28AC
 * address:  0x021D28AC
 * packet:   pkt_ov093_021D28AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021D6C50  0x021D6C50  thumb  ov093
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021B9934(char *p, int i);
extern int func_021B8DC0(void *p, void *a, u8 b);
struct Unk021D6C50;
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(void *w);

int func_021D28AC(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(*(char **)(p + 4), (u8)c[0]);
        u8 *b = func_021B9934(*(char **)(p + 4), (u8)c[1]);
        int d = func_021B8DC0(*(void **)p, *(void **)(p + 4), c[0]);
        int e = func_021B8DC0(*(void **)p, *(void **)(p + 4), c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(*(void **)(p + 0x54), d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(*(void **)(p + 0x54)))
            return 1;
        break;
    }
    return 0;
}
