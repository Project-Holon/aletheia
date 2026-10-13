/*
 * function: BSUBWAY_RECORD_LIST_DrawPageRows
 * address:  0x021BA480
 * packet:   pkt_ov069_021BA480
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   BSUBWAY_RECORD_LIST_GetRowCountOnPage  0x021BA470  thumb  ov069
 *   STRBUF_SetStringN  0x02045994  arm
 *   BSUBWAY_RECORD_LIST_DrawRowName  0x021BA520  thumb  ov069
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    unsigned char pad[0x20];
    u8 f0 : 1;
    u8 f1 : 1;
} Ent;

typedef struct Obj {
    unsigned char pad000[4];
    struct WinMgr *f4;
    char *f8;
    unsigned char pad00C[0x160 - 0xC];
    u16 page;
    u16 f162;
    int f164;
} Obj;

typedef unsigned int u32;
struct WinMgr;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int BSUBWAY_RECORD_LIST_GetRowCountOnPage(int a, int b, int c);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *dst, const u16 *src, u32 n);
extern void BSUBWAY_RECORD_LIST_DrawRowName(u8 *a0, int a1, void *a2, int a3);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void STRBUF_Delete(struct U16Vec *vec);

void BSUBWAY_RECORD_LIST_DrawPageRows(Obj *o)
{
    void *buf;
    int n;
    int i;

    buf = STRBUF_Create(0x10, 0x80);
    n = BSUBWAY_RECORD_LIST_GetRowCountOnPage(o->page, o->f162, o->f164);
    i = 0;
    if (n > 0) {
        do {
            STRBUF_SetStringN(buf, (const u16 *)(o->f8 + (i + o->page * 10) * 0x22), 8);
            BSUBWAY_RECORD_LIST_DrawRowName((u8 *)o, i, buf, ((Ent *)(o->f8 + (i + o->page * 10) * 0x22))->f1);
            i++;
        } while (i < n);
    }
    for (; i < 10; i++)
        BGWINFRM_HideFrame(o->f4, i);
    STRBUF_Delete(buf);
}
