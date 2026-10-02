/*
 * function: func_02180B14
 * address: 0x02180B14
 * packet: pkt_ov018_02180B14
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
 *   func_02180B38 0x02180B38 thumb ov018
 */
typedef unsigned int u32;
extern void func_0201232C(void *, void *, int);
extern void *func_020124E8(void *);
extern void func_02082D44(const void *, void *, u32);
extern int func_02180B38(void *, int *, void *);
void func_02180B14(void *task, const void *src)
{
    void *work;
    func_0201232C(task, func_02180B38, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}
