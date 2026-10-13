/*
 * function: FIELD_OV063_TaskUpdate
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
 *   func_021F3758  0x021F3758  thumb  ov063
 *   ov063_id       0x0000003F  data
 *   func_021F376C  0x021F376C  thumb  ov063
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
struct Obj;
void *func_020124E8(struct Obj *p);
extern void func_02034A5C(s32 handle);
extern int func_021F376C(int *p);
extern void func_021F3758(u8 *p);
extern char ov063_id[];

int FIELD_OV063_TaskUpdate(void *t)
{
    void **w = func_020124E8(t);

    if (func_021F376C(*w) != 0) {
        func_021F3758(*w);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}
