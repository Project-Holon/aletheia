/*
 * function: func_0217F67C
 * address: 0x0217F67C
 * packet: pkt_ov018_0217F67C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0217F6A0 0x0217F6A0 thumb ov018
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020122C0(void *, void *, void *, u32);
extern u8 *func_020124E8(void *);
extern int func_0217F6A0(int, int *, void *);
void *func_0217F67C(void *owner, u16 *out)
{
    void *task;
    u8 *work;
    int zero;
    zero = 0;
    task = func_020122C0(owner, 0, func_0217F6A0, 0x10);
    work = func_020124E8(task);
    *(u16 **)(work + 0xC) = out;
    *out = zero;
    return task;
}
