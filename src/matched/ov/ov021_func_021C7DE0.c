/*
 * function: FIELD_FLASH_Delete
 * address:  0x021C7DE0
 * packet:   pkt_ov021_021C7DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_ClearTween  0x021C7E64  thumb  ov021
 *   FLD_WIPE_3DOBJ_Delete  0x021C8054  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void FIELD_FLASH_ClearTween(u32 a);
extern int FLD_WIPE_3DOBJ_Delete(void *a);
void FIELD_FLASH_Delete(M *m)
{
    if (m != 0) {
        FIELD_FLASH_ClearTween((u32)m->sub);
        FLD_WIPE_3DOBJ_Delete((void *)m->f0);
        func_020307B0(m);
    }
}
