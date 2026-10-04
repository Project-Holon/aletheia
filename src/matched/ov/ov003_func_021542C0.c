/*
 * function: func_021542C0
 * address:  0x021542C0
 * packet:   pkt_ov003_021542C0
 * region:   ov003
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine installed by func_0215437C (allocator + link setup); the step
 * callback runs on *mode.  Same shape as arm9 func_02014698.  This address is
 * also labelled by ov000/ov001/ov002/ov006, hence the overlay-qualified name.
 *
 * The 3rd argument to func_020120B4 is the book-keeping table pointer
 * 0x0209DEFC, an interior entry of the seven-pointer table at 0x0209DEF0.
 * Its only pool word image-wide is the one inside this function, so it has no
 * `literal` witness, and `sole-ref/self` cannot read it: the site lives in an
 * overlapping overlay window and `rom_word_at` selects ov000's bytes there,
 * not ov003's.  It is therefore written as an opaque (void *) literal, which
 * reproduces the original pool word byte for byte with no relocation.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 */

typedef unsigned int u32;

struct Ctx;
extern u32   func_02012138(const struct Ctx *a0);
extern int   func_02026454(int x);
typedef unsigned short u16;
struct Evt;
extern u16 func_02005C44(void);
extern void func_02005E30(u32 a);
extern void *func_020144DC(u32 a0, u32 a1);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32   func_020120F4(u32 a0);
extern void  func_020120B4(u32 a0, u32 a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern void  func_02005D90(u32 a0, u32 a1);
extern void func_02005DF8(u32 a);
extern void *func_020145CC(u32 a0);

u32 func_021542C0(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];

    switch (*mode) {
    case 0:
        if (func_02026454(func_02012138((const struct Ctx *)a0)) == 0) {
            args[0] = func_02005C44();
            func_02005E30(6);
            (*mode)++;
        }
        break;
    case 1:
        func_02012374(obj, func_020144DC(a0, args[2]));
        *mode = 2;
        break;
    case 2:
        args[3] = func_020120F4(a0);
        args[4] = args[5];
        func_020120B4(a0, (u32)-1, (void *)0x0209DEFC, &args[3]);
        (*mode)++;
        break;
    case 3:
        if (func_020120F0(a0) == 0)
            (*mode)++;
        break;
    case 4:
        (*mode)++;
        break;
    case 5:
        func_02005D90(args[0], 0xFFFF);
        func_02005DF8(0x3C);
        func_02012374(obj, func_020145CC(a0));
        (*mode)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
