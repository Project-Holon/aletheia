/*
 * function: func_0215EBD0
 * address: 0x0215EBD0
 * packet: pkt_ov010_0215EBD0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_0215EBF8 0x0215EBF8 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(void *);
extern void func_0215F0E8(void *, void *, void *);
extern int func_0215EBF8(void *, int *, void *);
void *func_0215EBD0(void *a, void *b)
{
    void *task;
    task = func_020122C0(*(void **)((u8 *)b + 8), 0, (void *)func_0215EBF8, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}
