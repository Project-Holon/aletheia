/*
 * function: POKELIST_PrintTextMain
 * address:  0x021B9C1C
 * packet:   pkt_ov091_021B9C1C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);

#define W(o) (*(int *)(p + (o)))

void POKELIST_PrintTextMain(u8 *p, u32 win, u32 id, int x, s16 y, u16 color)
{
    void *text;

    text = func_02045EC0((void *)W(0x134), id);
    PRINTSYS_PrintQueColor((void *)W(0x140), (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, (u32)text, W(0x138), color);
    STRBUF_Delete(text);
}
