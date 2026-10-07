/*
 * file:     field_msgbg_p37.c
 * unit:     yes
 * function: func_0218E58C, func_0218E5A0, func_0218E5B8, func_0218E5D0
 * address:  0x0218E58C
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
 *   d_021D3E44  0x021D3E44  data  ov021  a4
 *   func_0218E284  0x0218E284  thumb  ov021
 *   func_0218E358  0x0218E358  thumb  ov021
 *   func_0218E540  0x0218E540  thumb  ov021
 *   func_0218E298  0x0218E298  thumb  ov021
 *   func_0218E404  0x0218E404  thumb  ov021
 *   func_0218E4B0  0x0218E4B0  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef void (*StateFunc)(void *a, u32 b);

extern void func_0218E284(u8 *a);
extern void func_0218E358(u8 *a);
extern u32 func_0218E540(u32);
extern int func_0218E298(u8 *a);
extern void func_0218E404(u8 *a);
extern void func_0218E4B0(u8 *a);
void func_0218E58C(u8 *a, u32 b);
int func_0218E5A0(u32 a, u32 b, u32 c, u32 d);
int func_0218E5B8(u32 a, u32 b, u32 c, u32 d);
int func_0218E5D0(u32 a, u32 b, u32 c, u32 d);
extern StateFunc d_021D3E44[];


void func_0218E58C(u8 *a, u32 b)
{
    d_021D3E44[*(u32 *)(a + 0x14)](a, b);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218E5A0(u32 a, u32 b, u32 c, u32 d)
{
func_0218E284((u8 *)a);
func_0218E358((u8 *)a);
return func_0218E540(a);
}


int func_0218E5B8(u32 a, u32 b, u32 c, u32 d)
{
func_0218E298((u8 *)a);
func_0218E404((u8 *)a);
return func_0218E540(a);
}


int func_0218E5D0(u32 a, u32 b, u32 c, u32 d)
{
func_0218E284((u8 *)a);
func_0218E298((u8 *)a);
func_0218E4B0((u8 *)a);
return func_0218E540(a);
}
