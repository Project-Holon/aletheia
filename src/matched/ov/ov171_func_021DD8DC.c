/*
 * function: func_021DD8DC
 * address: 0x021DD8DC
 * packet: pkt_ov171_021DD8DC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: offset locals carry both their initial and replacement constants.
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
void func_021DD8DC(char *p)
{
    int a, b, c, d;
    unsigned i;
    int obj;
    char *q;
    func_0201C4E4((struct PrintSys *)(*(int *)(p + 0xb6c)));
    a = 0xb6c;
    a = 0xb48;
    b = 0xb6c;
    b = 0xb4c;
    c = 0xb6c;
    c = 0xb48;
    d = 0xb6c;
    d = 0xb4c;
    for (i = 0; i < 2; ++i) {
        obj = *(int *)(p + 0xb6c);
        q = p + i * 8;
        if (*(unsigned char *)(q + d)) {
            if (!func_0201C6C4((struct PrintSys *)obj, (void *)((int)func_02045770((struct Descriptor *)*(int *)(q + c))))) {
                func_02045334((struct Descriptor *)*(int *)(q + a));
                *(unsigned char *)(q + b) = 0;
            }
        }
    }
}
