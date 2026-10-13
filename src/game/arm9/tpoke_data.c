/*
 * file:     tpoke_data.c
 * unit:     yes
 * function: func_0202A128, func_0202A170, func_0202A188, func_0202A19C, func_0202A1CC, func_0202A20C, func_0202A21C, func_0202A230, func_0202A298, func_0202A310, func_0202A3AC, func_0202A3BC, func_0202A3CC, func_0202A3D8, func_0202A3FC, func_0202A420
 * address:  0x0202A128
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   sTpokeData82   0x020A76CC  data
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   Data_0209FF1C  0x0209FF1C  data
 *   Table_0209FEE4  0x0209FEE4  data
 *   func_0202A3D8   0x0202A3D8  thumb
 *   func_0202A3AC  0x0202A3AC  thumb
 *   func_02082A60  0x02082A60  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 */
#include "../../matched/include/Obj15808.h"
#include "../../matched/include/Obj15810.h"
#include "../../matched/include/Obj15812.h"

struct Container;
struct ArcFile;
struct MsgBank;
struct Rec;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    int   handle;
    void *buf;
    void *buf4;
    u32   count;
} Tpoke;

typedef struct { void *p0; void *p1; } XmlReader;

typedef unsigned char  u8;

struct Item {
    u16 key;
    u16 v2;
    u16 v3;
    u16 pad;
};

struct Container {
    const struct Item *items;
    u32 pad1;
    u32 pad2;
    u32 count;
};

typedef signed int    s32;

typedef struct {
    u8  b0;
    u8  b1;
    u8  b2;
    u8  b3;
    u16 w[4];
    u32 d;
    u8  f : 1;
    u8  b11;
    u16 h12;
} Buf;

struct Record {
    u16 val : 7;
    u16 field2 : 4;
    u16 rest : 5;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int   ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern u32 func_0202A1CC(const struct Container *c, u32 key, u32 v2, u32 v3);
extern u32   ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void  ARC_TOOL_DeleteHandle(void *h);
u32 func_0202A20C(u8 *p, u32 key, u32 v2, u32 v3);
int func_0202A21C(int a0, int a1);
u32 func_0202A230(void *a, u32 idx);
u32 func_0202A298(u32 key, u32 want, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
void func_0202A310(int key, int want, void *dest, u32 heap);
void func_0202A3AC(void *a0, void *a1);
void func_0202A3BC(void *a0, void *a1);
u8 func_0202A3CC(u32 idx);
u8 func_0202A3D8(u32 key);
u8 func_0202A3FC(u32 key);
u32 func_0202A420(u32 key);
extern void  func_02082A60(const void *src, void *dest, u32 size);
extern void  PMSI_PARAM_ClearSentence(void *p);
Tpoke *func_0202A128(int heap);
void gsXmlFreeReader(XmlReader *reader);
u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3);
int func_0202A19C(u32 a, u32 *p, u32 c, u32 d, u16 e);
extern const char sTpokeData82[];
extern const u8 Data_0209FF1C[];
extern const struct Record Table_0209FEE4[];







Tpoke *func_0202A128(int heap)
{
    Tpoke *p;
    u32 size;

    p = (Tpoke *)func_02030734(heap, 0x10, 1, sTpokeData82, 82);
    p->handle = ARC_UTIL_LoadMemberWithSize(0xd3, 0, 0, heap, &size);
    p->count = size >> 3;
    p->buf = ARC_TOOL_LoadMember(0x30, 0, heap);
    p->buf4 = (char *)p->buf + 4;
    return p;
}






void gsXmlFreeReader(XmlReader *reader)
{
    func_020307B0(reader->p1);
    func_020307B0(reader->p0);
    func_020307B0(reader);
}







/*
 * Returns the halfword at entry i (times 8 plus 6) of the +0 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A188.c \
 *       --func func_0202A188 --addr 0x0202A188 --thumb --cc 1.1p1
 */
u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3)
{
    u32 i = func_0202A20C(p, a, v2, v3);

    return *(u16 *)(((struct Obj15808 *)p)->f0 + i * 8 + 6);
}







int func_0202A19C(u32 a, u32 *p, u32 c, u32 d, u16 e)
{
    int i = func_0202A20C((u8 *)p, c, d, e);
    u8 *r = (u8 *)func_0202A21C((int)p, *(u16 *)((u8 *)*p + i * 8 + 6));

    if (((struct Obj15810 *)r)->f7 == 2) {
        return 1;
    }
    return 0;
}







/*
 * Bounded scan of the container's 8-byte records: the one whose key matches and
 * whose second field is either 2 or the caller's v2, and whose third field is
 * the caller's v3, is returned by index; 0xffff when none is.  The bound is
 * re-read at the foot of the loop, which is the shape of
 * src/matched/sub_0202BFC4.c: the container has to be declared as a struct
 * with a `count` member and the records reached as `c->items[i]`, because the
 * subscript form is what keeps `c` live in r0 and re-loads `c->count` at the
 * bottom of the loop.  Written with a separate base pointer the compiler caches
 * the bound and the residue is 10 bytes of register shuffling.
 *
 * Closes the blocker of src/pending/func_0202A20C.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A1CC.c \
 *       --func func_0202A1CC --addr 0x0202A1CC --thumb --cc 1.1p1
 */
