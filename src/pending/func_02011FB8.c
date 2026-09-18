/*
 * function: func_02011FB8
 * address:  0x02011FB8
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02011F28     0x02011F28  thumb
 *   func_020267BC     0x020267BC  thumb
 *   func_02021438     0x02021438  thumb
 *
 * The object goes through func_02011F28 with r0 untouched, then one field
 * destructor and a global call.
 *
 * blocker:  label.  Two calls with no outside witness: 0x02011F28 at +0x04
 *           (its only caller in the image is this function) and 0x020267BC at
 *           +0x0A.  Both are byte-correct here; the range cannot be cut to
 *           free them because the call is inside the only function that makes
 *           it.  Folding 0x02011F28 into the same unit would take the packet
 *           to 0x02011F28.. and is possible - see the note in
 *           docs/notes/pkt_02011F28.c.txt.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011FB8.c \
 *       --func func_02011FB8 --addr 0x02011FB8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;         /* +0x08 */
    u32 pad0c;      /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 f14;        /* +0x14 */
    u32 pad18;      /* +0x18 */
    u32 f1c;        /* +0x1C */
    u32 f20;        /* +0x20 */
    u32 f24;        /* +0x24 */
    u32 pad28;      /* +0x28 */
    u32 f2c;        /* +0x2C */
};

extern void func_02011F28(struct IcaAnime *p);
extern void func_020267BC(u32 v);
extern void func_02021438(void);

void func_02011FB8(struct IcaAnime *p)
{
    func_02011F28(p);
    func_020267BC(p->f1c);
    func_02021438();
}
