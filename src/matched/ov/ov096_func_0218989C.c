/*
 * function: func_0218989C
 * address: 0x0218989C
 * packet: pkt_ov096_0218989C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller-visible return/second arguments override tail-forwarder declarations.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A308 0x0218A308 thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 */
#include "../include/Obj07926.h"
typedef unsigned char u8;
extern unsigned int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
typedef unsigned int   u32;
extern u8 *func_0218A308(void *p, u32 i);
struct QG;
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D5B68(void *);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D554C(u8 *p, u8 i);
int func_0218989C(int a, int b)
{
    int x, z, n;
    char *p;
    int i, j;
    u8 y;
    x = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160((u8 *)b, x);
    n = func_021B8DE4((char *)(((struct Obj07926 *)b)->fB0), y);
    p = func_021B9AF8(*(char * *)&((struct Obj07926 *)b)->fB8, n);
    i = func_021B99B8((void *)(((struct Obj07926 *)b)->fB0), n);
    for (; i < func_021B9B94((struct Q1 *)p); i++) {
        if (func_021D5B68(func_0218A308(p, (u8)i)) == 0) {
            for (j = 0; j < func_021D5448((struct QG *)func_0218A2FC((u8 *)b, y)); j++) {
                if (func_0218A0F4((u8 *)a, 3, func_021D554C(func_0218A2FC((u8 *)b, y), j), 0, z) != 0)
                    break;
            }
            if (j != func_021D5448((struct QG *)func_0218A2FC((u8 *)b, y)))
                break;
        }
    }
    return ((struct Obj07926 *)b)->fC4;
}
