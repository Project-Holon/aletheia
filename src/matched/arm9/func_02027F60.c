/*
 * function: APP_TASKMENU_RES_Create
 * address:  0x02027F60
 * packet:   pkt_02027F60
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_020275E4   0x020275E4  thumb
 *   func_02049DB4   0x02049DB4  arm
 *   func_02049B40   0x02049B40  arm
 *   app_taskmenu_File  0x020A74E0  data
 *
 * Allocate and zero a 0x18-byte record ("app_taskmenu.c", line 0x2c6) and
 * fill it: two u16 ids at +0/+2, two words at +0x10/+0x14, then two
 * resources from the 0x02049xxx loader keyed by func_020275E4()'s handle.
 *
 * The 30-byte residue the earlier notes read as an allocation tie was the
 * callees' argument lists: func_020275E4()'s result is the FIRST argument
 * of func_02049DB4 and func_02049B40 (r0 is never reloaded between the bl
 * and the blx), so the constants 0x20 / 0x1f are the second argument, and
 * func_02049B40 takes (h, 0x1f, sel, a1 << 5, 0x40, heap) -- six arguments
 * with the heap id last.  Written that way the heap parameter needs no
 * address-taken pointer; it is an ordinary fifth (stack) parameter.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32   func_020275E4(void);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern const char app_taskmenu_File[];

struct R {
    u16 a;
    u16 b;
    u32 f04;
    u32 obj;
    u32 pad0c;
    u32 c;
    u32 d;
};

struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap)
{
    struct R *r;
    u32 sel;

    sel = 0;
    r = (struct R *)func_02030734(heap, 0x18, 0, app_taskmenu_File, 0x2c6);
    MI_CpuFill8(r, 0, 0x18);
    r->a = a0;
    r->b = a1;
    r->c = a2;
    r->d = a3;
    if (a0 > 3) {
        sel = 4;
    }
    r->obj = (u32)func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&r->f04), heap);
    func_02049B40(func_020275E4(), 0x1f, sel, a1 << 5, 0x40, heap);
    return r;
}
