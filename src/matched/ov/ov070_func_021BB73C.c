/*
 * function: func_021BB73C
 * address:  0x021BB73C
 * packet:   pkt_ov070_021BB73C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Eleven dirty-window cleanup blocks. Code/pool ends at 0x021BB95C;
 * remaining handed extent is tables/strings, not an unlabelled follower.
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *);
extern int func_0201C6C4(void *, unsigned);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);

static inline void clean(u8 *p, int off)
{
    void *t = *(void **)(p + 0x50C);
    if (p[off] != 0) {
        if (func_0201C6C4(t, (u32)func_02045770((struct Descriptor *)*(u32 *)(p + off - 4))) == 0) {
            func_02045334((struct Descriptor *)*(u32 *)(p + off - 4));
            p[off] = 0;
        }
    }
}

void func_021BB73C(u8 *p)
{
    func_0201C4E4(*(struct PrintSys **)(p + 0x50C));
    clean(p, 0x738);
    clean(p, 0x740);
    clean(p, 0x748);
    clean(p, 0x750);
    clean(p, 0x758);
    clean(p, 0x760);
    clean(p, 0x768);
    clean(p, 0x770);
    clean(p, 0x778);
    clean(p, 0x500);
    clean(p, 0x508);
}
