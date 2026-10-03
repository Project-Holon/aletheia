/*
 * function: func_0217FB5C
 * address: 0x0217FB5C
 * packet: pkt_ov018_0217FB5C
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
 *   func_0217FB94 0x0217FB94 thumb ov018
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int f0; int f4; int f8; u16 fC; } Req;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, u8, u32);
extern int func_0217FB94(int, int *, Req *);
void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f)
{
    Req *work;
    void *task;
    task = func_020122C0(owner, 0, func_0217FB94, 0x10);
    work = func_020124E8(task);
    func_02082BCC(work, 0, 0x10);
    work->f0 = b;
    work->f4 = d;
    work->f8 = e;
    work->fC = f;
    return task;
}
