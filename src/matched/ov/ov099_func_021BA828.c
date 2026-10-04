/*
 * function: func_021BA828
 * address: 0x021BA828
 * packet: pkt_ov099_021BA828
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   data_021C371A 0x021C371A data a2
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinDat;
struct BmpMenu;
extern const struct WinDat data_021C371A;
extern void func_0201DD68(void);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *, u16, u8, u8, u16);
void func_021BA828(char *p)
{
    func_0201DD68();
    *(struct BmpMenu * *)&((struct Obj00008 *)p)->f108 = func_0201FDA0(&data_021C371A, ((struct Obj00008 *)p)->f1334, 14, 0, 0x21);
}
