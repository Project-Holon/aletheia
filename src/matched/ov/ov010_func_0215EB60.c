/*
 * function: func_0215EB60
 * address: 0x0215EB60
 * packet: pkt_ov010_0215EB60
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0215EB88 0x0215EB88 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Desc;
struct Obj;
struct Pair;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern int func_0215EB88(void *, int *, void *);
void *func_0215EB60(void *a, void *b)
{
    void *task;
    task = func_020122C0(*(void **)((u8 *)b + 8), 0, (void *)func_0215EB88, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}
