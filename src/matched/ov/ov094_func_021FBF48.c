/*
 * function: func_021FBF48
 * address:  0x021FBF48
 * packet:   pkt_ov094_021FBF48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021FFFD8  0x021FFFD8  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021F8694(void);
extern int func_021FCA04(State *s, int i, int *out);
extern void func_021FFFD8(char *w, int key, int flag, int clear);

int func_021FBF48(struct Cursor *a, State *s)
{
    int buf[8];
    int x = VM_GetU32(a);
    int n = func_021FCA04(s, VM_GetU32(a), buf);
    int y = VM_GetU32(a);
    int i;

    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFFD8((char *)func_021F8694(), buf[i], x, y);
    }
    return s->f23c;
}
