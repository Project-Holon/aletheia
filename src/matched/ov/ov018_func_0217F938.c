/*
 * function: func_0217F938
 * address: 0x0217F938
 * packet: pkt_ov018_0217F938
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0217F95C 0x0217F95C thumb ov018
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, u8, u32);
extern int func_0217F95C(void *a0, int *state, void *a2);
void *func_0217F938(void *owner)
{
    void *task;
    task = func_020122C0(owner, 0, func_0217F95C, 0x30);
    func_02082BCC(func_020124E8(task), 0, 0x30);
    return task;
}
