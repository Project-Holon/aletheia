/*
 * function: WF2DMAP_OBJ_FindAtPos
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
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_GetDestPos 0x021C4AD0 thumb ov127
 *   WF2DMAP_OBJ_OffsetPos 0x021C4A54 thumb ov127
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJ_GetCount 0x021C4914 thumb ov127
 *   WF2DMAP_OBJ_GetByIndex2 0x021C499C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short a, b; } Pos;
extern Pos WF2DMAP_OBJ_GetPos(void *);
extern Pos WF2DMAP_OBJ_GetDestPos(void *);
extern Pos WF2DMAP_OBJ_OffsetPos(Pos, int);
extern int WF2DMAP_OBJ_GetSlot(u8 *, u32);
extern u32 WF2DMAP_OBJ_GetCount(u8 *p);
extern u8 *WF2DMAP_OBJ_GetByIndex2(void *, u16);
u8 *WF2DMAP_OBJ_FindAtPos(u8 *p, void *list, int n)
{
    Pos src, a, dst, b;
    u32 count;
    int id;
    u32 i;
    u8 *q;
    int qid;
    src = WF2DMAP_OBJ_GetPos(p);
    dst = WF2DMAP_OBJ_OffsetPos(src, n);
    id = WF2DMAP_OBJ_GetSlot(p, 4);
    count = WF2DMAP_OBJ_GetCount(list);
    for (i = 0; i < count; i++) {
        q = WF2DMAP_OBJ_GetByIndex2(list, i);
        if (q != 0) {
            qid = WF2DMAP_OBJ_GetSlot(q, 4);
            if (qid == id) continue;
            a = WF2DMAP_OBJ_GetPos(q);
            if (a.a == dst.a && a.b == dst.b) return q;
            b = WF2DMAP_OBJ_GetDestPos(q);
            if (b.a == dst.a && b.b == dst.b) return q;
        }
    }
    return 0;
}
