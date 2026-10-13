/*
 * function: FIELD_TASK_CreateFade
 * address:  0x021C7814
 * packet:   pkt_ov021_021C7814
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
 *   FIELD_TASK_UpdateFade  0x021C7844  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern Q *FIELD_TASK_Create(u32 heap, u32 size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } X;
extern int FIELD_TASK_UpdateFade(u32 a, u32 b, u32 c);
Q *FIELD_TASK_CreateFade(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    Q *q = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x14, FIELD_TASK_UpdateFade);
    X *x = (X *)FIELD_TASK_GetWork((u8 *)q);
    x->f0 = a;
    x->f4 = b;
    x->f8 = c;
    x->fC = d;
    x->f10 = e;
    return q;
}
