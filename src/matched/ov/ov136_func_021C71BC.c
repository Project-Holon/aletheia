/*
 * function: MB_SEQ_OpenMenuKind
 * address:  0x021C71BC
 * packet:   pkt_ov136_021C71BC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MB_SEQ_OpenTwoEntryMenu 0x021C5974 thumb
 */
#include "../include/Obj08199.h"
#include "../include/Obj23640.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void MB_SEQ_OpenTwoEntryMenu(u8 *);
int MB_SEQ_OpenMenuKind(u8 *p, int v)
{
    ((struct Obj23640 *)(*(u8 * *)&((struct Obj08199 *)p)->f8))->f1E0 = v;
    MB_SEQ_OpenTwoEntryMenu(p);
    return 4;
}
