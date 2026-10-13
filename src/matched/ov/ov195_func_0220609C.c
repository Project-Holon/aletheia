/*
 * function: func_0220609C
 * address:  0x0220609C
 * packet:   pkt_0220609C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *
 * 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) resolves as label
 * since its function_starts seed (2026-09-27). EXACT*: the listing extent
 * includes the 2 bytes of alignment padding at 0x022060BA.
 */
#include "../include/Obj08349.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *p, u32 v);
extern void MCSS_SetOrthoMode(void *obj);

void func_0220609C(char *a)
{
    ((struct Obj08349 *)a)->f4C = (u32)MCSS_Init(2, (void *)(((struct Obj08349 *)a)->f0));
    MCSS_SetTextureTransAdrs((void *)(((struct Obj08349 *)a)->f4C), 0x30000);
    MCSS_SetOrthoMode((void *)(((struct Obj08349 *)a)->f4C));
}
