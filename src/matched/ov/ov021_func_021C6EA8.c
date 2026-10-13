/*
 * function: FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone
 * address:  0x021C6EA8
 * packet:   pkt_ov021_021C6EA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TASK_Start  0x021C6CC4  thumb  ov021
 *   FIELD_TASK_GetState  0x021C6CE0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
extern u32 FIELD_TASK_GetState(u8 *p);
extern void FIELD_TASK_Start(u32 *a0);
void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(R *r, int i)
{
    if (r->f4[i] != 0 && r->f8[i] != 0) {
        if (FIELD_TASK_GetState((u8 *)r->f4[i]) == 0 && FIELD_TASK_GetState((u8 *)r->f8[i]) == 2)
            FIELD_TASK_Start((u32 *)r->f4[i]);
    }
}
