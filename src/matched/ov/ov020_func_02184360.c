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
extern void *func_020122C0(void *owner, void *a, void *b, unsigned int n);
extern void *func_020124E8(void *p);
extern void func_021841C0(void);
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
