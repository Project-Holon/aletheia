/*
 * function: FIELD_TASK_CreatePlayerDrop
 * address:  0x021C7684
 * packet:   pkt_ov021_021C7684
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdatePlayerDrop  0x021C7730  thumb  ov021
 *   _fflt          0x0209BDBC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELD_TASK_Create(u32 h, int size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
extern void FIELD_TASK_UpdatePlayerDrop(void);

void *FIELD_TASK_CreatePlayerDrop(u32 a, u32 b, int c, int d)
{
    void *o;
    Fx *p;

    o = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x14, (void *)FIELD_TASK_UpdatePlayerDrop);
    p = (Fx *)FIELD_TASK_GetWork(o);
    p->st = 0;
    p->w4 = a;
    p->h8 = 0;
    p->ha = c;
    p->fc = (float)d;
    p->w10 = b;
    return o;
}
