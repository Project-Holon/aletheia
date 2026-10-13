/*
 * function: COMM_ENTRY_MENU_PrintMemberName
 * address:  0x021CE934
 * packet:   pkt_ov021_021CE934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18, f1c, f20;
} S;

struct Sub0200852CObj;
struct WordSet;
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);

void COMM_ENTRY_MENU_PrintMemberName(S *p, u32 b, u32 c)
{
    u32 n;

    if (p->fc != 0) {
        func_0201F02C((struct WordSet *)p->f4, 0, (void *)b);
        n = func_02008534((const struct Sub0200852CObj *)b);
        func_0201EFA4((struct WordSet *)p->f4, 1, n, 5, 2, 1);
        func_0201F250((struct WordSet *)p->f4, (void *)p->f20, (void *)p->f1c);
        FIELD_MSGBG_MsgWinPrintStr(p->fc, 0, (c & 0xfff) << 4, p->f20);
    }
}
