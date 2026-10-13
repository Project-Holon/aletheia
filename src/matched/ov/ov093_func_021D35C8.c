/*
 * function: BTL_CLIENT_CmdChangeForm
 * address:  0x021D35C8
 * packet:   pkt_ov093_021D35C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_ChangeForm  0x021D66D8  thumb  ov093
 *   func_021EA888  0x021EA888  thumb  ov093
 *   func_021EA8A4  0x021EA8A4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021B8E70(u8 *p, u32 k);
extern u8 *func_021B9934(char *p, int i);
extern void BTL_POKEPARAM_ChangeForm(u8 *m, u8 v);
extern void func_021EA888(char *ctx, int a);
extern int func_021EA8A4(u32 *p);

int BTL_CLIENT_CmdChangeForm(u32 *a, int *b, u32 *c)
{
    int x;

    switch (*b) {
    case 0:
        x = func_021B8E70((u8 *)a[0], func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]));
        BTL_POKEPARAM_ChangeForm(func_021B9934((char *)a[1], (u8)c[0]), (u8)c[1]);
        func_021EA888((char *)a[0x15], x);
        (*b)++;
        break;
    case 1:
        if (func_021EA8A4((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
