/*
 * function: func_021C6E74
 * address:  0x021C6E74
 * packet:   pkt_ov021_021C6E74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_TASK_Delete  0x021C6CA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
extern void FIELD_TASK_Delete(Q *q);
void func_021C6E74(R *r, u8 i)
{
    if (r->f4[i] != 0) {
        FIELD_TASK_Delete(r->f4[i]);
        r->f4[i] = 0;
        r->f8[i] = 0;
    }
}
