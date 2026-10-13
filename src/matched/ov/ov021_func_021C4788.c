/*
 * function: RAIL_SLIPDOWN_UpdateTask
 * address:  0x021C4788
 * packet:   pkt_ov021_021C4788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   RAIL_SLIPDOWN_Delete  0x021F3758  thumb  ov063
 *   ov063_id       0x0000003F  data
 *   RAIL_SLIPDOWN_IsDone  0x021F376C  thumb  ov063
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
struct Obj;
void *func_020124E8(struct Obj *p);
extern void func_02034A5C(s32 handle);
extern int RAIL_SLIPDOWN_IsDone(int *p);
extern void RAIL_SLIPDOWN_Delete(u8 *p);
extern char ov063_id[];

int RAIL_SLIPDOWN_UpdateTask(void *t)
{
    void **w = func_020124E8(t);

    if (RAIL_SLIPDOWN_IsDone(*w) != 0) {
        RAIL_SLIPDOWN_Delete(*w);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}
