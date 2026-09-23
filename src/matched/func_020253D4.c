/*
 * function: func_020253D4
 * address:  0x020253D4
 * packet:   pkt_02025360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * actor_tool.c: free the run that func_02025360 stamped with index i in
 * one bank: every slot from i on that still holds i goes back to 0xFF.
 * The bank select is the same `sel = 1; if (bank == 0) sel = 0;` as the
 * allocator.  Two declaration facts close it (docs/notes/pkt_020251FC.c.txt
 * had it at 5 bytes): the slots are a 2 x 16 array in the object (the
 * `adds p, i; ldrb [.., #6]` addressing), and the cursor is an INT while
 * the index it starts from is the u32 parameter, which is what makes the
 * image keep the two copies of the cursor (r2 and r3) apart; found by
 * tools/permuter.py --types (type:l(j:u32->int)).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ActorTool {
    u32 f00;
    u8  count[2];         /* +0x04 */
    u8  slot[2][16];      /* +0x06 */
};

void func_020253D4(struct ActorTool *p, u32 i, u32 bank)
{
    u32 sel = 1;
    int j;

    if (bank == 0)
        sel = 0;
    for (j = i; p->slot[sel][j] == i; j++)
        p->slot[sel][j] = 0xff;
}
