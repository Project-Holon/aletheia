/*
 * function: func_021D85F4
 * address:  0x021D85F4
 * packet:   pkt_ov093_021D85F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * lever: -1 is a signed store (subs from the shared 1); p is declared last.
 * symbols:
 *   func_021D85F4  0x021D85F4  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7D00(int a, int b);
int func_021C8120(int a, int b);
int func_021C7F68(int *p, int b, u8 *out);
void func_021C88B4(void *a, int k, int b);
void *func_021C88A4(int a, int k, int b);
void func_021C88C8(void *a, void *b);

void func_021D85F4(void *a, int b, int c)
{
    void *r;
    void *v;
    int w;
    u32 i;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    r = func_021C7D00(b, c);
    v = (void *)func_021C8120(b, 6);
    w = func_021C7F68((int *)b, (u16)((u32)r | 0x100), (u8 *)((int)v));
    if (w == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4(b, 0xe, c);
    *(u32 *)(p + 4) = 1;
    *(s8 *)(p + 0xc) = -1;
    *(u8 *)(p + 0xe) = 1;
    *(u8 *)(p + 0xf) = w;
    for (i = 0; i < (u32)w; i++)
        *(u8 *)(p + 0x10 + i) = ((u8 *)v)[i];
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}
