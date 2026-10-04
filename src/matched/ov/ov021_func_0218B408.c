/*
 * function: func_0218B408
 * address:  0x0218B408
 * packet:   pkt_ov021_0218B408
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3098  0x021A3098  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0218B6F8  0x0218B6F8  thumb
 *   func_0218B3DC  0x0218B3DC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern int func_021A3098(void *a);
extern u32 func_02188C98(u8 *p);
extern int func_021A2FA4(int a, int b);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F8(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(int a);
extern void func_02164208(int a, int *b, int c);
extern int func_0218B6F8(char *p, void *x);
extern int func_0218B3DC(int unused, int a, int b, int c, int d);

int func_0218B408(char *p, void *a, void *x)
{
    void *cam;
    int r7;
    int t;
    int flag;
    int t2;
    void *id;
    int v;
    int buf[3];

    id = func_02188CB4(x);
    if (func_021A3098(id) == 2) {
        cam = (void *)func_02188C98(x);
        r7 = func_021A2FA4(*(int *)(p + 0x18), *(int *)(p + 0x2C));
        if (r7 != 9) {
            func_021A3364(id, r7, buf);
            t = func_021AB0D4(cam, buf);
            v = func_021AB0F8(t);
            t2 = func_021AB0F0(t);
            flag = 0;
            if (func_021AB2E8(t2) == 1) {
                func_02164208(r7, buf, 0x10000);
                v = func_021AB0F8(func_021AB0D4(cam, buf));
                flag = 1;
            }
            if (func_0218B6F8(p, x) == 1 && !(v & 1) && !(v & 2))
                return func_0218B3DC((int)p, (int)a, (int)x, r7, flag);
        }
    }
    return 0;
}
