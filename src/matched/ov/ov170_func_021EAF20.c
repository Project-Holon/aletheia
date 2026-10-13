/*
 * function: func_021EAF20
 * address: 0x021EAF20
 * packet: pkt_ov170_021EAF20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   func_021EABA0 0x021EABA0 thumb ov170
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 */
#include "../include/Obj08243.h"
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void func_021EABA0(void **);
extern void func_021EAAE4(unsigned char *p, unsigned i);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
void func_021EAF20(char *p, Entry *e, unsigned i)
{
    BMP_Clear(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            func_021EABD0((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 95, 0, 0, ((struct Obj08243 *)p)->f78, 0x14c0);
        } else if (e->kind == 1) {
            func_021EABD0((unsigned char *)p, i, ((struct Obj08243 *)p)->f80, 96, 0, 0, ((struct Obj08243 *)p)->f78, 0xc80);
        } else {
            func_021EAAE4((unsigned char *)p, i); return;
        }
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}
