/*
 * function: func_02184360
 * address: 0x02184360
 * packet: pkt_ov020_02184360
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021841C0 0x021841C0 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021841C0(int ctx, int *state, u8 **pp);
void *func_02184360(u8 *p, int value)
{
    void *task;
    void **w;
    task = func_020122C0(*(void **)p, 0, (void *)func_021841C0, 4);
    w = func_020124E8(task);
    *w = p;
    p[0x30] = value;
    return task;
}
