/*
 * function: func_021B9F34
 * address:  0x021B9F34
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Releases the two pointers at +0x14 and +0x18 through the same arm9 helper.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

typedef struct {
    char pad[0x14];
    void *f14;
    void *f18;
} S;

void func_021B9F34(S *s)
{
    CLACT_DeleteActor(s->f14);
    CLACT_DeleteActor(s->f18);
}
