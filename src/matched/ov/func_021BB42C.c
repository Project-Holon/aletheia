/*
 * function: func_021BB42C
 * address:  0x021BB42C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B3B4  0x0204B3B4  arm
 *   sub_0204A8D4  0x0204A8D4  arm
 *   sub_0204ADA4  0x0204ADA4  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *
 * Guarded release of the four pointers at +0x180, each through its own arm9
 * helper.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

struct Obj;
extern void sub_0204B3B4(struct Obj *p);
extern void sub_0204A8D4(void *p);
extern void sub_0204ADA4(void *p);
extern void sub_0204AFD8(void *p);

typedef struct {
    char pad[0x180];
    void *f180;
    void *f184;
    void *f188;
    void *f18C;
} S;

void func_021BB42C(S *s)
{
    if (s->f180 != 0) {
        sub_0204B3B4(s->f180);
        sub_0204A8D4(s->f184);
        sub_0204ADA4(s->f188);
        sub_0204AFD8(s->f18C);
        s->f180 = 0;
    }
}
