/*
 * function: func_021C41C4
 * address:  0x021C41C4
 * packet:   pkt_ov111_021C41C4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
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

struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

void func_021C41C4(Work *p)
{
    int i;

    p->f31FC = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->f3200 = func_02045B38(0, 2, 0xBB, p->heap);
    p->f3208 = STRBUF_Create(4, p->heap);
    p->f3210 = STRBUF_Create(0x20, p->heap);
    p->f3214 = STRBUF_Create(0x21, p->heap);
    p->f320C = STRBUF_Create(5, p->heap);
    MSGDATA_ReadString(p->f3200, 0x17, p->f320C);
    for (i = 0; i < 3; i++) {
        p->f3218[i] = func_02045EC0(p->f3200, i + 0x1A);
    }
    for (i = 0; i < 2; i++) {
        p->f3224[i] = func_02045EC0(p->f3200, i + 0x1D);
    }
    for (i = 0; i < 26; i++) {
        p->f322C[i] = func_02045EC0(p->f3200, i);
    }
    for (i = 0; i < 5; i++) {
        p->f3294[i] = func_02045EC0(p->f3200, i + 0x38);
    }
    p->f3204 = GF_FONT_Create_EC64(p->heap);
}
