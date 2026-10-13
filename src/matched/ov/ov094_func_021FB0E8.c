/*
 * function: func_021FB0E8
 * address:  0x021FB0E8
 * packet:   pkt_ov094_021FB0E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFDB4  0x021FFDB4  thumb  ov094
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FFDB4(void *w, int a, u8 b, u8 c, u8 d, int e);

int func_021FB0E8(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFDB4((void *)func_021F8694(), buf[i], p, q, r, t);
    }
    return s->f23c;
}
