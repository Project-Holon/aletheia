/*
 * function: WIFICLUB_FindPeerActor
 * address:  0x021BE2A8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_GetActorId  0x021B9A50  thumb  ov099
 *
 * Walks the 0x21 pointers of the table at +0x814 and returns the first whose
 * WIFICLUBACTOR_GetActorId answer is the second argument, else 0.
 *
 * The two slots of the table are addressed by two spellings that differ in
 * where the 0x814 constant sits: `p + i * 4 + 0x814` on the test and the call,
 * `p + 0x814 + i * 4` on the return.  Writing all three the same way makes
 * 1.1p1 keep `p + i * 4` in a callee-saved register across the call
 * (`adds r7, r5, r0`) where the image keeps the bare scaled index there
 * (`lsls r7, r4, #2 ; adds r1, r5, r7`) and recomputes the base.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 WIFICLUBACTOR_GetActorId(char *p);

void *WIFICLUB_FindPeerActor(char *p, int key)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(u32 *)(p + i * 4 + 0x814) != 0 &&
            WIFICLUBACTOR_GetActorId(*(char **)(p + i * 4 + 0x814)) == key) {
            return *(void **)(p + 0x814 + i * 4);
        }
    }
    return 0;
}
