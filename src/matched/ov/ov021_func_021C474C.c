/*
 * function: FIELD_OV063_Start
 * address:  0x021C474C
 * packet:   pkt_ov021_021C474C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads ov063 and spawns the task that drives its effect.
 *
 * symbols:
 *   func_021F36C0  0x021F36C0  thumb  ov063
 *   FIELD_OV063_TaskUpdate  0x021C4788  thumb  ov021
 *   ov063_id       0x0000003F  data
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern int func_02034AC4(s32 handle);
extern void *func_021F36C0(void *a, u32 b, u32 c, u32 d);
extern char ov063_id[];
int FIELD_OV063_TaskUpdate(void *t);

void *FIELD_OV063_Start(void *a, u32 b, u32 c)
{
    void *t = func_020122C0(a, 0, FIELD_OV063_TaskUpdate, 4);
    void **w = func_020124E8(t);

    func_02034AC4((u32)ov063_id);
    *w = func_021F36C0(a, b, c, 0);
    return t;
}
