/*
 * file:     c_gear_p09.c
 * unit:     yes
 * function: func_021F2984, func_021F2994
 * address:  0x021F2984
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F26E0 0x021F26E0 thumb ov029
 *   func_020307B0 0x020307B0 arm
 *   func_0202223C  0x0202223C  thumb
 *   func_02022230  0x02022230  thumb
 *   func_021F251C  0x021F251C  thumb  ov029
 *   func_021F2180  0x021F2180  thumb  ov029
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021F26E0(char *p);
extern u32 func_020307B0(void *p);
extern void func_0202223C(u32 a, u32 color);
extern void func_02022230(u32 which);
extern void func_021F251C(u8 *p, int a1, int a2, int a3, int e);
extern void func_021F2180(char *p);
void func_021F2984(char *p);
int func_021F2994(int *p);

void func_021F2984(char *p)
{
    func_021F26E0(p);
    func_020307B0((void *)((int)p));
}


int func_021F2994(int *p)
{
    int a = p[8];
    int b = p[6];
    int c = p[7];

    if (p[0] == (int)func_021F2180) {
        func_0202223C(1, 0);
        func_021F26E0((char *)p);
        func_021F251C((u8 *)p, a, b, c, 0);
        func_02022230(1);
        return 1;
    }
    return 0;
}
