/*
 * function: func_0216BCE4
 * address: 0x0216BCE4
 * packet: pkt_ov010_0216BCE4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_021F3B68 0x021F3B68 thumb ov059
 *   func_0215897C 0x0215897C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02159B10(void *, void *);
extern void *func_021F3B68(void *, u32);
extern void func_0215897C(void *, void *);
int func_0216BCE4(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = func_0215A5F4(vm);
    p = func_0215A5DC(vm);
    task = func_021F3B68(p, func_02159B10(ctx, vm));
    if (task == 0) return 1;
    func_0215897C(ws, task);
    return 1;
}
