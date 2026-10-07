/*
 * function: func_02175358
 * address:  0x02175358
 * packet:   pkt_ov012_02175358
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills a small view of entry i: the word at +0x148, the record address at
 * +0x18 (stride 0x2C) and the record byte at +0x40.  Called from ov012 0x0217532C.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    u8 b28;
    u8 pad29[3];
} Rec;

typedef struct {
    u8 pad0[0x18];
    Rec rec[6];
    u8 pad120[0x148 - 0x120];
    u32 word[6];
} Obj;

typedef struct {
    u32 word;
    Rec *rec;
    u8 pad8;
    u8 b9;
} View;

void func_02175358(Obj *p, View *out, int i)
{
    out->word = p->word[i];
    out->rec = &p->rec[i];
    out->b9 = p->rec[i].b28;
}
