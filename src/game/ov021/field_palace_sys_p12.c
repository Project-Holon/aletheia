/*
 * file:     field_palace_sys_p12.c
 * unit:     yes
 * function: func_021D3164, func_021D317C, func_021D31A4
 * address:  0x021D3164
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
 *   d_021DE6C8     0x021DE6C8  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern u32 func_020307B0(void *p);
void func_021D3164(u32 *p);
void *func_021D317C(u32 heap);
void func_021D31A4(u32 a);
extern char d_021DE6C8[];


void func_021D3164(u32 *p)
{
    if (((u32 *)p[2])[1] == 0) {
        *(u16 *)p[3] = 0;
    } else {
        *(u16 *)p[3] = 1;
    }
}


void *func_021D317C(u32 heap)
{
    u8 *p = func_02030734(heap, 0x38, 1, d_021DE6C8, 0x80);

    func_02082BCC(p + 0x2c, 0xff, 8);
    return p;
}


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021D31A4(u32 a)
{
    func_020307B0((void *)a);
}
