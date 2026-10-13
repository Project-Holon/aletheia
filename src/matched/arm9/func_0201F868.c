/*
 * function: BMP_MENUWORK_Delete
 * address:  0x0201F868
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Destructor pair: run the teardown at 0x0201F8F4, then release the object
 * itself through the allocator's free entry at 0x020307B0.  The pointer has
 * to survive the first call, which is what spends r4 and turns a two-call
 * leaf into a push/pop function.
 *
 * symbols:
 *   BMP_MENUWORK_ReleaseItems  0x0201F8F4  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_Delete.c \
 *       --func BMP_MENUWORK_Delete --addr 0x0201F868 --cc 1.1p1 --thumb
 */
struct Slot;
extern void BMP_MENUWORK_ReleaseItems(struct Slot *s);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

u32 BMP_MENUWORK_Delete(void *p)
{
    BMP_MENUWORK_ReleaseItems(p);
    return func_020307B0(p);
}
