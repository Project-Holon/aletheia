/*
 * function: func_021FCA8C
 * address:  0x021FCA8C
 * packet:   pkt_021FCA8C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

struct MsgBank;
struct Strbuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void STRBUF_Delete(struct U16Vec *vec);

void func_021FCA8C(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g)
{
    void *s0;
    void *s1;
    void *t0;
    void *t1;

    s0 = STRBUF_Create(0x22, 0x48);
    s1 = STRBUF_Create(0x22, 0x48);
    t0 = func_02045EC0(bank, 0x37);
    STRBUF_SetString(s0, name);
    t1 = func_02045EC0(bank, 0xC2);
    POKE_TOOL_GetPartyValue(mon, 0x8D, (u32)s1);
    func_021F91A0(pane->win0, t0, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane->win1, s0, 0, 0, 0, 0x440, g);
    func_021F91A0(pane2->win0, t1, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane2->win1, s1, 1, 0, 0, 0x440, g);
    STRBUF_Delete(t0);
    STRBUF_Delete(s0);
    STRBUF_Delete(t1);
    STRBUF_Delete(s1);
}
