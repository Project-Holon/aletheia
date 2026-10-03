/*
 * function: func_021C4BA4
 * address: 0x021C4BA4
 * packet: pkt_ov127_021C4BA4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021C4C86 follow the function.
 * lever: Pos declaration order src,a,dst,b fixes stack slots; named qid fixes cmp order.
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4AD0 0x021C4AD0 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4914 0x021C4914 thumb ov127
 *   func_021C499C 0x021C499C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short a, b; } Pos;
extern Pos func_021C4AC4(void *);
extern Pos func_021C4AD0(void *);
extern Pos func_021C4A54(Pos, int);
extern int func_021C49A4(u8 *, u32);
extern u32 func_021C4914(u8 *p);
extern u8 *func_021C499C(void *, u16);
u8 *func_021C4BA4(u8 *p, void *list, int n)
{
    Pos src, a, dst, b;
    u32 count;
    int id;
    u32 i;
    u8 *q;
    int qid;
    src = func_021C4AC4(p);
    dst = func_021C4A54(src, n);
    id = func_021C49A4(p, 4);
    count = func_021C4914(list);
    for (i = 0; i < count; i++) {
        q = func_021C499C(list, i);
        if (q != 0) {
            qid = func_021C49A4(q, 4);
            if (qid == id) continue;
            a = func_021C4AC4(q);
            if (a.a == dst.a && a.b == dst.b) return q;
            b = func_021C4AD0(q);
            if (b.a == dst.a && b.b == dst.b) return q;
        }
    }
    return 0;
}
