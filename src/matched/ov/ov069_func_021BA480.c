/*
 * function: func_021BA480
 * address:  0x021BA480
 * packet:   pkt_ov069_021BA480
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_021BA470  0x021BA470  thumb  ov069
 *   func_02045994  0x02045994  arm
 *   func_021BA520  0x021BA520  thumb  ov069
 *   func_0202CC70  0x0202CC70  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    unsigned char pad[0x20];
    u8 f0 : 1;
    u8 f1 : 1;
} Ent;

typedef struct Obj {
    unsigned char pad000[4];
    struct WinMgr *f4;
    char *f8;
    unsigned char pad00C[0x160 - 0xC];
    u16 page;
    u16 f162;
    int f164;
} Obj;

typedef unsigned int u32;
struct WinMgr;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021BA470(int a, int b, int c);
struct Strbuf;
extern void func_02045994(struct Strbuf *dst, const u16 *src, u32 n);
extern void func_021BA520(u8 *a0, int a1, void *a2, int a3);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_02045808(struct U16Vec *vec);

void func_021BA480(Obj *o)
{
    void *buf;
    int n;
    int i;

    buf = func_020457B0(0x10, 0x80);
    n = func_021BA470(o->page, o->f162, o->f164);
    i = 0;
    if (n > 0) {
        do {
            func_02045994(buf, (const u16 *)(o->f8 + (i + o->page * 10) * 0x22), 8);
            func_021BA520((u8 *)o, i, buf, ((Ent *)(o->f8 + (i + o->page * 10) * 0x22))->f1);
            i++;
        } while (i < n);
    }
    for (; i < 10; i++)
        func_0202CC70(o->f4, i);
    func_02045808(buf);
}