u32 func_0202A1CC(const struct Container *c, u32 key, u32 v2, u32 v3)
{
    u32 i;

    for (i = 0; i < c->count; i++) {
        if (c->items[i].key != key) {
            continue;
        }
        if (c->items[i].v2 != 2 && c->items[i].v2 != v2) {
            continue;
        }
        if (c->items[i].v3 != v3) {
            continue;
        }
        return i;
    }
    return 0xffff;
}


/*
 * Returns func_0202A1CC's result, clamped to zero when negative.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A20C.c \
 *       --func func_0202A20C --addr 0x0202A20C --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202A1CC was filed as an EXACT entry this
 * wave (pkt_0202A19C) with the struct-container spelling of the bounded scan.
 */
u32 func_0202A20C(u8 *p, u32 key, u32 v2, u32 v3)
{
    s32 r = func_0202A1CC((const struct Container *)p, key, v2, v3);

    return r < 0 ? 0u : (u32)r;
}


int func_0202A21C(int a0, int a1){ int t0 = func_0200F128((int)(a1 + 0)); return (((struct Obj15812 *)((char *)((a0 + 0))))->f8 + (t0 * 0x1c)); }


u32 func_0202A230(void *a, u32 idx)
{
    Buf buf;
    u32 r;

    func_0202A3AC(a, &buf);
    switch (idx) {
    case 0:
        r = buf.b0;
        break;
    case 1:
        r = buf.b1;
        break;
    case 2:
        r = buf.b2;
        break;
    case 3:
        r = buf.b3;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = buf.w[idx - 4];
        break;
    case 8:
        r = buf.d;
        break;
    case 9:
        r = buf.f;
        break;
    case 10:
        r = buf.b11;
        break;
    case 11:
        r = buf.h12;
        break;
    }
    return r;
}


u32 func_0202A298(u32 key, u32 want, u32 heap)
{
    u16   rec[4];
    void *h;
    u32   end;
    u32   found = 0;

    end = ARC_TOOL_GetMemberSize(0x5a, 0);
    ARC_TOOL_ReadMemberRange(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = func_020490F4(0x5a, heap);

    while (rec[0] != end) {
        ARC_TOOL_ReadHandleMemberRange(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            found = 1;
            break;
        }
        if (rec[1] != key) {
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    ARC_TOOL_DeleteHandle(h);
    return found;
}



void func_0202A310(int key, int want, void *dest, u32 heap)
{
    u16   rec[4];
    void *h;
    void *bank;
    u32   end;

    bank = func_02045B38(0, 2, 0xbd, heap);
    end = ARC_TOOL_GetMemberSize(0x5a, 0);
    ARC_TOOL_ReadMemberRange(rec, 0x5b, 0, key * 2, (u32 *)2);
    h = func_020490F4(0x5a, heap);

    while (rec[0] != end) {
        ARC_TOOL_ReadHandleMemberRange(h, 0, rec[0], 4, &rec[1]);
        if (rec[1] == key && rec[2] == want) {
            MSGDATA_ReadString(bank, (u32)rec[0] >> 2, dest);
            break;
        }
        rec[0] = (u16)(rec[0] + 4);
    }

    ARC_TOOL_DeleteHandle(h);
    MSGDATA_Delete(bank);

    if (rec[0] == end) {
        STRBUF_Clear(dest);
    }
}



void func_0202A3AC(void *a0, void *a1)
{
    ARC_TOOL_ReadMember(a1, 0x5c, (u32)a0);
}



void func_0202A3BC(void *a0, void *a1)
{
    ARC_TOOL_ReadMember(a1, 0x5d, (u32)a0);
}



/*
 * Blocked: Data_0209FF1C is named by this function's one pool word
 * (0x0202A3D4) inside the compared range; `literal` has no outside site
 * and the target is neither a string nor a pointer table.  Every concrete
 * byte reproduces.
 */
u8 func_0202A3CC(u32 idx)
{
    return Data_0209FF1C[idx];
}


u8 func_0202A3D8(u32 key)
{
    int i;

    for (i = 0; i < 0x1c; i++) {
        if (key == Table_0209FEE4[i].val) {
            return (u8)i;
        }
    }
    return 0x1c;
}


u8 func_0202A3FC(u32 key)
{
    u8 idx = func_0202A3D8(key);
    if (idx >= 0x1c) {
        return 12;
    }
    return (u8)Table_0209FEE4[idx].field2;
}


u32 func_0202A420(u32 key)
{
    u8 idx = func_0202A3D8(key);
    if (idx >= 0x1c) {
        return 0x11;
    }
    return Table_0209FEE4[idx].rest;
}
