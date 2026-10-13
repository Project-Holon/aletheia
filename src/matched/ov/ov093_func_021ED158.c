/*
 * function: func_021ED158
 * address:  0x021ED158
 * packet:   pkt_ov093_021ED158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ED798  0x021ED798  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_021F7B2C  0x021F7B2C  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   GFL_USE_StopAllSe  0x02006210  thumb
 */

typedef unsigned char u8;

struct S;
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *s);
extern void func_021F7B2C(u8 *);
extern int func_021F7EB4(void);
extern void GFL_USE_StopAllSe(void);

int func_021ED158(int *st, u8 *b)
{
    switch (*st) {
    case 0:
        func_021ED798((struct S *)(b + 0x154));
    inc:
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED814((struct S *)(b + 0x154)) != 0) {
            func_021F7B2C(b + 0xf0);
            goto inc;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            GFL_USE_StopAllSe();
            goto inc;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
