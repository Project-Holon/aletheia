/*
 * function: func_021C42C0
 * address:  0x021C42C0
 * packet:   pkt_ov111_021C42C0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u8 pad2[0x31FC - 2];
    void *f31FC;
    void *f3200;
    void *f3204;
    void *f3208;
    void *f320C;
    void *f3210;
    void *f3214;
    void *f3218[3];
    void *f3224[2];
    void *f322C[26];
    void *f3294[5];
} Work;

struct Rec;
struct U16Vec;
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);

void func_021C42C0(Work *p)
{
    int i;

    func_0201ED04(p->f3204);
    for (i = 0; i < 5; i++) {
        STRBUF_Delete(p->f3294[i]);
    }
    for (i = 0; i < 26; i++) {
        STRBUF_Delete(p->f322C[i]);
    }
    STRBUF_Delete(p->f3224[1]);
    STRBUF_Delete(p->f3224[0]);
    STRBUF_Delete(p->f3218[2]);
    STRBUF_Delete(p->f3218[1]);
    STRBUF_Delete(p->f3218[0]);
    STRBUF_Delete(p->f320C);
    STRBUF_Delete(p->f3214);
    STRBUF_Delete(p->f3210);
    STRBUF_Delete(p->f3208);
    MSGDATA_Delete(p->f3200);
    GF_FONT_Delete(p->f31FC);
}
