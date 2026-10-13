/*
 * function: func_021F6AB8
 * address: 0x021F6AB8
 * packet: pkt_ov215_021F6AB8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 */
typedef unsigned int   u32;
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetOrthoMode(void *);
void func_021F6AB8(char *p)
{
    *(void **)(p + 0x30) = MCSS_Init(1, (void *)(*(unsigned short *)p));
    MCSS_SetTextureTransAdrs(*(void **)(p + 0x30), 3 << 16);
    MCSS_SetOrthoMode(*(void **)(p + 0x30));
    *(unsigned int *)(p + 0x3c) = 0;
    *(unsigned char *)(p + 0x40) = 0;
}
