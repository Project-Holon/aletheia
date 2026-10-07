/*
 * file:     trial_house_p11.c
 * unit:     yes
 * function: func_021CFBA8, func_021CFC14
 * address:  0x021CFBA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021587B0  0x021587B0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021CFB1C  0x021CFB1C  thumb  ov021
 */
struct U16Vec;
struct Strbuf;
struct WordSet;
struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Rec {
    u16 v[10];
} Rec;

extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dst, const u16 *src, u32 len);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_021CFB1C(void *a, void *b, void *c);
int func_021CFBA8(u32 a, u32 unused, const Rec *src);
void *func_021CFC14(void *a, void *unused, void *c);


/*
 * Copies a 20-byte record, opens the 0x0AFC resource, and passes the record's
 * first 8 bytes on to func_0201EE0C.
 *
 * Addresses are Black-image addresses.
 */
int func_021CFBA8(u32 a, u32 unused, const Rec *src)
{
    Rec r = *src;
    u32 h;
    u32 x;
    u32 buf;

    h = func_021587B0(a, 0x0AFC, 0, 0x15);
    func_02159058(h, r.v[8], 0, 0, 0);
    x = (u32)func_02158F74((void *)h);
    buf = (u32)func_020457B0(8, 0x15);
    func_02045994((struct Strbuf *)buf, (const u16 *)&r, 8);
    func_0201EE0C((struct WordSet *)x, 3, (const void *)buf, 1, 1, 2);
    func_02045808((struct U16Vec *)buf);
    return 0;
}


void *func_021CFC14(void *a, void *unused, void *c)
{
    void *task = func_020122C0(a, 0, func_021CFBA8, 0x14);
    void *work = func_020124E8(task);

    func_021CFB1C(func_0200BE48(func_02012EBC(func_020120F4(a))), c, work);
    return task;
}
