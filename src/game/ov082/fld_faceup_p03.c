/*
 * file:     fld_faceup_p03.c
 * unit:     yes
 * function: func_021F56C0, func_021F56D8, func_021F56E4, func_021F56FC
 * address:  0x021F56C0
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020416D4 0x020416D4 arm
 *   func_02043658  0x02043658  arm
 *   func_0204047C 0x0204047C arm
 *   func_02043534  0x02043534  arm
 */
typedef unsigned char u8;

typedef unsigned int   u32;

extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
extern void func_0204047C(int idx, unsigned short val);
void func_02043534(u32 planes);
void func_021F56C0(u8 *p);
void func_021F56D8(int *p);
void func_021F56E4(u8 *p);
void func_021F56FC(int *p);

void func_021F56C0(u8 *p) { int i; for(i=0;i<4;i++) p[i]=func_020416D4((u8)i); }


void func_021F56D8(int *p)
{
    p[1] = func_02043658();
}

void func_021F56E4(u8 *p) { int i; for(i=0;i<4;i++) func_0204047C((u8)i,p[i]); }


void func_021F56FC(int *p)
{
    func_02043534(p[1]);
}
