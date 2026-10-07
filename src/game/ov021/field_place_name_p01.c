/*
 * file:     field_place_name_p01.c
 * unit:     yes
 * function: func_021BBF78, func_021BBF9C
 * address:  0x021BBF78
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
 *   d_021DE320     0x021DE320  data  a4
 *   func_021BBFB0  0x021BBFB0  thumb  ov021
 *   func_021BBFB4  0x021BBFB4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
typedef struct {
    int f0;
} Obj;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_021BBFB0(void);
extern void func_021BBFB4(void *p);
extern u32 func_020307B0(void *p);
Obj *func_021BBF78(int a, int b);
void func_021BBF9C(u32 a, u8 *p);
extern int d_021DE320;


Obj *func_021BBF78(int a, int b)
{
    Obj *q = func_02030734(b, 4, 1, (const char *)&d_021DE320, 0x78);

    q->f0 = a;
    func_021BBFB0();
    return q;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBF9C(u32 a, u8 *p)
{
    func_021BBFB4(p);
    func_020307B0(p);
}
