/*
 * function: WIFICLUBACTOR_SetWaitState
 * address:  0x021BA248
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_UpdateWait  0x021BA4C8  thumb
 *   WIFICLUBACTOR_AnimateWalkBob  0x021BA2D4  thumb
 *
 * Homes two handlers at +0x10 and +0x18 in the second argument and stamps the two halfwords at +0x08 and +0x0C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[8];
    u16 f08;
    char pad2[2];
    u16 f0C;
    void *f10;
    void *f14;
    void *f18;
} S;

extern void WIFICLUBACTOR_UpdateWait(void);
extern void WIFICLUBACTOR_AnimateWalkBob(void);

void WIFICLUBACTOR_SetWaitState(int unused, S *s)
{
    s->f10 = (void *)WIFICLUBACTOR_UpdateWait;
    s->f18 = (void *)WIFICLUBACTOR_AnimateWalkBob;
    s->f08 = 0x2D;
    s->f0C = 1;
}
