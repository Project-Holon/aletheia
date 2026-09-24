/*
 * function: func_021D85F4
 * address:  0x021D85F4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH (parked)
 *
 * BLOCKER: 31 bytes: two residues.  (a) the 0xff at +0xc is materialised in the image as subs r0,r2,#2 from the 1 in r2, mwcc folds it to movs r0,#0xff; that also flips the record pointer from r2 to r1 for the rest of the body.  (b) the func_021C8120 result is copied through r4 before the copy loop.
 *
 * symbols:
 *   func_021D85F4   0x021D85F4  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7D00   0x021C7D00  thumb ov093
 *   func_021C8120   0x021C8120  thumb ov093
 *   func_021C7F68   0x021C7F68  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(2); the func_021C7D00(b,c) word gets bit 8 set and is
 * pared with func_021C8120(b,6) into func_021C7F68, whose result is both the
 * copy length and the +0xf byte of record #0xe.  The bytes of
 * func_021C8120(b,6) are copied to +0x10, and a "2"/"3" event pair brackets it.
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
int func_021C7F68(int a, int b, int c);
void func_021C88B4(int a, int k, int b);
void *func_021C88A4(int a, int k, int b);
void func_021C88C8(int a, void *p);

void func_021D85F4(void *a, int b, int c)
{
    void *r;
    void *v;
    u8 *p;
    int w;
    u32 i;

    if (c != func_021D775C(2))
        return;
    r = func_021C7D00(b, c);
    v = (void *)func_021C8120(b, 6);
    w = func_021C7F68(b, (u16)((u32)r | 0x100), (int)v);
    if (w == 0)
        return;
    func_021C88B4(b, 2, c);
    p = func_021C88A4(b, 0xe, c);
    *(u32 *)(p + 4) = 1;
    *(u8 *)(p + 0xc) = 0xff;
    *(u8 *)(p + 0xe) = 1;
    *(u8 *)(p + 0xf) = w;
    for (i = 0; i < (u32)w; i++)
        *(u8 *)(p + 0x10 + i) = ((u8 *)v)[i];
    func_021C88C8(b, p);
    func_021C88B4(b, 3, c);
}
