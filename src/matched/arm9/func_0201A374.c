/*
 * function: POKE_REGULATION_BuildPartySizeLine
 * address:  0x0201A374
 * packet:   pkt_0201A374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201EFA4   0x0201EFA4  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   MSGDATA_ReadString   0x02045CAC  arm
 *   func_0201F250   0x0201F250  thumb
 *
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through func_0201EFA4, the record is allocated against a4, its
 * slots are filled from *a2 through MSGDATA_ReadString and the pair is bound by
 * func_0201F250.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_BuildPartySizeLine.c \
 *       --func POKE_REGULATION_BuildPartySizeLine --addr 0x0201A374 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgBank;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void *POKE_REGULATION_BuildPartySizeLine(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[2] == 1 && a0[3] == 6) {
        mode = 6;
    } else if (a0[2] == a0[3]) {
        mode = 7;
    } else if (a0[2] > 1 && a0[3] == 6) {
        mode = 8;
    } else {
        mode = 9;
    }
    func_0201EFA4((struct WordSet *)a1, 0, a0[2], 1, 0, 1);
    func_0201EFA4((struct WordSet *)a1, 1, a0[3], 1, 0, 1);
    p = STRBUF_Create(0x40, a4);
    MSGDATA_ReadString((struct MsgBank *)(*a2), mode, (void *)a3);
    func_0201F250((struct WordSet *)a1, p, (void *)a3);
    return p;
}
