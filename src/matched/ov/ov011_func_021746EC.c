/*
 * function: func_021746EC
 * address:  0x021746EC
 * packet:   pkt_ov011_021746EC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   func_02082D44  0x02082D44  arm
 *   func_02012800  0x02012800  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_02026478(void *obj);
u8 *func_020127D0(u8 *o, u32 idx);
int func_021583EC(void *a0, int a1);
typedef unsigned short u16;
void func_021861F4(u16 *p, int x);
void func_02082D44(void *d, void *s, int n);
void func_02012800(u8 *obj, void *dst);

void func_021746EC(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = func_02026478((void *)(*(int *)(d + 4)));
    s = (int)func_020127D0((u8 *)h, 0);
    func_021861F4(c, func_021583EC((void *)h, a));
    func_02082D44(c, (void *)s, 0x1E8);
    func_02012800((u8 *)h, c);
    d[0x90C] = 1;
}
