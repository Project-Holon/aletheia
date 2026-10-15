/*
 * function: PARTY_STATUS_CreateSubWork
 * address:  0x021E5A70
 * packet:   pkt_021E5A70
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   LIVEBATTLEMATCH_IRC_Create  0x0217E00C  thumb  ov176
 *   ov176_id       0x000000B0  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void *LIVEBATTLEMATCH_IRC_Create(int unused, int heap);
extern u8 ov176_id[];

void PARTY_STATUS_CreateSubWork(u32 *out, u32 **pp, u32 v)
{
    func_02034AC4((u32)ov176_id);
    *out = (u32)LIVEBATTLEMATCH_IRC_Create(*(u32 *)*pp, v);
}
