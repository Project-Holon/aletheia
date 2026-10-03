/*
 * function: func_021F5260
 * address:  0x021F5260
 * packet:   pkt_ov082_021F5260
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: declaring w before obj gives w r4 and obj r5.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02189A60  0x02189A60  thumb  ov021
 *   func_021F58C0  0x021F58C0  thumb  ov082
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008374  0x02008374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021F5338  0x021F5338  thumb  ov082
 *   func_021F5748  0x021F5748  thumb  ov082
 *   func_021F57D8  0x021F57D8  thumb  ov082
 *   d_021F5920     0x021F5920  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern const char d_021F5920[];

typedef unsigned short u16;
struct Big;
struct Ctx;
struct Desc;
struct Sub02008700Obj;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 **func_02189A60(void *p);
extern void func_021F58C0(char *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_02008374(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_02188D30(void *a);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern int func_021F5338(void *task, int *st);
extern void func_021F5748(int a0, char *p);
extern void func_021F57D8(int a0, char *p);

void *func_021F5260(int a0, int a1, int a2, void *a3, int a4)
{
    u8 *w;
    void *obj;
    u32 mode;
    void *task;

    obj = func_0201210C(a3);
    w = func_02030734(0x50, 0x78, 1, d_021F5920, 0xa2);
    if (*func_02189A60(obj) != 0)
        return 0;
    *func_02189A60(obj) = w;
    *(int *)(w + 0xc) = a0;
    *(int *)(w + 0x10) = a4;
    *(int *)(w + 0x70) = a2;
    func_021F58C0((char *)(w + 0x28));
    func_021F58C0((char *)(w + 0x4c));
    mode = func_02008374(func_0200873C(func_02012EBC(func_020120F4(a3))));
    if (mode == 0)
        w[0x55] = 3;
    else if (mode == 1)
        w[0x55] = 2;
    else
        w[0x55] = 1;
    w[0x31] = 2;
    task = func_020122C0(a3, 0, (void *)func_021F5338, 0);
    *(void **)(w + 0x14) = func_02030DA8(func_02188D30(obj), (void *)func_021F5748, w, 0);
    *(void **)(w + 0x18) = func_020056A0((void *)func_021F57D8, w, 1);
    *(int *)(w + 0x1c) = 0;
    *(int *)(w + 0x74) = 1;
    return task;
}
