/*
 * function: FIELD_FLASH_Create
 * address:  0x021C7DAC
 * packet:   pkt_ov021_021C7DAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldFlashFileName  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_InitTween  0x021C7E58  thumb  ov021
 *   FLD_WIPE_3DOBJ_Create  0x021C8018  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char gFieldFlashFileName[];
extern u32 FLD_WIPE_3DOBJ_Create(u32 heap);
extern void FIELD_FLASH_InitTween(u32 a);
M *FIELD_FLASH_Create(u32 heap)
{
    M *m = func_02030734(heap, 0x20, 1, gFieldFlashFileName, 0x7a);
    m->f0 = FLD_WIPE_3DOBJ_Create(heap);
    m->f1C = 0;
    m->f1E = 4;
    FIELD_FLASH_InitTween((u32)m->sub);
    return m;
}
