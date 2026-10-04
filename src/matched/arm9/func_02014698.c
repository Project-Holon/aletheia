/*
 * function: func_02014698
 * address:  0x02014698
 * packet:   pkt_02014698
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step function func_02014728 installs (argsize 0x14, args p[0]..p[4]),
 * one stage per call on *mode.  Closed in wave 13: the earlier goto/label
 * spelling (docs/notes/func_02014698.c.txt, one byte out) was the wrong
 * shape.  Written plainly -- every arm carries its own `(*mode)++; break;`
 * and case 2 is `if (poll() == 0) (*mode)++;` -- the compiler cross-jumps
 * the repeated increments itself, and that leaves case 2's tail jump on
 * case 1's `b inc` block exactly as the image has it.
 *
 * symbols:
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020145CC  0x020145CC  thumb
 */

typedef unsigned int u32;

struct Ctx;
struct IcaAnime;
extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_020145CC(void *a0);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_02014698(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];

    switch (*mode) {
    case 0:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, args[1]));
        (*mode)++;
        break;
    case 1:
        func_020120B4((struct IcaAnime *)a0, args[2], (void *)args[3], (void *)args[4]);
        (*mode)++;
        break;
    case 2:
        if (func_020120F0((const struct Ctx *)a0) == 0) {
            (*mode)++;
        }
        break;
    case 3:
        func_02012374(obj, func_020145CC((void *)a0));
        (*mode)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
