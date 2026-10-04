/*
 * function: func_0204A9D0
 * address:  0x0204A9D0
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   lbl_02146A74    0x02146A74  data
 *   func_020637BC   0x020637BC  arm
 *   func_020637B4   0x020637B4  arm
 *   func_020862F0   0x020862F0  arm
 *   func_0207E780   0x0207E780  arm
 *   func_0207E804   0x0207E804  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj02146A74 {
    u8 pad[0x10c];
    u32 f10C;
};

struct Sub0204A9D0 {
    u8 pad[0x10];
    u32 f10;
    u32 f14;
};

extern struct Obj02146A74 *lbl_02146A74;
extern int func_020637BC(const u32 *p, u32 i);
extern int func_020637B4(int *p, int i);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E780(void *a, void *b, u32 c);
extern void func_0207E804(void *a, void *b, u32 c);

void func_0204A9D0(int a, struct Sub0204A9D0 *b)
{
    if (func_020637BC((const u32 *)(lbl_02146A74->f10C + (a << 6)), 1) != 0) {
        void *p = (void *)func_020637B4((int *)(lbl_02146A74->f10C + (a << 6)), 1);
        func_020862F0((void *)b->f14, b->f10);
        func_0207E780((void *)b->f14, p, b->f10);
    }
    if (func_020637BC((const u32 *)(lbl_02146A74->f10C + (a << 6)), 2) == 0)
        return;
    {
        void *p = (void *)func_020637B4((int *)(lbl_02146A74->f10C + (a << 6)), 2);
        func_020862F0((void *)b->f14, b->f10);
        func_0207E804((void *)b->f14, p, b->f10);
    }
}
