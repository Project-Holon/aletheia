/*
 * file:     field_msgbg_p11.c
 * unit:     yes
 * function: func_0218BB64, func_0218BB78, func_0218BBD0, func_0218BBF4, func_0218BC00, func_0218BC10, func_0218BC1C
 * address:  0x0218BB64
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
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218B924  0x0218B924  thumb  ov021
 */
#include "../../matched/include/Obj01114.h"
#include "../../matched/include/Obj00572.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    unsigned char pad[0x1C];
    unsigned char arr[0x190];
    unsigned short n;
} S;

extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_0218B924(u8 *p, u32 a1);
int func_0218BB64(char *a);
void func_0218BB78(u8 *s, int k);
int func_0218BBD0(S *p, unsigned int i);
int func_0218BBF4(u32 a, u32 b);
char *func_0218BC00(char *p, int i);
u8 *func_0218BC10(u8 *a, int b);
unsigned short func_0218BC1C(int x);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218BB64(char *a)
{
func_020307B0((void *)(((struct Obj01114 *)((u8 *)(a)))->f18));
*(u16 *)((u8 *)(a) + ((107 << 2))) = 0;
return (107 << 2);
}


void func_0218BB78(u8 *s, int k)
{
    u8 i;
    u8 v;
    int j;

    func_02082BCC(s + 0x1c, 0x80, 0x190);
    for (i = 0; i < ((struct Obj00572 *)s)->f1AC; i++)
        s[*((u16 *)func_0218B924(s, i)) + 0x1c] = i;
    v = (s + k)[0x1c];
    for (j = 0; j < 0x190; j++) {
        if (s[j + 0x1c] == 0x80)
            s[j + 0x1c] = v;
    }
}


int func_0218BBD0(S *p, unsigned int i)
{
    unsigned char v;
    if (i >= 0x190)
        i = 0;
    v = p->arr[i];
    if (v >= 0x80 || v >= p->n)
        v = 0;
    return v;
}


int func_0218BBF4(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 2))) + 4));
}

/*
 * Leaf: offset-table walk.  p[2] is a byte count; the table starts at p+4,
 * each entry a 32-bit relative offset.  Returns p + entry[i + (p[2]>>1)].
 * Callee of func_0218B8AC.
 */
char *func_0218BC00(char *p, int i)
{
    unsigned n = (unsigned char)p[2];
    return p + *(int *)(p + 4 + ((n >> 1) + i) * 4);
}


u8 *func_0218BC10(u8 *a, int b)
{
return (a + *(u32 *)((u8 *)((a + (b << 2))) + 4));
}

/*
 * Value remap: x >= 0xd2 maps to x-0xd2, x in [2,0xd2) maps to (x-2)/4,
 * x < 2 maps to 0.  The unsigned range tests force `blo` while the division
 * stays signed.  Callee of func_0218B8AC.  EXACT* (follower 0x0218BC40).
 */
unsigned short func_0218BC1C(int x)
{
    if ((unsigned)x >= 0xd2)
        return (unsigned short)(x - 0xd2);
    if ((unsigned)x >= 2)
        return (unsigned short)((x - 2) / 4);
    return 0;
}
