/*
 * function: func_021E8A00
 * address:  0x021E8A00
 * packet:   pkt_ov177_021E8A00
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020200CC  0x020200CC  thumb
 */

typedef struct {
    char          pad0[4];
    int           f4;
    int           f8;
    unsigned char fc;
    char          pad1[3];
    int           f10;
    int           f14;
    int           f18;
} S;

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern s32 func_020200CC(struct Obj *o);

int func_021E8A00(S *p)
{
    int r4 = p->f4;
    int r;

    if (p->fc != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)p->f8))) == 0) {
            func_02045334((struct Descriptor *)p->f8);
            p->fc = 0;
        }
    }
    r = func_020200CC((struct Obj *)p->f10);
    if (r == -2) {
        r = p->f18;
    }
    return r;
}
