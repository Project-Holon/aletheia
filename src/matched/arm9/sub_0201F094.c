/*
 * function: func_0201F094
 * address:  0x0201F094
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Promoted from src/pending/sub_0201F094.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_02025B94, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_02025B94.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller, and this file closes
 * to EXACT.
 *
 * A wordset.c setter that maps a caller value to a message id through
 * func_02025B94 and renders it. That is why the wordset.c setter run is
 * committed as src/matched/unit_0201F020.c and
 * src/matched/unit_0201F0F8.c with this function left out between them;
 * it can now be folded back in on a future pass.
 *
 * symbols:
 *   func_02025B94  0x02025B94  thumb
 *   MYSTATUS_NameToStrbuf  0x02008500  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F094.c \
 *       --func func_0201F094 --addr 0x0201F094 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct MsgBank;
struct Obj;
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_02045F50(const struct Obj *o);
extern void  MYSTATUS_NameToStrbuf(void *a, void *b);
extern u32   func_02025B94(u32 a);
extern u32 func_0202A230(void *a, u32 idx);
extern void func_0200785C(void *save, u32 box, void *dest);

struct Tag;

struct Entry {
    u8 tag[5];
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

extern void func_0201ED64(struct WordSet *p, u32 i);
extern void func_0201ED84(struct WordSet *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v);
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);

void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n)
{
    u32 id = func_02025B94(a);
    void *s;

    if (id != 0 && n != 0) {
        s = func_02045B38(0, 2, (u16)id, (u16)p->heap);
        if (s != 0) {
            if (n < func_02045F50(s)) {
                MSGDATA_ReadString(s, n, p->buf);
                func_0201ED84(p, i, p->buf, 0);
                MSGDATA_Delete(s);
                return;
            }
            MSGDATA_Delete(s);
        }
    }
    func_0201ED64(p, i);
}
