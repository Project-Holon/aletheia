/*
 * function: func_02205620
 * address:  0x02205620
 * packet:   pkt_02205620
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 kind;
    u32 val;
} Param;

extern u32 func_02045EC0(u32, u32);
extern u32 func_0201EC64(u32);
extern void func_0201EE0C(u32, u32, u32, int, int, int);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF34(u32, u32, u16);
extern u32 func_020457B0(int, u32);
extern void func_0201F250(u32, u32, u32);
extern void func_02045808(u32);
extern void func_0201ED04(u32);

u32 func_02205620(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1)
{
    Param p[2];
    u32 src, w, r, i;
    int z;

    if (k0 == 4 && k1 == 4) {
        r = func_02045EC0(a, b);
    } else {
        src = func_02045EC0(a, b);
        w = func_0201EC64(heap);
        p[0].kind = k0;
        p[0].val = v0;
        p[1].kind = k1;
        p[1].val = v1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                func_0201EE0C(w, i, p[i].val, z, 1, z);
                break;
            case 1:
                func_0201EE84((void *)w, i, (void *)p[i].val);
                break;
            case 2:
                func_0201EEF4((void *)w, i, (void *)p[i].val);
                break;
            case 3:
                func_0201EF34(w, i, *(u16 *)p[i].val);
                break;
            }
        }
        r = func_020457B0(0x100, heap);
        func_0201F250(w, r, src);
        func_02045808(src);
        func_0201ED04(w);
    }
    return r;
}
