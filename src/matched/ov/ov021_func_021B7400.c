/*
 * function: PDW_POSTMAN_CreateListWin
 * address:  0x021B7400
 * packet:   pkt_ov021_021B7400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   sPdwPostmanFileName     0x021DE288  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Obj;

struct Fx;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *FIELD_MSGBG_CreateMsgWin(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern u8 sPdwPostmanFileName[];

Obj *PDW_POSTMAN_CreateListWin(u32 a, u32 b, int c)
{
    u32 heap;
    Obj *o;
    int line;
    int sz;

    heap = FIELDMAP_GetHeapId((u8 *)a);
    line = 0x73;
    o = func_02030734(heap, 0x28, 1, (const char *)sPdwPostmanFileName, line);
    o->f0 = heap;
    o->f4 = a;
    o->f24 = b;
    o->f20 = c;
    line += 0xc8;
    o->f8 = (u32)func_02045B38(0, 3, line, heap);
    o->f14 = (u32)WORDSET_CreateDefault(heap);
    o->f18 = (u32)STRBUF_Create(0x80, heap);
    o->f1C = (u32)STRBUF_Create(0x80, heap);
    sz = (c * 14 + 7) & ~7;
    o->fC = (u32)FIELD_MSGBG_CreateMsgWin((struct Fx *)FIELDMAP_GetMsgBg((u8 *)a), o->f8, 1, 1, 0x15, (u16)(sz / 8));
    return o;
}
