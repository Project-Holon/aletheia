/*
 * function: enum_local_ips
 * address:  0x0219B6CC
 * packet:   pkt_ov009_0219B6CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      enum_local_ips (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * Near miss (DIFF, same 112 bytes, 7 concrete bytes).  The object's own
 * DWARF gives SOCInAddr as { unsigned long addr; } and a four-byte word
 * copy is what a struct assignment emits (84 bytes, wrong).  The original
 * copies the four address bytes with ldrb/strb grouped as load-pairs then
 * store-pairs, which is this compiler's 1-aligned aggregate copy shape:
 * declaring SOCInAddr as { unsigned char addr[4]; } reproduces the whole
 * body at exactly 112 bytes.  The only residue is a register-role swap of
 * the two scratch registers ip(r12)/lr: the original holds the
 * local_ip_list base in ip and the computed &local_ip_list[i] in lr, this
 * build does the converse (7 bytes).  Every ldrb/strb and the control flow
 * are identical.  Tried the word copy, a struct assignment through an
 * explicit dst pointer and a named src pointer; all give the same swap.
 * The object carries stamp 4.0.0.1025 ("no mwccarm build writes this
 * stamp"), so this is an allocator/version variance, not a source shape.
 * blocker: codegen, ip/lr register role swap (no C spelling flips it).
 *
 * symbols:
 *   getlocalhost   0x0217EFB8 arm
 *   num_local_ips  0x021AE9A0 data
 *   local_ip_list  0x021AE9A4 data
 */

struct SOCInAddr {
    unsigned char addr[4];
};

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

extern struct SOCHostEnt *getlocalhost(void);
extern int num_local_ips;
extern struct SOCInAddr local_ip_list[5];

static void enum_local_ips(void)
{
    struct SOCHostEnt *phost;
    int i;

    phost = getlocalhost();
    if (phost == 0)
        return;
    num_local_ips = 0;
    for (i = 0; i < 5; i++) {
        if (phost->addrList[i] == 0)
            return;
        local_ip_list[i] = *(struct SOCInAddr *)phost->addrList[i];
        num_local_ips = i + 1;
    }
}
