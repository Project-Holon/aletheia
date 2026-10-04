/*
 * function: func_021B6E68
 * address:  0x021B6E68
 * packet:   pkt_ov021_021B6E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Search the 0x24-byte records for the one whose second halfword is 0x46
 * and return its first.  The return reads through a byte offset rather
 * than t[i].a: the subscript form lets the compiler CSE t + i*0x24 into
 * one register (product in r2, ldrh r0,[r3]); the byte-offset form keeps
 * only the product live and loads ldrh r0,[r4,r3] as the original does.
 *
 * symbols:
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char u8;

struct Ent { u16 a; u16 b; u8 pad[0x20]; };

typedef unsigned int   u32;
struct BigObj;
u32 func_02012844(const struct BigObj *p);
u32 func_02162740(u8 *p);
u16 func_02162744(u8 *p);

int func_021B6E68(int a)
{
    struct Ent *t;
    int n;
    int m;
    int i;

    m = func_02012844((const struct BigObj *)a);
    t = (struct Ent *)func_02162740((u8 *)m);
    n = func_02162744((u8 *)m);
    if (t == 0 || n == 0) {
        return -1;
    }
    for (i = 0; i < n; i++) {
        if (t[i].b == 0x46) {
            return *(u16 *)((u8 *)t + i * 0x24);
        }
    }
    return -1;
}
