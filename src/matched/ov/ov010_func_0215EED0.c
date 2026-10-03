/*
 * function: func_0215EED0
 * address: 0x0215EED0
 * packet: pkt_ov010_0215EED0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0215EEF8 0x0215EEF8 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct C;
struct Desc;
struct Obj;
struct Pair;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern int func_0215EEF8(void *p, void *unused, struct C *ctx);
void *func_0215EED0(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(*(void **)((u8 *)ctx + 8), 0, (void *)func_0215EEF8, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}
