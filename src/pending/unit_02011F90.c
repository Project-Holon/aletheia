/*
 * unit:     yes
 * function: func_02011F90
 * address:  0x02011F90
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * symbols:
 *   func_020122B4     0x020122B4  thumb
 *   func_02012258     0x02012258  thumb
 *   func_0202B4F0     0x0202B4F0  thumb
 *   func_02012704     0x02012704  thumb
 *   func_02026250     0x02026250  thumb
 *   func_02013A48     0x02013A48  thumb
 *
 * ica_anime.c teardown: one call made with the incoming r0 left alone, that
 * same object passed explicitly to the next, then three fields through their
 * own destructors and a global one.  The object is saved first because the
 * first call takes no argument of its own.
 *
 * tu, not one: the last two bytes of the extent are the linker's alignment
 * padding up to func_02011FB8, which `one` counts as a size mismatch and
 * would report as EXACT*.
 *
 * blocker:  label.  The call to 0x0202B4F0 at +0x10 has no witness anywhere:
 *           no branch outside this range reaches it, no other pool word names
 *           it, and no EXACT manifest entry covers it.  Its only caller in the
 *           image is this function, so no cut or split helps, and the target
 *           is outside this agent's range (0x0202B4F0 is in the
 *           0x0201E000..0x0202E000 lane) - it cannot be written from here.
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02011F90.c \
 *       --addr 0x02011F90 --thumb
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

extern void func_020122B4(void);
extern void func_02012258(struct IcaAnime *p);
extern void func_0202B4F0(u32 v);
extern void func_02012704(u32 v);
extern void func_02026250(u32 v);
extern void func_02013A48(void);

void func_02011F90(struct IcaAnime *p)
{
    func_020122B4();
    func_02012258(p);
    func_0202B4F0(p->f2c);
    func_02012704(p->f1c);
    func_02026250(p->f24);
    func_02013A48();
}
