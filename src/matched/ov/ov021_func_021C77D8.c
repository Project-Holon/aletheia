/*
 * unit:     yes
 * function: FIELD_TASK_CreateWait, FIELD_TASK_UpdateWait
 * address:  0x021C77D8
 * packet:   pkt_ov021_021C77D8
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern Q *FIELD_TASK_Create(u32 heap, u32 size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
typedef struct { u16 f0; u16 f2; } X;
int FIELD_TASK_UpdateWait(X *x);
Q *FIELD_TASK_CreateWait(u32 a, u16 b)
{
    Q *q = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 4, FIELD_TASK_UpdateWait);
    X *x = (X *)FIELD_TASK_GetWork((u8 *)q);
    x->f0 = 0;
    x->f2 = b;
    return q;
}

int FIELD_TASK_UpdateWait(X *x)
{
    x->f0++;
    if (x->f2 <= x->f0)
        return 1;
    return 0;
}
