/*
 * function: WIFICLUBACTOR_ReleaseClactResources
 * address:  0x021B9EA0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *
 * Releases three pointers at +8, +0xC and +0x10 through three arm9 helpers.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

typedef struct {
    char pad[8];
    void *f08;
    void *f0C;
    void *f10;
} S;

void WIFICLUBACTOR_ReleaseClactResources(S *s)
{
    CLACT_ReleaseCharacter((u32)s->f08);
    CLACT_ReleasePalette((u32)s->f0C);
    CLACT_ReleaseCellAnim((u32)s->f10);
}
