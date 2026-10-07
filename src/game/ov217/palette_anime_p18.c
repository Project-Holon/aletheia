/*
 * file:     palette_anime_p18.c
 * unit:     yes
 * function: func_021C2B10, func_021C2B80
 * address:  0x021C2B10
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
 *   d_020A1B38 0x020A1B38 data a2
 *   _u32_div_f 0x0209C2B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_02021F64 0x02021F64 thumb
 */
#include "../../matched/include/Obj00115.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Rgb555 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

extern void func_02021F64(u16 *,u16 *,u32,u8,u16);
void func_021C2B10(u8 *p);
void func_021C2B80(u8 *p);
extern const short d_020A1B38[];

/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse value for value*3/32, retaining the dying local's register.
 */
void func_021C2B10(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/30u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*3/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}

/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse the byte local for the scaled value.
 */
void func_021C2B80(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/90u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*3/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}
