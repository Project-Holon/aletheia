/*
 * file:     dwc_rap_p18.c
 * unit:     yes
 * function: func_02156B18, func_02156B3C, func_02156B68
 * address:  0x02156B18
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   func_02155D2C 0x02155D2C thumb ov009
 *   func_021AF210 0x021AF210 thumb ov013
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef void (*Callback)(u16, int);

extern void func_02155D2C(int);
extern int func_021AF210(void);
void func_02156B18(int a, int b, int c, int d, int e);
void func_02156B3C(int a);
int func_02156B68(char *a0);
extern u8 *g_021A8264;

/*
 * The fifth input is visibly loaded into r0 before the call.
 */
void func_02156B18(int a, int b, int c, int d, int e)
{
    *(int *)(g_021A8264 + 0x778) = 0;
    if (a == 0 && b == 0)
        func_02155D2C(e);
}

/*
 * Extent follower 02156B68 already has its own matched file.
 */
void func_02156B3C(int a)
{
    *(int *)(g_021A8264 + 0x774) = a;
    if (*(Callback *)(g_021A8264 + 0x29c) != 0)
        (*(Callback *)(g_021A8264 + 0x29c))((u16)a, *(int *)(g_021A8264 + 0x2a0));
}

/*
 * extent: 8-byte thunk; larger accessor followers 02156B70 and 02156B8C excluded.
 */
int func_02156B68(char *a0)
{
    return func_021AF210();
}
