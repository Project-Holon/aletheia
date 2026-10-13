/*
 * function: FIELD_MSGBG_PrintLines
 * address:  0x021924F0
 * packet:   pkt_ov021_021924F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_FONT_GetLineHeight  0x0201DC80  thumb
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Font;
struct StrObj;
struct U16Vec;
extern u32 GF_FONT_GetLineHeight(struct Font *p);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);

void FIELD_MSGBG_PrintLines(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f)
{
    int i;
    u32 h;
    int t;

    t = GF_FONT_GetLineHeight((struct Font *)d) + 2;
    h = (u32)STRBUF_Create(STRBUF_GetLength((struct U16Vec *)e) + 1, f);
    for (i = 0; func_0201D37C((struct StrObj *)e, (struct StrObj *)h, i) == 1; i++) {
        PRINTSYS_Print((void *)c, (s16)a, (s16)b, (void *)h, (void *)d);
        b += (u16)t;
    }
    STRBUF_Delete((struct U16Vec *)h);
}
