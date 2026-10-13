/*
 * function: SCRCMD_PROC_FLD_BuildItemListFixed
 * address:  0x021B39C4
 * packet:   pkt_ov021_021B39C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BMP_MENUWORK_Create  0x0201F81C  thumb
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb
 *   SCRCMD_PROC_FLD_SetItemSlot  0x021B385C  thumb  ov021
 *   d_021DE164     0x021DE164  data  a4
 *   d_021D9430     0x021D9430  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 id;
    u16 pad;
    u32 val;
} Entry;

typedef struct {
    u8 _00[4];
    u16 heap;
    u8 _06[0x1a];
    Entry list[40];
    u16 count;
    u8 mode;
    u8 _163[0x1d];
    Entry *buf;
    u8 _184[4];
    u32 win;
} Obj;

extern Entry *d_021DE164[];
extern u8 d_021D9430[];
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern Entry *BMP_MENUWORK_Create(u32 a, u32 b);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void SCRCMD_PROC_FLD_SetItemSlot(char *p, int idx, int mode, int val, int arg);

void SCRCMD_PROC_FLD_BuildItemListFixed(Obj *p, int idx)
{
    int i;
    Entry *tbl;
    u32 h;
    int n;

    i = 0;
    h = (u32)func_02045B38(0, 2, 0x36, p->heap);
    tbl = d_021DE164[idx];
    n = d_021D9430[idx];
    p->buf = BMP_MENUWORK_Create(n + 1, p->heap);
    for (; i < n; i++) {
        SCRCMD_PROC_FLD_SetItemSlot((char *)p, i, p->mode, tbl[i].id, h);
        p->list[i].id = tbl[i].id;
        p->list[i].val = tbl[i].val;
    }
    p->count = i;
    BMP_MENUWORK_AddMsgItem((struct Slot *)(p->buf + i), p->win, 0xb, -2, p->heap);
    MSGDATA_Delete((struct Rec *)h);
}
