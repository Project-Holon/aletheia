/*
 * function: func_021B9F84
 * address:  0x021B9F84
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204B3DC  0x0204B3DC  arm
 *
 * Tail call onto the arm9 routine on the pointer at +0x28 with a zero selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x28];
    void *f28;
} S;

struct Obj;
extern void sub_0204B3DC(struct Obj *p, unsigned int v);

void func_021B9F84(S *s)
{
    sub_0204B3DC(s->f28, 0);
}
