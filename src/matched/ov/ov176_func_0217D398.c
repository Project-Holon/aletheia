/*
 * function: func_0217D398
 * address: 0x0217D398
 * packet: pkt_ov176_0217D398
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021E58A4 0x021E58A4 thumb ov177
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_0217D458 0x0217D458 thumb ov176
 *   d_0217E61C 0x0217E61C data a1
 */
typedef struct { int mode; int v[7]; } Config;
typedef struct { int a,b,c,d,callback; Config config; unsigned short heap; } Request;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_021E58A4(int unused, int mode, unsigned color);
extern int func_02045B38(int,int,int,int);
extern int func_0201EC74(int,int,int);
extern int func_021E8A3C(int,int,int);
extern void func_0217D458(int a, int unused, char *p);
extern const char d_0217E61C[];
Request *func_0217D398(Config *p, int heap)
{
    Request *r;
    r = func_02030734(heap, 0x38, 0, d_0217E61C, 0x9A);
    func_02082BCC(r, 0, 0x38);
    r->config = *p;
    r->heap = heap;
    func_021E58A4(r->config.v[4], 3, heap);
    r->a = func_02045B38(0, 2, 0xD2, heap);
    r->b = func_0201EC74(8, 0x40, heap);
    r->callback = func_021E8A3C((int)r, (int)func_0217D458, heap);
    return r;
}
