/*
 * function: func_021808C4
 * address: 0x021808C4
 * packet: pkt_ov018_021808C4
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201232C 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021808E8 0x021808E8 thumb ov018
 */
typedef unsigned int u32;
extern void func_0201232C(void *, void *, int);
extern void *func_020124E8(void *);
extern void func_02082D44(const void *, void *, u32);
extern int func_021808E8(void *, int *, void *);
void func_021808C4(void *task, const void *src)
{
    void *work;
    func_0201232C(task, func_021808E8, 0xA8);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}
