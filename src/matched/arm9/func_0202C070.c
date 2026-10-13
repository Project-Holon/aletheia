/*
 * function: ISS_SWITCH_SYS_Create
 * address:  0x0202C070
 * packet:   pkt_0202C070
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocked: the THM_CALL at +0012 to ISS_SWITCH_SYS_CreateSets has no manifest entry.
 * 0x0202C148 (76 bytes, pkt_0202C148, still open) is byte-correct except an
 * eight-instruction schedule permutation in its prologue: 15 C spellings were
 * measured and every one emits the same permuted block, so it is a DIFF and
 * cannot be filed - see docs/notes/pkt_0202C148.c.txt.  The other two sites
 * (ISS_SWITCH_SYS_Alloc, ISS_SWITCH_SYS_Init) resolve as `matched`.  Every concrete byte
 * reproduces.
 *
 * Creates a node through ISS_SWITCH_SYS_Alloc, prepares it with ISS_SWITCH_SYS_Init and
 * binds the argument with ISS_SWITCH_SYS_CreateSets.
 *
 * symbols:
 *   ISS_SWITCH_SYS_Alloc  0x0202C124  thumb
 *   ISS_SWITCH_SYS_Init  0x0202C118  thumb
 *   ISS_SWITCH_SYS_CreateSets  0x0202C148  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *ISS_SWITCH_SYS_Alloc(u32 heap);
extern void ISS_SWITCH_SYS_Init(void *obj);
extern void ISS_SWITCH_SYS_CreateSets(u8 *p, u32 heap);

u8 *ISS_SWITCH_SYS_Create(u32 heap)
{
    u8 *r = ISS_SWITCH_SYS_Alloc(heap);

    ISS_SWITCH_SYS_Init(r);
    ISS_SWITCH_SYS_CreateSets(r, heap);
    return r;
}
