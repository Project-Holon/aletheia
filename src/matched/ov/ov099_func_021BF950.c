/*
 * function: func_021BF950
 * address: 0x021BF950
 * packet: pkt_ov099_021BF950
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer addition spells base + index + 0x24, avoiding indexed strb.
 * symbols:
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C2874 0x021C2874 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 */
#include "../include/Obj03734.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern int func_021C23B8(int i);
extern int func_021C2874(void *);
extern int func_021C23C8(void *a, void *b);
extern void func_021BDE30(void *p, int kind, int value);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C19DC(char *, int);
extern void func_021BA874(char *, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BC090(char *);
int func_021BF950(char *p, int ret)
{
    int i = ((struct Obj03734 *)p)->f242 - 1;
    if (GFL_USE_IsSeSlotBusy(0)) return ret;
    *(*(u8 * *)&((struct Obj03734 *)p)->f248 + i + 0x24) = func_021C2874((void *)func_021C23B8(i));
    if (i >= 0 && i < 32 && func_021C23C8(p, (void *)i)) {
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        func_021BDE30(p, 4, 3);
        func_021C18C8(p, 4, 3);
        func_021C19DC(p, 0x21);
        func_021BA874(p, i);
        ((struct Obj03734 *)p)->f1C4 = 0xe10;
        func_021BAADC(p, 0x5e, 0);
        func_021BC090(p);
        ((struct Obj03734 *)p)->f1CC = 0x25;
        ((struct Obj03734 *)p)->f1350 = ((struct Obj03734 *)p)->f242;
        return ret;
    }
    ((struct Obj03734 *)p)->f1CC = 0xb;
    return ret;
}
