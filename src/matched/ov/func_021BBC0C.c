/*
 * function: func_021BBC0C
 * address:  0x021BBC0C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *
 * Three-step release of the pointer at +0x1A0; the field is re-read for each
 * step, which is why the listing reloads it between the calls.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

typedef struct {
    char pad[0x1A0];
    void *f1A0;
} S;

void func_021BBC0C(S *s)
{
    if (s->f1A0 != 0) {
        BMP_WIN_ClearScreen(s->f1A0);
        func_0201F7A8(s->f1A0, 1);
        BMP_WIN_Delete(s->f1A0);
        s->f1A0 = 0;
    }
}
