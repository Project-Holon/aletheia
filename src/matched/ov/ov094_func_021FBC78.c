/*
 * function: func_021FBC78
 * address:  0x021FBC78
 * packet:   pkt_ov094_021FBC78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F9948  0x021F9948  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);

int func_021FBC78(struct Cursor *a, State *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);
    int v8 = VM_GetU32(a);

    func_021F9948((void *)a, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    return s->f23c;
}
