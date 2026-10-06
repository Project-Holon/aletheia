/*
 * function: func_021A7654
 * address:  0x021A7654
 * packet:   pkt_ov021_021A7654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A78DC  0x021A78DC  thumb
 *   func_021A7818  0x021A7818  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 b[0x40];
} E;

typedef struct {
    E e[16];
    void *p;
} S;

typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern int func_021A78DC(u32 a);

extern void func_021A7818(struct Obj *a, s32 dt);

void func_021A7654(S *s, int x)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (func_021A78DC((u32)(&s->e[i]))) {
            func_021A7818((struct Obj *)(&s->e[i]), x);
        }
    }
}
