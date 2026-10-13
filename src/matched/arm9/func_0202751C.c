/*
 * function: BEACON_STATUS_Create
 * address:  0x0202751C
 * packet:   pkt_020274C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734       0x02030734  arm
 *   func_020457B0       0x020457B0  arm
 *   func_02045B38       0x02045B38  arm
 *   func_02045EC0       0x02045EC0  arm
 *   func_02045A38       0x02045A38  arm
 *   func_02045924       0x02045924  arm
 *   func_02045808       0x02045808  arm
 *   func_02045C04       0x02045C04  arm
 *   beacon_status_File     0x020A74D0  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgBank;
struct Rec;
struct Strbuf;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern const char beacon_status_File[];

typedef struct {
    void *f000[0xb08 / 4];
    void *fb08;
} Obj;

Obj *BEACON_STATUS_Create(u32 heap, u32 a1)
{
    Obj *p;
    void *arc;
    void *msg;
    u16 buf[10];

    p = (Obj *)func_02030734(heap, 0xb10, 1, beacon_status_File, 42);
    p->fb08 = func_020457B0(9, heap);
    arc = func_02045B38(0, 2, 8, a1);
    msg = func_02045EC0(arc, 0x11);
    func_02045A38(msg, buf, 9);
    func_02045924(p->fb08, buf);
    func_02045808(msg);
    func_02045C04(arc);
    return p;
}
