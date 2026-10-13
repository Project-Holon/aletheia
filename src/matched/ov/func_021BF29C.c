/*
 * function: WIFICLUB_ReleaseSlotActors
 * address:  0x021BF29C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_ResumeActorSprite  0x021B98E4  thumb  ov099
 *
 * Releases the block 0x274 bytes in once for every occupied slot of the
 * 0x21-entry pointer table at +0x814.  The slot value is the SECOND argument of
 * WIFICLUBACTOR_ResumeActorSprite, which is why the image loads it into r1 and keeps it live into
 * the call; that liveness, not an allocator quirk, is the byte the lane before
 * this one measured as a residue.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUBACTOR_ResumeActorSprite(int a, u8 *b);

void WIFICLUB_ReleaseSlotActors(char *p)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        void *v = *(void **)(p + i * 4 + 0x814);

        if (v != 0) {
            WIFICLUBACTOR_ResumeActorSprite((int)(p + 0x274), v);
        }
    }
}
