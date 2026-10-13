/*
 * function: MONOLITH_TOOL_TITLE_Init
 * address:  0x021B7C3C
 * packet:   pkt_ov071_021B7C3C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   MONOLITH_TOOL_TITLE_InitBackgrounds  0x021B7D6C  thumb  ov071
 *   MONOLITH_TOOL_TITLE_LoadGraphics  0x021B7DAC  thumb  ov071
 *   MONOLITH_TOOL_GetTitleSpecies  0x021B6F2C  thumb  ov071
 *   STRBUF_Create  0x020457B0  arm
 *   func_020084F4  0x020084F4  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MONOLITH_TOOL_CreateLabel  0x021B6E1C  thumb  ov071
 *   MONOLITH_TOOL_TITLE_CreateSlotIcons  0x021B7DE0  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 */

typedef struct {
    char pad[0x10];
    int f10;
} Inner;

typedef struct {
    int f0;
    Inner *f4;
} C;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Strbuf;
struct U16Vec;
typedef unsigned char  u8;
struct Sub0200852CObj;
struct WordSet;
struct Obj0203159C;
int MONOLITH_TOOL_TITLE_Init(struct Obj0203159C *a, int *b, C *c)
{
    extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void func_02082BCC(void *, int, int);
    extern void MONOLITH_TOOL_TITLE_InitBackgrounds(void);
    extern void MONOLITH_TOOL_TITLE_LoadGraphics(void *a, unsigned *b);
    extern void *MONOLITH_TOOL_GetTitleSpecies(u8 **p);
    extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
    extern const void *func_020084F4(const void *p);
    extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
    extern u8 func_02008550(const struct Sub0200852CObj *obj);
    extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
    extern void STRBUF_Delete(struct U16Vec *vec);
    extern void MONOLITH_TOOL_CreateLabel(Inner *, void *, int, int, int, int, int, int, int);
    extern void MONOLITH_TOOL_TITLE_CreateSlotIcons(void *, C *);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void func_020434DC(u32 mask, u32 enable);
    void *m;
    void *s;
    int h;

    switch (*b) {
    case 0:
        m = PROCSYS_AllocProcWork(a, 0x24, 0x61);
        func_02082BCC(m, 0, 0x24);
        MONOLITH_TOOL_TITLE_InitBackgrounds();
        MONOLITH_TOOL_TITLE_LoadGraphics(c, (unsigned int *)c->f4);
        h = (int)MONOLITH_TOOL_GetTitleSpecies((u8 **)c);
        s = STRBUF_Create(8, 0x61);
        STRBUF_SetStringN(s, func_020084F4((const void *)h), 8);
        func_0201EE0C((struct WordSet *)c->f4->f10, 0, s, func_02008550((const struct Sub0200852CObj *)h), 1, 2);
        STRBUF_Delete(s);
        MONOLITH_TOOL_CreateLabel(c->f4, m, 0, 0x80, 0xc, 0x1e, 2, 0, c->f4->f10);
        MONOLITH_TOOL_TITLE_CreateSlotIcons(m, c);
        *b = *b + 1;
        break;
    case 1:
        func_02040588(2, 1);
        func_020434DC(0x10, 1);
        return 1;
    }
    return 0;
}
