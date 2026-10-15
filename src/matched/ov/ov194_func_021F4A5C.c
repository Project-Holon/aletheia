/*
 * function: NAMEIN_GRAPHIC_CallbackFinish
 * address: 0x021F4A5C
 * packet: pkt_ov194_021F4A5C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_GetGridMode 0x021F3350 thumb ov194
 *   BEACON_SetInputFlag 0x0200C0FC thumb
 *   NAMEIN_GRAPHIC_SetCallback 0x021F462C thumb ov194
 *   NAMEIN_GRAPHIC_FinishCallback 0x021F4634 thumb ov194
 *   NAMEIN_GRAPHIC_CallbackPauseSave 0x021F4AA8 thumb ov194
 */
extern void *NAMEIN_GRAPHIC_GetGridMode(const unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Blk34;
extern void BEACON_SetInputFlag(struct Blk34 *p, u32 i, u8 v);
extern void NAMEIN_GRAPHIC_SetCallback(unsigned char *, unsigned);
extern void NAMEIN_GRAPHIC_FinishCallback(unsigned char *);
extern void NAMEIN_GRAPHIC_CallbackPauseSave(unsigned char *p, int *state, unsigned char *q);
#define OBJ(p) (*(char **)((p) + 0x2C4))
void NAMEIN_GRAPHIC_CallbackFinish(unsigned char *a, int unused, char *p)
{
    unsigned n;
    if (*(void **)(OBJ(p) + 0x28) != 0) {
        n = (unsigned int)NAMEIN_GRAPHIC_GetGridMode((const unsigned char *)(p + 0xFC));
        BEACON_SetInputFlag(*(void **)(OBJ(p) + 0x28), (u32)(*(void **)OBJ(p)), n);
    }
    if (*(void **)(OBJ(p) + 0x24) != 0) NAMEIN_GRAPHIC_SetCallback(a, (unsigned)NAMEIN_GRAPHIC_CallbackPauseSave);
    else NAMEIN_GRAPHIC_FinishCallback(a);
}
