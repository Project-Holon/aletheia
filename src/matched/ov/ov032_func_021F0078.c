/*
 * function: func_021F0078
 * address:  0x021F0078
 * packet:   pkt_ov032_021F0078
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0078  0x021F0078  thumb
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02012204  0x02012204  thumb
 *   func_021F253C  0x021F253C  thumb  ov032
 *   func_0201058C  0x0201058C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021585E0(int);
struct Ctx;
extern u32 func_02012204(const struct Ctx *p);
extern void func_021F253C(char *p, u16 v);
extern u32 func_0201058C(void *key);

int func_021F0078(char *p)
{
    int r;

    r = func_021585E0(*(int *)(p + 0x1C));
    if (func_02012204((const struct Ctx *)(*(u32 *)p)) != 0) {
        func_021F253C(p, 1);
        return 1;
    }
    if (r == 2) {
        func_021F253C(p, 2);
        return 1;
    }
    if (func_0201058C((void *)(*(int *)(p + 0x20))) & 8) {
        func_021F253C(p, 3);
        return 1;
    }
    return 0;
}
