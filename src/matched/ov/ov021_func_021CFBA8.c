/*
 * function: func_021CFBA8
 * address:  0x021CFBA8
 * packet:   pkt_ov021_021CFBA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 20-byte record, opens the 0x0AFC resource, and passes the record's
 * first 8 bytes on to func_0201EE0C.
 *
 * symbols:
 *   func_021587B0  0x021587B0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u16 v[10];
} Rec;

extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
struct U16Vec;
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *dst, const u16 *src, u32 len);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EE0C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

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
    func_0201EE0C(x, 3, buf, 1, 1, 2);
    func_02045808((struct U16Vec *)buf);
    return 0;
}
