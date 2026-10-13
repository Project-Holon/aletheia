/*
 * file:     field_3dbg_p01.c
 * unit:     yes
 * function: func_021A10D4, ov021_func_021A10E0, func_021A1138
 * address:  0x021A10D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c at 0x021A10D4 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_021F29D8  0x021F29D8  thumb  ov029
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_021F2980 0x021F2980 thumb ov029
 *   func_021F2994  0x021F2994  thumb  ov029
 *   func_021F2848  0x021F2848  thumb  ov029
 */
struct GameDataRef;
struct GameSystem;

typedef unsigned int   u32;
typedef unsigned short u16;

/* The field's C-Gear glue object; the creator of the cgear handle is in field_3dbg.c (func_021A1480). */
typedef struct FieldCGearWork {
    u32 gap00[3];
    u16 heapId;
    u16 gap0E;
    u32 gap10;
    void *fieldSystem;
    u32 gap18[2];
    void *cgear;
} FieldCGearWork;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_02012EBC(struct GameDataRef *p);
extern u32 func_02009210();
extern void func_02009200(u32, u32);
extern u32 func_0201214C(const struct GameSystem *);
extern u32 func_02012204(const struct GameSystem *p);
extern void func_02012210(struct GameSystem *p);
u32 func_021F2980(u32 a);
u32 func_021A10D4(FieldCGearWork *work);
extern int func_021F2994(int *cgear);
extern u32 func_021F2848(u32, u32);
u32 ov021_func_021A10E0(FieldCGearWork *work, u32 active);
/* Unprototyped on purpose: the caller passes the work pointer as a third argument; a two-parameter prototype changes the bytes. */
int func_021F29D8();

u32 func_021A10D4(FieldCGearWork *work) { return func_021F2980((u32)work->cgear); }


u32 ov021_func_021A10E0(FieldCGearWork *work, u32 active)
{
    u32 gameSystem, savedValue;
    if (active != 0) {
        gameSystem = (u32)func_02188C80(work->fieldSystem);
        savedValue = (u32)func_02009210(func_02012EBC(func_020120F4((const struct GameSystem *)gameSystem)));
        if (func_02012204((const struct GameSystem *)gameSystem) != 0) {
            if (func_0201214C((const struct GameSystem *)gameSystem) != 0) {
                func_02012210((struct GameSystem *)gameSystem);
            } else if (func_021F2994((int *)work->cgear) != 0) {
                func_02009200(savedValue, 0);
                func_02012210((struct GameSystem *)gameSystem);
            }
        }
    }
    return func_021F2848((u32)work->cgear, active);
}

int func_021A1138(FieldCGearWork *work, int button)
{
    return func_021F29D8(work->cgear, button, work);
}
