/*
 * function: func_021D683C
 * address: 0x021D683C
 * packet: pkt_ov125_021D683C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7700 0x021D7700 thumb ov125
 *   func_021D730C 0x021D730C thumb ov125
 *   func_021D7154 0x021D7154 thumb ov125
 *   func_021D71CC 0x021D71CC thumb ov125
 *   func_0200B910 0x0200B910 thumb
 */
typedef unsigned short u16;
extern char *func_021D7700(int);
typedef unsigned int   u32;
struct ObjC4;
extern int func_021D730C(char *p);
extern void func_0200B784(u16, int *, int *);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D71CC(const void *src, void *dst, u32 n);
extern struct ObjC4 *func_0200B910(void);
extern void func_02082D44(void *, const void *, unsigned int);
int func_021D683C(char *p, void *dst)
{
    char *r;
    char *out;
    char *base;
    int outer, inner;
    int n, m;
    int i;
    r = func_021D7700((int)p);
    if (!func_021D730C(p)) return 0;
    func_0200B784(*(u16 *)(r + 0xa6), &n, &m);
    base = r + 0xd00;
    out = p + 0x498;
    for (i = 0; i < 12; i++) {
        if (!func_021D7154((int)p, i, &outer, &inner)) break;
        func_021D71CC(base + outer * 676 + inner * 112 + 50, out + i * 22, 11);
    }
    *(int *)(p + 0x5a0) = 0;
    p[0x403] = 0;
    *(char **)(p + 0x174) = r;
    func_02082D44(dst, func_0200B910(), 128);
    p[0x401] = 60;
    *(int *)(p + 0x3d8) = 0x55f0;
    return 1;
}
