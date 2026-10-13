/*
 * function: FIELDMAP_CheckCommExit
 * address:  0x02189734
 * packet:   pkt_02189734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Comm;
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 GAME_COMM_IsTransition(void *obj);

int FIELDMAP_CheckCommExit(u32 a, u32 b, u32 c, u32 d)
{
if (GAME_COMM_GetKind((void *)a) == 0) {
    return 1;
}
if (GAME_COMM_IsTransition((void *)a) == 0) {
    GAME_COMM_RequestExitNoCallback((struct Comm *)a);
}
return 0;
}

