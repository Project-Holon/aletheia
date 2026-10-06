/*
 * function: func_021A2A18
 * address:  0x021A2A18
 * packet:   pkt_ov021_021A2A18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_021A1698  0x021A1698  thumb  ov021
 *   func_021A16D4  0x021A16D4  thumb  ov021
 *   func_021A16D8  0x021A16D8  thumb  ov021
 *   d_021EE710     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */

typedef struct {
    char pad0[8];
    unsigned char b8;
    char pad9[3];
} Buf;

typedef struct {
    char pad0[4];
    int f4;
    int f8[2];
    int f10;
} Obj;

extern unsigned char d_021EE710[12];
extern unsigned char d_021EE710b[12];

void func_02082D44(void *src, void *dst, int n);
int func_021A1698(unsigned int a, int b, void *c, int d);
typedef unsigned int   u32;
typedef unsigned char  u8;
void func_021A16D4(u8 *p, u32 v);
void func_021A16D8(u8 *p, u8 v);

void func_021A2A18(Obj *o, int idx, void *p, void *src, unsigned short x)
{
    func_02082D44(src, d_021EE710, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    func_021A1698((unsigned int)p, o->f10, d_021EE710, x);
    func_021A16D4(p, 0);
    func_021A16D8(p, 0x20);
    o->f8[idx] = 1;
}
