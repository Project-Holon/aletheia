/*
 * function: func_021FAC20
 * address: 0x021FAC20
 * packet: pkt_ov186_021FAC20
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: 02045874 takes the source and heap, forwarding r1 unchanged to its allocator.
 * evidence: matched arm9/sub_02045874.c; original 021FAC58 loads heap into r1,
 * then loads source into r0 at021FAC5A before storing heap and calling021FAC62.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045874 0x02045874 arm
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FB3BC 0x021FB3BC thumb ov186
 *   d_02200D18 0x02200D18 data a1
 */
typedef struct { unsigned short x,y,z; unsigned char flag,pad; } Config;
typedef struct {
    unsigned active, enabled, result, object;
    unsigned words[6];
    unsigned index, unused, owner;
    unsigned short heap, pad;
    unsigned a,b,work;
} Fields;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02045874(const void *, unsigned);
extern unsigned func_021FB7B0(unsigned, int);
extern void func_021FC124(void *, unsigned, void *);
extern unsigned func_021FC20C(char *p);
extern void *func_021FB3BC(void *, void *, int, int, int, int, int, void *, unsigned short);
extern char d_02200D18[];
void func_021FAC20(Fields *ctx, unsigned object, unsigned a, unsigned b, void *owner, const void *arg, unsigned index, unsigned short heap)
{
    unsigned info[3];
    Config config;
    const void *work;
    unsigned short heap_value;
    if (ctx->active) func_02034714(d_02200D18, 0, d_02200D18);
    func_02082BCC(ctx, 0, 0x44);
    ctx->active = 1;
    ctx->enabled = 1;
    ctx->object = object;
    ctx->index = index;
    ctx->owner = (unsigned)owner;
    heap_value = heap;
    work = arg;
    ctx->heap = heap_value;
    ctx->a = a;
    ctx->b = b;
    ctx->work = (unsigned)func_02045874(work, heap_value);
    func_02082BCC(&config, 0, 8);
    config.x = func_021FB7B0(ctx->object, 0);
    config.y = func_021FB7B0(ctx->object, 1);
    config.z = func_021FB7B0(ctx->object, 4);
    config.flag = 1;
    func_021FC124(owner, ctx->index + 1, info);
    ctx->result = (unsigned)func_021FB3BC(&config, (void *)ctx->work, 0xa0, ctx->enabled, a, b, func_021FC20C(owner), info, (unsigned short)((heap & 0x7fff) | 0x8000));
}
