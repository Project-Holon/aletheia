/*
 * function: func_02026728
 * address:  0x02026728
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_020272EC  0x020272EC  thumb
 *   func_02026824  0x02026824  thumb
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Obj;

extern char *g_02146940;

extern int  func_0203CD98(void);
extern void *func_02012FCC(u32 game);
struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);
extern void func_020272EC(s32 a);
extern void func_02026824(struct Obj *o);

void func_02026728(void)
{
    char *p;
    s32 v;
    s32 i;

    p = g_02146940;
    if (p == 0) {
        return;
    }
    if (func_0203CD98() == 0) {
        return;
    }
    if (*(u32 *)p != 0) {
        v = func_0200864C(func_02012FCC(*(u32 *)p));
        if (*(u16 *)(p + 0xbb0) != v) {
            switch (v) {
            case 0xa:
            case 0x1e:
            case 0x32:
            case 0x64:
                func_020272EC(v);
                break;
            }
        }
        *(u16 *)(p + 0xbb0) = (u16)v;
    }
    func_02026824((struct Obj *)(p + 4));
    for (i = 0; i < 0x1e; i++) {
        if (*(u8 *)(p + i * 0x60 + 0x64) != 0) {
            if (*(u16 *)(p + i * 0x60 + 0xc0) < 0xffff) {
                *(u16 *)(p + i * 0x60 + 0xc0) += 1;
            }
        }
    }
}
