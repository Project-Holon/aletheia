/*
 * file:     bsubway_scr_p15.c
 * unit:     yes
 * function: func_021C94BC, func_021C94E0
 * address:  0x021C94BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DE578  0x021DE578  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021C94F4  0x021C94F4  thumb  ov021
 *   func_021C952C  0x021C952C  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021C94F4(u32 *q);
extern void func_021C952C(void *p);
u32 *func_021C94BC(u32 a, u32 heap);
void func_021C94E0(u32 a, u8 *p);
extern char d_021DE578[];

u32 *func_021C94BC(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x1c, 1, d_021DE578, 0x66);
    q[0] = a;
    func_021C94F4(q);
    return q;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C94E0(u32 a, u8 *p)
{
    func_021C952C(p);
    func_020307B0(p);
}
