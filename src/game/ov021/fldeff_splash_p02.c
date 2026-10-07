/*
 * file:     fldeff_splash_p02.c
 * unit:     yes
 * function: func_021C4978, func_021C49AC
 * address:  0x021C4978
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
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_021C49C0  0x021C49C0  thumb  ov021
 *   d_021DE47C     0x021DE47C  data  ov021
 *   func_021C4A00  0x021C4A00  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
struct P;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

typedef unsigned short u16;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern void func_021C49C0(struct P *p);
extern void func_021C4A00(void *p);
extern u32 func_020307B0(void *p);
R *func_021C4978(u8 *owner, u32 heap);
void func_021C49AC(u32 a, u8 *p);
extern char d_021DE47C[];


/*
 * Allocates the 0xC-byte field-object record (second kind) and initialises
 * it.
 */
R *func_021C4978(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, d_021DE47C, 0x7D);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C49C0((struct P *)r);
    return r;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C49AC(u32 a, u8 *p)
{
    func_021C4A00(p);
    func_020307B0(p);
}
