/*
 * function: func_021D9E50
 * address: 0x021D9E50
 * packet: pkt_ov121_021D9E50
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_020310C4 0x020310C4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef signed int     s32;
struct Blk;
struct Ctx;
struct PrintSys;
struct Tcbl;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
void func_021D9E50(u8 *p)
{
    u32 q;
    switch (*(u32 *)(p + 0x28)) {
    case 2:
        q = *(u32 *)(p + 0x24);
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1c)))) == 0) {
                func_02045334((struct Descriptor *)*(u32 *)(p + 0x1c));
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = *(u32 *)(p + 0x24);
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1c)))) == 0) {
                func_02045334((struct Descriptor *)*(u32 *)(p + 0x1c));
                p[0x20] = 0;
            }
        }
        *(u32 *)(p + 0x2c) = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (*(u32 *)(p + 8)) {
            if (*(u32 *)(p + 0x30))
                func_020286C4((struct Ctx *)(*(u32 *)(p + 0x30)), (void *)(*(u32 *)(p + 8)), (void *)(*(u32 *)(p + 0x10)));
            if (func_02028484((struct Blk *)(p + 0x34), (void *)(*(u32 *)(p + 8))))
                *(u32 *)(p + 0x2c) = 1;
        }
        break;
    case 3:
        break;
    }
    func_020310C4((struct Tcbl *)(*(u32 *)(p + 0xc)));
}
