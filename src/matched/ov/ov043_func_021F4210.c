/*
 * function: func_021F4210
 * address:  0x021F4210
 * packet:   pkt_ov043_021F4210
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 */
#include "../include/Obj01223.h"

typedef unsigned char u8;

extern void func_0218EC54(u8 *p);
extern void func_0218EC30(int p, int v);
extern void func_0218ECC4(int p, int *v);
extern void func_0218ECD4(int p, void *v);

int func_021F4210(u8 *s)
{
    int v[3];

    switch (s[0]) {
    case 0:
        func_0218EC54((u8 *)(((struct Obj01223 *)s)->f8));
        s[0]++;
    case 1:
        if (s[3] % 2 == 0) {
            func_0218ECC4(((struct Obj01223 *)s)->f8, v);
            v[1] = v[1] + ((struct Obj01223 *)s)->f4;
            func_0218ECD4(((struct Obj01223 *)s)->f8, v);
            ((struct Obj01223 *)s)->f4 *= -1;
            s[1]++;
            if (s[1] >= s[2] * 2) {
                if (((struct Obj01223 *)s)->fC) {
                    func_0218EC30(((struct Obj01223 *)s)->f8, ((struct Obj01223 *)s)->fC);
                }
                func_0218ECD4(((struct Obj01223 *)s)->f8, s + 0x10);
                return 1;
            }
        }
        s[3] = (s[3] + 1) % 2;
    }
    return 0;
}
