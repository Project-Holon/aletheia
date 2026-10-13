/*
 * function: func_021F6D70
 * address: 0x021F6D70
 * packet: pkt_ov097_021F6D70
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: 2026-10-05 (wD9r lane136): w8 is a narrow local (u8). mwcc does not schedule the reload of a
 *   spilled narrow local above the outgoing stack stores, so the block-3 x sum comes after them as in the
 *   image; a u32 w8 reload is hoisted (25 bytes in waves D3 to D9r). The centre shift is unsigned
 *   (lsrs), so the u8 width is widened to u32 before the shift; a plain u8 `w8 >> 1` gives asrs. An inline
 *   helper `center_x(u32 w)` gives the same EXACT bytes. Diagnostic that found it: the block-2 s16 local x
 *   used as the block-3 operand gave the image order, a u32/int x did not.
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201D304  0x0201D304  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

static inline u8 center_x(u32 w)
{
    return 0x5c - (w >> 1);
}

void func_021F6D70(char *p, int idx)
{
    void *buf;
    void *t1;
    void *t2;
    void *t3;
    u8 w8;
    u8 r7;
    u32 f1;
    u32 f2;
    s16 x;
    u32 f3;
    u32 h;

    buf = STRBUF_Create(0x20, 0x8071);
    t1 = func_02045EC0(*(void **)(p + 0x14), 0xc);
    w8 = func_0201D304(t1, *(u32 *)(p + 0x10), 0);
    r7 = center_x(w8);
    {
        u32 y;
        f1 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        PRINTSYS_PrintQueColor((void *)f1, y, (s16)r7, 0x20, (u32)t1, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    STRBUF_Delete(t1);

    t2 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, POKE_TOOL_GetPartyValue((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa0, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t2);
    {
        u32 y;
        h = *(u32 *)(p + 0x10);
        x = r7 - func_0201D304(buf, h, 0);
        f2 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        PRINTSYS_PrintQueColor((void *)f2, y, x, 0x20, (u32)buf, h, 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    STRBUF_Delete(t2);

    t3 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, POKE_TOOL_GetPartyValue((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa1, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t3);
    {
        u32 y;
        f3 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        PRINTSYS_PrintQueColor((void *)f3, y, (s16)(r7 + w8), 0x20, (u32)buf, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    STRBUF_Delete(t3);
    STRBUF_Delete(buf);
}
