/*
 * function: BR_BTN_InitRecord
 * address: 0x021FAC20
 * packet: pkt_ov186_021FAC20
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: 02045874 takes the source and heap, forwarding r1 unchanged to its allocator.
 * evidence: matched arm9/STRBUF_Clone.c; original 021FAC58 loads heap into r1,
 * then loads source into r0 at021FAC5A before storing heap and calling021FAC62.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Clone 0x02045874 arm
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_BTN_CreateObject 0x021FB3BC thumb ov186
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
extern void MI_CpuFill8(void *, int, unsigned);
struct U16Vec;
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern int BR_BTN_DATA_GetRowField(void *p, int i);
extern void BR_RES_GetSprite(void *, unsigned, void *);
extern unsigned BR_RES_GetFont(char *p);
extern void *BR_BTN_CreateObject(void *, void *, int, int, int, int, int, void *, unsigned short);
extern char d_02200D18[];
void BR_BTN_InitRecord(Fields *ctx, unsigned object, unsigned a, unsigned b, void *owner, const void *arg, unsigned index, unsigned short heap)
{
    unsigned info[3];
    Config config;
    const void *work;
    unsigned short heap_value;
    if (ctx->active) func_02034714(d_02200D18, 0, d_02200D18);
    MI_CpuFill8(ctx, 0, 0x44);
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
    ctx->work = (unsigned)STRBUF_Clone((struct U16Vec *)work, heap_value);
    MI_CpuFill8(&config, 0, 8);
    config.x = BR_BTN_DATA_GetRowField((void *)ctx->object, 0);
    config.y = BR_BTN_DATA_GetRowField((void *)ctx->object, 1);
    config.z = BR_BTN_DATA_GetRowField((void *)ctx->object, 4);
    config.flag = 1;
    BR_RES_GetSprite(owner, ctx->index + 1, info);
    ctx->result = (unsigned)BR_BTN_CreateObject(&config, (void *)ctx->work, 0xa0, ctx->enabled, a, b, BR_RES_GetFont(owner), info, (unsigned short)((heap & 0x7fff) | 0x8000));
}
