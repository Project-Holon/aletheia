/*
 * function: func_02168E5C
 * address:  0x02168E5C
 * packet:   pkt_ov010_02168E5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02168EB0  0x02168EB0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub0200852CObj;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E8F8(void *sys);
extern void func_02168EB0(void);

int func_02168E5C(int a, int b, int c)
{
    int x = (int)func_020120F4((const struct Ctx *)a);
    int h = (int)func_020122C0((void *)a, 0, func_02168EB0, 0x18);
    int *p = func_020124E8((struct Obj *)h);
    p[0] = a;
    p[1] = (int)func_0201210C((void *)a); /* int-typed on purpose: field is int in record */
    *(u8 *)(p + 2) = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)x));
    p[3] = (int)func_0200E8F8(func_02012EBC((struct Big *)x));
    p[4] = b;
    p[5] = c;
    return h;
}
