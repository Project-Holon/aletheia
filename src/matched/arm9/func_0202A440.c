/*
 * unit:     no
 * function: func_0202A440
 * address:  0x0202A440
 * packet:   pkt_0202A440
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The __FILE__ argument at 0x020A76DC is the tr_tool.c anchor recorded in
 * layout/file_anchors.txt for this range; it is pinned by address, not
 * spelled as a literal __FILE__
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 *
 * symbols:
 *   g_020A76DC     0x020A76DC  data
 *   func_02030734  0x02030734  arm
 *   func_0202A3AC  0x0202A3AC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02082A60  0x02082A60  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Tmp {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    u8   f04[8];
    u32  f0c;
    u32  f10;
};

struct Out {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c[2];
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
};

extern char  g_020A76DC[];

typedef unsigned short u16;
struct MsgBank;
struct Rec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0202A3AC(void *a0, void *a1);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void  func_02082A60(const void *src, void *dest, u32 size);
extern void  PMSI_PARAM_ClearSentence(void *p);
extern u32 func_020307B0(void *p);

void func_0202A440(u32 id, struct Out *out, u32 heap)
{
    struct Tmp *t;
    void *bank;

    t = func_02030734(heap, 0x14, 0, g_020A76DC, 0x159);
    func_0202A3AC((void *)id, t);

    out->f00 = id;
    out->f04 = t->f01;
    out->f08 = t->f0c;

    bank = func_02045B38(0, 2, 0xbe, heap);
    func_02045CAC(bank, id, (void *)out->f14);
    func_02045C04(bank);

    func_02082A60(t->f04, &out->f0c, 8);
    PMSI_PARAM_ClearSentence(&out->f18);
    PMSI_PARAM_ClearSentence(&out->f20);

    func_020307B0(t);
}
