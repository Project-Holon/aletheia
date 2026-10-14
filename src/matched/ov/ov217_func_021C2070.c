/*
 * function: ARROW_Create
 * address:  0x021C2070
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   ARROW_Alloc  0x021C2550  thumb  ov217
 *   ARROW_Init  0x021C256C  thumb  ov217
 *   ARROW_CreateUnit  0x021C25B0  thumb  ov217
 *   ARROW_CreateActors  0x021C25D0  thumb  ov217
 *   ARROW_SetResources  0x021C2630  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 ARROW_Alloc(u32 a0);
extern u32 ARROW_Init();
extern void ARROW_CreateUnit(u8 *p);
extern void ARROW_CreateActors(u8 *p);
extern void ARROW_SetResources(char *p, char *q);
u32 ARROW_Create(u32 a0, u32 a1)
{
    u32 v1 = ARROW_Alloc(a0);
    ARROW_Init(v1, a0);
    ARROW_SetResources((char *)v1, (char *)a1);
    ARROW_CreateUnit((u8 *)v1);
    ARROW_CreateActors((u8 *)v1);
    return v1;
}

