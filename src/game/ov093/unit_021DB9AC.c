/*
 * file:     unit_021DB9AC.c
 * unit:     yes
 * function: func_021DB9AC, func_021DB9B8, func_021DB9D0, func_021DB9DC, func_021DBA00, func_021DBA0C, func_021DBA74, func_021DBA80, func_021DBAE4
 * address:  0x021DB9AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F06F8 0x021F06F8 data a4
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   d_021F06E8 0x021F06E8 data a4
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_021F06F0     0x021F06F0  data   ov093  a4
 *   func_021C8234  0x021C8234  thumb  ov093
 *   d_021F06E0     0x021F06E0  data   ov093  a4
 *   d_021F06D8     0x021F06D8  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C7D00(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C8234(u8 *p, int i);
int *func_021DB9AC(int *p);
void func_021DB9B8(int a, int b, int c);
int *func_021DB9D0(int *p);
void func_021DB9DC(int a,int b,int c);
int *func_021DBA00(int *p);
void func_021DBA0C(int a, int p, int x);
int *func_021DBA74(int *p);
void func_021DBA80(int a, int p, int x);
int *func_021DBAE4(int *p);
extern int d_021F06F8;
extern int d_021F06E8;
extern int d_021F06F0[];
extern int d_021F06E0[];
extern int d_021F06D8[];



int *func_021DB9AC(int *p) { *p=1; return &d_021F06F8; }




/* 021DB9B8  shape F1: gate on func_021D775C(4) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #4; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DB9CE; movs r0, #0x51; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DB9B8(int a, int b, int c)
{
    if (c == func_021D775C(4))
        func_021D76BC(0x51, 0);
}



int *func_021DB9D0(int *p)
{
    *p = 1;
    return d_021F06F0;
}



void func_021DB9DC(int a,int b,int c) { if(c==func_021D775C(3) && (unsigned char)func_021D775C(0x25)==0) func_021D76BC(0x26,10); }



int *func_021DBA00(int *p) { *p=1; return &d_021F06E8; }




void func_021DBA0C(int a, int p, int x)
{
    u8 buf[4];
    u32 n;
    u8 i;

    if (func_021B9A24((u8)func_021D775C(2), (int)x) == 0) {
        n = func_021C7F68((int *)p, (u16)(func_021C7D00((u8 *)p, x) | 0x100), buf);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(func_021C7CF4((int *)p, buf[i]), 0x11) == 0x17)
                return;
        }
        func_021D76BC(0x41, 1);
    }
}


int *func_021DBA74(int *p)
{
    *p = 1;
    return d_021F06E0;
}


void func_021DBA80(int a, int p, int x)
{
    u8 buf[4];
    u32 n;
    u8 i;

    if (func_021B9A24((u8)func_021D775C(2), x) == 0) {
        n = func_021C7F68((int *)p, (u16)(func_021C7D00((u8 *)p, x) | 0x100), buf);
        for (i = 0; i < n; i++) {
            if (func_021C8234((u8 *)p, buf[i]) == 0) {
                func_021D76BC(0x41, 1);
                return;
            }
        }
    }
}


int *func_021DBAE4(int *p)
{
    *p = 1;
    return d_021F06D8;
}
