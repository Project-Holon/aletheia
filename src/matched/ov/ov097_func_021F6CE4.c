/*
 * function: func_021F6CE4
 * address: 0x021F6CE4
 * packet: pkt_ov097_021F6CE4
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: six Window records initialized by matched 021F6A98; direct per-field Owner.window[b] accesses retain index scaling and recompute the dirty-byte address.
 * checks: 1 every callee copied from its own matched definition; 2 021F6A98 initializes six 8-byte records and gives the fixed bound; 3 enum zero gave84, readonly header38; 4 struct-array-per-field idiom closes38 to EXACT; 5 fresh idiom directory and matched neighbours read.
 * permuter: historical once-only types300 consumed; no repeat in wave77.
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef enum { ZERO } Zero;
typedef enum { INDEX_ZERO } Index;
struct U16Vec;
struct MsgBank;
struct Descriptor;
struct WordSet;
typedef struct { struct Descriptor *text; unsigned char dirty; unsigned char pad05[3]; } Window;
typedef struct {
    unsigned char pad00[0x10];
    u32 ink;
    struct MsgBank *catalogue;
    struct WordSet *formatter;
    void *renderer;
    Window window[6];
} Owner;
extern struct U16Vec *STRBUF_Create(u32, u32);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void *func_02045770(struct Descriptor *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_0201F250(struct WordSet *, void *, void *);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);

static inline void print_window(Owner *a, Index b, void *t)
{
    void *owner = a->renderer;
    PRINTSYS_PrintQueColor(owner,
                  (u32)func_02045770(a->window[(u32)b].text), 8, 0x20, (u32)t,
                  a->ink, 0x3dc0);
    a->window[(u32)b].dirty = 1;
}
void func_021F6CE4(Owner *a, Index b)
{
    struct U16Vec *t;
    void *u;
    unsigned char z = ZERO;

    t = STRBUF_Create(0x20, 0x8071);
    u = func_02045EC0(a->catalogue, 0xb);
    func_0201EFA4(a->formatter, 0,
                  POKE_TOOL_GetPartyValue(*(void **)((u32)a + (u32)b * 4 + 0xf8), 0x9e, 0), 3, z, 1);
    func_0201F250(a->formatter, t, u);
    print_window(a, b, t);
    STRBUF_Delete(u);
    STRBUF_Delete(t);
}
