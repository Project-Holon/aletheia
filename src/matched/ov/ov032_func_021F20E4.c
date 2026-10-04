/*
 * function: func_021F20E4
 * address:  0x021F20E4
 * packet:   pkt_ov032_021F20E4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F20E4 0x021F20E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02031194 0x02031194 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0201C6C4(u32 a, u32 b);
struct Descriptor;
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(u32 a);
extern u8 func_02045730(u32 a);
extern void *func_02045770(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);

void func_021F20E4(void *task, char *q)
{
    u8 *s;
    u32 v;
    int *r;

    v = *(u32 *)(*(char **)(q + 8) + 0xb4);
    s = *(u8 **)(q + 4) + 8;
    if (s[4] != 0) {
        if (func_0201C6C4(v, (u32)func_02045770((struct Descriptor *)*(u32 *)s)) == 0) {
            func_02045334((struct Descriptor *)*(u32 *)s);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        func_02045374(**(u32 **)(q + 4));
        func_02041B6C(func_02045730(**(u32 **)(q + 4)));
        r = *(int **)(q + 0xc);
        if (r != 0)
            (*r)--;
        func_02031194(task);
    }
}
