/*
 * file:     fldmmdl_blact_p15.c
 * unit:     yes
 * function: func_0219DB5C, func_0219DBC8, func_0219DC08
 * address:  0x0219DB5C
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
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216DC34(void *a0);
extern u16 func_021AB0F8(u32 attr);
extern int func_02163F40(int a, int dir);
extern void *func_0216D67C(void *a0);
extern int func_0216DC18(void *a0, int a1);
extern void func_021BBFB8(u32, u32, u32, u32);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);
void func_0219DBC8(void *a, u32 b, u32 c, u8 *d);
int func_0219DC08(u32 a);


/*
 * Addresses are Black-image addresses.
 */
void func_0219DB5C(void *a, u32 b, u32 c, u8 *d)
{
    u32 m;
    u32 e;
    u32 f;
    if (d[6] != 0 && func_0216DC34((void *)a) == 0) {
        m = -1;
        if (b != -1) {
            if (func_021AB0F8(b) & 0x40) {
                m = b;
            } else {
                b = func_02163F40((int)a, 1);
                if (func_021AB0F8(b) & 0x40) {
                    m = b;
                }
            }
            if (m != -1) {
                e = func_0219DC08((u32)a);
                f = (u32)func_0216D67C((void *)a);
                func_0216DC18(a, 1);
                func_021BBFB8(f, (u32)a, e, 1);
            }
        }
    }
}


void func_0219DBC8(void *a, u32 b, u32 c, u8 *d)
{
    int r;
    if (d[6] != 0 && func_0216DC34((void *)a) != 0) {
        r = func_02163F40((int)a, 1);
        if (r == -1) {
            func_0216DC18(a, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(a, 0);
        }
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DC08(u32 a)
{
return func_02188CD0((u8 *)func_0216D534((void *)func_0216D67C((void *)a)));
}
