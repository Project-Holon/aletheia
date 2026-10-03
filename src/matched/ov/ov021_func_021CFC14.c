/*
 * function: func_021CFC14
 * address:  0x021CFC14
 * packet:   pkt_ov021_021CFC14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200BE48  0x0200BE48  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021CFB1C  0x021CFB1C  thumb  ov021
 *   func_021CFBA8  0x021CFBA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Rec;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_021CFB1C(void *a, void *b, void *c);
extern int func_021CFBA8(u32 a, u32 unused, const struct Rec *src);

void *func_021CFC14(void *a, void *unused, void *c)
{
    void *task = func_020122C0(a, 0, func_021CFBA8, 0x14);
    void *work = func_020124E8(task);

    func_021CFB1C(func_0200BE48(func_02012EBC(func_020120F4(a))), c, work);
    return task;
}
