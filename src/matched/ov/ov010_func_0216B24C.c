/*
 * function: func_0216B24C
 * address: 0x0216B24C
 * packet: pkt_ov010_0216B24C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0216B280 0x0216B280 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int value; u8 flag; u8 padding[3]; } Work;
extern void func_020120F4(int);
extern int func_020122C0(int, int, int (*)(int, int *, u8 **), int);
extern Work *func_020124E8(int);
extern void func_02082BCC(void *, int, int);
extern int func_0216B280(int, int *, u8 **);
int func_0216B24C(int vm, int value, int flag)
{
    int task;
    Work *p;
    func_020120F4(vm);
    task = func_020122C0(vm, 0, func_0216B280, 8);
    p = func_020124E8(task);
    func_02082BCC(p, 0, 8);
    p->value = value;
    p->flag = flag;
    return task;
}
