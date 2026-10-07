/*
 * file:     fld_trade_p07.c
 * unit:     yes
 * function: func_021CD1AC, func_021CD1C8, func_021CD1F0, func_021CD204
 * address:  0x021CD1AC
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
 *   func_021CD038  0x021CD038  thumb  ov021
 *   func_021CCBE0  0x021CCBE0  thumb  ov021
 *   func_021CCE48  0x021CCE48  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE5D4  0x021DE5D4  data  ov021
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204932C  0x0204932C  arm
 */
#include "../../matched/include/Obj18362.h"

struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    void *arc;
} Holder_021CD1C8;

typedef struct {
    void *arc;
    u32 f4;
} Holder_021CD204;

extern void func_021CCBE0(u8 *s, int flag);
extern u32 func_021CCE48(u32, u32);
extern u32 func_021CD038(u32, u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void func_02049238(u32 arc);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
int func_021CD1AC(u32 a, u32 b, u32 c, u32 d);
Holder_021CD1C8 *func_021CD1C8(u32 heap);
int func_021CD1F0(void *a);
void func_021CD204(Holder_021CD204 *h, u32 a);
extern const char d_021DE5D4[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CD1AC(u32 a, u32 b, u32 c, u32 d)
{
func_021CD038(a, b, c, d);
func_021CCBE0((u8 *)a, 2);
return func_021CCE48(a, 2);
}


/*
 * Allocates a 0x28-byte zeroed holder on the given heap and opens archive 0xAF into its first word.
 *
 * Addresses are Black-image addresses.
 */
Holder_021CD1C8 *func_021CD1C8(u32 heap)
{
    Holder_021CD1C8 *h = func_02030734(heap, 0x28, 1, d_021DE5D4, 0x5b);
    h->arc = func_020490F4(0xaf, heap);
    return h;
}


int func_021CD1F0(void *a)
{
func_02049238(((struct Obj18362 *)((u8 *)(a)))->f0);
return func_020307B0(a);
}


/*
 * Forwards to func_0204932C with the holder's archive, the caller's argument and the holder's +4 field.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD204(Holder_021CD204 *h, u32 a)
{
    func_0204932C(h->arc, a, &h->f4);
}
