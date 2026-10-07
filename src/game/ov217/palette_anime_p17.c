/*
 * file:     palette_anime_p17.c
 * unit:     yes
 * function: func_021C2A10, func_021C2A18, func_021C2A28, func_021C2A30, func_021C2AA0
 * address:  0x021C2A10
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C2D9C  0x021C2D9C  thumb  ov217
 *   func_021C2B10  0x021C2B10  thumb  ov217
 *   func_021C2B80  0x021C2B80  thumb  ov217
 *   func_021C2BF0  0x021C2BF0  thumb  ov217
 *   func_021C2C30  0x021C2C30  thumb  ov217
 *   func_021C2C70  0x021C2C70  thumb  ov217
 *   func_021C2CB0  0x021C2CB0  thumb  ov217
 *   func_021C2CF0  0x021C2CF0  thumb  ov217
 *   func_021C2D28  0x021C2D28  thumb  ov217
 *   func_021C2D68  0x021C2D68  thumb  ov217
 *   d_020A1B38 0x020A1B38 data a2
 *   _u32_div_f 0x0209C2B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_02021F64 0x02021F64 thumb
 */
#include "../../matched/include/Obj08447.h"
#include "../../matched/include/Obj26035.h"
#include "../../matched/include/Obj00115.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    u32 kind;
} Rec;

struct Rgb555 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

extern u32 func_021C2D9C(u32 *p);
extern void func_021C2B10(u8 *p);
extern void func_021C2B80(u8 *p);
extern void func_021C2BF0(u8 *p);
extern void func_021C2C30(u8 *p);
extern void func_021C2C70(char *p);
extern void func_021C2CB0(char *p);
extern void func_021C2CF0(void *p);
extern void func_021C2D28(char *p);
extern void func_021C2D68(void *p);
extern void func_02021F64(u16 *,u16 *,u32,u8,u16);
void func_021C2A10(u32 a0, u32 a1);
void func_021C2A18(u8 *p, u32 b, u16 c);
void func_021C2A28(void *p);
void func_021C2A30(Rec *p);
void func_021C2AA0(u8 *p);
extern const short d_020A1B38[];


/*
 * Tail-call veneer: forwards its first argument to func_021C2D9C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A10(u32 a0, u32 a1)
{
    func_021C2D9C((u32 *)a0);
}


/*
 * Unlabelled 14-byte ov217 leaf in a .word run; target of the veneer at
 * 0x021C29F8 and the bottom of the func_021BA31C blocker chain.  Store order
 * in the source is +0x14, +0x18, +0x1c, +0x12.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A18(u8 *p, u32 b, u16 c)
{
    ((struct Obj08447 *)p)->f14 = 1;
    ((struct Obj08447 *)p)->f18 = b;
    ((struct Obj08447 *)p)->f1C = 0;
    ((struct Obj08447 *)p)->f12 = c;
}


/*
 * Clear the u32 at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A28(void *p)
{
    ((struct Obj26035 *)p)->f14 = 0;
}


/*
 * Dispatch: after two non-null guards, one of ten handlers is called on the
 * record, chosen by the word at offset 0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A30(Rec *p)
{
    if (p->w4 == 0)
        return;
    if (p->w14 == 0)
        return;
    switch (p->kind) {
    case 0:
        func_021C2AA0((u8 *)p);
        break;
    case 1:
        func_021C2B10((u8 *)p);
        break;
    case 2:
        func_021C2B80((u8 *)p);
        break;
    case 3:
        func_021C2BF0((u8 *)p);
        break;
    case 4:
        func_021C2C30((u8 *)p);
        break;
    case 5:
        func_021C2C70((char *)p);
        break;
    case 6:
        func_021C2CB0((char *)p);
        break;
    case 7:
        func_021C2CF0(p);
        break;
    case 8:
        func_021C2D28((char *)p);
        break;
    case 9:
        func_021C2D68(p);
        break;
    }
}

/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse value for value*10/32, retaining the dying local's register.
 */
void func_021C2AA0(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/60u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*10/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}
