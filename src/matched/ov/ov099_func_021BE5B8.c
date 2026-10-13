/*
 * function: WIFICLUB_InitSprites
 * address:  0x021BE5B8
 * packet:   pkt_ov099_021BE5B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 (wD6 lane13): EXACT. CLACT_SetUnitRenderer takes two arguments (bank, p); the second is the
 * value stored at p + 0x114. The 0x110/0x114 offsets are plain literals: mwcc derives them from the 0x64
 * count constant by itself.
 *
 * symbols:
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];
struct Bank;
struct Cfg;
struct Obj;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);

void WIFICLUB_InitSprites(char *p, void *a1)
{
    CLACT_InitSystem((const struct Cfg *)d_021C3740, (u32)d_021C3AA0, 0x21);
    *(void **)(p + 0x110) = CLACT_CreateUnit(0x64, 0, 0x21);
    *(void **)(p + 0x114) = CLACT_CreateRenderer(d_021C375C, 2, 0x21);
    CLACT_SetUnitRenderer(*(void **)(p + 0x110), *(void **)(p + 0x114));
}
