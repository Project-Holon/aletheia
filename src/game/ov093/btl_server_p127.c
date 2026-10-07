/*
 * file:     btl_server_p127.c
 * unit:     yes
 * function: func_021CD5E0, func_021CD63C
 * address:  0x021CD5E0
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
 *   func_021CCB18  0x021CCB18  thumb  ov093
 *   func_021CCAD4  0x021CCAD4  thumb  ov093
 *   func_021CD0F0  0x021CD0F0  thumb  ov093
 *   func_021CD6AC  0x021CD6AC  thumb  ov093
 *   data_021EFF14  0x021EFF14  data
 *   func_021CCAA8   0x021CCAA8  thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
} Buf;

extern u16 func_021CCB18(void *r);
extern u8 func_021CCAD4(u8 *p);
extern void func_021CD0F0(void *r, int cmd, s32 *a);
extern void func_021CD6AC(void *r, u8 cmd, s32 *a);
extern void func_021CCAA8(void *p, int v);
int func_021CD5E0(Buf *r, s32 *a);
void func_021CD63C(void *p, int v);
extern const u8 data_021EFF14[];


int func_021CD5E0(Buf *r, s32 *a)
{
    int c;
    u8 k;

    c = func_021CCB18(r);
    while (c == 0x5f) {
        r->rpos += func_021CCAD4((u8 *)r);
        if (r->rpos >= r->wpos) {
            return 0x5e;
        }
        c = func_021CCB18(r);
    }
    k = data_021EFF14[c];
    if (k != 0 && k != 0x10) {
        func_021CD0F0(r, k, a);
    } else {
        func_021CD6AC(r, c, a);
    }
    return c;
}


/*
 * tail-call thunk to func_021CCAA8
 */
void func_021CD63C(void *p, int v)
{
    func_021CCAA8(p, v);
}
