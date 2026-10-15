/*
 * unit:     yes
 * address:  0x0201F31C
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201F31C, func_0201F344
 *
 * symbols:
 *   gSpeciesNameBank   0x020A7370  data
 *   STRBUF_Clear  0x0204581C  arm
 *
 * The wordset.c "clear every slot" walk and the one-line initialiser that
 * fills the file-scope template string at 0x020A7370.  That pointer is loaded
 * by WORDSET_Callback in src/matched/unit_0201ED04.c and by seven functions
 * outside this region, so the `literal` class has witnesses to spare.
 *
 * func_0201F344 takes its heap id as a u16: the 4th argument of
 * func_02045B38 is a u16 and the original passes the incoming register
 * straight through with no `lsls`/`lsrs` truncation pair, which a u32
 * parameter would have cost.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F31C.c  *       --addr 0x0201F31C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgBank;
struct U16Vec;
extern void STRBUF_Clear(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *gSpeciesNameBank;

struct Entry { u8 tag[5]; void *str; };
struct WordSet { u32 count; u32 heap; struct Entry *entries; void *buf; };

void func_0201F31C(struct WordSet *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        STRBUF_Clear(p->entries[i].str);
    }
}

void func_0201F344(u16 heap)
{
    gSpeciesNameBank = func_02045B38(0, 2, 0x46, heap);
}
