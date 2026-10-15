/*
 * function: LIVEBATTLEMATCH_IRC_Delete
 * address:  0x0217E058
 * packet:   pkt_0217E058
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_020307B0  0x020307B0  arm
 */

extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern u32 func_020307B0(void *p);

void LIVEBATTLEMATCH_IRC_Delete(int *p)
{
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_DeleteCommandTable(0x1f00);
    func_020307B0(p);
}
