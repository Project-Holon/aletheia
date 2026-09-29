/*
 * function: func_021D2510
 * address:  0x021D2510
 * packet:   pkt_ov093_021D2510
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021EF9C8  0x021EF9C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021EA678(void *w, u16 v, int z);
extern int func_021EA710(void *w);
extern void func_021EF9C8(void *w);

int func_021D2510(u8 *p, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(*(void **)(p + 0x54), v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(*(void **)(p + 0x54))) {
            func_021EF9C8(*(void **)(p + 0x34));
            return 1;
        }
        break;
    }
    return 0;
}
