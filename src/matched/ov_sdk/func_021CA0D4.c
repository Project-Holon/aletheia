/*
 * function: func_021CA0D4
 * address:  0x021CA0D4
 * packet:   pkt_021CA0D4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA0D4   0x021CA0D4  arm
 *   gSceneSetListFocusColumnTable   0x021DA650  data
 *   func_021C9D10   0x021C9D10  arm
 *   func_021C9F58   0x021C9F58  arm
 *
 * Map the argument through the shared byte table into the global's second byte.
 * Addresses are Black-image addresses.
 */

extern int func_021C9D10(int);
extern void func_021C9F58(void);
extern unsigned char gSceneSetListFocusColumnTable[];

void func_021CA0D4(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;

    *g = a;
    *(unsigned char *)(g + 2) = func_021C9D10(gSceneSetListFocusColumnTable[a]);
    func_021C9F58();
}

