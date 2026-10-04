/*
 * function: func_021F6B38
 * address:  0x021F6B38
 * packet:   pkt_ov097_021F6B38
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *);

void func_021F6B38(char *p)
{
    unsigned i;
    char *e;
    int q;

    func_0201C4E4((struct PrintSys *)(*(int *)(p + 0x1c)));
    for (i = 0; i < 6; i++) {
        q = *(int *)(p + 0x1c);
        e = p + i * 8;
        if (*(u8 *)(e + 0x24) != 0) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)*(int *)(e + 0x20)))) == 0) {
                func_02045334((struct Descriptor *)*(int *)(e + 0x20));
                *(u8 *)(e + 0x24) = 0;
            }
        }
    }
}
