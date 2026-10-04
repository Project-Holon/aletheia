/*
 * function: func_021B6348
 * address: 0x021B6348
 * packet: pkt_ov173_021B6348
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two zero alignment bytes at 021B638E.
 * symbols:
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_021B7EB0(u8 *, int);
struct PrintSys;
struct TaskMenuState;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
void func_021B6348(u8 *p)
{
    func_021B7EB0(p, 0);
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0x1e4)));
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0x1f0)));
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0x1fc)));
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0x208)));
    func_02027FD8((struct TaskMenuState *)(*(u32 *)(p + 0x1dc)));
    func_0201C4C0((struct PrintSys *)(*(u32 *)(p + 0x218)));
}
