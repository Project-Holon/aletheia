/*
 * unit:     no
 * function: func_0202EE30
 * address:  0x0202EE30
 * packet:   pkt_0202EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and fills the 0x1c-byte time_icon record.  The heap id is the
 * fifth (stack) argument and is re-read from its slot for the second use
 * (it is also what func_0202EECC's u16 tail parameter receives), so it is
 * spelled `volatile u16`.  When the optional owner a0 is non-null the
 * record is registered with func_02030DA8 against the tag 0x0202F099 and
 * that call's result lands at +0; otherwise +0 is zeroed.
 *
 * Sibling of func_0202EE8C (docs/notes/pkt_0202EE0C.c.txt), which builds
 * the same record through the func_020311B8 allocator instead.
 *
 * symbols:
 *   g_020A7814     0x020A7814  data
 *   unk_0202F099   0x0202F099  data
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_0202EECC  0x0202EECC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char g_020A7814[];
extern u8   unk_0202F099[];

extern void *func_02030734(u16 heap, u32 size, u32 a2, char *file, u32 line);
extern u32   func_02030DA8(void *owner, u8 *tag, void *p, u32 a3);
extern void  func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);

u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap)
{
    u8 *p;

    p = (u8 *)func_02030734(heap, 0x1c, 0, g_020A7814, 0x49);
    func_0202EECC(p, a1, a2, a3, heap);
    if (owner != 0) {
        *(u32 *)p = func_02030DA8(owner, unk_0202F099, p, 0);
    } else {
        *(u32 *)p = 0;
    }
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0x18) = 1;
    return p;
}
