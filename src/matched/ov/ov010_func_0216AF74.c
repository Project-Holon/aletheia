/*
 * function: func_0216AF74
 * address:  0x0216AF74
 * packet:   pkt_ov010_0216AF74
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_020173EC  0x020173EC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_021AA304  0x021AA304  thumb
 *   func_0216B004  0x0216B004  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Desc;
struct Big;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 *func_020124E8(struct Desc *p);
extern void func_02082BCC();
extern u32 func_020173EC(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02012EBC(struct Big *p);
extern int func_0200E2BC();
extern void func_021AA304();
extern int func_0216B004();

struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)func_0216B004, 0x3C);
    p = func_020124E8(r);
    func_02082BCC(p, 0, 0x3C);
    *(int *)p = a1;
    *(u16 **)(p + 0x28) = a4;
    *(u16 *)(p + 0x24) = a5;
    *(int *)(p + 0xC) = a2;
    *(int *)(p + 0x20) = a3;
    *(u16 *)(p + 0x2C) = func_0203F1FC((const u8 *)a2, func_020173EC());
    if (func_0200E2BC(func_02012EBC(h), &a3, a5, 0) == 0)
        *(u32 *)(p + 0x20) = (*(u32 *)(p + 0x20) & 0xFFFFF800) | 0x28B;
    func_021AA304(p + 0x10, h, a1);
    return r;
}
