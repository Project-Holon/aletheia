/*
 * function: func_021E0BE8
 * address:  0x021E0BE8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E0BE8   0x021E0BE8  thumb ov093
 *   func_021C815C   0x021C815C  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021B9A24   0x021B9A24  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   func_021C830C   0x021C830C  thumb ov093
 *   func_021C8290   0x021C8290  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *
 * Six rejections in a row (func_021C815C(b) zero or 3, func_021B9A24(c,k),
 * BTL_EVENT_GetVar(0x12) == 0x1fb, BTL_POKEPARAM_HasSick(r,0x21), func_021C830C(b),
 * func_021C8290(b,k,c,(u16)BTL_EVENT_GetVar(0x12))) before BTL_EVENT_OverwriteVar(4, c).
 * The 0x1fb is the image's own pool constant.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021C815C(int *p);
int BTL_EVENT_GetVar(int a);
void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
int func_021B9A24(unsigned int a, unsigned int b);
int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
unsigned int func_021C830C(u8 *p);
int func_021C8290(u8 *p, int a, int b, void *item);
int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E0BE8(void *a, int b, int c)
{
    void *r;
    u8 k;
    u16 t;

    if (func_021C815C((int *)b) == 0)
        return;
    if (func_021C815C((int *)b) == 3)
        return;
    k = (u8)BTL_EVENT_GetVar(3);
    r = func_021C7CF4((int *)b, c);
    if (func_021B9A24(c, k) != 0)
        return;
    if (BTL_EVENT_GetVar(0x12) == 0x1fb)
        return;
    if (BTL_POKEPARAM_HasSick(r, 0x21) != 0)
        return;
    if (func_021C830C((u8 *)b) != 0)
        return;
    t = (u16)BTL_EVENT_GetVar(0x12);
    if (func_021C8290((u8 *)b, k, c, (void *)t) != 0)
        return;
    BTL_EVENT_OverwriteVar(4, c);
}
