/*
 * function: FIELD_TASK_MANAGER_UpdateSlot
 * address:  0x021C6E94
 * packet:   pkt_ov021_021C6E94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_TASK_Update  0x021C6CBC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
extern void FIELD_TASK_Update(void);
void FIELD_TASK_MANAGER_UpdateSlot(R *r, int i)
{
    if (r->f4[i] != 0)
        FIELD_TASK_Update();
}
