/*
 * file:     weather_task_p78.c
 * unit:     yes
 * function: func_021A66E4, func_021A66EC, func_021A66F8, func_021A6708, func_021A6714, func_021A6720, func_021A672C, func_021A6738, func_021A6744, func_021A6750, func_021A675C, func_021A6768, func_021A6774, func_021A6780
 * address:  0x021A66E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
} S;

void func_021A66E4(u32 *p, u32 v);
void func_021A66EC(u32 *p, u32 v);
int func_021A66F8(S *a, int m);
void func_021A6708(void *a);
void func_021A6714(void *a);
void func_021A6720(void *a);
void func_021A672C(void *a);
void func_021A6738(void *a);
void func_021A6744(void *a);
void func_021A6750(void *a);
void func_021A675C(void *a);
void func_021A6768(void *a);
void func_021A6774(void *a);
void func_021A6780(void *a);


/*
 * Unlabelled leaf: sets bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66E4(u32 *p, u32 v)
{
    p[1] |= v;
}


/*
 * Unlabelled leaf: clears bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66EC(u32 *p, u32 v)
{
    p[1] &= ~v;
}


int func_021A66F8(S *a, int m)
{
    if (a->f4 & m) {
        return 1;
    }
    return 0;
}


/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6708(void *a)
{
    func_021A66E4(a, 1);
}


void func_021A6714(void *a)
{
    func_021A66EC(a, 1);
}


/*
 * Tail-call thunk: pins the second argument to 2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6720(void *a)
{
    func_021A66E4(a, 2);
}


void func_021A672C(void *a)
{
    func_021A66EC(a, 2);
}


/*
 * Tail-call thunk: pins the second argument to 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6738(void *a)
{
    func_021A66EC(a, 4);
}


/*
 * Tail-call thunk: pins the second argument to 8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6744(void *a)
{
    func_021A66E4(a, 8);
}


void func_021A6750(void *a)
{
    func_021A66EC(a, 8);
}


/*
 * Tail-call thunk: pins the second argument to 16.
 *
 * Addresses are Black-image addresses.
 */
void func_021A675C(void *a)
{
    func_021A66E4(a, 16);
}


void func_021A6768(void *a)
{
    func_021A66EC(a, 16);
}


/*
 * Tail-call thunk: pins the second argument to 32.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6774(void *a)
{
    func_021A66E4(a, 32);
}


void func_021A6780(void *a)
{
    func_021A66EC(a, 32);
}
