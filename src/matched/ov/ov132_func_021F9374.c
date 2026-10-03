/*
 * function: func_021F9374
 * address: 0x021F9374
 * packet: pkt_ov132_021F9374
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
struct Rec3;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern unsigned func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
void func_021F9374(u8 *p)
{
    func_020310C4(*(void **)(p + 0xcc));
    if (*(void **)(p + 0xd8) && func_0201CE30(*(void **)(p + 0xd8)) == 2) {
        func_0201CE48(*(void **)(p + 0xd8));
        *(void **)(p + 0xd8) = 0;
    }
    if (*(int *)(p + 0xe4) == 1) {
        func_0201C4E4(*(void **)(p + 0xe8));
        if (func_0201C6B4(*(void **)(p + 0xe8)) == 1) {
            func_02045334(*(void **)(p + 0xd0));
            *(int *)(p + 0xe4) = 0;
        }
    }
}
