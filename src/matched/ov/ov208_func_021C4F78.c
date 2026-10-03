/*
 * function: ov208_func_021C4F78
 * address:  0x021C4F78
 * packet:   pkt_ov208_021C4F78
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  func_02014CEC witness (src/matched/arm9/func_02014CEC.c) has no shard yet; EXACT once the integrator builds it (2026-10-02)
 *
 * The last call takes the 3D heap handle as its second argument (r1 still
 * holds it), which is why the image copies the result to r1 before the store.
 *
 * symbols:
 *   func_02014B08  0x02014B08  thumb
 *   func_02016020  0x02016020  thumb
 *   func_02015BF0  0x02015BF0  thumb
 *   func_0202D060  0x0202D060  thumb
 *   func_02014CB8  0x02014CB8  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02014CEC  0x02014CEC  thumb
 *   func_02030734  0x02030734  arm
 *   data_021C8E64  0x021C8E64  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 f4;
    u32 cam;
    u8  padc[0x110];
    void *mem;
    void *heap3d;
};

extern u32  func_02014B08(int kind, u16 heap);
extern void func_02016020(u32 cam, u32 v);
extern void func_02015BF0(u32 cam);
struct Ctx;
extern int func_0202D060(void);
extern void func_02014CB8(u32 cam, u32 v);
extern u32  func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02014CEC(u32 cam, void *v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char data_021C8E64[];

void ov208_func_021C4F78(u16 *heap, struct Ov208Menu *p)
{
    p->cam = func_02014B08(4, *heap);
    func_02016020(p->cam, 0);
    func_02015BF0(p->cam);
    func_02014CB8(p->cam, func_0202D060());
    p->mem = func_02030734(*heap, func_02030CB0(4), 0, data_021C8E64, 0xa53);
    p->heap3d = func_02030CBC(4, p->mem);
    func_02014CEC(p->cam, p->heap3d);
}
