/*
 * function: FIELD_G3D_MAP_CreateIntrudeRequestEvent
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
 *   FIELD_G3D_MAP_IntrudeRequestEventMain 0x0216B280 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int value; u8 flag; u8 padding[3]; } Work;
struct Ctx;
struct Desc;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern int FIELD_G3D_MAP_IntrudeRequestEventMain(int, int *, u8 **);
int FIELD_G3D_MAP_CreateIntrudeRequestEvent(void *vm, int value, int flag)
{
    int task;
    Work *p;
    func_020120F4((const struct Ctx *)vm);
    task = (int)func_020122C0((void *)vm, 0, FIELD_G3D_MAP_IntrudeRequestEventMain, 8);
    p = func_020124E8((struct Obj *)task);
    func_02082BCC(p, 0, 8);
    p->value = value;
    p->flag = flag;
    return task;
}
