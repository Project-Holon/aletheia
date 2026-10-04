/*
 * function: func_021D9D44
 * address:  0x021D9D44
 * packet:   pkt_ov129_021D9D44
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s16 x;
    s16 y;
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} L;

struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B404(int, void *, int);
extern void func_0204B878(int, int);

void func_021D9D44(char *p)
{
    L s;
    int h = *(int *)(p + 0x25C);
    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 10;
    s.e = 0;
    *(int *)(p + 0x1E8) = (int)func_0204B294((void *)h, *(int *)(p + 0x270), *(int *)(p + 0x264), *(int *)(p + 0x288), &s.a, 0, 0x32);
    *(int *)(p + 0x204) = (int)func_0204B294((void *)h, *(int *)(p + 0x270), *(int *)(p + 0x264), *(int *)(p + 0x288), &s.a, 0, 0x32);
    s.x = (*(u8 *)(p + 0x2F2) + *(u8 *)(p + 0x2F3)) / 2;
    s.y = (*(u8 *)(p + 0x2F0) + *(u8 *)(p + 0x2F1)) / 2;
    func_0204B404(*(int *)(p + 0x1E8), &s, 0);
    func_0204B878(*(int *)(p + 0x1E8), 0);
    s.x = (*(u8 *)(p + 0x2F6) + *(u8 *)(p + 0x2F7)) / 2;
    s.y = (*(u8 *)(p + 0x2F4) + *(u8 *)(p + 0x2F5)) / 2;
    func_0204B404(*(int *)(p + 0x204), &s, 0);
    func_0204B878(*(int *)(p + 0x204), 0);
}
