/*
 * function: func_021BF4E8
 * address: 0x021BF4E8
 * packet: pkt_ov204_021BF4E8
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing two bytes are zero alignment padding.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj10880.h"
#include "../include/Obj14623.h"

extern void func_0201F7A8(void *, unsigned int);
typedef unsigned short u16;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct Obj;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
typedef unsigned int   u32;
extern u32 BMP_MENUWORK_Delete(void *p);
extern void func_02082BCC(void *, int, unsigned int);

void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    func_0201F7A8(((struct Obj10880 *)p)->f38, 0);
    BMP_Clear(func_02045770(((struct Obj10880 *)p)->f38), 0);
    BMP_WIN_TransferChars(((struct Obj10880 *)p)->f38);
    BMP_MENULIST_Delete(((struct Obj14623 *)block)->f0, 0, 0);
    BMP_MENUWORK_Delete(((struct Obj14623 *)block)->f4);
    func_02082BCC(block, 0, 12);
}
