/*
 * function: GFL_USE_UpdateSound
 * address:  0x02005BC0
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Closest C for the console-init body: shut the console down, arm the two
 * handlers, take the 0x1a-byte record block from the console object, then
 * walk all 16 slots, OR-ing the occupancy bit for every slot the slot probe
 * accepts, and finally tick the delay counter at +8 down by one.
 *
 * The global is spelled as an expression at every use rather than held in a
 * named u8 *: the image re-materialises 0x020AA260 from its pool word at
 * +0042 for the tail, which a named local suppresses.
 *
 * Byte-correct as written (the earlier DIFF's 29 concrete bytes are gone): the
 * two changes that closed it were spelling the global as an expression at
 * every use instead of binding it to a named `u8 *` local -- which is what
 * makes the tail re-materialise 0x020AA260 from its pool word at +0042 -- and
 * reading the delay counter into a named local `v` so the load is reused by
 * the store.
 *
 * PARKED AT MATCH*.  Four of the seven sites have no witness outside this
 * range: func_02072758 and func_020727B4 (called only from here image-wide),
 * NNS_SndHandleReadTrackInfo (likewise) and the record block g020AA414, whose only pool
 * word in the image is this function's own.  The third call and both other
 * relocations resolve (`label` x1/x5, `literal` x18).  The trailing `*` is the
 * unlabelled follower at 0x02005C18 (matched as src/matched/unit_02005C18.c)
 * making disasm.py's extent run to 0x02005C28.
 *
 * symbols:
 *   g020AA260      0x020AA260  data
 *   g020AA414      0x020AA414  data
 *   GFL_USE_UpdateBgmChange  0x02005FF4  thumb
 *   GFL_USE_GetBgmHandle  0x02005C3C  thumb
 *   func_02072758  0x02072758  arm
 *   func_020727B4  0x020727B4  arm
 *   NNS_SndHandleReadTrackInfo  0x02073108  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g020AA260[];
extern u8 g020AA414[];

extern void  GFL_USE_UpdateBgmChange(void);
extern u32 *GFL_USE_GetBgmHandle(void);
extern void  func_02072758(void);
extern u32 func_020727B4(void);
struct Obj;
struct SNDTrackInfo;
extern int   NNS_SndHandleReadTrackInfo(struct Obj *o, int trackNo, struct SNDTrackInfo *trackInfo);

void GFL_USE_UpdateSound(void)
{
    u8 *p;
    int i;
    u32 v;

    GFL_USE_UpdateBgmChange();
    func_02072758();
    func_020727B4();
    p = (u8 *)GFL_USE_GetBgmHandle();
    *(u16 *)g020AA260 = 0;
    for (i = 0; i < 0x10; i++) {
        if (NNS_SndHandleReadTrackInfo((struct Obj *)p, i, (struct SNDTrackInfo *)(g020AA414 + i * 0x1a)) == 1) {
            *(u16 *)g020AA260 |= (u16)(1 << i);
        }
    }
    v = *(u32 *)(g020AA260 + 8);
    if (v != 0) {
        *(u32 *)(g020AA260 + 8) = v - 1;
    }
}
