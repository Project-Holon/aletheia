/*
 * function: GFL_NET_ERR_ShowScreen
 * address:  0x0200F7B8
 * packet:   pkt_0200F734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  unresolved relocation(s): 0200FC0C (thumb, from name)*/

typedef unsigned int   u32;
extern u32 GFL_NET_ERR_ProcScreen(u32 a0);

u32 GFL_NET_ERR_ShowScreen(u32 a0)
{
    return GFL_NET_ERR_ProcScreen(a0);
}
