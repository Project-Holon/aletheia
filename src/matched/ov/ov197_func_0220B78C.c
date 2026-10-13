/*
 * function: func_0220B78C
 * address: 0x0220B78C
 * packet: pkt_ov197_0220B78C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);

void func_0220B78C(u8 *p, u32 idx)
{
    void *win = *(void **)(p + 0x120);
    void *msg = func_02045EC0(*(void **)(p + 0xc), 9);
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    void *w;
    func_0201EF40(*(void **)(p + 0x10), 0, *(u16 *)(row + 0x150 + idx * 4));
    func_0201F250(*(void **)(p + 0x10), *(void **)(p + 0x14), msg);
    BMP_Clear(func_02045770(win), 0);
    w = *(void **)(p + 0x18);
    PRINTSYS_PrintQueColor(w, (u32)func_02045770(*(void **)(p + 0x120)), 0, 0,
                  *(u32 *)(p + 0x14), *(u32 *)(*(u8 **)p + 4), 0x3C40);
    *(u8 *)(p + 0x124) = 1;
    STRBUF_Delete(msg);
}
