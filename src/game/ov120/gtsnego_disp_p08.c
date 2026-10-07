/*
 * file:     gtsnego_disp_p08.c
 * unit:     yes
 * function: func_021D4F98, func_021D4FC0
 * address:  0x021D4F98
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012F14 0x02012F14 thumb
 *   func_02009E8C 0x02009E8C thumb
 *   func_02009E54 0x02009E54 thumb
 *   func_021D588C  0x021D588C  thumb
 *   func_020435F4  0x020435F4  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void *func_02012F14(void **);
extern int func_02009E8C(void *);
extern void *func_02009E54(void *,int);
extern void func_021D588C(u8 *p);
extern void func_020435F4(u32 planes);
void *func_021D4F98(void **p,int i);
void func_021D4FC0(u8 *p);

void *func_021D4F98(void **p,int i) { int n; n=func_02009E8C(func_02012F14(p)); if (i<0) i=0; if (i>=n) i=n-1; return func_02009E54(func_02012F14(p),i); }


/*
 * Addresses are Black-image addresses.
 */
void func_021D4FC0(u8 *p)
{
    func_021D588C(p);
    func_020435F4(0x1f);
}
