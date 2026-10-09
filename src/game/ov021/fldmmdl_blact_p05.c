/*
 * file:     fldmmdl_blact_p05.c
 * unit:     yes
 * function: func_0219DB0C, func_0219DB44, func_0219DB48, func_0219DB5C, func_0219DBC8, func_0219DC08, func_0219DC18, func_0219DC28
 * address:  0x0219DB0C
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021AC578  0x021AC578  thumb  ov021
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_021AC2C0(u32, u32);
extern void *func_0216D568(void *p, u32 v);
extern u32 func_021AC578(u32, u32);
extern int func_0216DC34(void *a0);
extern u16 func_021AB0F8(u32 attr);
extern int func_02163F40(int a, int dir);
extern int func_0216DC18(void *a0, int a1);
extern void func_021BBFB8(u32, u32, u32, u32);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_0216D7CC(u32, u32, u32, u32);
void func_0219DB0C(u32 a, u32 a1, u32 a2, u32 a3);
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3);
int func_0219DB48(u32 a, u32 b, u32 c, u32 d);
void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);
void func_0219DBC8(void *a, u32 b, u32 c, u8 *d);
int func_0219DC08(u32 a);
int func_0219DC18(u32 a, u32 b, u32 c, u32 d);
int func_0219DC28(u32 a, u32 b, u32 c, u32 d);





/*
 * Addresses are Black-image addresses.
 */
void func_0219DB0C(u32 a, u32 a1, u32 a2, u32 a3)
{
    if (func_0216D98C((int)func_0216D67C((void *)a)) != 0) {
        if (func_0216D57C((void *)a, 0x4000) == 0) {
            func_021AC2C0(a, func_0219DC08(a));
            func_0216D568((void *)a, 0x4000);
        }
    }
}






/*
 * An empty function.
 */
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3)
{
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DB48(u32 a, u32 b, u32 c, u32 d)
{
return func_021AC578(a, func_0219DC08(a));
}





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





int func_0219DC08(u32 a)
{
return func_02188CD0((u8 *)func_0216D534((void *)func_0216D67C((void *)a)));
}



int func_0219DC18(u32 a, u32 b, u32 c, u32 d)
{
func_0216D568((void *)a, (1 << 10));
return 0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DC28(u32 a, u32 b, u32 c, u32 d)
{
func_0216D7CC(a, b, c, d);
return 1;
}
