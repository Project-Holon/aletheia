/*
 * function: GFL_NET_COMMAND_GetRecvFunc
 * address:  0x0203A70C
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_COMMAND_GetCommandTable  0x0203A67C  arm
 */

typedef unsigned int u32;

struct BaseTable;
extern struct BaseTable *GFL_NET_COMMAND_GetCommandTable(u32 cmd);

int GFL_NET_COMMAND_GetRecvFunc(u32 idx)
{
    int *p = (int *)GFL_NET_COMMAND_GetCommandTable(idx);
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off);
    }
    return 0;
}
