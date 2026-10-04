/*
 * function: func_02184F40
 * address:  0x02184F40
 * packet:   pkt_ov020_02184F40
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012914  0x02012914  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_0218495C  0x0218495C  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
struct BigObj;
u16 func_02012914(const struct BigObj *p);
u16 func_02159F94(int a);
void func_02014204(void *p, int id);
int func_0218495C(int ctx, int *state, u8 *p);
void func_02184CEC(void *obj, void *p);

void *func_02184F40(void *p)
{
    void *r6 = (void *)func_02012914(func_020120F4(p));
    void *r0v = func_020122C0(p, 0, func_0218495C, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC(r4, p);
    func_02014204(r4 + 0x10, func_02159F94((int)r6));
    *(int *)(r4 + 0x10) = 1;
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}
