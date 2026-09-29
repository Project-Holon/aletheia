/*
 * function: func_021F21B4
 * address:  0x021F21B4
 * packet:   pkt_ov029_021F21B4
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F1060  0x021F1060  thumb  ov029
 *   func_021F0300  0x021F0300  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 */

extern int func_021F1060(void *);
extern void func_021F0300(void *);
extern void func_021EFEF8(void *, void *, int);
extern void func_021F2180(void *);

void func_021F21B4(char *p)
{
    void (*f)(int);

    if (func_021F1060(p) == 0) {
        f = *(void (**)(int))(p + 0x1fc);
        if (f)
            f(*(int *)(p + 0x200));
        *(int *)(p + 0x1fc) = 0;
        *(int *)(p + 0x200) = 0;
        return;
    }
    func_021F0300(p);
    func_021EFEF8(p, (void *)func_021F2180, 0xF92);
}
